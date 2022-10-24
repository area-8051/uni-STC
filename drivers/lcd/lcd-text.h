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
	bool isDefault;
	uint8_t row;
	uint8_t col;
} LCDMenuOption;

typedef enum {
	LCD_SingleLineMenu,	/*!< Only the currently selected option is displayed at (startRow, startCol). */
	LCD_ListMenu,		/*!< The LCDMenuOption are displayed as a vertical list starting at (startRow, startCol). */
	LCD_PositionnedMenu,/*!< Each LCDMenuOption specifies its (row, col). menuWidth is ignored in this mode. */
} LCDMenuDisplayMode;

typedef struct {
	LCDDevice *lcdDevice;
	LCDMenuOption *menuOptions;
	uint8_t nbOptions;
	uint8_t selectedOption;
	LCDMenuDisplayMode displayMode;
	uint8_t menuWidth;
	uint8_t startRow;
	uint8_t startCol;
} LCDMenuData;

void lcdTxtMenuInitialise(
	LCDMenuData *menuData, 
	LCDDevice *device, 
	LCDMenuOption *menuOptions, 
	uint8_t nbOptions, 
	LCDMenuDisplayMode displayMode,
	int8_t menuWidth, /*!< When <= 0, menuWidth is calculated automatically. */
	uint8_t startRow, 
	uint8_t startCol
);

typedef enum {
	LCD_SelectNext,
	LCD_SelectPrevious,
	LCD_RefreshOption,
} LCDNewSelection;

void lcdTxtMenuOnChangeSelection(LCDMenuData *menuData, LCDNewSelection newSelection);

int lcdTxtMenuOnValidateSelection(LCDMenuData *menuData);

#endif // _LCD_TEXT_H
