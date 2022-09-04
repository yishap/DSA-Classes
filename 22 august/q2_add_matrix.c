// Write a program in C to add two user defined sparse  matrix and display the resultant triplet.
#include <stdio.h>

void display(int sparse3[][3],int m,int n,int val){
    printf("\nThe sparse matrix is:\n");
    printf("rows:%d\tcolumn:%d value:%d\n",m,n,val);
    for(int i=0;i<val;i++){
        for(int j=0;j<3;j++){
        printf("%d\t",sparse3[i][j]);
    }
    printf("\n");
    }
}

void create(int sparse[][3],int k,int *r,int *c){
    printf("Enter the number of rows and columns:");
    scanf("%d %d",r,c);
    printf("Enter the row, columns and data :\n");
    for(int i=0;i<k;i++){
        scanf("%d %d %d",&sparse[i][0],&sparse[i][1],&sparse[i][2]);
    }
    display(sparse,*r,*c,k);
}

void add(int sparse1[][3],int sparse2[][3],int k1,int k2,int r3,int c3){
    int sparse3[20][3];
    int p1=0,p2=0,p3=0;
    while(p1<k1 && p2<k2){
     
    if(sparse1[p1][0]==sparse2[p2][0]){
        if(sparse1[p1][1]<sparse2[p2][1]){
            sparse3[p3][0]=sparse1[p1][0];
            sparse3[p3][1]=sparse1[p1][1];
            sparse3[p3][2]=sparse1[p1][2];
            p1++;
            p3++;
        }
        else if(sparse1[p1][1]>sparse2[p2][1]){
            sparse3[p3][0]=sparse2[p2][0];
            sparse3[p3][1]=sparse2[p2][1];
            sparse3[p3][2]=sparse2[p2][2];
            p2++;
            p3++;  
        }
        else if(sparse1[p1][1]==sparse2[p2][1]){
            sparse3[p3][0]=sparse1[p1][0];
            sparse3[p3][1]=sparse1[p1][1];
            sparse3[p3][2]=sparse1[p1][2]+sparse2[p2][2];
            p1++;
            p2++;
            p3++;  
        }
     }
    else if(sparse1[p1][0]>sparse2[p2][0]){
        sparse3[p3][0]=sparse2[p2][0];
        sparse3[p3][1]=sparse2[p2][1];
        sparse3[p3][2]=sparse2[p2][2];
        p3++;
        p2++;
    }
    //  (sparse1[p1][1]<sparse2[p2][1]){
       else{ sparse3[p3][0]=sparse1[p1][0];
        sparse3[p3][1]=sparse1[p1][1];
        sparse3[p3][2]=sparse1[p1][2];
        p1++;
        p3++;
        }
    
    }
    while(p1<k1){
            sparse3[p3][0]=sparse1[p1][0];
            sparse3[p3][1]=sparse1[p1][1];
            sparse3[p3][2]=sparse1[p1][2];
            p1++;
            p3++;
    }
    while(p2<k2){
            sparse3[p3][0]=sparse2[p2][0];
            sparse3[p3][1]=sparse2[p2][1];
            sparse3[p3][2]=sparse2[p2][2];
            p2++;
            p3++;
    }
    printf("After addition:\n");
    display(sparse3,r3,c3,p3);
}

int main(){
    int k1,k2,r1,r2,c1,c2,r3,c3;
    printf("Enter the number of non zero element in 1st array :");
    scanf("%d",&k1);
    int sparse1[k1+1][3];
    create(sparse1,k1,&r1,&c1);
    printf("Enter the number of non zero element in 2nd array :");
    scanf("%d",&k2);
    int sparse2[k2+1][3];
    create(sparse2,k2,&r2,&c2);
    if(r1!=r2 || c1!=c2){
        printf("Order mismatch cannot be added.");
        return 0;
    }
    int k3;
    k3=(k1>k2)?k1:k2;
    c3=(c1>c2)?c1:c2;
    r3=(r1>r2)?r1:r2;
    
    add(sparse1,sparse2,k1,k2,r3,c3);
    return 0;
}