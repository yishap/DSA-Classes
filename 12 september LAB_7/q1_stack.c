/* Write a program in C to implement stack using linked list with the operations as push(), pop() and display(). */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **ptr){
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
    if (curr==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    printf("Enter the data : ");
    scanf("%d",&curr->data);
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
    printf("\nThe stack is : ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    struct node *start=NULL;
    int ch;
    while(1){
        printf("\n1. Push\n2. Pop \n3. Display \n4. Exit ");
        printf(" \nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push(&start);
                    break;
            case 2: pop(&start);
                    break;
            case 3: display(start);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }   

    return 0;
}