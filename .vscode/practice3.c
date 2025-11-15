#include <stdio.h>

int main()
{
    char operator;
    printf("Choose the operator: ");
    scanf("%c",&operator);
    int num1;
    int num2;
    printf("Enter the first number: ");
    scanf("%d",&num1);
    printf("Enter the second number: ");
    scanf("%d",&num2);

    int result;

    switch(operator){
        case '+':
        result = num1 + num2 ;
        break ;

        case '-':
        result = num1 - num2 ;
        break;

        case '/':
        result = num1 / num2 ;
        break;

        case '*':
        result = num1 * num2 ;
        break;
    }
    printf("%d",result);
    return 0 ;
}