// Write a program in C to merge two user entered linked list using the technique of passing two pointers to function.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};

void create(struct node *ptr){
    int i,data;
    printf("Enter the data: ");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    printf("Do you want to enter more data? (y/n): ");
    char ch;
    scanf(" %c",&ch);
    while(ch=='y'){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        ptr->next=new_node;
        ptr=new_node;
        printf("Do you want to enter more data? (y/n): ");
        scanf(" %c",&ch);
    }
}

void display(struct node *ptr){
    printf("\nThe linked list is: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void merge(struct node *ptr1,struct node *ptr2){
    struct node *temp1=ptr1;

    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=ptr2;
    display(ptr1);
}

void main(){
    struct node *ptr1,*ptr2,*ptr,*start1,*start2;
    printf("First linked list:\n");
    ptr1=(struct node *)malloc(sizeof(struct node));
    start1=ptr1;
    if (ptr1==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    create(ptr1);
    display(ptr1);
    printf("Second linked list:\n");
    ptr2=(struct node *)malloc(sizeof(struct node));
    start2=ptr2;
    if (ptr2==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    create(ptr2);
    display(ptr2);
    merge(ptr1,ptr2);
}
