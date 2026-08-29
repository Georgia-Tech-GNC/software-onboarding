// We include students.h to be able to access the macros and imports
// that we defined there.
#include "student.h"

// "Importing" stdio let's us use printf, which is helpful for debugging.
#include "stdio.h"

bool initialize_student(struct Student* student, const char* name, uint8_t age, uint8_t grade) {
   // Implement this method! You can see the detailed documentation in students.h
   // Checks if name or student is null
   if (name == NULL || student == NULL)
   {
      return false;
   }
   // Checks if length of name is greater than max length
   size_t len = strlen(name);
   if(len > MAX_NAME_LEN)
   {
      return false;
   }
   // Set age, grade, name
   student ->age = age;
   student ->grade = grade;
   memcpy(student ->name, name, len+1);
   return true;
   
   
}

uint8_t get_oldest_student(const struct Student* students, size_t num_students) {
   // Implement this method! You can see the detailed documentation in students.h
   uint8_t max_age = 0;
   // Loops through student array to find largest age
   for(size_t i = 0; i<num_students; i++)
   {
      if(students[i].age > max_age)
      {
         max_age = students[i].age;
      }
   }
   return max_age;
}

/** You can uncomment this main method and use it to help debug your code.
 * Make sure to re-comment it when running tests.
 */
//  int main(void) {
//      struct Student s;
//    initialize_student(&s, "bob", 5, 7);
     
//      printf("Name: %s \tAge: %d \tGrade: %d", s.name, s.age, s.grade);
//      return 0;
// }
