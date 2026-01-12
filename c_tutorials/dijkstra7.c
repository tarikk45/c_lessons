#include <stdio.h>

int main(){
    int nums[5] = {2,4,6,8,10};
    printf("%p",nums);
    printf("\n%p",&nums[0]);
    printf("\n%p",&nums[1]);
    printf("\n%p",&nums[2]);
    printf("\n%p",&nums[3]);
    printf("\n%p",&nums[4]);
    int *ptr = nums;
    printf("\n%d",*ptr);
    printf("\n%d",*(ptr + 1));
    printf("\n%p",ptr);
    printf("\n%p",ptr + 1);
    for(int i = 0 ; i < 5 ; i++){
        printf("\n%d = %p\n",nums[i],ptr);
        ptr++;
    }
}