#include "test.h"

START_TEST(to_upper_1) {
  char *dest = "ABCDF";
  char *str = "abcdf";
  str = my_to_upper(str);
  ck_assert_str_eq(dest, str);
  free(str);
}
END_TEST

START_TEST(to_upper_2) {
  char *dest = "ABCDF";
  char *str = "abCDF";
  str = my_to_upper(str);
  ck_assert_str_eq(dest, str);
  free(str);
}
END_TEST

START_TEST(to_upper_3) {
  char *dest = "ABCDF";
  char *str = "AbcDF";
  str = my_to_upper(str);
  ck_assert_str_eq(dest, str);
  free(str);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s15 = suite_create("my_to_upper");
  TCase *tc15 = tcase_create("case_to_upper");

  tcase_add_test(tc15, to_upper_1);
  tcase_add_test(tc15, to_upper_2);
  tcase_add_test(tc15, to_upper_3);

  suite_add_tcase(s15, tc15);
  return s15;
}