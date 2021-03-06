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
#include "uart-buffer.h"

/**
 * @file uart-buffer.c
 * 
 * UART circular buffer implementation.
 */

void uartBufferInitialise(UartBuffer *buffer) REENTRANT {
	buffer->first = UART_BUFFER_SIZE;
	buffer->last = UART_BUFFER_SIZE;
	buffer->busy = 0;
}

uint8_t uartBufferLength(UartBuffer *buffer) REENTRANT {
	return (buffer->last >= buffer->first)
		? (buffer->last == UART_BUFFER_SIZE
			? 0
			: (buffer->last - buffer->first + 1)
		)
		: (UART_BUFFER_SIZE - (buffer->first - buffer->last - 1));
}

uint8_t uartBufferWrite(UartBuffer *buffer, uint8_t data) REENTRANT {
	uint8_t rc = 0;
	
	if (uartBufferLength(buffer) < UART_BUFFER_SIZE) {
		buffer->last++;
		
		if (buffer->last >= UART_BUFFER_SIZE) {
			// Handles both buffer empty and wrap around cases.
			buffer->last = 0;
		}
		
		if (buffer->first == UART_BUFFER_SIZE) {
			// Buffer was empty, initialise .first too.
			buffer->first = 0;
		}
		
		buffer->data[buffer->last] = data;
		rc = 1;
	}
	
	return rc;
}

uint8_t uartBufferRead(UartBuffer *buffer) REENTRANT {
	uint8_t result = 0;
	
	if (buffer->first != UART_BUFFER_SIZE) {
		// Buffer is not empty, read first character.
		result = buffer->data[buffer->first];
		
		if (buffer->first == buffer->last) {
			// We've read the last character, mark buffer as empty.
			buffer->first = UART_BUFFER_SIZE;
			buffer->last = UART_BUFFER_SIZE;
		} else {
			buffer->first++;
			
			if (buffer->first == UART_BUFFER_SIZE) {
				buffer->first = 0;
			}
		}
	}
	
	return result;
}
