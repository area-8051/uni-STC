/**
 * @file uni-STC/pwm/pwm.h
 * 
 * Register, bit and mask definitions related to the
 * 15-bit extended PWM and 16-bit advanced PWM.
 */

#ifndef _UNISTC_PWM_PWM_H
#define _UNISTC_PWM_PWM_H

#if defined(PWM_GROUPS) && defined(PWM_CHANNELS) && PWM_GROUPS > 0 && PWM_CHANNELS > 0
	#if MCU_FAMILY == 15
		#include <uni-STC/pwm/pwm15.h>
		#define MCU_HAS_ENHANCED_PWM '5'
	#elif MCU_FAMILY == 8
		#if MCU_SERIES == 'H'
			#include <uni-STC/pwm/pwm8h.h>
			#define MCU_HAS_ADVANCED_PWM
			#define PWM_COUNTER_MAX 65535u

			// Bit mask for use with IP2L and IP2H
			#define M_PPWMA 0x04
			#define P_PPWMA 2

			#define M_PPWMB 0x08
			#define P_PPWMB 3
			
			// PWM A interrupt
			#define PWMA_INTERRUPT 26
			#define PWMA_VECTOR_ADDR 0x00D3

			// PWM B interrupt
			#define PWMB_INTERRUPT 27
			#define PWMB_VECTOR_ADDR 0x00DB
		#elif MCU_SERIES == 'G' || defined(STC8A8KxxD4)
			#include <uni-STC/pwm/pwm8g.h>
			#define MCU_HAS_ENHANCED_PWM 'G'
		#elif MCU_SERIES == 'A'
			#include <uni-STC/pwm/pwm8a.h>
			#define MCU_HAS_ENHANCED_PWM 'A'
		#endif // MCU_SERIES == 'H'
	#endif // MCU_FAMILY == 15

	#ifdef MCU_HAS_ENHANCED_PWM
		#define PWM_COUNTER_MAX 32767u
		
		// Bit mask for use with IP2L and IP2H
		#define M_PPWM0 0x04
		#define P_PPWM0 2
		
		#define M_PPWM0FD 0x08
		#define P_PPWM0FD 3
		
		#if PWM_GROUPS == 6
			// Bit mask for use with IP2L and IP2H
			#define M_PPWM2FD 0x80
			#define P_PPWM2FD 7
			
			// Bit mask for use with IP3L and IP3H
			#define M_PPWM1 0x04
			#define P_PPWM1 2
			
			#define M_PPWM2 0x08
			#define P_PPWM2 3
			
			#define M_PPWM3 0x10
			#define P_PPWM3 4
			
			#define M_PPWM4 0x20
			#define P_PPWM4 5
			
			#define M_PPWM5 0x40
			#define P_PPWM5 6
			
			#define M_PPWM4FD 0x80
			#define P_PPWM4FD 7
		#endif // PWM_GROUPS == 6

		// PWM group 0 interrupt
		#define PWM0_INTERRUPT 22
		#define PWM0_VECTOR_ADDR 0xB3
		
		// PWM group 0 fault detection interrupt
		#define PWM0FD_INTERRUPT 23
		#define PWM0FD_VECTOR_ADDR 0xBB
		
		#if PWM_GROUPS == 6
			// PWM group 1 interrupt
			#define PWM1_INTERRUPT 28
			#define PWM1_VECTOR_ADDR 0xE3
			
			// PWM group 2 interrupt
			#define PWM2_INTERRUPT 29
			#define PWM2_VECTOR_ADDR 0xEB
			
			// PWM group 3 interrupt
			#define PWM3_INTERRUPT 30
			#define PWM3_VECTOR_ADDR 0xF3
			
			// PWM group 4 interrupt
			#define PWM4_INTERRUPT 31
			#define PWM4_VECTOR_ADDR 0xFB
			
			// PWM group 5 interrupt (usage in C => see STC8G TRM appendix N)
			#define PWM5_INTERRUPT 32
			#define PWM5_VECTOR_ADDR 0x103
			
			// PWM group 2 fault detection interrupt (usage in C => see STC8G TRM appendix N)
			#define PWM2FD_INTERRUPT 33
			#define PWM2FD_VECTOR_ADDR 0x10B
			
			// PWM group 4 fault detection interrupt (usage in C => see STC8G TRM appendix N)
			#define PWM4FD_INTERRUPT 34
			#define PWM4FD_VECTOR_ADDR 0x113
		#endif // PWM_GROUPS == 6
	#endif // MCU_HAS_ENHANCED_PWM
#endif // defined(PWM_GROUPS) && defined(PWM_CHANNELS) && PWM_GROUPS > 0 && PWM_CHANNELS > 0

#endif // _UNISTC_PWM_PWM_H
