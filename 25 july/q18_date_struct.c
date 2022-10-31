// Write a program in c to create a date structure within a student structure.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[20];
    int roll;
    int age;
    struct date{
        int day;
        int month;
        int year;
    }dob;
}s[3];

void display(struct student s[3]){
    int i;
    for(i=0;i<3;i++){
        printf("\nName: %s",s[i].name);
        printf("\nRoll: %d",s[i].roll);
        printf("\nAge: %d",s[i].age);
        printf("\nDate of birth: %d-%d-%d",s[i].dob.day,s[i].dob.month,s[i].dob.year);
    }
}

int main(){
    int i;
    for(i=0;i<3;i++){
        printf("\nEnter the name: ");
        scanf("%s",s[i].name);
        printf("Enter the roll: ");
        scanf("%d",&s[i].roll);
        printf("Enter the age: ");
        scanf("%d",&s[i].age);
        printf("Enter the date of birth (Eg: DD-MM-YYYY) : ");
        scanf("%d-%d-%d",&s[i].dob.day,&s[i].dob.month,&s[i].dob.year);
    }
    display(s);
    return 0;
}