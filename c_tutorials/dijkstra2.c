#include <stdio.h>
#include <string.h>

void swapNumbers(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;

}

int main(){
    int a = 5;
    int b = 3;
    printf("a = %d and b = %d",a,b);
    swapNumbers(&a,&b);
    printf("\na = %d and b = %d",a,b);

    return 0;
}