#include "test.h"

START_TEST(strstr_1) {
  const char* str1 = "StrNEWing";
  char* ret = my_strstr(str1, "NEW");
  char* res = strstr(str1, "NEW");

  ck_assert_str_eq(ret, res);
}
END_TEST

START_TEST(strstr_2) {
  const char* str1 = "StrNEWing";
  char* ret = my_strstr(str1, "");
  char* res = strstr(str1, "");

  ck_assert_str_eq(ret, res);
}
END_TEST

START_TEST(strstr_3) {
  const char* str1 = "NEWString";
  char* ret = my_strstr(str1, "NeW");
  char* res = strstr(str1, "NeW");

  ck_assert_int_eq(ret == NULL, res == NULL);
}
END_TEST

Suite* test_strstr(void) {
  Suite* s20 = suite_create("my_strstr");
  TCase* tc20 = tcase_create("case_strerror");

  tcase_add_test(tc20, strstr_1);
  tcase_add_test(tc20, strstr_2);
  tcase_add_test(tc20, strstr_3);

  suite_add_tcase(s20, tc20);
  return s20;
}