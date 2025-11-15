#include <stdio.h>

void calculateSquare(int number){
    int square = number * number;
    printf("The square of %d is %d",number,square);
}

int main(){
    calculateSquare(5);
    return 0;
}