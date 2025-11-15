#include <stdio.h>

void addNumbers(int num1 , int num2){
    int sum = num1 + num2;
    printf("The sum of %d and %d is %d",num1,num2,sum);
}

int main(){
    addNumbers(5,9);
    return 0;
}