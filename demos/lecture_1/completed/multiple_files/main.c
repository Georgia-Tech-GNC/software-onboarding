#include <stdio.h>
#include "lib.h"

int main(void) {
    int value = my_library(PARAM_VALUE);

    printf("Value is: %d\n", value);
}