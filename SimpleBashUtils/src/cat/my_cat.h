#ifndef MY_CAT_H
#define MY_CAT_H
#include "../common/common.h"
#define BUFF_SIZE 1024

typedef struct flags {
  int number_nonblank;
  int number;
  int squeeze_blank;
} Flags;

void outputWithNoFlags(int argc, char **argv);

void outputWithFlags(int argc, char **argv);

void dollarSign(int argc, char **argv);

void numbers(int argc, char **argv);

void numbersWOEmpty(int argc, char **argv);

void deleteRepeatedStrings(int argc, char **argv);

int checkIsEmpty(char ch, int *empty);

void tabs(int argc, char **argv);

void replaceTabs(char ch);

void invalidSymbols(int argc, char **argv);

void replaceSymbols(char ch);

int checkSymbols(char ch);

void printLines(char *buff, size_t size);

#endif