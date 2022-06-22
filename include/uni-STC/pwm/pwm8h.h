/**
 * @file uni-STC/pwm/pwm8h.h
 * 
 * Register, bit and macro definitions for the 16-bit advanced PWM
 * of the STC8H family.
 */

#ifndef _UNISTC_PWM_PWM8H_H
#define _UNISTC_PWM_PWM8H_H

// SFR PWMA_ETRPS: PWMA ETR select register
SFRX(PWMA_ETRPS, 0xFEB0);

#define M_ETR_PS 0x03
#define P_ETR_PS 0

#define M_BRK_PS 0x4
#define P_BRK_PS 2

// SFR PWMA_ENO: PWMA output enable control
SFRX(PWMA_ENO, 0xFEB1);

#define M_ENO1P 0x1
#define P_ENO1P 0

#define M_ENO1N 0x2
#define P_ENO1N 1

#define M_ENO2P 0x4
#define P_ENO2P 2

#define M_ENO2N 0x8
#define P_ENO2N 3

#define M_ENO3P 0x10
#define P_ENO3P 4

#define M_ENO3N 0x20
#define P_ENO3N 5

#define M_ENO4P 0x40
#define P_ENO4P 6

#define M_ENO4N 0x80
#define P_ENO4N 7

// SFR PWMA_PS: PWMA output pin selection register
SFRX(PWMA_PS, 0xFEB2);

#define M_C1PS 0x03
#define P_C1PS 0

#define M_C2PS 0x0c
#define P_C2PS 2

#define M_C3PS 0x30
#define P_C3PS 4

#define M_C4PS 0xc0
#define P_C4PS 6

// SFR PWMA_IOAUX: PWMA auxiliary register
SFRX(PWMA_IOAUX, 0xFEB3);

#define M_AUX1P 0x1
#define P_AUX1P 0

#define M_AUX1N 0x2
#define P_AUX1N 1

#define M_AUX2P 0x4
#define P_AUX2P 2

#define M_AUX2N 0x8
#define P_AUX2N 3

#define M_AUX3P 0x10
#define P_AUX3P 4

#define M_AUX3N 0x20
#define P_AUX3N 5

#define M_AUX4P 0x40
#define P_AUX4P 6

#define M_AUX4N 0x80
#define P_AUX4N 7

// SFR PWMB_ETRPS: PWMB ETR select register
SFRX(PWMB_ETRPS, 0xFEB4);

// SFR PWMB_ENO: PWMB output enable control
SFRX(PWMB_ENO, 0xFEB5);

#define M_ENO5P 0x1
#define P_ENO5P 0

#define M_ENO6P 0x4
#define P_ENO6P 2

#define M_ENO7P 0x10
#define P_ENO7P 4

#define M_ENO8P 0x40
#define P_ENO8P 6

// SFR PWMB_PS: PWMB output pin selection register
SFRX(PWMB_PS, 0xFEB6);

#define M_C5PS 0x03
#define P_C5PS 0

#define M_C6PS 0x0c
#define P_C6PS 2

#define M_C7PS 0x30
#define P_C7PS 4

#define M_C8PS 0xc0
#define P_C8PS 6

// SFR PWMB_IOAUX: PWMB auxiliary register
SFRX(PWMB_IOAUX, 0xFEB7);

#define M_AUX5P 0x1
#define P_AUX5P 0

#define M_AUX6P 0x4
#define P_AUX6P 2

#define M_AUX7P 0x10
#define P_AUX7P 4

#define M_AUX8P 0x40
#define P_AUX8P 6

// SFR PWMA_CR1: PWMA control register 1
SFRX(PWMA_CR1, 0xFEC0);

#define M_CEN 0x1
#define P_CEN 0

#define M_UDIS 0x2
#define P_UDIS 1

#define M_URS 0x4
#define P_URS 2

#define M_OPM 0x8
#define P_OPM 3

#define M_DIR 0x10
#define P_DIR 4

#define M_CMS 0x60
#define P_CMS 5

#define M_ARPE 0x80
#define P_ARPE 7

// SFR PWMA_CR2: PWMA control register 2
SFRX(PWMA_CR2, 0xFEC1);

#define M_CCPC 0x1
#define P_CCPC 0

#define M_COMS 0x4
#define P_COMS 2

#define M_MMS 0x70
#define P_MMS 4

// SFR PWMA_SMCR: PWMA slave mode control register
SFRX(PWMA_SMCR, 0xFEC2);

#define M_SMS 0x07
#define P_SMS 0

#define M_TS 0x70
#define P_TS 4

#define M_MSM 0x80
#define P_MSM 7

// SFR PWMA_ETR: PWMA external trigger register
SFRX(PWMA_ETR, 0xFEC3);

#define M_ETF 0x0f
#define P_ETF 0

