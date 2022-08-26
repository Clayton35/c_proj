#include<stdio.h>

int main()
{
	for(int i = 0; i <= 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(i == 1 || i == 5 || i == 2 && j % 2 != 0 || i == 4 && j %2 != 0 || i == 3 && j % 2 ==0)
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
