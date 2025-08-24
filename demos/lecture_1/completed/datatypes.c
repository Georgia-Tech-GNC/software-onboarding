#include <stdio.h>

struct MyStruct {
    float x;
    int y[2];
};

int main(void) {
    int a = 0;

    printf("The value of a is: %d\n", a);

    unsigned char b = 'a';

    printf("The value of b is: %c\n", b);

    const double c = 10.2;
    //c = 10; //this will not compile!
    printf("The value of c is: %f\n", c);

    char string[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    printf("String is: %s\n", string);
    printf("Second character of string is: %c\n", string[1]);

    struct MyStruct my_struct = {
        .x = 10.0,
        .y = {1, 2}
    };

    printf("My struct has values: %f, %d, %d\n", my_struct.x, my_struct.y[0], my_struct.y[1]);
}