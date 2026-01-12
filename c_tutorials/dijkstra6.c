#include <stdio.h>

int main(){
    int nums[] = {2,4,6,8,10};
    printf("%p",nums);
    printf("\n%p",&nums[0]);
    int *p = nums;
    printf("\n%p",p);
    p = &nums[0];
    printf("\n%p",p);
    p = &nums[1];
    printf("\n%p",p);
    printf("\n%p",&nums[1]);
    printf("\n%p",nums + 1);
    printf("\n%p",&nums[2]);
    printf("\n%p",p + 1);
    return 0;
}