#include <stdio.h>
#include <stdbool.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int read_and_put(int fd, int *sum) {
    char buf[100];
    int bytes = read(fd, buf, 100);
    buf[bytes] = 0;
    *sum += atoi(buf);
    return bytes;
}

int main() {
    int f1 = open("./in1", O_RDWR);
    int f2 = open("./in2", O_RDWR);

    if (!(f1 && f2)) {
        printf("Error. No fifo");
        return 1;
    }

    fd_set read_set;
    int sum = 0;

    struct timeval tv;
    tv.tv_sec = 4;
    tv.tv_usec = 700000;

    int f1_bytes;
    int f2_bytes;

    while (true) {
        FD_ZERO(&read_set);
        FD_SET(f1, &read_set);
        FD_SET(f2, &read_set);

        int result = select(f2 + 1, &read_set, NULL, NULL, &tv);

        if (result) {
            if (FD_ISSET(f1, &read_set)) {
                f1_bytes = read_and_put(f1, &sum);
            }
            if (FD_ISSET(f2, &read_set)) {
                f2_bytes = read_and_put(f2, &sum);
            }
        }

        if ((result == 0) || (!(f1_bytes || f2_bytes))) {
            break;
        }
    }
    printf("%d\n", sum);

    return 0;
}
