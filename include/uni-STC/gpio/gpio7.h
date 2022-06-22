/**
 * @file uni-STC/gpio/gpio7.h
 * 
 * Register, bit and macro definitions for GPIO port 7
 */

#ifndef _UNISTC_GPIO_GPIO7_H
#define _UNISTC_GPIO_GPIO7_H

// SFR P7: Port 7
SFR(P7, 0xF8);
SBIT(P7_0, 0xF8, 0);
SBIT(P7_1, 0xF8, 1);
SBIT(P7_2, 0xF8, 2);
SBIT(P7_3, 0xF8, 3);
SBIT(P7_4, 0xF8, 4);
SBIT(P7_5, 0xF8, 5);
SBIT(P7_6, 0xF8, 6);
SBIT(P7_7, 0xF8, 7);

// SFR P7M1: Port 7 configuration 1
SFR(P7M1, 0xE1);

// SFR P7M0: Port 7 configuration 0
SFR(P7M0, 0xE2);

#ifdef GPIO_HAS_INT_WK
	// SFR P7INTE: Port 7 interrupt enable register
	SFRX(P7INTE, 0xFD07);

	// SFR P7INTF: Port 7 interrupt flag register
	SFRX(P7INTF, 0xFD17);

	// SFR P7IM0: Port 7 interrupt mode register 0
	SFRX(P7IM0, 0xFD27);

	// SFR P7IM1: Port 7 interrupt mode register 1
	SFRX(P7IM1, 0xFD37);

	// SFR P7WKUE: Port 7 interrupt wake-up enable register
	SFRX(P7WKUE, 0xFD47);
	
	// GPIO port 7 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P7_INTERRUPT 44
	#define P7_VECTOR_ADDR 0x0163
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P7PU: Port 7 pull-up resistor control register
	SFRX(P7PU, 0xFE17);

	// SFR P7NCS: Port 7 Schmidt trigger control register
	SFRX(P7NCS, 0xFE1F);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P7SR: Port 7 slew rate control register
	SFRX(P7SR, 0xFE27);

	// SFR P7DR: Port 7 drive current control register
	SFRX(P7DR, 0xFE2F);

	// SFR P7IE: Port 7 input enable control register
	SFRX(P7IE, 0xFE37);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO7_H
