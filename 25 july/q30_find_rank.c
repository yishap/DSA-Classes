// find the rank of the student.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int roll;
    char name[20];
    int m1,m2,m3;
    float grade;
    int rank;
};

void rank(struct student *s,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s[i].grade<s[j].grade){
                struct student temp;
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        s[i].rank=i+1;
    }
}

void search(struct student *s,int n){
    int i,j,roll;
    printf("Enter the roll number of the student: ");
    scanf("%d",&roll);
    for(i=0;i<n;i++){
        if(s[i].roll==roll){
            printf("\nThe rank of the student is: %d",s[i].rank);
            break;
        }
    }
    if(i==n){
        printf("\nThe student is not found in the list.");
    }
}

int main(){
    int i,n,roll;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student s[n];
    for(i=0;i<n;i++){
        printf("Enter the roll number of student %d: ",i+1);
        scanf("%d",&s[i].roll);
        printf("Enter the name of student %d: ",i+1);
        scanf("%s",s[i].name);
        printf("Enter the marks of student %d: ",i+1);
        scanf("%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3);
        s[i].grade=(s[i].m1+s[i].m2+s[i].m3)/3.0;;
    }
    rank(s,n);  
    search(s,n);

}