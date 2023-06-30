#include "my_cat.h"

void outputWithNoFlags(int argc, char **argv) {
  FILE *fp;
  char *buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
  int i = 1;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      size_t size = 0;
      while ((int)(size = getline(&buff, &size, fp)) != -1) {
        printLines(buff, size);
      }
    }
    i++;
    fclose(fp);
  }
  free(buff);
}

void outputWithFlags(int argc, char **argv) {
  char str[2][50] = {"number", "squeeze"};

  if (argv[1][0] == '-' && argv[1][1] == '-') {
    char *temp_str;
    int len = strlen(argv[1]);
    temp_str = strtok(argv[1], "-");
    if (strcmp(temp_str, str[0]) == 0 && len > 8) {
      numbersWOEmpty(argc, argv);
    } else if (strcmp(temp_str, str[0]) == 0) {
      numbers(argc, argv);
    } else if (strcmp(temp_str, str[1]) == 0) {
      deleteRepeatedStrings(argc, argv);
    } else {
      printf("No such flag.");
    }
  } else if (argv[1][0] != '-' && argv[1][1] != '-') {
    printf("No flags detected.");
  } else {
    switch (argv[1][1]) {
      case 'e':
        dollarSign(argc, argv);
        break;
      case 'n':
        numbers(argc, argv);
        break;
      case 'b':
        numbersWOEmpty(argc, argv);
        break;
      case 's':
        deleteRepeatedStrings(argc, argv);
        break;
      case 't':
        tabs(argc, argv);
        break;
      case 'v':
        invalidSymbols(argc, argv);
        break;
      default:
        printf("No such flag.");
        break;
    }
  }
}

void dollarSign(int argc, char **argv) {
  FILE *fp;
  char *buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
  int i = 2;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      size_t size = 0;
      while ((int)(size = getline(&buff, &size, fp)) != -1) {
        for (size_t j = 0; j < size; j++) {
          if (buff[j] == '\n') {
            printf("$");
          }
          replaceSymbols(buff[j]);
        }
      }
    }
    i++;
    fclose(fp);
  }
  free(buff);
}

void numbers(int argc, char **argv) {
  FILE *fp;
  char *buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
  int numbers = 1;
  int i = 2;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      size_t size = 0;
      while ((int)(size = getline(&buff, &size, fp)) != -1) {
        printf("%6d\t", numbers);
        printLines(buff, size);
        numbers++;
      }
    }
    i++;
    numbers = 1;
    fclose(fp);
  }
  free(buff);
}

void numbersWOEmpty(int argc, char **argv) {
  FILE *fp;
  char *buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
  int numbers = 1;
  int i = 2;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      size_t size = 0;
      while ((int)(size = getline(&buff, &size, fp)) != -1) {
        if (buff[strlen(buff) - 1] == '\n' && strlen(buff) == 1) {
          printf("%c", buff[strlen(buff) - 1]);
          continue;
        }
        printf("%6d\t", numbers);
        printLines(buff, size);
        numbers++;
      }
    }
    i++;
    numbers = 1;
    fclose(fp);
  }

  free(buff);
}

void deleteRepeatedStrings(int argc, char **argv) {
  FILE *fp;
  char *buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
  int empty = 0;
  int i = 2;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      size_t size = 0;
      while ((int)(size = getline(&buff, &size, fp)) != -1) {
        if (checkIsEmpty(*buff, &empty)) {
          continue;
        } else {
          printLines(buff, size);
        }
      }
    }
    i++;
    empty = 0;
    fclose(fp);
  }
  free(buff);
}

int checkIsEmpty(char ch, int *empty) {
  int check = 0;

  if (ch == '\n') {
    if (!*empty) {
      *empty = 1;
    } else {
      check = 1;
    }
  } else {
    *empty = 0;
  }
  return check;
}

void tabs(int argc, char **argv) {
  FILE *fp;
  char *buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
  int i = 2;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      size_t size = 0;
      while ((int)(size = getline(&buff, &size, fp)) != -1) {
        for (size_t j = 0; j < size; j++) {
          replaceTabs(buff[j]);
        }
      }
    }
    i++;
    fclose(fp);
  }
  free(buff);
}

void replaceTabs(char ch) {
  char sym;

  if (ch == '\t') {
    printf("^I");
  } else if (checkSymbols(ch)) {
    if (ch == 127) {
      sym = '?';
    } else {
      sym = '@' + ch;
    }
    printf("^%c", sym);
  } else {
    printf("%c", ch);
  }
}

void invalidSymbols(int argc, char **argv) {
  FILE *fp;
  char *buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
  int i = 2;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      size_t size = 0;
      while ((int)(size = getline(&buff, &size, fp)) != -1) {
        for (size_t j = 0; j < size; j++) {
          replaceSymbols(buff[j]);
        }
      }
    }
    i++;
    fclose(fp);
  }
}

void replaceSymbols(char ch) {
  char sym;

  if (checkSymbols(ch)) {
    if (ch == 127) {
      sym = '?';
    } else {
      sym = '@' + ch;
    }
    printf("^%c", sym);
  } else {
    printf("%c", ch);
  }
}

int checkSymbols(char ch) {
  return (ch >= 0 && ch != 9 && ch != 10 && ch <= 31) || ch == 127 ? 1 : 0;
}

void printLines(char *buff, size_t size) {
  for (size_t j = 0; j < size; j++) {
    printf("%c", buff[j]);
  }
}