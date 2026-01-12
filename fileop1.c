#include <stdio.h>
#include <string.h>

int main(){
    FILE *file = fopen("test.txt","w");
    char input[100];
    if(file == NULL){
        printf("Failed");
        return 1;
    }
    printf("Enter a text:");
    fgets(input,sizeof(input),stdin);
    fprintf(file,"%s",input);
    fclose(file);
    return 0;

}