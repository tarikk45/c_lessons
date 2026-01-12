#include <stdio.h>
#include <string.h>

int main(){
    char hi[] = "hello";
    hi[1] = 'a';
    printf("%s\n",hi);
    return 0;
}