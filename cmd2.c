#include<stdio.h>
#include<string.h>


int main (int argc, char *argv[]){
    for(int count = 1; count < argc; count++){
        if(argv[count][1] == 'f' && argv[count][0] != '-' )
            printf("argv[%d]: %s\n", count + 1, argv[count + 1]);
        if(strncmp("-f", argv[count], 2) == 0)
            printf("argv[%d]: %s\n", count + 1, argv[count + 1]);
    }
    printf("Value of argc: %d", argc);
    return 0;
}
