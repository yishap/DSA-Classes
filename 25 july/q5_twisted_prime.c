// Write a program in c to check a number is twisted prime or not.

#include<stdio.h>

int prime(int n){
    int i,flag=0;
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        return n;
    }
    else{
        printf("%d is not a prime number.\n",n);
        }

}

int twisted(int p,int q){
    int i,flag=0;
    for(i=2;i<=p/2;i++){
        if(p%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("%d is a twisted prime number.\n",q);
    else
        printf("%d is not a twisted prime number.\n",q);
}

int main(){
    int a,x,y,sum=0,r;
    printf("Enter a number : ");
    scanf("%d",&a);
    x = prime(a);
    for(int i=0;x>0;i++){
        r=x%10;
        sum=sum*10+r;
        x=x/10;
    }
    y=twisted(sum,a);
    return 0;
}