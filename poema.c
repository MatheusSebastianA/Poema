#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    int posi;
    char letra;
    FILE *arq, *arq_dst;

    arq = fopen("poema.bin", "r");

    if(!arq){
        perror("Arquivo não foi aberto");
        return 1;
    }

    arq_dst = fopen("saida.txt", "w+");

    if(!arq_dst){
        perror("Arquivo não foi aberto");
        return 1;
    }

    fread(&posi, sizeof(int), 1, arq);
    while (! feof(arq)){
        fread(&letra, sizeof(char), 1, arq);
        fseek (arq_dst, posi, SEEK_SET);
        fprintf(arq_dst, "%c", letra);
        fread(&posi, sizeof(int), 1, arq);
    }

    rewind(arq_dst);
    letra = fgetc (arq_dst);
    while (letra != EOF){
        printf ("%c", letra);		
        letra = fgetc (arq_dst) ;
  }
 

    fclose(arq);
    return 0;
}   
