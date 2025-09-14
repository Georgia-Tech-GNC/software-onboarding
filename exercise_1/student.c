// We include students.h to be able to access the macros and imports
// that we defined there.
#include "student.h"

// "Importing" stdio let's us use printf, which is helpful for debugging.
#include "stdio.h"

bool initialize_student(struct Student* student, const char* name, uint8_t age, uint8_t grade) {
   if (student == NULL || name == NULL) {
      return false;
   }
   int nameLength = 0;
   const char* i = name;
   while (*i != '\0') {
      nameLength++;
      i++;
   }
   if (nameLength > MAX_NAME_LEN) {
      return false;
   }
   student->age = age;
   student->grade = grade;
   memcpy((student->name), name, sizeof(char) * nameLength);
   student->name[nameLength] = '\0';
   return true;
}

uint8_t get_oldest_student(const struct Student* students, size_t num_students) {
   if (num_students == 0) {
      return 0;
   }
   uint8_t oldestAge = students[0].age;
   for (size_t i = 1; i < num_students; i++) {
      if (students[i].age > oldestAge) {
         oldestAge = students[i].age;
      }
   }
   return oldestAge;
}

/** You can uncomment this main method and use it to help debug your code.
 * Make sure to re-comment it when running tests.
 */
//int main(void) {
  // struct Student s1;
  // struct Student s2;
  // struct Student s3;
  // initialize_student(&s1, "bob1", 5, 7);
  // initialize_student(&s2, "bob2", 11, 7);
  // initialize_student(&s3, "bob3", 3, 7);
  // struct Student students[3] = {s1, s2, s3};
  // printf("Name: %s \tAge: %d \tGrade: %d", s1.name, s1.age, s1.grade);
  // printf("\nOldest student's age: %d", get_oldest_student(students, 3));
//}
