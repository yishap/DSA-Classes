// Write a program in c to display cgpa from the structure (name, cgpa), and the name can be determined from the structure (name, roll), the roll number is searching key.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[20];
    int roll;
    float cgpa;
};

void cgpa_search(struct student *s, int n){
    int i,j,k;
    printf("Enter the roll number to search: ");
    scanf("%d",&k);
    for(i=0;i<n;i++){
        if(s[i].roll==k){
            printf("\nThe cgpa of %s with roll number %d is: %.2f",s[i].name,s[i].roll,s[i].cgpa);
            break;
        }
    }
    if(i==n){
        printf("\nThe roll number is not found in the list.");
    }
}
int main(){
    int i,n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student s[n];
    for(i=0;i<n;i++){
        printf("\nEnter the name of the student: ");
        scanf("%s",s[i].name);
        printf("Enter the roll number of the student: ");
        scanf("%d",&s[i].roll);
        printf("Enter the cgpa of the student: ");
        scanf("%f",&s[i].cgpa);
    }
    cgpa_search(s,n);
}