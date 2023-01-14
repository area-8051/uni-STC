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
#ifndef _ENHPWM_HAL_H
#define _ENHPWM_HAL_H

/**
 * @file enhpwm-hal.h
 * 
 * 15-bit enhanced PWM abstraction definitions.
 * 
 * Supported MCU:
 * 
 *     STC15W4KxxS4
 *     STC8A8KxxS4A12
 *     STC8A8KxxD4
 *     STC8G2K*
 * 
 * Dependencies:
 * 
 *     gpio-hal
 * 
 * IMPORTANT 1:
 * 
 * On the STC8G2K*, only PWM20..27 are supported, and correspond to 
 * PWM_Channel0..7 respectively.
 * 
 * Rationale: the STC8G2KxxS4 seems to be an exception as STC never
 * manufactured another MCU with as many PWM channels. Moreover, the
 * STC8G2KxxS2 variant has only PWM2!
 * 
 * Furthermore, the advanced 16-bit PWM of the STC8H family also offers
 * only 8 channels. It seems the industry just wants more *independent*
 * PWM channels, rather than a higher total count of PWM outputs.
 * 
 * The purpose of a HAL being to reduce complexity and increase 
 * hardware independence, using a maximum of 8 PWM channels was
 * thus the most sensible option.
 * 
 * IMPORTANT 2:
 * 
 * On the STC15W4K*, STC numbered enhanced PWM channels PWM2..7 (the 
 * 2 available CCP channels counting for PWM0 and PWM1 in their mind).
 * However, enhanced PWM channels on the STC8A are numbered from 0 to 7. 
 * Furthermore, PWM2 SFRs on the STC15 are at the same addresses as 
 * PWM0's on the STC8A.
 * 
 * For consistency, I decided to number the enhanced PWM channels
 * of the STC15 from 0 to 5, aligned with those of the STC8A, as 
 * this improves portability between MCU families (the first enhanced
 * PWM channel is always PWM0 on all MCU).
 * 
 * IMPORTANT 3:
 * 
 * When using interrupts, don't forget to declare your ISR, this HAL
 * module doesn't provide one.
 * 
 * Its prototype must be either, for the STC8G2K:
 * 
 *     INTERRUPT_USING(enhpwm_isr, PWM2_INTERRUPT, 1);
 * 
 * or, for all other MCU:
 * 
 *     INTERRUPT_USING(enhpwm_isr, PWM0_INTERRUPT, 1);
 */

#include <hal-defs.h>

typedef enum {
	PWM_SYSCLK_DIV_1 = 0,
	PWM_SYSCLK_DIV_2 = 1,
	PWM_SYSCLK_DIV_3 = 2,
	PWM_SYSCLK_DIV_4 = 3,
	PWM_SYSCLK_DIV_5 = 4,
	PWM_SYSCLK_DIV_6 = 5,
	PWM_SYSCLK_DIV_7 = 6,
	PWM_SYSCLK_DIV_8 = 7,
	PWM_SYSCLK_DIV_9 = 8,
	PWM_SYSCLK_DIV_10 = 9,
	PWM_SYSCLK_DIV_11 = 10,
	PWM_SYSCLK_DIV_12 = 11,
	PWM_SYSCLK_DIV_13 = 12,
	PWM_SYSCLK_DIV_14 = 13,
	PWM_SYSCLK_DIV_15 = 14,
	PWM_SYSCLK_DIV_16 = 15,
	PWM_TIMER2 = 16,
} PWM_ClockSource;

typedef enum {
	PWM_Channel0 = 0,
	PWM_Channel1,
	PWM_Channel2,
	PWM_Channel3,
	PWM_Channel4,
	PWM_Channel5,
#if PWM_CHANNELS > 6
	PWM_Channel6,
	PWM_Channel7,
#endif // PWM_CHANNELS > 6
} PWM_Channel;

