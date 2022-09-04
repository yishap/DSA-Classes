// 1. Write a program to represent an user defined  sparse matrix in triplet representation.
#include <stdio.h>
#include <stdlib.h>

int main(){
    int row, column,n,k=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &column);
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        matrix[i] = (int *)malloc(column * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
            scanf("%d", &matrix[i][j]);
    }
    printf("The matrix is: \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("Enter the no. of non-zero elements: ");
    scanf("%d", &n);
    int sparse[n][3];
    for (int i=0;i<row;i++){
        for (int j=0;j<column;j++){
            if (matrix[i][j]!=0){
                sparse[k][0]=i+1;
                sparse[k][1]=j+1;
                sparse[k][2]=matrix[i][j];
                k++;
            }
        }
    }
    printf("The triplet representation is: \n");
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }
}




