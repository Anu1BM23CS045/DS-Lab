#include<stdio.h>
#define MAX 3

int top=-1,stack[MAX],ele,i;

void push(int item)
{
    if(top==MAX-1)
    {
        printf("Stack is full,couldn't insert %d\n",item);
        return;
    }
    stack[++top]=item;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    ele=stack[top];
    top--;
    return ele;
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack Contents:");
    for(i=top;i>=0;i--)
     printf("%d\t",stack[i]);
}

void main()
{
    int ch;
    do
    {
        printf("Stack Operation Menu:\n");
        printf("1.Push\n2.Pop\n3.Display4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter value to insert:");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2:ele=pop();
                  if(ele!=-1)
                  {
                    printf("Deleted %d",ele);
                  }break;
            case 3:display();break;
            case 4:printf("Exiting...");break;
            default:printf("Invalid choice");              
        }
    } while (ch!=4);
    
}
