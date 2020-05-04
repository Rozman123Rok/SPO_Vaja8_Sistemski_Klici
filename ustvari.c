#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
// Rok Rozman

int main(){
    char *imenik = "spoimenik"; // nasa mapa ki jo bomo naredili
    struct stat dat = {0}; // struktura
    
    if(stat(imenik, &dat) == -1) // funkcija ki nam vrne informacijo o dat
    {
        mkdir(imenik, 0777); // ce je ni jo ustvarimo
    }

    char* pot = malloc(strlen(imenik) + strlen("spozbirka.txt") + 2); // si nastavimo prostor ki ga rabimo
    pot = strcpy(pot, imenik); // kopiramo imenik v pot
    pot = strcat(pot, "/spozbirka.txt \n"); // mu dodamo se datoteko kjer je

    printf("Rok Rozman\n");
    printf("pot: %s", pot);

    long temp;
    temp = syscall(SYS_mkdir, "test", 0777); // ustvarim mapo 
    //char* temp1 = 
    long sprememba = syscall(SYS_chdir, "spoimenik"); // spremenimo dir
    //long ntemp = syscall(SYS_mkdir, "test1", 0777); // ustvarim mapo 
    
    long ustvari_file = syscall(SYS_creat, "spozbirka.txt"); // ustvarimo datoteko


    return 0;
}