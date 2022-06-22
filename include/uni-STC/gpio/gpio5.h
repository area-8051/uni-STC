/**
 * @file uni-STC/gpio/gpio5.h
 * 
 * Register, bit and macro definitions for GPIO port 5
 */

#ifndef _UNISTC_GPIO_GPIO5_H
#define _UNISTC_GPIO_GPIO5_H

// SFR P5: Port 5
SFR(P5, 0xC8);
SBIT(P5_0, 0xC8, 0);
SBIT(P5_1, 0xC8, 1);
SBIT(P5_2, 0xC8, 2);
SBIT(P5_3, 0xC8, 3);
SBIT(P5_4, 0xC8, 4);
SBIT(P5_5, 0xC8, 5);

// SFR P5M1: Port 5 configuration 1
SFR(P5M1, 0xC9);

// SFR P5M0: Port 5 configuration 0
SFR(P5M0, 0xCA);

#ifdef GPIO_HAS_INT_WK
	// SFR P5INTE: Port 5 interrupt enable register
	SFRX(P5INTE, 0xFD05);

	// SFR P5INTF: Port 5 interrupt flag register
	SFRX(P5INTF, 0xFD15);

	// SFR P5IM0: Port 5 interrupt mode register 0
	SFRX(P5IM0, 0xFD25);

	// SFR P5IM1: Port 5 interrupt mode register 1
	SFRX(P5IM1, 0xFD35);

	// SFR P5WKUE: Port 5 interrupt wake-up enable register
	SFRX(P5WKUE, 0xFD45);
	
	// GPIO port 5 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P5_INTERRUPT 42
	#define P5_VECTOR_ADDR 0x0153
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P5PU: Port 5 pull-up resistor control register
	SFRX(P5PU, 0xFE15);

	// SFR P5NCS: Port 5 Schmidt trigger control register
	SFRX(P5NCS, 0xFE1D);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P5SR: Port 5 slew rate control register
	SFRX(P5SR, 0xFE25);

	// SFR P5DR: Port 5 drive current control register
	SFRX(P5DR, 0xFE2D);

	// SFR P5IE: Port 5 input enable control register
	SFRX(P5IE, 0xFE35);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO5_H
