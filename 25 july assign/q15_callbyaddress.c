// Write a program in c to swap two number using call by address.
#include <stdio.h>

int swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b;
    printf("enter two numbers : ");
    scanf("%d %d", &a, &b);
    printf("Before reversing a = %d and b = %d.\n", a, b);
    swap(&a, &b);
    printf("After reversing a = %d and b = %d.", a, b);
    return 0;
}