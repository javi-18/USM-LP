%Aqui se define las reglas y hechos para un arco existente del grafo dirigido entregado

%Regla que define el arco entre 2 nodos del grafo dirigido
conexiones(X, Y) :- vecino(X, Y).

%Hechos:representa las conexiones existentes entre los nodos del grafo entregado
vecino(a,b).
vecino(a,c).
vecino(a,e).
vecino(b,c).
vecino(c,d).
vecino(c,e).
vecino(e,b).
vecino(f,b).
vecino(f,e).
vecino(f,g).
vecino(g,e).
vecino(h,g).
vecino(h,j).
vecino(h,i).
vecino(i,g).
vecino(j,g).
vecino(j,i).

%puedellegar: verifica si existe un camino que lleve desde un nodo X a un nodo Y, además de verificar si llega a otro nodo W que este conectado a Y

%Reglas que definen el camino que existe entre 2 nodos del grafo dirigido, utilizando la recursion para ver si se puede llegar a otros nodos y el DFS
puedellegar(X,Y) :-
    setof(X,aux_puedellegar(X, Y), Resultado),
    member(Y,Resultado);
    setof(X, aux_puedellegar(X, Y), Resultado),
    member(X,Resultado).

aux_puedellegar(X,Y) :-
    dfs_1(X, Y, [X]),
    dif(X,Y).

dfs_1(X,X,_).

dfs_1(X, Y, NodosVisitados) :-
    vecino(X,W),
    \+ (member(W, NodosVisitados)),
    dfs_1(W, Y, [W|NodosVisitados]).



% vecinos: muestra todas las conexiones directas entre los nodos

%Regla que define todos los nodos que llega directamente, dado un nodo cualquiera, retornandolos en una lista o demostrar que una lista contiene todos los
%vecinos del nodo X,segun la consulta
vecinos(X, Lista) :- findall(Vecinodir, vecino(X, Vecinodir), Lista).


%Camino valido: verifica si existe un camino valido, dado una lista de nodos del grafo

%Primero se define este hecho, para considerar el considerar el grafo vacio como caso valido
caminovalido([]) :- !.
%Hecho que define que el camino sobre un nodo sobre si mismo 
caminovalido([_]) :- !.

%Regla que permite encontrar el camino al nodo que se consulta
caminovalido([X, Y | Resto]) :- vecino(X, Y), !, caminovalido([Y | Resto]).


% Camino más corto: verifica el camino mas corto entre 2 nodos, retornando una lista con los nodos que conforman la lista segun la consulta

%Regla que permite encontrar el camino mas corto usando la regla del algoritmo BFS
caminomascorto(X, Y, L) :-
    bfs([[X]], Y, Linvertida),
    reverse(Linvertida, L),!.

%Regla que define el BFS, el cual se utiliza para recorrer el grafo
bfs([[Y|L]|_], Y, [Y|L]).
bfs([[X|L]|Cola], Y, Resultado) :-
    findall([Z, X|L], (vecino(X, Z), \+ member(Z, [X|L])), RestoL),
    append(Cola, RestoL, NuevaCola),
    bfs(NuevaCola, Y, Resultado).

