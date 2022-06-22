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
#include "delay.h"

/*
 * -- LCD DISPLAY ------------------------------------------------------
 * 
 * The LCD display module is a 12864 with an ST7920 controller.
 * For maximum speed, and because we have plenty of GPIO pins,
 * we'll use its parallel interface in 8-bit mode.
 */

#include "lcd-device.h"
#include "lcd-text.h"
#include "lcd-link-i2c.h"

/*
 * PIN ASSIGNMENTS:
 * 
 * SCL is connected to P1.5.
 * SDA is connected to P1.4.
 */
LCD_I2CLinkConfig lcdLinkConfig = {
	.slaveAddress  = 0x27,
	.pinSwitch = 0,
};

/*
 * LCD device definition.
 */
LCD_TEXT_ONLY_DEVICE(lcdDevice, &lcdLinkConfig, 2, 16)

void main() {
	// Initialise LCD module -------------------------------------------
	lcd_initialiseDevice(&lcdDevice);
	lcd_txtInitialiseDisplayMode(&lcdDevice);
		
	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		lcd_txtClear(&lcdDevice);
		delay1ms(1000);
		lcd_txtPrintAt(&lcdDevice, 0, 0, "Hello,");
		delay1ms(1000);
		lcd_txtPrintAt(&lcdDevice, 1, 8, "World!");
		delay1ms(1000);
	}
}
