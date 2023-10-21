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
    //printf("stav hore %d\n",adresa[znak]);
    if(rovnost && (adresa[znak] == '\0' || adresa[znak] == '\n')){
        return 1;
    } else if(rovnost == 1){
        return zvacsi(adresa[znak]);
    } else {
        return 0;
    }
}
int main(int argc, char *argv[]){
    char buffer[102];
    //char vypis[102];
    char ascii[128] = {0};
    char single[102];
    int poradie = 0;
    int prepis = 0;
    int stav;
    if(!argv[1]){
        argv[1] = "\0";
    }
    if(argc > 1){
        while(fgets(buffer,101,stdin) != NULL){
        stav = porovnanie(argv[1],buffer);
        //printf("stav dole %d\n",stav);
            if (stav == 1)
            {
                break;
            } else if (stav>1)//(stav>='A' && stav<='Z')      
            {
                for (prepis = 0; prepis < 102 && buffer[prepis] != '\0'; prepis++) {
                    single[prepis] = zvacsi(buffer[prepis]);
                }
                single[prepis] = '\0';
                //vypis[poradie] = stav;
                ascii[stav] = 1;
                poradie++;
            }
        }
        //vypis[poradie] = '\0';
        //printf("poradie %d",poradie);
        if(stav ==1){
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                buffer[i] = zvacsi(buffer[i]);
            }
            
            printf("Found: %s",buffer);
        } else if(poradie == 1){
            printf("Found: %s",single);
        } else if (poradie > 1){
            printf("Enable: ");
            for (int i = 0; i < 127; i++)
            {
                if(ascii[i] == 1){
                    printf("%c",i);
                }
            }
            
        } else {
            printf("Not found");
        }   
    } else {
        fprintf(stderr,"No input");
    }
    return 0;
}