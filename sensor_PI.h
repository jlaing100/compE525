#ifndef SERIAL_READER_H
#define SERIAL_READER_H

#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <iostream>

int openSerial(const char* device);
void readSerialData(int fd);

#endif
