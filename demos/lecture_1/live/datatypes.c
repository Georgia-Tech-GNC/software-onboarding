#include <stdio.h>

struct MyStruct {
    float x;
    int y[2];
};

int main(void) {
    int a = 0;

    unsigned char b = 'a';

    const double c = 10.2;

    char string[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    struct MyStruct my_struct = {
        .x = 10.0,
        .y = {1, 2}
    };
}