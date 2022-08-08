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

# Consistency checks ---------------------------------------------------

ifeq ($(PROJECT_NAME),)
	$(error The PROJECT_NAME variable must be defined.)
endif

ifeq ($(MCU_FREQ),)
	$(error The MCU_FREQ variable must be defined.)
endif

ifeq ($(HAS_DUAL_DPTR),)
	$(error The HAS_DUAL_DPTR variable must be defined.)
endif

ifeq ($(MEMORY_MODEL),)
	$(error The MEMORY_MODEL variable must be defined.)
endif

ifeq ($(MEMORY_SIZES),)
	$(error The MEMORY_SIZES variable must be defined.)
endif

ifeq ($(DRIVER_DIR),)
	$(error The DRIVER_DIR variable must be defined.)
endif

ifeq ($(HAL_DIR),)
	$(error The HAL_DIR variable must be defined.)
endif

ifeq ($(UNISTC_DIR),)
	$(error The UNISTC_DIR variable must be defined.)
endif

ifeq ($(ISP_PORT),)
	$(error The ISP_PORT variable must be defined.)
endif

ifeq ($(CONSOLE_PORT),)
	$(warning The CONSOLE_PORT variable is undefined, defaulting to $(ISP_PORT).)
	CONSOLE_PORT := $(ISP_PORT)
endif

ifeq ($(CONSOLE_BAUDRATE),)
	$(warning The CONSOLE_BAUDRATE variable is undefined, defaulting to 115200.)
	CONSOLE_BAUDRATE := 115200
endif

# Toolchain settings ---------------------------------------------------

TARGET_ARCH := -mmcs51

AS := sdas8051
CC := sdcc
ASFLAGS := -plosgffw
CPPFLAGS := $(PROJECT_FLAGS) -DMCU_FREQ=$(MCU_FREQ)UL -I. -I$(HAL_DIR) -I$(UNISTC_DIR) -I$(DRIVER_DIR)
CFLAGS := $(TARGET_ARCH) $(MEMORY_MODEL) $(CPPFLAGS)
LDFLAGS := $(TARGET_ARCH) $(MEMORY_MODEL) $(MEMORY_SIZES)

ifeq ($(BUILD_MODE),debug)
	CFLAGS += --debug
	BUILD_DIR := debug
else
	CFLAGS += --opt-code-size
	BUILD_DIR := release
endif

BUILD_ROOT := build

# Because we can't use debug mode, the extra directory level is useless.
# OBJDIR := $(BUILD_ROOT)/$(BUILD_DIR)
OBJDIR := $(BUILD_ROOT)

FW_FILE := $(OBJDIR)/$(PROJECT_NAME).ihx
DEP_FILE := $(OBJDIR)/dependencies

DRIVER_SRCS := $(filter $(DRIVER_DIR)/%, $(SRCS))
HAL_SRCS := $(filter $(HAL_DIR)/%, $(SRCS))
LOCAL_SRCS := $(filter-out $(DRIVER_DIR)/%, $(filter-out $(HAL_DIR)/%, $(SRCS)))

DRIVER_OBJS := $(patsubst %.c, $(OBJDIR)/%.rel, $(shell srcDir="$(DRIVER_DIR)";for srcFile in $(DRIVER_SRCS); do echo "$${srcFile#$$srcDir/}"; done))
HAL_OBJS := $(patsubst %.c, $(OBJDIR)/%.rel, $(shell srcDir="$(HAL_DIR)";for srcFile in $(HAL_SRCS); do echo "$${srcFile#$$srcDir/}"; done))
LOCAL_OBJS := $(patsubst %.c, $(OBJDIR)/%.rel, $(LOCAL_SRCS))

ifeq ($(HAS_DUAL_DPTR),y)
	DUAL_DPTR_SUPPORT := $(OBJDIR)/crtxinit.rel
else
	DUAL_DPTR_SUPPORT := 
endif

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
