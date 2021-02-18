/**********************************************************
 *                                                        *
 * Programación Aplicada                                  *
 * Primavera 2021                                         *
 * Mauricio Olguin                                        *
 * Modulo del programa de ejemplo para las listas Fifo    *
 *                                                        *
 * ********************************************************/

   

#include "local.h"

void CrearLista(char c, LISTA **inicio){
	LISTA *nodo;

	// 1.- Crear el espacio
	nodo=malloc(sizeof(LISTA));
	if(nodo==NULL){
		printf("No hay memoria\n");
		exit(1);
	}

	// 2.- Llenar la información
	nodo->letras=c;

	// 3.- Encadenar
    if(*inicio == NULL){
        nodo->sig = NULL;
    }
    else{
        nodo->sig = *inicio;
    }
    *inicio = nodo;
}  
void RecorrerLista(LISTA *inicio, FILE *fp1){
	LISTA *nodo;
		nodo=inicio;
		while(nodo!=NULL){
			putc(nodo->letras, fp1);
			nodo=nodo->sig;
		}
}

void LiberarMemoria(LISTA *inicio){
	LISTA *nodo;
	nodo=inicio;

	while(nodo!=NULL){
		inicio=nodo->sig;
		free(nodo);
		nodo=inicio;
	}
}