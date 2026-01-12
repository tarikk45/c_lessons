#include <stdio.h>
#include <string.h>

int main(){
    float a = 4.5;
    float b = 3.1;
    float *p = &a;
    printf("p = %x",p);
    p = &b;
    printf("\n*p = %f",*p);
    printf("\np = %x",p);
    *p = 7.2;
    p = &a;
    *p = 5.3;
    printf("\na = %f",a);
    printf("\nb = %f",b);
    return 0;
}