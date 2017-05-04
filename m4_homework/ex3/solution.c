#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int sum_usr_1 = 0;
int sum_usr_2 = 0;

void sig_handler(int sig_no) {
    if (sig_no == SIGUSR1) {
        ++sum_usr_1;
    }

    if (sig_no == SIGUSR2) {
        ++sum_usr_2;
    }

    if (sig_no == SIGTERM) {
        printf("%d %d\n", sum_usr_1, sum_usr_2);
        exit(0);
    }
}

int main() {
    int c = 0;

    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    signal(SIGTERM, sig_handler);

    while (true) {
        usleep(500000);
    }
}