#include "test.h"

int main(void) {
  int failed = 0;
  Suite* my_str_test[] = {test_memchr(),
                          test_memcmp(),
                          test_memcpy(),
                          test_memset(),
                          test_strncat(),
                          test_strchr(),
                          test_strncmp(),
                          test_strncpy(),
                          test_strcspn(),
                          test_strlen(),
                          test_strrchr(),
                          test_strpbrk(),
                          test_sprintf(),
                          test_sscanf(),
                          test_to_upper(),
                          test_to_lower(),
                          test_insert(),
                          test_trim(),
                          test_strcpy(),
                          test_strstr(),
                          test_strerror(),
                          test_strtok(),
                          NULL};

  for (int i = 0; my_str_test[i] != NULL; i++) {
    SRunner* sr = srunner_create(my_str_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  failed ? printf("\e[31m==== FAILED: %d ====\e[39m\n", failed)
         : printf("\e[32m==== FAILED: %d ====\e[39m\n", failed);
  return failed == 0 ? 0 : 1;
}