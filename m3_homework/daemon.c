#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    printf("%d\n", getpid());

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    daemon(0, 0);

    while (1) {}
}

