#ifndef LISTAELEMENTOS_H
#define LISTAELEMENTOS_H
#include "Bonus.h"
#include "PartesDeBarcos.h"
#include "Jugador.h"
#include <stdio.h>
#include <stdlib.h>


struct TableroCasilla{
    char elemento;
    struct TableroCasilla*siguiente;
    struct Bonus*bonus;
    struct ParteBarco*partebarco;
    struct Jugador* jugador;
    int posX;
    int posY;
 
    
};
struct TableroCasilla* crearCasilla(char elemento,int posX,int posY);
void agregarelemento(struct TableroCasilla** cabeza, char elemento, int posX, int posY);
void liberarTablero(struct TableroCasilla* cabeza);
void mostrarTablero(struct TableroCasilla* cabeza);
struct TableroCasilla* obtenerCasillaEnPosicion(struct TableroCasilla* cabeza, int posicionX, int posicionY);
void actualizarTablero(struct TableroCasilla* cabeza, int posX, int posY, char nuevoValor);
int barcoshundidos(struct TableroCasilla* cabeza);
#endif  