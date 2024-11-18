#include<stdio.h>
#define size 3

int cq[size],front=-1,rear=-1,ele;

void insert(int item)
{
    if(front==(rear+1)% size)
    {
        printf("Queue is full");
        return;
    }
    if(front==-1 && rear==-1){
        front=0;rear=0;
    }
    else
     rear=(rear+1)%size;

    cq[rear]=item;
    printf("Inserted:%d\n",item);
}

int delete()
{
    if(front==-1 && rear==-1){
        printf("Queue is empty");
        return -1;
    }
    ele=cq[front];
    if(front==rear){
        front=-1;rear=-1;
    }
    else
     front=(front+1)%size;
    return ele;
}

void display()
{
    if(front==-1 && rear==-1){
        printf("Queue is empty");
        return;
    }
    printf("Queue Contents:");
    if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
            printf("%d\t",cq[i]);
        printf("\n");
    }
    else{
        for(int i=front;i<size;i++)
            printf("%d\t",cq[i]);
        for(int i=0;i<=rear;i++)
            printf("%d\t",cq[i]);
        printf("\n");
    }
}

void main()
{
    int ch;
    do
    {
        printf("Circular Queue Menu:\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter you choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter value:");
                    scanf("%d",&ele);
                    insert(ele);
                    break;
            case 2:ele=delete();
                    if(ele!=-1)
                        printf("Deleted element:%d\n",ele);
                    break;
            case 3:display();break;
            case 4:printf("Exiting....");break;
            default:printf("Invalid Choice\n");        
        }     
    }while(ch!=4);
}
