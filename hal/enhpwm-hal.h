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
 * IMPORTANT1: on the STC8G2K*, only PWM20..27 are supported, and 
 * correspond to PWM_Channel0..7 respectively.
 * 
 * Rationale: the STC8G2K* seems to be an exception as STC never
 * manufactured another MCU with as many PWM channels. Instead, the
 * advanced 16-bit PWM of the STC8H family offers 8 channels again.
 * It seems the industry just wants more _independent_ PWM channels, 
 * and _not_ a higher total count of PWM outputs.
 * 
 * The purpose of a HAL being to reduce complexity and increase 
 * hardware independence, using a maximum of 8 PWM channels was
 * the most sensible option.
 * 
 * IMPORTANT2: on the STC15W4K*, STC numbered enhanced PWM channels 
 * PWM2..7 (the 2 available CCP channels counting for PWM0 and PWM1 
 * in their mind). However, enhanced PWM channels on the STC8A are 
 * numbered from 0 to 7. Furthermore, PWM2 SFRs on the STC15 are at 
 * the same addresses as PWM0's on the STC8A.
 * 
 * For consistency, I decided to number the enhanced PWM channels
 * of the STC15 from 0 to 5, aligned with those of the STC8A, as 
 * this improves portability between MCU families (the first enhanced
 * PWM channel is always PWM0 on all MCU).
 * 
 * IMPORTANT3: when using interrupts, don't forget to declare your
 * interrupt service routine, this HAL module doesn't provide one.
 * Its prototype must be either, for the STC8G2K:
 *     INTERRUPT_USING(__enhpwm_isr, PWM2_INTERRUPT, 1);
 * or, for all other MCU:
 *     INTERRUPT_USING(__enhpwm_isr, PWM0_INTERRUPT, 1);
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
 * Initialises and starts the master counter.
 */
void pwmInitialise(
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
 * Configures a PCA channel in PWM mode.
 */
void pwmStartChannel(
	PWM_Channel channel, 
	uint8_t pinSwitch, 
	GpioPinMode pinMode, 
	OutputLevel initialLevel, 
	PWM_InterruptOnEvent interruptOnEvent, 
	uint16_t flipPoint1, 
	uint16_t flipPoint2
);

/**
 * Changes the flip points of a PWM channel.
 * 
 * All other configuration parameters remain unchanged.
 */
void pwmSetFlipPoints(PWM_Channel channel, uint16_t flipPoint1, uint16_t flipPoint2);

#if MCU_HAS_ENHANCED_PWM != '5'
	// The STC15W4K doesn't have PWMxxHLD SFR
	
	void pwmLockChannel(PWM_Channel channel, OutputLevel outputLevel);

	void pwmUnlockChannel(PWM_Channel channel);
#endif // MCU_HAS_ENHANCED_PWM != '5'

#endif // _PWM_HAL_H
