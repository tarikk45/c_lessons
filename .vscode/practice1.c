#include <stdio.h>

int main()
{
    double number;
    printf("Enter a number: ");
    scanf("%lf",&number);
    if (number > 0){
        printf("It is positive");
    }
    else if (number < 0){
        printf("It is negative");
    }
    else {
        printf("It is 0");
    }
    return 0 ;
}