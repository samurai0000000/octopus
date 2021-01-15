/*
 * octopus/octopus.h
 *
 * Copyright (C) 2021, Charles Chiou
 */

#ifndef OCTOPUS_H
#define OCTOPUS_H

#define OCTOPUS_DEFAULT_PORT	49777
#define OCTOPUS_MAX_SERIALS	128

extern int octopus_serial_init(void);
extern int octopus_serial_cleanup(void);
extern int octopus_serial_attach(const char *device);
extern int octopus_serial_detach(const char *device);
extern int octopus_server_start_control(int port);
extern int octopus_server_start_serial(int port, const char *device);
extern int octopus_server_stop(void);
extern int octopus_session_start(int sock, const char *device);
extern int octopus_session_stop(int sock, const char *device);

#endif
