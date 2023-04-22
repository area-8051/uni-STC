/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Copyright (c) 2023 Vincent DEFERT. All rights reserved.
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
#include <lcd/lcd-graphics.h>
#include <stdio.h>
#include <stdlib.h>

LCD_DEVICE_INTERFACE_NO_RESET(testLCD, NULL)
LCD_DEVICE_GRAPHICS(testLCD, 0, 0, LCD_WIDTH, LCD_HEIGHT)

// Defined in lcd-controller-mock.c
uint8_t lcdGetMemory(int i);

static bool checkLcdMemory(const char *testName, const uint8_t *reference) {
	bool result = true;
	int i = 0;
	
	for (; result && i < LCD_MEMORY_SIZE; i++) {
		result = (reference[i] == lcdGetMemory(i));
	}
	
	if (!result) {
		printf("FAILED: offset = 0x%x, test = %s\n", i - 1, testName);
		printf("Offset Expected                   Actual\n");
		
		for (int j = 0; j < LCD_MEMORY_SIZE; j += 8) {
			printf("%4x -", j);
			
			for (int k = 0; k < 8; k++) {
				printf(" %02hhx", reference[j + k]);
			}
			
			printf(" -");
			
			for (int k = 0; k < 8; k++) {
				printf(" %02hhx", lcdGetMemory(j + k));
			}
			
			printf("\n");
		}
	}
	
	return result;
}

typedef struct {
	uint8_t startX;
	uint8_t startY;
	uint8_t endX;
	uint8_t endY;
	const uint8_t *reference;
	const char *testName;
} TestData;

const uint8_t st7920_horizontal0[] = {
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t st7920_horizontal8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t st7920_vertical0[] = {
	0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 
	0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t st7920_vertical8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 
	0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 
};

const uint8_t st7920_diagonal[] = {
	0x80, 0x00, 0x40, 0x00, 0x20, 0x00, 0x10, 0x00, 
	0x08, 0x00, 0x04, 0x00, 0x02, 0x00, 0x01, 0x00, 
	0x00, 0x80, 0x00, 0x40, 0x00, 0x20, 0x00, 0x10, 
	0x00, 0x08, 0x00, 0x04, 0x00, 0x02, 0x00, 0x01, 
};

const TestData st7920_tests[] = {
	{ .startX = 0, .startY = 0, .endX = 7, .endY = 0, st7920_horizontal0, "ST7920 horizontal 0,0 - 7,0" },
	{ .startX = 8, .startY = 4, .endX = 15, .endY = 4, st7920_horizontal8, "ST7920 horizontal 8,4 - 15,4" },
	{ .startX = 0, .startY = 0, .endX = 0, .endY = 7, st7920_vertical0, "ST7920 vertical 0,0 - 0,7" },
	{ .startX = 4, .startY = 8, .endX = 4, .endY = 15, st7920_vertical8, "ST7920 vertical 4,8 - 4,15" },
	{ .startX = 0, .startY = 0, .endX = 15, .endY = 15, st7920_diagonal, "ST7920 diagonal 0,0 - 15,15" },
};

const uint8_t st756x_horizontal0[] = {
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t st756x_horizontal8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t st756x_vertical0[] = {
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t st756x_vertical8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t st756x_diagonal[] = {
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 
};

const TestData st756x_tests[] = {
	{ .startX = 0, .startY = 0, .endX = 7, .endY = 0, st756x_horizontal0, "ST756x horizontal 0,0 - 7,0" },
	{ .startX = 8, .startY = 4, .endX = 15, .endY = 4, st756x_horizontal8, "ST756x horizontal 8,4 - 15,4" },
	{ .startX = 0, .startY = 0, .endX = 0, .endY = 7, st756x_vertical0, "ST756x vertical 0,0 - 0,7" },
	{ .startX = 4, .startY = 8, .endX = 4, .endY = 15, st756x_vertical8, "ST756x vertical 4,8 - 4,15" },
	{ .startX = 0, .startY = 0, .endX = 15, .endY = 15, st756x_diagonal, "ST756x diagonal 0,0 - 15,15" },
};

static bool runTests(const TestData *tests, int nbTests, bool runAll) {
	bool result = true;
	
	for (int i = 0; (runAll || result) && i < nbTests; i++) {
		lcdInitialiseDevice(&testLCD);
		lcdGfxInitialiseDisplayMode(&testLCD);
		lcdGfxLine(&testLCD, tests[i].startX, tests[i].startY, tests[i].endX, tests[i].endY, LCD_ON);
		lcdGfxUpdateDisplay(&testLCD);
		result = checkLcdMemory(tests[i].testName, tests[i].reference) && result;
	}
	
	return result;
}

int main() {
	// Setting runAll to true causes all tests to be executed
	// regardless of their success. runAll = false stops at
	// the first failed test.
	bool runAll = false;
	
	// Reminder: the ST7920 supports text mode, not the ST756x.
	
	// .textWidth and .textHeight are initialy set to 0,
	// meaning we're emulating an ST756x LCD controller.
	bool result = runTests(st756x_tests, sizeof(st756x_tests) / sizeof(st756x_tests[0]), runAll);
	
	if (runAll || result) {
		// Set .textWidth and .textHeight to non-zero values
		// so that we now emulate an ST7920 LCD controller.
		testLCD.textWidth = LCD_WIDTH / 8;
		testLCD.textHeight = LCD_HEIGHT / 16;
		result = runTests(st7920_tests, sizeof(st7920_tests) / sizeof(st7920_tests[0]), runAll) && result;
	}
	
	if (result) {
		printf("PASSED\n");
	}
}
