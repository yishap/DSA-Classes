// write a program to store student detail such as rollno, name, age and cgpa of five student using array structure and display the same.

#include<stdio.h>

struct student
{
    int rollno;
    char name[20];
    int age;
    float cgpa;
} s[5];

int main(){
    int i;
    for(i=0; i<5; i++){
        printf("Enter the student rollno : ");
        scanf("%d", &s[i].rollno);
        printf("Enter the student name : ");
        scanf("%s", s[i].name);
        printf("Enter the student age : ");
        scanf("%d", &s[i].age);
        printf("Enter the student cgpa : ");
        scanf("%f", &s[i].cgpa);
    }
    for(i=0; i<5; i++){
        printf("\nStudent rollno : %d\n", s[i].rollno);
        printf("Student name : %s\n", s[i].name);
        printf("Student age : %d\n", s[i].age);
        printf("Student cgpa : %f\n", s[i].cgpa);
    }
    return 0;
}