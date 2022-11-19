// Suppose a computer system has one processor to execute different tasks. Each task has a time of execution. 
// Each task is assigned with a priority number depending upon the type of task : 
// Local Printing (Lowest Priority -1), Web Applications (Priority-2), I/O interfacing (Highest Priority -3). 
// Every time a task is generated, its execution time and priority number are entered and stored. 
// Using Priority Queue to maintain such task, write functions for insertion and deletion operations for the 
// tasks with the condition that a task with highest priority will be processed first.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;
    int info;
    struct node *next;
};

struct node *front = NULL;

void enqueue(int item)
{
    struct node *temp, *q;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    if(item==1)
        temp->priority=1;
    else if(item==2)
        temp->priority=2;
    else if(item==3)
        temp->priority=3;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
    }
    else if(front->priority<temp->priority)
    {
        temp->next=front;
        front=temp;
    }
    else
    {
        q=front;
        while(q->next!=NULL && q->next->priority>temp->priority)
        {
            q=q->next;
        }
        temp->next=q->next;
        q->next=temp;
    }
}

int dequeue()
{
    struct node *temp;
    int item;
    if (front == NULL)
    {
        printf("Queue Underflow");
        exit(1);
    }
    else
    {
        temp = front;
        item = temp->info;
        front = front->next;
        free(temp);
    }
    return item;
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf("Queue is empty");
    else
    {
        printf("Queue is : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
    }
}

void execute()
{
    struct node *ptr=front;
    if(front==NULL)
        printf("No tasks to execute");
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->priority==3)
                printf("\nI/O interfacing task executed");
            else if(ptr->priority==2)
                printf("\nWeb Applications task executed");
            else if(ptr->priority==1)
                printf("\nLocal Printing task executed");
            ptr=ptr->next;
        }
    }
    while(front!=NULL)
    {
        dequeue();
    }
}

int main()
{
    int choice, item, priority;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.display\n4.Execute\n5.Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the operation to be done: ");
                printf("\n1.local printing\n2.web applications\n3.I/O interfacing\n");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                printf("Deleted item is %d", item);
                break;
            case 3:
                display();
                break;
            case 4:
                execute();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}