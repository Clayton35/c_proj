#include<stdio.h>
#include<string.h>

void functionA(void);
void functionB(void);

int main(){
    for(int i = 0; i < 5; i++)
        functionA();
    for(int i = 0; i < 5; i++)
        functionB();
    
    return 0;
}
void functionA(void){
    int value = 100;
    printf("[FUNA] The value now is: %d\n", value);
    value += 1;
}
void functionB(void){
    static int value = 100;
    printf("[FUNB] The value now is: %d\n", value);
    value += 1;
}
