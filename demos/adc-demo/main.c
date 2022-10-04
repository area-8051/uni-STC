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
#include <delay.h>
#include <adc-comp-hal.h>
#include <uart-hal.h>
#include <serial-console.h>
#include <stdio.h>

void main() {
	INIT_EXTENDED_SFR()
	
	serialConsoleInitialise(
		CONSOLE_UART, 
		CONSOLE_SPEED, 
		CONSOLE_PIN_CONFIG
	);
	
	adcInitialise(ADC_ALIGN_RIGHT, DISABLE_INTERRUPT);
	adcConfigureChannel(DEMO_ADC_CHANNEL);
	
	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		delay1ms(2000);
		printf("ADC max. value = %u\r\n", ((1 << ADC_BITS) - 1));
		printf("ADC Channel %2hhd = %u\r\n", DEMO_ADC_CHANNEL, adcBlockingRead(DEMO_ADC_CHANNEL));
#if MCU_FAMILY == 8
		printf("ADC Channel 15 = %u\r\n", adcBlockingRead(ADC_INTERNAL_VREF));
#endif // MCU_FAMILY == 8
	}
}
