#include"header.h" // links to header.h file

int main (){
    char inputStr[WIDE] = {'0'}; // initializes inputStr[] with value '0' in every element
    char revStr[WIDE] = {'0'};  // initializes revStr[] with value '0' in every element

    for(int count = 0; count < SIZE; count++) // runs getStrings() for SIZE(4) iterations
        getStrings(inputStr, revStr);  // calls getStrings() function with parameters inputStr[] and revStr[]
   
    return 0;
}

void getStrings(char inputStr[], char revStr[]){ // takes user input and stores them in inputStr[]
    printf("\nPlease enter a string up to 20 characters: ");
    scanf(" %[^\n]s", inputStr);

    reverseStr(inputStr, revStr); // calls reverseStr() with parameters inputStr and revStr
}

void reverseStr(char inputStr[], char revStr[]){   // reverses inputStr[] and stores it in revStr[]

    int count = 0;

    while(inputStr[count] != '\0')
         count++;

    for(int index = 0; index < count; index++){
        if(inputStr[count] == '\0')
            revStr[count] == inputStr[count];

        revStr[index] = inputStr[count - 1 - index];   
    }    
    isPalindrome(inputStr, revStr, count); // calls isPalindrome() with parameters inputStr and revStr
}

void isPalindrome(char inputStr[], char revStr[], int count){  // evaluates inputStr[] against revStr[] to determine is they are the same (thus a palindrome)
    int pal = 0;
    
    for(int count = 0; count < WIDE; count++){
        if(inputStr[count] == revStr[count])
            pal++;
        else
            break;
    }
    if(pal >= count)
        printf("\n%s is a palindrome.\n", inputStr);
    else 
        printf("\n%s is not a palindrome.\n", inputStr);
} 
