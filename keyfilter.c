#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max_array_length 102
#define ascii_table_length 128

int uppercase(int letter){
    if (letter >= 'a' && letter <= 'z') {
        return letter - ('a' - 'A');
    } else {
        return letter;
    }
}
// Function to compare each character from input with address
int comparison(char *input, char *address){
    int char_index = 0; // Character index for array
    bool strings_are_the_same = true;
    while (input[char_index] != '\0') { // Compare while there are valid characters
        // Comparing characters at char_index
        if(uppercase(input[char_index]) != uppercase(address[char_index])){
            strings_are_the_same = false;
            break;  // If they aren't the same we don't need to compare next characters
        } else {
            char_index++; // Move to next character
        }
    }
    if(strings_are_the_same){
        return uppercase(address[char_index]);
    } else {
        return 0;
    }
}
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
int check_arguments(int argc, char *argv[]){
    if(!argv[1]){
        argv[1] = "\0";
        argc++;
    }
    return argc;
}
int main(int argc, char *argv[]){
    char buffer[max_array_length];
    char ascii_table[128] = {0};
    char found_address[max_array_length];
    int found_index = 0;
    int found_address_index = 0;
    int comparison_value = 0;
    check_arguments(argc, argv);
    if(argc){
        while(fgets(buffer,101,stdin) != NULL){
        comparison_value = comparison(argv[1],buffer);
        if (comparison_value)   
            {
                for (found_address_index = 0; buffer[found_address_index] != '\0'; found_address_index++) {
                    found_address[found_address_index] = uppercase(buffer[found_address_index]);
                }
                found_address[found_address_index] = '\0';
                ascii_table[comparison_value] = 1;
                found_index++;
            }
        }

    output_results(found_index,found_address,ascii_table);

    } else {
        fprintf(stderr,"No input");
    }
    return 0;
}