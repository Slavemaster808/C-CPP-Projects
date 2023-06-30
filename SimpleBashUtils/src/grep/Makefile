CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11

all: my_grep

my_grep: my_grep.o main.o
	$(CC) $(CFLAGS) -o my_grep my_grep.o main.o

my_grep.o: my_grep.c
	$(CC) $(CFLAGS) -c my_grep.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf *.o my_grep

run:
	./app