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
#include "lcd-text.h"
#include "lcd-controller.h"
#include <stdio.h>
#include <string.h>

/**
 * @file lcd-text.c
 * 
 * Text operations for LCD devices: implementation.
 */

void lcd_txtInitialiseDisplayMode(LCD_Device *device) {
	lcd_disableGraphicsDisplay(device);
	lcd_txtClear(device);
}

void lcd_txtClear(LCD_Device *device) {
	lcd_clearTextDisplay(device);
}

void lcd_txtPrintAt(LCD_Device *device, uint16_t row, uint16_t column, const char *__fmt, ...) {
	va_list vaList;
	
	// Using a static buffer avoids consuming most of our scarce stack space.
	// This choice is unlikely to have any side effect on a poor MCS-51.
	// Besides, we're unlikely to have to worry about using a static buffer 
	// on any other MCU architecture (except maybe those cursed legacy PIC).
	static char buffer[81];

	// Strings of latin characters can start at any position provided
	// their length is an even number.
	// 16-bit Chinese characters can only start at an even position.
	// For the sake of simplicity, we do not want to start at odd columns.
	column &= ~1;
	lcd_setTextDisplayPosition(device, row, column);

	// CAUTION! SDCC doesn't provide vsnprintf(), so beware of buffer 
	// overflows if you can print arbitrary long values.
	va_start(vaList, __fmt);
	vsprintf(buffer, __fmt, vaList);
	va_end(vaList);
	
	// Make sure the length of the string is an even number
	// by adding a space if it isn't.
	uint16_t l = strlen(buffer);
	
	if (l & 1) {
		buffer[l] = ' ';
		buffer[++l] = '\0';
	}
	
	// Truncate the string if it would go past the end of the row.
	uint16_t lMax = device->textWidth - column;
	lMax &= ~1;
	
	if (l > lMax) {
		buffer[lMax] = '\0';
		l = lMax;
	}

	// Now we're good to go!
	for (uint8_t i = 0; i < l; i++) {
		lcd_writeByte(device, buffer[i]);
	}
}

#define MENU_LABEL_MAX_LENGTH 14

static void _lcd_txtMenu_displayOption(LCD_MenuData *menuData, uint8_t n) {
	// static => Same trick as in lcd_txtPrintAt().
	static char buffer[MENU_LABEL_MAX_LENGTH + 3];
	uint8_t maxLabelLen = 0;
	uint8_t row = menuData->menuOptions[n].row;
	uint8_t col = menuData->menuOptions[n].col;
	
	if (menuData->menuWidth != 0) {
		row = menuData->startRow;
		col = menuData->startCol;
		maxLabelLen = (menuData->menuWidth > 2) ? (menuData->menuWidth - 2) : 0;
	} else {
		if (menuData->lcdDevice->textWidth > col) {
			maxLabelLen = menuData->lcdDevice->textWidth - col;
			maxLabelLen = (maxLabelLen > 2) ? (maxLabelLen - 2) : 0;
		}
	}
	
	if (maxLabelLen > MENU_LABEL_MAX_LENGTH) {
		maxLabelLen = MENU_LABEL_MAX_LENGTH;
	}
	
	strncpy(buffer + 1, menuData->menuOptions[n].label, maxLabelLen);
	buffer[0] = (n == menuData->selectedOption) ? '>' : ' ';
	buffer[++maxLabelLen] = '\0';
	
	if (menuData->menuWidth != 0) {
		while (strlen(buffer) < maxLabelLen) {
			strcat(buffer, " ");
		}
	}
	
	if (n == menuData->selectedOption) {
		strcat(buffer, "<");
	} else {
		strcat(buffer, " ");
	}
	
	lcd_txtPrintAt(menuData->lcdDevice, row, col, "%s", buffer);
}

void lcd_txtMenu_initialise(LCD_MenuData *menuData, LCD_Device *device, 
	LCD_MenuOption *menuOptions, uint8_t nbOptions, 
	signed char menuWidth, uint8_t startRow, uint8_t startCol) {
	menuData->lcdDevice = device;
	menuData->menuOptions = menuOptions;
	menuData->nbOptions = nbOptions;
	menuData->startRow = startRow;
	menuData->startCol = startCol;
	menuData->selectedOption = 0;
	
	if (menuWidth < 0) {
		// menuWidth < 0 => autodetect menu width.
		menuData->menuWidth = 0;
		
		for (uint8_t i = 0; i < menuData->nbOptions; i ++) {
			size_t l = strlen(menuData->menuOptions[i].label);
			
			if (l > MENU_LABEL_MAX_LENGTH) {
				l = MENU_LABEL_MAX_LENGTH;
			}
			
			if (l > menuData->menuWidth) {
				menuData->menuWidth = l;
			}
		}
		
		menuData->menuWidth += 2;
		uint8_t availableWidth = menuData->lcdDevice->textWidth - menuData->startCol;
		
		if (menuData->menuWidth > availableWidth) {
			menuData->menuWidth = availableWidth;
		}
	} else {
		menuData->menuWidth = menuWidth;
	}
	
	for (uint8_t i = 0; i < menuData->nbOptions; i ++) {
		if (menuData->menuOptions[i].isDefault) {
			menuData->selectedOption = i;
			break;
		}
	}
	
	if (menuData->menuWidth == 0) {
		for (uint8_t i = 0; i < menuData->nbOptions; i ++) {
			_lcd_txtMenu_displayOption(menuData, i);
		}
	} else {
		_lcd_txtMenu_displayOption(menuData, menuData->selectedOption);
	}
}

void lcd_txtMenu_onChangeSelection(LCD_MenuData *menuData, LCD_NewSelection newSelection) {
	uint8_t previousOption = menuData->selectedOption;
	
	switch (newSelection) {
	case LCD_SelectNext:
		menuData->selectedOption++;
		
		if (menuData->selectedOption >= menuData->nbOptions) {
			menuData->selectedOption = 0;
		}
		break;
	
	case LCD_SelectPrevious:
		if (menuData->selectedOption == 0) {
			menuData->selectedOption = menuData->nbOptions;
		}
		
		menuData->selectedOption--;
		break;
	}
	
	if (menuData->menuWidth == 0) {
		_lcd_txtMenu_displayOption(menuData, previousOption);
	}
	
	_lcd_txtMenu_displayOption(menuData, menuData->selectedOption);
}

int lcd_txtMenu_onValidateSelection(LCD_MenuData *menuData) {
	return menuData->menuOptions[menuData->selectedOption].value;
}
