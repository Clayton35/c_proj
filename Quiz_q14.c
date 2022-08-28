#include<stdio.h>
#include<string.h>

 
int main(int argc, char *buffer[])
{
    char *filename;
    char *mode;
    char *status;
    int count = 0;
 
    while(count < argc)
    {
        if(strcmp(buffer[count], "-F") == 0)
        {
            filename = buffer[count + 1];
            printf("The filename: %s\n", filename);
        }
        else if( strcmp(buffer[count], "-m") == 0)
        {
            mode = buffer[count + 1];        
            printf("The mode: %s\n", mode);
        }
        else if(strcmp(buffer[count], "-s") == 0)
        {
            status = buffer[count + 1];        
            printf("The made up status code: %s\n", status);
        }
        count++;
    }
 
    return 0;
}
