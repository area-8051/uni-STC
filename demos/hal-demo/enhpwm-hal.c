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
#include "enhpwm-hal.h"

/**
 * @file enhpwm-hal.c
 * 
 * 15-bit enhanced PWM abstraction implementation.
 */

static const uint8_t __pinConfigurations[][PWM_CHANNELS] = {
#if MCU_HAS_ENHANCED_PWM == '5'
	// STC15W4K
	{ 0x37, 0x22, 0x21, 0x23, 0x16, 0x17 }, 
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

#define PIN_CONFIG_MAX (sizeof(__pinConfigurations) / sizeof(__pinConfigurations[0]))

// On the STC8G2K* and the STC8A8KxxD4, GPIO ports are configured
// in high-impedance mode by default, so configuring the channel 
// output pin mode is *REQUIRED*.
static void __configureOutput(ENHPWM_Channel channel, uint8_t pinSwitch, GpioPortMode pinMode) {
	if (pinSwitch >= PIN_CONFIG_MAX) {
		pinSwitch = 0;
	}
	
	switch (pinMode) {
	case GPIO_BIDIRECTIONAL:
	case GPIO_PUSH_PULL:
		break;
	default:
		pinMode = GPIO_BIDIRECTIONAL;
		break;
	}
	
	uint8_t channelPin = __pinConfigurations[pinSwitch][channel];
	GpioPort port = (GpioPort) (channelPin >> 4);
	GpioPin pin = (GpioPin) (channelPin & 0x0f);
	GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, pinMode);
	gpioConfigure(&pinConfig);
}

