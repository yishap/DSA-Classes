// Write a program to store employee details such as empid, ename, age, salary of five employees using structure and print the details of the employee with highest salary using the technique of passing pointer to structure to a function.

#include<stdio.h>

struct employee
{
    int empid;
    char ename[20];
    int age;
    int salary;
}e[5];

void max_salary(struct employee *p)
{
    int i;
    int max=e[0].salary;
    for(i=0; i<5; i++)
    {
        if(e[i].salary>max)
        {
            max=e[i].salary;
            p=&e[i];
        }
    }
    printf("\nEmployee id : %d\n", p->empid);
    printf("Employee name : %s\n", p->ename);
    printf("Employee age : %d\n", p->age);
    printf("Employee salary : %d\n", p->salary);
}

int main(){
    int i;
    for(i=0; i<5; i++){
        printf("Enter the employee empid : ");
        scanf("%d", &e[i].empid);
        printf("Enter the employee ename : ");
        scanf("%s", e[i].ename);
        printf("Enter the employee age : ");
        scanf("%d", &e[i].age);
        printf("Enter the employee salary : ");
        scanf("%d", &e[i].salary);
    }
    max_salary(e);
    return 0;
}