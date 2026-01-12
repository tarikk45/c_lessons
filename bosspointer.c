#include <stdio.h>

int main(){
    int a = 10;
    int *b = &a;
    int **c = &b;
    **c = **c + 5;
    printf("a = %d\n",a);
    printf("b = %d\n",*b);
    printf("c = %d\n",**c);
    printf("Adress a = %p\n",&a);
    printf("Adress b = %p\n",b);
    printf("Adress c = %p\n",*c);
    ++*b;
    printf("\n\n\n");
    printf("a = %d\n",a);
    printf("b = %d\n",*b);
    printf("c = %d\n",**c);
    printf("Adress a = %p\n",&a);
    printf("Adress b = %p\n",b);
    printf("Adress c = %p\n",*c);
    *b = **c++ + ++a;
    printf("\n\n\n");
    printf("a = %d\n",a);
    printf("Adress a = %p\n",&a);
    printf("Adress b = %p\n",b);
    printf("Adress c = %p\n",*c);
    printf("Adress c = %p\n",c);
    return 0;
}