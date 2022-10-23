/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Copyright (c) 2022 Vincenbt DEFERT. All rights reserved.
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
 * @file VT52-mock.c
 * 
 * Mocks a text-only LCD device using VT52 control codes.
 * Designed to develop the user interface of a device on a PC.
 * 
 * Support 1-line (up to 80 columns), 2-line (up to 40 columns), and 
 * 4-line (up to 20 columns) display configurations.
 * 
 * This file implements the abstraction layer described in 
 * lcd-controller.h, which is why it doesn't have its own header file. 
 */

#include "project-defs.h"
#include <lcd/lcd-controller.h>
#include <stdio.h>

void lcdInitialiseController(LCDDevice *device)  {
    lcdLinkConfigurationComplete(device->interface);
	// Disable output buffering
    setvbuf(stdout, NULL, _IONBF, 0);
	lcdClearTextDisplay(device);
}

void lcdWriteByte(LCDDevice *device, uint8_t byte)  {
	putchar(byte);
}

uint8_t lcdReadByte(LCDDevice *device)  {
	return 0;
}

uint8_t lcdReadBusyFlagAndAddress(LCDDevice *device)  {
	return 0;
}

void lcdClearTextDisplay(LCDDevice *device)  {
	putchar(0x1b); putchar('H');
	putchar(0x1b); putchar('J');
}

void lcdReturnHome(LCDDevice *device)  {
	putchar(0x1b); putchar('H');
}

void lcdSetEntryMode(LCDDevice *device, bool textDirection, bool shiftDisplay)  {
	// Not implemented
}

void lcdDisplayControl(LCDDevice *device, bool displayOn, bool cursorOn, bool blinkCursor)  {
	// Not implemented
}

void lcdCursorDisplayShiftControl(LCDDevice *device, bool shiftDisplay, bool shiftRight)  {
	// Not implemented
}

// It's quite unlikely someone would call this function, 
// but just in case, we'll make it call lcdSetTextDisplayPosition().
void lcdSetTextDisplayAddress(LCDDevice *device, uint8_t address)  {
	uint8_t row = 0;
	uint8_t col = 0;
	
	if (device->textHeight > 1) {
		if (address & 0x40) {
			row += 1;
			address &= 0x3f;
		}
		
		col = address;
		
		if (device->textHeight > 2 && col >= 0x14) {
			row += 2;
			col -= 0x14;
		}
	} else {
		col = address;
	}
	
	lcdSetTextDisplayPosition(device, row, col);
}

void lcdSetTextDisplayPosition(LCDDevice *device, uint8_t row, uint8_t column)  {
	putchar(0x1b); putchar('Y'); putchar(row + 0x20); putchar(column + 0x20);
}

// Functionalities below are not available on this controller.
// ---------------------------------------------------------------------

void lcdSetCharacterGeneratorAddress(LCDDevice *device, uint8_t address)  {
}

void lcdSetGraphicsDisplayAddress(LCDDevice *device, uint16_t pixelX, uint16_t pixelY) {
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
