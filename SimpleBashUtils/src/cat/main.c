#include "my_cat.h"

int main(int argc, char **argv) {
  int i = 1;
  int check = 0;

  while (i < argc) {
    if (argv[i][0] == '-') {
      check++;
    }
    i++;
  }

  if (check == 0) {
    outputWithNoFlags(argc, argv);
  } else if (check > 0) {
    outputWithFlags(argc, argv);
  } else {
    printf("No input file.");
  }

  return 0;
}