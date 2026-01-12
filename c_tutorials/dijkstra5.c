#include <stdio.h>
#include <string.h>

int main(){
    short *pt = NULL;
    float a = 3.1;
    float *fpt = &a;
    printf("Size of pt: %d\n",sizeof(pt));
    printf("Size of fpt: %d\n",sizeof(fpt));
    printf("Size of short: %d\n",sizeof(short));
    return 0;
}