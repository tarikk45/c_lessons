#include <stdio.h>

int main()
{
    for (int i = 0 ; i < 10 ; i++){
        printf("%d ",i);
    }
    for (int i = 0 ; i < 10 ; i++){
        printf("\nEmergency Condition");
    }
    int sum = 0;
    for (int a = 1 ; a <= 100 ; a++){
        sum += a;
    }
    printf("\n%d",sum);
    int sum2 = 0;
    for (int b = 2 ; b <= 100 ; b += 2){
        sum2 += b;
    }
    printf("\n%d",sum2);
    int sum3 = 0;
    for(int c = 1 ; c <= 100 ; c += 2){
        sum3 += c;
    }
    printf("\n%d",sum3);
    return 0 ;
}