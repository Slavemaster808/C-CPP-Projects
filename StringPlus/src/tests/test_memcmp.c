#include "test.h"

START_TEST(memcmp_1) {
  ck_assert_int_eq(my_memcmp("String", "String", 2),
                   memcmp("String", "String", 2));
}
END_TEST

START_TEST(memcmp_2) {
  char *str = "String";
  char *dest = "STring";
  ck_assert_int_eq(my_memcmp(str, dest, 6), memcmp(str, dest, 6));
}
END_TEST

START_TEST(memcmp_3) {
  ck_assert_int_eq(my_memcmp("String", "String", 6),
                   memcmp("String", "String", 6));
}
END_TEST

START_TEST(memcmp_4) {
  ck_assert_int_eq(my_memcmp("", "", 6), memcmp("", "", 6));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s2 = suite_create("my_memcmp");
  TCase *tc2 = tcase_create("case_memcmp");

  tcase_add_test(tc2, memcmp_1);
  tcase_add_test(tc2, memcmp_2);
  tcase_add_test(tc2, memcmp_3);
  tcase_add_test(tc2, memcmp_4);

  suite_add_tcase(s2, tc2);
  return s2;
}