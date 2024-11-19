#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *top = NULL, *front = NULL, *rear = NULL, *temp, *new1;
int ele;

void push();
int pop();
void sdisplay();
void qdisplay();
void insert();
int delete();

void main()
{
    int ch, ich;
    do
    {
        printf("1.Stack Operations\t2.Queue Opertions\t3.Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            do
            {
                printf("1.Push\t2.Pop\t3.Display\t4.Exit\nEnter your choice:");
                scanf("%d", &ich);
                switch (ich)
                {
                case 1:
                    push();
                    break;
                case 2:
                    ele = pop();
                    if (ele != -1)
                        printf("Deleted element:%d\n", ele);
                    break;
                case 3:
                    sdisplay();
                    break;
                case 4:
                    printf("Exiting Stack Operation\n");
                }
            } while (ich != 4);break;
        case 2:
            do
            {
                printf("1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your choice:");
                scanf("%d", &ich);
                switch (ich)
                {
                case 1:
                    insert();
                    break;
                case 2:
                    ele = delete ();
                    if (ele != -1)
                        printf("Deleted element:%d\n", ele);
                    break;
                case 3:
                    qdisplay();
                    break;
                case 4:
                    printf("Exiting Queue Operation\n");
                }
            } while (ich != 4);break;
        case 3:
           printf("Exiting");    
        }
    } while (ch != 3);
}

void push()
{
    new1=(node *)malloc(sizeof(node));
    printf("Enter element:");
    scanf("%d",&new1->data);
    if(top==NULL)
    {
        top=new1;
        new1->link=NULL;
        return;
    }
    new1->link=top;
    top=new1;
}

int pop()
{
    if(top==NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    temp=top;
    top=top->link;
    ele= temp->data;
    free(temp);
    return ele;
}

void sdisplay()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elemeents:\n");
    temp=top;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
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

void qdisplay()
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