/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Copyright (c) 2022 Vincent DEFERT. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "project-defs.h"
#include "pca-hal.h"

/**
 * @file pca-hal.c
 * 
 * PCA abstraction implementation.
 */

static uint8_t __pca_pinConfigurations[][PCA_CHANNELS + 1] = {
#if MCU_FAMILY == 8 && MCU_SERIES == 'G' && MCU_PINS > 8
	// PCA pin configurations for STC8G *except* STC8G1K08A
	{ 0x11, 0x10, 0x37, 0x12, }, 
	{ 0x35, 0x36, 0x37, 0x34, }, 
	{ 0x25, 0x26, 0x27, 0x24, }, 
#endif // MCU_FAMILY == 8 && MCU_SERIES == 'G' && MCU_PINS > 8

#if MCU_FAMILY == 8 && MCU_SERIES == 'G' && MCU_PINS == 8
	// PCA pin configurations for STC8G1K08A
	{ 0x32, 0x33, 0x54, 0x55, }, 
	{ 0x32, 0x33, 0x55, 0x31, }, 
	{ 0x31, 0x33, 0x54, 0x55, }, 
#endif // MCU_FAMILY == 8 && MCU_SERIES == 'G' && MCU_PINS == 8

#if MCU_FAMILY == 8 && MCU_SERIES == 'A'
	// PCA pin configurations for STC8A
	{ 0x17, 0x16, 0x15, 0x14, 0x12, }, 
	{ 0x23, 0x24, 0x25, 0x26, 0x22, }, 
	{ 0x70, 0x71, 0x72, 0x73, 0x74, }, 
	{ 0x33, 0x32, 0x31, 0x30, 0x35, }, 
#endif // MCU_FAMILY == 8 && MCU_SERIES == 'A'

#if MCU_FAMILY == 15
	// PCA pin configurations for STC8A
	{ 0x11, 0x10, 0x37, 0x12, }, 
	{ 0x35, 0x36, 0x37, 0x34, }, 
	// nNot available on STC15W4xxAS
	{ 0x25, 0x26, 0x27, 0x24, }, 
#endif // MCU_FAMILY == 15

#if MCU_FAMILY == 12
	// PCA pin configurations for STC8A
	{ 0x13, 0x14, 0x12, }, 
	{ 0x42, 0x43, 0x41, }, 
#endif // MCU_FAMILY == 12
};

/*
 * By default, all available UARTs are exposed through the HAL
 * However, should you need to reduce your application's RAM or
 * flash usage, you can define the HAL_UARTS macro to expose less
 * UARTs, e.g. setting HAL_UARTS to 2 on an MCU with 4 UARTs would
 * only expose UART1 and UART2.
 */
#ifdef HAL_PCA_CHANNELS
	#if HAL_PCA_CHANNELS < 1 || HAL_PCA_CHANNELS > PCA_CHANNELS
		#error "Macro HAL_PCA_CHANNELS out of range"
	#endif // HAL_PCA_CHANNELS < 1 || HAL_PCA_CHANNELS > NB_UARTS
#else
	#define HAL_PCA_CHANNELS PCA_CHANNELS
#endif

typedef enum {
	PCA_UNUSED = 0x00,
	// Pulse width capture
	PCA_CAPTURE = 0x40,
	// PWM output
	PCA_PWM = 0x42,
	// 16-bit software timer
	PCA_TIMER = 0x49,
	// 16-bit high-speed pulse output
	PCA_PULSE = 0x4d,
} PCA_ChannelMode;

typedef union {
	struct {
		uint8_t ccapl;
		uint8_t ccaph;
		uint8_t cnt;
		uint8_t zero;
	} fields;
	uint32_t count;
} PCA_CaptureCount;

static uint8_t __pca_pinSwitch;
static PCA_CaptureCount __pca_captureStartCount[HAL_PCA_CHANNELS];
static PCA_CaptureCount __pca_captureEndCount[HAL_PCA_CHANNELS];
static uint16_t __pca_timerPeriod[HAL_PCA_CHANNELS];
static uint16_t __pca_timerValue[HAL_PCA_CHANNELS];
static uint8_t __pca_captureOverflowCounter[HAL_PCA_CHANNELS];
static uint8_t __pca_captureShiftBits[HAL_PCA_CHANNELS];
static PCA_CaptureMode __pca_captureMode[HAL_PCA_CHANNELS];
static PCA_ChannelMode __pca_channelMode[HAL_PCA_CHANNELS];

// On all STC8G, STC8H and the STC8A8K64D4, GPIO ports are configured
// in high-impedance mode by default, so configuring the channel output
// pin mode is *REQUIRED*.
static void __pca_configureChannelOutput(PCA_Channel channel, GpioPortMode pinMode) {
	uint8_t channelPin = __pca_pinConfigurations[__pca_pinSwitch][channel];
	GpioPort port = (GpioPort) (channelPin >> 4);
	GpioPin pin = (GpioPin) (channelPin & 0x0f);
	GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, pinMode);
	gpioConfigure(&pinConfig);
}

