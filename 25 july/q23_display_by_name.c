// Write a program in c to display cgpa of a particular student (by name) by sending structure and name to a function.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int rollno;
    char name[20];
    float cgpa;
    }s[5];

int display(struct student s[],char name[]){
    int i,flag=0;
    for(i=0;i<5;i++){
        if(strcmp(s[i].name,name)==0){
            printf("\nCGPA of %s is %f\n",name,s[i].cgpa);
            return 1;
        }
        else{
            flag=1;
        }
    }
    if(flag==1){
        printf("\nStudent not found\n");
    }
    return 0;
}

int main(){
    int i,j;
    for(i=0;i<5;i++){
        printf("\nEnter rollno of student %d: ",i+1);
        scanf("%d",&s[i].rollno);
        printf("Enter name of student %d : ",i+1);
        scanf("%s",s[i].name);
        printf("Enter CGPA of student %d : ",i+1);
        scanf("%f",&s[i].cgpa);
    }
    printf("\nEnter name of the student : ");
    char name[20];
    scanf("%s",name);
    display(s,name);
    return 0;
}