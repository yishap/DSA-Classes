// Write a program in c to display details of student structure by passing to a function.

#include<stdio.h>
#include<stdlib.h>

struct student{
    int rollno;
    char name[20];
    float cgpa;
}s[3];

void display(struct student s[]){
    int i;
    for(i=0;i<3;i++){
        printf("\nRollno : %d\n",s[i].rollno);
        printf("Name : %s\n",s[i].name);
        printf("CGPA : %f\n\n",s[i].cgpa);
    }
}

int main(){
    int i;
    for(i=0;i<3;i++){
        printf("Enter rollno : ");
        scanf("%d",&s[i].rollno);
        printf("Enter name : ");
        scanf("%s",s[i].name);
        printf("Enter CGPA : ");
        scanf("%f",&s[i].cgpa);
    }
    display(s);
    return 0;
}