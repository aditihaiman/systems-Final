all: main.o monsters.o
	gcc -o program main.o

main.o: main.c players.h
	gcc -c main.c

monsters.o: monsters.c players.h
	gcc -c monsters.c

run: 
	./program