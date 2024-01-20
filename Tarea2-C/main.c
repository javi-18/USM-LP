#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arbol.h"
#include"arbol.c"


int main(){
 Nodo* primer_dir=crear_nodo(NULL,"directorio","USER-PC");
    char orden[100];
    char suborden[100];
    char texto[100];
    int largo;

    int ejecutar = 1;

    while (ejecutar==1){
        printf(">");
        scanf(orden,sizeof(orden),stdin);

        if (strcmp(orden, "off\n") == 0) {
            break;
        } else if (strncmp(orden, "ls\n",2) == 0){
            if(strlen(orden)<4){
                ls(primer_dir);
            } else {
                substr(orden,suborden, 3, strlen(orden)-3);
                largo = strlen(suborden);
                suborden[largo-1] = '\0';
                ls_dir(primer_dir,suborden);
            }
        } 
        strcpy(orden,strtok(orden, " "));
        if (strncmp(orden, "touch",5) == 0){
            strcpy(suborden,strtok(NULL, " "));
            largo = strlen(suborden);
            suborden[largo-1] = '\0';

            touch(primer_dir,suborden);

        }
        else if(strncmp(orden, "mkdir",5) == 0){
            strcpy(suborden,strtok(NULL, " "));
            largo = strlen(suborden);
            suborden[largo-1] = '\0';

            mkdir(primer_dir,suborden);
        }
        else if(strncmp(orden, "write",5) == 0){
            strcpy(suborden,strtok(NULL, " "));

            strcpy(texto,strtok(NULL, "#$&$#"));
            largo = strlen(texto);
            texto[largo-1] = '\0';
            write(primer_dir,suborden,texto);
        }

        else if(strncmp(orden, "cat",2) == 0){
            strcpy(suborden,strtok(NULL, " "));
            largo = strlen(suborden);
           suborden[largo-1] = '\0';
            cat(primer_dir,suborden);
        }

        else if(strncmp(orden, "cd",1) == 0){
             strcpy(suborden,strtok(NULL, " "));
            largo = strlen(suborden);
            suborden[largo-1] = '\0';

            primer_dir = cd(primer_dir,suborden);
        }

        else if (strncmp(orden, "mapdir",6) == 0)
        {
            strcpy(suborden,strtok(NULL, " "));
            if(strcmp(suborden, "ls\n") == 0){
                mapdir(primer_dir,lsmap,texto);
            }
            else{
                strcpy(texto,strtok(NULL, "#$&$#"));
                largo= strlen(texto);
                texto[largo-1] = '\0';

                if(strcmp(suborden, "touch") == 0){
                    mapdir(primer_dir,touch,texto);
                }
                else if (strcmp(suborden, "mkdir") == 0)
                {
                    mapdir(primer_dir,mkdir,texto);
                }
                
            }
        }
        

    }
    
    
    
    return 0;
}
    