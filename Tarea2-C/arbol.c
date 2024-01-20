#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"


/* Lista*crear_lista: es una función que permite crear una lista vacia dinamicamente, ya que esta no sabemos 
 el tamaño que esta puede tener  

 Parametros:
 largo_maximo_inicial (int) : entero que indica el tamaño que va a tener la lista
 
 Retorno :
 lista(Lista) : es un puntero de tipo Lista que apunta a la lista creada en el heap, que tendra el tamaño que el usuario ingrese 
 */


Lista*crear_lista (int largo_maximo_inicial){
    Lista*lista=(Lista*)mallloc(sizeof(Lista));
    lista-> largo_actual= 0;
    lista->largo_maximo= largo_maximo_inicial;
    lista->arreglo=(Nodo*)malloc(largo_maximo_inicial*sizeof(Nodo));
    return lista;

}


/* void insertar_lista: es una función que permite crear insertar un elemento de tipo Nodo dentro de la lista si hay espacio.En caso de que sea mayor
al largo de la lista, entonces se duplica el tamaño de la lista y se inserta el nodo dentro de la lista, con todos los elementos que contenia
anteriormente 

 Parametros:
 Lista*lista (Lista) : puntero al struct Lista creada en el heap, la cual inicialmente esta vacía
 
 Nodo*nodo (Nodo): puntero al struct Nodo que contendra la información ya sea de un archivo o de un directorio nuevo, el cual se crea en la 
 funcion Nodo*crear_nodo
 
 Retorno : Dado que es de tipo void no retorna nada, solamente insertara los nodos a la lista 
 
 */

void insertar_lista (Lista*lista,Nodo*nodo){
    if (lista->largo_actual== lista->largo_maximo){
        lista->arreglo[lista->largo_actual]=*nodo;
        lista->largo_actual +=1;
        return;
    }
    else if(lista->largo_actual>= lista->largo_maximo){
        int cont=0;
        Nodo*temporal= malloc(sizeof(Nodo)*((lista->largo_maximo)+1));
        while (cont<(lista->largo_maximo))
        {
            temporal[cont]= lista->arreglo[cont];
            cont+=1;
        }
        cont=0;
    lista->largo_maximo=(lista->largo_maximo)*2;
    Nodo*nuevo_arr= realloc(lista->arreglo,(lista->largo_maximo)*sizeof(Nodo));
    lista->arreglo= nuevo_arr;
    
    while (cont<lista->largo_actual)
    {
        lista->arreglo[cont]= temporal[cont];
        cont+=1;


    }
    cont=0;
    lista->arreglo[lista->largo_actual]= *nodo;
    lista->largo_actual+=1;
    return;

    }
    

}


/* Nodo*buscar_directorio: es una función que busca el directorio actual de un nombre dado 

 Parametros:
 Directorio*actual(Directorio*) : puntero a un struct directorio que esta contenido dentro de una lista, el cual se quiere buscar

 char*nombre(char*): arreglo de char que es el nombre del directorio que el usuario quiere buscar 
 
 Retorno :
 &actual->hijos->arreglo[i](&Directorio) : retorna la direccion de memoria donde esta almacenado el directorio que se estaba buscando
 En caso de que no lo encuentre o no exista el directorio retorna NULL
 */
Nodo*buscar_directorio(Directorio*actual,char*nombre){
    int i=0;
    while (i<(actual->hijos->largo_actual))
    {
        if(strcmp(actual->hijos->arreglo[i].tipo,"directorio")==0){
            Directorio*dir_ac=(Directorio*)(actual->hijos->arreglo[i].contenido);
            if(strcmp(dir_ac->nombre,nombre)==0){
                return &actual->hijos->arreglo[i];
            }
        }
        i+=1;
    }
    return NULL;



}



/* Nodo*buscar_archivo: es una función que busca en el directorio actual un archivo

 Parametros:
 Directorio*actual(Directorio*) : puntero a un struct directorio que esta contenido dentro de una lista,el sual se revisara para encontrar
 el nombre de un archivo dado por el usuario

 char*nombre(char*): arreglo de char que es el nombre del archivo que el usuario quiere buscar 
 
 Retorno :
 &actual->hijos->arreglo[i](&Directorio): retorna la direccion de memoria donde esta almacenado el archivo que se estaba buscando dentro del directorio
 actual.En caso de que no lo encuentre o no exista el directorio retorna NULL
 */

 Nodo*buscar_archivo (Directorio*actual,char*nombre){
    int i=0;
    while (i<(actual->hijos->largo_actual))
    {
        if(strcmp(actual->hijos->arreglo[i].tipo,"directorio")==0){
            Archivo*arch_ac=(Archivo*)(actual->hijos->arreglo[i].contenido);
            if(strcmp(arch_ac->nombre,nombre)==0){
                return &actual->hijos->arreglo[i];
            }
        }
        i+=1;
    }
    return NULL;



 }



