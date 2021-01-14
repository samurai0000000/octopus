/*
 * octopus/octopus.c
 *
 * Copyright (C) 2021, Charles Chiou
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <libssh/server.h>
#include <octopus.h>

static const struct option long_options[] = {
	{ "logfile", required_argument, NULL, 'l', },
	{ "port", required_argument, NULL, 'p', },
	{ "device", required_argument, NULL, 'd', },
	{ 0, 0, 0, 0, },
};

static void cleanup(void)
{
	octopus_server_stop();
	fclose(stdout);
}

int main(int argc, char **argv)
{
	int ret = 0;
	const char *logfile = NULL;
	int port = OCTOPUS_DEFAULT_PORT;

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

	if (port <= 0 || port > 65535) {
		fprintf(stderr, "invalid port %d!\n", port);
		exit(EXIT_FAILURE);
	}

	ret = ssh_init();
	if (ret != 0) {
		fprintf(stderr, "ssh_init() failed!\n");
		exit(EXIT_FAILURE);
	}

	if (logfile) {
		FILE *lf = fopen(logfile, "a");
		if (lf == NULL) {
			fprintf(stderr, "error opening logile '%s'!", logfile);
			exit(EXIT_FAILURE);
		}
		stdout = lf;
		stderr = lf;
	}

	ret = octopus_server_start_control(port);
	if (ret != 0) {
		exit(EXIT_FAILURE);
	}

	return ret;
}
