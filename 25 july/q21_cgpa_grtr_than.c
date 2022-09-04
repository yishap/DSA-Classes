// Write a program in c to display name of the student having cgpa > 9.8.

#include<stdio.h>
#include<stdlib.h>

struct student{
    int rollno;
    char name[20];
    float cgpa;
};

int display(struct student *s,int n){
    printf("\nStudents with cgpa more than 9.8 are: \n");
    for(int i=0;i<n;i++){
        if(s[i].cgpa > 9.8){
            printf("\nRoll no. : %d",s[i].rollno);
            printf("\nName : %s",s[i].name);
            printf("\ncgpa : %f\n",s[i].cgpa);
        }
    }
    return 0;
}
int main(){
    int n;
    struct student s[n];
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("\nEnter the roll number: ");
        scanf("%d", &s[i].rollno);
        printf("Enter the name: ");
        scanf("%s", s[i].name);
        printf("Enter the cgpa: ");
        scanf("%f", &s[i].cgpa);
    }
    display(s,n);
    return 0;
}

