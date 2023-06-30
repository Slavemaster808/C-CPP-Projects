#include "test.h"

START_TEST(strncmp_1) {
  const char* str1 = "String";
  const char* str2 = "String";

  ck_assert_int_eq(my_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(strncmp_2) {
  const char* str1 = "String";
  const char* str2 = "string";

  ck_assert_int_eq(my_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(strncmp_3) {
  const char* str1 = "StRing";
  const char* str2 = "string";

  ck_assert_int_eq(my_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

Suite* test_strncmp(void) {
  Suite* s7 = suite_create("my_strncmp");
  TCase* tc7 = tcase_create("case_strncmp");

  tcase_add_test(tc7, strncmp_1);
  tcase_add_test(tc7, strncmp_2);
  tcase_add_test(tc7, strncmp_3);

  suite_add_tcase(s7, tc7);
  return s7;
}