#define M_ETPS 0x30
#define P_ETPS 4

#define M_ECE 0x40
#define P_ECE 6

#define M_ETP 0x80
#define P_ETP 7

// SFR PWMA_IER: PWMA interrupt enable register
SFRX(PWMA_IER, 0xFEC4);

#define M_UIE 0x1
#define P_UIE 0

#define M_CC1IE 0x2
#define P_CC1IE 1

#define M_CC2IE 0x4
#define P_CC2IE 2

#define M_CC3IE 0x8
#define P_CC3IE 3

#define M_CC4IE 0x10
#define P_CC4IE 4

#define M_COMIE 0x20
#define P_COMIE 5

#define M_TIE 0x40
#define P_TIE 6

#define M_BIE 0x80
#define P_BIE 7

// SFR PWMA_SR1: PWMA status register 1
SFRX(PWMA_SR1, 0xFEC5);

#define M_UIF 0x1
#define P_UIF 0

#define M_CC1IF 0x2
#define P_CC1IF 1

#define M_CC2IF 0x4
#define P_CC2IF 2

#define M_CC3IF 0x8
#define P_CC3IF 3

#define M_CC4IF 0x10
#define P_CC4IF 4

#define M_COMIF 0x20
#define P_COMIF 5

#define M_TIF 0x40
#define P_TIF 6

#define M_BIF 0x80
#define P_BIF 7

// SFR PWMA_SR2: PWMA status register 2
SFRX(PWMA_SR2, 0xFEC6);

#define M_CC1OF 0x2
#define P_CC1OF 1

#define M_CC2OF 0x4
#define P_CC2OF 2

#define M_CC3OF 0x8
#define P_CC3OF 3

#define M_CC4OF 0x10
#define P_CC4OF 4

// SFR PWMA_EGR: PWMA event register
SFRX(PWMA_EGR, 0xFEC7);

#define M_UG 0x1
#define P_UG 0

#define M_CC1G 0x2
#define P_CC1G 1

#define M_CC2G 0x4
#define P_CC2G 2

#define M_CC3G 0x8
#define P_CC3G 3

#define M_CC4G 0x10
#define P_CC4G 4

#define M_COMG 0x20
#define P_COMG 5

#define M_TG 0x40
#define P_TG 6

#define M_BG 0x80
#define P_BG 7

// SFR PWMA_CCMR1: PWMA capture/compare mode register 1
SFRX(PWMA_CCMR1, 0xFEC8);

// Capture mode bit masks
#define M_CC_S 0x03
#define P_CC_S 0

#define M_OC_FE 0x4
#define P_OC_FE 2

#define M_OC_PE 0x8
#define P_OC_PE 3

#define M_OC_M 0x70
#define P_OC_M 4

#define M_OC_CE 0x80
#define P_OC_CE 7

// Compare mode bit masks
#define M_IC_PSC 0x0c
#define P_IC_PSC 0

#define M_IC_F 0xf0
#define P_IC_F 4

// SFR PWMA_CCMR2: PWMA capture/compare mode register 2
SFRX(PWMA_CCMR2, 0xFEC9);

// SFR PWMA_CCMR3: PWMA capture/compare mode register 3
SFRX(PWMA_CCMR3, 0xFECA);

// SFR PWMA_CCMR4: PWMA capture/compare mode register 4
SFRX(PWMA_CCMR4, 0xFECB);

// SFR PWMA_CCER1: PWMA capture compare enable register 1
SFRX(PWMA_CCER1, 0xFECC);

#define M_CC1E 0x1
#define P_CC1E 0

#define M_CC1P 0x2
#define P_CC1P 1

#define M_CC1NE 0x4
#define P_CC1NE 2

#define M_CC1NP 0x8
#define P_CC1NP 3

#define M_CC2E 0x10
#define P_CC2E 4

#define M_CC2P 0x20
#define P_CC2P 5

#define M_CC2NE 0x40
#define P_CC2NE 6

#define M_CC2NP 0x80
#define P_CC2NP 7

// SFR PWMA_CCER2: PWMA capture compare enable register 2
SFRX(PWMA_CCER2, 0xFECD);

#define M_CC3E 0x1
#define P_CC3E 0

#define M_CC3P 0x2
#define P_CC3P 1

#define M_CC3NE 0x4
#define P_CC3NE 2

#define M_CC3NP 0x8
#define P_CC3NP 3

#define M_CC4E 0x10
#define P_CC4E 4

#define M_CC4P 0x20
#define P_CC4P 5

#define M_CC4NE 0x40
#define P_CC4NE 6

#define M_CC4NP 0x80
#define P_CC4NP 7

