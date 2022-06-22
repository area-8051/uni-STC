/**
 * @file uni-STC/mdu.h
 * 
 * Register, bit and macro definitions for the Multiply-Divide Unit.
 */

#ifndef _UNISTC_MDU_H
#define _UNISTC_MDU_H

#ifdef MCU_HAS_MDU
	// SFR MD3: MDU data register
	SFRX(MD3, 0xFCF0);
	// SFR MD2: MDU data register
	SFRX(MD2, 0xFCF1);
	// SFR MD1: MDU data register
	SFRX(MD1, 0xFCF2);
	// SFR MD0: MDU data register
	SFRX(MD0, 0xFCF3);
	// SFR MD5: MDU data register
	SFRX(MD5, 0xFCF4);
	// SFR MD4: MDU data register
	SFRX(MD4, 0xFCF5);

	// SFR ARCON: MDU mode control register
	SFRX(ARCON, 0xFCF6);
	
	#define M_SC 0x1f
	#define P_SC 0
	
	#define M_MODE 0xe0
	#define P_MODE 5

	// SFR OPCON: MDU operation control register
	SFRX(OPCON, 0xFCF7);
	
	#define M_ENOP 0x1
	#define P_ENOP 0
	
	#define M_RST 0x2
	#define P_RST 1
	
	#define M_MDOV 0x40
	#define P_MDOV 6
#endif // MCU_HAS_MDU

#endif // _UNISTC_MDU_H