#if MCU_FAMILY == 12
	#define COUNTER_MAX 256UL
#else
	#define COUNTER_MAX 65536UL
#endif // MCU_FAMILY == 12

inline uint8_t __pca_ccapMode(PCA_ChannelMode channelMode, PCA_EdgeTrigger interruptTrigger) {
	return channelMode
		| (interruptTrigger << P_CAPN)
		| (((interruptTrigger != PCA_EDGE_NONE)
			? PCA_INTERRUPT_ENABLE 
			: PCA_INTERRUPT_DISABLE) << P_EECF);
}

void pcaInitialise(PCA_ClockSource clockSource, PCA_CounterMode counterMode, PCA_InterruptEnable overflowInterrupt, uint8_t pinSwitch) {
	__pca_pinSwitch = pinSwitch;
	P_SW1 = (P_SW1 & ~M_CCP_S) | ((pinSwitch << P_CCP_S) & M_CCP_S);
	
	for (uint8_t channel = 0; channel < PCA_CHANNELS; channel++) {
		__pca_channelMode[channel] = PCA_UNUSED;
	}
	
	CMOD = (counterMode << P_CIDL) | (clockSource << P_CPS) | (overflowInterrupt << P_ECF);
	CCON = 0;
	CL = 0;
	CH = 0;
	CR = 1;
}

void pcaStartCapture(PCA_Channel channel, GpioPortMode pinMode, PCA_EdgeTrigger trigger, PCA_CaptureMode captureMode, uint8_t shiftBits) {
	CR = 0;
	__pca_configureChannelOutput(channel, pinMode);
	
	__pca_captureOverflowCounter[channel] = 0;
	__pca_captureStartCount[channel].count = 0;
	__pca_captureEndCount[channel].count = 0;
	__pca_captureShiftBits[channel] = shiftBits;
	__pca_captureMode[channel] = captureMode;
	__pca_channelMode[channel] = PCA_CAPTURE;
	
	uint8_t ccapMode = __pca_ccapMode(PCA_CAPTURE, trigger);
	
	switch (channel) {
	case PCA_CHANNEL0:
		CCAPM0 = ccapMode;
		CCAP0L = 0;
		CCAP0H = 0;
		break;
		
#if HAL_PCA_CHANNELS > 1
	case PCA_CHANNEL1:
		CCAPM1 = ccapMode;
		CCAP1L = 0;
		CCAP1H = 0;
		break;
#endif // HAL_PCA_CHANNELS > 1
		
#if HAL_PCA_CHANNELS > 2
	case PCA_CHANNEL2:
		CCAPM2 = ccapMode;
		CCAP2L = 0;
		CCAP2H = 0;
		break;
#endif // HAL_PCA_CHANNELS > 2
		
#if HAL_PCA_CHANNELS > 3
	case PCA_CHANNEL3:
	#ifdef PCA_CHANNEL3_XSFR
		ENABLE_EXTENDED_SFR();
	#endif
		
		CCAPM3 = ccapMode;
		CCAP3L = 0;
		CCAP3H = 0;
		
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
		break;
#endif // HAL_PCA_CHANNELS > 3
	}
	
	CL = 0;
	CH = 0;
	CR = 1;
}

#if MCU_FAMILY == 12
	// Suppress warning "unreferenced function argument"
	#pragma disable_warning 85
