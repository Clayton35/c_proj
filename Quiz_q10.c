#include<stdio.h>
int main()
{
    FILE *fptr = NULL;
    fptr = fopen("random.txt", "r");
 
    if(fptr == NULL )
    {
        fprintf(stderr, "There was an error in opening the file\n");
    }
 
    fclose(fptr);
    return 0;
}
