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
#include <adc-comp-hal.h>
#include <gpio-hal.h>
#include <delay.h>

/**
 * @file adc-comp-hal.c
 * 
 * ADC and comparator abstraction layer implementation.
 */

inline void adcPowerOnDelay() {
#if MCU_FAMILY == 8 && (MCU_SERIES == 'G' || MCU_SERIES == 'H')
	// The STC8A TRM doesn't specify a power on delay and none is used in code examples.
	delay1ms(1);
#elif MCU_FAMILY == 12 || MCU_FAMILY == 15
	// The STC12 and STC15 TRM doesn't specify a power on delay BUT one is used in code examples.
	delay1ms(2);
#endif // MCU_FAMILY == 8 && (MCU_SERIES == 'G' || MCU_SERIES == 'H')
}

void adcPowerOn() {
	ADC_CONTR |= M_ADC_POWER;
	adcPowerOnDelay();
}

void adcPowerOff() {
	ADC_CONTR &= ~M_ADC_POWER;
}

inline void adcClearResult() {
#if MCU_FAMILY == 12 || MCU_FAMILY == 15
	// Clear previous result. This is not mentioned in the TRM, but
	// code examples for the STC12 and STC15 do it.
	ADC_RES = 0;
#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
}

static __bit rightAligned;

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void adcInitialise(ADC_Alignment resultAlignment, InterruptEnable useInterrupts) {
	rightAligned = (resultAlignment == ADC_ALIGN_RIGHT);

	#if MCU_FAMILY == 12
		P_SW1 = rightAligned ? (P_SW1 | M_RESFMT) : (P_SW1 & ~M_RESFMT);
	#elif MCU_FAMILY == 15
		CLKDIV = rightAligned ? (CLKDIV | M_RESFMT) : (CLKDIV & ~M_RESFMT);
	#elif MCU_FAMILY == 8
		ADCCFG = rightAligned ? (ADCCFG | M_RESFMT) : (ADCCFG & ~M_RESFMT);
	#endif // MCU_FAMILY == 12
	
	uint8_t adcContr = M_ADC_POWER;
	
	#ifdef MCU_HAS_ADCTIM
		// Use recommended settings from Technical Reference Manual
		#define cssetup 0
		#define cshold 1
		#define smpduty 15
		ENABLE_EXTENDED_SFR();
		ADCTIM = (cssetup << P_CSSETUP) | (cshold << P_CSHOLD) | (smpduty << P_SMPDUTY);
		DISABLE_EXTENDED_SFR();
		
		#define CYCLES_PER_CONV ((cssetup + 1) + (cshold + 1) + (smpduty + 1) + ADC_BITS)
	#elif MCU_FAMILY == 8
		#define CYCLES_PER_CONV 16
	#else // STC12 & STC15
		// On the STC12 and STC15, the number of clock cycles allowed
		// for the conversion seems to be a design choice. The TRM 
		// doesn't give any explanation as to how to choose the speed
		// and the code example uses the slowest speed.
		// However, a developer's natural expectation will likely be
		// that the ADC runs at its maximum speed, so let's use it as
		// default value.
		#ifndef ADC_CYCLES
			#define ADC_CYCLES 90
		#endif
		
		#if ADC_CYCLES <= 90
			#define SPEED 3
		#elif ADC_CYCLES <= 180
			#define SPEED 2
		#elif ADC_CYCLES <= 360
			#define SPEED 1
		#else // 540 cycles
			#define SPEED 0
		#endif
		
		adcContr |= SPEED << P_ADC_SPEED;
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
	
	if (useInterrupts == ENABLE_INTERRUPT) {
		IE1 |= M_EADC;
	}
	
	ADC_CONTR = adcContr;
	adcPowerOnDelay();
}
#pragma restore

#define NONE 0xff

static const uint8_t __adcPins[] = {
	// 0xff means "do NOT configure GPIO pin".
	// I didn't use a macro to keep arrays aligned, and because it's only used in adcConfigureChannel().
	#if MCU_FAMILY == 8 && MCU_SERIES == 'H'
		#if ADC_CHANNELS == 9
			0x10, 0x11, NONE, NONE, NONE, NONE, NONE, NONE, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, NONE, 
		#elif ADC_CHANNELS == 15
			0x10, 0x11, 0x54, NONE, NONE, NONE, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, NONE, 
		#elif defined(ADC_NO_CHANNEL3)
			0x10, 0x11, 0x12, NONE, NONE, NONE, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, NONE, 
		#else
			0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, NONE, NONE, NONE, NONE, 
		#endif // ADC_CHANNELS == 9
	#endif // MCU_FAMILY == 8 && MCU_SERIES == 'H'
	
	#if MCU_FAMILY == 8 && (MCU_SERIES == 'A' || MCU_SERIES == 'G')
		#if ADC_CHANNELS == 6
			0x30, 0x31, 0x32, 0x33, 0x54, 0x55, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, 
		#else
			0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, NONE, 
		#endif // ADC_CHANNELS == 6
	#endif // MCU_FAMILY == 8 && (MCU_SERIES == 'A' || MCU_SERIES == 'G')
	
	#if MCU_FAMILY == 12 || MCU_FAMILY == 15
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
	#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
};

