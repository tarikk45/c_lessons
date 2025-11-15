#include <stdio.h>

int main()
{
    char a = '5';
    int b = 9 ;
    double c = 5.67 ;
    int result = b + c ;
    double result2 = b + c ;
    double result3 = (int)c + b ;
    int result4 = (int)c + b ;
    printf("%d",a + b);
    printf("\n%d",result);
    printf("\n%lf",result2);
    int d = 5.67 ;
    printf("\n%d",d);
    printf("\n%lf",result3);
    printf("\n%d", result4);
    int e = 9 ;
    int f = 2 ;
    double result5 = e / f ;
    double result6 = (double) e / f ;
    printf("\n%lf",result5);
    printf("\n%lf",result6);
    return 0 ;
}