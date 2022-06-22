/**
 * @file uni-STC/led.h
 * 
 * Register, bit and macro definitions for the LED controller.
 */

#ifndef _UNISTC_LED_H
#define _UNISTC_LED_H

#ifdef MCU_HAS_LED
	// SFR COMEN: COM enable register
	SFRX(COMEN, 0xFB00);
	
	#define M_C0EN 0x1
	#define P_C0EN 0
	
	#define M_C1EN 0x2
	#define P_C1EN 1
	
	#define M_C2EN 0x4
	#define P_C2EN 2
	
	#define M_C3EN 0x8
	#define P_C3EN 3
	
	#define M_C4EN 0x10
	#define P_C4EN 4
	
	#define M_C5EN 0x20
	#define P_C5EN 5
	
	#define M_C6EN 0x40
	#define P_C6EN 6
	
	#define M_C7EN 0x80
	#define P_C7EN 7

	// SFR SEGENL: SEG enable register low
	SFRX(SEGENL, 0xFB01);
	
	#define M_S0EN 0x1
	#define P_S0EN 0
	
	#define M_S1EN 0x2
	#define P_S1EN 1
	
	#define M_S2EN 0x4
	#define P_S2EN 2
	
	#define M_S3EN 0x8
	#define P_S3EN 3
	
	#define M_S4EN 0x10
	#define P_S4EN 4
	
	#define M_S5EN 0x20
	#define P_S5EN 5
	
	#define M_S6EN 0x40
	#define P_S6EN 6
	
	#define M_S7EN 0x80
	#define P_S7EN 7

	// SFR SEGENH: SEG enable register high
	SFRX(SEGENH, 0xFB02);
	
	#define M_S8EN 0x1
	#define P_S8EN 0
	
	#define M_S9EN 0x2
	#define P_S9EN 1
	
	#define M_S10EN 0x4
	#define P_S10EN 2
	
	#define M_S11EN 0x8
	#define P_S11EN 3
	
	#define M_S12EN 0x10
	#define P_S12EN 4
	
	#define M_S13EN 0x20
	#define P_S13EN 5
	
	#define M_S14EN 0x40
	#define P_S14EN 6
	
	#define M_S15EN 0x80
	#define P_S15EN 7

	// SFR LEDCTRL: LED control register
	SFRX(LEDCTRL, 0xFB03);
	
	#define M_LEDDUTY 0x07
	#define P_LEDDUTY 0
	#define M_LEDMODE 0x38
	#define P_LEDMODE 3
	#define M_LEDON 0x80
	#define P_LEDON 7

	// SFR LEDCKS: LED clock divide register
	SFRX(LEDCKS, 0xFB04);
	

	// SFR COM0_DA_L: Common anode mode display low
	SFRX(COM0_DA_L, 0xFB10);
	// SFR COM0_DA_H: Common anode mode display high
	SFRX(COM0_DA_H, 0xFB18);

	// SFR COM1_DA_L: Common anode mode display low
	SFRX(COM1_DA_L, 0xFB11);
	// SFR COM1_DA_H: Common anode mode display high
	SFRX(COM1_DA_H, 0xFB19);

	// SFR COM2_DA_L: Common anode mode display low
	SFRX(COM2_DA_L, 0xFB12);
	// SFR COM2_DA_H: Common anode mode display high
	SFRX(COM2_DA_H, 0xFB1A);

	// SFR COM3_DA_L: Common anode mode display low
	SFRX(COM3_DA_L, 0xFB13);
	// SFR COM3_DA_H: Common anode mode display high
	SFRX(COM3_DA_H, 0xFB1B);

	// SFR COM4_DA_L: Common anode mode display low
	SFRX(COM4_DA_L, 0xFB14);
	// SFR COM4_DA_H: Common anode mode display high
	SFRX(COM4_DA_H, 0xFB1C);

	// SFR COM5_DA_L: Common anode mode display low
	SFRX(COM5_DA_L, 0xFB15);
	// SFR COM5_DA_H: Common anode mode display high
	SFRX(COM5_DA_H, 0xFB1D);

	// SFR COM6_DA_L: Common anode mode display low
	SFRX(COM6_DA_L, 0xFB16);
	// SFR COM6_DA_H: Common anode mode display high
	SFRX(COM6_DA_H, 0xFB1E);

	// SFR COM7_DA_L: Common anode mode display low
	SFRX(COM7_DA_L, 0xFB17);
	// SFR COM7_DA_H: Common anode mode display high
	SFRX(COM7_DA_H, 0xFB1F);


	// SFR COM0_DC_L: Common cathode mode display low
	SFRX(COM0_DC_L, 0xFB20);
	// SFR COM0_DC_H: Common cathode mode display high
	SFRX(COM0_DC_H, 0xFB28);

	// SFR COM1_DC_L: Common cathode mode display low
	SFRX(COM1_DC_L, 0xFB21);
	// SFR COM1_DC_H: Common cathode mode display high
	SFRX(COM1_DC_H, 0xFB29);

	// SFR COM2_DC_L: Common cathode mode display low
	SFRX(COM2_DC_L, 0xFB22);
	// SFR COM2_DC_H: Common cathode mode display high
	SFRX(COM2_DC_H, 0xFB2A);

	// SFR COM3_DC_L: Common cathode mode display low
	SFRX(COM3_DC_L, 0xFB23);
	// SFR COM3_DC_H: Common cathode mode display high
	SFRX(COM3_DC_H, 0xFB2B);

	// SFR COM4_DC_L: Common cathode mode display low
	SFRX(COM4_DC_L, 0xFB24);
	// SFR COM4_DC_H: Common cathode mode display high
	SFRX(COM4_DC_H, 0xFB2C);

	// SFR COM5_DC_L: Common cathode mode display low
	SFRX(COM5_DC_L, 0xFB25);
	// SFR COM5_DC_H: Common cathode mode display high
	SFRX(COM5_DC_H, 0xFB2D);

	// SFR COM6_DC_L: Common cathode mode display low
	SFRX(COM6_DC_L, 0xFB26);
	// SFR COM6_DC_H: Common cathode mode display high
	SFRX(COM6_DC_H, 0xFB2E);

	// SFR COM7_DC_L: Common cathode mode display low
	SFRX(COM7_DC_L, 0xFB27);
	// SFR COM7_DC_H: Common cathode mode display high
	SFRX(COM7_DC_H, 0xFB2F);
#endif // MCU_HAS_LED

#endif // _UNISTC_LED_H
