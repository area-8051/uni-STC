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
 * @file HD44780.c
 * 
 * Driver for text-only LCD devices using an HD44780-compatible controller.
 * Examples include the SPLC780D1 and the KS0066U.
 * 
 * These devices support 1-line (up to 80 columns), 2-line (up to 40 
 * columns), and 4-line (up to 20 columns) display configurations.
 * 
 * This file implements the abstraction layer described in 
 * lcd-controller.h, which is why it doesn't have its own header file. 
 * This design decision was driven by MCS-51/SDCC restrictions on 
 * function calls made through pointers. As a consequence, if the 
 * application uses several LCD devices, ALL of them **MUST** be based 
 * on the same controller model.
 * 
 * **Pin assignments (parallel interface)**
 * 
 * Signal	Description
 * ---------------------------------------------------------------------
 * VSS		Connect to GND
 * VDD		Connect to +5V
 * VO		Contrast adjustment. Connect to GND for maximum contrast.
 * RS		Register Select. 0 = Instruction, 1 = Data.
 * RW		Transfer direction. 0 = Write, 1 = Read.
 * E		I/O enable. Enables data out when high. Latches data in on falling edge.
 * D0		Data bus (bidirectional).
 * D1
 * D2
 * D3
 * D4
 * D5
 * D6
 * D7
 * A		Backlight anode. Connect to +5V.
 * K		Backlight cathode. Connect to GND.
 * 
 * **Notes**
 * 
 * - If you find backlight too bright, you may connect A to +5V through 
 * a resistor of, say 150 or 180 Ohm.
 * 
 * - If contrast is too weak with VO connected to GND (text only visible 
 * when viewed under a small angle), check your power supply voltage 
 * (must be greater than 4.5V).
 * 
 * - In 4-bit parallel mode, only D7..D4 are used, and most significant 
 * nibble is always transfered first.
 */

#include "project-defs.h"
#include <lcd/lcd-controller.h>
#include <delay.h>

// Microseconds
#define WRITE_DELAY 50

static void __waitWhileBusy(LCDInterface *interface) {
	while (lcdReadStatus(interface) & 0x80);
}

static void __sendCommand(LCDDevice *device, uint8_t command) {
	__waitWhileBusy(device->interface);
	lcdSendCommand(device->interface, command);
	device->__status.setAddressInvoked = 0;
	// All instructions take 50us except Clear Display and Return Home
	delay1us(WRITE_DELAY);
}

static void __sendData(LCDInterface *interface, uint8_t data) {
	__waitWhileBusy(interface);
	lcdSendData(interface, data);
	// All data write operations take 50us
	delay1us(WRITE_DELAY);
}

static uint8_t __readData(LCDInterface *interface) {
	__waitWhileBusy(interface);
	
	return lcdReadData(interface);
}

static void __displayControl(LCDDevice *device, bool displayOn, bool cursorOn, bool blinkCursor) {
	// Set entire display on/off
	uint8_t d = displayOn ? 4 : 0;
	// Set cursor on/off
	uint8_t c = cursorOn ? 2 : 0;
	// Cursor blink on/off
	uint8_t s = blinkCursor ? 1 : 0;
	__sendCommand(device, 0x08 | d | c | s);
}

static void __clearTextDisplay(LCDDevice *device) {
	__sendCommand(device, 0x01);
	// Clear Display takes 1.6ms but we already waited for WRITE_DELAY in sendCommand()
	delay1us(1600 - WRITE_DELAY);
}

static void __setEntryMode(LCDDevice *device, bool textDirection, bool shiftDisplay) {
	// 1 = shift display when cursor goes beyond display edge
	// 0 = don't shift
	uint8_t s = shiftDisplay ? 1 : 0;
	// 1 = increment address counter => move cursor right (LTR text) or shift display left, 
	// 0 = decrement address counter => move cursor left (RTL text) or shift display right
	uint8_t id = textDirection ? 2 : 0;
	__sendCommand(device, 0x04 | id | s);
}

