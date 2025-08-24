#include <stdio.h>

void plus_one(int *num) {
    *num = *num + 1;
}

int main(void) {
    int num = 1;
    plus_one(&num);

    printf("Num is: %d\n", num);
}