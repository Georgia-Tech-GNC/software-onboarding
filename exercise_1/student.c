// We include students.h to be able to access the macros and imports
// that we defined there.
#include "student.h"

bool initialize_student(
    struct Student* student, 
    const char* name, 
    size_t name_len, 
    uint8_t age, 
    uint8_t grade
) {
   // Implement this method! You can see the detailed documentation in students.h
}

uint8_t get_oldest_student(const struct Student* students, size_t num_students) {
   // Implement this method! You can see the detailed documentation in students.h
}

/** You can uncomment this main method and use it to help debug your code.
 * Make sure to re-comment it when running tests.
 */
// int main(void) {
//      struct Student s;
//      initialize_student(&s, )
// }
