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

#ifdef __SDCC
	#include <STC/8A8KxxD4/LQFP48.h>
#else
	#include <uni-STC/uni-STC.h>
#endif // __SDCC

#define CONSOLE_UART   UART1
#define CONSOLE_SPEED  57600
#define CONSOLE_PIN_CONFIG 0

#ifdef GPIO_NO_P13
	/**
	 * STC8H3 have no P1.3..5, so:
	 *     MOSI = P3.4, MISO = P3.3, SCLK = P3.2
	 */
	#define SPI_PIN_CONFIG 3
#else
	/**
	 * General rule:
	 *     MOSI = P1.3, MISO = P1.4, SCLK = P1.5
	 * 
	 * 8-pin STC8G:
	 *     MOSI = P5.4, MISO = P3.3, SCLK = P3.2
	 * 
	 * STC12:
	 *     MOSI = P1.5, MISO = P1.6, SCLK = P1.7
	 */
	#define SPI_PIN_CONFIG 0
#endif // GPIO_NO_P13

#define BASIC_GPIO_HAL
#define SUPPRESS_delay1us_WARNING
#define HAL_UARTS 1
#define SERIAL_CONSOLE_SEGMENT __xdata
#define UART_DEFAULT_SEGMENT __xdata

#endif // _PROJECT_DEFS_H
