#include<stdio.h>

int main()
{
	int aval = 0;
	
	int remain;
	
	while(aval <= 65535)
	{
		printf("Enter an integer between 0-65535: ");
		scanf("%d", &aval);
		
		if(aval > 65535)
		{
			printf("You don't listen well.");
			break;
		}
		
		for(int i = 0; i < 16; i++)
		{
			if(i % 4 == 0)
			{
				printf(" ");
			}
			
			remain = aval % 2;
			aval = aval / 2;
			
			printf("%d", remain);
		}
		
		printf("\n");
	}

	printf("\n");
	return 0;
}
