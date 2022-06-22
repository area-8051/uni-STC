/**
 * @file uni-STC/dptr.h
 * 
 * Register, bit and macro definitions
 */

#ifndef _UNISTC_DPTR_H
#define _UNISTC_DPTR_H

// SFR DPL: Data pointer (DPTR) low
SFR(DPL, 0x82);
// SFR DPH: Data pointer (DPTR) high
SFR(DPH, 0x83);

#if MCU_FAMILY == 8
	#define MCU_HAS_DUAL_DPTR
#endif // MCU_FAMILY == 8

#ifdef MCU_HAS_DUAL_DPTR
	#if MCU_FAMILY == 12 || MCU_FAMILY == 15
		// SFR DPS: alias of P_SW1
		// To support dual-DPTR, SDCC requires a DPS SFR to be defined,
		// hence the alias.
		SFR(DPS, 0xA2);
		
		#define M_DPSEL 0x1
		#define P_DPSEL 0
	#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15

	#if MCU_FAMILY == 8
		// SFR DPS: Data Pointer selector
		SFR(DPS, 0xE3);
		
		#define M_DPSEL 0x1
		#define P_DPSEL 0
		
		#define M_AU 0x18
		#define P_AU 3
		
		#define M_TSL 0x20
		#define P_TSL 5
		
		#define M_ID 0xc0
		#define P_ID 6

		// SFR DPL1: Second data pointer low
		SFR(DPL1, 0xE4);
		// SFR DPH1: Second data pointer high
		SFR(DPH1, 0xE5);
		
		// SFR TA: DPTR timing control register
		SFR(TA, 0xAE);
	#endif // MCU_FAMILY == 8
#endif // MCU_HAS_DUAL_DPTR

#endif // _UNISTC_DPTR_H
