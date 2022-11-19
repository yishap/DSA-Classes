/* write a program in c to perform the following operations on circular double linked list:
- creation of list
- display the list
- insertion after last node
- deletion at specified location
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void create(struct node *ptr){
    struct node *curr,*start;
    char ch;
    printf("\nEnter the data : ");
    scanf("%d",&ptr->data);
    start=ptr;
    ptr->next=start;
    ptr->prev=start;
    printf("Do you want to continue? (y/n) : ");
    scanf(" %c",&ch);
    while(ch=='y'){
        curr=(struct node *)malloc(sizeof(struct node));
        if (curr==NULL){
            printf("Memory not allocated");
            exit(0);
        }
        ptr->next=curr;
        curr->prev=ptr;
        ptr=ptr->next;
        printf("Enter the data : ");
        scanf("%d",&ptr->data);
        ptr->next=start;
        start->prev=ptr;
        printf("Do you want to continue? (y/n) : ");
        scanf(" %c",&ch);
    }
}

void display(struct node *ptr){
    struct node *start=ptr;
    printf("\nThe list is : ");
    while(ptr->next!=start){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
    printf("\n");
}

void insert_last(struct node *ptr){
    struct node *curr,*start=ptr;
    curr=(struct node *)malloc(sizeof(struct node));
    if (curr==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=curr;
    curr->prev=ptr;
    curr->next=start;
    start->prev=curr;
    printf("\nEnter the data : ");
    scanf("%d",&curr->data);
}

struct node *delete_node(struct node *ptr){
    struct node *start,*curr,*temp;
    start=ptr;
    curr=ptr;
    int loc;
    printf("\nEnter the location : ");
    scanf("%d",&loc);
    if (loc==1){
        temp=start->prev;
        start=ptr->next;
        start->prev=temp;
        temp->next=start;
        free(curr);
        return start;
    }
    else{
        for(int i=1;i<loc;i++){
            curr=curr->next;
        }
        temp=curr->prev;
        temp->next=curr->next;
        curr->next->prev=temp;
        free(curr);
        return start;
    }

}

int main(){                                     
    struct node *ptr,*temp1;
    ptr=(struct node *)malloc(sizeof(struct node));
    temp1=ptr;
    int choice;
    if (ptr==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        do{
            printf("\n1. Create the list,\n2. Display the list,\n3. Insert at last,\n4. Delete at specified location,\n5. Exit");
            printf("\nEnter your choice: ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                create(ptr);
                display(ptr);
                break;
            case 2:
                display(ptr);
                break;
            case 3:
                insert_last(ptr);
                display(ptr);
                break;
            case 4:
                temp1=delete_node(temp1);
                display(temp1);
                break;
            case 5:
                printf("Exit");
                exit(0);
                break;
            default:
                "Enter a valid choice";
                break;
            }
        }while(choice!=5);
    }
    return 0;
}
