// Write a program in c to display how many digits of a number without loop and if statement.

#include<stdio.h>
#include<math.h>


int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);
    int count=0;
    count=(a==0)?1:log10(a)+1;
    printf("The number of digits in the number are : %d",count);
    return 0;
}