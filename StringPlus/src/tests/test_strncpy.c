#include "test.h"

START_TEST(strncpy_1) {
  char* dest = malloc(sizeof(char) * 50);

  ck_assert_str_eq(my_strncpy(dest, "String", 7), strncpy(dest, "String", 7));
  free(dest);
}
END_TEST

START_TEST(strncpy_2) {
  char* dest = malloc(sizeof(char) * 50);

  ck_assert_str_eq(my_strncpy(dest, " ", 2), strncpy(dest, " ", 2));
  free(dest);
}
END_TEST

START_TEST(strncpy_3) {
  char* dest = malloc(sizeof(char) * 50);

  ck_assert_str_eq(my_strncpy(dest, "HELL", 5), strncpy(dest, "HELL", 5));
  free(dest);
}
END_TEST

Suite* test_strncpy(void) {
  Suite* s8 = suite_create("my_strncpy");
  TCase* tc8 = tcase_create("case_strncpy");

  tcase_add_test(tc8, strncpy_1);
  tcase_add_test(tc8, strncpy_2);
  tcase_add_test(tc8, strncpy_3);

  suite_add_tcase(s8, tc8);
  return s8;
}