typedef enum {
	PWM_INTERRUPT_EVENT_NONE = 0,
	PWM_INTERRUPT_EVENT_T1_ONLY = 5,
	PWM_INTERRUPT_EVENT_T2_ONLY = 6,
	PWM_INTERRUPT_EVENT_T1_AND_T2 = 7,
} PWM_InterruptOnEvent;

/**
 * Pin configurations for STC8G2K*
 * 
 * Value | PWM0 | PWM1 | PWM2 | PWM3 | PWM4 | PWM5 | PWM6 | PWM7 
 * ------+------+------+------+------+------+------+------+------
 *   0   | P2.0 | P2.1 | P2.2 | P2.3 | P2.4 | P2.5 | P2.6 | P2.7 
 * 
 * Pin configurations for STC8A8KxxS4A12 and STC8A8KxxD4
 * 
 * Value | PWM0 | PWM1 | PWM2 | PWM3 | PWM4 | PWM5 | PWM6 | PWM7 
 * ------+------+------+------+------+------+------+------+------
 *   0   | P2.0 | P2.1 | P2.2 | P2.3 | P2.4 | P2.5 | P2.6 | P2.7 
 *   1   | P1.0 | P1.1 | P1.2 | P1.3 | P1.4 | P1.5 | P1.6 | P1.7 
 *   2   | P6.0 | P6.1 | P6.2 | P6.3 | P6.4 | P6.5 | P6.6 | P6.7 
 * 
 * Pin configurations for STC15
 * 
 * Value | PWM0 | PWM1 | PWM2 | PWM3 | PWM4 | PWM5 
 * ------+------+------+------+------+------+------
 *   0   | P3.7 | P2.2 | P2.1 | P2.3 | P1.6 | P1.7 
 *   1   | P2.7 | P4.5 | P4.4 | P4.2 | P0.7 | P0.6 
 */

/**
 * Configures and starts the master counter.
 */
void pwmStartCounter(
	PWM_ClockSource clockSource, 
	uint16_t divisor, 
	InterruptEnable overflowInterrupt
);

/**
 * Configures PWM fault detection, aka. "brake".
 */

typedef enum {
	TRIGGER_ON_PWMFLT_RISING_EDGE = 0x22,
#ifdef M_INVIO
	TRIGGER_ON_PWMFLT_FALLING_EDGE = 0x62,
#endif // M_INVIO

	TRIGGER_ON_COMPARATOR_RISING_EDGE = 0x24,
#ifdef M_INVCMP
	TRIGGER_ON_COMPARATOR_FALLING_EDGE = 0xa4,
#endif // M_INVCMP
} PWM_FaultTrigger;

typedef enum {
	PWM_OUTPUT_STAY_UNCHANGED = 0,
	PWM_OUTPUT_GO_HIGH_IMPEDANCE = 0x10,
} PWM_FaultResponse;

void pwmConfigureFaultDetection(
	PWM_FaultTrigger faultTrigger, 
	PWM_FaultResponse faultResponse, 
	InterruptEnable faultInterrupt
);

/**
 * Resets the configuration of the master counter.
 * pwmStartCounter() must be called again to restart the PWM counter.
 */
void pwmStopCounter();

/**
 * Configures the output pin of a PWM channel.
 * Must be called (once is enough) before using pwmStartCounter().
 */
void pwmConfigureOutput(
	PWM_Channel channel, 
	uint8_t pinSwitch, 
	GpioPinMode pinMode
);

/**
 * Configures and starts a PWM channel.
 */
void pwmStartChannel(
	PWM_Channel channel, 
	OutputLevel initialLevel, 
	PWM_InterruptOnEvent interruptOnEvent, 
	uint16_t flipPoint1, 
	uint16_t flipPoint2
);

/**
 * Resets the configuration of a PWM channel.
 * pwmStartChannel() must be called again to restart the channel.
 */
void pwmStopChannel(PWM_Channel channel);

/**
 * Changes the flip points of a PWM channel.
 * 
 * All other configuration parameters remain unchanged.
 */
