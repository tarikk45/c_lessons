#include <stdio.h>
#include <string.h>

typedef struct{
    char name[16];
    float gpa;
}Student;

int main(){
    Student std1 = {"Peter",3.4};
    Student *p1 = &std1;
    int *q;
    char *r;
    printf("Name: %s",(*p1).name);
    printf("\nName: %s",p1->name);
    printf("\nGPA: %.2f",(*p1).gpa);
    printf("\nGPA: %.2f",p1->gpa);
    printf("\n%d",sizeof(Student));
    printf("\n%d",sizeof(p1));
    printf("\n%d",sizeof(q));
    printf("\n%d",sizeof(r));

    return 0;
}