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
#include <stdlib.h>
#include <stdio.h>

UartBuffer buffer;

typedef enum {
	READ,
	WRITE,
} TestType;

typedef struct {
	TestType test;
	uint8_t data;
	uint8_t retcode;
	uint8_t size;
} TestData;

const TestData items[] = {
	{ /*  0 */ .test = WRITE, .data =  1, .size = 1, .retcode = 1, },
	{ /*  1 */ .test = WRITE, .data =  2, .size = 2, .retcode = 1, },
	{ /*  2 */ .test = WRITE, .data =  3, .size = 3, .retcode = 1, },
	{ /*  3 */ .test = WRITE, .data =  4, .size = 4, .retcode = 1, },
	{ /*  4 */ .test = WRITE, .data =  5, .size = 4, .retcode = 0, },
	{ /*  5 */ .test = READ,  .data =  1, .size = 3, },
	{ /*  6 */ .test = READ,  .data =  2, .size = 2, },
	{ /*  7 */ .test = READ,  .data =  3, .size = 1, },
	{ /*  8 */ .test = READ,  .data =  4, .size = 0, },
	{ /*  9 */ .test = WRITE, .data =  6, .size = 1, .retcode = 1, },
	{ /* 10 */ .test = WRITE, .data =  7, .size = 2, .retcode = 1, },
	{ /* 11 */ .test = WRITE, .data =  8, .size = 3, .retcode = 1, },
	{ /* 12 */ .test = WRITE, .data =  9, .size = 4, .retcode = 1, },
	{ /* 13 */ .test = READ,  .data =  6, .size = 3, },
	{ /* 14 */ .test = READ,  .data =  7, .size = 2, },
	{ /* 15 */ .test = WRITE, .data = 10, .size = 3, .retcode = 1, },
	{ /* 16 */ .test = WRITE, .data = 11, .size = 4, .retcode = 1, },
	{ /* 17 */ .test = READ,  .data =  8, .size = 3, },
	{ /* 18 */ .test = READ,  .data =  9, .size = 2, },
	{ /* 19 */ .test = READ,  .data = 10, .size = 1, },
	{ /* 20 */ .test = READ,  .data = 11, .size = 0, },
};

static const char *test2str(int item) {
	const char *result = NULL;
	
	switch (items[item].test) {
	case READ:
		result = "READ ";
		break;
	
	case WRITE:
		result = "WRITE";
		break;
	}
	
	return result;
}

int main() {
	uartBufferInitialise(&buffer);
	
	for (int item = 0; item < (sizeof(items) / sizeof(TestData)); item++) {
		uint8_t result = 0;
		
		switch (items[item].test) {
		case READ:
			result = uartBufferRead(&buffer);
			break;
		
		case WRITE:
			result = uartBufferWrite(&buffer, items[item].data);
			break;
		}
		
		uint8_t size = uartBufferLength(&buffer);
		printf("After item %2d: .test = %s  .first = %hhd  .last = %hhd  size = %hhd\n", item, test2str(item), buffer.first, buffer.last, size);
		
		switch (items[item].test) {
		case READ:
			if (result != items[item].data) {
				printf("FAILED: item %d, expected data = %d, actual %d\n", item, items[item].data, result);
				exit(0);
			}
			break;
		
		case WRITE:
			if (result != items[item].retcode) {
				printf("FAILED: item %d, expected retcode = %d, actual %d\n", item, items[item].retcode, result);
				exit(0);
			}
			break;
		}
		
		if (size != items[item].size) {
			printf("FAILED: item %d, expected size = %hhd, actual %hhd\n", item, items[item].size, size);
			exit(0);
		}
	}
	
	printf("PASSED\n");
}
