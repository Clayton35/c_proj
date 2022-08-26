#include<stdio.h>

int main()
{
	unsigned short int aval = 65535; 	//initialize aval variable with value 65535
	unsigned short int bval = 0; 		//initialize bval variable with value 0
	int cval; 				//declare cval variable
	
	printf("First printf statement:\n"); 
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval); //print current values 											//of all variables
	
	bval = aval + 1; //assigning bval with value of aval + 1
	cval = aval + 1; //assigning cval with value of aval + 1
	
	printf("\nSecond printf statement:\n");
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval); //print new values of all
										//variables
	
	return 0;
}

/* 4.  a) The values are 65535, 0, 0.
       b) At line 7, value of cval is NULL or 0.
       c) Unsigned only allows for positive integers.
       d) Short means an int with 2bytes of memory. 2^16 = 65536terms (-32,768 to 32767)
       e) Aval remains unchanged because the = moderator is assigning the value of aval + 1 to 
       bval/cval; not changing the value of aval itself.
       f) bval is an unsigned short, making the range of values 0 to 65535, 65536 is outside it's 
       parameters, thus it returns NULL or 0. cval is an int, so 65536 is within its acceptable
       value range. */
       
