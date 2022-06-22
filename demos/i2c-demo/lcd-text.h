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

#include "lcd-device.h"

/**
 * @file lcd-text.h
 * 
 * Text operations for LCD devices: definitions.
 */

void lcd_txtInitialiseDisplayMode(LCD_Device *device);

void lcd_txtClear(LCD_Device *device);

void lcd_txtPrintAt(LCD_Device *device, uint16_t row, uint16_t column, const char *__fmt, ...);

typedef struct {
	const char *label;
	int value;
	uint8_t isDefault;
	uint8_t row;
	uint8_t col;
} LCD_MenuOption;

typedef struct {
	LCD_Device *lcdDevice;
	LCD_MenuOption *menuOptions;
	uint8_t nbOptions;
	uint8_t selectedOption;
	uint8_t menuWidth;
	uint8_t startRow;
	uint8_t startCol;
} LCD_MenuData;

typedef enum {
	LCD_SelectNext,
	LCD_SelectPrevious,
} LCD_NewSelection;

/**
 * menuWidth == 0 => each LCD_MenuOption must specify row and col, 
 * and all options are displayed simultaneously.
 * 
 * menuWidth != 0 => the selected LCD_MenuOption will be displayed 
 * at startRow, startCol. Chaging selection will replace it with
 * the newly selected option. menuWidth < 0 => autodetect menu width.
 */
void lcd_txtMenu_initialise(LCD_MenuData *menuData, LCD_Device *device, 
	LCD_MenuOption *menuOptions, uint8_t nbOptions, 
	signed char menuWidth, uint8_t startRow, uint8_t startCol);

void lcd_txtMenu_onChangeSelection(LCD_MenuData *menuData, LCD_NewSelection newSelection);

int lcd_txtMenu_onValidateSelection(LCD_MenuData *menuData);

#endif // _LCD_TEXT_H