/* Nodo*crear_nodo: es una función que permite crear un archivo o directorio,segun lo requiera el usuario, los cuales seran almacenados 
    en el struct tipo nodo

 Parametros:
 Nodo*padre (Nodo) : Puntero de tipo nodo que apunta al struct tipo Nodo

 char*tipo (char*): un puntero de tipo char, que indica si se quiere crear archivo o un directorio

 char*nombre(char*): Un puntero de tipo char, el cual es el nombre del archivo o directorio que se quiere poner
 
 Retorno :
 nodo_nuevo(Nodo*) : Un nodo que se crea en el heap que contendra el archivo o directorio nuevo que sera insertado en la lista creada 
 anteriormente con la función Lista*crear_lista
 */


Nodo*crear_nodo (Nodo*padre,char*tipo,char*nombre){
    Nodo*nodo_nuevo= (Nodo*)malloc(sizeof(Nodo));
    nodo_nuevo->padre=padre;
    strcpy(nodo_nuevo->tipo,tipo);
    if(strcmp(tipo,"archivo")==0){
        Archivo*archivo_nuevo= (Archivo*)malloc(sizeof(Archivo));
        strcpy(archivo_nuevo->nombre,nombre);
        nodo_nuevo->contenido=(void*)archivo_nuevo;
    }
    else if(strcmp(tipo,"directorio")==0){
        Directorio*directorio_nuevo= (Directorio*)malloc(sizeof(Directorio));
        strcpy(directorio_nuevo->nombre,nombre);
        directorio_nuevo->hijos=crear_lista(20);
        nodo_nuevo->contenido=(void*)directorio_nuevo;
    }
    return nodo_nuevo;
}


/* void mkdir: es una función que crea un directorio y lo agrega como hijo del actual

 Parametros:
 Nodo*actual (Nodo*) : puntero al nodo del struct Nodo, el cual contiene el directorio actual al cual se le quiere agregar el directorio hijo

 char*nombre_directorio(char*): es un arreglo de char, el cual indica el nombre del directorio actual
 
 Retorno :
 Dado que es de tipo void no retorna nada, solamente creara el directorio y lo agrega al nodo actual
 */

void mkdir (Nodo*actual,char*nombre_directorio){
    Directorio*dir=(Directorio*)actual->contenido;
    Nodo*nuevo_direc= crear_nodo(actual,"directorio",nombre_directorio);
    insertar_lista(dir->hijos,nuevo_direc);
    return;
}



/* void touch: es una función que permite crear un archivo y lo agrega como hijo del directorio actual

 Parametros:
 Nodo*actual(Nodo*) : Es un puntero de tipo nodo que 

 char*nombre_archivo(char*): un puntero de tipo char, que indica el nombre del archivo que se quiere crear
 
 Retorno :
 Como es una funcion de tipo void, no retorna nada, solamente crea el archivo 
 */

void touch (Nodo*actual,char*nombre_archivo){
    Directorio*dir_actual= (Directorio*)actual->contenido;
    Nodo*nuevo_nod=crear_nodo(actual,"archivo",nombre_archivo);
    insertar_lista(dir_actual->hijos,nuevo_nod);
    return;
}


/* void write: es una función que busca un archivo y cambia su contenido

 Parametros:
 Nodo*actual(Nodo*) : puntero de tipo nodo que un struct de tipo Nodo que contiene el archivo

 char*nombre_archivo(char*): puntero de tipo char, que indica el nombre del archvio al cual se quiere cambiar su contenido 
 
 Retorno :
 Como es una funcion de tipo void, no retorna nada, solamente cambia el contenido del archivo
 */

void write(Nodo*actual,char*nombre_archivo,char*contenido){
    Directorio* dir = (Directorio*) actual->contenido; 
    Archivo* arch = (Archivo*) (buscararchivo(dir,nombre_archivo));
    strcpy(arch->contenido,contenido);
    return;

}

/* void cat: es una función que busca un archivo e imprime su contenido

 Parametros:
Nodo*actual (Nodo*) : puntero de tipo nodo que un struct de tipo Nodo que contiene el archivo

char*nombre_archivo(char*): un puntero de tipo char, que indica el nombre del archivo
 
 Retorno :
 Como es una funcion de tipo void, no retorna nada, solamente muestra el contenido del archivo
 */

void cat (Nodo*actual , char*nombre_archivo){
    Directorio* dir_ec = (Directorio*) actual->contenido; 
    Archivo* arch_lect = (Archivo*) (buscararchivo(dir_ec,nombre_archivo)); 
    printf("%s",arch_lect->contenido);
    printf("\n");
    return;

}


