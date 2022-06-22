/**
 * @file uni-STC/gpio/gpio6.h
 * 
 * Register, bit and macro definitions for GPIO port 6
 */

#ifndef _UNISTC_GPIO_GPIO6_H
#define _UNISTC_GPIO_GPIO6_H

// SFR P6: Port 6
SFR(P6, 0xE8);
SBIT(P6_0, 0xE8, 0);
SBIT(P6_1, 0xE8, 1);
SBIT(P6_2, 0xE8, 2);
SBIT(P6_3, 0xE8, 3);
SBIT(P6_4, 0xE8, 4);
SBIT(P6_5, 0xE8, 5);
SBIT(P6_6, 0xE8, 6);
SBIT(P6_7, 0xE8, 7);

// SFR P6M1: Port 6 configuration 1
SFR(P6M1, 0xCB);

// SFR P6M0: Port 6 configuration 0
SFR(P6M0, 0xCC);

#ifdef GPIO_HAS_INT_WK
	// SFR P6INTE: Port 6 interrupt enable register
	SFRX(P6INTE, 0xFD06);

	// SFR P6INTF: Port 6 interrupt flag register
	SFRX(P6INTF, 0xFD16);

	// SFR P6IM0: Port 6 interrupt mode register 0
	SFRX(P6IM0, 0xFD26);

	// SFR P6IM1: Port 6 interrupt mode register 1
	SFRX(P6IM1, 0xFD36);

	// SFR P6WKUE: Port 6 interrupt wake-up enable register
	SFRX(P6WKUE, 0xFD46);
	
	// GPIO port 6 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P6_INTERRUPT 43
	#define P6_VECTOR_ADDR 0x015B
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P6PU: Port 6 pull-up resistor control register
	SFRX(P6PU, 0xFE16);

	// SFR P6NCS: Port 6 Schmidt trigger control register
	SFRX(P6NCS, 0xFE1E);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P6SR: Port 6 slew rate control register
	SFRX(P6SR, 0xFE26);

	// SFR P6DR: Port 6 drive current control register
	SFRX(P6DR, 0xFE2E);

	// SFR P6IE: Port 6 input enable control register
	SFRX(P6IE, 0xFE36);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO6_H
