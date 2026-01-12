#include <stdio.h>
#include <string.h>

int main(){
    char str1[20] = "hello";
    char str2[20] = "world";
    char str3[20];
    strcpy(str3,str1);
    strcat(str3," ");
    strcat(str3,str2);
    printf("%s",str3);
    return 0;
}