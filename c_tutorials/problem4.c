// 13. Soru
#include <stdio.h>

int main()
{
    int n;
    int pro = 1;
    printf("Enter a number:");
    scanf("%d",&n);
    for (int i = n ; i >= 1 ; i--){
        pro *= i;
    }
    printf("%d! = %d",n,pro);
}