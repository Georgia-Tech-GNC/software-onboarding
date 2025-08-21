#include "minunit.h"
#include "student.h"

_Static_assert(MAX_NAME_LEN == 20, 
    "If this assertion fails, something is wrong with your setup!" 
    "Make sure you set MAX_NAME_LEN in students.h to 20 when running the tests."
);

void clear_name(char* name) {
    for (int i = 0; i < 21; i++) {
        name[i] = '\0';
    }
}

MU_TEST(check_null_student) {
    char* name = "Harry Potter";    
	mu_check(initialize_student(NULL, name, 12, 12) == false);
}

MU_TEST(check_null_name) {
    struct Student s = {.age = 2, .grade = 2};
    clear_name(s.name);
	mu_check(initialize_student(&s, NULL, 12, 12) == false);
    mu_assert_int_eq(s.age, 2);
    mu_assert_int_eq(s.grade, 2);
    for (int i = 0; i < 21; i++) {
        mu_check(s.name[i] == '\0');
    }
}

MU_TEST(check_oversized_name) {
    char* name = "Neville F. Longbottom";  
    struct Student s = {.age = 2, .grade = 2};
    clear_name(s.name);
	mu_check(initialize_student(&s, name, 12, 12) == false);
    mu_assert_int_eq(s.age, 2);
    mu_assert_int_eq(s.grade, 2);
    for (int i = 0; i < 21; i++) {
        mu_check(s.name[i] == '\0');
    }
}

MU_TEST(check_20char_name) {
    char* name = "Fee Fi Fo Fum Far Fy";    
    struct Student s = {.age = 0, .grade = 0};
    clear_name(s.name);

	mu_check(initialize_student(&s, name, 12, 10) == true);
    mu_assert_int_eq(s.age, 12);
    mu_assert_int_eq(s.grade, 10);
    for (int i = 0; i < 21; i++) {
        mu_check(name[i] == s.name[i]);
    }
}

MU_TEST(check_empty_name) {
    char* name = "";    
    struct Student s = {.age = 0, .grade = 0};
    clear_name(s.name);
    s.name[0] = ' ';

	mu_check(initialize_student(&s, name, 3, 4) == true);
    mu_assert_int_eq(s.age, 3);
    mu_assert_int_eq(s.grade, 4);
    for (int i = 0; i < 21; i++) {
        mu_check(s.name[i] == '\0');
    }
}

MU_TEST(normal_init_student) {
    char* name = "George Cloony";    
    struct Student s = {.age = 0, .grade = 0};
    clear_name(s.name);

	mu_check(initialize_student(&s, name, 19, 13) == true);
    mu_assert_int_eq(s.age, 19);
    mu_assert_int_eq(s.grade, 13);
    for (int i = 0; i < 14; i++) {
        mu_check(name[i] == s.name[i]);
    }
    for (int i = 14; i < 21; i++) {
        mu_check(s.name[i] == '\0');
    }
}

MU_TEST_SUITE(test_init_student) {
	MU_RUN_TEST(check_null_student);
	MU_RUN_TEST(check_null_name);
	MU_RUN_TEST(check_oversized_name);
	MU_RUN_TEST(check_20char_name);
	MU_RUN_TEST(check_empty_name);
	MU_RUN_TEST(normal_init_student);

}

MU_TEST(oldest_from_empty) {
	mu_check(get_oldest_student(NULL, 0) == 0);
}

MU_TEST(oldest_from_one) {
    struct Student s = {.age = 15, .grade = 14};
    clear_name(s.name);

    mu_check(get_oldest_student(&s, 1) == 15);
}

MU_TEST(oldest_from_distinct) {
    struct Student s[] = {
        {.age = 15, .grade = 10},
        {.age = 17, .grade = 7},
        {.age = 13, .grade = 2},
        {.age = 12, .grade = 13},
    };
    for (int i = 0; i < 4; i++) {
        clear_name(s[i].name);
    }

    mu_check(get_oldest_student(s, 4) == 17);
}

MU_TEST(oldest_with_repeats) {
    struct Student s[] = {
        {.age = 15, .grade = 10},
        {.age = 17, .grade = 7},
        {.age = 13, .grade = 2},
        {.age = 17, .grade = 13},
        {.age = 12, .grade = 9},

    };
    for (int i = 0; i < 4; i++) {
        clear_name(s[i].name);
    }

    mu_check(get_oldest_student(s, 4) == 17);
}

MU_TEST_SUITE(test_get_oldest_student) {
    MU_RUN_TEST(oldest_from_empty);
    MU_RUN_TEST(oldest_from_one);
    MU_RUN_TEST(oldest_from_distinct);
    MU_RUN_TEST(oldest_with_repeats);
}

int main(void) {
	MU_RUN_SUITE(test_init_student);
    MU_RUN_SUITE(test_get_oldest_student);
	MU_REPORT();

    if (MU_EXIT_CODE == 0) {
        printf("All test cases passed! Congratulations!\n");
        printf("To complete this exercise, make a pull request on github with your code.\n\n");

    }

	return MU_EXIT_CODE;
}
