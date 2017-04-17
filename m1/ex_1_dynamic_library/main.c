#include "solution.c"
#include <stdio.h>

int main() {
    int  var = 20;   /* actual variable declaration */
    int  *ip;        /* pointer variable declaration */

    ip = &var;

    printf("%i\n", *ip);

    size_t size = 2;
    printf("%i\n", stringStat("", size, ip));

    printf("%i\n", *ip);
    return 0;
}