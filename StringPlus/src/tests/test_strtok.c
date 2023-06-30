#include "test.h"

START_TEST(strtok_1) {
  char str1[] = "Hello - world/     !!!";
  char str2[] = "Hello - world/     !!!";
  char delim[] = " -/!";
  char *coin1 = my_strtok(str1, delim);
  char *coin2 = strtok(str2, delim);

  while (coin1 != NULL && coin2 != NULL) {
    ck_assert_str_eq(coin1, coin2);
    coin1 = my_strtok(NULL, delim);
    coin2 = strtok(NULL, delim);
  }

  ck_assert_int_eq(coin1 == NULL, coin2 == NULL);
  free(coin1);
  free(coin2);
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "Hello - world/     !!!";
  char str2[] = "Hello - world/     !!!";
  // char *delim = "";
  char *coin1 = my_strtok(str1, "");
  char *coin2 = strtok(str2, "");

  while (coin1 != NULL && coin2 != NULL) {
    ck_assert_str_eq(coin1, coin2);
    coin1 = my_strtok(NULL, "");
    coin2 = strtok(NULL, "");
  }

  ck_assert_int_eq(coin1 == NULL, coin2 == NULL);
  free(coin1);
  free(coin2);
}
END_TEST

// START_TEST(strtok_3) {
//     char str1[] = "Hello - world/     !!!";
//     char str2[] = "Hello - world/     !!!";
//   char delim[] = " -/!";
//   char *coin1 = my_strtok(NULL, delim);
//   char *coin2 = strtok(NULL, delim);

//   ck_assert_int_eq(coin1 == NULL, coin2 == NULL);
// }
// END_TEST

Suite *test_strtok(void) {
  Suite *my = suite_create("my_strtok");
  TCase *tc21 = tcase_create("case_strtok");

  tcase_add_test(tc21, strtok_1);
  tcase_add_test(tc21, strtok_2);
  //   tcase_add_test(tc21, strtok_3);

  suite_add_tcase(my, tc21);
  return my;
}