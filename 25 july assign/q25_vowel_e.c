// Write a program in c to display name and cgpa where the name contains only one vowel "E".

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int rollno;
    char name[20];
    float cgpa;
}s[5];

int vowel_e(struct student s[]){
    int i;
    printf("\nStudents whose name contains only one vowel 'E' are : \n");
    for(i=0;i<5;i++){
        if(strstr(s[i].name,"e"))
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
        scanf("%s",s[i].name);
        printf("Enter CGPA of student %d : ",i+1);
        scanf("%f",&s[i].cgpa);
    }
    vowel_e(s);
    return 0;
}