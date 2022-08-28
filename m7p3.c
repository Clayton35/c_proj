/*
*
*       Created by: Clayton Davidson
*       Date: April 23, 2021
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void openFile(char *argv[]);
void readFile(FILE *fptr);

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "File name missing.\n");
        exit(-1);
    }

    openFile(argv);

    return (1);
}
void openFile(char *argv[]){
    char fileName[25];
    strcpy(fileName, argv[1]);

    FILE *fptr = fopen(fileName, "r");

    if(!fptr){
        printf("File error.\n");
        exit(-1);
    }

    readFile(fptr);
}
void readFile(FILE *fptr){
    unsigned char readPtr[20];
    int count = 0;
    int textFlag = 0;
    unsigned char buffer[5] = "\0";
    
    fread(buffer, 1, 4, fptr);  

    while(fread(readPtr, 1, 16, fptr)){
        fprintf(stdout, "%06x\t", count);
        for(int i = 0; i < 16; i++){
            if(readPtr[i] == '\0')
                fprintf(stdout, "   ");
            else
            fprintf(stdout, "%02x ", readPtr[i]);

            count++;
        }
        fprintf(stdout, "\t| ");
        
        for(int j = 0; j < 16; j++){
            if(readPtr[j] >= 0x20 && readPtr[j] <= 0x7E){
                fprintf(stdout, "%c", readPtr[j]);
                textFlag++;
            }
            else
                fprintf(stdout, ".");
        }
        fprintf(stdout, "|\n");  

        for(int k = 0; k < 20; k++){
            readPtr[k] =  '\0';
        }
        
    }
    fprintf(stdout, "\nThe Magic Value is 0x%02x%02x%02x%02x.\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    
    if(((textFlag * 100) / count) >= 75)
        fprintf(stdout, "This is definitely a text file.\n");
    else if(((textFlag * 100) / count) < 75 && ((textFlag * 100) / count) > 25)
        fprintf(stdout, "This is possibly a text file.\n");
    else if(((textFlag * 100) / count) <= 25)
        fprintf(stdout, "This is probably a binary file.\n");
}
