#include<stdio.h>

#define SIZE 12

int getNums(float arrNum[])
{
    int count;
    
    for(count = 0; count < SIZE; count++)
    {
        printf("Please enter up to twelve numbers: ");
        scanf(" %f", &arrNum[count]);

        if(arrNum[count] == 0)
            break;
    }

    return count;
}

void sortNums(float arrNums[], int count)
{
    int temp;
   
    for(int count1 = 1; count1 < count; ++count1)
    {
        for(int index = 0; index < count - count1; index++)
        {
            if(arrNums[index] > arrNums[index + 1])
            {    
                temp = arrNums[index];
                arrNums[index] = arrNums[index +1];
                arrNums[index + 1] = temp;
            }
        } 
    }
}

float printNums(float arrNums[], float arrNums2[], int count)
{
    printf("Unsorted:\tSorted:\n");
    for(int index = 0; index < count; index++)
    {
        printf("%.2f\t\t%.2f\n", arrNums2[index], arrNums[index]);
    }
}

int main ()
{
    float arrNums[SIZE];
    float arrNums2[SIZE];

    int count = getNums(arrNums);
    printf("You entered %d terms.\n", count);

    for(int index = 0; index < count; index++)
    {
        arrNums2[index] = arrNums[index];
    }  
    sortNums(arrNums, count);

    printNums(arrNums, arrNums2, count);
    return 0;
}