// SFR PWMA_CNTRH: PWMA counter high byte
SFRX(PWMA_CNTRH, 0xFECE);
// SFR PWMA_CNTRL: PWMA counter low byte
SFRX(PWMA_CNTRL, 0xFECF);

// SFR PWMA_PSCRH: PWMA prescale high byte
SFRX(PWMA_PSCRH, 0xFED0);
// SFR PWMA_PSCRL: PWMA prescale low byte
SFRX(PWMA_PSCRL, 0xFED1);

// SFR PWMA_ARRH: PWMA auto-reload register high byte
SFRX(PWMA_ARRH, 0xFED2);
// SFR PWMA_ARRL: PWMA auto-reload register low byte
SFRX(PWMA_ARRL, 0xFED3);

// SFR PWMA_RCR: PWMA repeat counter register
SFRX(PWMA_RCR, 0xFED4);

// SFR PWMA_CCR1H: PWMA compare capture register 1 high byte
SFRX(PWMA_CCR1H, 0xFED5);
// SFR PWMA_CCR1L: PWMA compare capture register 1 low byte
SFRX(PWMA_CCR1L, 0xFED6);

// SFR PWMA_CCR2H: PWMA compare capture register 2 high byte
SFRX(PWMA_CCR2H, 0xFED7);
// SFR PWMA_CCR2L: PWMA compare capture register 2 low byte
SFRX(PWMA_CCR2L, 0xFED8);

// SFR PWMA_CCR3H: PWMA compare capture register 3 high byte
SFRX(PWMA_CCR3H, 0xFED9);
// SFR PWMA_CCR3L: PWMA compare capture register 3 low byte
SFRX(PWMA_CCR3L, 0xFEDA);

// SFR PWMA_CCR4H: PWMA compare capture register 4 high byte
SFRX(PWMA_CCR4H, 0xFEDB);
// SFR PWMA_CCR4L: PWMA compare capture register 4 low byte
SFRX(PWMA_CCR4L, 0xFEDC);

// SFR PWMA_BKR: PWMA brake register
SFRX(PWMA_BKR, 0xFEDD);

#define M_LOCK 0x03
#define P_LOCK 0

#define M_OSSI 0x4
#define P_OSSI 2

#define M_OSSR 0x8
#define P_OSSR 3

#define M_BKE 0x10
#define P_BKE 4

#define M_BKP 0x20
#define P_BKP 5

#define M_AOE 0x40
#define P_AOE 6

#define M_MOE 0x80
#define P_MOE 7

// SFR PWMA_DTR: PWMA dead time control register
SFRX(PWMA_DTR, 0xFEDE);

// SFR PWMA_OISR: PWMA output idle status register
SFRX(PWMA_OISR, 0xFEDF);

#define M_OIS1 0x1
#define P_OIS1 0

#define M_OIS1N 0x2
#define P_OIS1N 1

#define M_OIS2 0x4
#define P_OIS2 2

#define M_OIS2N 0x8
#define P_OIS2N 3

#define M_OIS3 0x10
#define P_OIS3 4

#define M_OIS3N 0x20
#define P_OIS3N 5

#define M_OIS4 0x40
#define P_OIS4 6

#define M_OIS4N 0x80
#define P_OIS4N 7

// SFR PWMB_CR1: PWMB control register 1
SFRX(PWMB_CR1, 0xFEE0);

// SFR PWMB_CR2: PWMB control register 2
SFRX(PWMB_CR2, 0xFEE1);

// SFR PWMB_SMCR: PWMB slave mode control register
SFRX(PWMB_SMCR, 0xFEE2);

// SFR PWMB_ETR: PWMB external trigger register
SFRX(PWMB_ETR, 0xFEE3);

// SFR PWMB_IER: PWMB interrupt enable register
SFRX(PWMB_IER, 0xFEE4);

#define M_CC5IE 0x2
#define P_CC5IE 1

#define M_CC6IE 0x4
#define P_CC6IE 2

#define M_CC7IE 0x8
#define P_CC7IE 3

#define M_CC8IE 0x10
#define P_CC8IE 4

// SFR PWMB_SR1: PWMB status register 1
SFRX(PWMB_SR1, 0xFEE5);

#define M_CC5IF 0x2
#define P_CC5IF 1

#define M_CC6IF 0x4
#define P_CC6IF 2

#define M_CC7IF 0x8
#define P_CC7IF 3

#define M_CC8IF 0x10
#define P_CC8IF 4

// SFR PWMB_SR2: PWMB status register 2
SFRX(PWMB_SR2, 0xFEE6);

#define M_CC5OF 0x2
#define P_CC5OF 1

#define M_CC6OF 0x4
#define P_CC6OF 2

#define M_CC7OF 0x8
#define P_CC7OF 3

#define M_CC8OF 0x10
#define P_CC8OF 4

