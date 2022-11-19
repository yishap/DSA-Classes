// Write a program to find out the second largest element in a list stored in a dynamic array.

#include<stdio.h>
#include<stdlib.h>

void second_largest(int *a, int n)
{
    int i,j,max1,max2;
    for(int i=0; i<n; i++)
    {
        if(a[i]>max1)
        {
            max2=max1;
            max1=a[i];
        }
        else if(a[i]>max2)
        {
            max2=a[i];
        }
    }
    printf("\nSecond largest element is : %d", max2);
}

int main(){
    int i, n, *a, max, max1, max2;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    a=(int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++){
        printf("Enter the element : ");
        scanf("%d", &a[i]);
    }
    second_largest(a, n);
    return 0;
}