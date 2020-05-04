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

char* dovoljenja(char *datoteka){ // izpise katera dovoljenja ima datoteka
    struct stat st;
    char *temp = malloc(sizeof(char) * 9 + 1); // ker rabimo 9 mest za pisanje pravic
    if(stat(datoteka, &st) == 0){
        mode_t perm = st.st_mode; // PRIDOBIMO VREDNOST DOVOLJEN

        if(perm & S_IRUSR){temp[0]='r';} // CE IMA USER PRAVICO BRANJA
        else{temp[0]='-';}
        if(perm & S_IWUSR){temp[1]='w';} // CE IMA USER PRAVICO PISANJA
        else{temp[1]='-';}
        if(perm & S_IXUSR){temp[2]='x';} // CE IMA USER PRAVICO ZAGNAT
        else{temp[2]='-';}
        if(perm & S_IRGRP){temp[3]='r';} // CE IMA GROUP PRAVICO BRANJA
        else{temp[3]='-';}
        if(perm & S_IWGRP){temp[4]='w';} // CE IMA GROUP PRAVICO PISANJA
        else{temp[4]='-';}
        if(perm & S_IXGRP){temp[5]='x';} // CE IMA GROUP PRAVICO ZAGNAT
        else{temp[5]='-';}
        if(perm & S_IROTH){temp[6]='r';} // CE IMAJO OSTALI PRAVICO BRANJA
        else{temp[6]='-';}
        if(perm & S_IWOTH){temp[7]='w';} // CE IMAJO OSTALI PRAVICO PISANJA
        else{temp[7]='-';}
        if(perm & S_IXOTH){temp[8]='x';} // CE IMAJO OSTALI PRAVICO ZAGANJANJA
        else{temp[8]='-';}
        temp[9]='\0'; // ZADNJI ZNAK
        return temp; // VRNEMO REZULTAT   
    }
    else{
        return -1; // ce je error
    }   
}

int main(){
    long ustvari_mapo = syscall(SYS_mkdir, "spoimenik", 0777); // ustvarim mapo 
    if(ustvari_mapo < 0){printf("Error pri ustvarjanju mape\n"); return -1;} // preverimo ce nam vrze error

    long sp_dir = syscall(SYS_chdir, "spoimenik"); // spremenimo dir v mapo ki smo jo ustvarili
    if(sp_dir < 0){printf("Error pri spreminjanju dir\n"); return -1;}
    
    long ustvari_file = syscall(SYS_creat, "spozbirka.txt"); // ustvarimo datoteko brez podanih pravic
    if(ustvari_file < 0){printf("Error pri ustvarjanju dat\n"); return -1;}

    printf("Pravice pred (spozbirka.txt): \n");
    printf("%s\n" , dovoljenja("spozbirka.txt"));    

    long pravice = syscall(SYS_chmod,"spozbirka.txt", 00640); // dodamo pravice 6- user read and write, 4 - group read
    if(pravice < 0){printf("Error pri postavljanju pravic\n"); return -1;}

    printf("Pravice po (spozbirka,txt): \n");
    printf("%s\n" , dovoljenja("spozbirka.txt"));

    return 0;
}