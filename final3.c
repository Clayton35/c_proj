#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

int main(int argc, char *argv[]){
    int begin = 0, end = 0, count = 0;
    char filename[30] = "\0";
    FILE *log = fopen("log.txt", "w+");
    FILE *fileNames = fopen("fileNames.txt", "w+");

    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-b") == 0){
            begin = strtol(argv[i + 1], NULL, 10);
        }
        else if(strcmp(argv[i], "-e") == 0){
            end = strtol(argv[i + 1], NULL, 10);
        }
    }
    
    while(begin < end){
        fprintf(fileNames, "\nPair%03d_01.txt", begin);
        fscanf(fileNames, "%s", filename);
        fprintf(stderr, "\n[DEBUG] Value of filename: %s", filename);
        fprintf(stderr, "\n[DEBUG] Value of begin: %d\n", begin);
        FILE *ptr = fopen(filename, "r");

        if(!ptr){
            begin++;
        }
        else{
            fprintf(log, "\nPair%03d_01.txt - Exists\tPair%03d_02.txt - Exists\n", begin, begin);
            count++;
            begin++;
        }
        

    }
    fprintf(log, "\nFound %d pairs of files - total file count: %d\n", count, count * 2);
    fprintf(stdout, "\nFound %d pairs of files - total file count: %d\n", count, count * 2);

    fclose(log);
    fclose(fileNames);
    return 1;
}
/*I was having an issue getting the filenames to populate and search for the intended file.
If that file did not open, that file could not be found. If it does open, write the name of the file
to the log.txt and increment the count by one. 
*/
