// 17. Soru
#include <stdio.h>

int main()
{
    int row;
    printf("Enter number of rows:");
    scanf("%d",&row);
    while (row >= 1){
     for (int i = 1 ; i <= row ; i++){
        printf("%d",i);
        

     }
    row -= 1;
    printf("\n");
    }
    return 0;
}