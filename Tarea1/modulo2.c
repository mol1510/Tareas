#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leerArchivo(char *vocales, char *sin){
    char arr[60];
    FILE *fp, *fp1;

    fp = fopen(vocales, "r");
    fp1= fopen(sin, "w");
    
    if(fp==NULL){
        printf("no existe el archivo\n");
        exit(1);
    }

    while(fgets(arr, 60, fp)){
        for(int x=0; x<strlen(arr);x++){
            if(arr[x]==65 || arr[x]==69 || arr[x]==73 || arr[x]==79 || arr[x]==85){
                arr[x]=63;
            }
            if(arr[x]=='a' || arr[x]=='e' || arr[x]=='i' || arr[x]=='o'|| arr[x]=='u'){
                arr[x]='?';
            }
            if(arr[x]>159 && arr[x]<164){
                arr[x]='?';
            }
        }
    }
    fclose(fp);
    fclose(fp1);

}
