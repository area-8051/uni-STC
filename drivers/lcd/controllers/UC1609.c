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
 * @file UC1609.c
 * 
 * Driver for graphics-only LCD devices using an UC1609C controller,
 * connected through a 4-pin SPI interface with a maximum clock
 * frequency of 12.5 MHz.
 * 
 * == 19254-05 display module connections ==============================
 * 
 *   Module  | Connect to
 *  pin name |  MCU pin
 * ----------+------------
 *    K      | GND
 *    A      | +3.3V
 *    GND    | GND
 *    VDD    | +3.3V
 *    SCK    | SCLK
 *    SDA    | MOSI
 *    RST    | RESET#
 *    CD     | D/C#
 *    CS     | CS#
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
		// Data sheet says 3us
		delay1us(3);
		gpioWrite(&device->interface->resetOutput, 1);
		// Data sheet says 5ms
		delay1ms(5);
	}
	
	// Set inverse display so that "on" pixels are black
	// on a white background.
	lcdSendCommand(device->interface, 0xa7);
	
	// Set LCD mapping control to Mirror Y
	// so that 0,0 is at the upper left corner.
	lcdSendCommand(device->interface, 0xc4);
	
	// Set Vbias potentiometer: set contrast to 160/255
	lcdSendCommand(device->interface, 0x81);
	lcdSendCommand(device->interface, 160);
	
	// Initialise DDRAM
	for (uint8_t i = 0; i < 8; i++) {
		for (uint8_t j = 0; j < 128; j++) {
			lcdSendData(device->interface, 0xff);
		}
	}
	
	// Display on
	lcdSendCommand(device->interface, 0xaf);
}

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85

void lcdDisplayControl(LCDDevice *device, bool displayOn, bool cursorOn, bool blinkCursor)  {
	lcdSendCommand(device->interface, 0xae | (displayOn ? 1 : 0));
}

#pragma restore

void lcdSetGraphicsDisplayAddress(LCDDevice *device, uint8_t pixelX, uint8_t pixelY) {
	lcdSendCommand(device->interface, 0xb0 | ((pixelY >> 3) & 0x0f));
	lcdSendCommand(device->interface, 0x10 | ((pixelX >> 4) & 0x0f));
	lcdSendCommand(device->interface, pixelX & 0x0f);
}

void lcdWriteByte(LCDDevice *device, uint8_t byte)  {
	lcdSendData(device->interface, byte);
}

void lcdInverseDisplay(LCDDevice *device, bool on) {
	lcdSendCommand(device->interface, 0xa6 | (on ? 1 : 0));
}

void lcdAllPixelsOn(LCDDevice *device, bool on) {
	lcdSendCommand(device->interface, 0xa4 | (on ? 1 : 0));
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
