#include "test.h"

START_TEST(strncat_1) {
  char* dest = malloc(sizeof(char) * 50);
  char* str = malloc(sizeof(char) * 50);

  strcpy(dest, "Str");
  strcpy(str, "Str");
  ck_assert_str_eq(my_strncat(dest, "ingo", 3), strncat(str, "ingo", 3));
  free(dest);
  free(str);
}
END_TEST

START_TEST(strncat_2) {
  char* dest = malloc(sizeof(char) * 50);
  char* str = malloc(sizeof(char) * 50);

  strcpy(dest, "");
  strcpy(str, "");
  ck_assert_str_eq(my_strncat(dest, "ing", 2), strncat(str, "ing", 2));
  free(dest);
  free(str);
}
END_TEST

START_TEST(strncat_3) {
  char* dest = malloc(sizeof(char) * 50);
  char* str = malloc(sizeof(char) * 50);

  strcpy(dest, "");
  strcpy(str, "");
  ck_assert_str_eq(my_strncat(dest, "ing", 1), strncat(str, "ing", 1));
  free(dest);
  free(str);
}
END_TEST

Suite* test_strncat(void) {
  Suite* s5 = suite_create("my_strncat");
  TCase* tc5 = tcase_create("case_strncat");

  tcase_add_test(tc5, strncat_1);
  tcase_add_test(tc5, strncat_2);
  tcase_add_test(tc5, strncat_3);

  suite_add_tcase(s5, tc5);
  return s5;
}