#include "test.h"

START_TEST(strrchr_1) {
  char *dest = malloc(sizeof(char) * 50);
  char *ret_1;
  char *ret_2;

  strcpy(dest, "http://www.tutorialspoint.com");
  ret_1 = my_strrchr(dest, '/');
  ret_2 = strrchr(dest, '/');

  ck_assert_str_eq(ret_1, ret_2);
  free(dest);
}
END_TEST

START_TEST(strrchr_2) {
  char *dest = malloc(sizeof(char) * 50);
  char *ret_1;
  char *ret_2;

  strcpy(dest, "http://www.tutorialspoint.com");
  ret_1 = my_strrchr(dest, 'w');
  ret_2 = strrchr(dest, 'w');

  ck_assert_str_eq(ret_1, ret_2);
  free(dest);
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s11 = suite_create("my_strrchr");
  TCase *tc11 = tcase_create("case_strrchr");

  tcase_add_test(tc11, strrchr_1);
  tcase_add_test(tc11, strrchr_2);

  suite_add_tcase(s11, tc11);
  return s11;
}