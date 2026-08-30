// These two lines are called a header guard - they stop the compiler from 
// doing weird things when we include the same file twice.
// For now, don't worry too much about what this does -- it won't 
// affect your solution at all
#ifndef STUDENT_H
#define STUDENT_H

// Here we define a macro representing the maximum length of a student's name.
#define MAX_NAME_LEN 20

// "Importing" stdint.h allows us to use types like uint8_t (an 8 bit unsigned integer).
#include "stdint.h"

// "Importing" stddef.h allows us to use the size_t type, which is guaranteed to 
// fit any valid size (in number of bytes) in memory. The size_t type is also
// guaranteed to always be positive.
#include "stddef.h"

// "Importing" string.h provides access to the memcpy function, which is useful for 
// dealing with strings.
#include "string.h"

#include "stdbool.h"

/**
 * A simple struct reprenting a student.
 * Each student has a name, age, and grade.
 * 
 * Note that the name is stored as an array of MAX_NAME_LEN + 1 characters. 
 * This is because C needs to know the size of a struct in advance if we
 * want to avoid having to use malloc and free.
 * 
 * If the student's name is less than MAX_NAME_LEN, the remaining characters in 
 * the array will simply be left uninitialized.
 * 
 * We add one to MAX_NAME_LEN in order to account for the null terminator charactor '\0',
 * which every string must end with.
 */
struct Student {
    char name[MAX_NAME_LEN + 1];
    uint8_t age;
    uint8_t grade;
};


/**
 * The first method you should implement.
 * This method takes 4 parameters.
 * 
 * @param Student   the pointer to the student you should modify.
 * @param name      the name the student should have
 * @param age       the age of the student    
 * @param grade     the grade of the student.
 * 
 * If the length of the name (not including the null terminator) is bigger 
 * than MAX_NAME_LEN, you should return false and do nothing.
 * 
 * If either student or name are NULL, you should
 * return false and do nothing.
 * 
 * Otherwise, set the age, grade, and name of the student pointer
 * to the provided values. Then return true.
 * 
 * HELPFUL HINTS:
 *  - In this case, the Student* points to a single student. Why do we
 *      need to use a pointer instead of passing the student directly?
 *      
 *  - The name is provided as a char pointer. This pointer points to the first 
 *      element of an array of characters.
 * 
 *  - A string always ends in a null terminator ('\0'). To figure out the length of
 *      the string, loop forward in the array until you get to the '\0'. There may
 *      also be a standard library method to do it for you.
 * 
 *  - For copying the name from the name parameter to student->name, 
 *      you may find the memcpy method useful. Note that the size parameter 
 *      of memcpy takes the number of bytes, not array elements. You can 
 *      use sizeof(char) to get the number of bytes in each char.
 * 
 *  - To set properties of a pointer, use the arrow syntax. For example, 
 *      student->age will get/set the age, student->name will get/set the name, 
 *      and so on.
 * 
 *  - When copying the name, don't forget to copy the null terminator as well.
 */
bool initialize_student(
    struct Student* student, 
    const char* name, 
    uint8_t age, 
    uint8_t grade
);

/**
 * Here is the second method you will implement
 * There are two parameter
 * @param students      an array of students
 * @param num_students  the number of students in the array
 * 
 * You should loop through this array and return the age of the oldest student.
 * If the array is empty, return 0.
 * 
 * HELPFUL HINTS:
 * 
 *  - Unlike the previous example, students is now an array--the pointer points
 *      to the first element in the array. Even though it is an array, 
 *      you can still use square brackets to access elements, like this: 
 *      students[0].name
 */
uint8_t get_oldest_student(const struct Student* students, size_t num_students);




// This line is the end of the header guard
#endif
