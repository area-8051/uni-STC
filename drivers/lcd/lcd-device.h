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
#ifndef _LCD_DEVICE_H
#define _LCD_DEVICE_H

#include <lcd/lcd-interface.h>

/**
 * @file lcd-device.h
 * 
 * LCD device abstraction layer: definitions.
 * 
 * An LCD device consists of a display screen, a controller, and 
 * a communication interface.
 */

typedef struct {
	uint8_t graphicsMode;
	uint8_t extendedInstructionSet;
	uint8_t verticalScroll;
	uint8_t setAddressInvoked;
} LCDDeviceStatus;

typedef struct {
	LCDInterface *interface;
	
	uint8_t textWidth;
	uint8_t textHeight;
	
	uint8_t pixelWidth;
	uint8_t pixelHeight;
	
	/**
	 * The display buffer is used in graphics mode.
	 */
	uint8_t *displayBuffer;
	
	uint8_t __autoUpdate;
	uint8_t __batchStarted;
	uint8_t __displayAddressX;
	uint8_t __displayAddressY;
	uint8_t __minExtentX;
	uint8_t __minExtentY;
	uint8_t __maxExtentX;
	uint8_t __maxExtentY;
	uint8_t __bytesWidth;
	
	LCDDeviceStatus __status;
} LCDDevice;

#define LCD_DEVICE_INTERFACE_NO_RESET(varName, ifcConfig) \
static LCDInterface varName ## Interface = {\
	.linkConfig = ifcConfig, \
	.resetOutput = { .count = 0, }, \
};

#define LCD_DEVICE_INTERFACE_WITH_RESET(varName, ifcConfig, resetPort, resetPin) \
static LCDInterface varName ## Interface = {\
	.linkConfig = ifcConfig, \
	.resetOutput = { .port = resetPort, .pin = resetPin, .count = 1, .pinMode = GPIO_BIDIRECTIONAL_MODE, \
		DEFAULTS_PU_NCS  DEFAULTS_SR_DR_IE  DEFAULTS_INT_WK }, \
};

#define LCD_DEVICE_TEXT_ONLY(varName, txtRows, txtColumns) \
static LCDDevice varName = {\
	.interface = &varName ## Interface, \
	.textWidth = txtColumns, \
	.textHeight = txtRows, \
	.pixelWidth = 0, \
	.pixelHeight = 0, \
	.displayBuffer = NULL, \
};

#define LCD_DEVICE_GRAPHICS(varName, txtRows, txtColumns, gfxWidth, gfxHeight) \
static uint8_t varName ## Buffer[((gfxHeight + 7) / 8) * ((gfxWidth + 7) / 8) * 8];\
\
static LCDDevice varName = {\
	.interface = &varName ## Interface, \
	.textWidth = txtColumns, \
	.textHeight = txtRows, \
	.pixelWidth = gfxWidth, \
	.pixelHeight = gfxHeight, \
	.displayBuffer = varName ## Buffer, \
};

/**
 * IMPORTANT: interrupts must be enabled before calling lcdInitialiseDevice()
 * as communication with the device might need them.
 */
void lcdInitialiseDevice(LCDDevice *device);

#endif // _LCD_DEVICE_H
