#include <stdio.h>

int main()  // removed void
{
	int value = 2;
	float valueTwo = 25.8;  // added a ;
	
	printf("Float: %.1f\nInteger: %d\n", valueTwo, value);  //replaced , with \n and adjusted
								//variable names accordingly
	
	valueTwo = (int)valueTwo; 		//adjusted variable name as necessary
	printf("\nFloat: %f\nInteger: %d\n", valueTwo, value);//Added \n twice, changed variable
									//names as necessary
	
	return 0; 		//added return 0; to end program
}

/* 1. Removed void at line 3.
   2. Added a ; at line 6.
   3. Replaced , with \n and adjusted necessary variable names at line 8
   4. Adjusted variable names as necessary at line 11
   5. Added \n twice and changed variable names as necessary at line 12
   6. Added return 0; statement to terminate main() function.
   */
   
/* 1. Line 10 is attemping to type cast ValueTwo from a float to an int.
   2. The output is different because the int type does not allow for decimals, so 25.8 is        	    rounded to 25, but it is still printed as a float because it was explicitly typecaste.
   */
