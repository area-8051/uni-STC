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
# - stcgal 
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
# Force rebuilding dependencies:
#   make depend
#
# Open serial console in new window:
#   make console
#
# Clean project (remove all build files):
#   make clean

# Project-specific settings --------------------------------------------

PROJECT_NAME = spi-demo

# Tested on STC8A8K64D4-45I-LQFP48

MCU_FREQ = 24000000
TARGET_ARCH = -mmcs51
MEMORY_MODEL = --model-large
MEMORY_SIZES = \
	--xram-loc 0 \
	--xram-size 8192 \
	--stack-size 128 \
	--code-size 65536

CONSOLE_BAUDRATE = 57600
CONSOLE_PORT = ttyUSB0

ISP_PORT = ttyUSB0

# TODO: change to your installation directory.
UNISTC_DIR = ../../include

SRCS = \
	delay.c \
	gpio-hal.c \
	spi-hal.c \
	serial-console.c \
	timer-hal.c \
	fifo-buffer.c \
	uart-hal.c \
	main.c

# Toolchain-specific settings ------------------------------------------

AS = sdas8051
CC = sdcc
ASFLAGS = -plosgffw
CFLAGS = -DMCU_FREQ=$(MCU_FREQ)UL $(TARGET_ARCH) $(MEMORY_MODEL) -I$(UNISTC_DIR)
LDFLAGS = $(TARGET_ARCH) $(MEMORY_MODEL) $(MEMORY_SIZES)

ifeq ($(BUILD_MODE),debug)
	CFLAGS += --debug
	BUILD_DIR = debug
else
	CFLAGS += --opt-code-speed
	BUILD_DIR = release
endif

BUILD_ROOT = build

OBJDIR = $(BUILD_ROOT)/$(BUILD_DIR)
FW_FILE = $(OBJDIR)/$(PROJECT_NAME).ihx
DEP_FILE = $(OBJDIR)/dependencies

OBJS = $(patsubst %.c, $(OBJDIR)/%.rel, $(SRCS))

# Rules ----------------------------------------------------------------

.PHONY: all clean doc upload console

all: $(DEP_FILE) $(FW_FILE)


clean:
	rm -rf $(BUILD_ROOT)

doc:
	doxygen doxygen.conf

upload:
	stcgal -a -p /dev/$(ISP_PORT) -t `echo "$(MCU_FREQ)" | rev | cut -c 4- | rev` $(FW_FILE)

console:
	mate-terminal -t "$(PROJECT_NAME) console" -e "minicom -b $(CONSOLE_BAUDRATE) -D /dev/$(CONSOLE_PORT)"

-include $(DEP_FILE)

$(DEP_FILE): $(SRCS)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -MM $< >> $(DEP_FILE)

$(FW_FILE):	$(OBJS) $(OBJDIR)/crtxinit.rel
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJDIR)/crtxinit.rel:	crtxinit.asm
	$(AS) $(ASFLAGS) $@ $<

$(OBJDIR)/%.rel:	%.c
	$(CC) $(CFLAGS) -o $@ -c $<
