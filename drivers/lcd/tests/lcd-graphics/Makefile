# SPDX-License-Identifier: BSD-2-Clause
# 
# Copyright (c) 2023 Vincent DEFERT. All rights reserved.
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

PROJECT_NAME = lcd-graphics-test

SRCS = \
	../../lcd-device.c \
	../../lcd-graphics.c \
	../../lcd-interface.c \
	../../links/lcd-link-dummy.c \
	gpio-hal-mock.c \
	lcd-controller-mock.c \
	main.c

CC = gcc
# The -O2 option is REQUIRED for the 'inline' keyword to work as expected.
CFLAGS = -I. -I../../.. -I../../../../hal -I../../../../include -O2

test: $(PROJECT_NAME)
	@./$(PROJECT_NAME)
	@rm $(PROJECT_NAME)

$(PROJECT_NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^
