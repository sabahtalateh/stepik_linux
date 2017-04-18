#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("/root/stepik_linux/m2/l1_files/1.txt", O_RDONLY);

    char buf[4];
    size_t nbytes;
    ssize_t bytes_read;
    nbytes = sizeof(buf);

    while (1) {
        bytes_read = read(fd, buf, nbytes);
        printf("%s", buf);

        if (bytes_read <= 0) {
            printf("\n");
            break;
        }
    }

    close(fd);

    return 0;
}