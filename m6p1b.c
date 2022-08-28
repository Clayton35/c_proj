/*
*   Created By: Clayton Davidson
*   Date: April 7, 2021
*   To Do:  -Accept arguments from commandline***
*           -Scan function for inputs***
*           -Addition function***
*           -Multiplication function***
*           -Substraction function***
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void scanInputs(int argc, char *argv[], char output[]);
void argMult(char *argv[], int i, char output[]);
void argAdd(char *argv[], int i, char output[]);
void argSub(char *argv[], char output[], int i);

int main(int argc, char *argv[]){
    char output[200] = {'\0'};
    strcpy(output, argv[1]);

    scanInputs(argc, argv, output);
    printf("\nFinal Output: %s\n", output);
    return 0;
}
void scanInputs(int argc, char *argv[], char output[]){
    for(int i = 1; i < argc; i++){
        if(*argv[i] == '*'){
            argMult(argv, i, output);
        }
    }
    for(int i = 1; i < argc; i++){
        if (*argv[i] == '+'){
            argAdd(argv, i, output);
        }
        else if(*argv[i] == '-'){
            argSub(argv, output, i);
        }
        printf("Value of i: %d\nValue of Output String: %s\n", i, output);
    }
}
void argMult(char *argv[], int i, char output[]){
    for(int j = 1; j < strtol(argv[i + 1], NULL, 10); j++)
        strcat(output, argv[i - 1]);
}
void argAdd(char *argv[], int i, char output[]){
    strcat(output, argv[i + 1]);
}
void argSub(char *argv[], char output[], int i){
    char *ptr;
    int length = strlen(argv[i + 1]);

    if(ptr = strstr(output, argv[i + 1])){
        *ptr = '\0'; 
        strcat(output, ptr + length);
    }
}
