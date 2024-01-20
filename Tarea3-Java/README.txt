Javiera  Francisca Bobadilla Cornejo 
202173584-4

Para la creacion de esta tarea se utilizo el IDE IntelliJ 2023.1.1 con la version java 17.0.7 2023-04-18 LTS

Instrucciones de ejecucion:
Se debe tener el archivo makefile y la carpeta Tarea3LP en el mismo directorio, dentro de la carpeta deben estar todos los archivos .java , incluyendo el main.
Para ejecutar, se debe escribir en consola "make".

Se agrego la siguiente clase para la creacion del juego:s
	-Vacio : Representa lugares vacios en el mapa
	

Consideraciones:
	-En una pelea, el jugador y enemigo alternan golpes hasta que uno muera
	-Si por random se genera un mundo sin enemigos, cualquier movimiento avanzara el mundo al siguiente nivel, asi hasta que se encuentre en un mundo con enemigos.
	

Controles:
	
	Movimiento:

	"w" : moverse hacia arriba
	"s" : moverse hacia abajo
	"a" : moverse hacia izquierda
	"d" : moverse hacia derecha

	Acciones:

	"i" : Mostrar inventario y los datos de cada item
	"q" : Mostrar estadisticas (todos los datos del jugador)
	"equipar" : Muestra una mini lista del inventario, y pide elegir un objeto a equipar con su numero en la lista.
	"salir" : Termina el juego