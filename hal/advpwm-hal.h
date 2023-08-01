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
#ifndef _ADVPWM_HAL_H
#define _ADVPWM_HAL_H

/**
 * @file advpwm-hal.h
 * 
 * 16-bit advanced PWM abstraction definitions.
 * 
 * Supported MCU:
 * 
 *     STC8H*
 * 
 * Dependencies:
 * 
 *     gpio-hal
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 * 
 * **IMPORTANT:** You MUST define both pwmOnCounterInterrupt() and
 * pwmOnChannelInterrupt(), even if you don't use them.
 * 
 * **IMPORTANT:** Some functionalities need to be individually enabled
 * via the following macros when needed (#define in project-defs.h):
 * 
 * HAL_PWM_API_DISABLE             pwmDisableCounter
 * HAL_PWM_API_FAULT_DETECTION     pwmConfigureFaultDetection
 * HAL_PWM_API_EXTERNAL_TRIGGER    pwmConfigureExternalTrigger
 * HAL_PWM_API_DEAD_TIME           pwmConfigureDeadTime
 * HAL_PWM_API_STOP                pwmStopPWM
 * HAL_PWM_API_LOCK                pwmLockPWM
 * HAL_PWM_API_QUADRATURE_ENCODER  pwmInitialiseQuadratureEncoder
 */

#include <hal-defs.h>

#ifndef HAL_PWM_CHANNELS
	#define HAL_PWM_CHANNELS 8
#endif

#if HAL_PWM_CHANNELS != 1 && HAL_PWM_CHANNELS != 2 && HAL_PWM_CHANNELS != 4 && HAL_PWM_CHANNELS != 8
	#undef HAL_PWM_CHANNELS
	#define HAL_PWM_CHANNELS 8
#endif

typedef enum {
	PWM_COUNTER_A = 0,
#if HAL_PWM_CHANNELS > 4
	PWM_COUNTER_B = 1,
#endif
} PWM_Counter;

typedef enum {
	PWM_FREE_RUNNING = 0,
	PWM_EVENT_COUNTER1 = 1, // Input 1 (PWM1/5) sets direction (up/down), Input 2 (PWM2/6) clocks in events
	PWM_EVENT_COUNTER2 = 2, // Input 2 (PWM2/6) sets direction (up/down), Input 1 (PWM1/5) clocks in events
	PWM_QUADRATURE_ENCODER = 3,
	PWM_RESET_MODE = 4,
	PWM_GATED_MODE = 5,
	PWM_TRIGGER_MODE = 6,
	PWM_EXTERNAL_CLOCK = 7,
} PWM_CounterMode;

typedef enum {
	PWM_NO_TRIGGER = 0,
	PWM_COUNTER_B_TRGO = 2,  // Only applicable to PWM_COUNTER_A
	PWM_EDGE_DETECTOR = 4,   // PWM1 for counter A, PWM5 for counter B
	PWM_FILTERED_INPUT1 = 5, // PWM1 for counter A, PWM5 for counter B
	PWM_FILTERED_INPUT2 = 6, // PWM2 for counter A, PWM6 for counter B
	PWM_EXTERNAL_TRIGGER = 7,
} PWM_TriggerSource;

// Controls both the CMS and DIR fields of PWMx_CR1
typedef enum {
	// Counter counts up only
	PWM_EDGE_ALIGNED_UP = 0,
	// Counter counts down only
	PWM_EDGE_ALIGNED_DOWN = 1,
	// Counter counts up and down
	// PWM IF is set when counter counts down
	PWM_CENTRE_ALIGNED_INT_DOWN = 2,
	// Counter counts up and down
	// PWM IF is set when counter counts up
	PWM_CENTRE_ALIGNED_INT_UP = 4,
	// Counter counts up and down
	// PWM IF is set when counter counts both up and down
	PWM_CENTRE_ALIGNED_INT_UP_DOWN = 6,
} PWM_CounterDirection;

typedef enum {
	PWM_IMMEDIATE_UPDATE = 0,
	PWM_BUFFERED_UPDATE = 1,
} PWM_RegisterUpdate;

