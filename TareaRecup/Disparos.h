#include<stdio.h>
#include <stdlib.h>


struct Disparo
{
void (*Utilizar)(int posicionX, int posicionY);
int tipo;
int efectivo;
};

void iniciarDisapro(struct Disparo* disparo, void (*Utilizar)(int, int), int tipo);
void usarDisparo(struct Disparo *disparo,int posX, int posY);
void Disparoefectivo(struct Disparo* disparo);
