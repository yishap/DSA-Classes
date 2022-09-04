// Write a program in c to display the frequency of vowels of a string.

#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int i,j,count=0;
    printf("Enter a string : ");
    scanf("%[^\n]",str);
    for(i=0;i<strlen(str);i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            count++;
        }
    }
    printf("\nNumber of vowels in the string : %d",count);
    return 0;
}