// Controls both the URS and UDIS fields of PWMx_CR1.
// Enabling update events also enables UE interrupts.
typedef enum {
	// Disables all update events
	PWM_DISABLE_ALL_UE = 1,
	// Enables all update events, i.e. counter wrap, software UE, clock/trigger UE
	PWM_ENABLE_ALL_UE = 0,
	// Enables only counter wrap events (overflow/underflow)
	PWM_ENABLE_WRAP_UE_ONLY = 2,
} PWM_UpdateEventEnable;

typedef enum {
	PWM_CONTINUOUS = 0,
	PWM_SINGLE_PULSE = 1,
} PWM_CounterRunMode;

/**
 * When mode == PWM_EXTERNAL_CLOCK,
 *     counterFreq => prescaler value
 *     signalFreq  => reload value
 * When mode == PWM_EVENT_COUNTER1 || PWM_EVENT_COUNTER2 || PWM_QUADRATURE_ENCODER,
 *     no prescaler
 *     signalFreq => reload value
 * Other modes,
 *     MCU_FREQ / counterFreq => prescaler value
 *     counterFreq / signalFreq  => reload value
 */
uint16_t pwmConfigureCounter(
	PWM_Counter counter, 
	uint32_t counterFreq, 
	uint32_t signalFreq, 
	PWM_CounterMode mode, 
	PWM_TriggerSource trigger,
	uint8_t repeatCount, 
	PWM_RegisterUpdate registerUpdateMode,
	PWM_CounterRunMode counterRunMode,
	PWM_CounterDirection counterDirection,
	PWM_UpdateEventEnable updateEventEnable,
	InterruptEnable comInterrupt
);

void pwmEnableCounter(PWM_Counter counter);

#ifdef HAL_PWM_API_DISABLE
void pwmDisableCounter(PWM_Counter counter);
#endif // HAL_PWM_API_DISABLE

typedef enum {
	PWM_Channel0 = 0,
	PWM_Channel1 = 2,
	PWM_Channel2 = 4,
	PWM_Channel3 = 6,
#if HAL_PWM_CHANNELS > 4
	PWM_Channel4 = 8,
	PWM_Channel5 = 10,
	PWM_Channel6 = 12,
	PWM_Channel7 = 14,
#endif
} PWM_Channel;

typedef enum {
	PWM_FILTER_1_CLOCK = 0,
	PWM_FILTER_2_CLOCKS,
	PWM_FILTER_4_CLOCKS,
	PWM_FILTER_8_CLOCKS,
	PWM_FILTER_12_CLOCKS,
	PWM_FILTER_16_CLOCKS,
	PWM_FILTER_24_CLOCKS,
	PWM_FILTER_32_CLOCKS,
	PWM_FILTER_48_CLOCKS,
	PWM_FILTER_64_CLOCKS,
	PWM_FILTER_80_CLOCKS,
	PWM_FILTER_96_CLOCKS,
	PWM_FILTER_128_CLOCKS,
	PWM_FILTER_160_CLOCKS,
	PWM_FILTER_192_CLOCKS,
	PWM_FILTER_256_CLOCKS,
} PWM_Filter;

typedef enum {
	PWM_ACTIVE_HIGH = 0,
	PWM_ACTIVE_LOW,
} PWM_Polarity;

/**
 * Pin configurations
 * 
 * Value | PWM1P | PWM1N | PWM2P | PWM2N | PWM3P | PWM3N | PWM4P | PWM4N | PWM5 | PWM6 | PWM7 | PWM8 |
 * ------+-------+-------+-------+-------+-------+-------+-------+-------+------+------+------+------+
 *   0   | P1.0  | P1.1  | P1.2# | P1.3  | P1.4  | P1.5  | P1.6  | P1.7  | P2.0 | P2.1 | P2.2 | P2.3 |
 *   1   | P2.0  | P2.1  | P2.2  | P2.3  | P2.4  | P2.5  | P2.6  | P2.7  | P1.7 | P5.4 | P3.3 | P3.4 |
 *   2   | P6.0  | P6.1  | P6.2  | P6.3  | P6.4  | P6.5  | P6.6  | P6.7  | P0.0 | P0.1 | P0.2 | P0.3 |
 *   3   |   -   |   -   |   -   |   -   |   -   |   -   | P3.4  | P3.3  | P7.4 | P7.5 | P7.6 | P7.7 |
 *
 * #: P5.4 when P1.2 is not available (except STC8H1K08/17-36I-SOP16).
 * 
 * Value |PWMET1 |PWMET2 |
 * ------+-------+-------+
 *   0   | P3.2  | P3.2  |
 *   1   | P4.1  | P0.6  |
 *   2   | P7.3  |   -   |
 *   3   |   -   |   -   |
 * 
 * Value |PWMFLT1|PWMFLT2|
 * ------+-------+-------+
 *   0   | P3.5  | P3.5  |
 *   1   | Comp. | Comp. |
 *   2   |   -   |   -   |
 *   3   |   -   |   -   |
 * 
 * Comp.: Comparator output.
 */

