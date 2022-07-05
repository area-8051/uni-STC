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
#include "adc-hal.h"
#include "gpio-hal.h"
#include "delay.h"

/**
 * @file adc-hal.c
 * 
 * ADC abstraction layer implementation.
 */

void adcPowerOn() {
	ADC_CONTR |= M_ADC_POWER;
	
#if MCU_FAMILY == 8 && (MCU_SERIES == 'G' || MCU_SERIES == 'H')
	delay1ms(1);
#endif // MCU_FAMILY == 8 && (MCU_SERIES == 'G' || MCU_SERIES == 'H')
}

void adcPowerOff() {
	ADC_CONTR &= ~M_ADC_POWER;
}

void adcInitialise(ADC_Alignment resultAlignment, ADC_InterruptEnable useInterrupts) {
	#if MCU_FAMILY == 12
		P_SW1 = resultAlignment ? (P_SW1 | M_RESFMT) : (P_SW1 & ~M_RESFMT);
	#elif MCU_FAMILY == 15
		CLKDIV = resultAlignment ? (CLKDIV | M_RESFMT) : (CLKDIV & ~M_RESFMT);
	#elif MCU_FAMILY == 8
		ADCCFG = resultAlignment ? (ADCCFG | M_RESFMT) : (ADCCFG & ~M_RESFMT);
	#endif // MCU_FAMILY == 12
	
	#ifdef MCU_HAS_ADCTIM
		// Use recommended settings from Technical Reference Manual
		#define cssetup 0
		#define cshold 1
		#define smpduty 15
		ADCTIM = (cssetup << P_CSSETUP) | (cshold << P_CSHOLD) | (smpduty << P_SMPDUTY);
		
		#define CYCLES_PER_CONV ((cssetup + 1) + (cshold + 1) + (smpduty + 1) + ADC_BITS)
	#elif MCU_FAMILY == 8
		#define CYCLES_PER_CONV 16
	#else // STC12 & STC15
		#define CYCLES (MCU_FREQ / ADC_MAX_SAMPLE_RATE)
		
		#if CYCLES <= 90
			#define SPEED 3
		#elif CYCLES <= 180
			#define SPEED 2
		#elif CYCLES <= 360
			#define SPEED 1
		#else
			#define SPEED 0
		#endif
		
		ADC_CONTR = (ADC_CONTR & ~M_ADC_SPEED) | ((SPEED << P_ADC_SPEED) & M_ADC_SPEED);
	#endif // MCU_HAS_ADCTIM
	
	#if MCU_FAMILY == 8
		// Adjust speed to stay below ADC_MAX_SAMPLE_RATE
		#define SPEED (MCU_FREQ / 2UL / CYCLES_PER_CONV / ADC_MAX_SAMPLE_RATE)
		
		#if SPEED >= 16
			#define ADJ_SPEED 15
		#elif SPEED > 0
			#define ADJ_SPEED (SPEED - 1)
		#else
			#define ADJ_SPEED 0
		#endif
		
		ADCCFG = (ADCCFG & ~M_ADC_SPEED) | ((ADJ_SPEED << P_ADC_SPEED) & M_ADC_SPEED);
	#endif // MCU_FAMILY == 8
	
	ADC_CONTR &= ~M_ADC_FLAG;
	
	if (useInterrupts == ADC_INTERRUPT_ENABLE) {
		IE1 |= M_EADC;
	}
	
	adcPowerOn();
}

static const uint8_t __adcPins[] = {
	// 0xff means "do NOT configure GPIO pin".
	// I didn't use a macro to keep arrays aligned, and because it's only used in adcConfigureChannel().
	#if MCU_FAMILY == 8 && MCU_SERIES == 'H'
		#if ADC_CHANNELS == 9
			0x10, 0x11, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0xff, 
		#elif ADC_CHANNELS == 15
			0x10, 0x11, 0x54, 0xff, 0xff, 0xff, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0xff, 
		#elif defined(ADC_NO_CHANNEL3)
			0x10, 0x11, 0x12, 0xff, 0xff, 0xff, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0xff, 
		#else
			0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, 0xff, 0xff, 0xff, 0xff, 
		#endif // ADC_CHANNELS == 9
	#endif // MCU_FAMILY == 8 && MCU_SERIES == 'H'
	
	#if MCU_FAMILY == 8 && (MCU_SERIES == 'A' || MCU_SERIES == 'G')
		#if ADC_CHANNELS == 6
			0x30, 0x31, 0x32, 0x33, 0x54, 0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
		#else
			0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0xff, 
		#endif // ADC_CHANNELS == 6
	#endif // MCU_FAMILY == 8 && (MCU_SERIES == 'A' || MCU_SERIES == 'G')
	
	#if MCU_FAMILY == 12 || MCU_FAMILY == 15
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
	#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
};

void adcConfigureChannel(ADC_Channel channel) {
	uint8_t channelPin = __adcPins[channel];
	
	if (channelPin != 0xff) {
		// Set GPIO pin to high-impedance mode
		GpioPort port = (GpioPort) (channelPin >> 4);
		GpioPin pin = (GpioPin) (channelPin & 0x0f);
		GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, GPIO_HIGH_IMPEDANCE);
#ifdef GPIO_HAS_SR_DR_IE
		pinConfig.digitalInput = GPIO_DISABLED;
#endif // GPIO_HAS_SR_DR_IE
		gpioConfigure(&pinConfig);
		
#if MCU_FAMILY == 12 || MCU_FAMILY == 15
		P1ASF |= 1 << channel;
#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
	}
}

uint16_t adcBlockingRead(ADC_Channel channel) {
	ADC_CONTR = (ADC_CONTR & ~M_ADC_CHS) | channel | M_ADC_START;
	NOP();
	NOP();
#if MCU_FAMILY == 12 || MCU_FAMILY == 15
	NOP();
	NOP();
#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
	while (!(ADC_CONTR & M_ADC_FLAG));
	ADC_CONTR &= ~M_ADC_FLAG;
	
	return (ADC_RESH << 8) | ADC_RESL;
}

void adcStartConversion(ADC_Channel channel) {
	ADC_CONTR = (ADC_CONTR & ~M_ADC_CHS) | channel | M_ADC_START;
}
