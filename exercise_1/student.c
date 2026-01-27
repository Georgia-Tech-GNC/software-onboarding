// We include students.h to be able to access the macros and imports
// that we defined there.
#include "student.h"

// "Importing" stdio let's us use printf, which is helpful for debugging.
#include "stdio.h"

bool initialize_student(struct Student* student, const char* name, uint8_t age, uint8_t grade) {
   // Implement this method! You can see the detailed documentation in students.h
   // Here strlen() counts up to the null terminator of name.
   if (student == NULL || name == NULL || strlen(name) > MAX_NAME_LEN){
         return false;} else {
            size_t nchar = strlen(name);
            memcpy(student->name, name, sizeof(char)*(nchar+1) );
            student-> age = age;
            student-> grade = grade;  
            return true;       
   }
}

uint8_t get_oldest_student(const struct Student* students, size_t num_students) {
   
   // Im