CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I.


SOURCES = main.c Bonus.c PartesDeBarcos.c Disparos.c Jugador.c listaElementos.c


OBJECTS = $(SOURCES:.c=.o)


EXECUTABLE = main


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@


clean:
	rm -f $(OBJECTS) $(EXECUTABLE)