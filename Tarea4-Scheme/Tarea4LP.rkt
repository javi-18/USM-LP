#lang scheme
#|---------------------------------------------------------------------------------------------------|#
 ;; recibe una lista de bits, la cual se recorre y devuelve una lista que contiene el tamaño de cada bloque que tienen el mismo valor del bit  .
  ;;
  ;; lista-bits : lista que contiene bloques de distintos tamaños compuestos de 0's o 1's
  ;; 

(define (encode-bits lista-bits)
  (define(cont-bloques bits cont-bloque bit-actual)
    (cond ((null? bits) (cons (first cont-bloque) (rest cont-bloque)))
          ((= (first bits) bit-actual)
           (cont-bloques (rest bits) (cons (+ (first cont-bloque) 1) (rest cont-bloque)) bit-actual))
          (else
           (cont-bloques (rest bits) (cons 1 cont-bloque) (first bits)))))

  (let((primer-bit(first lista-bits)))
    (if(= primer-bit 1)
        (cons 0 (reverse (cont-bloques (rest lista-bits) (cons 1 '()) primer-bit)))
        (reverse (cont-bloques (rest lista-bits) (cons 1 '()) primer-bit)))))

 #|---------------------------------------------------------------------------------------------------|#
;; recibe una lista de numeros, la cual se recorre y devuelve una lista de bits el tamaño de cada bloque que tienen el mismo valor del bit  .
  ;; esta funcion se presenta en su version usando recursion simple y de cola 
  ;; lista-bloques : lista de enteros que contiene el tamaño de los distintos bloques que pueden corresponder a 0's o 1's de la lista de bits utilizada en la funcion anterior
;; 


(define decode-simple
  (lambda (code)
    (let encode_rec ( (l_bitresult '())(bits_rst code) (num_act 0) )
      (cond
        ((null? bits_rst) (reverse l_bitresult))

        
        ((> (first bits_rst) 0)
         (encode_rec (cons num_act l_bitresult) (cons (- (first bits_rst) 1) (rest bits_rst)) num_act ))
        
        
        (else
         (if(= num_act 0)
            (encode_rec l_bitresult (rest bits_rst) 1)
            (encode_rec l_bitresult (rest bits_rst) 0)))))))


(define decode
  (lambda (code)
    (letrec ((decode_cola
              (lambda (bits_rst num_act l_bitresult)
                (if (null? bits_rst)
                    (reverse l_bitresult)
                    (decode_cola (cdr bits_rst) (if (= num_act 0) 1 0) (append (make-list (car bits_rst) num_act) l_bitresult))))))
      (decode_cola code 0 '()))))






 #|---------------------------------------------------------------------------------------------------|#
 ;; funcion auxiliar que hace la parte de la sumatoria para calcular la integral de un numero entre el intervalo[a,b] .
  ;;
  ;; esta funcion no tiene parametros como tal si no que tiene una funcion lambda que tiene los siguientes parametros
  ;; a:parametro que se convierte en numero, el cual corresponde a la cota inferior del intervalo del cual se evalua
 ;; b: parametro que se convierte en numero, el cual corresponde a la cota superior del intervalo del cual se evalua
;; n:parametro que se convierte en numero, el cual se usara como parte del limite superior de la sumatoria, además de ser parte de ciertas divisiones que forman parte de la expresion entregada
;; f: es una funcion, la cual recibirá los numeros a y b para evaluar dentro de la expresion 


(define sumatoria
  (lambda (a b n f)
    (let suma ((num_1 a) (num_2 b) (num_3 n) (func f) (resultado 0) (k 1))
      (if (> num_3 k)
          (suma num_1 num_2 num_3 func (+ resultado (func (+ num_1 (* (/ (- num_2 num_1) num_3) k)))) (+ k 1))
      resultado))))

;; funcion que realiza la integral entre un intervalo [a,b],usando la definicion entregada  .
  ;; esta funcion utiliza la recursion simple 
  ;; esta funcion no tiene parametros como tal si no que tiene una funcion lambda y llama a la funcion sumatoria para calcular su valor
  ;; 
(define integrar_simple
  (lambda (a b n f) 
     (let ((resultado (/ (- b a) n)))
       (exact->inexact
        (* resultado (+ (+ (/ (f a) 2) (/ (f b) 2)) (sumatoria a b n f)))))))


;; funcion que realiza la integral entre un intervalo [a,b],usando la definicion entregada  .
  ;; esta funcion utiliza la recursion de cola
  ;; esta funcion no tiene parametros como tal si no que tiene una funcion sumatoria y una funcion auxiliar para calcular el valor de la integral 
  ;; 

(define (integrar_cola a b n f)
  (define dx (/ (- b a) n))

  (define (sumatoria_cola k sum)
    (if (> k (- n 1))
        sum
        (sumatoria_cola (+ k 1) (+ sum (f (+ a (* k dx)))))))

  (define (integrar-aux k acumul)
    (if (> k (- n 1))
        (* (/ (- b a) n)
           (+ (/ (f a) 2)
              (/ (f b) 2)
              acumul))
        (integrar-aux (+ k 1)
                         (+ acumul (f (+ a (* k dx)))))))

  (integrar-aux 1 0))

 #|---------------------------------------------------------------------------------------------------|#
;; recibe un arbol binario, el camino a seguir, la cual es una lista de 0 's y 1's y una funcion lambda .
  ;; sus parametros son los siguientes:
  ;; arbol : corresponde a un arbol binario el cual se representa como una lista de listas, siendo el primer elemento la raiz, seguido de una primera lista que representa su rama izquierda
  ;; y otra lista que representa la rama derecha
;; camino: es una lista de bits que representa el camino o recorrido, el cual va a operar la función
;; f: una funcion que toma todos los hijos de la rama escogida por el camino y opera con ellos
;; f2: una funcion auxiliar que toma los hijos de la rama del arbol que no son tomados por la funcion f, además utilizarse en la recursión
(define (map-arbol arbol camino f f2)
  (cond
    ((null? arbol) '())
    ((null? camino) arbol)
    (else
     (if (= (first camino) 1)
         (cons (f (first arbol))
               (list (map-arbol (cadr arbol) (rest camino) (lambda (x) (+ x 0)) (lambda (x) (+ x 0)))
                     (map-arbol (caddr arbol) (rest camino) f2 f2)))
         (cons (f (first arbol))
               (list (map-arbol (cadr arbol) (rest camino) f2 f2)
                     (map-arbol (caddr arbol) (rest camino) (lambda (x) (+ x 0)) (lambda (x) (+ x 0)))))))))

(define (map_arbol arbol camino f)
  (map-arbol arbol (append camino '(1)) f f))





"Encode:"
(encode-bits  '(0 0 0 1 1 0 1 1 1 0 0 0))
'(3 2 1 3 3)
(newline)

(encode-bits  '(1 1 0 1 1 1 0 0 0))
'(0 2 1 3 3)
(newline)

(encode-bits  '(1 0 1 0))
'(0 1 1 1 1)
(newline)

(encode-bits  '(0 0 0 0))
'(4)
(newline)

"Decode simple:"

(decode-simple '(3 2 1 3 3))
'(0 0 0 1 1 0 1 1 1 0 0 0)
(newline)
(decode-simple '(0 2 1 3 3))
'(1 1 0 1 1 1 0 0 0)
(newline)
(decode-simple '(0 1 1 1 1))
'(1 0 1 0)
(newline)
(decode-simple '(4))
'(0 0 0 0)
(newline)

"Decode cola:"

(decode '(3 2 1 3 3))
'(0 0 0 1 1 0 1 1 1 0 0 0)
(newline)
(decode '(0 2 1 3 3))
'(1 1 0 1 1 1 0 0 0)
(newline)
(decode '(0 1 1 1 1))
'(1 0 1 0)
(newline)
(decode '(4))
'(0 0 0 0)
(newline)

"Integrar simple:"

(integrar_simple 0 1 4 (lambda (x) (* x x)))
'0.34375
(newline)

(integrar_simple 1 10 100 (lambda (x) (/ (log x) (log 2))))
'20.234149405699014
(newline)

"Integrar cola:"
(integrar_cola 0 1 4 (lambda (x) (* x x)))
'0.34375
(newline)

(integrar_cola 1 10 100 (lambda (x) (/ (log x) (log 2))))
'20.234149405699014
(newline)

"map_arbol:"

(map_arbol '(2 (3 () ()) (4 () ())) '(1) (lambda (x) (* x x)))
'(4 (3 () ()) (16 () ()))
(newline)

(map_arbol '(2 (3 () ()) (4 (3 (5 () ()) ()) (3 (8 () ()) ()))) '(1 0 0) (lambda (x) (* x x)))
'(4 (3 () ()) (16 (9 (25 () ()) ()) (3 (8 () ()) ())))
(newline)

(map_arbol '(2 (3 () ()) (4 (3 (5 () ()) ()) (3 (8 () ()) ()))) '(0) (lambda(x) (* x x)))
'(4 (9 () ()) (4 (3 (5 () ()) ()) (3 (8 () ()) ())))

