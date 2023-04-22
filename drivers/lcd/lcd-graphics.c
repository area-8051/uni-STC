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
#include <lcd/lcd-controller.h>
#include <stdlib.h>

/**
 * @file lcd-graphics.c
 * 
 * Graphics operations for LCD devices: implementation.
 */

static uint8_t __reverseBits(uint8_t byte) {
	uint8_t result = 0;
	uint8_t mask = 0x80;
	
	for (uint8_t i = 8; i; i--) {
		result = (result >> 1) | ((byte & mask) ? 0x80 : 0);
		mask = mask >> 1;
	}
	
	return result;
}

static void __beginOperation(LCDDevice *device) {
	if (!device->__batchStarted) {
		device->__batchStarted = 1;
		device->__minExtentX = device->pixelWidth;
		device->__minExtentY = device->pixelHeight;
		device->__maxExtentX = 0;
		device->__maxExtentY = 0;
	}
}

static void __endOperation(LCDDevice *device) {
	if (device->__autoUpdate) {
		lcdGfxUpdateDisplay(device);
	}
}

void lcdGfxInitialiseDisplayMode(LCDDevice *device) {
	device->__autoUpdate = 0;
	device->__batchStarted = 0;
	lcdGfxClear(device);
	
	if (device->textWidth) {
		// The ST7920 supports both text and graphics modes
		
		// This is the fastest way to clear the graphics display (< 2 ms)
		lcdDisableGraphicsDisplay(device);
		lcdClearTextDisplay(device);
		
		// Switch to graphics mode
		lcdEnableGraphicsDisplay(device);
		
		device->__batchStarted = 0;
	}
}

void lcdGfxEnableAutoUpdate(LCDDevice *device) {
	device->__autoUpdate = 1;
}

void lcdGfxDisableAutoUpdate(LCDDevice *device) {
	lcdGfxUpdateDisplay(device);
	device->__autoUpdate = 0;
}

static void __updateST7920(LCDDevice *device) {
	// The ST7920 requires data bytes be sent in pairs, so we 
	// want to align xMin and xMax on 16-bit boundaries.
	uint8_t xMin = device->__minExtentX & ~0x0f;
	uint8_t xMax = device->__maxExtentX | 0x0f;
	
	for (uint8_t y = device->__minExtentY; y <= device->__maxExtentY; y++) {
		lcdSetGraphicsDisplayAddress(device, xMin, y);
		unsigned int byteOffset = (y * device->__bytesWidth + (xMin / 8));
		
		for (uint8_t x = 0; x <= (xMax - xMin) / 8; x++) {
			lcdWriteByte(device, device->displayBuffer[byteOffset + x]);
		}
	}
}

static void __updateST756X(LCDDevice *device) {
	// Align yMin and yMax on byte boundaries.
	uint8_t yMin = device->__minExtentY & ~7;
	uint8_t yMax = device->__maxExtentY | 7;
	
	for (uint8_t y = yMin; y <= yMax; y += 8) {
		lcdSetGraphicsDisplayAddress(device, device->__minExtentX, y);
		
		for (uint8_t x = device->__minExtentX; x <= device->__maxExtentX; x++) {
			uint8_t byte = 0;
			
			for (uint8_t i = 0; i < 8; i++) {
				unsigned int byteOffset = ((y + i) * device->__bytesWidth + (x / 8));
				uint8_t bitMask = 1 << (7 - x % 8);
				byte >>= 1;
				
				if (device->displayBuffer[byteOffset] & bitMask) {
					byte |= 0x80;
				}
			}
			
			lcdWriteByte(device, byte);
		}
	}
}

void lcdGfxUpdateDisplay(LCDDevice *device) {
	if (device->__batchStarted) {
		device->__batchStarted = 0;
		
		if (device->textWidth) {
			// The ST7920 supports both text and graphics modes
			__updateST7920(device);
		} else {
			// Graphics-only displays
			__updateST756X(device);
		}
	}
}

void lcdGfxClear(LCDDevice *device) {
	__beginOperation(device);
	
	for (unsigned int i = 0; i < (device->pixelHeight * device->__bytesWidth); i++) {
		device->displayBuffer[i] = 0;
	}
	
	device->__minExtentX = 0;
	device->__minExtentY = 0;
	device->__maxExtentX = device->pixelWidth - 1;
	device->__maxExtentY = device->pixelHeight - 1;
	
	__endOperation(device);
}

void __drawPoint(LCDDevice *device, uint8_t x, uint8_t y, LCDColour colour) {
	unsigned int byteOffset = (y * device->__bytesWidth) + (x / 8);
	
	uint8_t byte = device->displayBuffer[byteOffset];
	uint8_t bitMask = 1 << (7 - x % 8);
	
	// Set the bit according to the requested "colour"
	if (colour == LCD_ON) {
		byte |= bitMask;
	} else {
		byte &= ~bitMask;
	}
	
	device->displayBuffer[byteOffset] = byte;
	
	if (x < device->__minExtentX) {
		device->__minExtentX = x;
	}
	
	if (x > device->__maxExtentX) {
		device->__maxExtentX = x;
	}
	
	if (y < device->__minExtentY) {
		device->__minExtentY = y;
	}
	
	if (y > device->__maxExtentY) {
		device->__maxExtentY = y;
	}
}

