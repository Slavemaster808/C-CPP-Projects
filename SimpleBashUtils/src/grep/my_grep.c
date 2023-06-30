#include "my_grep.h"

void outputWithNoFlags(int argc, int n, int check, char flag, char **argv) {
  FILE *fp;
  int i;

  i = check == 0 ? 2 : 3;
  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp && flag == 's') {
      break;
    }
    if (!fp) {
      printf("No such file.");
    } else {
      char buff[BUFF_SIZE];
      char *substr;
      char *circum;
      while (fgets(buff, BUFF_SIZE - 1, fp)) {
        if (argv[check + 1][0] == '^') {
          circum = strtok(argv[check + 1], "^");
          substr = strstr(buff, circum);
        } else {
          substr = strstr(buff, argv[check + 1]);
        }
        if (substr && n > 1 && flag != 'h') {
          if (argv[check + 1][0] == '^' && isBeginning(circum, buff) == 1) {
            printLines(buff, argv[i]);
          } else if (argv[check + 1][0] != '^') {
            printLines(buff, argv[i]);
          }
        } else if (substr || (substr && flag == 'h')) {
          if (argv[check + 1][0] == '^' && isBeginning(circum, buff) == 1) {
            printLines(buff, NULL);
          } else if (argv[check + 1][0] != '^') {
            printLines(buff, NULL);
          }
        }
      }
    }
    i++;
    fclose(fp);
  }
}

int isBeginning(char *str, char *buff) {
  size_t check = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == buff[i]) {
      check++;
    }
  }
  return check == strlen(str) ? 1 : 0;
}

void printLinesWOSpaces(char *buff, char *line) {
  if (line != NULL) {
    if (buff[0] != ' ') {
      if (buff[strlen(buff) - 1] == '\n') {
        buff[strlen(buff) - 1] = '\0';
        printf("%s:%s\n", line, buff);
      } else {
        printf("%s:%s\n", line, buff);
      }
    }
  } else {
    if (buff[0] != ' ') {
      if (buff[strlen(buff) - 1] == '\n') {
        buff[strlen(buff) - 1] = '\0';
        printf("%s\n", buff);
      } else {
        printf("%s\n", buff);
      }
    }
  }
}

void printLines(char *buff, char *line) {
  if (line != NULL) {
    if (buff[strlen(buff) - 1] == '\n') {
      buff[strlen(buff) - 1] = '\0';
      printf("%s:%s\n", line, buff);
    } else {
      printf("%s:%s\n", line, buff);
    }
  } else {
    if (buff[strlen(buff) - 1] == '\n') {
      buff[strlen(buff) - 1] = '\0';
      printf("%s\n", buff);
    } else {
      printf("%s\n", buff);
    }
  }
}

void outputWithFlags(int argc, int n, int check, char flag, char **argv) {
  if (argv[1][0] == '-') {
    switch (argv[1][1]) {
      case 'e':
        outputWithNoFlags(argc, n, check, flag, argv);
        break;
      case 'c':
        countLines(argc, n, check, argv);
        break;
      case 'v':
        invertMatch(argc, n, check, argv);
        break;
      case 'n':
        numberLine(argc, n, check, argv);
        break;
      case 'l':
        matchingFiles(argc, check, argv);
        break;
      case 'i':
        ignoreCases(argc, n, check, argv);
        break;
      case 'h':
        outputWithNoFlags(argc, n, check, flag, argv);
        break;
      case 'o':
        matchedParts(argc, n, check, argv);
        break;
      case 's':
        outputWithNoFlags(argc, n, check, flag, argv);
        break;
      case 'f':
        searchPatterns(argc, n, check, argv);
        break;
      default:
        printf("No such flag.");
        break;
    }
  }
}

void searchPatterns(int argc, int n, int check, char **argv) {
  FILE *fp;
  int i = check == 0 ? 2 : 3;

  FILE *pattern;
  pattern = fopen(argv[check + 1], "rb");
  if (!pattern) {
    printf("No such pattern.");
  } else {
    while (i < argc) {
      fp = fopen(argv[i], "rb");
      if (!fp) {
        printf("No such file.");
      } else {
        char buff[BUFF_SIZE];
        char temp_str[BUFF_SIZE];
        char *substr;
        int iter = 0;
        while (fgets(temp_str, BUFF_SIZE - 1, pattern)) {
          if (temp_str[strlen(temp_str) - 1] == '\n') {
            temp_str[strlen(temp_str) - 1] = '\0';
          }
          if (iter >= 1 &&
              checkRepeated(argv[check + 1], temp_str, iter) == 1) {
            iter++;
            continue;
          }
          while (fgets(buff, BUFF_SIZE - 1, fp)) {
            substr = strstr(buff, temp_str);
            if (substr && n > 1) {
              printLines(buff, argv[i]);
            } else if (substr && n == 1) {
              printLines(buff, NULL);
            }
          }
          fseek(fp, 0, SEEK_SET);
          iter++;
        }
      }
      i++;
      fclose(fp);
      fseek(pattern, 0, SEEK_SET);
    }
  }
  fclose(pattern);
}

int checkRepeated(char *pattern, char *str, int iter) {
  FILE *ptr;
  char temp_str[BUFF_SIZE];
  int check = 0;
  int i = 0;

  ptr = fopen(pattern, "rb");
  while (fgets(temp_str, BUFF_SIZE - 1, ptr)) {
    if (temp_str[strlen(temp_str) - 1] == '\n') {
      temp_str[strlen(temp_str) - 1] = '\0';
    }
    if (strcmp(str, temp_str) == 0 && iter != i) {
      check++;
    }
    i++;
  }
  fclose(ptr);
  return check > 0 ? 1 : 0;
}

