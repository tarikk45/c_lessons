#include <stdio.h>

int addNumbers(int num1 , int num2);

int main(){
    int result = addNumbers(5,9);
    printf("Result = %d",result);
    return 0;

}

int addNumbers(int num1 , int num2){
    int sum = num1 + num2;
    return sum;
    printf("After");
}