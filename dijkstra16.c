#include <stdio.h>

int add(int num1, int num2){
    return num1 + num2;

}

int main(){
    int (*pfun)(int num1,int num2) = &add;
    int a = 5;
    int b = 8;
    int r = 0;
    r = pfun(a,b);
    printf("%d",r);
}