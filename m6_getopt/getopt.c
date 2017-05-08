#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

int main(int c, char **v) {

    int is_brackets = 0;
    int opchar = 0;
    int opindex = 0;
    int length = 0;

    char string[] = "Und wenn du lange in einen Abgrund blickst, blickt der Abgrund auch in dich hinein";

    struct option opts[] = {
            // flag, значение записывается в переменную is_brackets, 1 - будет записано в is_brackets если
            // есть опция brackets или её сокращённые варианты
            {"brackets",                  no_argument,       &is_brackets, 1},

            // option
            {"length",                    required_argument, 0,            'l'},

            // longname option
            {"authornameshouldbeprinted", no_argument,       0,            'a'},

            // Конец нашео массива
            {0, 0,                                           0,            0}
    };

    while (-1 != (opchar = getopt_long(c, v, "bl:aq", opts, &opindex))) {
        switch (opchar) {
            case 0:
                printf("0\n");
                break;

            case 'l':
                length = atoi(optarg);
                printf("length=%d\n", length);
                break;

            case 'a':
                printf("Friedrich Nietzsche (c)\n");
                break;

            default:
                printf("opchar: %c\n", opchar);
                break;
        }
    }

    if (strlen(string) > length && 0 != length) {
        string[length] = '\0';
    }

    if (is_brackets) {
        printf("[%s]\n", string);
    } else {
        printf("%s\n", string);
    }

    printf("Done.\n");

    return 0;
}