typedef enum {
	PWM_OUTPUT_P_ONLY = 1,
	PWM_OUTPUT_N_ONLY = 2,
	PWM_OUTPUT_COMPLEMENTARY = 3,
} PWM_OutputEnable;

typedef enum {
	PWM_DISABLE_FAULT_CONTROL = 0,
	PWM_ENABLE_FAULT_CONTROL,
} PWM_FaultControl;

/**
 * Configures the output pin of a PWM channel.
 * Must be called after pwmStartPWM().
 * Parameter outputEnable is ignored for channels of counter B.
 */
void pwmConfigureOutput(
	PWM_Channel channel, 
	uint8_t pinSwitch, 
	GpioPinMode pinMode,
	PWM_Polarity polarity, 
	PWM_FaultControl faultControl,
	OutputLevel idleLevel,
	PWM_OutputEnable outputEnable
);

typedef enum {
	PWM_CAPTURE_ON_RISING_EDGE = 0,
	PWM_CAPTURE_ON_FALLING_EDGE,
} PWM_CaptureEdge;

/**
 * PWM_CAPTURE_SAME_PIN is the pin corresponding to the channel.
 * PWM_CAPTURE_OTHER_PIN is the other pin in the same pair.
 * 
 * Channel   0     1     2     3     4    5    6    7
 * Same pin  PWM1P PWM2P PWM3P PWM4P PWM5 PWM6 PWM7 PWM8
 * Other pin PWM2P PWM1P PWM4P PWM3P PWM6 PWM5 PWM8 PWM7
 */
typedef enum {
	PWM_CAPTURE_SAME_PIN = 1,
	PWM_CAPTURE_OTHER_PIN,
	PWM_CAPTURE_TRC,
} PWM_CaptureSource;

typedef enum {
	// Calculates time elapsed between consecutive events on same pin.
	PWM_REFERENCE_SAME_PIN = 0,
	// Calculates time elapsed between event on same pin - event on other pin.
	PWM_REFERENCE_OTHER_PIN,
} PWM_CaptureReference;

// ---------------------------------------------------------------------

#ifdef HAL_PWM_API_FAULT_DETECTION
/**
 * Configures PWM fault detection, aka. "brake".
 */

typedef enum {
	PWM_FAULT_PIN = 0,
	PWM_FAULT_COMPARATOR,
} PWM_FaultTrigger;

typedef enum {
	PWM_SOFTWARE_RESUME = 0,
	PWM_AUTOMATIC_RESUME,
} PWM_FaultResume;

typedef enum {
	PWM_OUTPUT_DISABLED = 0,
	PWM_OUTPUT_ENABLED_IDLE_LEVEL,
	PWM_OUTPUT_ENABLED_INVALID_LEVEL,
} PWM_FaultResponse;

void pwmConfigureFaultDetection(
	PWM_Counter counter, 
	PWM_FaultTrigger faultTrigger, 
	PWM_Polarity faultPolarity, 
	PWM_FaultResponse faultResponse,
	PWM_FaultResume faultResume, 
	InterruptEnable enableInterrupt
);
#endif // HAL_PWM_API_FAULT_DETECTION

#ifdef HAL_PWM_API_EXTERNAL_TRIGGER
	typedef enum {
		PWM_DISABLE_EXTERNAL_CLOCK = 0,
		PWM_ENABLE_EXTERNAL_CLOCK,
	} PWM_ExternalClock;

	typedef enum {
		PWM_TRIGGER_ON_FALLING_EDGE = 0,
		PWM_TRIGGER_ON_RISING_EDGE,
	} PWM_TriggerEdge;

	typedef enum {
		PWM_TRIGGER_PRESCALER_DIV_1 = 0,
		PWM_TRIGGER_PRESCALER_DIV_2,
		PWM_TRIGGER_PRESCALER_DIV_4,
		PWM_TRIGGER_PRESCALER_DIV_8,
	} PWM_TriggerPrescaler;

	void pwmConfigureExternalTrigger(
		PWM_Counter counter, 
		uint8_t pinSwitch, 
		PWM_TriggerEdge triggerEdge,
		PWM_ExternalClock externalClock,
		PWM_TriggerPrescaler prescaler,
		PWM_Filter filter,
		InterruptEnable enableInterrupt
	);
