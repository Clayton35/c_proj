#include<stdio.h>

int main()
{
	char arrChar[40];
	int index = 0;
	char capTit;
	
	printf("Please enter a string less than 40 characters: ");
	scanf(" %[^\n]s", arrChar);
	
	printf("\nPress (a) CAPITALIZE (b) Title Case: ");
	scanf(" %c", &capTit);
	
	if(capTit == 'a')
	{
		for( ; index < 40; index++)
		{
			if(arrChar[index] > 90)
			{
				arrChar[index] -= 32;
			}
		
		}
	}
	
	else
	{
		for( ; index < 40; index++)
		{
			if(arrChar[0] > 90)
				arrChar[index] -= 32;
				
			else if(arrChar[index] == 0)
				continue;
			
			else if(arrChar[index] < 90 && arrChar[index] != 32)
				arrChar[index] += 32;
			
			else if(arrChar[index - 1] == 32 && arrChar[index] > 90)
				arrChar[index] -= 32;
			
		}
	}
	
	printf("%s", arrChar);
	printf("\n");
	
	return 0;
}
