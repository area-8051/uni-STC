#include "project-defs.h"
#include "module-root.h"
#include "module-position.h"
#include "module-single.h"
#include "module-volume.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * LCD device definition.
 */
LCD_DEVICE_INTERFACE_NO_RESET(lcdDevice, NULL)
LCD_DEVICE_TEXT_ONLY(lcdDevice, 4, 20)

// If we didn't have to run on an MCS-51, we would use an array
// of structs containing pointers to functions instead of these
// switch statements. It would also help write nicer abstractions
// for LCD controllers and communication links.

static void module_initialise(ModuleId currentModule, LCDDevice *lcdDevice) {
	switch (currentModule) {
	case Module_Root:
		rootModule_initialise(lcdDevice);
		break;
	case Module_Position:
		positionModule_initialise(lcdDevice);
		break;
	case Module_SingleLine:
		singleModule_initialise(lcdDevice);
		break;
	case Module_Volume:
		volumeModule_initialise(lcdDevice);
		break;
	}
}

static void module_onMove(ModuleId currentModule, bool moveForward, bool withButtonPressed) {
	switch (currentModule) {
	case Module_Root:
		rootModule_onMove(moveForward, withButtonPressed);
		break;
	case Module_Position:
		positionModule_onMove(moveForward, withButtonPressed);
		break;
	case Module_SingleLine:
		singleModule_onMove(moveForward, withButtonPressed);
		break;
	case Module_Volume:
		volumeModule_onMove(moveForward, withButtonPressed);
		break;
	}
}

static ModuleId module_onAction(ModuleId currentModule, bool buttonPushed) {
	switch (currentModule) {
	case Module_Root:
		return rootModule_onAction(buttonPushed);
	case Module_Position:
		return positionModule_onAction(buttonPushed);
	case Module_SingleLine:
		return singleModule_onAction(buttonPushed);
	case Module_Volume:
		return volumeModule_onAction(buttonPushed);
	}
	
	return currentModule;
}

static void module_onIdle(ModuleId currentModule) {
	switch (currentModule) {
	case Module_Root:
		rootModule_onIdle();
		break;
	case Module_Position:
		positionModule_onIdle();
		break;
	case Module_SingleLine:
		singleModule_onIdle();
		break;
	case Module_Volume:
		volumeModule_onIdle();
		break;
	}
}

int main() {
	// Initialise LCD module -------------------------------------------
	lcdInitialiseDevice(&lcdDevice);
	lcdTxtInitialiseDisplayMode(&lcdDevice);
	
	// Initialise menu system ------------------------------------------
	ModuleId currentModule = Module_Root;
	ModuleId previousModule = currentModule;
	module_initialise(currentModule, &lcdDevice);

	while (1) {
		if (currentModule != previousModule) {
			previousModule = currentModule;
			module_initialise(currentModule, &lcdDevice);
		}
		
		module_onIdle(currentModule);
		
		// Let's simulate a rotary encoder.
		switch (fgetc(stdin)) {
		case 0x0d:
		case 0x20:
			// Encoder button pushed
			currentModule = module_onAction(currentModule, true);
			break;
			
		case '+':
		case 'm':
		case 'M':
			// Encoder rotated clockwise
			module_onMove(currentModule, true, false);
			break;
			
		case '-':
		case 'n':
		case 'N':
			// Encoder rotated counter-clockwise
			module_onMove(currentModule, false, false);
			break;
		
		case 0x1b:
			// Escape key = exit
			exit(0);
		}
	}
}
