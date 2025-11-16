#include <stdio.h>

void updateMaxZeros(int num, int *currentZeros, int *maxZeros) {
    if (num == 0) {
        
        (*currentZeros)++;
    } else {
        
        if (*currentZeros > *maxZeros) {
            *maxZeros = *currentZeros;
        }
        
        *currentZeros = 0;
    }
}

int main() {
    int num;
    int currentZeros = 0; 
    int maxZeros = 0;     

    printf("Enter a stream of integers (enter -1 to stop):\n");

    
    do {
        
        if (scanf("%d", &num) != 1) {
            
            printf("Invalid input. Please enter integers only.\n");
            
            while (getchar() != '\n');
            continue; 
        }

        
        if (num != -1) {
            updateMaxZeros(num, &currentZeros, &maxZeros);
        }

    } while (num != -1);

    
    if (currentZeros > maxZeros) {
        maxZeros = currentZeros;
    }

    
    printf("\nThe length of the longest consecutive zero sequence is: %d\n", maxZeros);

    return 0;
}