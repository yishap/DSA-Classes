// Write a program to find the minimum distance between two user entered numbers in a list of numbers using the 
// technique of passing array to function.

#include<stdio.h>

void min(int *num,int n,int a, int b)
{
    int i,min=0;
    for(i=0;i<n;i++)
    {
        if(num[i]>a && num[i]<=b)
        {
            min++;
        }
    }
    printf("\nMinimum distance between %d and %d is %d\n",a,b,min);
}

int main(){
    int i,j,n,x,y;
    printf("enter the number of elements in the list : ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("enter the data \n");
        scanf("%d",&arr[i]);
    }
    printf("Enter two number from the list");
    scanf("%d %d",&x,&y);
    min(arr,n,x,y);
}