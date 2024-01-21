#include "listaElementos.h"
#define FILAS 10
#define COLUMNAS 10

struct TableroCasilla* crearCasilla(char elemento,int posX,int posY){
    struct TableroCasilla* nuevoNodo = malloc(sizeof(struct TableroCasilla));
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->posX= posX;
    nuevoNodo->posY= posY;
    return nuevoNodo;
}


void agregarelemento(struct TableroCasilla** cabeza, char elemento, int posX, int posY) {
   struct TableroCasilla* nuevaCasilla = crearCasilla(elemento, posX, posY);
    
    if (*cabeza == NULL) {
        *cabeza = nuevaCasilla;
    } else {
        struct TableroCasilla* casillaActual = *cabeza;
        while (casillaActual->siguiente != NULL) {
            casillaActual = casillaActual->siguiente;
        }
        casillaActual->siguiente = nuevaCasilla;
    }
        
    }



    

    
    


void liberarTablero(struct TableroCasilla* cabeza){
    struct TableroCasilla* nodoActual = cabeza;
    while (nodoActual != NULL) {
        struct TableroCasilla* nodoSiguiente = nodoActual->siguiente;
        free(nodoActual);
        nodoActual = nodoSiguiente;
        
    }

}


void mostrarTablero(struct TableroCasilla* cabeza){
    
    struct TableroCasilla* casillaActual = cabeza;
    char matriz[FILAS][COLUMNAS];
    

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = '0';
        }
    }
    int fila = 0, columna = 0;
    while (casillaActual != NULL && fila < FILAS) {
        matriz[fila][columna] = casillaActual->elemento;
        //casillaActual->posX=columna;
        //casillaActual->posY=fila;

        columna++;
        if (columna >= COLUMNAS) {
            columna = 0;
            fila++;
        }

        casillaActual = casillaActual->siguiente;
    }
    
    printf("    "); // Añade espacios antes de los números de fila
    for (int j = 0; j < COLUMNAS; j++) {
        printf("%-2d ", j);  // Muestra los números de columna
    }
    printf("\n");

    for (int i = 0; i < FILAS; i++) {
        printf("%-2d  ", i);// Muestra el número de fila con dos espacios
        for (int j = 0; j < COLUMNAS; j++) {
            printf("[%c]", matriz[i][j]);  // Muestra el elemento
        }
        printf("\n");
    }
}

struct TableroCasilla* obtenerCasillaEnPosicion(struct TableroCasilla* cabeza, int posicionX, int posicionY){
    struct TableroCasilla* casillaActual = cabeza;
    printf("Dirección de la casilla: %p\n", (void*)casillaActual);
    while (casillaActual != NULL) {
        // Comprueba si las coordenadas de la casilla actual coinciden con las especificadas
        if (casillaActual->posX == posicionX && casillaActual->posY == posicionY) {
            return casillaActual;
        }
        casillaActual = casillaActual->siguiente;
    }
    return NULL;

}

void actualizarTablero(struct TableroCasilla* cabeza, int posX, int posY, char nuevoValor){
    struct TableroCasilla* casilla = obtenerCasillaEnPosicion(cabeza, posX, posY);
    if (casilla != NULL) {
        casilla->elemento = nuevoValor;
    }
}

int barcoshundidos(struct TableroCasilla* cabeza) {
    struct TableroCasilla* casilla = cabeza;
    printf("Value of casilla pointer: %p\n", (void*)casilla);

    while (casilla != NULL) {
        

        //printf("casilla->partebarco->destruida: %d\n", casilla->partebarco->destruida);

        if (casilla->partebarco != NULL){ //&& !casilla->partebarco->destruida) {
            printf("entro al if casilla->partebarco != NULL\n");
            return 0; // Hay al menos un barco que no se ha hundido
        }else{
            printf("entro al if casilla->partebarco = NULL\n");
            return 1; // Todos los barcos se han hundido
        }
        casilla = casilla->siguiente;
        
    }
    return 100;
}


//printf("El elemento de la casilla en la posición (%d, %d) es: %c\n", casillaActual->posX, casillaActual->posY, casillaActual->elemento);
 