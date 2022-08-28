#include<stdio.h>
#include<stdlib.h>
 
// stdin - Standard input
// stdout - Standard output
// stderr - Standard error
 
int main(int argc, char **argv)
{
    FILE *ptr = fopen("myfile3.bin", "r");

    if(ptr == NULL)
    {
        fprintf(stderr, "File didn't open properly\n");
        exit(-1);
    }

    int value = 1;

    if(argc == 2)
    {
        value = (int) strtol(argv[1], NULL, 10);
    }
    else
        value = 15;

    fseek(ptr, value * 4, SEEK_SET); // Trying to read the 15th number from the file

    fread(&value, 4, 1, ptr);       // Start at given memaddr, datatype size, number of elements, filestream
    printf("value: %d\n", value);

    fclose(ptr);
}
