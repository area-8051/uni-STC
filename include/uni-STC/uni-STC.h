/**
 * @file uni-STC/uni-STC.h
 * 
 * This file contains the definitions expected when compiling firmware
 * as well as unit tests (with GCC or clang).
 */

#ifndef _UNISTC_UNISTC_H
#define _UNISTC_UNISTC_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __SDCC
	#define CRITICAL __critical
	#define REENTRANT __reentrant
	#define USING(registerBank) __using(registerBank)
	// With SDCC, we always optimise (generally for size), so no problem.
	#define INLINE inline
#else
	#define CRITICAL
	#define REENTRANT
	#define USING(registerBank)
	#define INTERRUPT(name, vector) void name()
	#define INTERRUPT_USING(name, vector, regnum) void name()
	// GCC & CLANG never inline functions unless optimisation is requested, 
	// which is not the case by default, so we need to insist a little bit.
	#define INLINE inline __attribute__((always_inline))
	#define __data
	#define __idata
	#define __pdata
	#define __xdata
	#define __code
#endif // __SDCC

#ifdef COOPERATIVE_MULTITASKING
	/**
	 * Simple cooperative multitasking support: long-running tasks
	 * should call yield() whenever it's possible and safe for them to
	 * stop their work - which they should do if yield() returns true.
	 * 
	 * The yield() function must be implemented in the C module where
	 * the super loop is defined.
	 */
	bool yield();
#else
	// This trick allows the same code to work with or without
	// cooperative multitasking support.
	#define yield() false
#endif

#endif // _UNISTC_UNISTC_H
