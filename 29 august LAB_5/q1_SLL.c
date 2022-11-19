/* write a menu driven program in C to perform following operation on a single linked list:
- creation of list
- traversal of the list
- insertion at the beginning of the list
- Deletion at specified location of the list
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
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

struct node *insert_beggining(struct node *ptr,struct node *head){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&new_node->data);
    new_node->next=ptr;
    head=new_node;
    return head;
}

struct node *delete_node(struct node *ptr,struct node *head){
    int loc;
    printf("Enter the location: ");
    scanf("%d",&loc);
    if(loc==1){
        head=ptr->next;
        free(ptr);
        return head;
    }
    else{
        struct node *temp=ptr;
        for(int i=1;i<loc-1;i++){
            temp=temp->next;
        }
        struct node *temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        return ptr;
    }  
}

int main(){
    struct node *ptr1,*start1,*head=NULL;
    int choice;
    ptr1=(struct node *)malloc(sizeof(struct node));
    start1=ptr1;
    if (ptr1==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    else{
        do{
            printf("\nEnter operation to perform: ");
            printf("\n1. Create a linked list\n2. Display the linked list\n3. Insert at the beginning of the linked list\n4. Delete a node from the linked list\n5. Exit\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    create(ptr1);
                    display(start1);
                    break;
                case 2:
                    display(start1);
                    break;
                case 3:
                    start1=insert_beggining(start1,head);
                    display(start1);
                    break;
                case 4:
                    start1=delete_node(start1,head);
                    display(start1);
                    break;
                case 5:
                    exit(0);
                default:
                    printf("Invalid choice");
            }
        }
        while(choice!=5);                       
    }
    return 0;
}



