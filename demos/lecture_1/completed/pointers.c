#include <stdio.h>

int main(void) {
    int number = 5;
    int *number_ptr = &number;

    printf("number is: %d\n", number);
    printf("number_ptr stores: %d\n", *number_ptr);
    printf("number_ptr is: %p\n", number_ptr);

    //A. We can either change the value stored in number_ptr
    *number_ptr = 6;

    printf("number is: %d\n", number);
    printf("number_ptr stores: %d\n", *number_ptr);
    printf("number_ptr is: %p\n", number_ptr);

    number = 10;
    //B. Or we can change the value of number

    printf("number is: %d\n", number);
    printf("number_ptr stores: %d\n", *number_ptr);
    printf("number_ptr is: %p\n", number_ptr);

    //A and B do the same thing, just in different ways
}