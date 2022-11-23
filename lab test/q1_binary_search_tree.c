// write a program to create a binary search tree and find the depth of a given node in the tree.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        struct node *temp = root;
        while (1)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = new_node;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new_node;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void display(struct node *temp)
{
    if (temp != NULL)
    {
        display(temp->left);
        printf("%d ", temp->data);
        display(temp->right);
    }
}

int depth(struct node *temp, int data)
{
    if (temp == NULL)
    {
        return -1;
    }
    else
    {
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return count;
            }
            else
            {
                count++;
                if (data < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

int main()
{
    int ch, x, count;
    do
    {
        printf("\n1. Insert\n2. Display\n3. Depth\n4. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            display(root);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &x);
            count = depth(root, x);
            if (count == -1)
            {
                printf("Data not found");
            }
            else
            {
                printf("Depth of %d is %d", x, count);
            }
            break;
        case 4:
            exit(0);
        }
    } while (ch!=4);
}