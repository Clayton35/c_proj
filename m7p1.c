/*
*
*       Created by: Clayton Davidson
*       Date: April 20, 2021
*
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *numPtr = fopen("numbers.txt", "rb");
    FILE *less60 = fopen("Below60.txt", "w");
    FILE *plus60 = fopen("Above60.txt", "w");
    float numVal;

    if(!numPtr || !less60 || !plus60){
        printf("File error.\n");
        exit(-1);
    }
    int numCount = 0, lessCount = 0, plusCount = 0;
    while(!feof(numPtr)){
        fread(&numVal, 4, 1, numPtr);
        
        if(numVal < 60){
            fprintf(less60, "Position: %d\t\tValue: %f\n", numCount, numVal);
            lessCount++;
        }
        else if(numVal >= 60){
            fprintf(plus60, "Position: %d\t\tValue: %f\n", numCount, numVal);
            plusCount++;
        }
    numCount++;
    if(numCount >= 1000000)
        break;
    }
    fclose(numPtr);
    fclose(less60);
    fclose(plus60);
    printf("\nNumbers.txt contains %d floats.\n", numCount);
    printf("less60.txt contains %d floats.\n", lessCount);
    printf("plus60.txt contains %d floats.\n", plusCount);

    return(1);
}
