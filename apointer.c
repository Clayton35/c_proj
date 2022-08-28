/*
* pointer.c
*
* Created on: Mar 17, 2021
*   Author: clayton
*/
#include<stdio.h>
int fun(int *ptr){
    printf("\n[fun]Hello World, my point is: %p %d\n", &ptr, *ptr);
    return 200;
}
int main(){

    int *point1;
    int num = 100;
    point1 = &num;

    printf("\n[main]Hello World, my point is: %p %d\n", &point1, *point1);
    
    num = fun(&num);
    fun(point1);

    
    return 0;
}
