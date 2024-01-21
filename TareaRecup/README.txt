Nombre: Javiera Bobadilla
Rol: 202173584-4

Para ejecutar el programa se debe escribir make directamente dentro de la consola, el cual ejecutar el makefile que se adjunta dentro de esta tarea, el cual permite compilar todos los archivos adjuntos main.c Bonus.c PartesDeBarcos.c Disparos.c Jugador.c ListaElementos.c, donde cada uno incluye todos los archivos.h correspondientes. Con esto se genera este ejecutable "main.o Bonus.o PartesDeBarcos.o Disparos.o Jugador.o listaElementos.o -o main"

Para ejecutar el programa basta con escribi ./main directamente dentro de la consola y si se quiere volver a ejecutar primero se debe usar el comando make clean para eliminar todos los ejecutables y volver a escribir ./main dentro de la consola 

El programa fue programado y probado en Visual studiuo Code usando el subsistema de Linux (Wsl) para compilar y crear el makefile para ejecutar el codigo

Instrucciones de juego:
- Una vez se ejecuta el programa, se debe ingresar las coordenadas que el jugador quiera, para asi efectuar un disparo el cual mostrara el efecto de ese disparo ejecutado revelando lo que contiene esa casilla

-Esto se ejecutara hasta que el jugador se quede sin disparos o hasta que hunda todos los barcos
Actualizacion: se carga la matriz con los elementos del archivo txt  a causa de un segmentation fault no permite generar correctamente los disparos, el cual se intento de muchas maneras de corregirlo 
pero generaba una carga no adecuada de los datos en la matriz, o generaba comportamientos extraños en el programa 
Para un mejor manejo se decidio usar un archivo txt con los elementos de la matriz sin las tabulaciones como se entrega en este archivo tar.gz