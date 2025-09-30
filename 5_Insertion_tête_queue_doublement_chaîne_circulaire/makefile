CC = gcc
CFLAGS = -Wall -std=c99

all: main

main: main.o fonctions.o
	$(CC) $(CFLAGS) main.o fonctions.o -o main

main.o: main.c fonctions.h
	$(CC) $(CFLAGS) -c main.c

fonctions.o: fonctions.c fonctions.h
	$(CC) $(CFLAGS) -c fonctions.c

clean:
	rm -f *.o main
