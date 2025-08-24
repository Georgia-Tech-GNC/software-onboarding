#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //Get the length of the array. Don't worry about scanf
    int length = 0;
    printf("Enter the length of array: ");
    scanf("%d", &length);

    int *array = /* How can we use malloc to create an array of N integers*/

    for (int i = 0; i < length; i ++) {
        //Get the next number. Don't worry about scanf;
        int num = 0;
        printf("Enter number: ");
        scanf("%d", &num);

        array[i] = num;
    }

    //Print the numbers back to the user
    printf("The numbers you entered are: ");

    for (int i = 0; i < length; i ++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    //Return the memory back to the operating system
    free(array);
}
