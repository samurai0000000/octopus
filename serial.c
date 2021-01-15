/*
 * octopus/serial.c
 *
 * Copyright (C) 2021, Charles Chiou
 */
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <octopus.h>

struct octopus_serial {
	char device[64];
	int fd;
};

static struct octopus_serial ser[OCTOPUS_MAX_SERIALS];

int octopus_serial_init(void)
{
	for (int i = 0; i < OCTOPUS_MAX_SERIALS; i++) {
		ser[i].device[0] = '\0';
		ser[i].fd = -1;
	}

	return 0;
}

int octopus_serial_cleanup(void)
{
	int ret = 0;

	for (int i = 0; i < OCTOPUS_MAX_SERIALS; i++) {
		if (ser[i].fd >= 0) {
			if (close(ser[i].fd) != 0) {
				fprintf(stderr, "close(%d) failed!\n",
					ser[i].fd);
				ret -= 1;
			}
		}
		ser[i].fd = -1;
		ser[i].device[0] = '\0';
	}

	return ret;
}

int octopus_serial_attach(const char *device)
{
	return 0;
}

int octopus_serial_detach(const char *device)
{
	return 0;
}
