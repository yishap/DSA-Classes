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
    struct node *link;
};

struct node *front = NULL;

void insert_by_priority(int item, int priority)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    tmp->priority = priority;
    if (front == NULL || priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }
    else
    {
        q = front;
        while (q->link != NULL && q->link->priority <= priority)
            q = q->link;
        tmp->link = q->link;
        q->link = tmp;
    }
}

int delete_by_priority()
{
    struct node *tmp;
    int item;
    if (front == NULL)
    {
        printf("Queue Underflow");
        exit(1);
    }
    else
    {
        tmp = front;
        item = tmp->info;
        front = front->link;
        free(tmp);
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
            ptr = ptr->link;
        }
    }
}