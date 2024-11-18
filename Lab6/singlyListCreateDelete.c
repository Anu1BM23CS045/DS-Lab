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
void del_beg();
void del_end();
void del_ele();

void main()
{
    int ch;
    do
    {
        printf("1.Create\t2.Display\n3.Delete in beginning\t4.Delete at end\n5.Delete at specific element\t6.Exit\nEnter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:del_beg();break;
        case 4:del_end();break;    
        case 5:del_ele();break;    
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

void del_beg()
{
    if(start==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp=start;
    start=start->link;
    printf("Deleted Element :%d\n",temp->data);
    free(temp);
}

void del_end()
{
    if(start==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if(start->link==NULL)
    {
        free(start);
        start=NULL;
        return;
    }
    node *prev,*next;
    next=start;
    prev=NULL;

    while(next->link!=NULL)
    {
        prev=next;
        next=next->link;
    }
    prev->link=NULL;
    printf("Deleted Element :%d\n",next->data);
    free(next);
}

void del_ele()
{
   if(start==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    int ele;
    printf("Enter element:");
    scanf("%d",&ele);
    if(start->data==ele)
    {
        temp=start;
        start=start->link;
        free(temp);
    }
    node *prev,*next;
    next=start;
    prev=NULL;
    while(next!=NULL && next->data!=ele)
    {
        prev=next;
        next=next->link;
    }
    if(next==NULL)
    {
        printf("Element not found\n");
        return;
    }
    prev->link=next->link;
    printf("Deleted Element :%d\n",next->data);
    free(next);
}
