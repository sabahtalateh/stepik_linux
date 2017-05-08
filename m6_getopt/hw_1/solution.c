#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int c, char **v) {

    extern int opterr;
    opterr = 0;

    int opchar = 0;
    int opindex = 0;
    bool has_wrong = false;
    char *query = '\0';
    int optc = 0;

    int i = 0;
    while (true) {
        if (v[i] == NULL) break;
        printf("%s ", v[i]);
        i++;
    }

    printf("\n");

    struct option opts[] = {
            {"version",                no_argument,       0, 'v'},
            {"longinformationrequest", no_argument,       0, 'i'},
            {"query",                  required_argument, 0, 'q'},
            {0, 0,                                        0, 0}
    };

    while (-1 != (opchar = getopt_long(c, v, "viq:", opts, &opindex))) {
        switch (opchar) {

            case 'v':
//                printf("Version: 0.1\n");
                optc++;
                break;

            case 'i':
//                printf("Ohh I'm tired of you\n");
                optc++;
                break;

            case 'q':
//                printf("query=%s\n", optarg);
                optc++;
                break;

            default:
                has_wrong = true;
//                printf("opchar: %c\n", opchar);
                break;
        }
    }

    if (has_wrong) {
        printf("-\n");
//    } else if (optc == 0 && c > 1) {
//        printf("-\n");
    } else {
        printf("+\n");
    }

}
