#include"Jugador.h"

void inicializarJugador(struct Jugador* jugador){
    jugador->Puntaje = 0;
    jugador->cantidadDisparos = MAX_DISPAROS;
    for(int i=0;i<MAX_DISPAROS;i++){
        jugador->disparos[i].tipo=0;
    }

}


void incrementarpuntaje(struct Jugador* jugador, int cantidad){
    jugador->Puntaje += cantidad;
}




void utilizaDisparo(struct Jugador* jugador, int tipodispar, int posicionX, int posicionY, struct TableroCasilla* cabeza) {
    //if (indice >= 0){ //&& indice < jugador->cantidadDisparos) {
        //struct Disparo* disparo = &(jugador->disparos[tipodispar]);

        //if (disparo != NULL && disparo->Utilizar != NULL) {
            //disparo->Utilizar(posicionX, posicionY);
            //jugador->Puntaje++;

            // Actualizar el tablero con los efectos del disparo
            printf("Elemento de la casilla: %c\n", cabeza->elemento);
            printf("Elemento de la casilla: %c\n", cabeza->posX);
            struct TableroCasilla* casilla = obtenerCasillaEnPosicion(cabeza, posicionX, posicionY);
            struct TableroCasilla* casillajugador = obtenerCasillaEnPosicion(cabeza, posicionX, posicionY);
            //if (casilla != NULL) {
                printf("El elemento de la casilla en la posición (%d, %d) es: %c\n", casilla->posX, casilla->posY, casilla->elemento);
                switch (casilla->elemento) {
                    case 'B':
                        casilla->elemento= 'B'; // Actualizar con el caracter correspondiente al impactar en una parte de barco
                        incrementarpuntaje(jugador, 100);
                        actualizarTablero(casillajugador,posicionX,posicionY,'B');
                        printf("Acertaste el tiro :D\n");
                        break;
                    case '0':
                        casilla->elemento = '0'; // Actualizar con el caracter correspondiente al impactar en una casilla vacía
                        actualizarTablero(casillajugador,posicionX,posicionY,'0');
                        printf("Fallaste el tiro\n");
                        break;
                    case '1':
                        
                    case '2':
                    case '3':
                        casilla->elemento = 'B'; // Actualizar con el caracter correspondiente al impactar en un bonus
                        // Aquí puedes realizar las acciones adicionales correspondientes al bonus
                        break;
                    default:
                        actualizarTablero(casillajugador,posicionX,posicionY,'X');
                        printf("Fallaste el tiro\n");
                        break;

                }
            //}
            jugador->disparos[tipodispar-1].tipo--;
        //}
    //}
}

void agregarbonus(struct Jugador* jugador){
    int cantidadBonus = CANT_BONUS;
    int celda = rand() % MAX_DISPAROS;  // Generar número aleatorio entre 0 y MAX_DISPAROS-1

    if (celda >= 0 && celda < MAX_DISPAROS) {
        jugador->disparos[celda].tipo += cantidadBonus;
    }
}