void ignoreCases(int argc, int n, int check, char **argv) {
  FILE *fp;
  int i = check == 0 ? 2 : 3;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      char buff[BUFF_SIZE];
      char *substr;
      while (fgets(buff, BUFF_SIZE - 1, fp)) {
        substr = strcasestr(buff, argv[check + 1]);
        if (substr && n > 1) {
          printLines(buff, argv[i]);
        } else if (substr && n == 1) {
          printLines(buff, NULL);
        }
      }
    }
    i++;
    fclose(fp);
  }
}

void countLines(int argc, int n, int check, char **argv) {
  FILE *fp;
  int cnt = 0;
  int i = check == 0 ? 2 : 3;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      char buff[BUFF_SIZE];
      char *substr;
      char *circum;
      if (n > 1) {
        while (fgets(buff, BUFF_SIZE - 1, fp)) {
          if (argv[check + 1][0] == '^') {
            circum = strtok(argv[check + 1], "^");
            substr = strstr(buff, circum);
          } else {
            substr = strstr(buff, argv[check + 1]);
          }
          if (substr && argv[check + 1][0] == '^' &&
              isBeginning(circum, buff)) {
            cnt++;
          } else if (substr && argv[check + 1][0] != '^') {
            cnt++;
          }
        }
        printf("%s:%d\n", argv[i], cnt);
        cnt = 0;
      } else {
        while (fgets(buff, BUFF_SIZE - 1, fp)) {
          if (argv[check + 1][0] == '^') {
            circum = strtok(argv[check + 1], "^");
            substr = strstr(buff, circum);
          } else {
            substr = strstr(buff, argv[check + 1]);
          }
          if (substr && argv[check + 1][0] == '^' &&
              isBeginning(circum, buff)) {
            cnt++;
          } else if (substr && argv[check + 1][0] != '^') {
            cnt++;
          }
        }
        printf("%d\n", cnt);
      }
    }
    i++;
    fclose(fp);
  }
}

void invertMatch(int argc, int n, int check, char **argv) {
  FILE *fp;
  int i = check == 0 ? 2 : 3;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      char buff[BUFF_SIZE];
      char *substr;
      while (fgets(buff, BUFF_SIZE - 1, fp)) {
        substr = strstr(buff, argv[check + 1]);
        if (!substr && n > 1) {
          printLines(buff, argv[i]);
        } else if (!substr) {
          printLines(buff, NULL);
        }
      }
    }
    i++;
    fclose(fp);
  }
}

void numberLine(int argc, int n, int check, char **argv) {
  FILE *fp;
  int i = check == 0 ? 2 : 3;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      char buff[BUFF_SIZE];
      char *substr;
      int num = 1;
      if (n > 1) {
        while (fgets(buff, BUFF_SIZE - 1, fp)) {
          substr = strstr(buff, argv[check + 1]);
          if (substr) {
            if (buff[strlen(buff) - 1] == '\n') {
              buff[strlen(buff) - 1] = '\0';
              printf("%s:%d:%s\n", argv[i], num, buff);
              num++;
            } else {
              printf("%s:%d:%s", argv[i], num, buff);
              num++;
            }
          } else {
            num++;
          }
        }
      } else {
        while (fgets(buff, BUFF_SIZE - 1, fp)) {
          substr = strstr(buff, argv[check + 1]);
          if (substr) {
            if (buff[strlen(buff) - 1] == '\n') {
              buff[strlen(buff) - 1] = '\0';
              printf("%d:%s\n", num, buff);
              num++;
            } else {
              printf("%d:%s", num, buff);
              num++;
            }
          } else {
            num++;
          }
        }
      }
    }
    i++;
    fclose(fp);
  }
}

void matchingFiles(int argc, int check, char **argv) {
  FILE *fp;
  int i = check == 0 ? 2 : 3;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      char buff[BUFF_SIZE];
      char *substr;
      int check_ = 0;
      while (fgets(buff, BUFF_SIZE - 1, fp) && check_ == 0) {
        substr = strstr(buff, argv[check + 1]);
        if (substr) {
          check_ = 1;
        }
      }
      if (check_ == 1) {
        printf("%s\n", argv[i]);
      }
    }
    i++;
    fclose(fp);
  }
}

void matchedParts(int argc, int n, int check, char **argv) {
  FILE *fp;
  int i = check == 0 ? 2 : 3;

  while (i < argc) {
    fp = fopen(argv[i], "rb");
    if (!fp) {
      printf("No such file.");
    } else {
      char buff[BUFF_SIZE];
      char *substr;
      char *circum;
      while (fgets(buff, BUFF_SIZE - 1, fp)) {
        if (argv[check + 1][0] == '^') {
          circum = strtok(argv[check + 1], "^");
          substr = strstr(buff, circum);
        } else {
          substr = strstr(buff, argv[check + 1]);
        }
        if (substr && n > 1) {
          if (argv[check + 1][0] == '^' && isBeginning(circum, buff)) {
            printf("%s:%s\n", argv[i], circum);
          } else if (argv[check + 1][0] != '^') {
            printf("%s:%s\n", argv[i], argv[check + 1]);
          }
        } else if (substr && n == 1) {
          if (argv[check + 1][0] == '^' && isBeginning(circum, buff)) {
            printf("%s\n", circum);
          } else if (argv[check + 1][0] != '^') {
            printf("%s\n", argv[check + 1]);
          }
        }
      }
    }
    i++;
    fclose(fp);
  }
}