/**
 * @file uni-STC/iap.h
 * 
 * Register, bit and macro definitions
 */

#ifndef _UNISTC_IAP_H
#define _UNISTC_IAP_H

#if MCU_FAMILY == 8
	#if MCU_SERIES == 'G'
		#define MCU_HAS_IAP_TPS
	#elif MCU_SERIES == 'H'
		#define MCU_HAS_IAP_TPS
	#elif defined(STC8A8KxxD4)
		#define MCU_HAS_IAP_TPS
	#endif
#endif // MCU_FAMILY == 8

#if MCU_FAMILY == 90
	// SFR IAP_DATA: ISP/IAP flash data register
	SFR(IAP_DATA, 0xE2);

	// SFR IAP_ADDRH: ISP/IAP flash address high
	SFR(IAP_ADDRH, 0xE3);
	// SFR IAP_ADDRL: ISP/IAP flash address low
	SFR(IAP_ADDRL, 0xE4);

	// IAP_ADDR as an int
	SFR16E(IAP_ADDR, 0xE3E4);

	// SFR IAP_CMD: ISP/IAP flash command register
	SFR(IAP_CMD, 0xE5);
	#define M_CMD 0x07

	// SFR IAP_TRIG: ISP/IAP flash trigger register
	SFR(IAP_TRIG, 0xE6);

	// SFR IAP_CONTR: ISP/IAP flash control register
	SFR(IAP_CONTR, 0xE7);
#else
	// SFR IAP_DATA: ISP/IAP flash data register
	SFR(IAP_DATA, 0xC2);

	// SFR IAP_ADDRH: ISP/IAP flash address high
	SFR(IAP_ADDRH, 0xC3);
	// SFR IAP_ADDRL: ISP/IAP flash address low
	SFR(IAP_ADDRL, 0xC4);

	// IAP_ADDR as an int
	SFR16E(IAP_ADDR, 0xC3C4);

	// SFR IAP_CMD: ISP/IAP flash command register
	SFR(IAP_CMD, 0xC5);
	#define M_CMD 0x03

	// SFR IAP_TRIG: ISP/IAP flash trigger register
	SFR(IAP_TRIG, 0xC6);

	// SFR IAP_CONTR: ISP/IAP flash control register
	SFR(IAP_CONTR, 0xC7);
#endif // MCU_FAMILY == 90

#define M_CMD_FAIL 0x10
#define P_CMD_FAIL 4

#define M_SWRST 0x20
#define P_SWRST 5

#define M_SWBS 0x40
#define P_SWBS 6

#define M_IAPEN 0x80
#define P_IAPEN 7

#ifdef MCU_HAS_IAP_TPS
	// SFR IAP_TPS: IAP Waiting Time Control Register
	SFR(IAP_TPS, 0xF5);
#else
	// For use with IAP_CONTR
	#define M_IAP_WT 0x07
	#define P_IAP_WT 0
#endif // MCU_HAS_IAP_TPS

#endif // _UNISTC_IAP_H
