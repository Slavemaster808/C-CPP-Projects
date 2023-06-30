#include "test.h"

START_TEST(insert_1) {
  char *string = "Hello";
  char *ready = "Heabcllo";
  string = my_insert(string, "abc", 2);
  ck_assert_str_eq(string, ready);
  free(string);
}
END_TEST

START_TEST(insert_2) {
  char *string = "Test insert func";
  char *ready = "Tes123t insert func";
  string = my_insert(string, "123", 3);
  ck_assert_str_eq(string, ready);
  free(string);
}
END_TEST

START_TEST(insert_3) {
  char *string = "Shcool";
  char *ready = "Shcool21";
  char *str = "21";
  string = my_insert(string, str, 6);
  ck_assert_str_eq(ready, string);
  free(string);
}
END_TEST

START_TEST(insert_4) {
  char *string = NULL;
  char *ready = NULL;
  char *str = "21";
  string = my_insert(string, str, 6);
  ck_assert_int_eq(ready == NULL, string == NULL);
  free(string);
}
END_TEST

START_TEST(insert_5) {
  char *string = "School21";
  char *ready = NULL;
  char *str = "21";
  string = my_insert(string, str, 20);
  ck_assert_int_eq(ready == NULL, string == NULL);
  free(string);
}
END_TEST

START_TEST(insert_6) {
  char *string = "School21";
  char *ready = NULL;
  char *str = "21";
  string = my_insert(string, str, -1);
  ck_assert_int_eq(ready == NULL, string == NULL);
  free(string);
}
END_TEST

Suite *test_insert(void) {
  Suite *s17 = suite_create("insert");
  TCase *tc17 = tcase_create("case_insert");

  tcase_add_test(tc17, insert_1);
  tcase_add_test(tc17, insert_2);
  tcase_add_test(tc17, insert_3);
  tcase_add_test(tc17, insert_4);
  tcase_add_test(tc17, insert_5);
  tcase_add_test(tc17, insert_6);

  suite_add_tcase(s17, tc17);
  return s17;
}