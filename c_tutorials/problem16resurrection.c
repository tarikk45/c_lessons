#include <stdio.h>

void getInput(int *a, int *b) {
    printf("Enter two positive integers: ");
    
    while (scanf("%d %d", a, b) != 2 || *a <= 0 || *b <= 0) {
        
        while (getchar() != '\n');
        
        printf("Invalid input. Please enter two *positive* integers: ");
    }
}

int findGCD(int n1, int n2) {
    int temp;

    while (n2 != 0) {
        temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    
    return n1;
}

int findLCM(int n1, int n2, int gcd) {
    
    return (int)(((long long)n1 * n2) / gcd);
}

int main() {
    int num1, num2, gcd, lcm;

    getInput(&num1, &num2);

    gcd = findGCD(num1, num2);

    lcm = findLCM(num1, num2, gcd);

    printf("----------------------------------\n");
    printf("First number:  %d\n", num1);
    printf("Second number: %d\n", num2);
    printf("----------------------------------\n");
    printf("Greatest Common Divisor (GCD): %d\n", gcd);
    printf("Least Common Multiple (LCM):   %d\n", lcm);
    printf("----------------------------------\n");

    return 0;
}