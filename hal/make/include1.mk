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

# Toolchain settings ---------------------------------------------------

TARGET_ARCH := -mmcs51

AS := sdas8051
CC := sdcc
ASFLAGS := -plosgffw
CPPFLAGS := $(PROJECT_FLAGS) -DMCU_FREQ=$(MCU_FREQ)UL -I. -I$(HAL_DIR) -I$(UNISTC_DIR)
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

HAL_SRCS := $(filter $(HAL_DIR)/%, $(SRCS))
LOCAL_SRCS := $(filter-out $(HAL_DIR)/%, $(SRCS))

HAL_OBJS := $(patsubst %.c, $(OBJDIR)/%.rel, $(shell for f in $(HAL_SRCS); do basename $$f; done))
LOCAL_OBJS := $(patsubst %.c, $(OBJDIR)/%.rel, $(shell for f in $(LOCAL_SRCS); do basename $$f; done))

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
