#include <stdio.h>
#include <stdbool.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void read_and_report(int fd) {
    char buf[100];

    printf("FD %d is reade to read\n", fd);
    int bytes = (int) read(fd, buf, 100);
    buf[bytes] = 0;
    printf("Get %d bytes from %d: %s\n", bytes, fd, buf);
}

int main() {

    int f1 = open("/tmp/f1.fifo", O_RDWR);
    int f2 = open("/tmp/f2.fifo", O_RDWR);

    if (!(f1 && f2)) {
        printf("Error during opening pipes\n");
        return 1;
    }

    printf("Descriptors %d %d\n", f1, f2);

    fd_set read_set;

    while (true) {
        FD_ZERO(&read_set);
        // Наблюдаем за f1 f2
        FD_SET(f1, &read_set);
        FD_SET(f2, &read_set);

        int result = select(f2 + 1, &read_set, NULL, NULL, NULL);

        if (result) {
            if (FD_ISSET(f1, &read_set)) {
                read_and_report(f1);
            }
            if (FD_ISSET(f2, &read_set)) {
                read_and_report(f1);
            }
        }
    }

    return 0;
}

