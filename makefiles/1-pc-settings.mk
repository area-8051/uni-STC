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

ifeq ($(DRIVER_DIR),)
	$(error The DRIVER_DIR variable must be defined.)
endif

ifeq ($(HAL_DIR),)
	$(error The HAL_DIR variable must be defined.)
endif

ifeq ($(UNISTC_DIR),)
	$(error The UNISTC_DIR variable must be defined.)
endif

ifeq ($(BUILD_ROOT),)
	BUILD_ROOT := build
endif

# Toolchain settings ---------------------------------------------------

CC := cc
CFLAGS := $(PROJECT_FLAGS) -I. -I$(HAL_DIR) -I$(UNISTC_DIR) -I$(DRIVER_DIR) -Wall
LDFLAGS := 

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
	BUILD_DIR := debug
else
	CFLAGS += -O2
	BUILD_DIR := release
endif

OBJDIR := $(BUILD_ROOT)/$(BUILD_DIR)

FW_FILE := $(OBJDIR)/$(PROJECT_NAME)
DEP_FILE := $(OBJDIR)/dependencies.mk

DRIVER_SRCS := $(filter $(DRIVER_DIR)%, $(SRCS))
HAL_SRCS := $(filter $(HAL_DIR)%, $(SRCS))
LOCAL_SRCS := $(filter-out $(DRIVER_DIR)%, $(filter-out $(HAL_DIR)%, $(SRCS)))

DRIVER_OBJS := $(subst $(DRIVER_DIR),$(OBJDIR),$(subst .c,.o,$(DRIVER_SRCS)))
HAL_OBJS := $(subst $(HAL_DIR),$(OBJDIR),$(subst .c,.o,$(HAL_SRCS)))
LOCAL_OBJS := $(addprefix $(OBJDIR)/,$(subst .c,.o,$(LOCAL_SRCS)))

OBJDIR_TREE := $(sort $(dir $(DRIVER_OBJS) $(HAL_OBJS) $(LOCAL_OBJS)))

# Rules ----------------------------------------------------------------

.PHONY: all clean

all: $(DEP_FILE) $(FW_FILE)

doc:
	doxygen $(MAKE_DIR)/doxygen.conf

run: $(FW_FILE)
	@$(FW_FILE)

clean:
	@rm -rf $(BUILD_ROOT)

