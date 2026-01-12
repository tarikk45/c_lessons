#include <stdio.h>
int* add_numbers(int* number1,int* number2,int* sum){
    *sum = *number1 + *number2;
    return sum;
}

int main(){
    int number1 = 32;
    int number2 = 18;
    int sum;
    int* result = add_numbers(&number1,&number2,&sum);
    printf("Sum is %d",*result);

}