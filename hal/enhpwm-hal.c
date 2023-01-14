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
#include <enhpwm-hal.h>
#include <gpio-hal.h>

/**
 * @file enhpwm-hal.c
 * 
 * 15-bit enhanced PWM abstraction implementation.
 */

static const uint8_t __pinConfigurations[][PWM_CHANNELS] = {
#if MCU_HAS_ENHANCED_PWM == '5'
	// STC15W4K
	{ 0x37, 0x21, 0x22, 0x23, 0x16, 0x17 }, 
	{ 0x27, 0x45, 0x44, 0x42, 0x07, 0x06 }, 
#endif // MCU_HAS_ENHANCED_PWM == '5'

#if MCU_HAS_ENHANCED_PWM == 'A' || (MCU_HAS_ENHANCED_PWM == 'G' && MCU_SERIES == 'A')
	// STC8A8KxxS4A12 and STC8A8KxxD4
	{ 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27 }, 
	{ 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17 }, 
	{ 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67 }, 
#endif // MCU_HAS_ENHANCED_PWM == 'A'

#if MCU_HAS_ENHANCED_PWM == 'G'
	// STC8G2K
	{ 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27 }, 
#endif // MCU_HAS_ENHANCED_PWM == 'G'
};

static uint8_t __pinSwitchAndMode[PWM_CHANNELS];

#define PIN_CONFIG_MAX (sizeof(__pinConfigurations) / sizeof(__pinConfigurations[0]))

// On the STC8G2K* and the STC8A8KxxD4, GPIO ports are configured
// in high-impedance mode by default, so configuring the channel 
// output pin mode is *REQUIRED*.
void pwmConfigureOutput(PWM_Channel channel, uint8_t pinSwitch, GpioPinMode pinMode) {
	if (pinSwitch >= PIN_CONFIG_MAX) {
		pinSwitch = 0;
	}
	
	__pinSwitchAndMode[channel] = pinSwitch | (pinMode << 4);
	
	if (pinMode == GPIO_HIGH_IMPEDANCE_MODE) {
		pinMode = GPIO_PUSH_PULL_MODE;
	}
	
	uint8_t channelPin = __pinConfigurations[pinSwitch][channel];
	GpioPort port = (GpioPort) (channelPin >> 4);
	GpioPin pin = (GpioPin) (channelPin & 0x0f);
	GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, pinMode);
	gpioConfigure(&pinConfig);
}

void pwmStartCounter(PWM_ClockSource clockSource, uint16_t divisor, InterruptEnable overflowInterrupt) {
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A' // STC8A8KxxD4
		PWMSET |= M_ENPWM0;
	#else // STC8G2K
		PWMSET |= M_ENPWM2;
	#endif // MCU_SERIES == 'A'
#endif // MCU_HAS_ENHANCED_PWM == 'G'
	ENABLE_EXTENDED_SFR();
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A' // STC8A8KxxD4
		PWM0CKS = clockSource;
		PWM0CL = divisor;
		PWM0CH = divisor >> 8;
		PWM0IF = 0;
		DISABLE_EXTENDED_SFR();
		PWMCFG01 = (PWMCFG01 & 0xf0) | (overflowInterrupt ? M_EPWM0CBI : 0) | M_PWM0CEN;
	#else // STC8G2K
		PWM2CKS = clockSource;
		PWM2CL = divisor;
		PWM2CH = divisor >> 8;
		PWM2IF = 0;
		DISABLE_EXTENDED_SFR();
		PWMCFG23 = (PWMCFG23 & 0xf0) | (overflowInterrupt ? M_EPWM2CBI : 0) | M_PWM2CEN;
	#endif // MCU_SERIES == 'A'
#else // STC8A8KxxS4A12 and STC15W4K
	PWM0CKS = clockSource;
	PWM0CL = divisor;
	PWM0CH = divisor >> 8;
	DISABLE_EXTENDED_SFR();
	PWM0IF = 0;
	PWMCR = M_ENPWM | (overflowInterrupt ? M_ECBI : 0);
#endif // MCU_HAS_ENHANCED_PWM == 'G'
}

