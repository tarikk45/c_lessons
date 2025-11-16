#include <stdio.h>
int fibonacciCalculator();



int main(){
    fibonacciCalculator();
    return 0;

}

int fibonacciCalculator(){
    int n;
    int a = 1;
    int b = 1;
    printf("Enter the n:");
    scanf("%d",&n);
    if (n == 1){
        printf("The 1st number of the fibonacci is %d",a);
    }
    else if (n == 2){
        printf("The 2nd number of the fibonacci is %d",b);
    }
    else if (n == 3){
        printf("The 1st number of the fibonacci is %d",a + b);
    }
    else if (n > 3){
        for (int i = 1 ; i <= n ; i++){
            int next_fib = a + b;
            a = b;
            b = next_fib;

        }
        printf("The %dth number of the fibonacci is %d",n,b);
    }
    else {
        printf("Invalid stuff");
    }
}