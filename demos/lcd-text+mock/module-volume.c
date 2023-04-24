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
#include "module-volume.h"

/**
 * @file module-volume.c
 * 
 * Volume module implementation.
 * 
 * Demonstrates:
 * 
 * - Returning to parent module
 * - Using rotary encoder events to change a value
 * - A module does not necessarily have a menu
 */

static struct {
	LCDDevice *lcdDevice;
	LCDMenuData menuData;
	uint8_t volume;
} _moduleData = { .volume = 10, };

#define LOWER_BOUND 0
#define UPPER_BOUND 100
#define INCREMENT   1

static void updateVolume() {
	lcdTxtPrintAt(_moduleData.lcdDevice, 0, 0, "Volume: %3hhd", _moduleData.volume);
}

void volumeModule_initialise(LCDDevice *lcdDevice) {
	_moduleData.lcdDevice = lcdDevice;
	lcdTxtClear(_moduleData.lcdDevice);
	updateVolume();
}

void volumeModule_onMove(bool moveForward, bool withButtonPressed) {
	// This code works with any value of INCREMENT, and can be
	// used with both signed and unsigned variables, provided
	// UPPER_BOUND > LOWER_BOUND and
	// INCREMENT < (UPPER_BOUND - LOWER_BOUND)
	
	if (moveForward) {
		if (_moduleData.volume < (UPPER_BOUND - INCREMENT)) {
			_moduleData.volume += INCREMENT;
		} else {
			_moduleData.volume = UPPER_BOUND;
		}
	} else {
		if (_moduleData.volume > (LOWER_BOUND + INCREMENT)) {
			_moduleData.volume -= INCREMENT;
		} else {
			_moduleData.volume = LOWER_BOUND;
		}
	}
	
	updateVolume();
}

ModuleId volumeModule_onAction(bool buttonPushed) {
	ModuleId result = Module_Volume;
	
	if (buttonPushed) {
		// We've accepted the new value, let's go back to parent menu.
		result = Module_Root;
	}
	
	return result;
}

void volumeModule_onIdle() {
}
