Javiera Bobadilla 
202173584-4

Todas las funciones fueron programadas y ejecutdas usando la version 8.9 [cs]

Para la primera funcion se asume que siempre se entregara una lista que contiene al menos 1 bit para probar funcion ya que la funcion no acepta listas vacías

Para las funciones decode e integrar se entregan 2 versiones de la funciones donde la primera usa la recursion simple y la segunda usa la recursion de cola,aunque se recomienda probar los ejemplos usando el Debug de DrRacket para comprobar el uso de ambas recursiones 

Para probar las funciones integrar y map_arbol se recomienda colocar los siguientes formatos para probar los ejemplos, para que sea más rápido

-map_arbol
(define arbol-ejemplo '(2 (3 () ()) (4 (3 (5 () ()) ()) (3 (8 () ()) ())))) -->
(define camino-ejemplo '(0))
(define (f x) (* x x))

(map_arbol arbol-ejemplo camino-ejemplo f) 

-integrar_cola
(displayln (integrar_cola 0 1 100 (lambda (x) (* x x))))
(newline)
(otro ejemplo)

-integrar_simple
(displayln (integrar_simple 0 1 100 (lambda (x) (* x x))))
(newline)