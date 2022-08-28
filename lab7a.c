#include<stdio.h>

int main(){
    char mystring[20] = "Wow";

    sprintf(mystring, "Oh%sReally?\n", mystring);

    printf("\nThis is soooo cool: %s\n", mystring);

    return 0;
}
