#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max_array_length 102
#define ascii_table_length 128
/*
The function checks the argument's ASCII value and if it is lowercase letter
it will change it to its uppercase value.
*/
int uppercase(int letter){
    if (letter >= 'a' && letter <= 'z') {
        return letter - ('a' - 'A');
    } else {
        return letter;
    }
}
/*
The function compares every character from input with address.
If every character from input matches characters from address,
the function returns the next character in address.
If they aren't the same the cycle that checks every letter from input stops
and the fucntion returns 0.
*/
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
/*
The function checks how many addresses are valid.
If it is only one address, the function prints the address.
If more addresses are valid, the funcion prints the next letters
that the user can add to his input. And if no addresses are valid,
the function prints "Not found".
*/
void output_results(int found_index,char* found_address,char* ascii_table){
    if(found_index == 1){
        printf("Found: %s",found_address);
    } else if (found_index > 1){
        printf("Enable: ");
        for (int i = 0; i < ascii_table_length; i++)
        {
            if(ascii_table[i] == 1){
                printf("%c",i);
            }
        }
    } else {
        printf("Not found");
    }
}
/*
The function checks it user passed an arguement, and if
they didn't, it will set it to empty string.
*/
int check_arguments(int argc, char *argv[]){
    if(!argv[1]){
        argv[1] = "";
        argc++;
    }
    return argc;
}
/*
The function is used to save found address in case
that only one address is valid.
*/
char* saves_valid_address(char *buffer, char *found_address){
    int found_address_index;
    for (found_address_index = 0; buffer[found_address_index] != '\0'; found_address_index++) {
        found_address[found_address_index] = uppercase(buffer[found_address_index]);
    }
    found_address[found_address_index] = '\0';
    return found_address;
}
/*
The function calls comparison function for every address from stdin.
If the address is valid it saves it and it also saves next enabled letter.
After comparing every address it prints the results. 
*/
int main(int argc, char *argv[]){
    char buffer[max_array_length];
    char ascii_table[128] = {0};
    char found_address[max_array_length];
    int found_index = 0;
    int comparison_value = 0;
    check_arguments(argc, argv);
    if(argc){
        while(fgets(buffer,101,stdin) != NULL){
            comparison_value = comparison(argv[1],buffer);
            if (comparison_value){
                saves_valid_address(buffer,found_address);
                found_index++;
                ascii_table[comparison_value] = 1;
            }
        }

    output_results(found_index,found_address,ascii_table);

    } else {
        fprintf(stderr,"No input");
    }
    return 0;
}