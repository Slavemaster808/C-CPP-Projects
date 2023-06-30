#include "test.h"

START_TEST(strcspn_1) {
  const char *str1 = "0123456789";
  const char *str2 = "9876";

  ck_assert_int_eq(my_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  const char *str1 = "0123456789";
  const char *str2 = "64375648378543";

  ck_assert_int_eq(my_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  const char *str1 = "GGGGGhkaak";
  const char *str2 = "ak";
  ck_assert_int_eq(my_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s9 = suite_create("my_strcspn");
  TCase *tc9 = tcase_create("case_strcspn");

  tcase_add_test(tc9, strcspn_1);
  tcase_add_test(tc9, strcspn_2);
  tcase_add_test(tc9, strcspn_3);

  suite_add_tcase(s9, tc9);
  return s9;
}