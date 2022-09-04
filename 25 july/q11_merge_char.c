// Write a program in c to merge two arrays of characters.

#include<stdio.h>
#include<string.h>
int main(){
    char a[100],b[100];
    int i;
    printf("Enter the first string: ");
    scanf("%s",a);
    printf("Enter the second string: ");
    scanf("%s",b);
    strcat(a,b);
    printf("The merged string is: ");
    printf("%s",a);
    return 0;
}