#endif // MCU_FAMILY == 12
static void __pcaConfigurePWM(uint8_t initialise, PCA_Channel channel, GpioPortMode pinMode, PCA_PWM_Bits pwmBits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
	__pca_channelMode[channel] = PCA_PWM;
	
#if MCU_FAMILY == 12
	PCA_PWM_Bits bits = PCA_8BIT_PWM;
	uint16_t maxValue = 256;
#else
	PCA_PWM_Bits bits = pwmBits;

	if (initialise) {
		__pca_configureChannelOutput(channel, pinMode);
	} else {
		switch (channel) {
		case PCA_CHANNEL0:
			bits = (PCA_PWM_Bits) ((PCA_PWM0 & M_EBS) >> P_EBS);
			break;

	#if HAL_PCA_CHANNELS > 1
		case PCA_CHANNEL1:
			bits = (PCA_PWM_Bits) ((PCA_PWM1 & M_EBS) >> P_EBS);
			break;
	#endif // HAL_PCA_CHANNELS > 1

	#if HAL_PCA_CHANNELS > 2
		case PCA_CHANNEL2:
			bits = (PCA_PWM_Bits) ((PCA_PWM2 & M_EBS) >> P_EBS);
			break;
	#endif // HAL_PCA_CHANNELS > 2

	#if HAL_PCA_CHANNELS > 3
		case PCA_CHANNEL3:
		#ifdef PCA_CHANNEL3_XSFR
			ENABLE_EXTENDED_SFR();
		#endif
		
			bits = (PCA_PWM_Bits) ((PCA_PWM3 & M_EBS) >> P_EBS);
		
		#ifdef PCA_CHANNEL3_XSFR
			DISABLE_EXTENDED_SFR();
		#endif
			break;
	#endif // HAL_PCA_CHANNELS > 3
		}
	}

	uint16_t maxValue = 0;
	
	switch (bits) {
	case PCA_8BIT_PWM:
		maxValue = 256;
		break;

	#ifdef PCA_HAS_6_7_BIT_PWM
	case PCA_7BIT_PWM:
		maxValue = 128;
		break;
	
	case PCA_6BIT_PWM:
		maxValue = 64;
		break;
	#endif // PCA_HAS_6_7_BIT_PWM

	#ifdef PCA_HAS_10BIT_PWM
	case PCA_10BIT_PWM:
		maxValue = 1024;
		break;
	#endif // PCA_HAS_10BIT_PWM
	}
#endif // MCU_FAMILY == 12
	
	uint16_t reloadValue = maxValue - ((clocksHigh >= maxValue) ? (maxValue - 1) : clocksHigh);
	uint8_t xccap = (reloadValue >> 8) & 3;
	uint8_t ccap = reloadValue & 0xff;
	// When using 10-bit PWM:
	// (xccap << 4) defines bits 9 and 8 of the reload value (XCCAPnH)
	// (xccap << 2) defines bits 9 and 8 of the comparison value (XCCAPnL)
	uint8_t pcaPwm = (bits << P_EBS) | (xccap << P_XCCAPH) | (xccap << P_XCCAPL);
	uint8_t ccapMode = __pca_ccapMode(PCA_PWM, interruptTrigger);
	
	switch (channel) {
	case PCA_CHANNEL0:
		PCA_PWM0 = pcaPwm;
		
		if (initialise) {
			CCAPM0 = ccapMode;
			CCAP0L = ccap;
		}
		
		CCAP0H = ccap;
		break;
		
#if HAL_PCA_CHANNELS > 1
	case PCA_CHANNEL1:
		PCA_PWM1 = pcaPwm;
		
		if (initialise) {
			CCAPM1 = ccapMode;
			CCAP1L = ccap;
		}
		
		CCAP1H = ccap;
		break;
#endif // HAL_PCA_CHANNELS > 1
	
#if HAL_PCA_CHANNELS > 2
	case PCA_CHANNEL2:
		PCA_PWM2 = pcaPwm;
		
		if (initialise) {
			CCAPM2 = ccapMode;
			CCAP2L = ccap;
		}
		
		CCAP2H = ccap;
		break;
#endif // HAL_PCA_CHANNELS > 2
	
#if HAL_PCA_CHANNELS > 3
	case PCA_CHANNEL3:
	#ifdef PCA_CHANNEL3_XSFR
		ENABLE_EXTENDED_SFR();
	#endif
		
		PCA_PWM3 = pcaPwm;
		
		if (initialise) {
			CCAPM3 = ccapMode;
			CCAP3L = ccap;
		}
		
		CCAP3H = ccap;
		
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
		break;
#endif // HAL_PCA_CHANNELS > 3
	}
}

void pcaStartPwm(PCA_Channel channel, GpioPortMode pinMode, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
	__pcaConfigurePWM(1, channel, pinMode, bits, interruptTrigger, clocksHigh);
}

void pcaSetPwmDutyCycle(PCA_Channel channel, uint16_t clocksHigh) {
	__pcaConfigurePWM(0, channel, GPIO_BIDIRECTIONAL, 0, PCA_EDGE_NONE, clocksHigh);
}

void pcaStartTimer(PCA_Channel channel, GpioPortMode pinMode, PCA_OutputEnable pulseOutput, uint16_t timerPeriod) {
	__pca_configureChannelOutput(channel, pinMode);
	
	__pca_timerPeriod[channel] = timerPeriod;
	__pca_timerValue[channel] = __pca_timerPeriod[channel];
	uint8_t ccapMode = (pulseOutput == PCA_OUTPUT_ENABLE) ? PCA_PULSE : PCA_TIMER;
	__pca_channelMode[channel] = ccapMode;
	
	switch (channel) {
	case PCA_CHANNEL0:
		CCAPM0 = ccapMode;
		CCAP0L = __pca_timerValue[channel] & 0xff;
		CCAP0H = __pca_timerValue[channel] >> 8;
		break;
		
#if HAL_PCA_CHANNELS > 1
	case PCA_CHANNEL1:
		CCAPM1 = ccapMode;
		CCAP1L = __pca_timerValue[channel] & 0xff;
		CCAP1H = __pca_timerValue[channel] >> 8;
		break;
#endif // HAL_PCA_CHANNELS > 1
		
#if HAL_PCA_CHANNELS > 2
	case PCA_CHANNEL2:
		CCAPM2 = ccapMode;
		CCAP2L = __pca_timerValue[channel] & 0xff;
		CCAP2H = __pca_timerValue[channel] >> 8;
		break;
#endif // HAL_PCA_CHANNELS > 2
		
#if HAL_PCA_CHANNELS > 3
	case PCA_CHANNEL3:
	#ifdef PCA_CHANNEL3_XSFR
		ENABLE_EXTENDED_SFR();
	#endif
		
		CCAPM3 = ccapMode;
		CCAP3L = __pca_timerValue[channel] & 0xff;
		CCAP3H = __pca_timerValue[channel] >> 8;
		
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
		break;
#endif // HAL_PCA_CHANNELS > 3
	}
}

