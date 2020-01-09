ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif


all: main.o monsters.o
	$(CC) -o program main.o monsters.o

main.o: main.c players.h
	$(CC) -c main.c

monsters.o: monsters.c players.h
	$(CC) -c monsters.c

run: 
	./program