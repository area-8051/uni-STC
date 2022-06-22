/**
 * @file uni-STC/lcd.h
 * 
 * Register, bit and macro definitions for the LCD controller.
 */

#ifndef _UNISTC_LCD_H
#define _UNISTC_LCD_H

#ifdef MCU_HAS_LCD
	// SFR LCDCFG1: LCD configuration register
	SFRX(LCDCFG1, 0xFB80);
	
	#define M_VLCDSEL 0x07
	#define P_VLCDSEL 0
	
	#define M_VRLPSEL 0x8
	#define P_VRLPSEL 3
	
	#define M_CKSEL 0x80
	#define P_CKSEL 7

	// SFR LCDCFG2: LCD configuration register 2
	SFRX(LCDCFG2, 0xFB81);
	
	#define M_SEG0PS 0x1
	#define P_SEG0PS 0
	
	#define M_SEG1PS 0x2
	#define P_SEG1PS 1
	
	#define M_SEG2PS 0x4
	#define P_SEG2PS 2
	
	#define M_SEG3PS 0x8
	#define P_SEG3PS 3

	// SFR DBLEN: Dead time length configuration
	SFRX(DBLEN, 0xFB82);

	// SFR COMLENL: COM time length configuration low
	SFRX(COMLENL, 0xFB83);
	// SFR COMLENM: COM time length configuration median
	SFRX(COMLENM, 0xFB84);
	// SFR COMLENH: COM time length configuration high
	SFRX(COMLENH, 0xFB85);

	// SFR BLINKRATE: Flicker rate configuration register
	SFRX(BLINKRATE, 0xFB86);

	// SFR LCDCR: LCD control register
	SFRX(LCDCR, 0xFB87);
	
	#define M_ENLCD 0x1
	#define P_ENLCD 0
	
	#define M_ACTMODE 0x06
	#define P_ACTMODE 1

	// SFR COMON: COM line enable register
	SFRX(COMON, 0xFB88);
	
	#define M_COM0 0x1
	#define P_COM0 0
	
	#define M_COM1 0x2
	#define P_COM1 1
	
	#define M_COM2 0x4
	#define P_COM2 2
	
	#define M_COM3 0x8
	#define P_COM3 3

	// SFR SEGON1: SEG line enable register 1
	SFRX(SEGON1, 0xFB8A);
	
	#define M_SEG0 0x1
	#define P_SEG0 0
	
	#define M_SEG1 0x2
	#define P_SEG1 1
	
	#define M_SEG2 0x4
	#define P_SEG2 2
	
	#define M_SEG3 0x8
	#define P_SEG3 3
	
	#define M_SEG4 0x10
	#define P_SEG4 4
	
	#define M_SEG5 0x20
	#define P_SEG5 5
	
	#define M_SEG6 0x40
	#define P_SEG6 6
	
	#define M_SEG7 0x80
	#define P_SEG7 7

	// SFR SEGON2: SEG line enable register 2
	SFRX(SEGON2, 0xFB8B);
	
	#define M_SEG8 0x1
	#define P_SEG8 0
	
	#define M_SEG9 0x2
	#define P_SEG9 1
	
	#define M_SEG10 0x4
	#define P_SEG10 2
	
	#define M_SEG11 0x8
	#define P_SEG11 3
	
	#define M_SEG12 0x10
	#define P_SEG12 4
	
	#define M_SEG13 0x20
	#define P_SEG13 5
	
	#define M_SEG14 0x40
	#define P_SEG14 6
	
	#define M_SEG15 0x80
	#define P_SEG15 7

	// SFR SEGON3: SEG line enable register 3
	SFRX(SEGON3, 0xFB8C);
	
	#define M_SEG16 0x1
	#define P_SEG16 0
	
	#define M_SEG17 0x2
	#define P_SEG17 1
	
	#define M_SEG18 0x4
	#define P_SEG18 2
	
	#define M_SEG19 0x8
	#define P_SEG19 3
	
	#define M_SEG20 0x10
	#define P_SEG20 4
	
	#define M_SEG21 0x20
	#define P_SEG21 5
	
	#define M_SEG22 0x40
	#define P_SEG22 6
	
	#define M_SEG23 0x80
	#define P_SEG23 7

	// SFR SEGON4: SEG line enable register 4
	SFRX(SEGON4, 0xFB8D);
	
	#define M_SEG24 0x1
	#define P_SEG24 0
	
	#define M_SEG25 0x2
	#define P_SEG25 1
	
	#define M_SEG26 0x4
	#define P_SEG26 2
	
	#define M_SEG27 0x8
	#define P_SEG27 3
	
	#define M_SEG28 0x10
	#define P_SEG28 4
	
	#define M_SEG29 0x20
	#define P_SEG29 5
	
	#define M_SEG30 0x40
	#define P_SEG30 6
	
	#define M_SEG31 0x80
	#define P_SEG31 7

	// SFR SEGON5: SEG line enable register 5
	SFRX(SEGON5, 0xFB8E);
	
	#define M_SEG32 0x1
	#define P_SEG32 0
	
	#define M_SEG33 0x2
	#define P_SEG33 1
	
	#define M_SEG34 0x4
	#define P_SEG34 2
	
	#define M_SEG35 0x8
	#define P_SEG35 3
	
	#define M_SEG36 0x10
	#define P_SEG36 4
	
	#define M_SEG37 0x20
	#define P_SEG37 5
	
	#define M_SEG38 0x40
	#define P_SEG38 6
	
	#define M_SEG39 0x80
	#define P_SEG39 7

	// SFR C0SEGV0: C0SEG 7..0 data register
	SFRX(C0SEGV0, 0xFB90);
	// SFR C0SEGV1: C0SEG 15..8 data register
	SFRX(C0SEGV1, 0xFB91);
	// SFR C0SEGV2: C0SEG 23..16 data register
	SFRX(C0SEGV2, 0xFB92);
	// SFR C0SEGV3: C0SEG 31..24 data register
	SFRX(C0SEGV3, 0xFB93);
	// SFR C0SEGV4: C0SEG 39..32 data register

	// SFR C1SEGV0: C1SEG 7..0 data register
	SFRX(C1SEGV0, 0xFB98);
	// SFR C1SEGV1: C1SEG 15..8 data register
	SFRX(C1SEGV1, 0xFB99);
	// SFR C1SEGV2: C1SEG 23..16 data register
	SFRX(C1SEGV2, 0xFB9A);
	// SFR C1SEGV3: C1SEG 31..24 data register
	SFRX(C1SEGV3, 0xFB9B);
	// SFR C1SEGV4: C1SEG 39..32 data register
	SFRX(C1SEGV4, 0xFB9C);
	
	// SFR C2SEGV0: C2SEG 7..0 data register
	SFRX(C2SEGV0, 0xFBA0);
	// SFR C2SEGV1: C2SEG 15..8 data register
	SFRX(C2SEGV1, 0xFBA1);
	// SFR C2SEGV2: C2SEG 23..16 data register
	SFRX(C2SEGV2, 0xFBA2);
	// SFR C2SEGV3: C2SEG 31..24 data register
	SFRX(C2SEGV3, 0xFBA3);
	// SFR C2SEGV4: C2SEG 39..32 data register
	SFRX(C2SEGV4, 0xFBA4);
	
	// SFR C3SEGV0: C3SEG 7..0 data register
	SFRX(C3SEGV0, 0xFBA8);
	// SFR C3SEGV1: C3SEG 15..8 data register
	SFRX(C3SEGV1, 0xFBA9);
	// SFR C3SEGV2: C3SEG 23..16 data register
	SFRX(C3SEGV2, 0xFBAA);
	// SFR C3SEGV3: C3SEG 31..24 data register
	SFRX(C3SEGV3, 0xFBAB);
	// SFR C3SEGV4: C3SEG 39..32 data register
	SFRX(C3SEGV4, 0xFBAC);
#endif // MCU_HAS_LCD

#endif // _UNISTC_LCD_H
