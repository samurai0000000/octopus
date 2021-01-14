# octopus/Makefile
#
# Copyright (C) 2021, Charles Chiou

CC = 		gcc
CFLAGS =	-g -O2 -Wall -Werror -I. -Ilibssh/include -Ibuild/libssh/include
LDFLAGS =	-Lbuild/libssh/lib -lssh

OBJS =		octopus.o serial.o server.o session.o

OBJS :=		$(foreach o,$(OBJS),build/$(o))

build/octopus: $(OBJS) build/libssh/lib/libssh.so
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) 

build/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

build/libssh/lib/libssh.so: build/libssh/Makefile
	$(MAKE) -C build/libssh

build/libssh/Makefile:
	@mkdir -p build/libssh
	cd build/libssh && cmake ../../libssh

.PHONY: run

run: build/octopus build/libssh/lib/libssh.so
	LD_LIBRARY_PATH=build/libssh/lib build/octopus

.PHONY: clean distclean

clean:
	rm -f build/*.*

distclean:
	rm -rf build
