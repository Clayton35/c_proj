#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    FILE *ptr1 = NULL;
    ptr1 = fopen(argv[1], "w+");

    int again = 1;
    int val2 = 1;

    if(ptr1 == NULL){
        fprintf(stderr, "Error - File did not open.");
        exit(-1);
    }
    for(int i = 0; i < 100; i++){
        fprintf(ptr1, "%d ", i);
    }
    while(!feof(ptr1)){
        fscanf(ptr1, "%d ", &val2);
        fprintf(stderr, "Value of val2: %d\n", val2);
    }
    
    fclose(ptr1);

    return 0;
}
