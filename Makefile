# octopus/Makefile
#
# Copyright (C) 2021, Charles Chiou

CC = 		gcc
CFLAGS =	-g -O2 -Wall -Werror -I.
LDFLAGS =	-lssh

OBJS =		octopus.o serial.o server.o session.o

OBJS :=		$(foreach o,$(OBJS),build/$(o))

build/octopus: $(OBJS)
	@mkdir -p build
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) 

build/%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: run

run: build/octopus
	build/octopus

.PHONY: clean distclean

clean:
	rm -f build/*.*

distclean:
	rm -rf build
