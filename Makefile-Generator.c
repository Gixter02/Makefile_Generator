#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv){
    if(argc != 3){
        printf("ERRORE:Numero di parametri diverso da 3\n");
        exit(1);
    }
    int clen = strlen(argv[1]);
    if(clen <= 2){
        printf("ERRORE: nome primo parametro non corretto\n");
        exit(2);
    }
    if(argv[1][clen-1] != 'c' || argv[1][clen-2] != '.'){
        printf("ERRORE: la stringa %s non termina con .c\n", argv[1]);
        exit(3);
    }
    printf("Il file .c si chiama: \"%s\"\n", argv[1]);
    printf("Il file eseguibile si chiamera': \"%s\"\n", argv[2]);
    FILE* f= fopen("makefile", "w");
    if(f==NULL){
        printf("ERRORE nell'apertura del file\n");
        exit(4);
    }
    fprintf(f,"%s: %s\n\tgcc -Wall -std=c11 -o %s %s", argv[2], argv[1], argv[2], argv[1]);
    if(fclose(f) != 0){
        printf("ERRORE: file chiuso NON correttamente\n");

        exit(5);
    }
    printf("makefile creato correttamente!\n");
    exit(0);
}