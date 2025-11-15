#include <stdio.h>

int main()
{
    int age;
    double number;
    char alphabet;
    double number2;
    char alphabet2;
    
    printf("Enter the age: ");

    scanf("%d",&age);

    printf("Age = %d\n",age);

    scanf("%d",&age);
    printf("Age = %d\n",age);


    printf("Enter double input: ");
    scanf("%lf",&number);
    
    printf("Enter character input: ");
    scanf("\n%c",&alphabet);

    printf("Number = %lf",number);
    printf("\nCharacter = %c",alphabet);

    printf("\nEnter input values: ");
    scanf("\n%lf %c",&number2,&alphabet2);

    printf("Number = %lf",number2);
    printf("\nCharacter = %c",alphabet2);

    return 0;
}