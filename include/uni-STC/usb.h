/**
 * @file uni-STC/usb.h
 * 
 * Register, bit and macro definitions for the USB interface.
 */

#ifndef _UNISTC_USB_H
#define _UNISTC_USB_H

#ifdef MCU_HAS_USB
	// SFR USBCLK: USB clock control register
	SFR(USBCLK, 0xDC);
	
	#define M_PHYTST 0x03
	#define P_PHYTST 0
	#define M_TST_PHY 0x4
	#define P_TST_PHY 2
	#define M_TST_USB 0x8
	#define P_TST_USB 3
	#define M_CRE 0x10
	#define P_CRE 4
	#define M_PCKI 0x60
	#define P_PCKI 5
	#define M_ENCKM 0x80
	#define P_ENCKM 7

	// SFR USBDAT: USB data register
	SFR(USBDAT, 0xEC);

	// SFR USBCON: USB control register
	SFR(USBCON, 0xF4);
	
	#define M_DM 0x1
	#define P_DM 0
	#define M_DP 0x2
	#define P_DP 1
	#define M_DFREC 0x4
	#define P_DFREC 2
	#define M_PDEN 0x8
	#define P_PDEN 3
	#define M_PUEN 0x10
	#define P_PUEN 4
	#define M_PS2M 0x20
	#define P_PS2M 5
	#define M_USBRST 0x40
	#define P_USBRST 6
	#define M_ENUSB 0x80
	#define P_ENUSB 7

	// SFR USBADR: USB address register
	SFR(USBADR, 0xFC);
	
	#define M_UADR 0x3f
	#define P_UADR 0
	#define M_AUTORD 0x40
	#define P_AUTORD 6
	#define M_BUSY 0x80
	#define P_BUSY 7
	
	// USB interrupt
	#define USB_INTERRUPT 25
	#define USB_VECTOR_ADDR 0x00CB
#endif // MCU_HAS_USB

#endif // _UNISTC_USB_H