/* voidnombre_nodos(Nodo*nodo): es una función que muestra todos los nodos dentro de la lista

 Parametros:
 Nodo*nodo(Nodo*) : Es un puntero de tipo nodo que apunta una estructura tipo Nodo que contiene los directorios y archivos que 
 se quieren imprimir 

 
 Retorno :
 Como es una funcion de tipo void, no retorna nada, solamente muestra el nombre de los nodos
 */

void nombre_nodos(Nodo*nodo){
    if(strcmp(nodo->tipo,"archivo")==0){
            Archivo*arch=(Archivo*)(nodo->contenido);
            printf("%s",arch->nombre);
        }
        else if(strcmp(nodo->tipo,"directorio")==0){
            Directorio*directorio_ac=(Directorio*)(nodo->contenido);
            printf("%s",directorio_ac->nombre);
        }
        return;
}

/* void ls: es una función que imprime todos los hijos del directorio actual

 Parametros:
 Nodo*actual (Nodo*) : Es un puntero de tipo nodo que apunta una estructura tipo Nodo que contiene el directorio que se quiere imprimir
 
 Retorno :
Como es una funcion de tipo void, no retorna nada, solamente imprime los hijos del directorio actual
 */

void ls(Nodo*actual){
    Directorio*directorio_ac= (Directorio*)actual->contenido;
    int e=0;
    while (e<(directorio_ac->hijos->largo_actual))
    {
        nombre_nodos(&directorio_ac->hijos->arreglo[e]);
        printf("%s","\n");
        e+=1;

    }
    return;
    

}


/* void lsmap: es una función que imprime todos los hijos del directorio actual

 Parametros:
 Nodo*actual (Nodo*) : Es un puntero de tipo nodo que apunta una estructura tipo Nodo que contiene el directorio que se quiere imprimir
 
 Retorno :
Como es una funcion de tipo void, no retorna nada, solamente imprime los hijos del directorio actual
 */

void lsmap(Nodo*actual,char*aux){
    ls(actual);
    return;
}




/* void lsdir: es una función que imprime todos los hijos de un subdirectorio

 Parametros:
 Nodo*actual (Nodo*) : Es un puntero de tipo nodo que apunta una estructura tipo Nodo que contiene el directorio del cual se quiere imprimir sus hijos

 char*nombre_directorio(char*): puntero de tipo char que indica el nombre del directorio seleccionado
 
 Retorno :
Como es una funcion de tipo void, no retorna nada, solamente imprime los hijos del directorio seleccionado
 */

void lsdir(Nodo*actual,char*nombre_directorio){
    Directorio*direc_econ=(Directorio*)actual->contenido;
    return;


}




/* Nodo*cd: es una función que hace la instruccion cd, la cual permite seleccionar un directorio como el actual

 Parametros:
 Nodo*actual(Nodo*) : puntero a una estructura tipo nodo que contiene el directorio que pasara a hacer el actual

 char*nombre_directorio(char*): puntero de tipo char, que indica el nombre del directorio a seleccionar
 
 Retorno :
 &actual->hijos->arreglo[i](&Directorio): devuelve la direccion de memoria,donde se encuentra el directorio seleccionado como el actual
 */
Nodo*cd(Nodo*actual,char*nombre_directorio){
     Directorio* dire = (Directorio*) actual->contenido;  
    if(strcmp(nombre_directorio, "..") == 0){
        return actual->padre;
    } else{
        return buscar_directorio(dire,nombre_directorio);
    }    
}


/* void mapdir: es una función que aplica la instruccion a todos los subdirectorios.
 Parametros:
 Nodo*actual(Nodo*) : puntero a una estructura tipo nodo que contiene el directorio,al cual se le aplicara la

 void (*insturccion) (Nodo*,char*)(void*): es un puntero tipo void que apunta a

 char*parametro_instruccion(char*): puntero de tipo char que indica la instruccion que debe ejecutarse dentro de los subdirectorios
 
 Retorno :
 Como es una funcion de tipo void, no retorna nada, solamente aplica una instruccion para todos los subdirectorios
 */

void mapdir(Nodo*actual ,void (*insturccion) (Nodo*,char*),char*parametro_instruccion){
     Directorio* dir_actual = (Directorio*) (actual->contenido);
    int pos =0;
    while(pos < (dir_actual->hijos->largo_actual)){
        if(strcmp(dir_actual->hijos->arreglo[pos].tipo,"directorio")==0){
            instruccion(&dir_actual->hijos->arreglo[pos],parametro_instruccion); 
        } 
        pos+=1;
    }


}


 
