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

#include <stdlib.h>
#include <stdint.h>

#ifdef __TESTING__
	#include <uni-STC/testing.h>
#else
	//#include <STC/8A8KxxS4A12/LQFP48.h>
	#include <STC/8A8KxxD4/LQFP48.h>
	//#include <STC/8G1Kxx/TSSOP20.h>
	//#include <STC/8G2KxxS4/LQFP48.h>
	//#include <STC/8H1Kxx/TSSOP20.h>
	//#include <STC/8H3KxxS2/TSSOP20.h>
	//#include <STC/8H3KxxS4/LQFP32.h>
	//#include <STC/8H8KxxU/PDIP40.h>
	//#include <STC/15W4KxxS4/PDIP40.h>
	//#include <STC/12C5AxxS2/PDIP40.h>
#endif // __TESTING__

#define CONSOLE_UART   UART1
#define CONSOLE_SPEED  57600UL
#define CONSOLE_PIN_CONFIG 0

#if MCU_FAMILY == 8 && MCU_SERIES == 'G' && MCU_PINS == 8
	// We'll use channel 3 (P3.3) on the STC8G1K08A to leave P3.0
	// and P3.1 available for the serial console.
	#define DEMO_ADC_CHANNEL ADC_CHANNEL3
#else
	// On all other MCU, we'll use channel 0 (P1.0).
	#define DEMO_ADC_CHANNEL ADC_CHANNEL0
#endif

// You should connect a known voltage source on DEMO_ADC_CHANNEL,
// but you may also leave it floating for the fun of it - or more 
// seriously to assess the relevance of the least significant bits
// of a floating ADC input as a source of entropy.

// On STC8, the value of channel 15 (internal voltage reference)
// will also be displayed.

// Reduce RAM footprint so we can use the medium memory model
// regardless of the MCU.
#define HAL_UARTS 1

#endif // _PROJECT_DEFS_H
