#include <stdio.h>
#include <string.h>

int main(){
    char str1[5] = "hello";
    char str2[5];
    char *ptr1 = str1;
    char *ptr2 = str2;
    while(*ptr1 != '\0'){
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }
    *ptr2 = '\0';
    printf("%s",str2);
    return 0;
}