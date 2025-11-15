#include <stdio.h>

int main()
{
    for (int i = 1 ; i < 5 ; i++){
        printf("%d\n",i);
        break;
        printf("Audi TTS");
    }
    for (int i = 1 ; i < 5 ; i++){
        printf("%d\n",i);
        break;
        printf("Audi TTS");
    }
    for (int i = 1 ; i < 5 ; i++){
        if (i == 4){
            break;

        }
        printf("%d\n",i);
    }
    int number;
    while(1){
        printf("Enter a number: ");
        scanf("%d",&number);
        if (number < 0){
            break;
        }
        printf("%d\n",number);
    }
    for (int i = 1 ; i <= 5 ; i++){
        if (i == 3){
            continue;
        }
        printf("%d\n",i);
    }
    int number2;
    while(1){
        printf("Enter a number: ");
        scanf("%d",&number2);
        if (number2 < 0){
            break;
        }
        if ((number2 % 2) != 0){
            continue;
        }
        
        printf("%d\n",number2);
        
    }
    return 0;
}