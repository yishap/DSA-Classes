// Write a program to create a stack and count the number of pop operation performed on the stack to reach particular element.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(top==NULL)
    {
        top=new_node;
    }
    else
    {
        new_node->next=top;
        top=new_node;
    }
}

void display(){
    struct node *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int pop(int data){
    struct node *temp=top;
    int count=1;
    while(temp!=NULL){
        if(temp->data==data){
            return count;
        }
        else{
            count++;
            temp=temp->next;
        } 
    }
}

int main(){
    int ch,x,count;
    do{
        printf("\n1. Push\n2. Display\n3. Pop\n3. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1 : 
                push();
                break;
            case 2 :
                display();
                break;
            case 3 :
                printf("Enter the element to be searched: ");
                scanf("%d", &x);
                count = pop(x);
                printf("Number of pop operations performed: %d", count);
                break;
            case 4 :
                exit(0);
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }while(ch!=4);
    return 0;
}

