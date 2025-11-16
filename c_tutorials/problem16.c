#include <stdio.h>

int getNumber();
int findGCD();
int findLCM();
int num1;
int num2;
int gcd = 0;
int lcm;

int getNumber(){
    printf("Enter two number:");
    scanf("%d %d",&num1,&num2);
    while (num1 <= 0 || num2 <= 0){
        printf("Invalid type. Please enter again:");
        scanf("%d %d",&num1,&num2);
    }
}

int findGCD(){
    for(int i = num1 ; i >= 1 ; i--){
        if (num1 % i == 0 && num2 % i == 0){
            gcd += i;
            break;

        }

    }
    return gcd;

}

int findLCM(){
    lcm = num1;
    while (lcm % num1 != 0 || lcm % num2 != 0){
        lcm++;
    }
    return lcm;
}

int main(){
    getNumber();
    int gcdd = findGCD();
    int lcmm = findLCM();
    printf("The GCD is: %d",gcdd);
    printf("\nThe LCM is: %d",lcmm);
    
}