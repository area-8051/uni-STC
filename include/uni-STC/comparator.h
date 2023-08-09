/**
 * @file uni-STC/comparator.h
 * 
 * Register, bit and macro definitions for the comparator.
 */

#ifndef _UNISTC_COMPARATOR_H
#define _UNISTC_COMPARATOR_H

#ifdef MCU_HAS_COMPARATOR
	// COMPARATOR_1P2N => STC15 without ADC
	// COMPARATOR_4P2N => new comparator in some STC8H + the STC8A8KxxD4
	// COMPARATOR_2P2N => STC15 with ADC and all other STC8
	// nP means n possible sources for the positive input of the comparator.
	// nN means n possible sources for the negative input of the comparator.
	// 1P2N can't select ADCIN because they have no ADC.
	
	#if !defined(COMPARATOR_1P2N) && !defined(COMPARATOR_4P2N)
		#define COMPARATOR_2P2N
	#endif // !defined(COMPARATOR_1P2N) && !defined(COMPARATOR_4P2N)
	
	// SFR CMPCR1: Comparator control register 1
	SFR(CMPCR1, 0xE6);
	
	#define M_CMPRES 0x1
	#define P_CMPRES 0
	
	#define M_CMPOE 0x2
	#define P_CMPOE 1
	
	#ifndef COMPARATOR_4P2N
		#define M_NIS 0x4
		#define P_NIS 2
		
		#define M_PIS 0x8
		#define P_PIS 3
	#endif // COMPARATOR_4P2N
	
	// Interrupt flag
	#define M_CMPIF 0x40
	#define P_CMPIF 6
	
	// Peripheral enable
	#define M_ENCMP 0x80
	#define P_ENCMP 7
	
	// Rising edge interrupt enable
	#define M_CMPNIE 0x10
	#define P_CMPNIE 4
	
	// Falling edge interrupt enable
	#define M_CMPPIE 0x20
	#define P_CMPPIE 5

	// SFR CMPCR2: Comparator control register 2
	SFR(CMPCR2, 0xE7);
	
	#define M_LCDTY 0x3f
	#define P_LCDTY 0
	
	#define M_DISFLT 0x40
	#define P_DISFLT 6
	
	#define M_INVCMPO 0x80
	#define P_INVCMPO 7

	#ifdef COMPARATOR_4P2N
		// SFR CMPEXCFG: Comparator extended configuration register
		SFRX(CMPEXCFG, 0xFEAE);
		
		#define M_CMPPS 0x03
		#define P_CMPPS 0
		
		#define M_CMPNS 0x04
		#define P_CMPNS 2
		
		#define M_CHYS 0xc0
		#define P_CHYS 6
	#endif // COMPARATOR_4P2N

	// Bit mask for use with IP2L and IP2H
	#define M_CMPPR 0x20
	#define P_CMPPR 5
	
	// Comparator interrupt
	#define CMP_INTERRUPT 21
	#define CMP_VECTOR_ADDR 0x00AB
#endif // MCU_HAS_COMPARATOR

#endif // _UNISTC_COMPARATOR_H
