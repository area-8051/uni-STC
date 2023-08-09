/**
 * @file uni-STC/rtc.h
 * 
 * Register, bit and macro definitions for the Real-Time Clock.
 */

#ifndef _UNISTC_RTC_H
#define _UNISTC_RTC_H

#ifdef MCU_HAS_RTC
	// SFR RTCCR: RTC control register
	SFRX(RTCCR, 0xFE60);
	
	// Called RUNRTC in the documentation
	#define M_RTCRUN 0x1
	#define P_RTCRUN 0

	// SFR RTCCFG: RTC configuration register
	SFRX(RTCCFG, 0xFE61);
	
	// Called SETRTC in the documentation
	#define M_RTCSET 0x1
	#define P_RTCSET 0
	
	#define M_RTCCKS 0x2
	#define P_RTCCKS 1

	// SFR RTCIEN: RTC interrupt enable register
	SFRX(RTCIEN, 0xFE62);
	
	#define M_SEC32IE 0x1
	#define P_SEC32IE 0
	
	#define M_SEC8IE 0x2
	#define P_SEC8IE 1
	
	#define M_SEC2IE 0x4
	#define P_SEC2IE 2
	
	#define M_SECIE 0x8
	#define P_SECIE 3
	
	#define M_MINIE 0x10
	#define P_MINIE 4
	
	#define M_HOURIE 0x20
	#define P_HOURIE 5
	
	#define M_DAYIE 0x40
	#define P_DAYIE 6
	
	#define M_ALAIE 0x80
	#define P_ALAIE 7

	// SFR RTCIF: RTC interrupt flag register
	SFRX(RTCIF, 0xFE63);
	
	#define M_SEC32IF 0x1
	#define P_SEC32IF 0
	
	#define M_SEC8IF 0x2
	#define P_SEC8IF 1
	
	#define M_SEC2IF 0x4
	#define P_SEC2IF 2
	
	#define M_SECIF 0x8
	#define P_SECIF 3
	
	#define M_MINIF 0x10
	#define P_MINIF 4
	
	#define M_HOURIF 0x20
	#define P_HOURIF 5
	
	#define M_DAYIF 0x40
	#define P_DAYIF 6
	
	#define M_ALAIF 0x80
	#define P_ALAIF 7

	// SFR ALAHOUR: RTC alarm hour
	SFRX(ALAHOUR, 0xFE64);

	// SFR ALAMIN: RTC alarm minute
	SFRX(ALAMIN, 0xFE65);

	// SFR ALASEC: RTC alarm second
	SFRX(ALASEC, 0xFE66);

	// SFR ALASSEC: RTC alarm 1/128th second
	SFRX(ALASSEC, 0xFE67);

	// SFR INIYEAR: RTC initialization year
	SFRX(INIYEAR, 0xFE68);

	// SFR INIMONTH: RTC initialization month
	SFRX(INIMONTH, 0xFE69);

	// SFR INIDAY: RTC initialization day
	SFRX(INIDAY, 0xFE6A);

	// SFR INIHOUR: RTC initialization hour
	SFRX(INIHOUR, 0xFE6B);

	// SFR INIMIN: RTC initialization minute
	SFRX(INIMIN, 0xFE6C);

	// SFR INISEC: RTC initialization second
	SFRX(INISEC, 0xFE6D);

	// SFR INISSEC: RTC initialization 1/128th second
	SFRX(INISSEC, 0xFE6E);

	// SFR YEAR: RTC year
	SFRX(YEAR, 0xFE70);

	// SFR MONTH: RTC month
	SFRX(MONTH, 0xFE71);

	// SFR DAY: RTC day
	SFRX(DAY, 0xFE72);

	// SFR HOUR: RTC hour
	SFRX(HOUR, 0xFE73);

	// SFR MIN: RTC minute
	SFRX(MIN, 0xFE74);

	// SFR SEC: RTC second
	SFRX(SEC, 0xFE75);

	// SFR SSEC: RTC 1/128th second
	SFRX(SSEC, 0xFE76);
	
	// For use with IP3L / IP3H
	#define M_RTCPR 0x04
	#define P_RTCPR 2

	// RTC interrupt (usage in C => see STC8H TRM appendix R)
	#define RTC_INTERRUPT 36
	#define RTC_VECTOR_ADDR 0x0123
#endif // MCU_HAS_RTC

#endif // _UNISTC_RTC_H
