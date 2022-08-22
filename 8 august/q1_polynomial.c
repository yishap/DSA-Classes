// Write a menu driven program to perform the following operations on single variable polynomial 
// - Insertion of values
// - Displaying the values
// - Addition of two polynomials
// - Multiplication of two polynomials

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
struct polynomial{
    int degree;
    int coeff[max];
}p1,p2;

int max_degree(struct polynomial p1,struct polynomial p2){
    if(p1.degree>p2.degree)
        return p1.degree;
    else
        return p2.degree;
}

void display(struct polynomial p){
    int i;
    for(i=p.degree;i>=0;i--){
        printf("%dx^%d  ",p.coeff[i],i);
        if(i>0)
            printf("+ ");
    }
    printf("\n");
}

void insert(struct polynomial *p){
    int i;
    printf("Enter the degree of the polynomial: ");
    scanf("%d",&p->degree);
    for(i=0;i<=p->degree;i++){
        printf("Enter the coefficient of x^%d: ",i);
        scanf("%d",&p->coeff[i]);
    }
}

void add(struct polynomial p1,struct polynomial p2){
    int i,j,k;
    struct polynomial p3;
    p3.degree=max_degree(p1,p2);
    for(i=0;i<=p3.degree;i++){
        p3.coeff[i]=p1.coeff[i]+p2.coeff[i];
    }
    display(p3);
}

void multiply(struct polynomial p1,struct polynomial p2){
    int i,j,k;
    struct polynomial p3;
    p3.degree=p1.degree+p2.degree;
    for(i=0;i<=p3.degree;i++){
        p3.coeff[i]=0;
    }
    for(i=0;i<=p1.degree;i++){
        for(j=0;j<=p2.degree;j++){
            p3.coeff[i+j]+=p1.coeff[i]*p2.coeff[j];
        }
    }
    display(p3);
}

int main(){
    insert(&p1);
    insert(&p2);
    int choice;
    do{
        printf("\n1. Displaying the values");
        printf("\n2. Addition of two polynomials");
        printf("\n3. Multiplication of two polynomials");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nThe polynomials are :\n");
                display(p1);
                display(p2);
                break;
            case 2:
                printf("\nThe added polynomial is :\n");
                add(p1,p2);
                break;
            case 3:
                printf("\nThe resultant polynomial is :\n");
                multiply(p1,p2);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }while(choice!=4);
    return 0;
}





