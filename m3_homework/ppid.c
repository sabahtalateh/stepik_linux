#include <regex.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[150];
    FILE *fp;

    sprintf(str, "/proc/%d/status", getpid());

    fp = fopen(str, "r");

    while (fgets(str, 150, fp)) {
        if (strstr(str, "PPid")) {
            int i = 0;
            for (; i < strlen(str); i++) {
                if (isdigit(str[i])) {
                    printf("%c", str[i]);
                }
            }
        }
    }
    fclose(fp);

    printf("\n");

    return 0;
}