void lcdInitialiseController(LCDDevice *device)  {
    lcdLinkConfigurationBegins(device->interface);
	
	// Data sheet says to wait for >= 50ms
	delay1ms(50);

	if (lcdIsLinkParallel(device->interface)) {
		// Configure parallel interface mode
		
		// In case of a warm reset, we must make sure to be in 8-bit mode
		// so the context is the same as after a power-on reset.
		__sendCommand(device, 0x30);
		// Wait for 4.1ms, but we've already waited for WRITE_DELAY in sendCommnand()
		delay1us(4100 - WRITE_DELAY);
		__sendCommand(device, 0x30);
		// Wait for 100us, but we've already waited for WRITE_DELAY in sendCommnand()
		delay1us(100 - WRITE_DELAY);
		__sendCommand(device, 0x30);
		
		if (lcdGetLinkWidth(device->interface) != 8) {
			// Switch to 4-bit mode
			__sendCommand(device, 0x20);
		}
	}
    
    lcdLinkConfigurationComplete(device->interface);
    
	// Function Set (only valid at initialisation)
	// dl = number of data lines (0 = 4-bit mode, 0x10 = 8-bit mode)
	uint8_t dl = lcdGetLinkWidth(device->interface) == 8 ? 0x10 : 0;
	// n = number of display lines (0 = 1 line, 0x08 = 2 lines)
	uint8_t n = device->textHeight > 1 ? 0x08 : 0;
	// f = character font (0 = 5x8 font, 0x04 = 5x10 font)
	// Note: cannot display 2 lines of text with 5x10 font.
	uint8_t f = 0;
	__sendCommand(device, 0x20 | dl | n | f);

	// Turn display on, no cursor, no blinking.
	__displayControl(device, 1, 0, 0);

	// Clear display
    __clearTextDisplay(device);

	// Set Entry Mode
	__setEntryMode(device, 1, 0);
}

void lcdWriteByte(LCDDevice *device, uint8_t byte)  {
	__sendData(device->interface, byte);
}

uint8_t lcdReadByte(LCDDevice *device)  {
	return __readData(device->interface);
}

uint8_t lcdReadBusyFlagAndAddress(LCDDevice *device)  {
	return lcdReadStatus(device->interface);
}

void lcdClearTextDisplay(LCDDevice *device)  {
	__clearTextDisplay(device);
}

void lcdReturnHome(LCDDevice *device)  {
	__sendCommand(device, 0x02);
	// Return Home takes 1.6ms but we already waited for WRITE_DELAY in sendCommand()
	delay1us(1600 - WRITE_DELAY);
}

void lcdSetEntryMode(LCDDevice *device, bool textDirection, bool shiftDisplay)  {
	__setEntryMode(device, textDirection, shiftDisplay);
}

void lcdDisplayControl(LCDDevice *device, bool displayOn, bool cursorOn, bool blinkCursor)  {
	__displayControl(device, displayOn, cursorOn, blinkCursor);
}

void lcdCursorDisplayShiftControl(LCDDevice *device, bool shiftDisplay, bool shiftRight)  {
	// 1 = Shift display, 0 = Move cursor
	uint8_t sc = shiftDisplay ? 8 : 0;
	// 1 = Shift/move to the right, 0 = Shift/move to the left
	uint8_t rl = shiftRight ? 4 : 0;
	__sendCommand(device, 0x10 | sc | rl);
}

void lcdSetCharacterGeneratorAddress(LCDDevice *device, uint8_t address)  {
	__sendCommand(device, 0x40 | (address & 0x3F));
}

void lcdSetTextDisplayAddress(LCDDevice *device, uint8_t address)  {
	__sendCommand(device, 0x80 | (address & 0x7f));
}

void lcdSetTextDisplayPosition(LCDDevice *device, uint8_t row, uint8_t column)  {
	uint8_t rowAddr = 0;
	uint8_t colAddr = column;
	
	if (device->textHeight > 1) {
		rowAddr = (row & 0x01) << 6;
		colAddr &= 0x3f;
		
		if (row > 1) {
			colAddr += 0x14;
		}
	}
	
	lcdSetTextDisplayAddress(device, rowAddr | colAddr);
}

// Functionalities below are not available on this controller.
// ---------------------------------------------------------------------

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85

void lcdSetGraphicsDisplayAddress(LCDDevice *device, uint8_t pixelX, uint8_t pixelY) {
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

#pragma restore
