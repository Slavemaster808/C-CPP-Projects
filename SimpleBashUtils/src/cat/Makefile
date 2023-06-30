CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11

all: my_cat

my_cat: my_cat.o main.o
	$(CC) $(CFLAGS) -o my_cat my_cat.o main.o

my_cat.o: my_cat.c
	$(CC) $(CFLAGS) -c my_cat.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf *.o my_cat

run:
	./app