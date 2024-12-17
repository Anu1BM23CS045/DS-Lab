#include<stdio.h>
#include<stdlib.h>
#define MAX 25

int a[10][10],vis[MAX],q[MAX],i,j,n,v,front=-1,rear=-1;

void bsf(int);
void insert(int);
int delete();

void main()
{
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    }
    for(i=1;i<=n;i++)
    vis[i]=0;
    printf("Traversal:");
    bsf(1);

}

void bsf(int v)
{
    insert(v);

    vis[v]=1;
    while(front!=-1 && rear!=-1)
    {
        v=delete();
        printf("%d \t",v);
        for(i=1;i<=n;i++)
        {
          if(a[v][i]==1 && vis[i]==0)
          {
            insert(i);
            vis[i]=1;
          }
        }
    }
}

void insert(int v)
{
    if(rear==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    if(front==-1 && rear==-1)
    {
        front=0;
    }
    q[++rear]=v;
}

int delete()
{
    v=q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
    return v;
}
