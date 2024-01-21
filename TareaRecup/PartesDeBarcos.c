#include "PartesDeBarcos.h"

void inicializarBarco(struct ParteBarco *parte){
    parte->acierto=acertado;
    parte->destruida= 0;
}

void acertado(void*parte){
     if (parte != NULL) {
        struct ParteBarco* parteBarco = (struct ParteBarco*)parte;
        parteBarco->destruida = 1;
        printf("Le diste a un barco :D !\n");
    }
}


void destruido(struct ParteBarco *parte){
    parte->destruida= 1;
}