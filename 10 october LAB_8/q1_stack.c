/* Write a program in C to store student rollno, height and weight in a stack in sorted order of rollno.
Also there should be a provision for revising the weight of any student by using pop operation and push operation. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int rollno;
    float height;
    float weight;
};

struct node{
    struct student info;
    struct node *next;
};

struct node *top = NULL;

void push(struct student s){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = s;
    new_node->next = top;
    top = new_node;
}

void pop(){
    if(top==NULL){
        printf("Stack is empty");
    }
    else{
        struct node *ptr = top;
        top = top->next;
        free(ptr);
    }
}

void display(){
    struct node *ptr = top;
    while(ptr!=NULL){
        printf("\nRollno: %d",ptr->info.rollno);
        printf(" Height: %f",ptr->info.height);
        printf(" Weight: %f\n",ptr->info.weight);
        ptr = ptr->next;
    }
}

void sort_stack(){
    struct node *ptr = top;/ 
    struct node *ptr1 = top;
    struct student temp;
    while(ptr!=NULL){
        ptr1 = ptr->next;
        while(ptr1!=NULL){
            if(ptr->info.rollno > ptr1->info.rollno){
                temp = ptr->info;
                ptr->info = ptr1->info;
                ptr1->info = temp;
            }
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}

void revise_weight(int rollno){
    struct node *ptr = top;
    while(ptr!=NULL){
        if(ptr->info.rollno == rollno){
            printf("Enter the new weight: ");
            scanf("%f",&ptr->info.weight);
            break;
        }
        ptr = ptr->next;
    }
}

int main(){
    struct student s;
    int choice;
    do{
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Sort rollno\n 5. Change weight\n 6. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter rollno, weight ,height: ");
                scanf("%d %f %f",&s.rollno,&s.weight,&s.height);
                push(s);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                sort_stack();
                break;
            case 5:
                printf("Enter the rollno: ");
                scanf("%d",&s.rollno);
                revise_weight(s.rollno);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }while(choice!=6);
    return 0;
}

