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

$(DEP_FILE):
	@mkdir -p $(OBJDIR)
	# SDCC's dependencies generation is buggy and doesn't match GCC's
	# documentation (which the SDCC manual says should apply), so we 
	# need to compensate for this.
	@for srcFile in $(LOCAL_SRCS); do $(CC) $(CPPFLAGS) -MM $${srcFile} >> $(DEP_FILE); done
	@sed -i "s/^\(.*\.rel:.*\)/build\/\1/g" $(DEP_FILE)
	# Create subdirectories as needed because SDCC can't do it.
	@for objFile in $(DRIVER_OBJS); do objPath="$${objFile%/*}"; if [ ! -d "$${objPath}" ]; then mkdir -p "$${objPath}"; fi; done
	@for objFile in $(HAL_OBJS); do objPath="$${objFile%/*}"; if [ ! -d "$${objPath}" ]; then mkdir -p "$${objPath}"; fi; done
	@for objFile in $(LOCAL_OBJS); do objPath="$${objFile%/*}"; if [ ! -d "$${objPath}" ]; then mkdir -p "$${objPath}"; fi; done

$(FW_FILE):	$(DRIVER_OBJS)	$(HAL_OBJS)	$(LOCAL_OBJS) $(DUAL_DPTR_SUPPORT)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJDIR)/crtxinit.rel:	$(HAL_DIR)/crtxinit.asm
	$(AS) $(ASFLAGS) $@ $<

$(DRIVER_OBJS):
	$(CC) $(CFLAGS) -o $@ -c $(patsubst %.rel, $(DRIVER_DIR)/%.c, $(shell srcDir="$(OBJDIR)";srcFile="$@";echo "$${srcFile#$$srcDir/}"))

$(HAL_OBJS):
	$(CC) $(CFLAGS) -o $@ -c $(patsubst %.rel, $(HAL_DIR)/%.c, $(shell srcDir="$(OBJDIR)";srcFile="$@";echo "$${srcFile#$$srcDir/}"))

$(LOCAL_OBJS):
	$(CC) $(CFLAGS) -o $@ -c $(patsubst %.rel, %.c, $(shell srcDir="$(OBJDIR)";srcFile="$@";echo "$${srcFile#$$srcDir/}"))
