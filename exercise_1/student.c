// We include students.h to be able to access the macros and imports
// that we defined there.
#include "student.h"

// "Importing" stdio let's us use printf, which is helpful for debugging.
#include "stdio.h"

bool initialize_student(struct Student* student, const char* name, uint8_t age, uint8_t grade) {
   // Implement this method! You can see the detailed documentation in students.h

   if ((student == NULL) || (name == NULL)) return false;
   else if (strlen(name) > MAX_NAME_LEN) return false;

   size_t i; 
   for (i = 0; i < strlen(name); i++) {
      student->name[i] = name[i];
   }
   student->name[i] = '\0';

   student->age = age;
   student->grade = grade;
   return true;
}

uint8_t get_oldest_student(const struct Student* students, size_t num_students) {
   // Implement this method! You can see the detailed documentation in students.h

   if (num_students != 0) {
      int biggest = 0;
      for (size_t i = 0; i < num_students; i++) {
         if (students[i].age > biggest) biggest = students[i].age;
      }

      return biggest;
   }
   
   return 0;
}

/** You can uncomment this main method and use it to help debug your code.
 * Make sure to re-comment it when running tests.
 */
// int main(void) {
//      struct Student s;
//      initialize_student(&s, "bob", 5, 7);
     
//      printf("Name: %s \tAge: %d \tGrade: %d", s.name, s.age, s.grade);
// }
