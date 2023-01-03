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
#include <pca-hal.h>
#include <gpio-hal.h>

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

/**
 * @file pca-hal.c
 * 
 * PCA abstraction implementation.
 */

static const uint8_t __pca_pinConfigurations[][PCA_CHANNELS + 1] = {
#if MCU_FAMILY == 8 && MCU_SERIES == 'G' && MCU_PINS > 8
	// PCA pin configurations for STC8G *except* STC8G1K08A
	{ 0x11, 0x10, 0x37, 0x12, }, 
	{ 0x35, 0x36, 0x37, 0x34, }, 
	#ifdef GPIO_HAS_P2
		{ 0x25, 0x26, 0x27, 0x24, }, 
	#endif // GPIO_HAS_P2
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
	#if PCA_CHANNELS == 2
		// PCA pin configurations for STC15W4KxxS4
		{ 0x11, 0x10, 0x12, }, 
		{ 0x35, 0x36, 0x34, }, 
		{ 0x25, 0x26, 0x24, }, 
	#else
		// PCA pin configurations for STC15W4xxAS
		{ 0x11, 0x10, 0x37, 0x12, }, 
		{ 0x35, 0x36, 0x37, 0x34, }, 
		#ifdef GPIO_HAS_P2
			{ 0x25, 0x26, 0x27, 0x24, }, 
		#endif // GPIO_HAS_P2
	#endif
#endif // MCU_FAMILY == 15

#if MCU_FAMILY == 12
	// PCA pin configurations for STC8A
	{ 0x13, 0x14, 0x12, }, 
	{ 0x42, 0x43, 0x41, }, 
#endif // MCU_FAMILY == 12
};

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
		uint16_t ccap;
		uint8_t cnt;
		uint8_t zero;
	} capture;
	struct {
		uint16_t value;
		uint16_t period;
	} timer;
	uint32_t value;
} PCA_ChannelData;

typedef struct {
	PCA_ChannelMode mode;
	union {
		struct {
			PCA_CaptureMode mode:1;
			uint8_t shiftBits:5;
		} capture;
		struct {
			PCA_PWM_Bits bits;
		} pwm;
	} settings;
} PCA_ChannelConfig;

// Access to __pca_pinSwitch is not timing-critical,
// so let's leave it in the default memory segment.
static uint8_t __pca_pinSwitch;

// Each channel uses 7 bytes RAM
static HAL_PCA_SEGMENT uint8_t __pca_overflowCounter[HAL_PCA_CHANNELS];
static HAL_PCA_SEGMENT PCA_ChannelData __pca_channelData[HAL_PCA_CHANNELS];
static HAL_PCA_SEGMENT PCA_ChannelConfig __pca_channelConfig[HAL_PCA_CHANNELS];

// On all STC8G, STC8H and the STC8A8K64D4, GPIO ports are configured
// in high-impedance mode by default, so configuring the channel output
// pin mode is *REQUIRED*.
static void pcaConfigureChannel(PCA_Channel channel, GpioPinMode pinMode) {
	uint8_t channelPin = __pca_pinConfigurations[__pca_pinSwitch][channel];
	GpioPort port = (GpioPort) (channelPin >> 4);
	GpioPin pin = (GpioPin) (channelPin & 0x0f);
	GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, pinMode);
	gpioConfigure(&pinConfig);
}

void pcaConfigureOutput(PCA_Channel channel, GpioPinMode pinMode) {
	if (pinMode == GPIO_HIGH_IMPEDANCE_MODE) {
		pinMode = GPIO_PUSH_PULL_MODE;
	}
	
	pcaConfigureChannel(channel, pinMode);
}

void pcaConfigureInput(PCA_Channel channel) {
	pcaConfigureChannel(channel, GPIO_HIGH_IMPEDANCE_MODE);
}

#if MCU_FAMILY == 12
	#define COUNTER_MAX 256UL
#else
	#define COUNTER_MAX 65536UL
#endif // MCU_FAMILY == 12

inline uint8_t __pca_ccapMode(PCA_ChannelMode channelMode, PCA_EdgeTrigger interruptTrigger) {
	return channelMode
		| (interruptTrigger << P_CAPN)
		| ((interruptTrigger != PCA_EDGE_NONE
			? ENABLE_INTERRUPT 
			: DISABLE_INTERRUPT) << P_EECF);
}

void pcaStartCounter(PCA_ClockSource clockSource, CounterControl counterMode, InterruptEnable overflowInterrupt, uint8_t pinSwitch) {
	__pca_pinSwitch = pinSwitch;
	P_SW1 = (P_SW1 & ~M_CCP_S) | ((pinSwitch << P_CCP_S) & M_CCP_S);
	
	for (uint8_t channel = 0; channel < PCA_CHANNELS; channel++) {
		__pca_channelConfig[channel].mode = PCA_UNUSED;
	}
	
	CMOD = (counterMode << P_CIDL) | (clockSource << P_CPS) | (overflowInterrupt << P_ECF);
	CCON = 0;
	PCA_CTR = 0;
	CR = 1;
}

