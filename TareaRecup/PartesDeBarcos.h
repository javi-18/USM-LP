#include <stdio.h>
#include <stdlib.h>

struct ParteBarco
{
void (*acierto)(void *);
int destruida;
};

void inicializarBarco(struct ParteBarco *parte);
void destruido(struct ParteBarco *parte);
void acertado(void*parte);