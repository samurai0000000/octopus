/*
 * octupus/octupus.c
 *
 * Copyright (C) 2021, Charles Chiou
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <octupus.h>

static const struct option long_options[] = {
	{ "logfile", required_argument, NULL, 'l', },
	{ "port", required_argument, NULL, 'p', },
	{ "device", required_argument, NULL, 'd', },
	{ 0, 0, 0, 0, },
};

static void cleanup(void)
{

}

int main(int argc, char **argv)
{
	int ret = 0;
	const char *logfile = NULL;
	int port = OCTUPUS_DEFAULT_PORT;

	atexit(cleanup);

	while (1) {
		int option_index = 0;
		int c = getopt_long(argc, argv, "l:p:d:",
				    long_options, &option_index);
		if (c == -1)
			break;
		switch (c) {
		case 'l':
			logfile = optarg;
			break;
		case 'p':
			port = atoi(optarg);
			break;
		case 'd':
			break;
		default:
			break;
		}
	}

	(void)(logfile);
	(void)(port);

	return ret;
}