void pcaStartCapture(PCA_Channel channel, PCA_EdgeTrigger trigger, PCA_CaptureMode captureMode, uint8_t shiftBits) {
	CR = 0;
	
	__pca_overflowCounter[channel] = 0;
	__pca_channelData[channel].value = 0;
	__pca_channelConfig[channel].settings.capture.shiftBits = shiftBits;
	__pca_channelConfig[channel].settings.capture.mode = captureMode;
	__pca_channelConfig[channel].mode = PCA_CAPTURE;
	
	uint8_t ccapMode = __pca_ccapMode(PCA_CAPTURE, trigger);
	
	switch (channel) {
	case PCA_CHANNEL0:
		CCAPM0 = ccapMode;
		CCAP0 = 0;
		break;
		
#if HAL_PCA_CHANNELS > 1
	case PCA_CHANNEL1:
		CCAPM1 = ccapMode;
		CCAP1 = 0;
		break;
#endif // HAL_PCA_CHANNELS > 1
		
#if HAL_PCA_CHANNELS > 2
	case PCA_CHANNEL2:
		CCAPM2 = ccapMode;
		CCAP2 = 0;
		break;
#endif // HAL_PCA_CHANNELS > 2
		
#if HAL_PCA_CHANNELS > 3
	case PCA_CHANNEL3:
	#ifdef PCA_CHANNEL3_XSFR
		ENABLE_EXTENDED_SFR();
	#endif
		
		CCAPM3 = ccapMode;
		CCAP3 = 0;
		
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
		break;
#endif // HAL_PCA_CHANNELS > 3
	}
	
	PCA_CTR = 0;
	CR = 1;
}

void pcaStopChannel(PCA_Channel channel) {
	switch (channel) {
	case PCA_CHANNEL0:
		CCAPM0 = 0;
		break;
		
#if HAL_PCA_CHANNELS > 1
	case PCA_CHANNEL1:
		CCAPM1 = 0;
		break;
#endif // HAL_PCA_CHANNELS > 1
		
#if HAL_PCA_CHANNELS > 2
	case PCA_CHANNEL2:
		CCAPM2 = 0;
		break;
#endif // HAL_PCA_CHANNELS > 2
		
#if HAL_PCA_CHANNELS > 3
	case PCA_CHANNEL3:
	#ifdef PCA_CHANNEL3_XSFR
		ENABLE_EXTENDED_SFR();
	#endif
		CCAPM3 = 0;
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
		break;
#endif // HAL_PCA_CHANNELS > 3
	}
}

#if MCU_FAMILY == 12
	// Suppress warning "unreferenced function argument"
	#pragma disable_warning 85
