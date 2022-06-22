/**
 * @file uni-STC/pwm/pwm15.h
 * 
 * Register, bit and macro definitions for the 15-bit enhanced PWM
 * of the STC15W4K32S4.
 */

#ifndef _UNISTC_PWM_PWM15_H
#define _UNISTC_PWM_PWM15_H

// SFR PWMCFG: PWM configuration register
SFR(PWMCFG, 0xF1);

#define M_C0INI 0x1
#define P_C0INI 0

#define M_C1INI 0x2
#define P_C1INI 1

#define M_C2INI 0x4
#define P_C2INI 2

#define M_C3INI 0x8
#define P_C3INI 3

#define M_C4INI 0x10
#define P_C4INI 4

#define M_C5INI 0x20
#define P_C5INI 5

#define M_CBTADC 0x40
#define P_CBTADC 6

// SFR PWM0IF: PWM interrupt flag
SFR(PWM0IF, 0xF6);

#define M_C0IF 0x1
#define P_C0IF 0

#define M_C1IF 0x2
#define P_C1IF 1

#define M_C2IF 0x4
#define P_C2IF 2

#define M_C3IF 0x8
#define P_C3IF 3

#define M_C4IF 0x10
#define P_C4IF 4

#define M_C5IF 0x20
#define P_C5IF 5

#define M_CBIF 0x40
#define P_CBIF 6

// SFR PWM0FDCR: PWM fault detection control register
SFR(PWM0FDCR, 0xF7);

#define M_FDIF 0x1
#define P_FDIF 0

#define M_FDIO 0x2
#define P_FDIO 1

#define M_FDCMP 0x4
#define P_FDCMP 2

#define M_EFDI 0x8
#define P_EFDI 3

#define M_FLTFLIO 0x10
#define P_FLTFLIO 4

#define M_ENFD 0x20
#define P_ENFD 5

// SFR PWMCR: PWM control register
SFR(PWMCR, 0xF5);

#define M_EN0O 0x1
#define P_EN0O 0

#define M_EN1O 0x2
#define P_EN1O 1

#define M_EN2O 0x4
#define P_EN2O 2

#define M_EN3O 0x8
#define P_EN3O 3

#define M_EN4O 0x10
#define P_EN4O 4

#define M_EN5O 0x20
#define P_EN5O 5

#define M_ECBI 0x40
#define P_ECBI 6

#define M_ENPWM 0x80
#define P_ENPWM 7

// SFR PWM0CH: PWM counter high
SFRX(PWM0CH, 0xFFF0);
// SFR PWM0CL: PWM counter low
SFRX(PWM0CL, 0xFFF1);
// SFR PWM0CKS: PWM clock selection register
SFRX(PWM0CKS, 0xFFF2);

#define M_PWM_PS 0x0f
#define P_PWM_PS 0

#define M_SELT2 0x10
#define P_SELT2 4

// SFR PWM00T1H: PWM2 Timer 1 high
SFRX(PWM00T1H, 0xFF00);
// SFR PWM00T1L: PWM2 Timer 1 low
SFRX(PWM00T1L, 0xFF01);
// SFR PWM00T2H: PWM2 Timer 2 high
SFRX(PWM00T2H, 0xFF02);
// SFR PWM00T2L: PWM2 Timer 2 low
SFRX(PWM00T2L, 0xFF03);
// SFR PWM00CR: PWM2 control register
SFRX(PWM00CR, 0xFF04);

#define M_ENT1I 0x1
#define P_ENT1I 0

#define M_ENT2I 0x2
#define P_ENT2I 1

#define M_EENI 0x4
#define P_EENI 2

#define M_C_S 0x8
#define P_C_S 3

// SFR PWM01T1H: PWM3 Timer 1 high
SFRX(PWM01T1H, 0xFF10);
// SFR PWM01T1L: PWM3 Timer 1 low
SFRX(PWM01T1L, 0xFF11);
// SFR PWM01T2H: PWM3 Timer 2 high
SFRX(PWM01T2H, 0xFF12);
// SFR PWM01T2L: PWM3 Timer 2 low
SFRX(PWM01T2L, 0xFF13);
// SFR PWM01CR: PWM3 control register
SFRX(PWM01CR, 0xFF14);

// SFR PWM02T1H: PWM4 Timer 1 high
SFRX(PWM02T1H, 0xFF20);
// SFR PWM02T1L: PWM4 Timer 1 low
SFRX(PWM02T1L, 0xFF21);
// SFR PWM02T2H: PWM4 Timer 2 high
SFRX(PWM02T2H, 0xFF22);
// SFR PWM02T2L: PWM4 Timer 2 low
SFRX(PWM02T2L, 0xFF23);
// SFR PWM02CR: PWM4 control register
SFRX(PWM02CR, 0xFF24);

// SFR PWM03T1H: PWM5 Timer 1 high
SFRX(PWM03T1H, 0xFF30);
// SFR PWM03T1L: PWM5 Timer 1 low
SFRX(PWM03T1L, 0xFF31);
// SFR PWM03T2H: PWM5 Timer 2 high
SFRX(PWM03T2H, 0xFF32);
// SFR PWM03T2L: PWM5 Timer 2 low
SFRX(PWM03T2L, 0xFF33);
// SFR PWM03CR: PWM5 control register
SFRX(PWM03CR, 0xFF34);

// SFR PWM04T1H: PWM6 Timer 1 high
SFRX(PWM04T1H, 0xFF40);
// SFR PWM04T1L: PWM6 Timer 1 low
SFRX(PWM04T1L, 0xFF41);
// SFR PWM04T2H: PWM6 Timer 2 high
SFRX(PWM04T2H, 0xFF42);
// SFR PWM04T2L: PWM6 Timer 2 low
SFRX(PWM04T2L, 0xFF43);
// SFR PWM04CR: PWM6 control register
SFRX(PWM04CR, 0xFF44);

// SFR PWM05T1H: PWM7 Timer 1 high
SFRX(PWM05T1H, 0xFF50);
// SFR PWM05T1L: PWM7 Timer 1 low
SFRX(PWM05T1L, 0xFF51);
// SFR PWM05T2H: PWM7 Timer 2 high
SFRX(PWM05T2H, 0xFF52);
// SFR PWM05T2L: PWM7 Timer 2 low
SFRX(PWM05T2L, 0xFF53);
// SFR PWM05CR: PWM7 control register
SFRX(PWM05CR, 0xFF54);

#endif // _UNISTC_PWM_PWM15_H