void pwmSetFlipPoints(PWM_Channel channel, uint16_t flipPoint1, uint16_t flipPoint2);

/**
 * The STC15W4K doesn't have the PWMxxHLD SFR. We can emulate
 * pwmLockChannel(), but not pwmUnlockChannel(), you will need
 * to call pwmStartChannel() again to unlock it.
 */
void pwmLockChannel(PWM_Channel channel, OutputLevel outputLevel);

void pwmUnlockChannel(PWM_Channel channel);

/**
 * Helper macros to write generic ISR.
 * 
 * Examples:
 * 

INTERRUPT_USING(pwm_isr, PWM_INTERRUPT, 1) {
	if (PWM_COUNTER_IF_SFR & PWM_COUNTER_IF_MASK) {
		PWM_COUNTER_IF_SFR &= ~PWM_COUNTER_IF_MASK;
		// do something
	}
	
	PWM_CHANNEL_IF_SFR_ENABLE
	
	if (PWM_CHANNEL_IF_SFR & M_C0IF) {
		PWM_COUNTER_IF_SFR &= ~M_C0IF;
		// do something
	}
	
	PWM_CHANNEL_IF_SFR_DISABLE
}

INTERRUPT_USING(pwmfd_isr, PWMFD_INTERRUPT, 1) {
	PWMFD_SFR_ENABLE
	
	if (PWMFD_SFR & M_FDIF) {
		PWMFD_SFR &= ~M_FDIF;
		// do something
	}
	
	PWMFD_SFR_DISABLE
}
 */
#if MCU_HAS_ENHANCED_PWM == 'G' // STC8G2K and STC8A8KxxD4
	#if MCU_SERIES == 'A' // STC8A8KxxD4
		#define PWM_INTERRUPT PWM0_INTERRUPT
		#define PWM_COUNTER_IF_SFR PWMCFG01
		#define PWM_COUNTER_IF_MASK M_PWM0CBIF
		#define PWM_CHANNEL_IF_SFR PWM0IF
		
		#define PWMFD_INTERRUPT PWM0FD_INTERRUPT
		#define PWMFD_SFR PWM0FDCR
	#else
		#define PWM_INTERRUPT PWM2_INTERRUPT
		#define PWM_COUNTER_IF_SFR PWMCFG23
		#define PWM_COUNTER_IF_MASK M_PWM2CBIF
		#define PWM_CHANNEL_IF_SFR PWM2IF
		
		#define PWMFD_INTERRUPT PWM2FD_INTERRUPT
		#define PWMFD_SFR PWM2FDCR
	#endif
	
	#define PWM_CHANNEL_IF_SFR_ENABLE ENABLE_EXTENDED_SFR()
	#define PWM_CHANNEL_IF_SFR_DISABLE DISABLE_EXTENDED_SFR()
	
	#define PWMFD_SFR_ENABLE ENABLE_EXTENDED_SFR()
	#define PWMFD_SFR_DISABLE DISABLE_EXTENDED_SFR()
#else
	#if MCU_HAS_ENHANCED_PWM == 'A'
		#define PWM_COUNTER_IF_SFR PWMCFG
	#elif MCU_HAS_ENHANCED_PWM == '5'
		#define PWM_COUNTER_IF_SFR PWM0IF
	#endif
	
	#define PWM_INTERRUPT PWM0_INTERRUPT
	#define PWM_COUNTER_IF_MASK M_CBIF
	#define PWM_CHANNEL_IF_SFR PWM0IF
	#define PWM_CHANNEL_IF_SFR_ENABLE 
	#define PWM_CHANNEL_IF_SFR_DISABLE 
	
	#define PWMFD_INTERRUPT PWM0FR_INTERRUPT
	#define PWMFD_SFR PWM0FDCR
	#define PWMFD_SFR_ENABLE 
	#define PWMFD_SFR_DISABLE 
#endif

#endif // _PWM_HAL_H
