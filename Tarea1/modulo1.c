#include <stdio.h>
#include <stdlib.h>


extern void leerArchivo(char *vocales, char *sin);

int main(int argc, char *argv[]){
     if(argc != 3){
        printf("Error al correr el programa. Los argumentos están mal");
        exit(1);
    }
    leerArchivo(argv[1], argv[2]);

}