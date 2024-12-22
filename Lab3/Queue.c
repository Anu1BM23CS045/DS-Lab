#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int front = -1, rear = -1, q[MAX], ele;

void enqueue();
int dequeue();
void display();

void main()
{
    int ch;
    do
    {
        printf("Queue Operations:\n1.Insert an element\t2.Delete an element\t3.Display Queue\n4.Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            ele = dequeue();
            if (ele != -1)
            {
                printf("Deleted Element:%d\n", ele);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting..");
            break;
        default:
            printf("Invalid choice");
        }

    } while (ch != 4);
}

void enqueue()
{
    if(rear==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter element:");
    scanf("%d",&ele);
    if(front==-1 && rear==-1)
    {
        front=0;
    }
    q[++rear]=ele;
}

int dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    ele=q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    return ele;
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",q[i]);
    }
    printf("\n");
}
