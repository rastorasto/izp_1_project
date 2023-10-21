#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int zvacsi(int pismenko){
    if (pismenko >= 'a' && pismenko <= 'z') {
        return pismenko - ('a' - 'A');
    } else {
        return pismenko;
    }
}
int porovnanie(char *vstup, char *adresa){
    int znak = 0;
    bool rovnost = true;
    while (vstup[znak] != '\0' /*&& adresa[znak] != '\0'*/) {
        if(zvacsi(vstup[znak]) != zvacsi(adresa[znak])){
            rovnost = false;
            break;
        } else {
            znak++;
        }
    }
    printf("%d\n",adresa[znak]);
    if(rovnost && (adresa[znak] == '\0' || adresa[znak] == '\n')){
        return 1;
    } else if(rovnost == 1){
        return zvacsi(adresa[znak]);
    } else {
        return 0;
    }
}
int main(int argc, char *argv[]){
    char buffer[101];
    char vypis[101];
    int poradie = 0;
    int stav;
    if(!argv[1]){
        argv[1] = "\0";
    }
    if(argc > 1){
        while(fgets(buffer,101,stdin) != NULL){
        stav = porovnanie(argv[1],buffer);
            if (stav == 1)
            {
                break;
            } else if (stav>='A' && stav<='Z')      
            {
                vypis[poradie] = stav;
                poradie++;
            }
        }
        vypis[poradie] = '\0';
        if(stav ==1){
            printf("Found:%s",buffer);
        } else if (poradie != 0){
            printf("Enable: %s",vypis);
        } else {
            printf("Not found");
        }   
    } else {
        fprintf(stderr,"No input");
    }
    return 0;
}