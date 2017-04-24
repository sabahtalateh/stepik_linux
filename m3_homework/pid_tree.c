#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *get_ppid(char const *pid) {
    char *pid_status_file = malloc(150 * sizeof(char));
    sprintf(pid_status_file, "/proc/%s/status", pid);

    FILE *fd = fopen(pid_status_file, "r");

    char str[200];
    char *ppid = malloc(200 * sizeof(char));
    while (fgets(str, 150, fd)) {
        if (strstr(str, "PPid")) {
            int i = 0;
            for (; i < strlen(str); i++) {
                if (isdigit(str[i])) {
                    sprintf(ppid, "%s%c", ppid, str[i]);
                }
            }
        }
    }

    return ppid;
}

int main(int argc, char **argv) {
    char *pid = argv[1];
    printf("%s\n", pid);

    while (true) {
        char *ppid = get_ppid(pid);
        printf("%s\n", ppid);
        pid = ppid;

        if (strcmp(ppid, "1") == 0) {
            break;
        }
    }

    return 0;
}
