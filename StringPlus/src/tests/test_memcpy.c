#include "test.h"

START_TEST(memcpy_1) {
  char* dest = calloc(100, sizeof(char));
  const char* str = "String";

  ck_assert_str_eq(my_memcpy(dest, str, 3), memcpy(dest, str, 3));
  free(dest);
}
END_TEST

START_TEST(memcpy_2) {
  char* dest = malloc(sizeof(char) * 100);
  const char* str = " ";

  ck_assert_str_eq(my_memcpy(dest, str, 2), memcpy(dest, str, 2));
  free(dest);
}
END_TEST

START_TEST(memcpy_3) {
  char* dest = calloc(100, sizeof(char));
  const char* str = "Hello";

  ck_assert_str_eq(my_memcpy(dest, str, 4), memcpy(dest, str, 4));
  free(dest);
}
END_TEST

Suite* test_memcpy(void) {
  Suite* s3;
  TCase* tc3;
  s3 = suite_create("my_memcpy");
  tc3 = tcase_create("case_memcpy");

  tcase_add_test(tc3, memcpy_1);
  tcase_add_test(tc3, memcpy_2);
  tcase_add_test(tc3, memcpy_3);

  suite_add_tcase(s3, tc3);
  return s3;
}