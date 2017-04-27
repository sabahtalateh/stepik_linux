#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    pid_t c_pid;
    char buf;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    c_pid = fork();
    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (c_pid == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execl(argv[1], argv[1], argv[2], (char *) NULL);
        exit(0);
    } else {
        close(pipefd[1]);
        int c = 0;

        while (read(pipefd[0], &buf, 1) > 0) {
            if (buf == '0') {
                ++c;
            }
        }
        waitpid(c_pid, 0, 0);
        printf("%d\n", c);
    }

    return 0;
}
