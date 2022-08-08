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
	
	uint16_t textWidth;
	uint16_t textHeight;
	
	uint16_t pixelWidth;
	uint16_t pixelHeight;
	
	/**
	 * Display buffers may be used either when the communication 
	 * interface is write-only (e.g. serial interface of the ST7920)
	 * and the application needs to be able to read the display RAM,
	 * or in order to optimise performance in graphics mode using 
	 * batch updates.
	 */
	uint8_t *displayBuffer;
	
	uint8_t __autoUpdate;
	uint8_t __batchStarted;
	uint16_t __displayAddressX;
	uint16_t __displayAddressY;
	uint16_t __minExtentX;
	uint16_t __minExtentY;
	uint16_t __maxExtentX;
	uint16_t __maxExtentY;
	uint16_t __bytesWidth;
	
	LCDDeviceStatus __status;
} LCDDevice;

#define LCD_TEXT_ONLY_DEVICE(varName, ifcConfig, txtRows, txtColumns) \
static LCDInterface varName ## Interface = {\
	.linkConfig = ifcConfig, \
};\
\
static LCDDevice varName = {\
	.interface = &varName ## Interface, \
	.textWidth = txtColumns, \
	.textHeight = txtRows, \
	.pixelWidth = 0, \
	.pixelHeight = 0, \
	.displayBuffer = NULL, \
};

#define LCD_GRAPHICS_DEVICE(varName, ifcConfig, txtRows, txtColumns, gfxWidth, gfxHeight) \
static LCDInterface varName ## Interface = {\
	.linkConfig = ifcConfig, \
};\
\
static LCDDevice varName = {\
	.interface = &varName ## Interface, \
	.textWidth = txtColumns, \
	.textHeight = txtRows, \
	.pixelWidth = gfxWidth, \
	.pixelHeight = gfxHeight, \
	.displayBuffer = NULL, \
};

#define LCD_GRAPHICS_DEVICE_WITH_BUFFER(varName, ifcConfig, txtRows, txtColumns, gfxWidth, gfxHeight) \
static LCDInterface varName ## Interface = {\
	.linkConfig = ifcConfig, \
};\
\
static uint8_t varName ## Buffer[gfxHeight * (gfxWidth / 8)];\
\
static LCDDevice varName = {\
	.interface = &varName ## Interface, \
	.textWidth = txtColumns, \
	.textHeight = txtRows, \
	.pixelWidth = gfxWidth, \
	.pixelHeight = gfxHeight, \
	.displayBuffer = varName ## Buffer, \
};

void lcdInitialiseDevice(LCDDevice *device);

#endif // _LCD_DEVICE_H
