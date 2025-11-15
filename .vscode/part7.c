#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool value1 = true;
    bool value2 = false;
    printf("%d",value1);
    printf("\n%d",value2);
    /*
    >  Greater than
    <  Less than
    == Equal to
    >= Greater than or equal to
    <= Less than or equal to
    != Not equal to
    */
    bool value3 = (12 > 9);
    bool value4 = (12 < 9);
    printf("\n%d",value3);
    printf("\n%d",value4);
    int num1 = 45 ;
    int num2 = 34 ;
    bool test1 = (num1 > num2);
    printf("\n%d",test1);
    /*
    && = And
    || = Or
    !  = Not
    */
    int age = 18 ;
    int height = 11 ;
    bool test2 = (age > 14) && (height > 4);
    printf("\n%d",test2);
    // logical operatörleri mantık konusu gibi düşün çıktılarını
    return 0 ;

}