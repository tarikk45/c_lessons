#include <stdio.h>
#include <string.h>

int main(){
    FILE *file = fopen("test.txt","r");
    char text[100];
    char text2[100];
    if(file == NULL){
        printf("File does not exist");
        return 1;
    }
    fscanf(file,"%s %s",text,text2);
    fclose(file);
    printf("%s %s",text,text2);
}