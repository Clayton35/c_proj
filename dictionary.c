#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

void mainMenu(char arrChar[][20], int rows);
void getInput(char *input);
void insertWord(int rows, char arrChar[][20], char *input);
void checkDictionary(char arrChar[][20], int rows);
void printDict(char arrChar[][20], int rows);

int main(){
    char arrChar[100][20] = {{"around"}, {"pool"}, {"lifeguard"}, {"strangers"}, {"ordered"}, 
                            {"marbles"}, {"somewhere"}, {"futuristic"}, {"unrealistic"}, 
                            {"definition"}, {"surprise"}};
    int rows = 12;
    mainMenu(arrChar, rows);

    return 0;
}
void mainMenu(char arrChar[][20], int rows){
    char choice;
    char input[20] = {'\0'};

    printf("\nWelcome to Clayton's Dictionary!");
    printf("\n\t1. Add Word\n\t2. Search\n\t3. View Dictionary\n\t4. Exit\n");
    printf("\nWhat would you like to do today? ");
    scanf(" %c", &choice);

    if(choice == '1'){
        if(rows < 101){
            getInput(input);
            insertWord(rows, arrChar, input);
            printf("There are now %d words in the dictionary.\n", rows);
            rows+=1;
            mainMenu(arrChar, rows);   
        }
        else{
            printf("\nDictionary is full.");
            mainMenu(arrChar, rows);
        }
    }
    else if(choice == '2')
        checkDictionary(arrChar, rows);
    else if(choice == '3')
        printDict(arrChar, rows);
    else if(choice == '4')
        exit(-1);
    else{
        printf("\nInvalid Entry. Please Try again.\n");
        mainMenu(arrChar, rows);
    }
}
void getInput(char *input){
    printf("\nPlease enter a word up to 19 characters: ");
    scanf(" %[^\n]s", input);

    printf("Your added word is: %s\n", input);
    
    if(input[0] == '2' && input[1] == '0' && input[2] == '2' && input[3] == '1')
        exit(-1); 
}
void insertWord(int rows, char arrChar[][20], char *input){
    strcpy(arrChar[rows - 1], input);
}
void checkDictionary(char arrChar[][20], int rows){
    char wrdSrch[20] = {'\0'};
    int choice, index, count = 0;

    printf("What word would you like to search? ");
    scanf(" %[^\n]s", wrdSrch);

    for(index = 0; index < rows; index++){
        if(strcasecmp(arrChar[index], wrdSrch) == 0){
            printf("\nYour word is in row %d in the dictionary. ", index + 1);
            mainMenu(arrChar, rows);
        }
        else 
            count++;
            continue;
    }
    if(count == index){
        printf("\nYour word is not in the dictionary. ");
        mainMenu(arrChar, rows);
    }
}
void printDict(char arrChar[][20], int rows){
    for(int index = 0; index < rows - 1; index++)
        printf("%d. %s\n", index + 1, arrChar[index]);
    
    mainMenu(arrChar, rows);
}
