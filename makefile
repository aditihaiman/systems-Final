ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif


all: main.o monsters.o forest.o desert.o
	$(CC) -o program main.o monsters.o forest.o desert.o

main.o: main.c players.h
	$(CC) -c main.c

monsters.o: monsters.c players.h
	$(CC) -c monsters.c

forest.o: forest.c players.h
	$(CC) -c forest.c

desert.o: desert.c players.h
	$(CC) -c desert.c

run: 
	./program