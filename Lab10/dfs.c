#include<stdio.h>
#include<stdlib.h>

int a[10][10],vis[25],i,j,n,v,flag=1;

void dsf(int);

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
    printf("Traversal from 1:");
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dsf(i);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            printf("\nThe Graph is disconnected");
            return;
        }
    }
    printf("\nThe graph is connected");

}

void dsf(int v)
{
    printf("%d->",v);
    vis[v]=1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i]==1 && vis[i]==0)
            dsf(i);
    }
}

