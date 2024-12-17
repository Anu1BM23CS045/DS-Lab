#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    char data;
    struct Node *right;
};

typedef struct Node node;

node *root = NULL, *new1, *curr, *temp;

void create();
node *accept();
void inorder(node *temp);
void preorder(node *temp);
void postorder(node *temp);
void display();

void main()
{
    int ch;
    do
    {
        printf("\nBinary Search Tree\n1.Create\n2.Preorder\t3.Inorder\n4.Postorder\t5.Display\t6.Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting..");
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 6);
}

node *accept()
{
    new1 = (node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf(" %c", &new1->data);
    return new1;
}

void create()
{
    char c;
    int item;
    node *ptr;
    new1 = accept();
    root = new1;
    new1->left = NULL;
    new1->right = NULL;
    curr = new1;
    while (1)
    {
        printf("Do you want to insert another(y/n):");
        scanf(" %c", &c);
        if (c == 'Y' || c == 'y')
        {
            new1 = accept();
            new1->left = NULL;
            new1->right = NULL;
            item = new1->data;
            curr = root;
            while (curr != NULL)
            {
                ptr = curr;
                curr = (item > curr->data) ? curr->right : curr->left;
            }
            if (item < ptr->data)
            {
                ptr->left = new1;
            }
            else
            {
                ptr->right = new1;
            }
        }
        else
        {
            return;
        }
    }
}

void preorder(node *temp)
{
    if (temp != NULL)
    {
        printf("%c \t", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(node *temp)
{
    if (temp != NULL)
    {

        inorder(temp->left);
        printf("%c \t", temp->data);
        inorder(temp->right);
    }
}

void postorder(node *temp)
{
    if (temp != NULL)
    {

        postorder(temp->left);
        postorder(temp->right);
        printf("%c\t", temp->data);
    }
}

void display()
{
    printf("hehe");
}
