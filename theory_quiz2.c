#include<stdio.h>
#include<string.h>


void swap(char *left, char *right){
	for(int i = 0; i < 40; i++){
		if(left[i] == '\0' || right[i] == '\0')
			break;
		else if(left[i] > right[i]){
			char temp = left[i];
			left[i] = right[i];
			right[i] = temp;
		}
	}
	printf("\nAfter swapping, array1 becomes: %s", left);
	printf("\nAfter swapping, array2 becomes: %s\n", right);
}

void reverse(char *string){
	int len_str = 0;
	int count = 0;

	printf("\nYour string: %s", string);

	while( *(string + count) ){
		count++;
	}

	for(int col = 0; col < count/2; col++){
		char temp = *(string+col);
		*(string+col) = *(string+(count - col - 1));
		*(string+(count - col - 1)) = temp;
	}

	printf("\nYour string reversed: %s\n", string);	
}
/*******************************************************************
 * title_rev: is a function that takes the address of a string
 *            it reverses the string and then converts the string to
 *            title cased:
 * Example: This is my string become Gnirts Ym Si Siht
 *******************************************************************/
void title_rev(char *string){
    char revCap[40] = {'\0'};
    int index = 0;

    printf("\nYour string is: %s", string);
    while(string[index] != '\0')
        index++;
    for(int i = 0; i < index;i++){
        revCap[i] = string[index - i - 1];
    }
    for(int i = 0; i < index; i++){
        if(revCap[0] > 90)
            revCap[i] -= 32;
        else if(revCap[i] == 0)
            continue;
        else if(revCap[i] < 90 && revCap[i] != 32)
            revCap[i] += 32;
        else if(revCap[i-1] == 32 && revCap[i] > 90)
            revCap[i] -= 32;   
    }
    printf("\nYour new string is: %s\n", revCap);
    
}
/***********************************************************************************************
 * clr_stdin implemented based on code
 * Reference: https://stackoverflow.com/questions/38767967/clear-input-buffer-after-fgets-in-c
 *
 ***********************************************************************************************/
void clr_input(char *string1){
	char *pos = strchr(string1, '\n');
	if(pos){
		*pos = '\0';
	}
	else{
		scanf("%*[^\n]");
		scanf("%*c");
	}
}

void getInput(char *string1, char *string2){
    printf("Please enter a string: ");
    fgets(string1, 40, stdin);
    clr_input(string1);

    printf("Please enter second string: ");
    fgets(string2, 40, stdin);
    clr_input(string2);
}
    
int main()
{
	char array1[40];
	char array2[40];
	
	getInput(array1, array2);
	reverse(array1);
    title_rev(array2);
	swap(array1, array2);

	return 0;
}
