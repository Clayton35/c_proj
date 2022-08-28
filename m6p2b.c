/*
*       Created By: Clayton Davidson
*       Date: April 7, 2021
*       To Do:  -Scan for input errors**
*               -Scan input arguments***
*               -Make new file***
*               -Read files***
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

void inputScan(int argc, char *argv[]);
void errorScan(int argc, char *argv[]);
void readFile(char filename[]);
void makeFile(char *argv[], char filename[], int argc);

int main(int argc, char *argv[]){
    errorScan(argc, argv);

    return 0;
}
void errorScan(int argc, char *argv[]){
    if(strcmp(argv[1], "-b") != 0)
        printf("\nRange Start Error.\n");
    else if(strcmp(argv[3], "-e") != 0)
        printf("\nRange End Error.\n");
    else if(strcmp(argv[5], "-s") != 0)
        printf("\nRange Step Size Error.\n");
    else if(strcmp(argv[7], "-f") != 0)
        printf("\nFile Name Error.\n");
    else if(strcmp(argv[9], "-m") != 0)
        printf("\nMode Error.\n");
    else if(*argv[2] >= *argv[4])
        printf("\nError. Loop will not iterate.\n");
    else
        inputScan(argc, argv);
}
void inputScan(int argc, char *argv[]){
    for(int i = 1; i < argc; i++)
        if(strcmp(argv[i], "-m") == 0 && *argv[i + 1] == 'w')
            makeFile(argv, argv[i - 1], argc);
        else if(strcmp(argv[i], "-m") == 0 && *argv[i + 1] == 'r')
            readFile(argv[i - 1]);
}
void makeFile(char *argv[], char filename[], int argc){
    int begin, end, step;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-b") == 0)
            begin = strtol(argv[i + 1], NULL, 10);
        else if(strcmp(argv[i], "-e") == 0)
            end = strtol(argv[i + 1], NULL, 10);
        else if(strcmp(argv[i], "-s") == 0)
            step = strtol(argv[i + 1], NULL, 10);
    }

    FILE *file;
    char *name = filename;
    file = fopen(name, "w");

    for(; begin <= end; begin += step){
        fprintf(file, "The %d ", begin);
        printf("The value of Begin is: %d ", begin);
    }
    fclose(file);
    printf("\n");
}
void readFile(char filename[]){
    int c;
    FILE *file;
    char *name = filename;

    file = fopen(name, "r");
    printf("Reading File...\n");
    while(!feof(file)){
        fscanf(file, "%d ", &c);
        printf("%d ", c);
    }

    fclose(file);
    printf("\n");
}
