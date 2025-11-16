#include <stdio.h>
#include <stdlib.h>
int operationSelection();
int resultCalculator(int num);

int main(){
    while (1){
    printf("Menu\n1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Modulus\n6 - Exponentiation\n7 - Exit\nPlease select the operation.\n");
    int numm = operationSelection();
    if (numm == 7){
        printf("END");
        return 0;
    }
    int resultt = resultCalculator(numm);
    
    printf("The result is %d",resultt);
    printf("\n\n");
     
    }
    return 0;
}

int operationSelection(){
    int num;
    printf("Your choice:");
    scanf("%d",&num);
    return num;

}

int resultCalculator(int num){
    int num1;
    int num2;
    int result;
    printf("\nEnter the first number:");
    scanf("%d",&num1);
    printf("Enter the second number:");
    scanf("%d",&num2);
    if (num == 1){
        result = num1 + num2;
    }
    else if (num == 2){
        result = num1 - num2;
    }
    else if (num == 3){
        result = num1 * num2;
    }
    else if (num == 4){
        if (num2 == 0){
            printf("Invalid");
            return 0;
        }
        else {
            result = num1 / num2;
        }
    }
    else if (num == 5){
        if (num2 == 0){
            printf("Invalid");
            return 0;
        }
        else {
            result = num1 % num2;
        }
    }
    else if (num == 6){
        result = 1;
        for (int i = 1 ; i <= num2 ; i++){
            result *= num1;
        }
    }
    
    
    return result;
}