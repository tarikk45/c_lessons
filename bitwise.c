#include <stdio.h>

int main(){
    unsigned char a = 60;
    unsigned char b = 13;
    unsigned char c = a & b;
    unsigned char d = a | b;
    unsigned char e = a ^ b;
    unsigned char f = ~a;
    unsigned char g = !a;
    printf("c = %d d = %d e = %d f = %d g = %d",c,d,e,f,g);
    unsigned char h = 3;
    unsigned char i;
    unsigned char j;
    i = h << 2;
    j = h >> 2;
    printf("\ni = %d j = %d",i,j);
    unsigned char k = 10;
    unsigned char l;
    l = k >> 2;
    printf("\nl = %d\n",l);
    printf(765 & 1);
    return 0;
}