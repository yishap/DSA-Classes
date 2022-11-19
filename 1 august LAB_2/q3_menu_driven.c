// Write a menu driven program to perform the following operations on integer array –

// - Displaying the content of the array
// - Insertion at a specific position
// - Deletion at a specific position

#include<stdio.h>
#include<stdlib.h>

void display(int *a, int n)
{
    int i;
    printf("\nThe array is : ");
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}
void insert(int *a, int n)
{
    int p, element;
    printf("\nEnter the position : ");
    scanf("%d", &p);
    printf("Enter the element : ");
    scanf("%d", &element);
    for(int i=n; i>p-1; i--)
    {
        a[i]=a[i-1];
    }
    a[p-1]=element;
    for(int i=0; i<n+1; i++)
    {
        printf("%d ", a[i]);
    }
}
void delete(int *a, int n)
{
    int p;
    printf("\nEnter the position : ");
    scanf("%d", &p);
    for(int i=p-1; i<n-1; i++)
    {
        a[i]=a[i+1];
    }
    for(int i=0; i<n-1; i++)
    {
        printf("%d ", a[i]);
    }
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

    printf("\nEnter an option : ");
    printf("\n1. Display the array");
    printf("\n2. Insert an element at a specific position");
    printf("\n3. Delete an element at a specific position");
    printf("\n4. Exit\n");
    int option;
    scanf("%d", &option);
if(option==1){
    display(a, n);
}
else if(option==2){
    insert(a, n);
}
else if(option==3){
    delete(a, n);
}
else if(option==4){
    exit(0);
}
else{
    printf("\nInvalid option");
}
    return 0;
}

