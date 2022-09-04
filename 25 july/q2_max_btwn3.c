// Write a program in c to display maximum of three numbers using 2 simple if (one condition) statement.

#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("Enter three numbers : ");
    scanf("%d %d %d",&a,&b,&c);
    d=(a>b?(a>c?a:c):(b>c?b:c));
    printf("the largest number is : %d ",d);
}