void lcdGfxPoint(LCDDevice *device, uint8_t x, uint8_t y, LCDColour colour) {
	__beginOperation(device);
	__drawPoint(device, x, y, colour);
	__endOperation(device);
}

void lcdGfxLine(LCDDevice *device, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, LCDColour colour) {
	__beginOperation(device);
	
	if (x0 == x1) {
		if (y0 > y1) {
			uint8_t n = y1;
			y1 = y0;
			y0 = n;
		}
		
		for (uint8_t y = y0; y <= y1; y++) {
			__drawPoint(device, x0, y, colour);
		}
	} else if (y0 == y1) {
		if (x0 > x1) {
			uint8_t n = x1;
			x1 = x0;
			x0 = n;
		}
		
		for (uint8_t x = x0; x <= x1; x++) {
			__drawPoint(device, x, y0, colour);
		}
	} else {
		int dx = abs(x1 - x0);
		int sx = x0 < x1 ? 1 : -1;
		int dy = -abs(y1 - y0);
		int sy = y0 < y1 ? 1 : -1;
		int err = dx + dy;
		int e2;
		int x = x0;
		int y = y0;
		
		while (1) {
			__drawPoint(device, x, y, colour);
			e2 = 2 * err;
			
			if (e2 >= dy) {
				if (x == x1)
					break;
				
				err += dy;
				x += sx;
			}
			
			if (e2 <= dx) {
				if (y == y1)
					break;
				
				err += dx;
				y += sy;
			}
		}
	}
	
	__endOperation(device);
}

void lcdGfxXbmImage(
	LCDDevice *device, 
	uint8_t imageWidth, 
	uint8_t imageHeight, 
	uint8_t *imageBits, 
	LCDAlignment alignment, 
	uint8_t positionX, 
	uint8_t positionY
) {
	__beginOperation(device);
	
	// XBM format: if imageWidth is not a multiple of 8, unused bits in the last byte are ignored.
	uint8_t bytesPerImageRow = imageWidth / 8 + ((imageWidth % 8) ? 1 : 0);
	// The LCD display expects to receive pairs of bytes.
	uint8_t bytesPerDisplayRow = bytesPerImageRow + (bytesPerImageRow % 2);
	uint8_t offsetX = 0;
	uint8_t offsetY = 0;
	
	switch (alignment) {
	case LCD_ALIGN_TOP_LEFT:
	case LCD_ALIGN_BOTTOM_LEFT:
	case LCD_ALIGN_MIDDLE_LEFT:
		offsetX = 0;
		break;
	case LCD_ALIGN_TOP_RIGHT:
	case LCD_ALIGN_BOTTOM_RIGHT:
	case LCD_ALIGN_MIDDLE_RIGHT:
		offsetX = (device->pixelWidth > imageWidth) ? (device->pixelWidth - imageWidth) : 0;
		break;
	case LCD_ALIGN_TOP_CENTER:
	case LCD_ALIGN_BOTTOM_CENTER:
	case LCD_ALIGN_MIDDLE_CENTER:
		offsetX = (device->pixelWidth > imageWidth) ? ((device->pixelWidth - imageWidth) / 2) : 0;
		break;
	case LCD_ALIGN_CUSTOM_OFFSET:
		offsetX = positionX;
		break;
	}
	
	switch (alignment) {
	case LCD_ALIGN_TOP_LEFT:
	case LCD_ALIGN_TOP_RIGHT:
	case LCD_ALIGN_TOP_CENTER:
		offsetY = 0;
		break;
	case LCD_ALIGN_BOTTOM_LEFT:
	case LCD_ALIGN_BOTTOM_RIGHT:
	case LCD_ALIGN_BOTTOM_CENTER:
		offsetY = (device->pixelHeight > imageHeight) ? (device->pixelHeight - imageHeight) : 0;
		break;
	case LCD_ALIGN_MIDDLE_LEFT:
	case LCD_ALIGN_MIDDLE_RIGHT:
	case LCD_ALIGN_MIDDLE_CENTER:
		offsetY = (device->pixelHeight > imageHeight) ? ((device->pixelHeight - imageHeight) / 2) : 0;
		break;
	case LCD_ALIGN_CUSTOM_OFFSET:
		offsetY = positionY;
		break;
	}
	
	for (uint8_t row = 0; row < imageHeight; row++) {
		unsigned int baseOffset = ((offsetY + row) * device->__bytesWidth) + (offsetX / 8);
		
		for (uint8_t col = 0; col < bytesPerDisplayRow; col++) {
			uint8_t byte = (col < bytesPerImageRow) ? imageBits[row * bytesPerImageRow + col] : 0;
			// XBM format: the leftmost pixel is represented by the least significant bit,
			// so XBM bytes need to be reversed before being sent to the display.
			device->displayBuffer[baseOffset + col] = __reverseBits(byte);
		}
	}
	
	uint8_t xMin = offsetX;
	uint8_t yMin = offsetY;
	uint8_t xMax = xMin + imageWidth;
	uint8_t yMax = yMin + imageHeight;
	
	if (xMin < device->__minExtentX) {
		device->__minExtentX = xMin;
	}
	
	if (xMax > device->__maxExtentX) {
		device->__maxExtentX = xMax;
	}
	
	if (yMin < device->__minExtentY) {
		device->__minExtentY = yMin;
	}
	
	if (yMax > device->__maxExtentY) {
		device->__maxExtentY = yMax;
	}
	
	__endOperation(device);
}
