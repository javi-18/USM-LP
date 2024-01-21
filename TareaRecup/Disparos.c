#include "Disparos.h"
#include <stdlib.h>
#include<stdio.h>

void iniciarDisapro(struct Disparo* disparo, void (*Utilizar)(int, int), int tipo){
    disparo->Utilizar = Utilizar;
    disparo->tipo = tipo;
}

void usarDisparo(struct Disparo *disparo,int posX, int posY){
    if (disparo->Utilizar != NULL) {
        disparo->Utilizar(posX, posY);
    }
    printf("Disparo efectuado en la posicion (%d,%d)\n",posX,posY);
}
void Disparoefectivo(struct Disparo* disparo){
    disparo->efectivo = 1;
}
