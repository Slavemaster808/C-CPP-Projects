#include "test.h"

START_TEST(memchr_1) {
  ck_assert_int_eq(my_memchr("String", 'f', 2) == NULL,
                   memchr("String", 'f', 2) == NULL);
}
END_TEST

START_TEST(memchr_2) {
  char *dest = "Hello dir friend i com for you!";
  ck_assert_str_eq(my_memchr(dest, 'i', 10), memchr(dest, 'i', 10));
}
END_TEST

START_TEST(memchr_3) {
  char *dest = " ";
  ck_assert_str_eq(my_memchr(dest, ' ', 1), memchr(dest, ' ', 1));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s1 = suite_create("my_memchr");
  TCase *tc1 = tcase_create("case_memchr");

  tcase_add_test(tc1, memchr_1);
  tcase_add_test(tc1, memchr_2);
  tcase_add_test(tc1, memchr_3);

  suite_add_tcase(s1, tc1);
  return s1;
}