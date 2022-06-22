/**
 * @file uni-STC/gpio/gpio3.h
 * 
 * Register, bit and macro definitions for GPIO port 3
 */

#ifndef _UNISTC_GPIO_GPIO3_H
#define _UNISTC_GPIO_GPIO3_H

// SFR P3: Port 3
SFR(P3, 0xB0);
SBIT(P3_0, 0xB0, 0);
SBIT(P3_1, 0xB0, 1);
SBIT(P3_2, 0xB0, 2);
SBIT(P3_3, 0xB0, 3);
SBIT(P3_4, 0xB0, 4);
SBIT(P3_5, 0xB0, 5);
SBIT(P3_6, 0xB0, 6);
SBIT(P3_7, 0xB0, 7);

// SFR P3M1: Port 3 configuration 1
SFR(P3M1, 0xB1);

// SFR P3M0: Port 3 configuration 0
SFR(P3M0, 0xB2);

#ifdef GPIO_HAS_INT_WK
	// SFR P3INTE: Port 3 interrupt enable register
	SFRX(P3INTE, 0xFD03);

	// SFR P3INTF: Port 3 interrupt flag register
	SFRX(P3INTF, 0xFD13);

	// SFR P3IM0: Port 3 interrupt mode register 0
	SFRX(P3IM0, 0xFD23);

	// SFR P3IM1: Port 3 interrupt mode register 1
	SFRX(P3IM1, 0xFD33);

	// SFR P3WKUE: Port 3 interrupt wake-up enable register
	SFRX(P3WKUE, 0xFD43);
	
	// GPIO port 3 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P3_INTERRUPT 40
	#define P3_VECTOR_ADDR 0x0143
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P3PU: Port 3 pull-up resistor control register
	SFRX(P3PU, 0xFE13);

	// SFR P3NCS: Port 3 Schmidt trigger control register
	SFRX(P3NCS, 0xFE1B);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P3SR: Port 3 slew rate control register
	SFRX(P3SR, 0xFE23);

	// SFR P3DR: Port 3 drive current control register
	SFRX(P3DR, 0xFE2B);

	// SFR P3IE: Port 3 input enable control register
	SFRX(P3IE, 0xFE33);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO3_H
