#include "test.h"

START_TEST(sprintf_1) {
  char *dest = malloc(sizeof(char) * 100);
  char *str = malloc(sizeof(char) * 100);

  my_sprintf(dest, "%s %c %d %c %.7lf", "line", 'C', -13, 'a', 12.9999999);
  sprintf(str, "%s %c %d %c %.7lf", "line", 'C', -13, 'a', 12.9999999);

  ck_assert_str_eq(dest, str);
  free(dest);
  free(str);
}
END_TEST

START_TEST(sprintf_2) {
  char *dest = malloc(sizeof(char) * 100);
  int cnt;

  ck_assert_int_eq((cnt = my_sprintf(dest, "%s %c %d %c %.7lf", "line", 'C',
                                     -13, 'a', 12.9999999)),
                   (cnt = sprintf(dest, "%s %c %d %c %.7lf", "line", 'C', -13,
                                  'a', 12.9999999)));
  free(dest);
}
END_TEST

START_TEST(sprintf_3) {
  char *dest = malloc(sizeof(char) * 100);
  char *str = malloc(sizeof(char) * 100);

  my_sprintf(dest, "%17s %5c %d %c %.7lf", "line", 'C', -13, 'a', 12.9999999);
  sprintf(str, "%17s %5c %d %c %.7lf", "line", 'C', -13, 'a', 12.9999999);

  ck_assert_str_eq(dest, str);
  free(dest);
  free(str);
}
END_TEST

Suite *test_sprintf(void) {
  Suite *s13 = suite_create("my_sprintf");
  TCase *tc13 = tcase_create("case_sprintf");

  tcase_add_test(tc13, sprintf_1);
  tcase_add_test(tc13, sprintf_2);
  tcase_add_test(tc13, sprintf_3);

  suite_add_tcase(s13, tc13);
  return s13;
}