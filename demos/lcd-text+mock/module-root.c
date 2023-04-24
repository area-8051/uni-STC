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
#include "module-root.h"

/**
 * @file module-root.c
 * 
 * Root module implementation.
 * 
 * Demonstrates:
 * 
 * - List menu
 * - Navigation
 * - Menu option refresh
 */

#define TOGGLE 255

const char * const toggleValueON = "Toggle is ON";
const char * const toggleValueOFF = "Toggle is OFF";

static LCDMenuOption menu[] = {
	{ .label = "Positionned menu", .value = Module_Position, .isDefault = true, .isEnabled = true, },
	{ .label = "Single-line menu", .value = Module_SingleLine, .isDefault = false, .isEnabled = true, },
	{ .label = "Adjust volume", .value = Module_Volume, .isDefault = false, .isEnabled = true, },
	{ .label = toggleValueOFF, .value = TOGGLE, .isDefault = false, .isEnabled = true, },
};

static struct {
	LCDDevice *lcdDevice;
	LCDMenuData menuData;
	bool toggleValue;
	bool keepSelectedOption;
} _moduleData = {
	.toggleValue = false,
	.keepSelectedOption = false,
};

void rootModule_initialise(LCDDevice *lcdDevice) {
	_moduleData.lcdDevice = lcdDevice;
	lcdTxtClear(_moduleData.lcdDevice);
	lcdTxtMenuInitialise(
		&_moduleData.menuData, _moduleData.lcdDevice, 
		menu, sizeof(menu) / sizeof(LCDMenuOption), 
		LCD_ListMenu, 0, 0, 0, _moduleData.keepSelectedOption
	);
	_moduleData.keepSelectedOption = true;
}

void rootModule_onMove(bool moveForward, bool withButtonPressed) {
	lcdTxtMenuOnChangeSelection(&_moduleData.menuData, moveForward ? LCD_SelectNext : LCD_SelectPrevious);
}

ModuleId rootModule_onAction(bool buttonPushed) {
	ModuleId result = Module_Root;
	
	if (buttonPushed) {
		int optionValue = _moduleData.menuData.menuOptions[_moduleData.menuData.selectedOption].value;
		
		if (optionValue == TOGGLE) {
			_moduleData.toggleValue = !_moduleData.toggleValue;
			menu[3].label = _moduleData.toggleValue ? toggleValueON : toggleValueOFF;
			lcdTxtMenuOnChangeSelection(&_moduleData.menuData, LCD_RefreshOption);
		} else {
			result = (ModuleId) optionValue;
		}
	}
	
	return result;
}

void rootModule_onIdle() {
}
