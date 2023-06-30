#include "test.h"

START_TEST(memset_1) {
  char* dest = malloc(sizeof(char) * 50);
  char* str = malloc(sizeof(char) * 50);

  strcpy(dest, "String");
  strcpy(str, "String");
  ck_assert_str_eq(my_memset(dest, 'c', 2), memset(str, 'c', 2));
  free(dest);
  free(str);
}
END_TEST

START_TEST(memset_2) {
  char* dest = calloc(50, sizeof(char));
  char* str = calloc(50, sizeof(char));

  strcpy(dest, "");
  strcpy(str, "");
  ck_assert_str_eq(my_memset(dest, 'c', 2), memset(str, 'c', 2));
  free(dest);
  free(str);
}
END_TEST

START_TEST(memset_3) {
  char* dest = malloc(sizeof(char) * 50);
  char* str = malloc(sizeof(char) * 50);

  strcpy(dest, "Sock cook");
  strcpy(str, "Sock cook");
  ck_assert_str_eq(my_memset(dest, 'C', 1), memset(str, 'C', 1));
  free(dest);
  free(str);
}
END_TEST
Suite* test_memset(void) {
  Suite* s4 = suite_create("my_memset");
  TCase* tc4 = tcase_create("case_memset");

  tcase_add_test(tc4, memset_1);
  tcase_add_test(tc4, memset_2);
  tcase_add_test(tc4, memset_3);

  suite_add_tcase(s4, tc4);
  return s4;
}