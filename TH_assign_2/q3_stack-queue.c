// Write a program in C to implement stack using queue data structure only.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};  

void push(struct node **front,struct node **rear, int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item; 
    temp->next = NULL;
    if(*front==NULL)
    {
        *front=temp;
        *rear=temp;
    }
    else
    {
        (*rear)->next=temp;
        *rear=temp;
    }
}

void pop(struct node **front,struct node **rear)
{
    struct node *temp=NULL;
    struct node *temp_rear=NULL;
    while((*front)->next!=NULL)
    {
        push(&temp,&temp_rear,(*front)->info);
        *front=(*front)->next;
    }
    printf("Deleted element is %d. ",(*front)->info);
    *front=NULL;
    *rear=NULL;
    while(temp!=NULL)
    {
        push(front,rear,temp->info);
        temp=temp->next;
    }
}

void display(struct node *front)
{
    struct node *temp;
    temp = front;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
}

int main(){
    struct node *front=NULL,*rear=NULL;
    int choice,item;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the item to be pushed : ");
                scanf("%d",&item);
                push(&front,&rear,item);
                break;
            case 2:
                pop(&front,&rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice");
        }
    }
}







