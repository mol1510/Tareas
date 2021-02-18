/***********************************************
 *                                             *
 * Programación Aplicada                       *
 * Primavera 2021                              *
 * Mauricio Olguin                             *
 * Programa de ejemplo para las listas Lifo    *
 *                                             *
 * *********************************************/


#include "local.h"


extern void CrearLista(char c, LISTA **inicio);
extern void RecorrerLista(LISTA *inicio, FILE *fp1);
extern void LiberarMemoria(LISTA *inicio);


int main(int argc, char *argv[]){
	FILE *fp, *fp1;
	char c;
	// Paso número dos: Crear variables del tipo de la estructura
	LISTA *inicio, *aux;

	// Paso número tres: inicializar a NULL el apuntador inicio
	inicio=NULL;

	if(argc!=3){
		printf("Error al ejecutar el programa. Faltan o sobran argumentos\n");
		exit(1);
	}

	fp=fopen(argv[1], "r");
    fp1=fopen(argv[2], "w");
	if(fp==NULL){
		printf("Error al abrir el archivo\n");
		exit(1);
	}

	while((c=getc(fp))!=EOF){
		CrearLista(c, &inicio);
	}
	RecorrerLista(inicio, fp1);
	LiberarMemoria(inicio);
	fclose(fp);
    fclose(fp1);
}
