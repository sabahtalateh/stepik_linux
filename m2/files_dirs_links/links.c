#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int c, const char **args) {
    char buf[100];
    size_t sz = 0;

    if (c != 2) {
        printf("\nPleas call\n\t%s filename\n", args[0]);
        return 1;
    }

    char *fname = (char *) args[1];

    // O_NOFOLLOW - не ходить по ссылкам, открывать как есть
    int fd = open(fname, O_RDONLY|O_NOFOLLOW);
    perror("fd");
    printf("fd=%d\n", fd);
    sz = read(fd, buf, 100);

    printf("sz=%ld\n", sz);
    printf("buf=%s\n", buf);

}