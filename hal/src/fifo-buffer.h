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
#ifndef _FIFO_BUFFER_H
#define _FIFO_BUFFER_H

/**
 * @file fifo-buffer.h
 * 
 * FIFO circular buffer definitions.
 * 
 * Supported MCU:
 * 
 *     STC12*
 *     STC15*
 *     STC8*
 * 
 * Dependencies:
 * 
 *     none
 */

typedef struct {
	uint8_t size;
	uint8_t first;
	uint8_t last;
	uint8_t status;
	uint8_t *data;
} FifoState;

// Declares a FifoState variable and its buffer.
#define FIFO_BUFFER(variableName, bufferSize, segment) \
	static segment uint8_t variableName ## Data[bufferSize]; \
	segment FifoState variableName = { \
		.size = bufferSize, \
		.first = bufferSize, \
		.last = bufferSize, \
		.status = 0, \
		.data = variableName ## Data, \
	};

uint8_t __fifoLength(FifoState *fifo) REENTRANT;

bool fifoWrite(FifoState *fifo, const uint8_t *data, uint8_t count) REENTRANT;

bool fifoRead(FifoState *fifo, uint8_t *data, uint8_t count) REENTRANT;

INLINE void fifoClear(FifoState *fifo) {
	fifo->first = fifo->size;
	fifo->last = fifo->size;
	fifo->status = 0;
}

INLINE bool fifoIsEmpty(FifoState *fifo) {
	return __fifoLength(fifo) == 0;
}

INLINE bool fifoIsFull(FifoState *fifo) {
	return __fifoLength(fifo) == fifo->size;
}

INLINE uint8_t fifoBytesUsed(FifoState *fifo) {
	return __fifoLength(fifo);
}

INLINE uint8_t fifoBytesFree(FifoState *fifo) {
	return fifo->size - __fifoLength(fifo);
}

#endif // _FIFO_BUFFER_H
