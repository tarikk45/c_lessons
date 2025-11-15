// 18. Soru
#include <stdio.h>

int main() {
    char ch;

    printf("Enter letters ('.' to stop):");

    while(1) {  
        scanf(" %c", &ch);

        if (ch == '.') 
            break;

        
        if (ch == 'a' || ch == 'A' ||
            ch == 'e' || ch == 'E' ||
            ch == 'i' || ch == 'I' ||
            ch == 'o' || ch == 'O' ||
            ch == 'u' || ch == 'U')
            continue;

        printf("%c", ch);
    }

    return 0;
}
