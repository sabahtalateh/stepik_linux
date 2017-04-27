#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;
    for (; i < atoi(argv[1]); ++i) {
        int t = rand();
        char str[15];
        sprintf(str, "%d", t);
        int j = 0;
        write(STDOUT_FILENO, str, 13);
    }

    return 0;
}
