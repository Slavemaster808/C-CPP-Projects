#include "test.h"

START_TEST(sscanf_1) {
  char* dest = malloc(sizeof(char) * 100);
  char* str = malloc(sizeof(char) * 100);
  char* test_str = "Test case 1";
  my_sscanf(test_str, "%s", str);
  sscanf(test_str, "%s", dest);
  ck_assert_str_eq(dest, str);
  free(dest);
  free(str);
}
END_TEST

START_TEST(sscanf_2) {
  char* dest = malloc(sizeof(char) * 100);
  char* str = malloc(sizeof(char) * 100);
  char* str_test = "qwetazfasrqwqtigbigim3i5118tngi13n1ir11im24o122";
  my_sscanf(str_test, "%s", str);
  sscanf(str_test, "%s", dest);
  ck_assert_str_eq(dest, str);
  free(dest);
  free(str);
}
END_TEST

START_TEST(sscanf_3) {
  char* dest = malloc(sizeof(char) * 100);
  char* str = malloc(sizeof(char) * 100);
  char* str_test = "1231 gkgkg 214115";
  my_sscanf(str_test, "%s", str);
  sscanf(str_test, "%s", dest);
  ck_assert_str_eq(dest, str);
  free(dest);
  free(str);
}
END_TEST

Suite* test_sscanf(void) {
  Suite* s14 = suite_create("my_sscanf");
  TCase* tc14 = tcase_create("case_sscanf");

  tcase_add_test(tc14, sscanf_1);
  tcase_add_test(tc14, sscanf_2);
  tcase_add_test(tc14, sscanf_3);

  suite_add_tcase(s14, tc14);
  return s14;
}
