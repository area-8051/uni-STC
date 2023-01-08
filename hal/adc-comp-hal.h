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
#ifndef _ADC_COMP_HAL_H
#define _ADC_COMP_HAL_H

/**
 * @file adc-comp-hal.h
 * 
 * ADC abstraction layer definitions.
 * 
 * Supported MCU:
 * 
 *     STC12*
 *     STC15*
 *     STC8*
 * 
 * Comparator abstraction layer definitions.
 * 
 * Supported MCU:
 * 
 *     STC15*
 *     STC8*
 * 
 * Dependencies:
 * 
 *     gpio-hal
 *     delay
 */

#include <hal-defs.h>

typedef enum {
	// Left alignment means we only want the 8 most significant bits of the result.
	ADC_ALIGN_LEFT = 0,
	// Right alignment means we want the full result.
	ADC_ALIGN_RIGHT = 1,
} ADC_Alignment;

typedef enum {
	ADC_CHANNEL0 = 0,
	ADC_CHANNEL1 = 1,
#ifndef ADC_NO_CHANNEL2
	ADC_CHANNEL2 = 2,
#endif // ADC_NO_CHANNEL2
#ifndef ADC_NO_CHANNEL3
	ADC_CHANNEL3 = 3,
#endif // ADC_NO_CHANNEL3
#ifndef ADC_NO_CHANNEL4
	ADC_CHANNEL4 = 4,
#endif // ADC_NO_CHANNEL4
#ifndef ADC_NO_CHANNEL5
	ADC_CHANNEL5 = 5,
#endif // ADC_NO_CHANNEL5
#if ADC_CHANNELS > 6
	#ifndef ADC_NO_CHANNEL6
		ADC_CHANNEL6 = 6,
	#endif // ADC_NO_CHANNEL6
	#ifndef ADC_NO_CHANNEL7
		ADC_CHANNEL7 = 7,
	#endif // ADC_NO_CHANNEL7
#endif // ADC_CHANNELS > 6
#if ADC_CHANNELS > 8
	ADC_CHANNEL8 = 8,
	ADC_CHANNEL9 = 9,
	ADC_CHANNEL10 = 10,
	ADC_CHANNEL11 = 11,
	#ifndef ADC_NO_CHANNEL12
		ADC_CHANNEL12 = 12,
	#endif // ADC_NO_CHANNEL12
	#ifndef ADC_NO_CHANNEL13
		ADC_CHANNEL13 = 13,
	#endif // ADC_NO_CHANNEL13
	#ifndef ADC_NO_CHANNEL14
		ADC_CHANNEL14 = 14,
	#endif // ADC_NO_CHANNEL14
#endif // ADC_CHANNELS > 8
#if MCU_FAMILY == 8
	ADC_INTERNAL_VREF = 15,
#endif // MCU_FAMILY == 8
} ADC_Channel;

/**
 * ADC initialisation.
 */
void adcInitialise(ADC_Alignment resultAlignment, InterruptEnable useInterrupts);

/**
 * ADC input pin configuration.
 * 
 * Must be called for each ADC channel used by the application,
 * before or after adcInitialise().
 */
void adcConfigureChannel(ADC_Channel channel);

/**
 * Turn off ADC power.
 * 
 * Must be called before entering a power saving mode.
 */
void adcPowerOff();

/**
 * Turn on ADC power.
 * 
 * Called internally by adcInitialise().
 * Can be called when leaving a power saving mode.
 */
void adcPowerOn();

/**
 * As the name implies, starts an ADC conversion, waits for its 
 * completion, and returns the result.
 */
uint16_t adcBlockingRead(ADC_Channel channel);

/**
 * Start an ADC conversion when ADC interrupts are used.
 * 
 * There's no predefined interrupt service routine, you have to supply 
 * one with the following prototype:
 * 
 * INTERRUPT_USING(__adc_isr, ADC_INTERRUPT, 1);
 */
void adcStartConversion(ADC_Channel channel);

uint16_t adcReadResult();

#ifdef M_ADC_EPWMT
	/**
	 * Prepares ADC to be triggered by PWM.
	 * 
	 * Note 1: only applicable to STC8G, STC8H and STC8A8K64D4.
	 * 
	 * Note 2: interrupts MUST be enabled when calling adcInitialise()
	 * to use this mode. And of course, an ISR must be provided.
	 */
	void adcPwmTriggered(ADC_Channel channel);
#endif // M_ADC_EPWMT

typedef enum {
	COMP_EDGE_RISING = 2,
	COMP_EDGE_FALLING = 1,
	COMP_EDGE_BOTH = 3,
	COMP_EDGE_DISABLED = 0,
} COMP_EdgeInterrupt;

typedef enum {
	POSITIVE_INPUT_P37 = 0,
	#ifndef COMPARATOR_1P2N
		POSITIVE_INPUT_ADC_IN = 3,
	#endif // COMPARATOR_1P2N
	#ifdef COMPARATOR_4P2N
		POSITIVE_INPUT_P50 = 1,
		POSITIVE_INPUT_P51 = 2,
	#endif // COMPARATOR_4P2N
} COMP_PositiveInput;

typedef enum {
	NEGATIVE_INPUT_INTERNAL_VREF = 0,
	NEGATIVE_INPUT_P36 = 1,
} COMP_NegativeInput;

typedef enum {
	COMP_HYSTERESIS_0 = 0,
	COMP_HYSTERESIS_10mV = 1,
	COMP_HYSTERESIS_20mV = 2,
	COMP_HYSTERESIS_30mV = 3,
} COMP_InputHysteresis;

typedef enum {
	COMP_OUTPUT_DISABLE = 0,
	COMP_OUTPUT_NORMAL = 2,
	COMP_OUTPUT_INVERT = 3,
} COMP_OutputMode;

typedef enum {
	COMP_ANALOG_FILTER_OFF = 1,
	COMP_ANALOG_FILTER_ON = 0,
} COMP_AnalogFilter;

typedef enum {
	COMP_POSITIVE_LOWER_THAN_NEGATIVE = 0,
	COMP_POSITIVE_HIGHER_THAN_NEGATIVE = 1,
} COMP_Result;

#define COMP_IGNORE_ADC_CHANNEL ADC_CHANNEL0
#define COMP_DIGITAL_FILTER_OFF 0

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
);

/**
 * Reads the comparator output value and clear interrupt flag.
 */
COMP_Result compRead();

#endif // _ADC_COMP_HAL_H
