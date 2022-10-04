/**
 * @file uni-STC/gpio/gpio.h
 * 
 * Register, bit and mask definitions related to the GPIO.
 */

#ifndef _UNISTC_GPIO_GPIO_H
#define _UNISTC_GPIO_GPIO_H

/**
 * When using most, but not all, STC8H
 *     The GPIO_HAS_INT_WK macro must be defined.
 */

// All MCU have P3 and P5. Other ports might be available depending 
// on the number of pins.

#if MCU_PINS > 8
	#define GPIO_HAS_P1
#endif // MCU_PINS > 8

#if MCU_PINS >= 28
	#define GPIO_HAS_P2
#endif // MCU_PINS >= 28

#if MCU_PINS >= 32
	#define GPIO_HAS_P0
#endif // MCU_PINS >= 32

#if MCU_PINS >= 40
	#define GPIO_HAS_P4
#endif // MCU_PINS >= 40

#if MCU_PINS >= 64
	#define GPIO_HAS_P6
	#define GPIO_HAS_P7
#endif // MCU_PINS >= 64

// Most STC MCU have P5, not having one is an exception.
#ifndef MCU_HAS_NO_P5
	#define GPIO_HAS_P5
#endif

#if MCU_FAMILY == 8
	#if MCU_SERIES == 'A' || MCU_SERIES == 'F'
		// Internal pull-up resistors & Schmidt-trigger
		#define GPIO_HAS_PU_NCS

		#ifdef STC8A8KxxD4
			// Slew rate control, drive current control, input enable
			#define GPIO_HAS_SR_DR_IE
			// Interrupts & wake-up
			#define GPIO_HAS_INT_WK
		#endif // STC8A8KxxD4
	#endif // MCU_SERIES == 'A'

	#if MCU_SERIES == 'G'
		// Internal pull-up resistors & Schmidt-trigger
		#define GPIO_HAS_PU_NCS
		// Slew rate control, drive current control, input enable
		#define GPIO_HAS_SR_DR_IE
	#endif // MCU_SERIES == 'G'

	#if MCU_SERIES == 'H'
		// Internal pull-up resistors & Schmidt-trigger
		#define GPIO_HAS_PU_NCS
		// Slew rate control, drive current control, input enable
		#define GPIO_HAS_SR_DR_IE
	#endif // MCU_SERIES == 'G'
#endif // MCU_FAMILY == 8

#ifdef GPIO_HAS_P0
	#include <uni-STC/gpio/gpio0.h>
#endif // GPIO_HAS_P0

#ifdef GPIO_HAS_P1
	#include <uni-STC/gpio/gpio1.h>
#endif // GPIO_HAS_P1

#ifdef GPIO_HAS_P2
	#include <uni-STC/gpio/gpio2.h>
#endif // GPIO_HAS_P2

#include <uni-STC/gpio/gpio3.h>

#ifdef GPIO_HAS_P4
	#include <uni-STC/gpio/gpio4.h>
#endif // GPIO_HAS_P4

#ifdef GPIO_HAS_P5
	#include <uni-STC/gpio/gpio5.h>
#endif // GPIO_HAS_P5

#ifdef GPIO_HAS_P6
	#include <uni-STC/gpio/gpio6.h>
#endif // GPIO_HAS_P6

#ifdef GPIO_HAS_P7
	#include <uni-STC/gpio/gpio7.h>
#endif // GPIO_HAS_P7

#ifdef GPIO_HAS_INT_WK
	// SFR PINIPL: I/O port interrupt priority register low
	SFRX(PINIPL, 0xFD60);
	
	#ifdef GPIO_HAS_P0
		#define M_P0IP 0x1
		#define P_P0IP 0
	#endif // GPIO_HAS_P0

	#ifdef GPIO_HAS_P1
		#define M_P1IP 0x2
		#define P_P1IP 1
	#endif // GPIO_HAS_P1

	#ifdef GPIO_HAS_P2
		#define M_P2IP 0x4
		#define P_P2IP 2
	#endif // GPIO_HAS_P2

	#define M_P3IP 0x8
	#define P_P3IP 3

	#ifdef GPIO_HAS_P4
		#define M_P4IP 0x10
		#define P_P4IP 4
	#endif // GPIO_HAS_P4

	#ifdef GPIO_HAS_P5
		#define M_P5IP 0x20
		#define P_P5IP 5
	#endif // GPIO_HAS_P5

	#ifdef GPIO_HAS_P6
		#define M_P6IP 0x40
		#define P_P6IP 6
	#endif // GPIO_HAS_P6

	#ifdef GPIO_HAS_P7
		#define M_P7IP 0x80
		#define P_P7IP 7
	#endif // GPIO_HAS_P7

	// SFR PINIPH: I/O port interrupt priority register high
	SFRX(PINIPH, 0xFD61);
#endif // GPIO_HAS_INT_WK

typedef enum {
	GPIO_BIDIRECTIONAL_MODE = 0,
	GPIO_PUSH_PULL_MODE = 1,
	GPIO_HIGH_IMPEDANCE_MODE = 2,
	GPIO_OPEN_DRAIN_MODE = 3,
} GpioPinMode;

#ifdef GPIO_HAS_SR_DR_IE
	typedef enum {
		GPIO_HIGH_SLEW_RATE = 0,
		GPIO_LOW_SLEW_RATE = 1,
	} GpioSlewRate;

	typedef enum {
		GPIO_ENHANCED_DRIVE = 0,
		GPIO_STANDARD_DRIVE = 1,
	} GpioCurrentDrive;
#endif // GPIO_HAS_SR_DR_IE

#ifdef GPIO_HAS_INT_WK
	typedef enum {
		GPIO_FALLING_EDGE = 0,
		GPIO_RISING_EDGE = 1,
		GPIO_LOW_LEVEL = 2,
		GPIO_HIGH_LEVEL = 3,
	} GpioInterruptTrigger;
#endif // GPIO_HAS_INT_WK

typedef enum {
#ifdef GPIO_HAS_P0
	GPIO_PORT0 = 0,
#endif // GPIO_HAS_P0
#ifdef GPIO_HAS_P1
	GPIO_PORT1 = 1,
#endif // GPIO_HAS_P1
#ifdef GPIO_HAS_P2
	GPIO_PORT2 = 2,
#endif // GPIO_HAS_P2
	GPIO_PORT3 = 3,
#ifdef GPIO_HAS_P4
	GPIO_PORT4 = 4,
#endif // GPIO_HAS_P4
#ifdef GPIO_HAS_P5
	GPIO_PORT5 = 5,
#endif // GPIO_HAS_P5
#ifdef GPIO_HAS_P6
	GPIO_PORT6 = 6,
#endif // GPIO_HAS_P6
#ifdef GPIO_HAS_P7
	GPIO_PORT7 = 7,
#endif // GPIO_HAS_P7
} GpioPort;

typedef enum {
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
} GpioPin;

#endif // _UNISTC_GPIO_GPIO_H
