#include <stdio.h>

int addNumbers(int num1 , int num2){
    int sum = num1 + num2;
    return sum;
    printf("After");
}

int main(){
    int result = addNumbers(5,9);
    printf("Result = %d",result);
    return 0;

}