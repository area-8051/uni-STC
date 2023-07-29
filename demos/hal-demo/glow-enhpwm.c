#include "project-defs.h"
#include "glow-enhpwm.h"
#include <enhpwm-hal.h>

#define PWM_COUNTER_VALUE 32767U

static const uint16_t PWM_GLOW_GRADIENT[] = {
	181, 342, 579, 907, 1340, 1893, 2579, 3415, 4414, 5590, 6960, 
	8536, 10334, 12368, 14653, 17204, 20034, 23159, 26594, 30352, 
};

#define PWM_GLOW_STEPS (sizeof(PWM_GLOW_GRADIENT) / sizeof(PWM_GLOW_GRADIENT[0]))

static int8_t pwmGlowStep = 0;
static int8_t pwmGlowIncrement = 1;

void pwmGlowUpdateDutyCycle() {
	pwmSetFlipPoints(PWM_GLOW_CHANNEL, 0, PWM_COUNTER_VALUE - PWM_GLOW_GRADIENT[pwmGlowStep]);
	
	int8_t newStep = pwmGlowStep + pwmGlowIncrement;
	
	if (newStep < 0 || newStep >= PWM_GLOW_STEPS) {
		pwmGlowIncrement = -pwmGlowIncrement;
	}
	
	pwmGlowStep += pwmGlowIncrement;
}

void pwmGlowInitialise() {
	pwmStartCounter(
		PWM_SYSCLK_DIV_7, 
		PWM_COUNTER_VALUE, 
		DISABLE_INTERRUPT
	);
	pwmConfigureOutput(
		PWM_GLOW_CHANNEL, 
		PWM_GLOW_PIN_CONFIG, 
		GPIO_BIDIRECTIONAL_MODE
	);
	pwmStartChannel(
		PWM_GLOW_CHANNEL, 
		OUTPUT_LOW, 
		PWM_INTERRUPT_EVENT_NONE, 
		0,
		PWM_COUNTER_VALUE - PWM_GLOW_GRADIENT[0]
	);
}
