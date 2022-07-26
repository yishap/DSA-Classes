// write a program to store employee detail such as empid, ename, age and salary of an employee using structure and display the same.

#include<stdio.h>

struct employee
{
    int empid;
    char ename[20];
    int age;
    int salary;
} e;

int main(){
    printf("Enter the employee id : ");
    scanf("%d", &e.empid);
    printf("Enter the employee name : ");
    scanf("%s", e.ename);
    printf("Enter the employee age : ");
    scanf("%d", &e.age);
    printf("Enter the employee salary : ");
    scanf("%d", &e.salary);
    printf("\nEmployee id : %d\n", e.empid);
    printf("Employee name : %s\n", e.ename);
    printf("Employee age : %d\n", e.age);
    printf("Employee salary : %d\n", e.salary);
    return 0;
}