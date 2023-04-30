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
#include <lcd/lcd-device.h>
#include <lcd/lcd-graphics.h>
#include <delay.h>
#include <gpio-hal.h>

#if defined(USES_ST7565) || defined(USES_ST7567)
	#define SPI_MAX_FREQ 20000000UL
#elif defined(USES_UC1609)
	#define SPI_MAX_FREQ 12500000UL
#elif defined(USES_PCD8544)
	#define SPI_MAX_FREQ 4000000UL
#endif

#if defined(USES_ST7920)
	// We assume the LCD display is connected using the ST7920's serial interface.
	#include <lcd/links/lcd-link-serial.h>
	
	static LCDSerialLinkConfig lcdLink = {
		// RS (CS#) = P1.6
		.csOutput = GPIO_PIN_CONFIG(GPIO_PORT1, GPIO_PIN6, GPIO_BIDIRECTIONAL_MODE),
		// E (SCLK) = P1.5
		.sclkOutput = GPIO_PIN_CONFIG(GPIO_PORT1, GPIO_PIN5, GPIO_BIDIRECTIONAL_MODE),
		// RW (MOSI) = P1.3
		.dataInOut = GPIO_PIN_CONFIG(GPIO_PORT1, GPIO_PIN3, GPIO_BIDIRECTIONAL_MODE),
	};
#elif defined(SPI_MAX_FREQ)
	#include <lcd/links/lcd-link-spi.h>
	#include <spi-hal.h>
	
	static LCDSPILinkConfig lcdLink = {
		// D/C# = P1.7
		.commandDataOutput = GPIO_PIN_CONFIG(GPIO_PORT1, GPIO_PIN7, GPIO_BIDIRECTIONAL_MODE),
		// CS# = P1.6
		.csOutput = GPIO_PIN_CONFIG(GPIO_PORT1, GPIO_PIN6, GPIO_BIDIRECTIONAL_MODE),
		// SCLK = P1.5
		// MOSI = P1.3
		.spiPinSwitch = SPI_PIN_CONFIG,
		.spiClockFrequency = SPI_MAX_FREQ,
	};
#else
	#error "Please define the link configuration matching the lcd-link-XXX.c in Makefile."
#endif

// RST# = P1.1
LCD_DEVICE_INTERFACE_WITH_RESET(lcdDevice, &lcdLink, GPIO_PORT1, GPIO_PIN1)

#if defined(USES_ST7565) || defined(USES_ST7567)
	LCD_DEVICE_GRAPHICS(lcdDevice, 0, 0, 128, 64)
#elif defined(USES_ST7920)
	LCD_DEVICE_GRAPHICS(lcdDevice, 4, 16, 128, 64)
#elif defined(USES_UC1609)
	LCD_DEVICE_GRAPHICS(lcdDevice, 0, 0, 192, 64)
#elif defined(USES_PCD8544)
	LCD_DEVICE_GRAPHICS(lcdDevice, 0, 0, 84, 48)
#endif

#include "smiley.xbm"

enum FixedPoint {
	TOP_LEFT,
	BOTTOM_RIGHT,
	TOP_RIGHT,
	BOTTOM_LEFT,
};

#define SPLASH_SCREEN_DURATION_MS 2000

void main() {
	INIT_EXTENDED_SFR()

	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	lcdInitialiseDevice(&lcdDevice);
	lcdGfxInitialiseDisplayMode(&lcdDevice);
	
	// We want to automatically update the LCD display after each drawing
	// operation instead of calling lcdGfxUpdateDisplay(&lcdDevice);
	lcdGfxEnableAutoUpdate(&lcdDevice);
	
	// Splash screen ---------------------------------------------------
	
	lcdGfxClear(&lcdDevice);
	lcdGfxXbmImage(&lcdDevice, smiley_width, smiley_height, smiley_bits, LCD_ALIGN_MIDDLE_CENTER, 0, 0);
	delay1ms(SPLASH_SCREEN_DURATION_MS);
	
	// Main loop -------------------------------------------------------
	
	uint8_t curStep = 0;
	uint8_t inc = 4;
	uint8_t yMaxSteps = lcdDevice.pixelHeight / inc - 1;
	uint8_t xMax = lcdDevice.pixelWidth - 1;
	uint8_t yMax = lcdDevice.pixelHeight - 1;
	enum FixedPoint fixedPoint = TOP_LEFT;
	
	while (1) {
		if (curStep == 0) {
			lcdGfxClear(&lcdDevice);
		}
		
		switch (fixedPoint) {
		case TOP_LEFT:
			lcdGfxLine(&lcdDevice, 0, 0, xMax, curStep * inc, LCD_ON);
			curStep++;
			
			if (curStep > yMaxSteps) {
				curStep = 0;
				fixedPoint = TOP_RIGHT;
			}
			break;
		
		case TOP_RIGHT:
			lcdGfxLine(&lcdDevice, xMax, 0, 0, curStep * inc, LCD_ON);
			curStep++;
			
			if (curStep > yMaxSteps) {
				curStep = 0;
				fixedPoint = BOTTOM_LEFT;
			}
			break;
		
		case BOTTOM_LEFT:
			lcdGfxLine(&lcdDevice, 0, yMax, xMax, (yMaxSteps - curStep) * inc, LCD_ON);
			curStep++;
			
			if (curStep > yMaxSteps) {
				curStep = 0;
				fixedPoint = BOTTOM_RIGHT;
			}
			break;
		
		case BOTTOM_RIGHT:
			lcdGfxLine(&lcdDevice, xMax, yMax, 0, (yMaxSteps - curStep) * inc, LCD_ON);
			curStep++;
			
			if (curStep > yMaxSteps) {
				curStep = 0;
				fixedPoint = TOP_LEFT;
			}
			break;
		}
	}
}
