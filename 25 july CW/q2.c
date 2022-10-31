// write a program to store student detail such as rollno, name, age and cgpa of five student using array structure 
// and display the same.

#include<stdio.h>

struct student
{
    int rollno;
    char name[20];
    int age;
    float cgpa;
} s[2];

int main(){
    int i;
    for(i=0; i<2; i++){
        printf("Enter rollno : ");
        scanf("%d", &s[i].rollno);
        printf("Enter name : ");
        scanf("%s", s[i].name);
        printf("Enter age : ");
        scanf("%d", &s[i].age);
        printf("Enter cgpa : ");
        scanf("%f", &s[i].cgpa);
    }
    for(i=0; i<2; i++){
        printf("\nStudent rollno : %d\n", s[i].rollno);
        printf("Student name : %s\n", s[i].name);
        printf("Student age : %d\n", s[i].age);
        printf("Student cgpa : %f\n", s[i].cgpa);
    }
    return 0;
}