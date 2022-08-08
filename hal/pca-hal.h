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
#ifndef _PCA_HAL_H
#define _PCA_HAL_H

/**
 * @file pca-hal.h
 * 
 * PCA abstraction definitions.
 * 
 * Supported MCU:
 * 
 *     STC12*
 *     STC15*
 *     STC8A*
 *     STC8G*
 * 
 * Dependencies:
 * 
 *     gpio-hal
 *     timer-hal (only when using Timer 0 as clock source)
 * 
 * Optional macros:
 * 
 *     HAL_PCA_SEGMENT (default: __idata) defines where the HAL's 
 *     state information will be stored. Impacts ISR execution time.
 * 
 *     HAL_PCA_CHANNELS (default: PCA_CHANNELS) defines how many PCA
 *     channels will be supported by the HAL. Useful to reduce both
 *     flash and RAM footprint.
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 */

#include "hal-defs.h"

typedef enum {
	PCA_CONTINUOUS = 0,
	PCA_ONE_SHOT = 1,
} PCA_CaptureMode;

/**
 * PCA pin configurations for STC8G *except* STC8G1K08A and STC8G1K08T
 * 
 * Value | CCP0 | CCP1 | CCP2 | ECI
 * ------+------+------+------+-----
 *   0   | P1.1 | P1.0 | P3.7 | P1.2
 *   1   | P3.5 | P3.6 | P3.7 | P3.4
 *   2   | P2.5 | P2.6 | P2.7 | P2.4
 * 
 * PCA pin configurations for STC8G1K08A
 * 
 * Value | CCP0 | CCP1 | CCP2 | ECI
 * ------+------+------+------+-----
 *   0   | P3.2 | P3.3 | P5.4 | P5.5
 *   1   | P3.2 | P3.3 | P5.5 | P3.1
 *   2   | P3.1 | P3.3 | P5.4 | P5.5
 * 
 * PCA pin configurations for STC8A
 * 
 * Value | CCP0 | CCP1 | CCP2 | CCP3 | ECI
 * ------+------+------+------+------+-----
 *   0   | P1.7 | P1.6 | P1.5 | P1.4 | P1.2
 *   1   | P2.3 | P2.4 | P2.5 | P2.6 | P2.2
 *   2   | P7.0 | P7.1 | P7.2 | P7.3 | P7.4
 *   3   | P3.3 | P3.2 | P3.1 | P3.0 | P3.5
 * 
 * PCA pin configurations for STC15
 * 
 * Value | CCP0 | CCP1 | CCP2 | ECI
 * ------+------+------+------+-----
 *   0   | P1.1 | P1.0 | P3.7 | P1.2
 *   1   | P3.5 | P3.6 | P3.7 | P3.4
 *   2   | P2.5 | P2.6 | P2.7 | P2.4 (not available on STC15W4xxAS)
 * 
 * PCA pin configurations for STC12
 * 
 * Value | CCP0 | CCP1 | ECI
 * ------+------+------+-----
 *   0   | P1.3 | P1.4 | P1.2
 *   1   | P4.2 | P4.3 | P4.1
 */

INTERRUPT_USING(__pca_isr, PCA_INTERRUPT, 1);

/**
 * Initialises the master counter of the counter array.
 * 
 * For source code clarity, should be called before any other PCA_* function.
 * 
 * PCA = Programmable Counter Array
 * 
 * CCP = Compare / Capture / PWM
 */
void pcaInitialise(PCA_ClockSource clockSource, CounterControl counterMode, InterruptEnable overflowInterrupt, uint8_t pinSwitch);

/**
 * Configures a PCA channel to measure the width of a pulse.
 * 
 * The calculated 32-bit duration will be shifted right 'shiftBits' 
 * bits to get an uint16_t to pass to pca_onInterrupt().
 * 
 * shiftBits > 23 makes no sense, but be aware no check is made.
 */
void pcaStartCapture(PCA_Channel channel, GpioPinMode pinMode, PCA_EdgeTrigger trigger, PCA_CaptureMode captureMode, uint8_t shiftBits);

/**
 * Configures a PCA channel in PWM mode.
 * 
 * The duty cycle is defined by the number of clockSource pulses during 
 * which the PWM output must be high.
 */
void pcaStartPwm(PCA_Channel channel, GpioPinMode pinMode, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh);

/**
 * Changes the duty cycle of a PWM channel.
 * 
 * All other configuration parameters remain unchanged.
 */
void pcaSetPwmDutyCycle(PCA_Channel channel, uint16_t clocksHigh);

/**
 * Configures a PCA channel in 16-bit software timer / pulse output mode.
 * 
 * timerPeriod is expressed as a number of clockSource pulses.
 */
void pcaStartTimer(PCA_Channel channel, GpioPinMode pinMode, OutputEnable pulseOutput, uint16_t timerPeriod);

/**
 * MUST be implemented by the application, even when not used.
 * 
 * **IMPORTANT** We're inside an ISR, so just keep track of the values 
 * but DON'T do any processing there!
 */
void pcaOnInterrupt(PCA_Channel channel, uint16_t pulseLength) USE_BANK(1);

#endif // _PCA_HAL_H