void __pca_isr() ISR_PARAM(PCA_INTERRUPT, 1) CRITICAL {
	uint8_t ccapl = 0;
	uint8_t ccaph = 0;
	uint8_t channel = HAL_PCA_CHANNELS;
	PCA_CaptureCount width;
	uint16_t duration = 0;
	
	if (CF) {
		CF = 0;
		__pca_captureOverflowCounter[PCA_CHANNEL0]++;
		
#if HAL_PCA_CHANNELS > 1
		__pca_captureOverflowCounter[PCA_CHANNEL1]++;
#endif // HAL_PCA_CHANNELS > 1
		
#if HAL_PCA_CHANNELS > 2
		__pca_captureOverflowCounter[PCA_CHANNEL2]++;
#endif // HAL_PCA_CHANNELS > 2

#if HAL_PCA_CHANNELS > 3
		__pca_captureOverflowCounter[PCA_CHANNEL3]++;
#endif // HAL_PCA_CHANNELS > 3
	}
	
	if (CCF0) {
		CCF0 = 0;
		channel = PCA_CHANNEL0;
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP0L;
			ccaph = CCAP0H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM0 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP0L = __pca_timerValue[channel] & 0xff;
			CCAP0H = __pca_timerValue[channel] >> 8;
			break;
		}
	}
	
#if HAL_PCA_CHANNELS > 1
	if (CCF1) {
		CCF1 = 0;
		channel = PCA_CHANNEL1;
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP1L;
			ccaph = CCAP1H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM1 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP1L = __pca_timerValue[channel] & 0xff;
			CCAP1H = __pca_timerValue[channel] >> 8;
			break;
		}
	}
#endif // HAL_PCA_CHANNELS > 1
	
#if HAL_PCA_CHANNELS > 2
	if (CCF2) {
		CCF2 = 0;
		channel = PCA_CHANNEL2;
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP2L;
			ccaph = CCAP2H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM2 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP2L = __pca_timerValue[channel] & 0xff;
			CCAP2H = __pca_timerValue[channel] >> 8;
			break;
		}
	}
#endif // HAL_PCA_CHANNELS > 2
	
#if HAL_PCA_CHANNELS > 3
	if (CCF3) {
		CCF3 = 0;
		channel = PCA_CHANNEL3;
		
	#ifdef PCA_CHANNEL3_XSFR
		ENABLE_EXTENDED_SFR();
	#endif
		
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			ccapl = CCAP3L;
			ccaph = CCAP3H;
			
			if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
				CCAPM3 = 0;
				__pca_channelMode[channel] = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_timerValue[channel] += __pca_timerPeriod[channel];
			CCAP3L = __pca_timerValue[channel] & 0xff;
			CCAP3H = __pca_timerValue[channel] >> 8;
			break;
		}
		
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
	}
#endif // HAL_PCA_CHANNELS > 3
	
	if (channel < HAL_PCA_CHANNELS) {
		switch (__pca_channelMode[channel]) {
		case PCA_CAPTURE:
			__pca_captureStartCount[channel].count = __pca_captureEndCount[channel].count;
			__pca_captureEndCount[channel].fields.ccapl = ccapl;
			__pca_captureEndCount[channel].fields.ccaph = ccaph;
			__pca_captureEndCount[channel].fields.cnt = __pca_captureOverflowCounter[channel];
			__pca_captureEndCount[channel].fields.zero = 0;
			
			width.count = (__pca_captureEndCount[channel].count - __pca_captureStartCount[channel].count) >> __pca_captureShiftBits[channel];
			// 0xffff means "maximum value and above".
			duration = width.fields.cnt ? 0xffff : ((uint16_t) width.count);
			
			pcaOnInterrupt(channel, duration);
			break;
		
		case PCA_PWM:
		case PCA_TIMER:
			pcaOnInterrupt(channel, duration);
			break;
		}
	}
}
