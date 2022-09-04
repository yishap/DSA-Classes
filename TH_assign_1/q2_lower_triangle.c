// Write a program in C to print the lower triangle of an user entered matrix in a triangle format.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int row,col;
    printf("Enter the number of rows and column of the matrix : ");
    scanf("%d %d",&row,&col);

    int arr[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter the value at (%d,%d) :- ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nThe matrix is :- \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\nLower Triangle Matrix :- \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}