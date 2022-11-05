// Write a program in C to implement binary tree using linked list with operations such as create, insertion and display.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node * create(){
    struct node *newnode = malloc(sizeof(struct node));
    int x;
    printf("\nEnter data OR -1 to exit: ");
    scanf("%d", &x);
    if(x == -1){
        return NULL;
    }
    else{
    newnode->data = x;
    }
    printf("Enter left child of %d", x);
    newnode->left = create(); 
    printf("Enter right child of %d", x);
    newnode->right = create();
    return newnode;
}

void insert(struct node *root){
    int x,y;
    printf("Enter data to insert: ");
    scanf("%d", &x);
    printf("Enter 1 to insert right or 2 to insert left: ");
    scanf(" %d", &y);
    if(y == 1){
        while(root->right != NULL){
            root = root->right;
        }
        root->right = malloc(sizeof(struct node));
        root->right->data = x;
        root->right->left = NULL;
        root->right->right = NULL;
    }
    else if(y == 2){
        while(root->left != NULL){
            root = root->left;
        }
        root->left = malloc(sizeof(struct node));
        root->left->data = x;
        root->left->left = NULL;
        root->left->right = NULL;
    }
    else{
        printf("Invalid choice");
    }
}

void display(struct node *root){
    if(root == NULL){
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int main(){
    struct node *root = malloc (sizeof(struct node));
    int ch;
    do{
        printf("\n1. Create\n2. Insert\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                root = create();
                break;
            case 2:
                insert(root);
                break;
            case 3:
                display(root);
                break;
            case 4:
                exit(0);
        }
    }while(ch != 4);
}
