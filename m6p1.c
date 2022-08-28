/*
*       Created by: Clayton Davidson
*       Date: March 30, 2021
*       
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#define SIZE 200

void opScan(int argc, char *argv[], char output[]);
void argMult(char *argv[], char output[], int argc, int i);
void argAdd(char *argv[], char output[], int i, int argc);
void argSub(char haystack[], char needle[]);

int main(int argc, char *argv[]){
    char output[SIZE] = {"\0"};

    opScan(argc, argv, output);
    printf("Output: %s\n", output);

    return 0;
}
void opScan(int argc, char *argv[], char output[SIZE]){ 
    strcat(output, argv[1]);
    for(int i = 1; i < argc; i++)
        if(*argv[i] == '*')
            argMult(argv, output, argc, i);  
    for(int i = 1; i < argc; i++){
        if(*argv[i] == '+')
            argAdd(argv, output, i, argc);
        else if(*argv[i] == '-')
            argSub(output, argv[i + 1]);
    }
}
void argSub(char output[], char needle[]){
    char *ptr = output;
    int length = strlen(needle);
    
    strstr(ptr, needle);
    *ptr = '\0';
    strcat(output, ptr + length);
    ptr++;
}
void argAdd(char *argv[], char output[], int i, int argc){
    printf("i: %d\nargv[i-2]: %d\nargv[i+2]: %d\n", i, *argv[i-2], *argv[i+2]);
    if(i == 2 && *argv[i+2] == '-')
        strcat(output, argv[i+1]);
    else if(i == (argc - 2) && *argv[i-2] == '*')
        strcat(output, argv[i+1]);
    else if(*argv[i-2] == '*' && *argv[i+2] == '*')
        return; 
    else if(i == (argc-2 && i != 2)){
        strcat(output, argv[i-1]);
        strcat(output, argv[i+1]);
    }
    else if(i % 2 == 0 && i != 2)
        strcat(output, argv[i-1]);   
}
void argMult(char *argv[], char output[], int argc, int i){
    char temp[SIZE] = {'\0'};

    if(*argv[i] == '*' && *argv[i - 2] == '-'){
        for(int j = 0; j < strtol(argv[i + 1], NULL, 10); j++)
            strcat(temp, argv[i - 1]);
        argSub(output, temp);
    }   
    else if(*argv[i] == '*'){
        for (int j = 0; j < strtol(argv[i + 1], NULL, 10); j++)
            strcat(output, argv[i - 1]);
    }
}
