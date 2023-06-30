#include "test.h"

START_TEST(strchr_1) {
  char* dest = malloc(sizeof(char) * 50);
  char* ret_1;
  char* ret_2;

  strcpy(dest, "String");
  ret_1 = my_strchr(dest, 't');
  ret_2 = strchr(dest, 't');
  ck_assert_str_eq(ret_1, ret_2);
  free(dest);
}
END_TEST

START_TEST(strchr_2) {
  char* dest = malloc(sizeof(char) * 50);
  char* ret_1;
  char* ret_2;

  strcpy(dest, " ");
  ret_1 = my_strchr(dest, ' ');
  ret_2 = strchr(dest, ' ');
  ck_assert_str_eq(ret_1, ret_2);
  free(dest);
}
END_TEST

START_TEST(strchr_3) {
  char* dest = malloc(sizeof(char) * 50);
  char* ret_1;
  char* ret_2;

  strcpy(dest, "Hello World");
  ret_1 = my_strchr(dest, 'l');
  ret_2 = strchr(dest, 'l');
  ck_assert_str_eq(ret_1, ret_2);
  free(dest);
}
END_TEST

Suite* test_strchr(void) {
  Suite* s6 = suite_create("my_strchr");
  TCase* tc6 = tcase_create("case_strchr");

  tcase_add_test(tc6, strchr_1);
  tcase_add_test(tc6, strchr_2);
  tcase_add_test(tc6, strchr_3);

  suite_add_tcase(s6, tc6);
  return s6;
}