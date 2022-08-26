#include<stdio.h>

int main() 
{
	char arrChar[50];
	char arrChar2[50];
	int count = 0;
	
	printf("\nPlease enter a sentence: ");
	scanf(" %[^\n]s", arrChar);
	
	printf("\nYour entered sentence is: %s\n", arrChar);
	
	while(arrChar[count] != '\0')
		count++;
		
	for(int count2 = 0; count2 < count; count2++)
	{
		if(arrChar[count] == '\0')
			arrChar2[count] == arrChar[count];
			
		arrChar2[count2] = arrChar[count - 1 - count2];
			
	}	
	
	for(int count2 = 0; count2 < 50; count2++)
		{
			if(arrChar2[0] > 90)
				arrChar2[count2] -= 32;
				
			else if(arrChar2[count2] == 0)
				continue;
			
			else if(arrChar2[count2] < 90 && arrChar2[count2] != 32)
				arrChar2[count2] += 32;
			
			else if(arrChar2[count2 - 1] == 32 && arrChar2[count2] > 90)
				arrChar2[count2] -= 32;
			
		}
	
	printf("\nYour reversed sentence is: %s\n", arrChar2);
	printf("\nYour sentence length is: %d\n", count);
	
	return 0;
}
