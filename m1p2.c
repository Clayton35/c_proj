#include<stdio.h>

int main()
{
	int choice;
	
	printf("Some aspects of life: ");
	printf("\n1. Polictics");
	printf("\n2. Money");
	printf("\n3. Friends");
	printf("\n4. Family");
	printf("\n5. Health");
	printf("\n6. Success");
	printf("\n7. Long Life");
	printf("\n8. Happiness");
	
	printf("\n\nWhat is the most important? ");
	scanf("%d", &choice);
	
	if(choice == 8)
	{
		printf("\nYes, Happiness is the most important!\n");
	}
	else 
	{
		printf("\nWrong! Happiness is the most important!\n");
	}
	
	return 0;
}
	
