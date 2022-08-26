#include<stdio.h>

int main()
{
	int aval = 0;
	
	int remain;
	
	while(aval <= 65535)
	{
		int counter = 0;
		
		printf("Enter an integer: ");
		scanf("%d", &aval);
		int bval = aval;
		
		if(aval > 65535)
		{
			printf("Please try again.");
			break;
		}
		else if(aval > 4095 && aval < 65535)
			counter += 16;
		else if(aval > 255 && aval < 4095)
			counter += 12;
		else if(aval > 15 && aval < 255)
			counter += 8;
		else
			counter += 4;
			
			
		for(int i = 0; i < counter; i++)
		{
			if(i % 4 == 0)
				printf(" ");
			
			remain = aval % 2;
			aval = aval / 2;
			
			printf("%d", remain);
		}
		
		printf(" \t --->  0x%x", bval);
		
		printf("\n");
	}

	printf("\n");
	return 0;
}

/* 1. The best choice would be to store the bits as 'char' datatype.
	2. Char datatypes only use 1 byte per "element" making it the most memory efficient way to store the bits.
	3. It would take 17 bits to store the integer 75000. 
	*/
