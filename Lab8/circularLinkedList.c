#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *start, *temp, *new1, *curr;

void createList();
void insert_beg();
void insert_end();
void insert_pos();
node *accept();
void display();

void main()
{
    int ch;
    do
    {
        printf("Circular Linked List\n1.Create\n2.Insert at the beginning\t3.Insert at end\t4.Insert at specific position\n5.Display\t6.Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createList();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_pos();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...");
            break;
        default:
            printf("Invalid Choice");
        }
    } while (ch != 6);
}

node *accept()
{
    new1 = (node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d", &new1->data);
    return new1;
}

void createList()
{
    char c;
    do
    {
        new1 = accept();
        if (start == NULL)
        {
            start = new1;
            curr = new1;
            new1->link = start;
        }
        printf("Do you want to insert another(y/n):");
        scanf(" %c", &c);
        curr->link = new1;
        curr = new1;
    } while (c == 'Y' || c == 'y');
    curr->link = start;
}

void insert_beg()
{
    new1 = accept();
    if (start == NULL)
    {
        start = new1;
        start->link = start;
        return;
    }
    temp = start;
    while (temp->link != start)
    {
        temp = temp->link;
    }
    temp->link = new1;
    new1->link = start;
    start = new1;
}

void insert_end()
{
    new1 = accept();
    if (start == NULL)
    {
        start = new1;
        start->link = start;
        return;
    }
    temp = start;
    while (temp->link != start)
    {
        temp = temp->link;
    }
    temp->link = new1;
    new1->link = start;
}

void insert_pos()
{
    new1 = accept();
    int pos;
    printf("Enter Position:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_beg();
        return;
    }

    int i = 1;
    temp = start;
    while (temp->link != start && i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    if (temp->link == start && i == pos - 1)
    {
        temp->link = new1;
        new1->link = start;
        return;
    }
    if (temp->link == start && i != pos - 1)
    {
        printf("Entered position is more than no. of nodes");
        return;
    }
    new1->link = temp->link;
    temp->link = new1;
}

void display()
{
    if (start == NULL)
    {
        printf("list is empty");
        return;
    }
    printf("List Contents:");
    temp = start;
    do
    {
        printf("%d ->", temp->data);
        temp = temp->link;
    } while (temp->link != start);
    printf("%d\n", temp->data);

}
