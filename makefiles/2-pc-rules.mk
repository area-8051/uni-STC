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

$(OBJDIR_TREE):
	@mkdir -p $@

$(DEP_FILE): $(OBJDIR)
	$(CC) $(CFLAGS) -MM -MF - $(SRCS) > $(DEP_FILE)
	@sed -i "s/^\(.*\.o:.*\)/$(BUILD_ROOT)\/$(BUILD_DIR)\/\1/g" $(DEP_FILE)

$(FW_FILE): $(DRIVER_OBJS) $(HAL_OBJS) $(LOCAL_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(DRIVER_OBJS): $(OBJDIR_TREE)
	$(CC) $(CFLAGS) -o $@ -c $(subst $(OBJDIR),$(DRIVER_DIR),$(subst .o,.c,$@))

$(HAL_OBJS): $(OBJDIR_TREE)
	$(CC) $(CFLAGS) -o $@ -c $(subst $(OBJDIR),$(HAL_DIR),$(subst .o,.c,$@))

$(LOCAL_OBJS): $(OBJDIR_TREE)
	$(CC) $(CFLAGS) -o $@ -c $(subst $(OBJDIR)/,,$(subst .o,.c,$@))