#endif // MCU_FAMILY == 12
static void __pcaConfigurePWM(bool initialise, PCA_Channel channel, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
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
	
	uint16_t reloadValue = maxValue - ((clocksHigh >= maxValue) ? (maxValue - 1) : clocksHigh);
	uint8_t xccap = (reloadValue >> 8) & 3;
	uint8_t ccap = reloadValue;
	// When using 10-bit PWM:
	// (xccap << 4) defines bits 9 and 8 of the reload value (XCCAPnH)
	// (xccap << 2) defines bits 9 and 8 of the comparison value (XCCAPnL)
	uint8_t pcaPwm = (bits << P_EBS) | (xccap << P_XCCAPH) | (xccap << P_XCCAPL);
	uint8_t ccapMode = initialise ? __pca_ccapMode(PCA_PWM, interruptTrigger) : 0;
	
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

void pcaStartPwm(PCA_Channel channel, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
	__pca_channelConfig[channel].mode = PCA_PWM;
	__pca_channelConfig[channel].settings.pwm.bits = bits;
	__pcaConfigurePWM(
		true,
		channel, 
		bits, 
		interruptTrigger, 
		clocksHigh
	);
}

void pcaSetDutyCycle(PCA_Channel channel, uint16_t clocksHigh) {
	__pcaConfigurePWM(
		false,
		channel, 
		__pca_channelConfig[channel].settings.pwm.bits, 
		PCA_EDGE_NONE, // No longer used once PWM channel is started.
		clocksHigh
	);
}

void pcaStartTimer(PCA_Channel channel, OutputEnable pulseOutput, uint16_t timerPeriod) {
	__pca_channelData[channel].timer.period = timerPeriod;
	__pca_channelData[channel].timer.value = timerPeriod;
	uint8_t ccapMode = (pulseOutput == ENABLE_OUTPUT) ? PCA_PULSE : PCA_TIMER;
	__pca_channelConfig[channel].mode = ccapMode;
	
	switch (channel) {
	case PCA_CHANNEL0:
		CCAPM0 = ccapMode;
		CCAP0 = timerPeriod;
		break;
		
#if HAL_PCA_CHANNELS > 1
	case PCA_CHANNEL1:
		CCAPM1 = ccapMode;
		CCAP1 = timerPeriod;
		break;
#endif // HAL_PCA_CHANNELS > 1
		
#if HAL_PCA_CHANNELS > 2
	case PCA_CHANNEL2:
		CCAPM2 = ccapMode;
		CCAP2 = timerPeriod;
		break;
#endif // HAL_PCA_CHANNELS > 2
		
#if HAL_PCA_CHANNELS > 3
	case PCA_CHANNEL3:
	#ifdef PCA_CHANNEL3_XSFR
		ENABLE_EXTENDED_SFR();
	#endif
		
		CCAPM3 = ccapMode;
		CCAP3 = timerPeriod;
		
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
		break;
#endif // HAL_PCA_CHANNELS > 3
	}
}

INTERRUPT_USING(__pca_isr, PCA_INTERRUPT, 1) {
	uint16_t ccap = 0;
	uint8_t channel = HAL_PCA_CHANNELS;
	
	if (CF) {
		CF = 0;
		__pca_overflowCounter[PCA_CHANNEL0]++;
		
#if HAL_PCA_CHANNELS > 1
		__pca_overflowCounter[PCA_CHANNEL1]++;
#endif // HAL_PCA_CHANNELS > 1
		
#if HAL_PCA_CHANNELS > 2
		__pca_overflowCounter[PCA_CHANNEL2]++;
#endif // HAL_PCA_CHANNELS > 2

#if HAL_PCA_CHANNELS > 3
		__pca_overflowCounter[PCA_CHANNEL3]++;
#endif // HAL_PCA_CHANNELS > 3
	}
	
	if (CCF0) {
		CCF0 = 0;
		channel = PCA_CHANNEL0;
		
		switch (__pca_channelConfig[channel].mode) {
		case PCA_CAPTURE:
			ccap = CCAP0;
			
			if (__pca_channelConfig[channel].settings.capture.mode == PCA_ONE_SHOT) {
				CCAPM0 = 0;
				__pca_channelConfig[channel].mode = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_channelData[channel].timer.value += __pca_channelData[channel].timer.period;
			CCAP0 = __pca_channelData[channel].timer.value;
			break;
		}
	}
	
#if HAL_PCA_CHANNELS > 1
	if (CCF1) {
		CCF1 = 0;
		channel = PCA_CHANNEL1;
		
		switch (__pca_channelConfig[channel].mode) {
		case PCA_CAPTURE:
			ccap = CCAP1;
			
			if (__pca_channelConfig[channel].settings.capture.mode == PCA_ONE_SHOT) {
				CCAPM1 = 0;
				__pca_channelConfig[channel].mode = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_channelData[channel].timer.value += __pca_channelData[channel].timer.period;
			CCAP1 = __pca_channelData[channel].timer.value;
			break;
		}
	}
#endif // HAL_PCA_CHANNELS > 1
	
#if HAL_PCA_CHANNELS > 2
	if (CCF2) {
		CCF2 = 0;
		channel = PCA_CHANNEL2;
		
		switch (__pca_channelConfig[channel].mode) {
		case PCA_CAPTURE:
			ccap = CCAP2;
			
			if (__pca_channelConfig[channel].settings.capture.mode == PCA_ONE_SHOT) {
				CCAPM2 = 0;
				__pca_channelConfig[channel].mode = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_channelData[channel].timer.value += __pca_channelData[channel].timer.period;
			CCAP2 = __pca_channelData[channel].timer.value;
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
		
		switch (__pca_channelConfig[channel].mode) {
		case PCA_CAPTURE:
			ccap = CCAP3;
			
			if (__pca_channelConfig[channel].settings.capture.mode == PCA_ONE_SHOT) {
				CCAPM3 = 0;
				__pca_channelConfig[channel].mode = PCA_UNUSED;
			}
			break;
		
		case PCA_TIMER:
		case PCA_PULSE:
			__pca_channelData[channel].timer.value += __pca_channelData[channel].timer.period;
			CCAP3 = __pca_channelData[channel].timer.value;
			break;
		}
		
	#ifdef PCA_CHANNEL3_XSFR
		DISABLE_EXTENDED_SFR();
	#endif
	}
#endif // HAL_PCA_CHANNELS > 3
	
	if (channel < HAL_PCA_CHANNELS) {
		PCA_ChannelData width;
		PCA_ChannelData newCount;
		uint32_t startCount;
		uint16_t duration;
		
		switch (__pca_channelConfig[channel].mode) {
		case PCA_CAPTURE:
			startCount = __pca_channelData[channel].value;
			newCount.capture.ccap = ccap;
			newCount.capture.cnt = __pca_overflowCounter[channel];
			newCount.capture.zero = 0;
			width.value = (newCount.value - __pca_channelData[channel].value) >> __pca_channelConfig[channel].settings.capture.shiftBits;
			__pca_channelData[channel].value = newCount.value;
			
			// 0xffff means "maximum value and above".
			duration = width.capture.cnt ? 0xffff : ((uint16_t) width.value);
			pcaOnInterrupt(channel, duration);
			break;
		
		case PCA_PWM:
		case PCA_TIMER:
			pcaOnInterrupt(channel, 0);
			break;
		}
	}
}
