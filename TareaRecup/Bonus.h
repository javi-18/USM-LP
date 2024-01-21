#include<stdio.h>
#include <stdlib.h>


struct Bonus
{
void (*activar)(void *);
int tipo;
int cantidad;
};

void inicializarBonus(struct Bonus* bonus, void (*activar)(void*), int tipo, int cantidad);
void activarbonus(struct Bonus *bonus);