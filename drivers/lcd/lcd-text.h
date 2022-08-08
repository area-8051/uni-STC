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
#ifndef _LCD_TEXT_H
#define _LCD_TEXT_H

#include <lcd/lcd-device.h>

/**
 * @file lcd-text.h
 * 
 * Text operations for LCD devices: definitions.
 */

void lcdTxtInitialiseDisplayMode(LCDDevice *device);

void lcdTxtClear(LCDDevice *device);

void lcdTxtPrintAt(LCDDevice *device, uint16_t row, uint16_t column, const char *__fmt, ...);

typedef struct {
	const char *label;
	int value;
	uint8_t isDefault;
	uint8_t row;
	uint8_t col;
} LCDMenuOption;

typedef struct {
	LCDDevice *lcdDevice;
	LCDMenuOption *menuOptions;
	uint8_t nbOptions;
	uint8_t selectedOption;
	uint8_t menuWidth;
	uint8_t startRow;
	uint8_t startCol;
} LCDMenuData;

typedef enum {
	LCD_SelectNext,
	LCD_SelectPrevious,
} LCDNewSelection;

/**
 * menuWidth == 0 => each LCDMenuOption must specify row and col, 
 * and all options are displayed simultaneously.
 * 
 * menuWidth != 0 => the selected LCDMenuOption will be displayed 
 * at startRow, startCol. Changing selection will replace it with
 * the newly selected option. menuWidth < 0 => autodetect menu width.
 */
void lcdTxtMenuInitialise(
	LCDMenuData *menuData, 
	LCDDevice *device, 
	LCDMenuOption *menuOptions, 
	uint8_t nbOptions, 
	int8_t menuWidth, 
	uint8_t startRow, 
	uint8_t startCol
);

void lcdTxtMenuOnChangeSelection(LCDMenuData *menuData, LCDNewSelection newSelection);

int lcdTxtMenuOnValidateSelection(LCDMenuData *menuData);

#endif // _LCD_TEXT_H
