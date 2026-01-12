#include <stdio.h>

int main() {
    char *names[] = {"Ali", "Veli", "Ayse"};
    char **p = names;

    printf("%s\n", *p);       // Ali
    printf("%s\n", *(p + 1)); // Veli


    printf("**names        = %c\n", **names);          // 'A'
    printf("*names         = %s\n", *names);           // "Ali"
    printf("*names + 1     = %c\n", *(*names + 1));    // 'l'

    printf("*(names + 1)   = %s\n", *(names + 1));     // "Veli"
    printf("*(*(names + 1)+1)  = %c\n", *(*(names + 1)+1));    // 'V'
    printf("**(names + 1)  = %c\n", **(names + 1));  // 'V'
    return 0;
}