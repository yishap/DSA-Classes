/* Write a menu driven program to implement queue using linked list with following operations 
-Enque, Deque, Display. */

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enque(int x){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = x;
    new_node->next = NULL;
    if(front==NULL){
        front = new_node;
        rear = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void deque(){
    if(front==NULL){
        printf("Queue is empty");
    }
    else{
        struct node *ptr = front;
        front = front->next;
        free(ptr);
    }
}

void display(){
    struct node *ptr = front;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->next;
    }
}

int main(){
    int choice;
    int x;
    do{
        printf("\n 1. Enque\n 2. Deque\n 3. Display\n 4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element: ");
                scanf("%d",&x);
                enque(x);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }while(choice!=4);
}
