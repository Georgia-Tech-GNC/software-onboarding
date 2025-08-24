#include <stdio.h>

int *dangerous_function(int x) {
    int number = x;
    return &number;
}

int main(void) {
    int *ptr = dangerous_function(5);
    dangerous_function(7);

    printf("%d\n", *ptr); //We would expect ptr to be 5, but it is actually 7 :O

    int *null_ptr = (int *) 0;
    //printf("%d\n", *null_ptr); //Segmentation fault

    int *random_ptr = (int *) 0xAFC12AB49;
    //printf("%d\n", *random_ptr); //Segmentation fault
}