#include <stdio.h>
#include <string.h>

void strCopy(char *p1, char *p2){
    while(*p1 != '\0'){
        *p2 = *p1;
        p2++;
        p1++;
    }
    *p2 = '\0';

}

int main(){
    char *str1 = "hello";
    char str2[10];
    strCopy(str1,str2);
    printf("%s",str2);
    return 0;
}