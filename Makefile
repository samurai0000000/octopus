# octupus/Makefile
#
# Copyright (C) 2021, Charles Chiou

CC = 		gcc
CFLAGS =	-g -O2 -Wall -Werror -I.
LDFLAGS =	-Lbuild/libssh/lib -lssh

OBJS =		octupus.o serial.o server.o session.o

OBJS :=		$(foreach o,$(OBJS),build/$(o))

build/octopus: $(OBJS) build/libssh/lib/libssh.so
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

build/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

build/libssh/lib/libssh.so: build/libssh/Makefile
	$(MAKE) -C build/libssh

build/libssh/Makefile:
	@mkdir -p build/libssh
	cd build/libssh && cmake ../../libssh

.PHONY: clean distclean

clean:
	rm -f build/*.*

distclean:
	rm -rf build
