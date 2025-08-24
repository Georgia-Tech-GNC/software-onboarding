#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //Get the length of the array. Don't worry about scanf
    int length = 0;
    printf("Enter the length of array: ");
    scanf("%d", &length);

    /* malloc takes the number of bytes to allocate as a parameter, 
        so we must multiply the number of ints by the size of an int in bytes*/
    int *array = (int *) malloc(length * sizeof(int));

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
