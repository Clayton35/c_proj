#include<stdio.h>

int main()
{
	int arr1[6];
	char arr2[6];
	int count = 0;
	
	for( ; count < 6; count++)
	{
		printf("\nPLease enter an integer: ");
		scanf(" %d", &arr1[count]);
	}
	
	printf("\nPlease enter a six letter string: ");
	scanf(" %[^\n]s", arr2);
	
	for(count = 0; count < 6; count++)
		printf("\nInteger %d: %d\t%p\t0x%x", count, arr1[count], &arr1[count], arr1[count]);
		
	printf("\n");
	
	for(count = 0; count < 6; count++)
		printf("\narrChar[%d] %c\t%p\t0x%x", count, arr2[count], &arr2[count], arr2[count]);
		
	printf("\n");
	
	return 0;
}

/* 1. The difference between integer[1] and integer[2] is 4 bytes.
	2. Based on the difference seen, I can conclude that integers take up 4bytes of memory.
	3. The difference in the address of arrChar[1] and arrChar[2] is 1byte.
	4. Based on the difference seen, I can conclude that characters take up 1byte of memory.
	5. The difference in memory between the first address and the last address of each array 
	is the overall size of each array; 4 bytes for the int array, 6 bytes for the character array.
	*/
