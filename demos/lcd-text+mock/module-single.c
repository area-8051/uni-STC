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
#include "module-single.h"

/**
 * @file module-single.c
 * 
 * Single-line menu module implementation.
 * 
 * Demonstrates:
 * 
 * - Single-line menu
 * - Returning to parent module
 */

#define BACK 255

static LCDMenuOption menu[] = {
	{ .label = "Option 0", .value = 0, .isDefault = true, .isEnabled = true, },
	{ .label = "Option 1", .value = 1, .isDefault = false, .isEnabled = true, },
	{ .label = "Option 2", .value = 2, .isDefault = false, .isEnabled = true, },
	{ .label = "Back", .value = BACK, .isDefault = false, .isEnabled = true, },
};

static struct {
	LCDDevice *lcdDevice;
	LCDMenuData menuData;
} _moduleData;

void singleModule_initialise(LCDDevice *lcdDevice) {
	_moduleData.lcdDevice = lcdDevice;
	lcdTxtClear(_moduleData.lcdDevice);
	lcdTxtPrintAt(_moduleData.lcdDevice, 0, 0, "- Single-line menu -");
	lcdTxtPrintAt(_moduleData.lcdDevice, 1, 0, "Action:");
	lcdTxtMenuInitialise(
		&_moduleData.menuData, _moduleData.lcdDevice, 
		menu, sizeof(menu) / sizeof(LCDMenuOption), 
		LCD_SingleLineMenu, 0, 1, 8, false
	);
}

void singleModule_onMove(bool moveForward, bool withButtonPressed) {
	lcdTxtMenuOnChangeSelection(&_moduleData.menuData, moveForward ? LCD_SelectNext : LCD_SelectPrevious);
}

ModuleId singleModule_onAction(bool buttonPushed) {
	ModuleId result = Module_SingleLine;
	
	if (buttonPushed) {
		int optionValue = _moduleData.menuData.menuOptions[_moduleData.menuData.selectedOption].value;
		
		if (optionValue == BACK) {
			// Return to parent module.
			result = Module_Root;
		} else {
			// Simulate option selection handling.
			lcdTxtPrintAt(_moduleData.lcdDevice, 2, 0, "Selected: %d", optionValue);
		}
	}
	
	return result;
}

void singleModule_onIdle() {
}