void enhpwmInitialise(ENHPWM_ClockSource clockSource, uint16_t divisor, ENHPWM_InterruptEnable overflowInterrupt) {
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

void enhpwmStartChannel(ENHPWM_Channel channel, uint8_t pinSwitch, GpioPortMode pinMode, ENHPWM_OutputLevel initialLevel, ENHPWM_InterruptOnEvent interruptOnEvent, uint16_t clocksHigh) {
	__configureOutput(channel, pinSwitch, pinMode);
	enhpwmSetDutyCycle(channel, clocksHigh);
	uint8_t channelCR = interruptOnEvent;
	
	#ifdef M_C_S
		// STC8G2K doesn't support pin switch
		channelCR |= (pinSwitch << P_C_S) & M_C_S;
	#endif // M_C_S
	
	#if MCU_HAS_ENHANCED_PWM != '5' // STC8A and STC8G2K
		channelCR |= M_ENO;
		channelCR |= (initialLevel << P_INI) & M_INI;
	#endif // MCU_HAS_ENHANCED_PWM != '5'
	
	ENABLE_EXTENDED_SFR();
	
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A' // STC8A8KxxD4
		switch (channel) {
		case ENHPWM_Channel0:
			PWM00T1H = 0;
			PWM00T1L = 0;
			PWM00CR = channelCR;
			break;
		case ENHPWM_Channel1:
			PWM01T1H = 0;
			PWM01T1L = 0;
			PWM01CR = channelCR;
			break;
		case ENHPWM_Channel2:
			PWM02T1H = 0;
			PWM02T1L = 0;
			PWM02CR = channelCR;
			break;
		case ENHPWM_Channel3:
			PWM03T1H = 0;
			PWM03T1L = 0;
			PWM03CR = channelCR;
			break;
		case ENHPWM_Channel4:
			PWM04T1H = 0;
			PWM04T1L = 0;
			PWM04CR = channelCR;
			break;
		case ENHPWM_Channel5:
			PWM05T1H = 0;
			PWM05T1L = 0;
			PWM05CR = channelCR;
			break;
		case ENHPWM_Channel6:
			PWM06T1H = 0;
			PWM06T1L = 0;
			PWM06CR = channelCR;
			break;
		case ENHPWM_Channel7:
			PWM07T1H = 0;
			PWM07T1L = 0;
			PWM07CR = channelCR;
			break;
		}
	#else // STC8G2K
		switch (channel) {
		case ENHPWM_Channel0:
			PWM20T1H = 0;
			PWM20T1L = 0;
			PWM20CR = channelCR;
			break;
		case ENHPWM_Channel1:
			PWM21T1H = 0;
			PWM21T1L = 0;
			PWM21CR = channelCR;
			break;
		case ENHPWM_Channel2:
			PWM22T1H = 0;
			PWM22T1L = 0;
			PWM22CR = channelCR;
			break;
		case ENHPWM_Channel3:
			PWM23T1H = 0;
			PWM23T1L = 0;
			PWM23CR = channelCR;
			break;
		case ENHPWM_Channel4:
			PWM24T1H = 0;
			PWM24T1L = 0;
			PWM24CR = channelCR;
			break;
		case ENHPWM_Channel5:
			PWM25T1H = 0;
			PWM25T1L = 0;
			PWM25CR = channelCR;
			break;
		case ENHPWM_Channel6:
			PWM26T1H = 0;
			PWM26T1L = 0;
			PWM26CR = channelCR;
			break;
		case ENHPWM_Channel7:
			PWM27T1H = 0;
			PWM27T1L = 0;
			PWM27CR = channelCR;
			break;
		}
	#endif // MCU_SERIES == 'A'
	
	DISABLE_EXTENDED_SFR();
#else // STC8A8KxxS4A12 and STC15W4K
	switch (channel) {
	case ENHPWM_Channel0:
		PWM00T1H = 0;
		PWM00T1L = 0;
		PWM00CR = channelCR;
		break;
	case ENHPWM_Channel1:
		PWM01T1H = 0;
		PWM01T1L = 0;
		PWM01CR = channelCR;
		break;
	case ENHPWM_Channel2:
		PWM02T1H = 0;
		PWM02T1L = 0;
		PWM02CR = channelCR;
		break;
	case ENHPWM_Channel3:
		PWM03T1H = 0;
		PWM03T1L = 0;
		PWM03CR = channelCR;
		break;
	case ENHPWM_Channel4:
		PWM04T1H = 0;
		PWM04T1L = 0;
		PWM04CR = channelCR;
		break;
	case ENHPWM_Channel5:
		PWM05T1H = 0;
		PWM05T1L = 0;
		PWM05CR = channelCR;
		break;
	#if PWM_CHANNELS > 6
		case ENHPWM_Channel6:
			PWM06T1H = 0;
			PWM06T1L = 0;
			PWM06CR = channelCR;
			break;
		case ENHPWM_Channel7:
			PWM07T1H = 0;
			PWM07T1L = 0;
			PWM07CR = channelCR;
			break;
	#endif // PWM_CHANNELS > 6
	}
	
	DISABLE_EXTENDED_SFR();
	
	#if MCU_HAS_ENHANCED_PWM == '5' // STC15W4K
		PWMCFG |= initialLevel << channel;
		PWMCR |= 1 << channel;
	#endif // MCU_HAS_ENHANCED_PWM == '5'
#endif // MCU_HAS_ENHANCED_PWM == 'G'
}

void enhpwmSetDutyCycle(ENHPWM_Channel channel, uint16_t clocksHigh) {
	ENABLE_EXTENDED_SFR();
	
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A' // STC8A8KxxD4
		switch (channel) {
		case ENHPWM_Channel0:
			PWM00T2H = clocksHigh >> 8;
			PWM00T2L = clocksHigh;
			break;
		case ENHPWM_Channel1:
			PWM01T2H = clocksHigh >> 8;
			PWM01T2L = clocksHigh;
			break;
		case ENHPWM_Channel2:
			PWM02T2H = clocksHigh >> 8;
			PWM03T2L = clocksHigh;
			break;
		case ENHPWM_Channel3:
			PWM03T2H = clocksHigh >> 8;
			PWM03T2L = clocksHigh;
			break;
		case ENHPWM_Channel4:
			PWM04T2H = clocksHigh >> 8;
			PWM04T2L = clocksHigh;
			break;
		case ENHPWM_Channel5:
			PWM05T2H = clocksHigh >> 8;
			PWM05T2L = clocksHigh;
			break;
		case ENHPWM_Channel6:
			PWM06T2H = clocksHigh >> 8;
			PWM06T2L = clocksHigh;
			break;
		case ENHPWM_Channel7:
			PWM07T2H = clocksHigh >> 8;
			PWM07T2L = clocksHigh;
			break;
		}
	#else // STC8G2K
		switch (channel) {
		case ENHPWM_Channel0:
			PWM20T2H = clocksHigh >> 8;
			PWM20T2L = clocksHigh;
			break;
		case ENHPWM_Channel1:
			PWM21T2H = clocksHigh >> 8;
			PWM21T2L = clocksHigh;
			break;
		case ENHPWM_Channel2:
			PWM22T2H = clocksHigh >> 8;
			PWM23T2L = clocksHigh;
			break;
		case ENHPWM_Channel3:
			PWM23T2H = clocksHigh >> 8;
			PWM23T2L = clocksHigh;
			break;
		case ENHPWM_Channel4:
			PWM24T2H = clocksHigh >> 8;
			PWM24T2L = clocksHigh;
			break;
		case ENHPWM_Channel5:
			PWM25T2H = clocksHigh >> 8;
			PWM25T2L = clocksHigh;
			break;
		case ENHPWM_Channel6:
			PWM26T2H = clocksHigh >> 8;
			PWM26T2L = clocksHigh;
			break;
		case ENHPWM_Channel7:
			PWM27T2H = clocksHigh >> 8;
			PWM27T2L = clocksHigh;
			break;
		}
	#endif // MCU_SERIES == 'A'
#else // STC8A8KxxS4A12 and STC15W4K
	switch (channel) {
	case ENHPWM_Channel0:
		PWM00T2H = clocksHigh >> 8;
		PWM00T2L = clocksHigh;
		break;
	case ENHPWM_Channel1:
		PWM01T2H = clocksHigh >> 8;
		PWM01T2L = clocksHigh;
		break;
	case ENHPWM_Channel2:
		PWM02T2H = clocksHigh >> 8;
		PWM03T2L = clocksHigh;
		break;
	case ENHPWM_Channel3:
		PWM03T2H = clocksHigh >> 8;
		PWM03T2L = clocksHigh;
		break;
	case ENHPWM_Channel4:
		PWM04T2H = clocksHigh >> 8;
		PWM04T2L = clocksHigh;
		break;
	case ENHPWM_Channel5:
		PWM05T2H = clocksHigh >> 8;
		PWM05T2L = clocksHigh;
		break;
	#if PWM_CHANNELS > 6
		case ENHPWM_Channel6:
			PWM06T2H = clocksHigh >> 8;
			PWM06T2L = clocksHigh;
			break;
		case ENHPWM_Channel7:
			PWM07T2H = clocksHigh >> 8;
			PWM07T2L = clocksHigh;
			break;
	#endif // PWM_CHANNELS > 6
	}
#endif // MCU_HAS_ENHANCED_PWM == 'G'
	DISABLE_EXTENDED_SFR();
}

#if MCU_HAS_ENHANCED_PWM != '5'
	// The STC15W4K doesn't have PWMxxHLD SFR

	void enhpwmLockChannel(ENHPWM_Channel channel, ENHPWM_OutputLevel outputLevel) {
		uint8_t lock = outputLevel ? M_HLDH : M_HLDL;
		ENABLE_EXTENDED_SFR();
		
	#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
		#if MCU_SERIES == 'A' // STC8A8KxxD4
			switch (channel) {
			case ENHPWM_Channel0:
				PWM00HLD = lock;
				break;
			case ENHPWM_Channel1:
				PWM01HLD = lock;
				break;
			case ENHPWM_Channel2:
				PWM02HLD = lock;
				break;
			case ENHPWM_Channel3:
				PWM03HLD = lock;
				break;
			case ENHPWM_Channel4:
				PWM04HLD = lock;
				break;
			case ENHPWM_Channel5:
				PWM05HLD = lock;
				break;
			case ENHPWM_Channel6:
				PWM06HLD = lock;
				break;
			case ENHPWM_Channel7:
				PWM07HLD = lock;
				break;
			}
		#else // STC8G2K
			switch (channel) {
			case ENHPWM_Channel0:
				PWM20HLD = lock;
				break;
			case ENHPWM_Channel1:
				PWM21HLD = lock;
				break;
			case ENHPWM_Channel2:
				PWM22HLD = lock;
				break;
			case ENHPWM_Channel3:
				PWM23HLD = lock;
				break;
			case ENHPWM_Channel4:
				PWM24HLD = lock;
				break;
			case ENHPWM_Channel5:
				PWM25HLD = lock;
				break;
			case ENHPWM_Channel6:
				PWM26HLD = lock;
				break;
			case ENHPWM_Channel7:
				PWM27HLD = lock;
				break;
			}
		#endif // MCU_SERIES == 'A'
	#else // STC8A8KxxS4A12
		switch (channel) {
		case ENHPWM_Channel0:
			PWM00HLD = lock;
			break;
		case ENHPWM_Channel1:
			PWM01HLD = lock;
			break;
		case ENHPWM_Channel2:
			PWM02HLD = lock;
			break;
		case ENHPWM_Channel3:
			PWM03HLD = lock;
			break;
		case ENHPWM_Channel4:
			PWM04HLD = lock;
			break;
		case ENHPWM_Channel5:
			PWM05HLD = lock;
			break;
		case ENHPWM_Channel6:
			PWM06HLD = lock;
			break;
		case ENHPWM_Channel7:
			PWM07HLD = lock;
			break;
		}
	#endif // MCU_HAS_ENHANCED_PWM == 'G'
		
		DISABLE_EXTENDED_SFR();
	}

	void enhpwmUnlockChannel(ENHPWM_Channel channel) {
		ENABLE_EXTENDED_SFR();
		
	#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
		#if MCU_SERIES == 'A' // STC8A8KxxD4
			switch (channel) {
			case ENHPWM_Channel0:
				PWM00HLD = 0;
				break;
			case ENHPWM_Channel1:
				PWM01HLD = 0;
				break;
			case ENHPWM_Channel2:
				PWM02HLD = 0;
				break;
			case ENHPWM_Channel3:
				PWM03HLD = 0;
				break;
			case ENHPWM_Channel4:
				PWM04HLD = 0;
				break;
			case ENHPWM_Channel5:
				PWM05HLD = 0;
				break;
			case ENHPWM_Channel6:
				PWM06HLD = 0;
				break;
			case ENHPWM_Channel7:
				PWM07HLD = 0;
				break;
			}
		#else // STC8G2K
			switch (channel) {
			case ENHPWM_Channel0:
				PWM20HLD = 0;
				break;
			case ENHPWM_Channel1:
				PWM21HLD = 0;
				break;
			case ENHPWM_Channel2:
				PWM22HLD = 0;
				break;
			case ENHPWM_Channel3:
				PWM23HLD = 0;
				break;
			case ENHPWM_Channel4:
				PWM24HLD = 0;
				break;
			case ENHPWM_Channel5:
				PWM25HLD = 0;
				break;
			case ENHPWM_Channel6:
				PWM26HLD = 0;
				break;
			case ENHPWM_Channel7:
				PWM27HLD = 0;
				break;
			}
		#endif // MCU_SERIES == 'A'
	#else // STC8A8KxxS4A12
		switch (channel) {
		case ENHPWM_Channel0:
			PWM00HLD = 0;
			break;
		case ENHPWM_Channel1:
			PWM01HLD = 0;
			break;
		case ENHPWM_Channel2:
			PWM02HLD = 0;
			break;
		case ENHPWM_Channel3:
			PWM03HLD = 0;
			break;
		case ENHPWM_Channel4:
			PWM04HLD = 0;
			break;
		case ENHPWM_Channel5:
			PWM05HLD = 0;
			break;
		case ENHPWM_Channel6:
			PWM06HLD = 0;
			break;
		case ENHPWM_Channel7:
			PWM07HLD = 0;
			break;
		}
	#endif // MCU_HAS_ENHANCED_PWM == 'G'
		
		DISABLE_EXTENDED_SFR();
	}

#endif // MCU_HAS_ENHANCED_PWM != '5'
