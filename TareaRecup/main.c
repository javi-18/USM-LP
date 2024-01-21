#include "listaElementos.h"
#include <string.h>





int main(){ 
    
    struct TableroCasilla* cabeza = NULL;
    struct TableroCasilla*cabezajugador=NULL; 
    struct Jugador* jugador = malloc(sizeof(struct Jugador));
    
   
    jugador->Puntaje = 0;
    jugador->cantidadDisparos=MAX_DISPAROS;
    
    
    printf("paso1\n");
    FILE* archivo = fopen("entrada.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n"); 
        free(jugador);
        

        return 1;
    }
    printf("paso2\n");
    char linea[100];
    printf("%s",linea);
    int contadorLineas = 0;
    int i=0;
    int x=0;
    int y=0;
    printf("paso3\n");
    while(fgets(linea, sizeof(linea), archivo) != NULL){
        
        if(contadorLineas<6){
            
            jugador->disparos[contadorLineas].tipo=linea[0] - '0';
            jugador->disparos[contadorLineas].efectivo = 0; 
            jugador->disparos[contadorLineas].Utilizar = NULL;
            
            
        }else{
            printf("%d\n",i);
            printf("%d\n",linea[i]);

            agregarelemento(&cabeza, linea[i],x,y);
            if (x==9){
                x=0;
                y++;
            }else{
                x++;
            }
           
        }
        contadorLineas++;
        i++;
    }
    
    fclose(archivo);

    mostrarTablero(cabezajugador);

    printf("Puntaje: %d\n", jugador->Puntaje);
    for (int i = 0; i < jugador->cantidadDisparos; i++) {
        printf("Disparo %d: Tipo %d\n", i + 1, jugador->disparos[i].tipo);
    }
    printf("\n");

    int Disparostotales=0;
    for(int i=0; i<MAX_DISPAROS;i++){
        Disparostotales+=jugador->disparos[i].tipo;
    }
    printf("%d\n", Disparostotales);
 
    int posX, posY;
    int tipdis;
    int tipocantdisp;
    int cantdisparos= 1;
    //int inddisparos=MAX_DISPAROS;
    //int valdisparo= jugador->disparos[0].tipo;
    //int indarr=0;
    //int cantdisparr=1;
    printf("valor posx %d\n " ,posX);
    printf(" valor posy %d\n  " ,posY);
    printf("%d\n valor barcoshundidos ",barcoshundidos(cabeza));

    while (cantdisparos <= Disparostotales){ //&& cantdisparr<=jugador->disparos[indarr].tipo) {
        //&& !barcoshundidos(cabeza)) {
        
        
        printf("Disparoj %d\n", jugador->cantidadDisparos);
        printf("Disparo %d\n",  cantdisparos );
        printf("Ingrese la posición X del disparo:\n ");
        scanf("%d", &posX);
        posX--;
        printf("Ingrese la posición Y del disparo:\n ");
        scanf("%d", &posY);
        posY--;
        getchar(); // Consumir el carácter de nueva línea en el buffer de entrada
        printf("Ingrese tipo del disparo(entre 1-6):\n ");
        scanf("%d",&tipdis);
        tipocantdisp= jugador->disparos[tipdis-1].tipo;
        if(tipocantdisp != 0){
            printf("%d\n",posX); 
            printf("%d\n",posY);
            printf("%d\n", tipocantdisp);

        // Realizar el disparo
        //struct TableroCasilla* casillaDisparo = obtenerCasillaEnPosicion(cabeza, posX, posY);
        if (NULL == NULL) {
            //if (casillaDisparo == NULL) {
            printf("Posición inválida, no se pudo realizar el disparo.\n");
        //} else {
            printf("aqui se cae\n");
            switch(tipdis-1){
                case 0:
                utilizaDisparo(jugador,  tipdis, posX, posY, cabeza);
                break;

                case 1:
                utilizaDisparo(jugador,  tipdis, posX, posY, cabeza);
                if( posX-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX-1, posY, cabeza);
                }
                if(posX+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX+1, posY, cabeza);
                
                }
                break;

                case 2:
                utilizaDisparo(jugador,  tipdis, posX, posY, cabeza);
                if( posY-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX, posY-1, cabeza);
                }
                if( posY+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX, posY+1, cabeza);
                }
                break;

                case 3:
                utilizaDisparo(jugador,  tipdis, posX, posY, cabeza);
                if( posX-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX-1, posY, cabeza);
                }
                if(posX+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX+1, posY, cabeza);
                
                }
                utilizaDisparo(jugador,  tipdis, posX, posY, cabeza);
                if( posY-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX, posY-1, cabeza);
                }
                if( posY+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX, posY+1, cabeza);
                }
                break;

                case 4:
                utilizaDisparo(jugador,  tipdis, posX, posY, cabeza);
                if( posX-1 >=0 && posY+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX-1, posY+1, cabeza);
                }
                if(posX-1 >=0 && posY-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX-1, posY-1, cabeza);
                
                }
                if( posX+1 <=9 && posY+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX+1, posY+1, cabeza);
                }
                if( posX+1 <=9 && posY-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX+1, posY-1, cabeza);
                }
                break;

                case 5:
                utilizaDisparo(jugador,  tipdis, posX, posY, cabeza);
                if( posX-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX-1, posY, cabeza);
                }
                if(posX+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX+1, posY, cabeza);
                
                }
                if( posY-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX, posY-1, cabeza);
                }
                if( posY+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX, posY+1, cabeza);
                }

                if( posX-1 >=0 && posY+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX-1, posY+1, cabeza);
                }
                if(posX-1 >=0 && posY-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX-1, posY-1, cabeza);
                
                }
                if( posX+1 <=9 && posY+1 <=9){
                    utilizaDisparo(jugador,  tipdis, posX+1, posY+1, cabeza);
                }
                if( posX+1 <=9 && posY-1 >=0){
                    utilizaDisparo(jugador,  tipdis, posX+1, posY-1, cabeza);
                }
                break;


            }
            printf("Resultado del disparo:\n");
            //mostrarTablero(cabeza); // Mostrar el tablero después del disparo
        }
        }else{
            printf("No quedan disparos de ese tipo");
        }
        // Restar uno al contador de disparos disponibles del jugador
    cantdisparos++;
}
// Verificar si el jugador ganó o perdió y mostrar el resultado
    /*
   
    if (barcoshundidos(cabeza)) {
        printf("¡Ganaste! Has destruido todos los barcos.\n");
    } else {
        printf("¡Perdiste! Te quedaste sin disparos.\n");
    }
     */
    // Mostrar el puntaje final y el tablero
    printf("Puntaje final: %d\n", jugador->Puntaje);
    mostrarTablero(cabezajugador);

    //struct Disparo disparojugador;
    //Disparoefectivo(&disparojugador);

    liberarTablero(cabezajugador);
    liberarTablero(cabeza);
    free(jugador);

    return 0;
}
