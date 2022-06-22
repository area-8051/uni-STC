/**
 * @file uni-STC/comparator.h
 * 
 * Register, bit and macro definitions for the comparator.
 */

#ifndef _UNISTC_COMPARATOR_H
#define _UNISTC_COMPARATOR_H

#if MCU_FAMILY == 15 || MCU_FAMILY == 8
	#if MCU_PINS > 8
		#define MCU_HAS_COMPARATOR
	#endif
#endif

#ifdef MCU_HAS_COMPARATOR
	#define MCU_HAS_COMPARATOR_PIE_NIE
	
	#if MCU_FAMILY == 8
		#if MCU_SERIES == 'H'
			#define MCU_HAS_COMPARATOR_EXCFG
		#endif
		
		#if MCU_SERIES == 'A' && defined(MCU_HAS_DMA)
			#define MCU_HAS_COMPARATOR_EXCFG
			#undef MCU_HAS_COMPARATOR_PIE_NIE
		#endif
	#endif
	
	// SFR CMPCR1: Comparator control register 1
	SFR(CMPCR1, 0xE6);
	
	#define M_CMPRES 0x1
	#define P_CMPRES 0
	
	#define M_CMPOE 0x2
	#define P_CMPOE 1
	
	#define M_NIS 0x4
	#define P_NIS 2
	
	#define M_PIS 0x8
	#define P_PIS 3
	
	#define M_CMPIF 0x40
	#define P_CMPIF 6
	
	#define M_CMPEN 0x80
	#define P_CMPEN 7
	
	#ifdef MCU_HAS_COMPARATOR_PIE_NIE
		#define M_NIE 0x10
		#define P_NIE 4
		
		#define M_PIE 0x20
		#define P_PIE 5
	#endif

	// SFR CMPCR2: Comparator control register 2
	SFR(CMPCR2, 0xE7);
	
	#define M_LCDTY 0x3f
	#define P_LCDTY 0
	
	#define M_DISFLT 0x40
	#define P_DISFLT 6
	
	#define M_INVCMPO 0x80
	#define P_INVCMPO 7

	#ifdef MCU_HAS_COMPARATOR_EXCFG
		// SFR CMPEXCFG: Comparator extended configuration register
		SFRX(CMPEXCFG, 0xFEAE);
		
		#define M_CMPPS 0x03
		#define P_CMPPS 0
		
		#define M_CMPNS 0x04
		#define P_CMPNS 2
		
		#define M_CHYS 0xc0
		#define P_CHYS 6
	#endif // MCU_HAS_COMPARATOR_EXCFG

	// Bit mask for use with IP2L and IP2H
	#define M_PCMP 0x20
	#define P_PCMP 5
	
	// Comparator interrupt
	#define CMP_INTERRUPT 21
	#define CMP_VECTOR_ADDR 0x00AB
#endif // MCU_HAS_COMPARATOR

#endif // _UNISTC_COMPARATOR_H
