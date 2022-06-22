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
#ifndef _PROJECT_DEFS_H
#define _PROJECT_DEFS_H

#include <stdint.h>

#ifdef __TESTING__
	#include <uni-STC/testing.h>
#else
	#ifdef BUILD_FOR_STC8G1K08_TSSOP20
		#include <STC/8G1Kxx/TSSOP20.h>
		#define SMALL_FLASH
	#endif
	
	#ifdef BUILD_FOR_STC8G2K64S4
		#include <STC/8G2KxxS4/LQFP48.h>
	#endif
	
	#ifdef BUILD_FOR_STC8A8K64S4A12
		#include <STC/8A8KxxS4A12/LQFP48.h>
	#endif
	
	#ifdef BUILD_FOR_STC8A8K64D4
		#include <STC/8A8KxxD4/LQFP48.h>
	#endif
	
	#ifdef BUILD_FOR_STC8H1K08_TSSOP20
		#include <STC/8H1Kxx/TSSOP20.h>
		#define SMALL_FLASH
	#endif
	
	#ifdef BUILD_FOR_STC8H8K64U_PDIP40
		#include <STC/8H8KxxU/PDIP40.h>
	#endif
	
	#ifdef BUILD_FOR_STC15W4K32S4_PDIP40
		#include <STC/15W4KxxS4/PDIP40.h>
	#endif
	
	#ifdef BUILD_FOR_STC15W408AS_DIP16
		#include <STC/15W4xxAS/DIP16.h>
		#define SMALL_FLASH
	#endif
	
	#ifdef BUILD_FOR_STC12C5A56S2_PDIP40
		#include <STC/12C5AxxS2/PDIP40.h>
	#endif
#endif // __TESTING__

// INSIDE THE MAIN LOOP

// 1. The MCU will echo characters received from the serial console.
// Exercises: UART, baud rate generation, serial console support

#define CONSOLE_SPEED 57600UL

// Target MCU | RxD  | TxD 
// -----------+------+------
// All        | P3.0 | P3.1
#define CONSOLE_UART UART1
#define CONSOLE_PIN_CONFIG 0

// 2. The MCU will blink an LED connected to a GPIO pin.
// Exercises: GPIO, delay loop

// Target MCU   | Blinking LED pin
// -------------+-----------------
// All          | P3.3

#define BLINKING_PIN GPIO_PIN3
// Delay in milliseconds.
#define BLINKING_HALF_PERIOD 250

// 3. The MCU will glow an LED connected to a PCA CCP pin.
// Exercises: PCA

// Target MCU   | Glowing LED pin
// -------------+-----------------
// All STC8A    | P1.7
// STC8G1K08A   | P3.2
// Other STC8G  | P1.1
// All STC8H    | -
// All STC15    | P1.1
// STC12C5AxxS2 | P1.3

// Number of gradation steps (not too many so the change is noticeable)
#define GLOWING_SWEEP_STEPS 8
// Output frequency of the PWM channel in Hz
#define GLOWING_PWM_FREQ 100UL

// Let's use 8-bit PWM mode, all MCU have it
#define GLOWING_PWM_BITS 8

// All MCU have this pin configuration
#define GLOWING_PIN_CONFIG 0

// All MCU have CCP0
#define GLOWING_CCP_CHANNEL PCA_CHANNEL0

#define GLOWING_COUNTER_FREQ ((1 << GLOWING_PWM_BITS) * GLOWING_PWM_FREQ)

#define GLOWING_DUTY_CYCLE_INCREMENT ((1 << GLOWING_PWM_BITS) / GLOWING_SWEEP_STEPS)
#define GLOWING_DUTY_CYCLE_MIN 0
#define GLOWING_DUTY_CYCLE_MAX ((1 << GLOWING_PWM_BITS) - 1)
	
#ifdef SMALL_FLASH
	// Manage to fit in 8 KB flash...
	#define HAL_UARTS 1
	#define HAL_PCA_CHANNELS 1
#endif // SMALL_FLASH

#endif // _PROJECT_DEFS_H
