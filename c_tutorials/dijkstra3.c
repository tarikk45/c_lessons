#include <stdio.h>
#include <string.h>

int main(){
    short a = 4;
    float b = 3.1;
    short *pa = &a;
    float *pb = &b;
    printf("%d",*pa);
    printf("\n%.1f",*pb);
    printf("\n%p",pa);
    printf("\n%d",pa);
    printf("\n%x",pa);
    printf("\n%p",&a);
    printf("\n%d",&a);
    printf("\n%x",&a);
    
    return 0;
}