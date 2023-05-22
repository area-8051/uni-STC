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
#include <fifo-buffer.h>

/**
 * @file fifo-buffer.c
 * 
 * FIFO circular buffer implementation.
 */

bool fifoWrite(FifoState *buffer, const void *data, uint8_t count) {
	bool rc = (buffer->size - fifoLength(buffer)) >= count;
	
	if (rc) {
		uint8_t wIndex = buffer->wIndex;
		
		for (uint8_t n = 0; n < count; n++) {
			buffer->data[wIndex] = ((const uint8_t *) data)[n];
			wIndex++;
			
			if (wIndex > buffer->size) {
				wIndex = 0;
			}
		}
		
		buffer->wIndex = wIndex;
	}
	
	return rc;
}

bool fifoRead(FifoState *buffer, void *data, uint8_t count) {
	bool rc = fifoLength(buffer) >= count;
	
	if (rc) {
		uint8_t rIndex = buffer->rIndex;
		
		for (uint8_t n = 0; n < count; n++) {
			// Buffer is not empty, read rIndex character.
			((uint8_t *) data)[n] = buffer->data[rIndex];
			rIndex++;
			
			if (rIndex > buffer->size) {
				rIndex = 0;
			}
		}
		
		buffer->rIndex = rIndex;
	}
	
	return rc;
}
