#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *ptr = fopen("final.bin", "rb");
    int location = 0, numByt = 0, count = 0;
    char byte; 

    if(!ptr){
        fprintf(stderr, "\nFile Error.\n");
        exit(-1);
    }

    while(!feof(ptr)){
        if(count == 0x35){
            fread(&location, 4, 1, ptr);
            fprintf(stdout, "\nValue of location: %d\n", location);
        }
        else if(count == 0x40){
            fread(&numByt, 4, 1, ptr);
            fread(&byte, 1, 1, ptr);
            fprintf(stdout, "\nValue of numByt: %d\nValue of byte: %d", numByt, byte);
        }
        else if(count > 0x40)
            break;

        count++;
    }
    char array[50] = "\0";
    //array = location;
    fprintf(stdout, "\nBefore XOR: %s\n", array);
    for(int i = 0; i < 50; i++){
        array[i] ^ byte;
    }
    fprintf(stdout, "After XOR: %s\n", array);

    fclose(ptr);
    return 1;
}
