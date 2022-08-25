/**
 * @file uni-STC/spi.h
 * 
 * Main header - the only one that must be included in MCU-specific headers.
 */

#ifndef _UNISTC_STCMCU_H
#define _UNISTC_STCMCU_H

#ifndef MCU_FREQ
	#error "The MCU_FREQ macro must be defined (e.g. 24000000ul)"
#endif

#ifndef MCU_FAMILY
	#error "The MCU_FAMILY macro must be defined (e.g. 12, 15, 8)"
#endif

#ifndef MCU_SERIES
	#error "The MCU_SERIES macro must be defined (e.g. 'A', 'G', 'H')"
#endif

#ifndef MCU_PINS
	#error "The MCU_PINS macro must be defined (e.g. 8, 20, 48)"
#endif

// Convenience macro, improves legibility.
#if MCU_FAMILY == 8 && MCU_SERIES == 'A' && defined(MCU_HAS_DMA)
	#define STC8A8KxxD4
#endif

#include <compiler.h>

#include <uni-STC/uni-STC.h>
#include <uni-STC/adc.h>
#include <uni-STC/comparator.h>
#include <uni-STC/dma.h>
#include <uni-STC/dptr.h>
#include <uni-STC/gpio/gpio.h>
#include <uni-STC/i2c.h>
#include <uni-STC/iap.h>
#include <uni-STC/interrupt.h>
#include <uni-STC/lcd.h>
#include <uni-STC/lcm.h>
#include <uni-STC/led.h>
#include <uni-STC/mdu.h>
#include <uni-STC/misc.h>
#include <uni-STC/pca.h>
#include <uni-STC/pwm/pwm.h>
#include <uni-STC/rtc.h>
#include <uni-STC/spi.h>
#include <uni-STC/sysclk.h>
#include <uni-STC/timer.h>
#include <uni-STC/touchkey.h>
#include <uni-STC/uart.h>
#include <uni-STC/usb.h>

#endif // _UNISTC_STCMCU_H
