/*
*   Created by: Clayton Davidson
*   Date: April 3, 2021
*           
*/

#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<strings.h>

void errorScan(int argc, char *argv[]);
void inputScan(int argc, char *argv[]);
void makeFile(int argc, char *argv[], char fileName[]);
void printFile(char fileName[]);

int main(int argc, char *argv[]){
    if(argc > 11){
        printf("\nYou entered too many arguments, Please try again.\n");
        exit(-1);
    }
    errorScan(argc, argv);
    return 0;
}
void errorScan(int argc, char *argv[]){             //checks for input errors
    if(strcmp(argv[1], "-b") != 0)
        printf("\nRange Start Error.\n");
    else if(strcmp(argv[3], "-e") != 0)
        printf("\nRange End Error.\n");
    else if(strcmp(argv[5], "-s") != 0)
        printf("\nRange Step Size Error.\n");
    else if(strcmp(argv[7], "-f") != 0)
        printf("\nFile Error.\n");
    else if(strcmp(argv[9], "-m") != 0)
        printf("\nMode Error.\n");
    else if(strcmp(argv[2], argv[4]) == 0)
        printf("\nLoop Error. Will Not Iterate.\n");
    else
        inputScan(argc, argv);
}  
void inputScan(int argc, char *argv[]){             //scans arguments to see whether to read or write
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-m") == 0 && *argv[i + 1] == 'w')
            makeFile(argc, argv, argv[i - 1]);
        else if(strcmp(argv[i], "-m") == 0 && *argv[i + 1] == 'r')
            printFile(argv[i - 1]);
    }
}
void printFile(char fileName[]){                    //prints file contents to terminal window
    int c;
    char *name = fileName;
    FILE *file;
    file = fopen(name, "r");

    printf("Reading File...\n");

    while(!feof(file)){
        fscanf(file, "%c", c);
        printf("%c", c);
    }
    printf("\n");
    fclose(file);
}
void makeFile(int argc, char *argv[], char fileName[]){     //creates a new file and prints specified contents to specified file and terminal
    long int start, end, step;

    for(int j = 1; j < argc; j++){
        if(strcmp(argv[j], "-b") == 0)
            start = strtol(argv[j + 1], NULL, 10);
        else if(strcmp(argv[j], "-e") == 0)
            end = strtol(argv[j + 1], NULL, 10);
        else if(strcmp(argv[j], "-s") == 0)
            step = strtol(argv[j + 1], NULL, 10);
    }
    FILE *file;
    char *name = fileName;
    file = fopen(name, "w");

    for(; start <= end; start += step){
        fprintf(file, "%ld ", start);
        printf("%ld ", start);
    }
    printf("\n");
    fclose(file);
}
