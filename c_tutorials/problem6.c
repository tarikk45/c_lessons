//15. Soru
#include <stdio.h>

int main()
{
    int num;
    int isprime = 0;
    int iscomposite = 0;
    while (1) {
        printf("Enter a number:");
        scanf("%d",&num);
        if (num == -1){
            break;
        }
        if (num == 2){
            isprime++;
            continue;
        }
        if (num > 1){
            for (int i = 2 ; i * i <= num ; i++){
                if (num % i == 0){
                    iscomposite++;
                    continue;
                }
                else{
                    isprime++;
                    continue;

                }

            }
        }
    }
    printf("\nCount of prime numbers entered = %d\n", isprime);
    printf("Count of composite numbers entered = %d\n", iscomposite);
    return 0;
}
