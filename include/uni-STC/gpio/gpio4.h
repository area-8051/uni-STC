/**
 * @file uni-STC/gpio/gpio4.h
 * 
 * Register, bit and macro definitions for GPIO port 4
 */

#ifndef _UNISTC_GPIO_GPIO4_H
#define _UNISTC_GPIO_GPIO4_H

// SFR P4: Port 4
SFR(P4, 0xC0);
SBIT(P4_0, 0xC0, 0);
SBIT(P4_1, 0xC0, 1);
SBIT(P4_2, 0xC0, 2);
SBIT(P4_3, 0xC0, 3);
SBIT(P4_4, 0xC0, 4);
SBIT(P4_5, 0xC0, 5);
SBIT(P4_6, 0xC0, 6);
SBIT(P4_7, 0xC0, 7);

// SFR P4M1: Port 4 configuration 1
SFR(P4M1, 0xB3);

// SFR P4M0: Port 4 configuration 0
SFR(P4M0, 0xB4);

#ifdef GPIO_HAS_INT_WK
	// SFR P4INTE: Port 4 interrupt enable register
	SFRX(P4INTE, 0xFD04);

	// SFR P4INTF: Port 4 interrupt flag register
	SFRX(P4INTF, 0xFD14);

	// SFR P4IM0: Port 4 interrupt mode register 0
	SFRX(P4IM0, 0xFD24);

	// SFR P4IM1: Port 4 interrupt mode register 1
	SFRX(P4IM1, 0xFD34);

	// SFR P4WKUE: Port 4 interrupt wake-up enable register
	SFRX(P4WKUE, 0xFD44);
	
	// GPIO port 4 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P4_INTERRUPT 41
	#define P4_VECTOR_ADDR 0x014B
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P4PU: Port 4 pull-up resistor control register
	SFRX(P4PU, 0xFE14);

	// SFR P4NCS: Port 4 Schmidt trigger control register
	SFRX(P4NCS, 0xFE1C);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P4SR: Port 4 slew rate control register
	SFRX(P4SR, 0xFE24);

	// SFR P4DR: Port 4 drive current control register
	SFRX(P4DR, 0xFE2C);

	// SFR P4IE: Port 4 input enable control register
	SFRX(P4IE, 0xFE34);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO4_H
