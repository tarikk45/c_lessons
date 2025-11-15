// 19. Soru
#include <stdio.h>

int main()
{
    int n;
    
    printf("Enter a number:");
    scanf("%d",&n);
    if (n % 3 != 0){
        printf("Invalid Number");
    }
    else{
        int index = n / 3;
        while (1 <= index){
            for (int i = n ; i <= n * index ; i += n){
                printf("%d ",i);
            }
        index -= 1;
        printf("\n");
        }
    }
    return 0;
}