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
#ifndef _LCD_CONTROLLER_H
#define _LCD_CONTROLLER_H

#include "lcd-device.h"

/**
 * @file lcd-controller.h
 * 
 * LCD controller abstraction layer: definitions.
 */

void lcd_initialiseController(LCD_Device *device);

void lcd_clearTextDisplay(LCD_Device *device);

void lcd_returnHome(LCD_Device *device);

/**
 * @param textDirection 1 = shift display when cursor goes beyond display edge,
 * 0 = don't shift.
 * @param shiftDisplay 1 = increment address counter => move cursor right (LTR text) or shift display left, 
 * 0 = decrement address counter => move cursor left (RTL text) or shift display right.
 */
void lcd_setEntryMode(LCD_Device *device, uint8_t textDirection, uint8_t shiftDisplay);

/**
 * @param displayOn Set entire display on/off
 * @param cursorOn Set cursor on/off
 * @param blinkCursor Cursor blink on/off
 */
void lcd_displayControl(LCD_Device *device, uint8_t displayOn, uint8_t cursorOn, uint8_t blinkCursor);

/**
 * @param shiftDisplay 1 = shift display, 0 = move cursor.
 * @param shiftRight 1 = display shifts or cursor moves right, 0 = display shifts or cursor moves left.
 * 
 * shiftDisplay == 1 && shiftRight == 1 => display shifts right, cursor follows, address counter does not change.
 * shiftDisplay == 1 && shiftRight == 0 => display shifts left,  cursor follows, address counter does not change.
 * shiftDisplay == 0 && shiftRight == 1 => cursor moves right, address counter is incremented.
 * shiftDisplay == 0 && shiftRight == 0 => cursor moves left,  address counter is decremented.
 */
void lcd_cursorDisplayShiftControl(LCD_Device *device, uint8_t shiftDisplay, uint8_t shiftRight);

void lcd_enableGraphicsDisplay(LCD_Device *device);

void lcd_disableGraphicsDisplay(LCD_Device *device);

void lcd_setCharacterGeneratorAddress(LCD_Device *device, uint8_t address);

void lcd_setTextDisplayAddress(LCD_Device *device, uint8_t address);

/**
 * Convenience function. 
 * 
 * Calculates the DDRAM address corresponding to the specified row and column, and calls lcd_setTextDisplayAddress().
 */
void lcd_setTextDisplayPosition(LCD_Device *device, uint8_t row, uint8_t column);

/**
 * Sets the GDRAM address to point at the 16-bit word containing the specified pixel.
 */
void lcd_setGraphicsDisplayAddress(LCD_Device *device, uint16_t pixelX, uint16_t pixelY);

uint8_t lcd_readBusyFlagAndAddress(LCD_Device *device);

void lcd_writeByte(LCD_Device *device, uint8_t byte);

uint8_t lcd_readByte(LCD_Device *device);

/**
 * Calling any other function will cause the device to leave standby mode.
 */
void lcd_enterStandbyMode(LCD_Device *device);

void lcd_enableVerticalScroll(LCD_Device *device);

void lcd_disableVerticalScroll(LCD_Device *device);

/**
 * Reverses the pixel colours of the specified text row.
 */
void lcd_reverseRow(LCD_Device *device, uint8_t row);

void lcd_setScrollAddress(LCD_Device *device, uint8_t address);

#endif // _LCD_CONTROLLER_H
