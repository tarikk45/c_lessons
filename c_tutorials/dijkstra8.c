#include <stdio.h>

int main(){
    int a1[5] = {12,7,17,5,13};
    int *pa = a1;
    pa = pa + 2;
    *(pa + 1) = 888;
    printf("%d",*(pa + 1));
    printf("\n%d",a1[3]);
}