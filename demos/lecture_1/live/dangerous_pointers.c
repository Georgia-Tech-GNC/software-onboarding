#include <stdio.h>

int *dangerous_function(int x) {
    int number = x;
    return &number;
}

int main(void) {
    int *ptr = dangerous_function(5);
    printf("%d\n", *ptr);
}