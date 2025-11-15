#include <stdio.h>

int main() {
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);

    if (age > 120 || age < 0) {
        printf("Invalid age\n");
    }
    else if (age >= 18) {
        printf("You can vote\n");
    }
    else {
        printf("You cannot vote\n");
    }

    return 0;
}
