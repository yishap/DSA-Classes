//Write a program in C to add two user entered polynomials (double variable) using array.

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct polynomial{
    int degree_X;
    int degree_Y;
    int arr[10][10];
}p1,p2;



void display(struct polynomial p){
    int i,j;
    printf("\nThe polynomial is: ");
    for(i=p.degree_X;i>=0;i--){
        for(j=p.degree_Y;j>=0;j--){
            printf("%dx^%dy^%d  ",p.arr[i][j],i,j);
            if(i!=0 || j!=0){
                printf("+ ");
        }
    }
}
printf("\n");
}


void create(struct polynomial *p){
    int i,j;
    printf("Enter the degree X and Y of the polynomial: ");
    scanf("%d %d",&p->degree_X,&p->degree_Y);
    for(i=0;i<=p->degree_X;i++){
        for(j=0;j<=p->degree_Y;j++){
            printf("Enter the coefficient of x^%d y^%d: ",i,j);
            scanf("%d",&p->arr[i][j]);
        }
    }  
    display(*p); 
}

void add(struct polynomial p1,struct polynomial p2){
    int i,j,k;
    struct polynomial p3;
    p3.degree_X=(p1.degree_X>p2.degree_X)?p1.degree_X:p2.degree_X;
    p3.degree_Y=(p1.degree_Y>p2.degree_Y)?p1.degree_Y:p2.degree_Y;
    for(i=0;i<=p3.degree_X;i++){
        for(j=0;j<=p3.degree_Y;j++){
            p3.arr[i][j]=p1.arr[i][j]+p2.arr[i][j];
        }
    }
    display(p3);
}

int main(){
    create(&p1);
    create(&p2);
    add(p1,p2);
    return 0;
}



