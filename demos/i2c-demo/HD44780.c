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
 * 
 * These devices support 1-line (up to 80 columns) and 2-line (up to 40 
 * columns) display configurations.
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
#include "lcd-controller.h"
#include "delay.h"

static void __waitWhileBusy(LCD_Interface *interface) {
	while (lcd_readStatus(interface) & 0x80);
}

static void __sendCommand(LCD_Device *device, uint8_t command) {
	__waitWhileBusy(device->interface);
	lcd_sendCommand(device->interface, command);
	device->__status.setAddressInvoked = 0;
	// All instructions except Clear Display and Return Home take 50us
	delay10us(5);
}

static void __sendData(LCD_Interface *interface, uint8_t data) {
	__waitWhileBusy(interface);
	lcd_sendData(interface, data);
	// All data write operations take 50us
	delay10us(5);
}

static uint8_t __readData(LCD_Interface *interface) {
	__waitWhileBusy(interface);
	
	return lcd_readData(interface);
}

static void __displayControl(LCD_Device *device, uint8_t displayOn, uint8_t cursorOn, uint8_t blinkCursor) {
	// Set entire display on/off
	uint8_t d = displayOn ? 4 : 0;
	// Set cursor on/off
	uint8_t c = cursorOn ? 2 : 0;
	// Cursor blink on/off
	uint8_t s = blinkCursor ? 1 : 0;
	__sendCommand(device, 0x08 | d | c | s);
}

static void __clearTextDisplay(LCD_Device *device) {
	__sendCommand(device, 0x01);
	// Clear Display takes 1.6ms but we already waited for 50us in sendCommand()
	delay10us(155);
}

static void __setEntryMode(LCD_Device *device, uint8_t textDirection, uint8_t shiftDisplay) {
	// 1 = shift display when cursor goes beyond display edge
	// 0 = don't shift
	uint8_t s = shiftDisplay ? 1 : 0;
	// 1 = increment address counter => move cursor right (LTR text) or shift display left, 
	// 0 = decrement address counter => move cursor left (RTL text) or shift display right
	uint8_t id = textDirection ? 2 : 0;
	__sendCommand(device, 0x04 | id | s);
}

void lcd_initialiseController(LCD_Device *device)  {
    lcd_linkConfigurationBegins(device->interface);
	
	// Data sheet says to wait for >= 50ms
	delay1ms(50);

	if (lcd_isLinkParallel(device->interface)) {
		// Configure parallel interface mode
		
		// In case of a warm reset, we must make sure to be in 8-bit mode
		// so the context is the same as after a power-on reset.
		__sendCommand(device, 0x30);
		// Wait for 4.1ms, but we've already waited for 50us in sendCommnand()
		delay1ms(4);
		delay10us(5);
		__sendCommand(device, 0x30);
		// Wait for 100us, but we've already waited for 50us in sendCommnand()
		delay10us(5);
		__sendCommand(device, 0x30);
		
		if (lcd_getLinkWidth(device->interface) != 8) {
			// Switch to 4-bit mode
			__sendCommand(device, 0x20);
		}
	}
    
    lcd_linkConfigurationComplete(device->interface);
    
	// Function Set (only valid at initialisation)
	// dl = number of data lines (0 = 4-bit mode, 0x10 = 8-bit mode)
	uint8_t dl = lcd_getLinkWidth(device->interface) == 8 ? 0x10 : 0;
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

void lcd_writeByte(LCD_Device *device, uint8_t byte)  {
	__sendData(device->interface, byte);
}

uint8_t lcd_readByte(LCD_Device *device)  {
	return __readData(device->interface);
}

uint8_t lcd_readBusyFlagAndAddress(LCD_Device *device)  {
	return lcd_readStatus(device->interface);
}

void lcd_clearTextDisplay(LCD_Device *device)  {
	__clearTextDisplay(device);
}

void lcd_returnHome(LCD_Device *device)  {
	__sendCommand(device, 0x02);
	// Return Home takes 1.6ms but we already waited for 50us in sendCommand()
	delay10us(155);
}

void lcd_setEntryMode(LCD_Device *device, uint8_t textDirection, uint8_t shiftDisplay)  {
	__setEntryMode(device, textDirection, shiftDisplay);
}

void lcd_displayControl(LCD_Device *device, uint8_t displayOn, uint8_t cursorOn, uint8_t blinkCursor)  {
	__displayControl(device, displayOn, cursorOn, blinkCursor);
}

void lcd_cursorDisplayShiftControl(LCD_Device *device, uint8_t shiftDisplay, uint8_t shiftRight)  {
	// 1 = Shift display, 0 = Move cursor
	uint8_t sc = shiftDisplay ? 8 : 0;
	// 1 = Shift/move to the right, 0 = Shift/move to the left
	uint8_t rl = shiftRight ? 4 : 0;
	__sendCommand(device, 0x10 | sc | rl);
}

void lcd_setCharacterGeneratorAddress(LCD_Device *device, uint8_t address)  {
	__sendCommand(device, 0x40 | (address & 0x3F));
}

void lcd_setTextDisplayAddress(LCD_Device *device, uint8_t address)  {
	__sendCommand(device, 0x80 | (address & 0x7f));
}

void lcd_setTextDisplayPosition(LCD_Device *device, uint8_t row, uint8_t column)  {
	uint8_t rowAddr = 0;
	uint8_t colAddr = column;
	
	if (device->textHeight > 1) {
		rowAddr = (row & 0x01) << 6;
		colAddr &= 0x3f;
	}
	
	lcd_setTextDisplayAddress(device, rowAddr | colAddr);
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_setGraphicsDisplayAddress(LCD_Device *device, uint16_t pixelX, uint16_t pixelY) {
	// Not available on this controller.
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_enableGraphicsDisplay(LCD_Device *device)  {
	// Not available on this controller.
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_disableGraphicsDisplay(LCD_Device *device)  {
	// Not available on this controller.
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_enterStandbyMode(LCD_Device *device)  {
	// Not available on this controller.
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_reverseRow(LCD_Device *device, uint8_t row)  {
	// Not available on this controller.
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_setScrollAddress(LCD_Device *device, uint8_t address)  {
	// Not available on this controller.
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_enableVerticalScroll(LCD_Device *device) {
	// Not available on this controller.
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void lcd_disableVerticalScroll(LCD_Device *device) {
	// Not available on this controller.
}
