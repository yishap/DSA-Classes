// Write a program in c to display unique characters from a string. (Remove duplicate).

#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int i,j,count=0;
    printf("Enter a string : ");
    scanf("%[^\n]",str);
    for(i=0;i<strlen(str);i++){
        for(j=i+1;j<strlen(str);j++){
            if(str[i]==str[j]){
                str[j]='\0';
            }
        }
    }
    printf("\nUnique characters in the string are : ");
    for(i=0;i<strlen(str);i++){
        printf("%c",str[i]);
    }
    return 0;
}