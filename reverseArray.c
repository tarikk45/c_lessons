#include <stdio.h>

void reverseArray(int *start, int *end){
    for(int i = 0 ; i < 3 ; i++){
        int temp = *start;
        *start = *end;
        *end = temp;
        *start++;
        *end--;
    }

}

int main(){
    int array[] = {10,20,30,40,50,60};
    int length = sizeof(array) / sizeof(array[0]);
    reverseArray(array, array + length - 1);
    for(int j = 0 ; j < length ; j++){
        printf("%d ",array[j]);
    }
    return 0;

}