/**
 * @file uni-STC/i2c.h
 * 
 * Register, bit and macro definitions for I2C.
 */

#ifndef _UNISTC_I2C_H
#define _UNISTC_I2C_H

#if MCU_FAMILY == 8
	#define MCU_HAS_I2C
#endif // MCU_FAMILY == 8

#ifdef MCU_HAS_I2C
	// SFR I2CCFG: I2C configuration register
	SFRX(I2CCFG, 0xFE80);
	
	#define M_MSSPEED 0x3f
	#define P_MSSPEED 0
	
	#define M_MSSL 0x40
	#define P_MSSL 6
	
	#define M_ENI2C 0x80
	#define P_ENI2C 7

	// SFR I2CMSCR: I2C host control register
	SFRX(I2CMSCR, 0xFE81);
	
	#define M_MSCMD 0x0f
	#define P_MSCMD 0
	
	#define M_EMSI 0x80
	#define P_EMSI 7

	// SFR I2CMSST: I2C host state register
	SFRX(I2CMSST, 0xFE82);
	
	#define M_MSACKO 0x01
	#define P_MSACKO 0
	
	#define M_MSACKI 0x02
	#define P_MSACKI 1
	
	#define M_MSIF 0x40
	#define P_MSIF 6
	
	#define M_MSBUSY 0x80
	#define P_MSBUSY 7

	// SFR I2CSLCR: I2C slave control register
	SFRX(I2CSLCR, 0xFE83);
	
	#define M_SLRST 0x1
	#define P_SLRST 0
	
	#define M_ESTOI 0x8
	#define P_ESTOI 3
	
	#define M_ETXI 0x10
	#define P_ETXI 4
	
	#define M_ERXI 0x20
	#define P_ERXI 5
	
	#define M_ESTAI 0x40
	#define P_ESTAI 6

	// SFR I2CSLST: I2C slave state register
	SFRX(I2CSLST, 0xFE84);
	
	#define M_SLACKO 0x01
	#define P_SLACKO 0
	
	#define M_SLACKI 0x02
	#define P_SLACKI 1
	
	#define M_TXING 0x4
	#define P_TXING 2
	
	#define M_STOIF 0x8
	#define P_STOIF 3
	
	// UART also has RXIF and TXIF
	#define M_I2C_TXIF 0x10
	#define P_I2C_TXIF 4
	
	#define M_I2C_RXIF 0x20
	#define P_I2C_RXIF 5
	
	#define M_STAIF 0x40
	#define P_STAIF 6
	
	#define M_SLBUSY 0x80
	#define P_SLBUSY 7

	// SFR I2CSLADR: I2C slave address register
	SFRX(I2CSLADR, 0xFE85);
	
	#define M_MA 0x1
	#define P_MA 0
	
	#define M_SLADR 0xfe
	#define P_SLADR 1

	// SFR I2CTXD: I2C data transmission register
	SFRX(I2CTXD, 0xFE86);

	// SFR I2CRXD: I2C data receiving register
	SFRX(I2CRXD, 0xFE87);

	// SFR I2CMSAUX: I2C host auxiliary control register
	SFRX(I2CMSAUX, 0xFE88);
	
	#define M_WDTA 0x1
	#define P_WDTA 0

	// Bit mask for use with IP2L and IP2H
	#define M_PI2C 0x40
	#define P_PI2C 6
	
	// I2C interrupt
	#define I2C_INTERRUPT 24
	#define I2C_VECTOR_ADDR 0x00C3
#endif // MCU_HAS_I2C

#endif // _UNISTC_I2C_H
