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
	uint8_t size; /*!< Usable size of the buffer. */
	uint8_t rIndex; /*!< Index of the next read. */
	uint8_t wIndex; /*!< Index of the next write. */
	uint8_t status; /*!< Application-defined status byte. */
	uint8_t *data; /*!< Buffer address (must be statically allocated). */
} FifoState;

/**
 * Declares a FifoState variable and its buffer.
 * Buffer is empty when rIndex == wIndex.
 * bufferSize is the usable size of the buffer and MUST be in [1; 255].
 * Effective buffer size is bufferSize + 1.
 * 
 * IMPORTANT: This extra unused byte is the price to pay for an 
 * interrupt-safe FIFO implementation. This is true as long as the
 * ISR only writes to (respectively reads from) the FIFO, while the
 * main loop only reads from (respectively writes to) it.
 */
#define FIFO_BUFFER(variableName, bufferSize, segment) \
	static uint8_t segment variableName ## Data[bufferSize + 1]; \
	FifoState segment variableName = { \
		.size = bufferSize, \
		.rIndex = 0, \
		.wIndex = 0, \
		.status = 0, \
		.data = variableName ## Data, \
	};

/**
 * Returns the number of bytes in use.
 */
INLINE uint8_t fifoLength(FifoState *buffer) {
	return (buffer->wIndex >= buffer->rIndex)
		? (buffer->wIndex - buffer->rIndex)
		: (buffer->size - buffer->rIndex + buffer->wIndex + 1);
}

/**
 * Empties the fifo.
 */
INLINE void fifoClear(FifoState *buffer) {
	buffer->rIndex = 0;
	buffer->wIndex = 0;
	buffer->status = 0;
}

bool fifoWrite(FifoState *fifo, const void *data, uint8_t count) REENTRANT;
bool fifoRead(FifoState *fifo, void *data, uint8_t count) REENTRANT;

INLINE bool fifoIsEmpty(FifoState *fifo) {
	return fifoLength(fifo) == 0;
}

INLINE bool fifoIsFull(FifoState *fifo) {
	return fifoLength(fifo) == fifo->size;
}

INLINE uint8_t fifoBytesUsed(FifoState *fifo) {
	return fifoLength(fifo);
}

INLINE uint8_t fifoBytesFree(FifoState *fifo) {
	return fifo->size - fifoLength(fifo);
}

#endif // _FIFO_BUFFER_H
