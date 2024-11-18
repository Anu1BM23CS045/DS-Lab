#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *front=NULL,*rear=NULL, *new1, *temp;
int ele;

void insert();
int delete();
void display();

void main()
{
    int ch;
    do{
    printf("1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
         insert();
        break;
    case 2:
        ele = delete();
        if (ele != -1)
            printf("Deleted element:%d\n", ele);
        break;
    case 3:
        display();
        break;
    case 4:printf("Exiting");    
    }
    }while(ch!=4);
}

void insert()
{
    new1=(node *)malloc(sizeof(node));
    printf("Enter element");
    scanf("%d",&new1->data);
   if(front==NULL && rear==NULL)
   {
    front=rear=new1;
    rear->link=NULL;
    return;
   }
   rear->link=new1;
   rear=new1;
   rear->link=NULL;
}

int delete()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    temp=front;
    if(front==rear)
    {
       front=NULL;
       rear=NULL;
    }
    front=front->link;
    ele=temp->data;
    free(temp);
    return ele;
    
}

void display()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Contents:");
    temp=front;
    while(temp!=rear->link)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}