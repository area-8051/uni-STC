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

/**
 * @file PCD8584.c
 * 
 * Driver for graphics-only LCD devices using a PCD8584 controller,
 * also known as "Nokia 5110" (84x48 pixels, 4-pin SPI interface).
 * 
 * SPI configuration: CPOL = 1, CPHA = 1, MSB first, max. 4MHz.
 * 
 * == Nokia5110 display module connections =============================
 * 
 *   Module  | Connect to
 *  pin name |  MCU pin
 * ----------+------------
 *    RST    | RESET#
 *    CE     | CS#
 *    DC     | D/C#
 *    DIN    | MOSI
 *    CLK    | SCLK
 *    VCC    | +3.3V
 *    LIGHT  | GND
 *    GND    | GND
 */

#include "project-defs.h"
#include <lcd/lcd-controller.h>
#include <delay.h>

void lcdInitialiseController(LCDDevice *device) {
    lcdLinkConfigurationComplete(device->interface);
    
    // Wait for power to stabilise
	delay1ms(1);
    
	if (device->interface->resetOutput.count) {
		gpioWrite(&device->interface->resetOutput, 0);
		delay1us(1);
		gpioWrite(&device->interface->resetOutput, 1);
	}
    
    // 1. Turn display on and select extended instruction set
	lcdSendCommand(device->interface, 0x21);
	// 2. Set bias to 4 (recommended value)
	lcdSendCommand(device->interface, 0x14);
	// 3. Set Vop to 6.9V (op-code = 0x80 + value = 64 = 0x40)
	// (values <= 58 = 6.54V are barely visible)
	lcdSendCommand(device->interface, 0xc0);
    // 4. Select basic instruction set
	lcdSendCommand(device->interface, 0x20);
	
	// 5. Initialise DDRAM
	// Set Y address to 0
	lcdSendCommand(device->interface, 0x40);
	// Set X address to 0
	lcdSendCommand(device->interface, 0x80);
	
	for (uint8_t i = 0; i < 6; i++) {
		for (uint8_t j = 0; j < 84; j++) {
			lcdSendData(device->interface, 0);
		}
	}
	
    // 6. Set display in normal mode
	lcdSendCommand(device->interface, 0x0c);
}

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85

void lcdDisplayControl(LCDDevice *device, bool displayOn, bool cursorOn, bool blinkCursor)  {
	// We exclusively use horizontal addressing, and basic instruction set.
	lcdSendCommand(device->interface, 0x20 | (displayOn ? 4 : 0));
}

#pragma restore

void lcdSetGraphicsDisplayAddress(LCDDevice *device, uint8_t pixelX, uint8_t pixelY) {
	lcdSendCommand(device->interface, 0x40 | ((pixelY >> 3) & 7));
	lcdSendCommand(device->interface, 0x80 | (pixelX & 0x7f));
}

void lcdWriteByte(LCDDevice *device, uint8_t byte)  {
	lcdSendData(device->interface, byte);
}

void lcdInverseDisplay(LCDDevice *device, bool on) {
	lcdSendCommand(device->interface, on ? 0x0d : 0x0c);
}

void lcdAllPixelsOn(LCDDevice *device, bool on) {
	lcdSendCommand(device->interface, on ? 0x09 : 0x0c);
}

// Functionalities below are not available on this controller.
// ---------------------------------------------------------------------

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85

uint8_t lcdReadByte(LCDDevice *device)  {
	return 0;
}

uint8_t lcdReadBusyFlagAndAddress(LCDDevice *device)  {
	return 0;
}

void lcdClearTextDisplay(LCDDevice *device)  {
}

void lcdReturnHome(LCDDevice *device)  {
}

void lcdSetEntryMode(LCDDevice *device, bool textDirection, bool shiftDisplay)  {
}

void lcdCursorDisplayShiftControl(LCDDevice *device, bool shiftDisplay, bool shiftRight)  {
}

void lcdSetCharacterGeneratorAddress(LCDDevice *device, uint8_t address)  {
}

void lcdSetTextDisplayAddress(LCDDevice *device, uint8_t address)  {
}

void lcdSetTextDisplayPosition(LCDDevice *device, uint8_t row, uint8_t column)  {
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

#pragma restore
