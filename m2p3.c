#include<stdio.h>

int main() 
{
	int var1;
	int sum = 0;
	float average;

	for(int x = 0; x < 10; x++)
	{
		printf("\nPlease enter an integer: ");
		scanf("%d", &var1);
		sum += var1;
	}
	
	if(sum % 2 == 0)
	{
		printf("\nYour sum is even.\n");
	}
	else
	{
		printf("\nYour sum is odd.\n");
	}
	
	average = (float) sum / 10;
	printf("\nThe average is: %.2f\n\n", average);
	
	
	return 0;
}
		
