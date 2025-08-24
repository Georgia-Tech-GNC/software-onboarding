#include <stdio.h>

int add(int a, int b); //if this isn't here, we will get an error/warning

int subtract(int a, int b) {
    return add(a, -b);
}

int add(int a, int b) {
    return a + b;
}

int main(void) {
    printf("%d\n", subtract(10, 2));
}