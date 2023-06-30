#ifndef MY_GREP_H
#define MY_GREP_H
#include "../common/common.h"
#define BUFF_SIZE 1024

void outputWithNoFlags(int argc, int n, int check, char flag, char **argv);

void outputWithFlags(int argc, int n, int check, char flag, char **argv);

void ignoreCases(int argc, int n, int check, char **argv);

void countLines(int argc, int n, int check, char **argv);

void invertMatch(int argc, int n, int check, char **argv);

void numberLine(int argc, int n, int check, char **argv);

void matchingFiles(int argc, int check, char **argv);

void matchedParts(int argc, int n, int check, char **argv);

int isBeginning(char *str, char *buff);

void printLines(char *buff, char *line);

void printLinesWOSpaces(char *buff, char *line);

void searchPatterns(int argc, int n, int check, char **argv);

int checkRepeated(char *pattern, char *str, int iter);

#endif