#endif // HAL_PWM_API_EXTERNAL_TRIGGER

#ifdef HAL_PWM_API_DEAD_TIME
void pwmConfigureDeadTime(PWM_Counter counter, uint16_t clockPulses);
#endif // HAL_PWM_API_DEAD_TIME

void pwmEnableMainOutput(PWM_Counter counter);

/**
 * Configures and starts a PWM channel.
 */
void pwmInitialisePWM(
	PWM_Channel channel, 
	OutputLevel initialLevel, 
	InterruptEnable enableInterrupt, 
	PWM_RegisterUpdate registerUpdateMode,
	uint16_t ticks
);

/**
 * Changes the duty cycle of a PWM channel.
 * All other configuration parameters remain unchanged.
 * 
 * @param ticks value assigned to PWMx_CCRyH / PWMx_CCRyL.
 */
void pwmSetDutyCycle(PWM_Channel channel, uint16_t ticks);

#ifdef HAL_PWM_API_STOP
	/**
	 * Resets the configuration of a PWM channel.
	 * pwmInitialisePWM() must be called again to restart the channel.
	 */
	void pwmStopPWM(PWM_Channel channel);
#endif // HAL_PWM_API_STOP

#ifdef HAL_PWM_API_LOCK
	/**
	 * Permanently forces a PWM output in the specified logical level.
	 * You will need to call pwmInitialisePWM() to unlock it.
	 */
	void pwmLockPWM(PWM_Channel channel, OutputLevel outputLevel);
#endif // HAL_PWM_API_LOCK

/**
 * Calls pwmConfigureInput() internally.
 */
void pwmInitialiseCapture(
	PWM_Channel channel, 
	uint8_t pinSwitch, 
	PWM_CaptureEdge captureEdge, 
	PWM_CaptureSource captureSource,
	PWM_Filter filter,
	PWM_CaptureReference reference
);

#ifdef HAL_PWM_API_QUADRATURE_ENCODER
/**
 * Configures the counter, the channel pair and enables the counter.
 */
void pwmInitialiseQuadratureEncoder(
	PWM_Channel firstChannel, 
	uint8_t pinSwitch, 
	PWM_CaptureEdge captureEdge, 
	PWM_Filter filter
);
#endif // HAL_PWM_API_QUADRATURE_ENCODER


typedef enum {
	PWM_INTERRUPT_FAULT,
	PWM_INTERRUPT_TRIGGER,
	PWM_INTERRUPT_COM,
	PWM_INTERRUPT_UPDATE,
} PWM_CounterInterrupt;

/**
 * Invoked whenever a counter interrupt occurs.
 * IMPORTANT: you MUST define this function in your code, even if you don't use it.
 * 
 * @param counter is the counter which generated the interrupt.
 * @param event is the type of interrupt.
 */
void pwmOnCounterInterrupt(PWM_Counter counter, PWM_CounterInterrupt event);

/**
 * Invoked whenever a channel interrupt occurs.
 * IMPORTANT: you MUST define this function in your code, even if you don't use it.
 * 
 * @param channel is the channel which generated the interrupt.
 * @param counterValue is the content of the channel's CCR register.
 * @param isCountingDown is false if the counter counts up, true if it counts down.
 * 
 * For PWM channels, counterValue and isCountingDown are 0.
 * For Encoder channels, counterValue is 0 and isCountingDown is valid.
 * For Capture channels, counterValue is the time elapsed between
 * 2 consecutive events and isCountingDown is irrelevant.
 */
void pwmOnChannelInterrupt(PWM_Channel channel, uint16_t counterValue, bool isCountingDown);

INTERRUPT(pwmA_isr, PWMA_INTERRUPT);

#if HAL_PWM_CHANNELS > 4
	INTERRUPT(pwmB_isr, PWMB_INTERRUPT);
#endif

#endif // _ENHPWM_HAL_H
