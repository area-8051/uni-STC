/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Copyright (c) 2023 Vincenbt DEFERT. All rights reserved.
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
#include <lcd/lcd-controller.h>

static uint8_t xAddress = 0;
static uint8_t yAddress = 0;
static uint8_t lcdMemory[LCD_MEMORY_SIZE];

uint8_t lcdGetMemory(int i) {
	return lcdMemory[i];
}

void lcdClearMemory() {
    for (int i = 0; i < LCD_MEMORY_SIZE; i++) {
		lcdMemory[i] = 0;
	}
}

void lcdInitialiseController(LCDDevice *device)  {
    lcdLinkConfigurationComplete(device->interface);
    lcdClearMemory();
}

static int getByteIndex(LCDDevice *device) {
	// The ST7920 supports text mode, not the ST756x.
	return device->textWidth
		? (yAddress * (LCD_WIDTH / 8) + xAddress / 8)
		: ((yAddress / 8) * LCD_WIDTH + xAddress);
}

void lcdWriteByte(LCDDevice *device, uint8_t byte)  {
	lcdMemory[getByteIndex(device)] = byte;
	
	// Auto-increment position
	if (device->textWidth) {
		xAddress += 8;
		
		if (xAddress >= device->pixelWidth) {
			xAddress = 0;
			yAddress++;
		}
	} else {
		xAddress++;
		
		if (xAddress >= device->pixelWidth) {
			xAddress = 0;
			yAddress += 8;
		}
	}
}

uint8_t lcdReadByte(LCDDevice *device)  {
	return lcdMemory[getByteIndex(device)];
}

void lcdSetGraphicsDisplayAddress(LCDDevice *device, uint8_t pixelX, uint8_t pixelY) {
	xAddress = pixelX;
	yAddress = pixelY;
}

uint8_t lcdReadBusyFlagAndAddress(LCDDevice *device)  {
	return 0;
}

void lcdClearTextDisplay(LCDDevice *device)  {
}

void lcdReturnHome(LCDDevice *device)  {
}

void lcdDisplayControl(LCDDevice *device, bool displayOn, bool cursorOn, bool blinkCursor)  {
}

void lcdSetTextDisplayAddress(LCDDevice *device, uint8_t address)  {
}

void lcdSetTextDisplayPosition(LCDDevice *device, uint8_t row, uint8_t column)  {
}

void lcdSetEntryMode(LCDDevice *device, bool textDirection, bool shiftDisplay)  {
}

void lcdCursorDisplayShiftControl(LCDDevice *device, bool shiftDisplay, bool shiftRight)  {
}

void lcdSetCharacterGeneratorAddress(LCDDevice *device, uint8_t address)  {
}

void lcdEnableGraphicsDisplay(LCDDevice *device)  {
}

void lcdDisableGraphicsDisplay(LCDDevice *device)  {
}

void lcdEnterStandbyMode(LCDDevice *device)  {
}

void lcdReverseRow(LCDDevice *device, uint8_t row)  {
}

void lcdSetScrollAddress(LCDDevice *device, uint8_t address)  {
}

void lcdEnableVerticalScroll(LCDDevice *device) {
}

void lcdDisableVerticalScroll(LCDDevice *device) {
}

void lcdInverseDisplay(LCDDevice *device, bool on) {
}

void lcdAllPixelsOn(LCDDevice *device, bool on) {
}
