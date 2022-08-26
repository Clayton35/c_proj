#include"header2.h"

int main(){
    char inputStr[SIZE];

    for(int count = 0; count < 3; count++)
        getStr(inputStr);
    return 0;
}
void getStr(char inputStr[]){
    int length = 0;

    printf("\nWelcome. Please enter a string up to 30 characters: ");
    scanf(" %[^\n]s", inputStr);

    while(inputStr[length] != '\0')
        length++;
    convertStr(inputStr, length);
}
void convertStr(char inputStr[], int length){
    int value = 0;
    char randStr[10];

    for(int count = 0; count < length; count++)
        value += (inputStr[count] * (length - count));
    if(value == 8470)
        challenge(value);
    else{
        printf("Welcome, you may proceed.\n");
        randChars(randStr);
        printf("%s\n", randStr);
    }
}
void randChars(char randStr[]){
    srand(time('\0'));

    for(int index = 0; index < 10; index++)
        randStr[index] = rand() % 94 + 33; 
}
void challenge(int value){
    srand(time('\0'));
    int pick = rand() % 3;
    char inputStr2[SIZE];

    if(pick == 0)
        printf("\nWhat has roots but does not grow? ");
    else if (pick == 1)
        printf("What runs but has no feet? ");
    else
        printf("What whispers with no lips? ");
    scanf(" %[^\n]s", inputStr2);
    checkAns(inputStr2, pick);
}
void checkAns(char inputStr2[], int pick){
    int value2 = 0, length = 0;
    char ans[3][SIZE]  = {{"mountain"}, {"nose"}, {"wind"}};

    while(inputStr2[length] != '\0')
        length++;

    for(int count = 0; count < length; count++){
        if(inputStr2[count] == ans[pick][count])
            value2++; 
        else{
            printf("\nI'm not mad, just disappointed... \n");
            break;
        }
    }
    if(value2 == length){
       printf("\nWell, you're a clever one. \n");
       exit(-1);
    } 
}
