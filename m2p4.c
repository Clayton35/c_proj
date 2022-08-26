#include<stdio.h>

int main()
{
	short int aval = 100;
	int bval = 100;
	float cval = 100;
	double dval = 100;
	char eval = 100;
	unsigned char fval = 100;
	
	
	printf("Variable Name: aval \n&of variable: %p\nContent of Variable: %d\n", &aval, aval);
	printf("Size of aval: %lu bytes\n\n", sizeof(aval));  //prints name, address, content and size of aval
	
	printf("Variable Name: bval \n&of variable: %p\nContent of Variable: %d\n", &bval, bval);
	printf("Size of bval: %lu bytes\n\n", sizeof(bval));  //prints name, address, content and size of bval
	
	printf("Variable Name: cval \n&of variable: %p\nContent of Variable: %.2f\n", &cval, cval);
	printf("Size of cval: %lu bytes\n\n", sizeof(cval));  //prints name, address, content and size of cval
	
	printf("Variable Name: dval \n&of variable: %p\nContent of Variable: %.2e\n", &dval, dval);
	printf("Size of dval: %lu bytes\n\n", sizeof(dval));  //prints name, address, content and size of dval
	
	printf("Variable Name: eval \n&of variable: %p\nContent of Variable: %c\n", &eval, eval);
	printf("Size of eval: %lu bytes\n\n", sizeof(eval));  //prints name, address, content and size of eval
	
	printf("Variable Name: fval \n&of variable: %p\nContent of Variable: %c\n", &fval, fval);
	printf("Size of fval: %lu bytes\n\n", sizeof(fval)); //prints name, address, content and size of fval
	
	
	return 0;
}
