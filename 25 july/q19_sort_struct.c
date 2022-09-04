// Write a program in c to sort the student structure (name, cgpa) according to cgpa.

#include<stdio.h>

struct student{
    int rollno;
    char name[20];
    float cgpa;
}s[5];

int sort(struct student s[]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(s[i].cgpa>s[j].cgpa){
                struct student temp;
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
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
        scanf("%s",s[i].name);
        printf("Enter CGPA of student %d : ",i+1);
        scanf("%f",&s[i].cgpa);
    }
    sort(s);
    printf("\nSorted list of students : \n");
    for(i=0;i<5;i++){        
        printf("CGPA of %s is %f\n",s[i].name,s[i].cgpa);
    }
    return 0;
}