void pwmConfigureFaultDetection(PWM_FaultTrigger faultTrigger, PWM_FaultResponse faultResponse, InterruptEnable faultInterrupt) {
	PWMFD_SFR_ENABLE
	PWMFD_SFR = faultTrigger | faultResponse | ((faultInterrupt == ENABLE_INTERRUPT) ? 0x08 : 0);
	PWMFD_SFR_DISABLE
}

void pwmStopCounter() {
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A' // STC8A8KxxD4
		PWMCFG01 &= ~(M_EPWM0CBI | M_PWM0CEN);
		PWMSET &= ~M_ENPWM0;
	#else // STC8G2K
		PWMCFG23 &= ~(M_EPWM2CBI | M_PWM2CEN);
		PWMSET &= ~M_ENPWM2;
	#endif // MCU_SERIES == 'A'
#else // STC8A8KxxS4A12 and STC15W4K
	PWMCR = 0;
#endif // MCU_HAS_ENHANCED_PWM == 'G'
	PWMFD_SFR_ENABLE
	PWMFD_SFR = 0;
	PWMFD_SFR_DISABLE
}

static void __pwmSetFlipPoints(PWM_Channel channel, uint16_t flipPoint1, uint16_t flipPoint2) {
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A' // STC8A8KxxD4
		switch (channel) {
		case PWM_Channel0:
			PWM00T1H = flipPoint1 >> 8;
			PWM00T1L = flipPoint1;
			PWM00T2H = flipPoint2 >> 8;
			PWM00T2L = flipPoint2;
			break;
		case PWM_Channel1:
			PWM01T1H = flipPoint1 >> 8;
			PWM01T1L = flipPoint1;
			PWM01T2H = flipPoint2 >> 8;
			PWM01T2L = flipPoint2;
			break;
		case PWM_Channel2:
			PWM02T1H = flipPoint1 >> 8;
			PWM02T1L = flipPoint1;
			PWM02T2H = flipPoint2 >> 8;
			PWM02T2L = flipPoint2;
			break;
		case PWM_Channel3:
			PWM03T1H = flipPoint1 >> 8;
			PWM03T1L = flipPoint1;
			PWM03T2H = flipPoint2 >> 8;
			PWM03T2L = flipPoint2;
			break;
		case PWM_Channel4:
			PWM04T1H = flipPoint1 >> 8;
			PWM04T1L = flipPoint1;
			PWM04T2H = flipPoint2 >> 8;
			PWM04T2L = flipPoint2;
			break;
		case PWM_Channel5:
			PWM05T1H = flipPoint1 >> 8;
			PWM05T1L = flipPoint1;
			PWM05T2H = flipPoint2 >> 8;
			PWM05T2L = flipPoint2;
			break;
		case PWM_Channel6:
			PWM06T1H = flipPoint1 >> 8;
			PWM06T1L = flipPoint1;
			PWM06T2H = flipPoint2 >> 8;
			PWM06T2L = flipPoint2;
			break;
		case PWM_Channel7:
			PWM07T1H = flipPoint1 >> 8;
			PWM07T1L = flipPoint1;
			PWM07T2H = flipPoint2 >> 8;
			PWM07T2L = flipPoint2;
			break;
		}
	#else // STC8G2K
		switch (channel) {
		case PWM_Channel0:
			PWM20T1H = flipPoint1 >> 8;
			PWM20T1L = flipPoint1;
			PWM20T2H = flipPoint2 >> 8;
			PWM20T2L = flipPoint2;
			break;
		case PWM_Channel1:
			PWM21T1H = flipPoint1 >> 8;
			PWM21T1L = flipPoint1;
			PWM21T2H = flipPoint2 >> 8;
			PWM21T2L = flipPoint2;
			break;
		case PWM_Channel2:
			PWM22T1H = flipPoint1 >> 8;
			PWM22T1L = flipPoint1;
			PWM22T2H = flipPoint2 >> 8;
			PWM22T2L = flipPoint2;
			break;
		case PWM_Channel3:
			PWM23T1H = flipPoint1 >> 8;
			PWM23T1L = flipPoint1;
			PWM23T2H = flipPoint2 >> 8;
			PWM23T2L = flipPoint2;
			break;
		case PWM_Channel4:
			PWM24T1H = flipPoint1 >> 8;
			PWM24T1L = flipPoint1;
			PWM24T2H = flipPoint2 >> 8;
			PWM24T2L = flipPoint2;
			break;
		case PWM_Channel5:
			PWM25T1H = flipPoint1 >> 8;
			PWM25T1L = flipPoint1;
			PWM25T2H = flipPoint2 >> 8;
			PWM25T2L = flipPoint2;
			break;
		case PWM_Channel6:
			PWM26T1H = flipPoint1 >> 8;
			PWM26T1L = flipPoint1;
			PWM26T2H = flipPoint2 >> 8;
			PWM26T2L = flipPoint2;
			break;
		case PWM_Channel7:
			PWM27T1H = flipPoint1 >> 8;
			PWM27T1L = flipPoint1;
			PWM27T2H = flipPoint2 >> 8;
			PWM27T2L = flipPoint2;
			break;
		}
	#endif // MCU_SERIES == 'A'
#else // STC8A8KxxS4A12 and STC15W4K
	switch (channel) {
	case PWM_Channel0:
		PWM00T1H = flipPoint1 >> 8;
		PWM00T1L = flipPoint1;
		PWM00T2H = flipPoint2 >> 8;
		PWM00T2L = flipPoint2;
		break;
	case PWM_Channel1:
		PWM01T1H = flipPoint1 >> 8;
		PWM01T1L = flipPoint1;
		PWM01T2H = flipPoint2 >> 8;
		PWM01T2L = flipPoint2;
		break;
	case PWM_Channel2:
		PWM02T1H = flipPoint1 >> 8;
		PWM02T1L = flipPoint1;
		PWM02T2H = flipPoint2 >> 8;
		PWM02T2L = flipPoint2;
		break;
	case PWM_Channel3:
		PWM03T1H = flipPoint1 >> 8;
		PWM03T1L = flipPoint1;
		PWM03T2H = flipPoint2 >> 8;
		PWM03T2L = flipPoint2;
		break;
	case PWM_Channel4:
		PWM04T1H = flipPoint1 >> 8;
		PWM04T1L = flipPoint1;
		PWM04T2H = flipPoint2 >> 8;
		PWM04T2L = flipPoint2;
		break;
	case PWM_Channel5:
		PWM05T1H = flipPoint1 >> 8;
		PWM05T1L = flipPoint1;
		PWM05T2H = flipPoint2 >> 8;
		PWM05T2L = flipPoint2;
		break;
	#if PWM_CHANNELS > 6
		case PWM_Channel6:
			PWM06T1H = flipPoint1 >> 8;
			PWM06T1L = flipPoint1;
			PWM06T2H = flipPoint2 >> 8;
			PWM06T2L = flipPoint2;
			break;
		case PWM_Channel7:
			PWM07T1H = flipPoint1 >> 8;
			PWM07T1L = flipPoint1;
			PWM07T2H = flipPoint2 >> 8;
			PWM07T2L = flipPoint2;
			break;
	#endif // PWM_CHANNELS > 6
	}
#endif // MCU_HAS_ENHANCED_PWM == 'G'
}

