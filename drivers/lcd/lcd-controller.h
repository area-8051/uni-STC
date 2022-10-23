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

#include <lcd/lcd-device.h>

/**
 * @file lcd-controller.h
 * 
 * LCD controller abstraction layer: definitions.
 */

void lcdInitialiseController(LCDDevice *device);

void lcdClearTextDisplay(LCDDevice *device);

void lcdReturnHome(LCDDevice *device);

/**
 * @param textDirection true = shift display when cursor goes beyond display edge,
 * false = don't shift.
 * @param shiftDisplay true = increment address counter => move cursor right (LTR text) or shift display left, 
 * false = decrement address counter => move cursor left (RTL text) or shift display right.
 */
void lcdSetEntryMode(LCDDevice *device, bool textDirection, bool shiftDisplay);

/**
 * @param displayOn Set entire display on/off
 * @param cursorOn Set cursor on/off
 * @param blinkCursor Cursor blink on/off
 */
void lcdDisplayControl(LCDDevice *device, bool displayOn, bool cursorOn, bool blinkCursor);

/**
 * @param shiftDisplay true = shift display, false = move cursor.
 * @param shiftRight true = display shifts or cursor moves right, false = display shifts or cursor moves left.
 * 
 * shiftDisplay && shiftRight => display shifts right, cursor follows, address counter does not change.
 * shiftDisplay && !shiftRight => display shifts left,  cursor follows, address counter does not change.
 * !shiftDisplay && shiftRight => cursor moves right, address counter is incremented.
 * !shiftDisplay && !shiftRight => cursor moves left,  address counter is decremented.
 */
void lcdCursorDisplayShiftControl(LCDDevice *device, bool shiftDisplay, bool shiftRight);

void lcdEnableGraphicsDisplay(LCDDevice *device);

void lcdDisableGraphicsDisplay(LCDDevice *device);

void lcdSetCharacterGeneratorAddress(LCDDevice *device, uint8_t address);

void lcdSetTextDisplayAddress(LCDDevice *device, uint8_t address);

/**
 * Convenience function. 
 * 
 * Calculates the DDRAM address corresponding to the specified row and column, and calls lcdSetTextDisplayAddress().
 */
void lcdSetTextDisplayPosition(LCDDevice *device, uint8_t row, uint8_t column);

/**
 * Sets the GDRAM address to point at the 16-bit word containing the specified pixel.
 */
void lcdSetGraphicsDisplayAddress(LCDDevice *device, uint16_t pixelX, uint16_t pixelY);

uint8_t lcdReadBusyFlagAndAddress(LCDDevice *device);

void lcdWriteByte(LCDDevice *device, uint8_t byte);

uint8_t lcdReadByte(LCDDevice *device);

/**
 * Calling any other function will cause the device to leave standby mode.
 */
void lcdEnterStandbyMode(LCDDevice *device);

void lcdEnableVerticalScroll(LCDDevice *device);

void lcdDisableVerticalScroll(LCDDevice *device);

/**
 * Reverses the pixel colours of the specified text row.
 */
void lcdReverseRow(LCDDevice *device, uint8_t row);

void lcdSetScrollAddress(LCDDevice *device, uint8_t address);

#endif // _LCD_CONTROLLER_H
