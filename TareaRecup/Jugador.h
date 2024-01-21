#ifndef JUGADOR_H
#define JUGADOR_H
#include<stdio.h>
#include<stdlib.h>
#include "Disparos.h"
#include "listaElementos.h"
#define MAX_DISPAROS 6
#define CANT_BONUS 1
struct TableroCasilla;

struct Jugador
{
int Puntaje; //inicialmente igual a cero
struct Disparo disparos[MAX_DISPAROS]; // Utilizar un puntero a Disparo
int cantidadDisparos;
};

void inicializarJugador(struct Jugador* jugador);
void incrementarpuntaje(struct Jugador* jugador, int cantidad);
void utilizaDisparo(struct Jugador* jugador, int tipodispar, int posicionX, int posicionY, struct TableroCasilla* cabeza);
void agregarbonus(struct Jugador* jugador);
#endif  // Fin de la guarda de inclusión JUGADOR_H

