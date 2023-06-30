#include "my_grep.h"

int main(int argc, char **argv) {
  int check = 0;
  int check_amount_of_files = 0;
  int i = 1;

  while (i < argc) {
    if (argv[i][0] == '-') {
      check = 1;
    }
    i++;
  }
  if (check > 0) {
    i = 3;
    while (i < argc) {
      check_amount_of_files++;
      i++;
    }
  } else {
    i = 2;
    while (i < argc) {
      check_amount_of_files++;
      i++;
    }
  }
  if (check == 0) {
    outputWithNoFlags(argc, check_amount_of_files, check, argv[1][1], argv);
  } else {
    outputWithFlags(argc, check_amount_of_files, check, argv[1][1], argv);
  }
  return 0;
}