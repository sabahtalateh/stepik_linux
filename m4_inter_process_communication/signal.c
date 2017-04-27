#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

void sig_handler(int signo)
{
    printf("received sig %d\n", signo);
}

int main() {

    int c = 0;

    if (signal(SIGINT, sig_handler) == SIG_ERR) {
        printf("\ncan't catch SIGINT\n");
    }

    while (true) {
        printf("Hello %d\n", ++c);
        usleep(500000);
    }

    return 0;
}

