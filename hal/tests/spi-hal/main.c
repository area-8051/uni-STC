/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Copyright (c) 2023 Vincent DEFERT. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "project-defs.h"
#include <stdio.h>

static uint32_t mcuFreqs[] = {
	24000000L,
	28000000L,
	30000000L,
	35000000L,
	36000000L,
	38000000L,
	40000000L,
	45000000L,
};

static uint32_t maxDeviceRates[] = {
	2500000L,
	4000000L,
	10000000L,
	12500000L,
	20000000L,
};

static uint8_t expectedDivisor[][5] = {
	{ 10,  6, 3, 2, 2, },
	{ 12,  7, 3, 3, 2, },
	{ 12,  8, 3, 3, 2, },
	{ 14,  9, 4, 3, 2, },
	{ 15,  9, 4, 3, 2, },
	{ 16, 10, 4, 4, 2, },
	{ 16, 10, 4, 4, 2, },
	{ 18, 12, 5, 4, 3, },
};

static uint8_t expectedPot[][5] = {
	{ 4, 3, 2, 1, 1, },
	{ 4, 3, 2, 2, 1, },
	{ 4, 3, 2, 2, 1, },
	{ 4, 4, 2, 2, 1, },
	{ 4, 4, 2, 2, 1, },
	{ 4, 4, 2, 2, 1, },
	{ 4, 4, 2, 2, 1, },
	{ 5, 4, 3, 2, 2, },
};

int main() {
	bool runAll = true;
	bool pass = true;
	
	for (int f = 0; f < (sizeof(mcuFreqs) / sizeof(mcuFreqs[0])); f++) {
		for (int r = 0; r < (sizeof(maxDeviceRates) / sizeof(maxDeviceRates[0])); r++) {
			uint32_t mcuFreq = mcuFreqs[f];
			uint32_t maxDeviceRate = maxDeviceRates[r];
			
			// <tested code>
			
			uint16_t divisor = (uint16_t) (mcuFreq / maxDeviceRate);
			
			if (mcuFreq % maxDeviceRate) {
				divisor++;
			}
			
			uint8_t pot = 0;
			
			// Determine the power of two ("pot") equal or immediately greater
			// to the value of the divisor.
			for (uint16_t n = divisor; n > 1; n = n >> 1, pot++);
			
			if (divisor > (1 << pot)) {
				pot++;
			}
			
			// </tested code>
			
			if (divisor != expectedDivisor[f][r] || pot != expectedPot[f][r]) {
				printf("FAILED: mcuFreq = %lu, deviceRate = %lu => exp.divisor = %u, actual %u, exp. pot = %hhu, actual %hhu\n",
					mcuFreq, maxDeviceRate, expectedDivisor[f][r], divisor, expectedPot[f][r], pot);
				pass = false;
				
				if (!runAll) {
					goto end;
				}
			}
		}
	}
	
end:
	if (pass) {
		printf("PASSED\n");
	}
}
