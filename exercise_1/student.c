// We include students.h to be able to access the macros and imports
// that we defined there.
#include "student.h"

// "Importing" stdio let's us use printf, which is helpful for debugging.
#include "stdio.h"
#include <stdbool.h>

//Student passed as pointer so not a local copy but the actual struct
//Strings are array - only passed as a pointer
bool initialize_student(struct Student* student, const char* name, uint8_t age, uint8_t grade) {
   // Implement this method! You can see the detailed documentation in students.h

   if (name == NULL || student == NULL) {
      return false;
   }
   
   size_t name_length = strlen(name);
   if (name_length > MAX_NAME_LEN) {
      return false;
   }

   for (size_t i = 0; i < name_length; i++) {
      student->name[i] = name[i];
   }

   //null operator at the end
   student->name[name_length] = '\0';
   student->age = age;
   student->grade = grade;
   return true;
}

uint8_t get_oldest_student(const struct Student* students, size_t num_students) {
   // Implement this method! You can see the detailed documentation in students.h
   uint8_t age_highest = 0; 

   for (size_t i = 0; i < num_students; i++) {
      if (students[i].age > age_highest) {
         age_highest = students[i].age;
      } 
   }

   return age_highest;

}

/** You can uncomment this main method and use it to help debug your code.
 * Make sure to re-comment it when running tests.
 */
// int main(void) {
//      struct Student s;
//      initialize_student(&s, "bob", 5, 7);
//      
//      printf("Name: %s \tAge: %d \tGrade: %d", s.name, s.age, s.grade);
// }
