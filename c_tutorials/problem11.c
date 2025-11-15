#include <stdio.h>

int check_num(){
    int number;
    printf("Enter the number:");
    scanf("%d",&number);
    return number;
}

int even_or_odd(int number){
    if (number % 2 == 0){
        return 2;
    }
    else {
        return 1;
    }
}

int main(){
    int numberr;
    int result;
    numberr = check_num();
    result = even_or_odd(numberr);
    if (result == 1){
        printf("%d is an odd number",numberr);
    }
    else {
        printf("%d is an even number",numberr);
    }
}