void pwmStartChannel(PWM_Channel channel, OutputLevel initialLevel, PWM_InterruptOnEvent interruptOnEvent, uint16_t flipPoint1, uint16_t flipPoint2) {
	uint8_t channelCR = interruptOnEvent;
	
	#ifdef M_C_S
		// STC8G2K doesn't support pin switch
		channelCR |= ((__pinSwitchAndMode[channel] & 0x0f) << P_C_S) & M_C_S;
	#endif // M_C_S
	
	#if MCU_HAS_ENHANCED_PWM != '5'
		// STC8A and STC8G2K
		channelCR |= M_ENO;
		channelCR |= (initialLevel << P_INI) & M_INI;
	#endif // MCU_HAS_ENHANCED_PWM != '5'
	
	ENABLE_EXTENDED_SFR();
	__pwmSetFlipPoints(channel, flipPoint1, flipPoint2);
	
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A'
		// STC8A8KxxD4
		switch (channel) {
		case PWM_Channel0:
			PWM00CR = channelCR;
			break;
		case PWM_Channel1:
			PWM01CR = channelCR;
			break;
		case PWM_Channel2:
			PWM02CR = channelCR;
			break;
		case PWM_Channel3:
			PWM03CR = channelCR;
			break;
		case PWM_Channel4:
			PWM04CR = channelCR;
			break;
		case PWM_Channel5:
			PWM05CR = channelCR;
			break;
		case PWM_Channel6:
			PWM06CR = channelCR;
			break;
		case PWM_Channel7:
			PWM07CR = channelCR;
			break;
		}
	#else
		// STC8G2K*
		switch (channel) {
		case PWM_Channel0:
			PWM20CR = channelCR;
			break;
		case PWM_Channel1:
			PWM21CR = channelCR;
			break;
		case PWM_Channel2:
			PWM22CR = channelCR;
			break;
		case PWM_Channel3:
			PWM23CR = channelCR;
			break;
		case PWM_Channel4:
			PWM24CR = channelCR;
			break;
		case PWM_Channel5:
			PWM25CR = channelCR;
			break;
		case PWM_Channel6:
			PWM26CR = channelCR;
			break;
		case PWM_Channel7:
			PWM27CR = channelCR;
			break;
		}
	#endif // MCU_SERIES == 'A'
	
	DISABLE_EXTENDED_SFR();
#else
	// STC8A8KxxS4A12 and STC15W4K*
	switch (channel) {
	case PWM_Channel0:
		PWM00CR = channelCR;
		break;
	case PWM_Channel1:
		PWM01CR = channelCR;
		break;
	case PWM_Channel2:
		PWM02CR = channelCR;
		break;
	case PWM_Channel3:
		PWM03CR = channelCR;
		break;
	case PWM_Channel4:
		PWM04CR = channelCR;
		break;
	case PWM_Channel5:
		PWM05CR = channelCR;
		break;
	#if PWM_CHANNELS > 6
		case PWM_Channel6:
			PWM06CR = channelCR;
			break;
		case PWM_Channel7:
			PWM07CR = channelCR;
			break;
	#endif // PWM_CHANNELS > 6
	}
	
	DISABLE_EXTENDED_SFR();
	
	#if MCU_HAS_ENHANCED_PWM == '5'
		// STC15W4K*
		PWMCFG |= initialLevel << channel;
		PWMCR |= 1 << channel;
	#endif // MCU_HAS_ENHANCED_PWM == '5'
#endif // MCU_HAS_ENHANCED_PWM == 'G'
}

