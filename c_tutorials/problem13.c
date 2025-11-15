#include <stdio.h>

int getNumber(){
    int number;
    printf("Enter a number:");
    scanf("%d",&number);
    return number;
}

int addOperation(int number){
    int sum = 0;
    for(int i = 1 ; i <= number ; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int numberr = getNumber();
    int summ = addOperation(numberr);
    printf("The sum is %d",summ);
    return 0;
}