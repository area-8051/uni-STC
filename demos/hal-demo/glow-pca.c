#include "project-defs.h"
#include "glow-pca.h"
#include <timer-hal.h>
#include <pca-hal.h>

#define PCA_COUNTER_VALUE 255U

// Luminance as per CIELAB scaled to 256 (8-bit PWM)
static const uint8_t PCA_GLOW_GRADIENT[] = {
	1, 3, 5, 7, 10, 15, 20, 27, 34, 44, 54, 
	67, 81, 97, 114, 134, 157, 181, 208, 237,
};

#define PCA_GLOW_STEPS (sizeof(PCA_GLOW_GRADIENT) / sizeof(PCA_GLOW_GRADIENT[0]))

static int8_t pcaGlowStep = 0;
static int8_t pcaGlowIncrement = 1;

/*
 * @see pca.h
 */
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pcaOnInterrupt(PCA_Channel channel, uint16_t HAL_PCA_SEGMENT pulseLength) {
}

void pcaGlowUpdateDutyCycle() {
	pcaSetDutyCycle(PCA_GLOW_CHANNEL, PCA_COUNTER_VALUE - PCA_GLOW_GRADIENT[pcaGlowStep]);
	
	int8_t newStep = pcaGlowStep + pcaGlowIncrement;
	
	if (newStep < 0 || newStep >= PCA_GLOW_STEPS) {
		pcaGlowIncrement = -pcaGlowIncrement;
	}
	
	pcaGlowStep += pcaGlowIncrement;
}

void pcaGlowInitialise() {
	startTimer(
		TIMER0, 
		frequencyToSysclkDivisor(PCA_GLOW_COUNTER_FREQ), 
		DISABLE_OUTPUT, 
		DISABLE_INTERRUPT, 
		FREE_RUNNING
	);
	
	pcaStartCounter(
		PCA_TIMER0, 
		FREE_RUNNING, 
		DISABLE_INTERRUPT, 
		PCA_GLOW_PIN_CONFIG
	);
	pcaConfigureOutput(
		PCA_GLOW_CHANNEL, 
		GPIO_BIDIRECTIONAL_MODE
	);
	pcaStartPwm(
		PCA_GLOW_CHANNEL, 
		MAKE_PCA_PWM_BITS(PCA_GLOW_PWM_BITS), 
		PCA_EDGE_NONE, 
		PCA_COUNTER_VALUE - PCA_GLOW_GRADIENT[0]
	);
}