void pwmStopChannel(PWM_Channel channel) {
	ENABLE_EXTENDED_SFR();
	
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A'
		// STC8A8KxxD4
		switch (channel) {
		case PWM_Channel0:
			PWM00CR = 0;
			break;
		case PWM_Channel1:
			PWM01CR = 0;
			break;
		case PWM_Channel2:
			PWM02CR = 0;
			break;
		case PWM_Channel3:
			PWM03CR = 0;
			break;
		case PWM_Channel4:
			PWM04CR = 0;
			break;
		case PWM_Channel5:
			PWM05CR = 0;
			break;
		case PWM_Channel6:
			PWM06CR = 0;
			break;
		case PWM_Channel7:
			PWM07CR = 0;
			break;
		}
	#else
		// STC8G2K*
		switch (channel) {
		case PWM_Channel0:
			PWM20CR = 0;
			break;
		case PWM_Channel1:
			PWM21CR = 0;
			break;
		case PWM_Channel2:
			PWM22CR = 0;
			break;
		case PWM_Channel3:
			PWM23CR = 0;
			break;
		case PWM_Channel4:
			PWM24CR = 0;
			break;
		case PWM_Channel5:
			PWM25CR = 0;
			break;
		case PWM_Channel6:
			PWM26CR = 0;
			break;
		case PWM_Channel7:
			PWM27CR = 0;
			break;
		}
	#endif // MCU_SERIES == 'A'
	
	DISABLE_EXTENDED_SFR();
#else
	// STC8A8KxxS4A12 and STC15W4K
	switch (channel) {
	case PWM_Channel0:
		PWM00CR = 0;
		break;
	case PWM_Channel1:
		PWM01CR = 0;
		break;
	case PWM_Channel2:
		PWM02CR = 0;
		break;
	case PWM_Channel3:
		PWM03CR = 0;
		break;
	case PWM_Channel4:
		PWM04CR = 0;
		break;
	case PWM_Channel5:
		PWM05CR = 0;
		break;
	#if PWM_CHANNELS > 6
		case PWM_Channel6:
			PWM06CR = 0;
			break;
		case PWM_Channel7:
			PWM07CR = 0;
			break;
	#endif // PWM_CHANNELS > 6
	}
	
	DISABLE_EXTENDED_SFR();
	
	#if MCU_HAS_ENHANCED_PWM == '5'
		// STC15W4K*
		PWMCR &= ~(1 << channel);
	#endif // MCU_HAS_ENHANCED_PWM == '5'
#endif // MCU_HAS_ENHANCED_PWM == 'G'
}

