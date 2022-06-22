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
#include "delay.h"

/**
 * @file delay.c
 * 
 * Calibrated delay loops.
 */

/*
 * == STC8 timing ======================================================
 * 
 * Tested on STC8A8K64S4A12 - Internal RC oscillator @ 24 MHz.
 */
#if MCU_FAMILY == 8

#define DELAY_1ms ((unsigned int) (((MCU_FREQ / 1000UL) - 20UL) / 13UL))
/*
 * total_cycles = ms (13 n - (n div 256) + 17) - (ms div 256) + 10
 * total_cycles = delay (= 1e-3 s) * oscillator_frequency (= 2.4e7 Hz)
 * In order to round the result of the division to the closest integer,
 * we add 13/2 = 7 to the numerator, giving - 20UL instead of - 27UL.
 * n = 1844 => error = -0.0333 %
 */

#define DELAY_10us ((unsigned char) (((MCU_FREQ / 100000UL) - 16UL) / 6UL))
/*
 * total_cycles = us (6 n + 11) + 8
 * total_cycles = delay (= 1e-5 s) * oscillator_frequency (= 2.4e7 Hz)
 * In order to round the result of the division to the closest integer,
 * we add 6/2 = 3 to the numerator, giving - 16UL instead of - 19UL.
 * n = 37 => error = +0.4167 %
 */

#endif // MCU_FAMILY == 8
// =====================================================================


/*
 * == STC15 timing =====================================================
 * 
 * Tested on an STC15W4K32S4 - Internal RC oscillator @ 24 MHz.
 */
#if MCU_FAMILY == 15

#define DELAY_1ms ((unsigned int) (((MCU_FREQ / 1000UL) - 30UL) / 18UL))
/*
 * total_cycles = ms (18 n + 2 (n div 256) + 25) + 2 (ms div 256) + 14
 * total_cycles = delay (= 1e-3 s) * oscillator_frequency (= 2.4e7 Hz)
 * In order to round the result of the division to the closest integer,
 * we add 18/2 = 9 to the numerator, giving - 30UL instead of - 39UL.
 * n = 1331 => error = -0.0125 %
 */

#define DELAY_10us ((unsigned char) (((MCU_FREQ / 100000UL) - 23UL) / 10UL))
/*
 * total_cycles = us (10 n + 17) + 11
 * total_cycles = delay (= 1e-5 s) * oscillator_frequency (= 2.4e7 Hz)
 * In order to round the result of the division to the closest integer,
 * we add 10/2 = 5 to the numerator, giving - 23UL instead of - 28UL.
 * n = 21 => error = -0.9434 %
 */

#endif // MCU_FAMILY == 15
// =====================================================================


/*
 * == STC12 timing =====================================================
 * 
 * Tested on an STC12C5A60S2 - External 11.0952 MHz crystal.
 */
#if MCU_FAMILY == 12

#define DELAY_1ms ((unsigned int) (((MCU_FREQ / 1000UL) - 30UL) / 18UL))
/*
 * total_cycles = ms (19 n + 3 (n div 256) + 26) + 3 (ms div 256) + 14
 * total_cycles = delay (= 1e-3 s) * oscillator_frequency (in Hz)
 * In order to round the result of the division to the closest integer,
 * we add 19/2 = 9 to the numerator, giving - 30UL instead of - 39UL.
 */

#define DELAY_10us ((unsigned char) (((MCU_FREQ / 100000UL) - 23UL) / 10UL))
/*
 * total_cycles = us (10 n + 16) + 10
 * total_cycles = delay (= 1e-5 s) * oscillator_frequency (in Hz)
 * In order to round the result of the division to the closest integer,
 * we add 10/2 = 5 to the numerator, giving - 21UL instead of - 26UL.
 */

#endif // MCU_FAMILY == 12
// =====================================================================


/*
 * == STC90 timing =====================================================
 * 
 * Tested on an STC90C58RD+ - External 11.0952 MHz crystal.
 */
#if MCU_FAMILY == 90

#if MCU_CYCLES == 6
#define DELAY_1ms ((unsigned int) (((MCU_FREQ / 1000UL) - 114UL) / 72UL))
#else
#define DELAY_1ms ((unsigned int) (((MCU_FREQ / 1000UL) - 228UL) / 144UL))
#endif // MCU_CYCLES == 6

/*
 * 12T mode: total_cycles = ms (144 n + 12 (n div 256) + 180) + 12 (ms div 256) + 120
 * 6T mode: total_cycles = ms (72 n + 6 (n div 256) + 90) + 6 (ms div 256) + 60
 * total_cycles = delay (= 1e-3 s) * oscillator_frequency (in Hz)
 */

#if MCU_CYCLES == 6
#define DELAY_10us ((unsigned char) (((MCU_FREQ / 100000UL) - 84UL) / 36UL))
#else
#define DELAY_10us ((unsigned char) (((MCU_FREQ / 100000UL) - 168UL) / 72UL))
#endif // MCU_CYCLES == 6

/*
 * 12T mode: total_cycles = us (72 n + 120) + 84
 * 6T mode: total_cycles = us (36 n + 60) + 42
 * total_cycles = delay (= 1e-5 s) * oscillator_frequency (in Hz)
 */

#endif // MCU_FAMILY == 90
// =====================================================================

void delay1ms(unsigned int ms) {
	for (unsigned int i = ms; i; i--) {
		for (unsigned int n = DELAY_1ms; n; n--) {
			__asm nop __endasm;
			__asm nop __endasm;
			__asm nop __endasm;
		}
	}
}
void delay10us(unsigned char us) {
	for (unsigned char i = us; i; i--) {
		for (unsigned char n = DELAY_10us; n; n--) {
		}
	}
}
