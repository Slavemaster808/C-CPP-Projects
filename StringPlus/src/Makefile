CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
FUNC=my_string.c
FUNC_LIB=my_string.o
CHECKFLAGS = $(shell pkg-config --libs --cflags check)

.PHONY: all clean rebuild

all: my_string.a

build: main.o my_string.o
	$(CC) $(CFLAGS) -o my_string main.o my_string.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

my_string.o:
	gcc $(FLAGS) -c $(FUNC) my_string.h

my_string.a: my_string.o
	ar rc my_string.a $(FUNC_LIB)
	ranlib my_string.a

test: my_string.a 
	$(CC) $(FLAGS) --coverage my_string.c tests/*.c $(CHECKFLAGS) -o my_string_test
	./my_string_test

test4u: my_string.a 
	$(CC) $(FLAGS) -D UBUNTU_PEER --coverage my_string.c tests/*.c -lcheck -o my_string_test -lsubunit -lm
	./my_string_test

gcov_report: test
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info
	open ./report/index.html

gcov_report4u: test4u
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info

check:
	clang-format -style=google -i *.c
	clang-format -style=google -i *.h

leaks: rebuild test
	leaks -atExit -- ./my_string_test

valgrind: rebuild test
	valgrind --tool=memcheck --leak-check=yes ./my_string_test

valgrind4u: rebuild test4u
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./my_string_test

clean:
	rm -rf *.o out *.info *.gcda *.gcno *.gcov *.gch *.out *.a my_string_test my_string
	rm -rf report

rebuild: clean all