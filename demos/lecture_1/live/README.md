**DEMO INSTRUCTIONS**

***hello_world.c***
1. Print "Hello, World!" on a new line

***datatypes.c***
1. For each primitive datatype in the file, print out its value using the appropriate printf format.
2. For the const value, show that attempting to modify a const value will generate a compile error.
3. For the string value, show how we can access single characters.
4. For the struct value, show how we can the primitive values in the struct.

***functions.c***
1. Implement the "add" function and call it from main
2. Implement the "subtract" function using "add" but DO NOT include the function prototype yet
3. Add the function prototype to fix the implicit function declaration

***pointers.c***
1. Run the program to show what the value of number is, the value stored in the pointer to number, and the value of the pointer itself.
2. Modify the value in number_ptr using dereferencing and show that it is reflected in number.
3. Modify the value in number and show that it is reflected in number_ptr.
4. Highlight the fact that the value of the pointer itself never changed in the demo, only the value that it points to.

***pass_by_value.c***
1. Attempt to implement the plus_one function by writing num = num + 1

***pass_by_reference.c***
1. Fix the implementation of plus_one by using pointers and dereferencing

***dangerous_pointers.c***
1. Show that returning a dangling pointer is undefined behavior by calling the dangerous_function again with a different value. The value in the original pointer returned by the first call should now be that new value.
2. Attempt to dereference a null pointer.
3. Attempt to dereference a pointer to a random memory address.

***malloc_free.c***
1. Implement line 10 using malloc after explaining why we cannot know the size of the array at compile-time

***multiple_files***
1. Implement the library function my_library that takes in a value param and returns param * 2
2. Define the PARAM_VALUE macro in lib.h