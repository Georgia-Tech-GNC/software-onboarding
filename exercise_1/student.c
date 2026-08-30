// We include students.h to be able to access the macros and imports
// that we defined there.
#include "student.h"

// "Importing" stdio let's us use printf, which is helpful for debugging.
#include "stdio.h"

bool initialize_student(struct Student* student, const char* name, uint8_t age, uint8_t grade) {
    if (student == NULL || name == NULL)
        return false;

    size_t len = strlen(name);
    if (len > MAX_NAME_LEN)
        return false;

    size_t sizeBytes = (len + 1) * sizeof(char);
    memcpy(student->name, name, sizeBytes);

    student->age = age;
    student->grade = grade;

    return true;
}

uint8_t get_oldest_student(const struct Student* students, size_t num_students) {
    uint8_t oldest = 0;

    for (size_t i = 0; i < num_students; i++) {
        if (students[i].age > oldest)
            oldest = students[i].age;
    }

    return oldest;
}

/** You can uncomment this main method and use it to help debug your code.
 * Make sure to re-comment it when running tests.
 */
// int main(void) {
//      struct Student s;
//      initialize_student(&s, "bob", 5, 7);
//
//      // printf("Name: %s \tAge: %d \tGrade: %d", s.name, s.age, s.grade);
//      //
//      struct Student students[] = {
//          { "Student1", 10, 5 },
//          { "Student2", 50, 5 },
//          { "Student3", 90, 5 },
//          { "Student4", 55, 5 },
//      };
//
//      uint8_t oldest = get_oldest_student(students, 4);
//      printf("Oldest: %d\n", oldest);
// }
