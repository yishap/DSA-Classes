// Write a program in c to display name and cgpa where the name contains "KUMAR" by passing structure to a function.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int rollno;
    char name[20];
    float cgpa;
}s[5];

int display(struct student s[]){
    int i;
    printf("\nStudents whose name contains KUMAR are : \n");
    for(i=0;i<5;i++){
        if(strstr(s[i].name,"kumar"))
        {
            printf(" %s -- %f\n",s[i].name,s[i].cgpa);
        }
    }
    return 0;
}
int main(){
    int i,j;
    for(i=0;i<5;i++){
        printf("\nEnter rollno of student %d: ",i+1);
        scanf("%d",&s[i].rollno);
        printf("Enter name of student %d : ",i+1);
        scanf("%[^\n]",s[i].name);
        printf("Enter CGPA of student %d : ",i+1);
        scanf("%f",&s[i].cgpa);
    }
    display(s);
    return 0;
}
