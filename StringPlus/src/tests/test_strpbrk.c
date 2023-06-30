#include "test.h"

START_TEST(strpbrk_1) {
  const char *str1 = "0123456789";
  const char *str2 = "9876";
  char *ret_1, *ret_2;

  ret_1 = my_strpbrk(str1, str2);
  ret_2 = strpbrk(str1, str2);

  ck_assert_str_eq(ret_1, ret_2);
}
END_TEST

START_TEST(strpbrk_2) {
  const char *str1 = "0123456789";
  const char *str2 = "9876";
  char *ret_1, *ret_2;

  ret_1 = my_strpbrk(str1, str2);
  ret_2 = strpbrk(str1, str2);

  ck_assert_int_eq(*ret_1, *ret_2);
}
END_TEST

START_TEST(strpbrk_3) {
  const char *str1 = "1234567890";
  const char *str2 = "24566";
  char *ret_1, *ret_2;

  ret_1 = my_strpbrk(str1, str2);
  ret_2 = strpbrk(str1, str2);

  ck_assert_int_eq(*ret_1, *ret_2);
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s12 = suite_create("my_strpbrk");
  TCase *tc12 = tcase_create("case_strpbrk");

  tcase_add_test(tc12, strpbrk_1);
  tcase_add_test(tc12, strpbrk_2);
  tcase_add_test(tc12, strpbrk_3);

  suite_add_tcase(s12, tc12);
  return s12;
}