#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *top, *new1, *temp;
int ele;

void push();
int pop();
void display();

void main()
{
    int ch;
    do{
    printf("1.Push\t2.Pop\t3.Display\t4.Exit\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
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
        display();
        break;
    case 4:printf("Exiting");    
    }
    }while(ch!=4);
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

void display()
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
