// Write a program in c to display maximum of two numbers. without if statement.

#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);
    c=a>b?a:b;
    printf("the largest number is : %d ",c);
}