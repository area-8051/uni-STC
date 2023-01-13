# SPDX-License-Identifier: BSD-2-Clause
# 
# Copyright (c) 2022 Vincent DEFERT. All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without 
# modification, are permitted provided that the following conditions 
# are met:
# 
# 1. Redistributions of source code must retain the above copyright 
# notice, this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright 
# notice, this list of conditions and the following disclaimer in the 
# documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
# POSSIBILITY OF SUCH DAMAGE.

# Prerequisites --------------------------------------------------------
#
# Besides make, his project requires: 
#
# - sdcc
# - stcgal-patched
# - minicom
# - doxygen

# Usage ----------------------------------------------------------------
#
# Build executable in release mode:
#   make
#
# Build executable in debug mode:
#   make BUILD_MODE=debug
#
# Build documentation:
#   make doc
#
# Upload executable to MCU:
#   make upload
#
# Open serial console in new window:
#   make console
#
# Clean project (remove all build files):
#   make clean

# Target MCU settings --------------------------------------------------

# Note: using a system clock around 24MHz works with all MCU
# having an internal RC oscillator.
MCU_FREQ_KHZ := 23961

STACK_SIZE := 112

# Tested on STC8G1K08-38I-TSSOP20

MEMORY_SIZES := \
	--xram-loc 0 \
	--xram-size 1024 \
	--stack-size $(STACK_SIZE) \
	--code-size 8192

MEMORY_MODEL := --model-medium

HAS_DUAL_DPTR := y

# Define UNISTC_DIR, HAL_DIR, DRIVER_DIR, and MAKE_DIR -----------------
include ../../makefiles/0-directories.mk

# Project settings -----------------------------------------------------
PROJECT_NAME := hal-demo

PROJECT_FLAGS = -DBUILD_FOR_STC8G1K08_TSSOP20

SRCS := \
	$(HAL_DIR)/delay.c \
	$(HAL_DIR)/fifo-buffer.c \
	$(HAL_DIR)/gpio-hal.c \
	$(HAL_DIR)/pca-hal.c \
	$(HAL_DIR)/serial-console.c \
	$(HAL_DIR)/timer-hal.c \
	$(HAL_DIR)/uart-hal.c \
	main.c

CONSOLE_BAUDRATE := 57600
CONSOLE_PORT := /dev/ttyUSB0

ISP_PORT := /dev/ttyUSB0

# Default is -a, override here if you have specific needs.
# STCGAL_OPTIONS := -A rts -a

# Boilerplate rules ----------------------------------------------------
include $(MAKE_DIR)/1-mcu-settings.mk
-include $(DEP_FILE)
include $(MAKE_DIR)/2-mcu-rules.mk
