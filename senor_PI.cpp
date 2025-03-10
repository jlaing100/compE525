#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>

int main() {
    int fd = open("/dev/ttyACM0", O_RDONLY);
    if (fd < 0) {
        std::cerr << "Failed to open serial port\n";
        return 1;
    }

    struct pollfd pfd;
    pfd.fd = fd;
    pfd.events = POLLIN;

    char buffer[256];

    while (true) {
        int ret = poll(&pfd, 1, -1);  // waits indefinitely
        if (ret > 0 && (pfd.revents & POLLIN)) {
            ssize_t len = read(fd, buffer, sizeof(buffer)-1);
            if (len > 0) {
                buffer[len] = '\0';
                std::cout << "Voltage received from Arduino: " << buffer;
            }
        }
    }

    close(fd);
    return 0;
}