// SFR PWMB_EGR: PWMB event register
SFRX(PWMB_EGR, 0xFEE7);

#define M_CC5G 0x2
#define P_CC5G 1

#define M_CC6G 0x4
#define P_CC6G 2

#define M_CC7G 0x8
#define P_CC7G 3

#define M_CC8G 0x10
#define P_CC8G 4

// SFR PWMB_CCMR1: PWMB capture mode register 1
SFRX(PWMB_CCMR1, 0xFEE8);

// SFR PWMB_CCMR2: PWMB capture mode register 2
SFRX(PWMB_CCMR2, 0xFEE9);

// SFR PWMB_CCMR3: PWMB capture mode register 3
SFRX(PWMB_CCMR3, 0xFEEA);

// SFR PWMB_CCMR4: PWMB capture mode register 4
SFRX(PWMB_CCMR4, 0xFEEB);

// SFR PWMB_CCER1: PWMB capture compare enable register 1
SFRX(PWMB_CCER1, 0xFEEC);

#define M_CC5E 0x1
#define P_CC5E 0

#define M_CC5P 0x2
#define P_CC5P 1

#define M_CC5NE 0x4
#define P_CC5NE 2

#define M_CC5NP 0x8
#define P_CC5NP 3

#define M_CC6E 0x10
#define P_CC6E 4

#define M_CC6P 0x20
#define P_CC6P 5

#define M_CC6NE 0x40
#define P_CC6NE 6

#define M_CC6NP 0x80
#define P_CC6NP 7

// SFR PWMB_CCER2: PWMB capture compare enable register 2
SFRX(PWMB_CCER2, 0xFEED);

#define M_CC7E 0x1
#define P_CC7E 0

#define M_CC7P 0x2
#define P_CC7P 1

#define M_CC7NE 0x4
#define P_CC7NE 2

#define M_CC7NP 0x8
#define P_CC7NP 3

#define M_CC8E 0x10
#define P_CC8E 4

#define M_CC8P 0x20
#define P_CC8P 5

#define M_CC8NE 0x40
#define P_CC8NE 6

#define M_CC8NP 0x80
#define P_CC8NP 7

// SFR PWMB_CNTRH: PWMB counter high byte
SFRX(PWMB_CNTRH, 0xFEEE);
// SFR PWMB_CNTRL: PWMB counter low byte
SFRX(PWMB_CNTRL, 0xFEEF);

// SFR PWMB_PSCRH: PWMB prescale high byte
SFRX(PWMB_PSCRH, 0xFEF0);
// SFR PWMB_PSCRL: PWMB prescale low byte
SFRX(PWMB_PSCRL, 0xFEF1);

// SFR PWMB_ARRH: PWMB auto-reload register high byte
SFRX(PWMB_ARRH, 0xFEF2);
// SFR PWMB_ARRL: PWMB auto-reload register low byte
SFRX(PWMB_ARRL, 0xFEF3);

// SFR PWMB_RCR: PWMB repeat counter register
SFRX(PWMB_RCR, 0xFEF4);

// SFR PWMB_CCR1H: PWMB compare capture register 1 high byte
SFRX(PWMB_CCR1H, 0xFEF5);
// SFR PWMB_CCR1L: PWMB compare capture register 1 low byte
SFRX(PWMB_CCR1L, 0xFEF6);

// SFR PWMB_CCR2H: PWMB compare capture register 2 high byte
SFRX(PWMB_CCR2H, 0xFEF7);
// SFR PWMB_CCR2L: PWMB compare capture register 2 low byte
SFRX(PWMB_CCR2L, 0xFEF8);

// SFR PWMB_CCR3H: PWMB compare capture register 3 high byte
SFRX(PWMB_CCR3H, 0xFEF9);
// SFR PWMB_CCR3L: PWMB compare capture register 3 low byte
SFRX(PWMB_CCR3L, 0xFEFA);

// SFR PWMB_CCR4H: PWMB compare capture register 4 high byte
SFRX(PWMB_CCR4H, 0xFEFB);
// SFR PWMB_CCR4L: PWMB compare capture register 4 low byte
SFRX(PWMB_CCR4L, 0xFEFC);

// SFR PWMB_BKR: PWMB brake register
SFRX(PWMB_BKR, 0xFEFD);

// SFR PWMB_DTR: PWMB dead time control register
SFRX(PWMB_DTR, 0xFEFE);

// SFR PWMB_OISR: PWMB output idle status register
SFRX(PWMB_OISR, 0xFEFF);

#define M_OIS5 0x1
#define P_OIS5 0

#define M_OIS6 0x4
#define P_OIS6 2

#define M_OIS7 0x10
#define P_OIS7 4

#define M_OIS8 0x40
#define P_OIS8 6

#endif // _UNISTC_PWM_PWM8H_H
