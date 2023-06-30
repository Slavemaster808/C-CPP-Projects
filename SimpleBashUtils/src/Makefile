CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC_DIR=.
CAT_DIR=$(SRC_DIR)/cat
GREP_DIR=$(SRC_DIR)/grep
COMMON_DIR=$(SRC_DIR)/common
TEST_DIR=$(SRC_DIR)/../tests

all: my_cat my_grep test

my_cat: cat/my_cat.o cat/main.o
	$(CC) $(CFLAGS) -o cat/my_cat cat/my_cat.o cat/main.o

my_cat.o: cat/my_cat.c
	$(CC) $(CFLAGS) -c cat/my_cat.c

my_grep: grep/my_grep.o grep/main.o
	$(CC) $(CFLAGS) -o grep/my_grep grep/my_grep.o grep/main.o

my_grep.o: grep/my_grep.c
	$(CC) $(CFLAGS) -c grep/my_grep.c

main.o: grep/main.c cat/main.c
	$(CC) $(CFLAGS) -c grep/main.c cat/main.c

test: my_cat my_grep
	bash $(TEST_DIR)/t_cat.sh $(TEST_DIR)/test $(CAT_DIR)
	bash $(TEST_DIR)/t_grep.sh $(TEST_DIR)/test $(GREP_DIR)
	cat log.txt
	rm -rf log.txt

lint:
	clang-format -n -style=Google --verbose cat/*.c cat/*.h
	clang-format -n -style=Google --verbose grep/*.c grep/*.h
	clang-format -i -style=Google --verbose cat/*.c cat/*.h
	clang-format -i -style=Google --verbose grep/*.c grep/*.h

clean:
	rm -rf grep/*.o grep/my_grep cat/*.o cat/my_cat