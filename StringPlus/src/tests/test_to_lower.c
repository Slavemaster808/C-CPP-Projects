#include "test.h"

START_TEST(to_lower_1) {
  char *dest = "abcd";
  char *str = "ABCD";
  str = my_to_lower(str);
  ck_assert_str_eq(dest, str);
  free(str);
}
END_TEST

START_TEST(to_lower_2) {
  char *dest = "abcd";
  char *str = "ABcd";
  str = my_to_lower(str);
  ck_assert_str_eq(dest, str);
  free(str);
}
END_TEST

START_TEST(to_lower_3) {
  char *dest = "abcd";
  char *str = "ABCd";
  str = my_to_lower(str);
  ck_assert_str_eq(dest, str);
  free(str);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s16 = suite_create("my_to_lower");
  TCase *tc16 = tcase_create("case_to_lower");

  tcase_add_test(tc16, to_lower_1);
  tcase_add_test(tc16, to_lower_2);
  tcase_add_test(tc16, to_lower_3);

  suite_add_tcase(s16, tc16);
  return s16;
}