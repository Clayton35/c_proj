#include<stdio.h>
 
void swap(int *ptr1, int *ptr2)        // Pass By reference which is simply passing the address
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
 
void swap2(int val1, int val2)        // Pass By Value which is simply making a copy
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
    printf("\t[swap2]val1: %d, val2: %d\n", val1, val2);
}
 
int main()
{
    int val1, val2;

    printf("Please enter 2 values: ");
    scanf(" %d %d", &val1, &val2);

    printf("val1: %d, val2: %d\n", val1, val2);

    swap(&val1, &val2);

    printf("val1: %d, val2: %d\n", val1, val2);

    swap2(val1, val2);

    printf("val1: %d, val2: %d\n", val1, val2);
 
    return 0;
}
