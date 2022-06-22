/**
 * @file uni-STC/touchkey.h
 * 
 * Register, bit and macro definitions for the LCD controller.
 */

#ifndef _UNISTC_TOUCHKEY_H
#define _UNISTC_TOUCHKEY_H

#ifdef MCU_HAS_TOUCHKEY
	// SFR TSCHEN1: Touch key enable register 1
	SFRX(TSCHEN1, 0xFB40);
	
	#define M_TKEN0 0x1
	#define P_TKEN0 0
	
	#define M_TKEN1 0x2
	#define P_TKEN1 1
	
	#define M_TKEN2 0x4
	#define P_TKEN2 2
	
	#define M_TKEN3 0x8
	#define P_TKEN3 3
	
	#define M_TKEN4 0x10
	#define P_TKEN4 4
	
	#define M_TKEN5 0x20
	#define P_TKEN5 5
	
	#define M_TKEN6 0x40
	#define P_TKEN6 6
	
	#define M_TKEN7 0x80
	#define P_TKEN7 7

	// SFR TSCHEN2: Touch key enable register 2
	SFRX(TSCHEN2, 0xFB41);
	
	#define M_TKEN8 0x1
	#define P_TKEN8 0
	
	#define M_TKEN9 0x2
	#define P_TKEN9 1
	
	#define M_TKEN10 0x4
	#define P_TKEN10 2
	
	#define M_TKEN11 0x8
	#define P_TKEN11 3
	
	#define M_TKEN12 0x10
	#define P_TKEN12 4
	
	#define M_TKEN13 0x20
	#define P_TKEN13 5
	
	#define M_TKEN14 0x40
	#define P_TKEN14 6
	
	#define M_TKEN15 0x80
	#define P_TKEN15 7

	// SFR TSCFG1: Touch key configuration register 1
	SFRX(TSCFG1, 0xFB42);
	
	#define M_DT0 0x07
	#define P_DT0 0
	
	#define M_SCR 0x70
	#define P_SCR 4

	// SFR TSCFG2: Touch key configuration register 2
	SFRX(TSCFG2, 0xFB43);
	
	#define M_TSVR 0x03
	#define P_TSVR 0

	// SFR TSWUTC: Touch key wake-up control register
	SFRX(TSWUTC, 0xFB44);

	// SFR TSCTRL: Touch key control register
	SFRX(TSCTRL, 0xFB45);
	
	#define M_TSSAMP 0x03
	#define P_TSSAMP 0
	
	#define M_TSWUEN 0x4
	#define P_TSWUEN 2
	
	#define M_TSDCEN 0x8
	#define P_TSDCEN 3
	
	#define M_TSWUCS 0x10
	#define P_TSWUCS 4
	
	#define M_TSWAIT 0x20
	#define P_TSWAIT 5
	
	#define M_SINGLE 0x40
	#define P_SINGLE 6
	
	#define M_TSGO 0x80
	#define P_TSGO 7

	// SFR TSSTA1: Touch key status register 1
	SFRX(TSSTA1, 0xFB46);
	
	#define M_TSWKCHN 0x0f
	#define P_TSWKCHN 0
	
	#define M_LEDWK 0x80
	#define P_LEDWK 7

	// SFR TSSTA2: Touch key status register 2
	SFRX(TSSTA2, 0xFB47);
	
	#define M_TSDNCHN 0x0f
	#define P_TSDNCHN 0
	
	#define M_TSDOV 0x40
	#define P_TSDOV 6
	
	#define M_TSIF 0x80
	#define P_TSIF 7

	// SFR TSRT: Touch key time control register
	SFRX(TSRT, 0xFB48);

	// SFR TSDATH: Touch key data high
	SFRX(TSDATH, 0xFB49);
	// SFR TSDATL: Touch key data low
	SFRX(TSDATL, 0xFB4A);

	// SFR TSTH00H: Touch key 0 threshold high
	SFRX(TSTH00H, 0xFB50);
	// SFR TSTH00L: Touch key 0 threshold low
	SFRX(TSTH00L, 0xFB51);

	// SFR TSTH01H: Touch key 1 threshold high
	SFRX(TSTH01H, 0xFB52);
	// SFR TSTH01L: Touch key 1 threshold low
	SFRX(TSTH01L, 0xFB53);

	// SFR TSTH02H: Touch key 2 threshold high
	SFRX(TSTH02H, 0xFB54);
	// SFR TSTH02L: Touch key 2 threshold low
	SFRX(TSTH02L, 0xFB55);

	// SFR TSTH03H: Touch key 3 threshold high
	SFRX(TSTH03H, 0xFB56);
	// SFR TSTH03L: Touch key 3 threshold low
	SFRX(TSTH03L, 0xFB57);

	// SFR TSTH04H: Touch key 4 threshold high
	SFRX(TSTH04H, 0xFB58);
	// SFR TSTH04L: Touch key 4 threshold low
	SFRX(TSTH04L, 0xFB59);

	// SFR TSTH05H: Touch key 5 threshold high
	SFRX(TSTH05H, 0xFB5A);
	// SFR TSTH05L: Touch key 5 threshold low
	SFRX(TSTH05L, 0xFB5B);

	// SFR TSTH06H: Touch key 6 threshold high
	SFRX(TSTH06H, 0xFB5C);
	// SFR TSTH06L: Touch key 6 threshold low
	SFRX(TSTH06L, 0xFB5D);

	// SFR TSTH07H: Touch key 7 threshold high
	SFRX(TSTH07H, 0xFB5E);
	// SFR TSTH07L: Touch key 7 threshold low
	SFRX(TSTH07L, 0xFB5F);

	// SFR TSTH08H: Touch key 8 threshold high
	SFRX(TSTH08H, 0xFB60);
	// SFR TSTH08L: Touch key 8 threshold low
	SFRX(TSTH08L, 0xFB61);

	// SFR TSTH09H: Touch key 9 threshold high
	SFRX(TSTH09H, 0xFB62);
	// SFR TSTH09L: Touch key 9 threshold low
	SFRX(TSTH09L, 0xFB63);

	// SFR TSTH10H: Touch key 10 threshold high
	SFRX(TSTH10H, 0xFB64);
	// SFR TSTH10L: Touch key 10 threshold low
	SFRX(TSTH10L, 0xFB65);

	// SFR TSTH11H: Touch key 11 threshold high
	SFRX(TSTH11H, 0xFB66);
	// SFR TSTH11L: Touch key 11 threshold low
	SFRX(TSTH11L, 0xFB67);

	// SFR TSTH12H: Touch key 12 threshold high
	SFRX(TSTH12H, 0xFB68);
	// SFR TSTH12L: Touch key 12 threshold low
	SFRX(TSTH12L, 0xFB69);

	// SFR TSTH13H: Touch key 13 threshold high
	SFRX(TSTH13H, 0xFB6A);
	// SFR TSTH13L: Touch key 13 threshold low
	SFRX(TSTH13L, 0xFB6B);

	// SFR TSTH14H: Touch key 14 threshold high
	SFRX(TSTH14H, 0xFB6C);
	// SFR TSTH14L: Touch key 14 threshold low
	SFRX(TSTH14L, 0xFB6D);

	// SFR TSTH15H: Touch key 15 threshold high
	SFRX(TSTH15H, 0xFB6E);
	// SFR TSTH15L: Touch key 15 threshold low
	SFRX(TSTH15L, 0xFB6F);

	// Touch key interrupt (usage in C => see STC8H TRM appendix R)
	#define TKSU_INTERRUPT 35
	#define TKSU_VECTOR_ADDR 0x011B
#endif // MCU_HAS_TOUCHKEY

#endif // _UNISTC_TOUCHKEY_H
