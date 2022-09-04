//  Write a program in c to check a number is ARMSTRONG number or not.

#include<stdio.h>

int main(){
    int a,r,n,sum=0;
    printf("Enter a number : ");
    scanf("%d",&a);
    n=a;
    
    for(int i=0;a>0;i++){
        r=a%10;
        sum=sum+(r*r*r);
        a=a/10;
    }

    if(sum==n)
    {
    printf("%d is a armstrong number.",n);
    }
    else
    {
    printf("%d is not a armstrong number.",n);
    }
}