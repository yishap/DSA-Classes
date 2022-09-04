// Write a program in c to return maximum when the function called first time and minimum when the function called second time.

#include<stdio.h>




int main(){
    int i,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nThe largest element in the array is: %d",max_min(a,n));
    printf("\nThe smallest element in the array is: %d",max_min(a,n));
}