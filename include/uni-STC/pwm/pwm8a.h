/**
 * @file uni-STC/pwm/pwm8a.h
 * 
 * Register, bit and macro definitions for the 15-bit enhanced PWM
 * of the STC8A8K64S4A12.
 */

#ifndef _UNISTC_PWM_PWM8A_H
#define _UNISTC_PWM_PWM8A_H

// SFR PWMCFG: PWM configuration register
SFR(PWMCFG, 0xF1);

#define M_ETADC 0x40
#define P_ETADC 6

#define M_CBIF 0x80
#define P_CBIF 7

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

#define M_C6IF 0x40
#define P_C6IF 6

#define M_C7IF 0x80
#define P_C7IF 7

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

#define M_INVIO 0x40
#define P_INVIO 6

#define M_INVCMP 0x80
#define P_INVCMP 7

// SFR PWMCR: PWM control register
SFR(PWMCR, 0xFE);

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

// SFR PWM0TADCH: ADC counter value high
SFRX(PWM0TADCH, 0xFFF3);
// SFR PWM0TADCL: ADC counter value low
SFRX(PWM0TADCL, 0xFFF4);

// SFR PWM00T1H: PWM0 Timer 1 high
SFRX(PWM00T1H, 0xFF00);
// SFR PWM00T1L: PWM0 Timer 1 low
SFRX(PWM00T1L, 0xFF01);
// SFR PWM00T2H: PWM0 Timer 2 high
SFRX(PWM00T2H, 0xFF02);
// SFR PWM00T2L: PWM0 Timer 2 low
SFRX(PWM00T2L, 0xFF03);
// SFR PWM00CR: PWM0 control register
SFRX(PWM00CR, 0xFF04);

#define M_ENT1I 0x1
#define P_ENT1I 0

#define M_ENT2I 0x2
#define P_ENT2I 1

#define M_ENI 0x4
#define P_ENI 2

#define M_C_S 0x18
#define P_C_S 3

#define M_INI 0x40
#define P_INI 6

#define M_ENO 0x80
#define P_ENO 7

// SFR PWM00HLD: PWM0 level hold control register
SFRX(PWM00HLD, 0xFF05);

#define M_HLDL 0x1
#define P_HLDL 0

#define M_HLDH 0x2
#define P_HLDH 1

// To manipulate both HLDL & HLDH in a single operation.
#define M_HLD 0x3
#define P_HLD 0

// SFR PWM01T1H: PWM1 Timer 1 high
SFRX(PWM01T1H, 0xFF10);
// SFR PWM01T1L: PWM1 Timer 1 low
SFRX(PWM01T1L, 0xFF11);
// SFR PWM01T2H: PWM1 Timer 2 high
SFRX(PWM01T2H, 0xFF12);
// SFR PWM01T2L: PWM1 Timer 2 low
SFRX(PWM01T2L, 0xFF13);
// SFR PWM01CR: PWM1 control register
SFRX(PWM01CR, 0xFF14);
// SFR PWM01HLD: PWM1 level hold control register
SFRX(PWM01HLD, 0xFF15);

// SFR PWM02T1H: PWM2 Timer 1 high
SFRX(PWM02T1H, 0xFF20);
// SFR PWM02T1L: PWM2 Timer 1 low
SFRX(PWM02T1L, 0xFF21);
// SFR PWM02T2H: PWM2 Timer 2 high
SFRX(PWM02T2H, 0xFF22);
// SFR PWM02T2L: PWM2 Timer 2 low
SFRX(PWM02T2L, 0xFF23);
// SFR PWM02CR: PWM2 control register
SFRX(PWM02CR, 0xFF24);
// SFR PWM02HLD: PWM2 level hold control register
SFRX(PWM02HLD, 0xFF25);

// SFR PWM03T1H: PWM3 Timer 1 high
SFRX(PWM03T1H, 0xFF30);
// SFR PWM03T1L: PWM3 Timer 1 low
SFRX(PWM03T1L, 0xFF31);
// SFR PWM03T2H: PWM3 Timer 2 high
SFRX(PWM03T2H, 0xFF32);
// SFR PWM03T2L: PWM3 Timer 2 low
SFRX(PWM03T2L, 0xFF33);
// SFR PWM03CR: PWM3 control register
SFRX(PWM03CR, 0xFF34);
// SFR PWM03HLD: PWM3 level hold control register
SFRX(PWM03HLD, 0xFF35);

// SFR PWM04T1H: PWM4 Timer 1 high
SFRX(PWM04T1H, 0xFF40);
// SFR PWM04T1L: PWM4 Timer 1 low
SFRX(PWM04T1L, 0xFF41);
// SFR PWM04T2H: PWM4 Timer 2 high
SFRX(PWM04T2H, 0xFF42);
// SFR PWM04T2L: PWM4 Timer 2 low
SFRX(PWM04T2L, 0xFF43);
// SFR PWM04CR: PWM4 control register
SFRX(PWM04CR, 0xFF44);
// SFR PWM04HLD: PWM4 level hold control register
SFRX(PWM04HLD, 0xFF45);

// SFR PWM05T1H: PWM5 Timer 1 high
SFRX(PWM05T1H, 0xFF50);
// SFR PWM05T1L: PWM5 Timer 1 low
SFRX(PWM05T1L, 0xFF51);
// SFR PWM05T2H: PWM5 Timer 2 high
SFRX(PWM05T2H, 0xFF52);
// SFR PWM05T2L: PWM5 Timer 2 low
SFRX(PWM05T2L, 0xFF53);
// SFR PWM05CR: PWM5 control register
SFRX(PWM05CR, 0xFF54);
// SFR PWM05HLD: PWM5 level hold control register
SFRX(PWM05HLD, 0xFF55);

// SFR PWM06T1H: PWM6 Timer 1 high
SFRX(PWM06T1H, 0xFF60);
// SFR PWM06T1L: PWM6 Timer 1 low
SFRX(PWM06T1L, 0xFF61);
// SFR PWM06T2H: PWM6 Timer 2 high
SFRX(PWM06T2H, 0xFF62);
// SFR PWM06T2L: PWM6 Timer 2 low
SFRX(PWM06T2L, 0xFF63);
// SFR PWM06CR: PWM6 control register
SFRX(PWM06CR, 0xFF64);
// SFR PWM06HLD: PWM6 level hold control register
SFRX(PWM06HLD, 0xFF65);

// SFR PWM07T1H: PWM7 Timer 1 high
SFRX(PWM07T1H, 0xFF70);
// SFR PWM07T1L: PWM7 Timer 1 low
SFRX(PWM07T1L, 0xFF71);
// SFR PWM07T2H: PWM7 Timer 2 high
SFRX(PWM07T2H, 0xFF72);
// SFR PWM07T2L: PWM7 Timer 2 low
SFRX(PWM07T2L, 0xFF73);
// SFR PWM07CR: PWM7 control register
SFRX(PWM07CR, 0xFF74);
// SFR PWM07HLD: PWM7 level hold control register
SFRX(PWM07HLD, 0xFF75);

#endif // _UNISTC_PWM_PWM8A_H
