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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __SDCC
	//#include <STC/8A8KxxS4A12/LQFP48.h>
	//#include <STC/8A8KxxD4/LQFP48.h>
	#include <STC/8G1Kxx/TSSOP20.h>
	//#include <STC/8G2KxxS4/LQFP48.h>
	//#include <STC/8H1Kxx/TSSOP20.h>
	//#include <STC/8H3KxxS2/TSSOP20.h>
	//#include <STC/8H3KxxS4/LQFP32.h>
	//#include <STC/8H8KxxU/PDIP40.h>
	//#include <STC/15W4KxxS4/PDIP40.h>
	//#include <STC/12C5AxxS2/PDIP40.h>
#else
	#include <uni-STC/uni-STC.h>
#endif // __SDCC

#define CONSOLE_UART   UART1
#define CONSOLE_SPEED  57600UL
#define CONSOLE_PIN_CONFIG 0

// Reduce RAM footprint so we can use the medium memory model
// regardless of the MCU.
#define HAL_UARTS 1

#endif // _PROJECT_DEFS_H
