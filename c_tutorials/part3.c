#include <stdio.h>

int main()
{
    double number = 12.45; //Up to 8 byte
    float number2 = 10.9f; //Up to 4 byte
    printf("%lf\n",number);
    printf("%.2lf\n",number);
    printf("%f\n",number2);
    printf("%.1f\n",number2);
    printf("%.2f\n",number2);
    double number3 = 5.5e6;
    printf("%lf\n",number3);
    char character = 't';
    printf("%c\n",character);
    printf("%d\n",character);
    printf("%zu\n",sizeof(number));
    printf("%zu\n",sizeof(number2));
    return 0;
}