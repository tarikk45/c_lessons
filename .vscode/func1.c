#include <stdio.h>

void greet(){
    printf("Good Morning\n");
}

int main(){
    greet();
    greet();
    greet();
    printf("After the function");
    return 0;
}