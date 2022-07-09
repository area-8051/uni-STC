/**
 * @file uni-STC/testing.h
 * 
 * The __TESTING__ macro must be defined when compiling unit tests 
 * with GCC.
 * 
 * The macros below are for use in header files in order to avoid 
 * build errors when GCC comes across an SDCC-specific keyword.
 */

#ifndef _UNISTC_TESTING_H
#define _UNISTC_TESTING_H

#ifdef __TESTING__
	#define CRITICAL /**/
	#define REENTRANT /**/
	#define USE_BANK(registerBank) /**/
	#define INTERRUPT_USING(name, vector, regnum) void name()
	// GCC & CLANG never inline functions unless optimisation is requested, 
	// which is not the case by default, so we need to insist a little bit.
	#define INLINE inline __attribute__((always_inline))
#else
	#define CRITICAL __critical
	#define REENTRANT __reentrant
	#define USE_BANK(registerBank) __using(registerBank)
	// With SDCC, we always optimise (generally for size), so no problem.
	#define INLINE inline
#endif // __TESTING__

#endif // _UNISTC_TESTING_H
