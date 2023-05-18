#include <stdio.h> /* Standard Input-Output */
/* include necessario per usare printf e altre; inoltre
definisce la costante BUFSIZ */
#include <fcntl.h> /* File CoNTroL */
/* include necessario per usare la primitiva open e le
relative costanti come O_RDONLY */
#include <stdlib.h> /* Standard Library */
/* include necessario per usare la primitiva exit */
#include <unistd.h> /* UNIX Standard */
/* include necessario per usare la primitiva read, write
e close */
#include <sys/wait.h>
/* include necessario per la primitiva wait */

int main(int argc, char ** argv){
    if(argc != 3){
        printf("ERRORE:Numero di parametri diverso da 3\n");
        exit(1);
    }
    printf("Il file .c si chiama:\t%s\n", argv[1]);
    printf("Il file eseguibile si chiamera':\t%s\n", argv[2]);
    FILE* f= fopen("makefile", "w");
    if(f==NULL){
        printf("ERRORE nell'apertura del file\n");
        exit(2);
    }
    fprintf(f,"%s: %s\n\tgcc -Wall -std=c11 -o %s %s", argv[2], argv[1], argv[2], argv[1]);
    fclose(f);
    exit(0);
}