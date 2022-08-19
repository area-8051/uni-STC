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

/**
 * @file serial-console.c
 * 
 * Serial console support.
 */

#include "project-defs.h"
#include "serial-console.h"
#include <uart-hal.h>
#include <delay.h>
#include <stdio.h>

static Uart SERIAL_CONSOLE_SEGMENT __serialConsoleUart;

#ifdef TIMER_HAS_T1
	#define CONSOLE_TIMER UART_USE_OWN_TIMER
#else
	#define CONSOLE_TIMER UART_USE_TIMER2
#endif // TIMER_HAS_T1


void serialConsoleInitialise(Uart uart, uint32_t baudRate, uint8_t pinConfiguration) {
	__serialConsoleUart = uart;
	uartInitialise(__serialConsoleUart, baudRate, CONSOLE_TIMER, UART_8N1, pinConfiguration);
}

int putchar(int c) {
	if (c == '\n') {
		// Using Unix line terminations reduces flash usage and makes
		// strings in the source code a little big more legible.
		uartSendCharacter(__serialConsoleUart, '\r', BLOCKING);
	}
	
	uartSendCharacter(__serialConsoleUart, c, BLOCKING);
	
	return c;
}

int getchar() {
	return uartGetCharacter(__serialConsoleUart, BLOCKING);
}
