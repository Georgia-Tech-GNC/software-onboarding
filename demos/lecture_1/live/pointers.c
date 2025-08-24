#include <stdio.h>

int main(void) {
    int number = 5;
    int *number_ptr = &number;

    printf("number is: %d\n", number);
    printf("number_ptr stores: %d\n", *number_ptr);
    printf("number_ptr is: %p\n", number_ptr);
}