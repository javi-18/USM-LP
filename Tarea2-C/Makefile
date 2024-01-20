CC=gcc
CFLAGS=-I.

main: codigo.o arbol.o
	$(CC) -o main codigo.o arbol.o

codigo.o: main.c arbol.h
	$(CC) -c main.c

arbol.o: arbol.c arbol.h
	$(CC) -c arbol.c

clean:
	rm -f *.o main