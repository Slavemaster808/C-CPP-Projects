#include "test.h"

START_TEST(strerror_1) {
  char *str = my_strerror('c');
  char *ret = strerror('c');

  ck_assert_str_eq(str, ret);
}
END_TEST

START_TEST(strerror_2) {
  char *str = my_strerror(0);
  char *ret = strerror(0);

  ck_assert_str_eq(str, ret);
}
END_TEST

START_TEST(strerror_3) {
  char *str = my_strerror(-15);
  char *ret = strerror(-15);

  ck_assert_str_eq(str, ret);
}
END_TEST

Suite *test_strerror(void) {
  Suite *my = suite_create("my_strerror");
  TCase *tc21 = tcase_create("case_strerror");

  tcase_add_test(tc21, strerror_1);
  tcase_add_test(tc21, strerror_2);
  tcase_add_test(tc21, strerror_3);

  suite_add_tcase(my, tc21);
  return my;
}