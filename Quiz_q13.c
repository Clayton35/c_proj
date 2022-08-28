#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    char temp[50] = {'\0'};
    char fill[] = {"_"};
    FILE *ptr1 = NULL;
    FILE *ptr2 = NULL;
    ptr1 = fopen("unknown.txt", "r");
    ptr2 = fopen("knowns.txt", "w");

    if(ptr1 == NULL || ptr2 == NULL){
        fprintf(stderr, "Error. No file opened.\n");
        exit(-1);
    }

    while(!feof(ptr1)){
        fscanf(ptr1, " %s", temp);
        if(strcmp(temp, "ephemeral") == 0){
            fprintf(ptr2, "%s ", fill);
            continue;
        }
        else if(strcmp(temp, "Ephemeral") == 0){
            fprintf(ptr2, "%s ", fill);
            continue;

        }
        else{
            fprintf(ptr2, "%s ", temp);
        }
    }
    return 0;
}
