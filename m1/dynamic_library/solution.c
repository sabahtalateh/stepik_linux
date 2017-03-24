//#include "solution.h"
#include <string.h>
#include <stddef.h>

int stringStat(const char *string, size_t multiplier, int *count) {
    int size = (int) strlen(string);

    *count += 1;

    return (int) (size * multiplier);
}

