all: main

teste: main.c complexo.c
	gcc main.o complexo.o -o teste

main.o: main.c
	gcc -c main.c

complexos.o: complexos.c complexos.h
	gcc -c complexos.c