void pwmSetFlipPoints(PWM_Channel channel, uint16_t flipPoint1, uint16_t flipPoint2) {
	ENABLE_EXTENDED_SFR();
	__pwmSetFlipPoints(channel, flipPoint1, flipPoint2);
	DISABLE_EXTENDED_SFR();
}

void pwmLockChannel(PWM_Channel channel, OutputLevel outputLevel) {
#if MCU_HAS_ENHANCED_PWM == '5'
	// The STC15W4K doesn't have the PWMxxHLD SFR, let's emulate
	// the functionality. Note pwmStartChannel() MUST be called
	// again to unlock the channel.
	pwmStartChannel(
		channel, 
		outputLevel, 
		PWM_INTERRUPT_EVENT_NONE, 
		PWM_COUNTER_MAX, 
		PWM_COUNTER_MAX
	);
#else
	uint8_t lock = outputLevel ? M_HLDH : M_HLDL;
	ENABLE_EXTENDED_SFR();
	
	#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
		#if MCU_SERIES == 'A'
		// STC8A8KxxD4
		switch (channel) {
		case PWM_Channel0:
			PWM00HLD = lock;
			break;
		case PWM_Channel1:
			PWM01HLD = lock;
			break;
		case PWM_Channel2:
			PWM02HLD = lock;
			break;
		case PWM_Channel3:
			PWM03HLD = lock;
			break;
		case PWM_Channel4:
			PWM04HLD = lock;
			break;
		case PWM_Channel5:
			PWM05HLD = lock;
			break;
		case PWM_Channel6:
			PWM06HLD = lock;
			break;
		case PWM_Channel7:
			PWM07HLD = lock;
			break;
		}
		#else
		// STC8G2K*
		switch (channel) {
		case PWM_Channel0:
			PWM20HLD = lock;
			break;
		case PWM_Channel1:
			PWM21HLD = lock;
			break;
		case PWM_Channel2:
			PWM22HLD = lock;
			break;
		case PWM_Channel3:
			PWM23HLD = lock;
			break;
		case PWM_Channel4:
			PWM24HLD = lock;
			break;
		case PWM_Channel5:
			PWM25HLD = lock;
			break;
		case PWM_Channel6:
			PWM26HLD = lock;
			break;
		case PWM_Channel7:
			PWM27HLD = lock;
			break;
		}
		#endif // MCU_SERIES == 'A'
	#else
		// STC8A8KxxS4A12
		switch (channel) {
		case PWM_Channel0:
			PWM00HLD = lock;
			break;
		case PWM_Channel1:
			PWM01HLD = lock;
			break;
		case PWM_Channel2:
			PWM02HLD = lock;
			break;
		case PWM_Channel3:
			PWM03HLD = lock;
			break;
		case PWM_Channel4:
			PWM04HLD = lock;
			break;
		case PWM_Channel5:
			PWM05HLD = lock;
			break;
		case PWM_Channel6:
			PWM06HLD = lock;
			break;
		case PWM_Channel7:
			PWM07HLD = lock;
			break;
		}
	#endif // MCU_HAS_ENHANCED_PWM == 'G'
	
	DISABLE_EXTENDED_SFR();
#endif // MCU_HAS_ENHANCED_PWM == '5'
}

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pwmUnlockChannel(PWM_Channel channel) {
#if MCU_HAS_ENHANCED_PWM != '5'
	ENABLE_EXTENDED_SFR();
	
	#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
		#if MCU_SERIES == 'A'
		// STC8A8KxxD4
		switch (channel) {
		case PWM_Channel0:
			PWM00HLD = 0;
			break;
		case PWM_Channel1:
			PWM01HLD = 0;
			break;
		case PWM_Channel2:
			PWM02HLD = 0;
			break;
		case PWM_Channel3:
			PWM03HLD = 0;
			break;
		case PWM_Channel4:
			PWM04HLD = 0;
			break;
		case PWM_Channel5:
			PWM05HLD = 0;
			break;
		case PWM_Channel6:
			PWM06HLD = 0;
			break;
		case PWM_Channel7:
			PWM07HLD = 0;
			break;
		}
		#else
		// STC8G2K*
		switch (channel) {
		case PWM_Channel0:
			PWM20HLD = 0;
			break;
		case PWM_Channel1:
			PWM21HLD = 0;
			break;
		case PWM_Channel2:
			PWM22HLD = 0;
			break;
		case PWM_Channel3:
			PWM23HLD = 0;
			break;
		case PWM_Channel4:
			PWM24HLD = 0;
			break;
		case PWM_Channel5:
			PWM25HLD = 0;
			break;
		case PWM_Channel6:
			PWM26HLD = 0;
			break;
		case PWM_Channel7:
			PWM27HLD = 0;
			break;
		}
		#endif // MCU_SERIES == 'A'
	#else
		// STC8A8KxxS4A12
		switch (channel) {
		case PWM_Channel0:
			PWM00HLD = 0;
			break;
		case PWM_Channel1:
			PWM01HLD = 0;
			break;
		case PWM_Channel2:
			PWM02HLD = 0;
			break;
		case PWM_Channel3:
			PWM03HLD = 0;
			break;
		case PWM_Channel4:
			PWM04HLD = 0;
			break;
		case PWM_Channel5:
			PWM05HLD = 0;
			break;
		case PWM_Channel6:
			PWM06HLD = 0;
			break;
		case PWM_Channel7:
			PWM07HLD = 0;
			break;
		}
	#endif // MCU_HAS_ENHANCED_PWM == 'G'
	
	DISABLE_EXTENDED_SFR();
#endif // MCU_HAS_ENHANCED_PWM != '5'
}
#pragma restore
