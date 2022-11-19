// Write a menu driven program to implement priority queue using linked list with following: 
// operations -Enque, Deque, Display.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

void enque(int data, int priority)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    if(front == NULL)
    {
        front = newNode;
    }
    else
    {
        struct node *temp = front;
        if(temp->priority > priority)
        {
            newNode->next = temp;
            front = newNode;
        }
        else
        {
            while(temp->next != NULL && temp->next->priority < priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deque()
{
    if(front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp = front;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int choice;
    int data;
    int priority;
    do{
        printf("\n 1. Enque\n 2. Deque\n 3. Display\n 4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element: ");
                scanf("%d",&data);
                printf("Enter the priority: ");
                scanf("%d",&priority);
                enque(data, priority);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }
    }while(choice!=4);
}