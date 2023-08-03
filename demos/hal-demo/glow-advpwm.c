#include "project-defs.h"
#include "glow-advpwm.h"
#include <advpwm-hal.h>

static const uint16_t PWM_GLOW_GRADIENT[] = {
	363, 684, 1159, 1814, 2680, 3785, 5159, 6830, 8827, 11181, 13919, 
	17072, 20668, 24736, 29306, 34407, 40069, 46319, 53187, 60703, 
};

#define PWM_GLOW_STEPS (sizeof(PWM_GLOW_GRADIENT) / sizeof(PWM_GLOW_GRADIENT[0]))

static int8_t pwmGlowStep = 0;
static int8_t pwmGlowIncrement = 1;

void pwmGlowUpdateDutyCycle() {
	pwmSetDutyCycle(PWM_GLOW_CHANNEL, PWM_GLOW_GRADIENT[pwmGlowStep]);
	
	int8_t newStep = pwmGlowStep + pwmGlowIncrement;
	
	if (newStep < 0 || newStep >= PWM_GLOW_STEPS) {
		pwmGlowIncrement = -pwmGlowIncrement;
	}
	
	pwmGlowStep += pwmGlowIncrement;
}

void pwmGlowInitialise() {
	pwmConfigureCounter(
		PWM_GLOW_COUNTER, 
		PWM_GLOW_SIGNAL_FREQ * 65535UL, 
		PWM_GLOW_SIGNAL_FREQ, 
		PWM_FREE_RUNNING, 
		PWM_NO_TRIGGER,
		0, 
		PWM_BUFFERED_UPDATE,
		PWM_CONTINUOUS,
		PWM_EDGE_ALIGNED_UP,
		PWM_DISABLE_ALL_UE,
		DISABLE_INTERRUPT
	);
	
	pwmInitialisePWM(
		PWM_Channel0, 
		OUTPUT_HIGH, 
		DISABLE_INTERRUPT, 
		PWM_IMMEDIATE_UPDATE,
		PWM_GLOW_GRADIENT[0]
	);
	
	pwmConfigureOutput(
		PWM_GLOW_CHANNEL, 
		PWM_GLOW_PIN_CONFIG, 
		GPIO_BIDIRECTIONAL_MODE,
		PWM_ACTIVE_LOW, 
		PWM_DISABLE_FAULT_CONTROL, 
		OUTPUT_HIGH,
		PWM_OUTPUT_P_ONLY
	);
	
	pwmEnableMainOutput(PWM_GLOW_COUNTER);
	pwmEnableCounter(PWM_GLOW_COUNTER);
}

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pwmOnCounterInterrupt(PWM_Counter counter, PWM_CounterInterrupt HAL_PWM_SEGMENT event) {
}

void pwmOnChannelInterrupt(PWM_Channel channel, uint16_t HAL_PWM_SEGMENT counterValue) {
}
