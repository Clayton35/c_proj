#include<stdio.h>
void mystrcpy(char *dest, char *src){
    int count = 0;
    printf("\t[mystrcpy]src: %s\n", src);

    while(src[count] != '\0'){
        dest[count] = src[count];
        count++;
    }
}

void printout(char *first, char *second){
    printf("String1: %s String2: %s\n", first, second);
}

int main(){
    char arr1[30], arr2[30] = {'\0'};

    printf("Please enter a string: ");
    scanf(" %[^\n]s", arr1);
    printf("\t[main]src: %s\n", arr1);

    mystrcpy(arr2, arr1);             //strcpy(dest, source)
    
    printout(arr1, arr2);
    
    return 0;
}
