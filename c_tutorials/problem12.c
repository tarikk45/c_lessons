#include <stdio.h>
#include <ctype.h>

char getChar(){
    char letter;
    printf("Enter the char: ");
    scanf("%c",&letter);
    return letter;
}

int Declaration(char letter){
    char lowerC = tolower(letter);
    if(!isalpha(lowerC)){
        return -1;
    }
    else if(lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u'){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int result;
    char letterr;
    letterr = getChar();
    result = Declaration(letterr);
    if(result == 1){
        printf("It is a vowel");
    }
    else if(result == 0){
        printf("It is a consonant");
    }
    else{
        printf("Error 404");
    }
}