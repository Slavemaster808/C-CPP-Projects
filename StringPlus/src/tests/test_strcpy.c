#include "test.h"

START_TEST(my_strcpy_1) {
  char string[100];
  char *ready = "Hello";
  my_strcpy(string, ready);
  ck_assert_str_eq(string, ready);
}
END_TEST

START_TEST(my_strcpy_2) {
  char string[100];
  char *ready = "School 21";
  my_strcpy(string, ready);
  ck_assert_str_eq(string, ready);
}
END_TEST

START_TEST(my_strcpy_3) {
  char string[100];
  char *ready = "Hello World";
  my_strcpy(string, ready);
  ck_assert_str_eq(string, ready);
}
END_TEST

Suite *test_strcpy(void) {
  Suite *s19 = suite_create("my_strcpy");
  TCase *tc19 = tcase_create("case_strcpy");

  tcase_add_test(tc19, my_strcpy_1);
  tcase_add_test(tc19, my_strcpy_2);
  tcase_add_test(tc19, my_strcpy_3);

  suite_add_tcase(s19, tc19);
  return s19;
}