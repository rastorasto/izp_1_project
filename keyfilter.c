#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int uppercase(int letter){
    if (letter >= 'a' && letter <= 'z') {
        return letter - ('a' - 'A');
    } else {
        return letter;
    }
}
int comparison(char *input, char *address){
    int char_index = 0;
    bool strings_are_the_same = true;
    while (input[char_index] != '\0') {
        if(uppercase(input[char_index]) != uppercase(address[char_index])){
            strings_are_the_same = false;
            break;
        } else {
            char_index++;
        }
    }
    if(strings_are_the_same){
        return uppercase(address[char_index]);
    } else {
        return 0;
    }
}
#define max_array_length 102
int main(int argc, char *argv[]){
    char buffer[max_array_length];
    char ascii[128] = {0};
    char found_address[max_array_length];
    int found_index = 0;
    int found_address_index = 0;
    int comparison_value = 0;
    if(!argv[1]){
        argv[1] = "\0";
        argc++;
    }
    if(argc > 1){
        while(fgets(buffer,101,stdin) != NULL){
        comparison_value = comparison(argv[1],buffer);
        if (comparison_value)   
            {
                for (found_address_index = 0; buffer[found_address_index] != '\0'; found_address_index++) {
                    found_address[found_address_index] = uppercase(buffer[found_address_index]);
                }
                found_address[found_address_index] = '\0';
                ascii[comparison_value] = 1;
                found_index++;
            }
        }
        if(found_index == 1){
            printf("Found: %s",found_address);
        } else if (found_index > 1){
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