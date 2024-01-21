#include "Bonus.h"

void inicializarBonus(struct Bonus* bonus, void (*activar)(void*), int tipo, int cantidad){
   bonus->activar = activar;
   bonus->tipo = tipo;
   bonus->cantidad = cantidad;
}

void activarbonus(struct Bonus *bonus){
     if(bonus->activar!=NULL){
        bonus->activar(bonus);
     }
}