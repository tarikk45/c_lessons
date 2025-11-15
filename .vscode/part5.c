// Addition       +
// Subtraction    -
// Multiplication *
// Division       /
// Remainder      %
// Increment by 1 ++
// Decrement by 1 --

#include <stdio.h>

int main()
{
    int x = 12 ;
    double y = 12.57 ;
    double z = 12.00 ;
    int t = 4 / 2 + 6 * 5 - 1 ;
    int number = x + 8 ;
    double result = y + 8.67 ;
    double result2 = z / 8.00 ;
    int result3 = x % 9 ;
    printf("%d\n",number);
    printf("%d\n",x + 8);
    printf("%.2lf\n",result);
    printf("%.2lf\n",x + y);
    printf("%.2lf\n",result2);
    printf("%d\n",result3);
    printf("%d\n",++x);
    printf("%d\n",--x);
    printf("%d",t);
    return 0;
}