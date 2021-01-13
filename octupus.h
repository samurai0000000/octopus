/*
 * octupus/octupus.h
 *
 * Copyright (C) 2021, Charles Chiou
 */

#ifndef OCTUPUS_H
#define OCTUPUS_H

#define OCTUPUS_DEFAULT_PORT	49777

extern int octupus_serial_attach(const char *device);
extern int octupus_serial_detach(const char *device);
extern int octupus_server_start_control(int port);
extern int octupus_server_start_serial(int port, const char *device);
extern int octupus_server_stop(void);
extern int octupus_session_start(int sock, const char *device);
extern int octupus_session_stop(int sock, const char *device);

#endif
