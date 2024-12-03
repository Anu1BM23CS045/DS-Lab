#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct Node node;

node *new1, *temp, *start, *curr;

void createDLL();
void insertleft();
void del_spec();
void printDLL();
node *accept();

void main()
{
    int ch;
    do
    {
        printf("Doubly Linked List\n1.Create\n2.Insert before a node\t3.delete specific element\n4.Display\t5.Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createDLL();
            break;
        case 2:
            insertleft();
            break;
        case 3:
            del_spec();
            break;
        case 4:
            printDLL();
            break;
        case 5:
            printf("Exiting..");
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 5);
}

node *accept()
{
    new1 = (node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d", &new1->data);
    return new1;
}

void createDLL()
{

    char c;
    do
    {
        new1 = accept();
        if (start == NULL)
        {
            start = new1;
            curr = new1;
            new1->next = NULL;
            new1->prev = NULL;
        }
        printf("Do you want to insert another(y/n):");
        scanf(" %c", &c);
        curr->next = new1;
        new1->prev = curr;
        curr = new1;
    } while (c == 'Y' || c == 'y');
    curr->next = NULL;
}

void insertleft()
{
    int ele;
    printf("Enter data value before which a node is to be inserted:");
    scanf("%d", &ele);
    new1=accept();
    if (start->data == ele)
    {
        new1->next = start;
        start->prev = new1;
        new1->prev = NULL;
        start = new1;
        return;
    }
    temp = start;
    while (temp != NULL && temp->data != ele)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found");
        return;
    }

    if (temp->data == ele)
    {
        temp->prev->next = new1;
        new1->prev = temp->prev;
        new1->next = temp;
        temp->prev = new1;
        return;
    }
}

void del_spec()
{
    int ele;
    printf("Enter data to be deleted:");
    scanf("%d", &ele);
    if (start->data == ele)
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        return;
    }
    temp = start;
    while (temp != NULL && temp->data != ele)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found");
        return;
    }
    if (temp->data == ele)
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        return;
    }
}

void printDLL()
{
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = start;
    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
