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
 * Supported MCU: STC15W4KxxS4, STC8A8KxxS4A12, STC8A8KxxD4, STC8G2K*.
 * 
 * IMPORTANT1: on the STC8G2K*, only PWM20..27 are supported, and 
 * correspond to ENHPWM_Channel0..7 respectively.
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
 */

#include "gpio-hal.h"

typedef enum {
	ENHPWM_SYSCLK_DIV_1 = 0,
	ENHPWM_SYSCLK_DIV_2 = 1,
	ENHPWM_SYSCLK_DIV_3 = 2,
	ENHPWM_SYSCLK_DIV_4 = 3,
	ENHPWM_SYSCLK_DIV_5 = 4,
	ENHPWM_SYSCLK_DIV_6 = 5,
	ENHPWM_SYSCLK_DIV_7 = 6,
	ENHPWM_SYSCLK_DIV_8 = 7,
	ENHPWM_SYSCLK_DIV_9 = 8,
	ENHPWM_SYSCLK_DIV_10 = 9,
	ENHPWM_SYSCLK_DIV_11 = 10,
	ENHPWM_SYSCLK_DIV_12 = 11,
	ENHPWM_SYSCLK_DIV_13 = 12,
	ENHPWM_SYSCLK_DIV_14 = 13,
	ENHPWM_SYSCLK_DIV_15 = 14,
	ENHPWM_SYSCLK_DIV_16 = 15,
	ENHPWM_TIMER2 = 16,
} ENHPWM_ClockSource;

typedef enum {
	ENHPWM_Channel0 = 0,
	ENHPWM_Channel1,
	ENHPWM_Channel2,
	ENHPWM_Channel3,
	ENHPWM_Channel4,
	ENHPWM_Channel5,
#if PWM_CHANNELS > 6
	ENHPWM_Channel6,
	ENHPWM_Channel7,
#endif // PWM_CHANNELS > 6
} ENHPWM_Channel;

typedef enum {
	ENHPWM_INTERRUPT_EVENT_NONE = 0,
	ENHPWM_INTERRUPT_EVENT_T1_ONLY = 5,
	ENHPWM_INTERRUPT_EVENT_T2_ONLY = 6,
	ENHPWM_INTERRUPT_EVENT_T1_AND_T2 = 7,
} ENHPWM_InterruptOnEvent;

typedef enum {
	ENHPWM_INTERRUPT_DISABLE = 0,
	ENHPWM_INTERRUPT_ENABLE = 1,
} ENHPWM_InterruptEnable;

typedef enum {
	ENHPWM_LOW = 0,
	ENHPWM_HIGH = 1,
} ENHPWM_OutputLevel;

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
void enhpwmInitialise(ENHPWM_ClockSource clockSource, uint16_t divisor, ENHPWM_InterruptEnable overflowInterrupt);

/**
 * Configures a PCA channel in PWM mode.
 * 
 * The duty cycle is defined by the number of clockSource pulses during 
 * which the PWM output must be high.
 */
void enhpwmStartChannel(ENHPWM_Channel channel, uint8_t pinSwitch, GpioPortMode pinMode, ENHPWM_OutputLevel initialLevel, ENHPWM_InterruptOnEvent interruptOnEvent, uint16_t clocksHigh);

/**
 * Changes the duty cycle of a PWM channel.
 * 
 * All other configuration parameters remain unchanged.
 */
void enhpwmSetDutyCycle(ENHPWM_Channel channel, uint16_t clocksHigh);

#if MCU_HAS_ENHANCED_PWM != '5'
	// The STC15W4K doesn't have PWMxxHLD SFR
	
	void enhpwmLockChannel(ENHPWM_Channel channel, ENHPWM_OutputLevel outputLevel);

	void enhpwmUnlockChannel(ENHPWM_Channel channel);
#endif // MCU_HAS_ENHANCED_PWM != '5'

#endif // _ENHPWM_HAL_H
