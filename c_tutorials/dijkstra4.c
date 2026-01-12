#include <stdio.h>

void incr(int *num){
    *num += 1;

}

int main(){
    int a = 4;
    int *b = &a;
    printf("a = %d",a);
    printf("\nb = %d",*b);
    incr(&a);
    printf("\na = %d",a);
    printf("\nb = %d",*b);
    return 0;
}