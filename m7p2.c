/*
*
*       Created by: Clayton Davidson
*       Date: April 20, 2021
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void openFile(char filename[]);
void adjustFile(FILE *namePtr, FILE *outputNames, char filename[]);

int main(){
    char filename[15] = "\0-names.txt";
    long offset = 0;
    printf("Please enter the first letter of the name you are looking for: ");
    scanf("%c", &filename[0]);
    
    openFile(filename);
    return(1);
}
void openFile(char filename[]){
    FILE *namePtr = fopen("names.txt", "r");
    FILE *outputNames = fopen(filename, "a+");

    if(!namePtr || !outputNames){
        printf("\nFile Error.\n");
        exit(-1);
    }
    adjustFile(namePtr, outputNames, filename);
}
void adjustFile(FILE *namePtr, FILE *outputNames, char filename[]){
    char nameEval[50] = "\0";
    char nameEval2[50] = "\0";
    int nameCount = 0;

    while(!feof(namePtr)){
        fscanf(namePtr, "%s", nameEval);

        if(nameEval[0] == filename[0]){
            nameCount++;
            
            if(strlen(nameEval) >= 6)
                printf("You added a name longer than 5 characters: %s\n", nameEval);

            fscanf(outputNames, "%s", nameEval2);
            if(strcasecmp(nameEval, nameEval2) == 0)
                continue;
            else if(strcasecmp(nameEval, nameEval2) != 0)
                fprintf(outputNames, "%s\n", nameEval);
        }
    }
    printf("\nThere are %d names in %c-names.txt.\n", nameCount, filename[0]);
}
