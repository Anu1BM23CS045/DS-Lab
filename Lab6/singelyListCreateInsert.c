#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *new1, *curr, *temp, *start = NULL;

void create();
void display();
void insert_beg();
void insert_end();
void insert_pos();

void main()
{
    int ch;
    do
    {
        printf("1.Create\t2.Display\n3.Insert in beginning\t4.Insert at end\n5.Insert at specific position\t6.Exit\nEnter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:insert_beg();break;
        case 4:insert_end();break;    
        case 5:insert_pos();break;    
        case 6:
            printf("Exiting...");
        }
    } while (ch != 6);
}

void create()
{
    char c;
    do
    {

        new1 = (node *)malloc(sizeof(node));
        printf("Enter data:");
        scanf("%d", &new1->data);
        if (start == NULL)
        {
            start = new1;
            curr = new1;
        }
        curr->link = new1;
        curr = new1;
        

        printf("Do you want to insert one more (Y/N):");
        scanf(" %c",&c);

    } while (c=='Y' || c=='y');
    curr->link=NULL;
}

void display()
{
    if(start==NULL)
    {
        printf("List is Empty");
        return;
    }
    printf("Linked List:");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}

void insert_beg()
{
    new1=(node *)malloc(sizeof(node));
    printf("Enter element:");
    scanf("%d",&new1->data);
    if(start==NULL)
    {
        start=new1;
        new1->link=NULL;
    }
    new1->link=start;
    start=new1;
}

void insert_end()
{
    new1=(node *)malloc(sizeof(node));
    printf("Enter element:");
    scanf("%d",&new1->data);
    if(start==NULL)
    {
        start=new1;
        new1->link=NULL;
    }
    temp=start;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new1;
    new1->link=NULL;
}

void insert_pos()
{
    int pos;
    new1=(node *)malloc(sizeof(node));
    printf("Enter element:");
    scanf("%d",&new1->data);
    printf("Enter postion to be inserted:");
    scanf("%d",&pos);
    if(pos==1)
    {
        new1->link=start;
        start=new1;
        return;
    }
    int i=1;
    temp=start;
    while(temp!=NULL && i<pos-1)
    {
        temp=temp->link;
    }
    if(temp==NULL)
    {
        printf("Entered position is greater than the number of nodes.");
        return;
    }
    new1->link=temp->link;
    temp->link=new1;
}
