#include "test.h"

START_TEST(strlen_1) {
  ck_assert_int_eq(my_strlen("String"), strlen("String"));
}
END_TEST

START_TEST(strlen_2) { ck_assert_int_eq(my_strlen(""), strlen("")); }
END_TEST

START_TEST(strlen_3) { ck_assert_int_eq(my_strlen("\0"), strlen("\0")); }
END_TEST

Suite *test_strlen(void) {
  Suite *s10 = suite_create("my_strlen");
  TCase *tc10 = tcase_create("case_strlen");

  tcase_add_test(tc10, strlen_1);
  tcase_add_test(tc10, strlen_2);
  tcase_add_test(tc10, strlen_3);

  suite_add_tcase(s10, tc10);
  return s10;
}