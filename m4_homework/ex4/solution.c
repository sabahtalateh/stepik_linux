#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig_no) {
    if (sig_no == SIGURG) {
        exit(0);
    }
}

int main() {

    signal(SIGURG, sig_handler);

    printf("%d\n", getpid());

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    daemon(0, 0);

    while (1) {}
}