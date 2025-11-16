#include <stdio.h>

int updateMaxZeros();

int main(){
    
    int maxZeross = updateMaxZeros();
    printf("Longest consecutive zero sequences = %d",maxZeross);
    return 0;
    
}



int updateMaxZeros() {
    int number = 0;
    int currentZeros = 0;
    int maxZeros = 0;

    while (1) {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &number);

        if (number == -1)
            break;

        if (number == 0) {
            currentZeros++;
            if (currentZeros > maxZeros){
                maxZeros = currentZeros;
            }
        } 
        else{
            currentZeros = 0;
        }
        
    }
    return maxZeros;
}

