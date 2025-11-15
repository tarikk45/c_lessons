// Find the biggest value
#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Enter three value:");
    scanf("%d%d%d",&a,&b,&c);
    if (a >= b){
        if (c >= a)
        printf("Biggest is %d",c);
        else
        printf("Biggest is %d",a);
    }
    else if (b > a){
        if (c >= b)
        printf("Biggest is %d",c);
        else
        printf("Biggest is %d",b);
    }
    return 0;
}