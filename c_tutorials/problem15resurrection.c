#include <stdio.h>

int fibonacciCalculator(int n);

int main() {
    int n;
    int result;
    printf("Enter the number: ");
    scanf("%d", &n);

    result = fibonacciCalculator(n);

    if (n == 1) {
        printf("The 1st number of the sequence is 1");
    } else if (n == 2) {
        printf("The 2nd number of the sequence is 1");
    } else if (n == 3) {
        printf("The 3rd number of the sequence is 2");
    } else if (n > 3) {
        printf("The %dth number of the sequence is %d", n, result);
    }
    
    return 0; 
}


int fibonacciCalculator(int n) {
   
    int a = 1; 
    int b = 2; 
    int current;

    for (int i = 4; i <= n; i++) {
        current = a + b;
        a = b;
        b = current;
    }
    return b; 
}