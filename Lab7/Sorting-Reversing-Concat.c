#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *start1 = NULL, *start2 = NULL, *start = NULL, *new1, *temp;

node *createnode(int x);
void insertend(node **start, int x);
node *concatenate(node *start1, node *start2);
node *rev(node *start);
void sort(node *start);
void display(node *start);

void main()
{
    start1 = createnode(12);
    insertend(&start1, 98);
    insertend(&start1, 8);
    insertend(&start1, 54);
    insertend(&start1, 72);
    insertend(&start1, 6);

    start2 = createnode(34);
    insertend(&start2, 10);
    insertend(&start2, 4);
    insertend(&start2, 88);

    int ch, list;
    int choicelist()
    {
        printf("List1/List2:");
        scanf("%d", &list);
        return list;
    }

    do
    {
        printf("1.Display\t2.Reverse List\t3.Sort list\t4.Concatenate 2 Lists\t5.Exit\nEnter you choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (choicelist() == 1)
                display(start1);
            else
                display(start2);
            break;
        case 2:
            if (choicelist() == 1)
            {
                start1 = rev(start1);
                display(start1);
            }
            else
            {
                start2 = rev(start2);
                display(start2);
            }
            break;
        case 3:
            if (choicelist() == 1)
            {
                sort(start1);
                display(start1);
            }
            else
            {
                sort(start2);
                display(start2);
            }
            break;
        case 4:
            start = concatenate(start1, start2);
            printf("Concatenated ");
            display(start);
            break;
        case 5:
            printf("Exiting");
            break;
        }
    } while (ch != 5);
}

node *createnode(int x)
{
    new1 = (node *)malloc(sizeof(node));
    new1->data = x;
    new1->link = NULL;
    return new1;
}

void insertend(node **start, int x)
{
    new1 = createnode(x);
    if (*start == NULL)
    {
        *start = new1;
    }
    temp = *start;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new1;
}

node *concatenate(node *start1, node *start2)
{
    if (start1 == NULL && start2 == NULL)
    {
        printf("Lists are Empty\n");
        return NULL;
    }
    if (start1 == NULL)
    {
        return start2;
    }
    temp = start1;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = start2;
    return start1;
}

void display(node *start)
{
    if (start == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp = start;
    printf("List Contents:");
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

node *rev(node *start)
{
    node *a, *b, *c;
    a = start;
    b = NULL;
    c = NULL;
    while (a != NULL)
    {
        c = b;
        b = a;
        a = a->link;
        b->link = c;
    }
    start = b;
    return start;
}

void sort(node *start)
{
    int t;
    node *i = start, *j = NULL;
    while (i != NULL)
    {
        j = i->link;
        while (j != NULL)
        {
            if (i->data > j->data)
            {
                t = j->data;
                j->data = i->data;
                i->data = t;
            }
            j = j->link;
        }
        i = i->link;
    }
}
