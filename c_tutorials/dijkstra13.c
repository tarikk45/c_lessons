#include <stdio.h>
#include <string.h>

int main(){
    char *str1 = "hello";
    char *str2 = "world";
    char str3[32];
    strcpy(str3,str1);
    strcat(str3," ");
    strcat(str3,str2);
    printf("%s",str3);
    return 0;
}