// Write a menu driven program to implement circular queue using linked list with following operations 
// -Enque, Deque, Display.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enque(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front;
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
        rear->next = front;
        free(temp);
    }
}

void display()
{
    struct node *temp = front;
    while(temp->next != front)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
}

int main()
{
    int choice, data;
    do{
        printf("\n1. Enque\n2. Deque\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                enque(data);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice");
        }
    }while(choice != 4);
    return 0;
}