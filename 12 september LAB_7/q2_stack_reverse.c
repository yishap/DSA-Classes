/* Write a program in C to store user entered students detalls such as rollno, CGPA
in a stack and print these in the reverse order of storing. */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int rollno;
    float cgpa;
    struct node *next;
};

void push(struct node **ptr){
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
    if (curr==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    printf("Enter the rollno and cgpa: ");
    scanf("%d %f",&curr->rollno,&curr->cgpa);
    curr->next=*ptr;
    *ptr=curr;
}

void pop(struct node **ptr){
    struct node *temp;
    if (*ptr==NULL){
        printf("Stack is empty");
        exit(0);
    }
    temp=*ptr;
    *ptr=(*ptr)->next;
    free(temp);
}

void display(struct node *ptr){
    printf("\nThe stack is : \n");
    while(ptr!=NULL){
        printf("Rollno : %d, CGPA : %f ",ptr->rollno,ptr->cgpa);
        ptr=ptr->next;
        printf("\n");
    }
    printf("\n");
}

void reverse(struct node *ptr){
    struct node *temp;
    if (ptr==NULL){
        return;
    }
    reverse(ptr->next);
    printf("Rollno : %d, CGPA : %f ",ptr->rollno,ptr->cgpa);
    printf("\n");
}

int main(){
    struct node *start=NULL;
    int a;
    while(1){
        printf("\n1. Push \n2. Pop \n3. Display \n4. Reverse \n5. Exit ");
        printf(" \nEnter your choice : ");
        scanf("%d",&a);
        switch(a){
            case 1: push(&start);
                    break;
            case 2: pop(&start);
                    break;
            case 3: display(start);
                    break;
            case 4: reverse(start);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice");
        }
    }   
}


