// Write a program in c to display first 10 Fibonacci numbers.

#include<stdio.h>

int main(){
    int i,a,b,c;
    a=0;
    b=1;
    printf("The first 10 fibonacci numbers are : ");
    printf("%d ",a);
    printf("%d ",b);
    for(i=0;i<8;i++)
    {
        c=a+b;
        a=b;
        b=c;
        printf("%d ",c);
    }
}