void adcConfigureChannel(ADC_Channel channel) {
	uint8_t channelPin = __adcPins[channel];
	
	if (channelPin != NONE) {
		// Set GPIO pin to high-impedance mode
		GpioPort port = (GpioPort) (channelPin >> 4);
		GpioPin pin = (GpioPin) (channelPin & 0x0f);
		GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, GPIO_HIGH_IMPEDANCE_MODE);
#ifdef GPIO_HAS_SR_DR_IE
		pinConfig.digitalInput = DISABLE_GPIO_DIGITAL_INPUT;
#endif // GPIO_HAS_SR_DR_IE
		gpioConfigure(&pinConfig);
		
#if MCU_FAMILY == 12 || MCU_FAMILY == 15
		P1ASF |= (1 << channel);
#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
	}
}

uint16_t adcBlockingRead(ADC_Channel channel) {
	adcClearResult();
	ADC_CONTR = (ADC_CONTR & ~M_ADC_CHS) | channel | M_ADC_START;
	NOP();
	NOP();
#if MCU_FAMILY == 12 || MCU_FAMILY == 15
	NOP();
	NOP();
#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15

	while (!(ADC_CONTR & M_ADC_FLAG));
	
	ADC_CONTR &= ~M_ADC_FLAG;
	
	return adcReadResult();
}

void adcStartConversion(ADC_Channel channel) {
	adcClearResult();
	ADC_CONTR = (ADC_CONTR & ~M_ADC_CHS) | channel | M_ADC_START;
}

uint16_t adcReadResult() {
	// Left alignment means we only want the 8 most significant bits of the result.
	// Right alignment means we want the full result.
	return rightAligned ? ADC_RES : ((uint16_t) ADC_RESH);
}

#ifdef M_ADC_EPWMT
	void adcPwmTriggered(ADC_Channel channel) {
		ADC_CONTR = (ADC_CONTR & ~M_ADC_CHS) | channel | M_ADC_EPWMT;
	}
#endif // M_ADC_EPWMT

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void compInitialise(
	COMP_PositiveInput positiveInput,
	// Ignored when positiveInput != POSITIVE_INPUT_ADC_IN.
	ADC_Channel adcChannel,
	COMP_NegativeInput negativeInput,
	// Used on COMPARATOR_4P2N, ignored by other comparator versions.
	COMP_InputHysteresis inputHysteresis,
	COMP_OutputMode outputMode,
	COMP_AnalogFilter analogFilter,
	// Debounces comparator output during (digitalFilter + 2) system
	// clocks when digitalFilter is in the range 1..63, disabled if 0.
	uint8_t digitalFilter,
	COMP_EdgeInterrupt interruptMode
) {
	if (positiveInput == POSITIVE_INPUT_ADC_IN) {
		if (!(ADC_CONTR & M_ADC_POWER)) {
			adcPowerOn();
		}
		
		adcConfigureChannel(adcChannel);
		ADC_CONTR = (ADC_CONTR & ~M_ADC_CHS) | adcChannel;
	}
	
	CMPCR2 = ((outputMode & 1) << P_INVCMPO)
		| (analogFilter << P_DISFLT)
		| (digitalFilter & M_LCDTY);
	
	#ifdef COMPARATOR_4P2N
		ENABLE_EXTENDED_SFR();
		CMPEXCFG = (inputHysteresis << P_CHYS)
			| (negativeInput << P_CMPNS)
			| positiveInput;
		DISABLE_EXTENDED_SFR();
	#endif // COMPARATOR_4P2N
	
	uint8_t cmpcr1 = M_CMPEN
		| (interruptMode << P_NIE)
		| (outputMode != COMP_OUTPUT_DISABLE ? M_CMPOE : 0);
	
	#ifndef COMPARATOR_4P2N
		cmpcr1 |= (positiveInput & 1) << P_PIS;
		cmpcr1 |= negativeInput << P_NIS;
	#endif // COMPARATOR_4P2N
	
	CMPCR1 = cmpcr1;
}
#pragma restore

COMP_Result compRead() {
	CMPCR1 &= ~M_CMPIF;
	
	return (COMP_Result) (CMPCR1 & M_CMPRES);
}
