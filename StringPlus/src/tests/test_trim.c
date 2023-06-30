#include "test.h"

START_TEST(trim_1) {
  char *str = "    Hello World,,,\n\n";
  char *ready = "Hello World";
  char *input = " ,\n";
  char *ret = my_trim(str, input);
  ck_assert_str_eq(ready, ret);
  free(ret);
}
END_TEST

START_TEST(trim_2) {
  char *str = "    Hello\tWorld,,,\n\n";
  char *ready = "Hello\tWorld";
  char *input = " ,\n\t";
  char *ret = my_trim(str, input);
  ck_assert_str_eq(ready, ret);
  free(ret);
}
END_TEST

START_TEST(trim_3) {
  char *str = "    Hello ,,,\n\n";
  char *ready = "Hello";
  char *input = " ,\n";
  char *ret = my_trim(str, input);
  ck_assert_str_eq(ready, ret);
  free(ret);
}
END_TEST

START_TEST(trim_4) {
  char *str = "Hello";
  char *ready = "Hello";
  char *input = NULL;
  char *ret = my_trim(str, input);
  ck_assert_str_eq(ready, ret);
  free(ret);
}
END_TEST

START_TEST(trim_5) {
  char *str = "Hello      ";
  char *ready = "Hello";
  char *input = " \0 ";
  char *ret = my_trim(str, input);
  ck_assert_str_eq(ready, ret);
  free(ret);
}
END_TEST

START_TEST(trim_6) {
  char *str = NULL;
  char *ready = NULL;
  char *input = " \0 ";
  char *ret = my_trim(str, input);
  ck_assert_int_eq(ready == NULL, ret == NULL);
  free(ret);
}
END_TEST

Suite *test_trim(void) {
  Suite *s18 = suite_create("trim");
  TCase *tc18 = tcase_create("case_trim");

  tcase_add_test(tc18, trim_1);
  tcase_add_test(tc18, trim_2);
  tcase_add_test(tc18, trim_3);
  tcase_add_test(tc18, trim_4);
  tcase_add_test(tc18, trim_5);
  tcase_add_test(tc18, trim_6);

  suite_add_tcase(s18, tc18);
  return s18;
}