#ifndef _STC8H8KXXU_LQFP48_H
#define _STC8H8KXXU_LQFP48_H

/**
 * IMPORTANT - Check your chip version (A, B, or C)!
 * 
 * Refer to the STC8H Technical Reference Manual section 2.5.1 for 
 * differences between versions A and B, and Appendix T section T.4
 * for version B's errata fixed in version C.
 */

/**
 * NOTE: On the STC8H8 and STC8H4, the pin traditionally used for P55 
 * is used for ADC_VRef+.
 */

#define MCU_FAMILY 8
#define MCU_SERIES 'H'
#define MCU_PINS 48
#define MCU_HAS_COMPARATOR
#define COMPARATOR_4P2N
#define MCU_HAS_MDU
#define MCU_HAS_DMA
#define MCU_HAS_LCM
#define MCU_HAS_RTC
#define MCU_HAS_USB
#define GPIO_NO_P12
#define GPIO_NO_P55
#define NB_UARTS 4
#define PWM_GROUPS 2
#define PWM_CHANNELS 4
#define ADC_CHANNELS 15
#define SPI_HAS_HIGH_SPEED
#define NB_TIMERS 5

#include <uni-STC/stcmcu.h>

#endif // _STC8H8KXXU_LQFP48_H
