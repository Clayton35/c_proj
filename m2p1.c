#include<stdio.h>

int main()
{
	for(int i = 0; i <= 5; i++)
	{
		for(int j = 8; j > 0; j--)
		{
			if(i == 1 || i == 5)
			{
				printf("*");
			}
			else if(i == 2 && j <= 7 && j >= 2)
			{
				printf("*");
			}
			
			else if(i == 3 && j == 4 || i == 3 && j == 5)
			{
				printf("*");
			}
			else if(i == 4 && j <= 7 && j >= 2)
			{
				printf("*");
			}
			else
			{
			printf(" ");
			}
		}
		
		
	printf("\n");
	}
	
	printf("\n");
	
	return 0;
}
	
