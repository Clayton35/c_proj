#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;    

    ptr = fopen("myfile3.bin", "wb");
    ptr2 = fopen("myfile3.txt", "w");

    if(ptr == NULL || ptr2 == NULL)
    {
        fprintf(stderr, "Nope!!!\n");
        exit(-1);
    }
 
    for(int count = 0; count < 100; count++)
    {    // size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
        fwrite(&count, 4, 1, ptr);
        // &count - represents the address fwrite will get its data that it will write to the file
        // 4 - represents the size of the datatype that will be written; in this case the size of count which is an int
        // 1 - represents the number of 4 bytes block to write into the file each time
        // ptr - file stream to write to.
        
        fprintf(ptr2, "%d ", count);
    }    

    fclose(ptr);
    fclose(ptr2);
    return 0;
}
