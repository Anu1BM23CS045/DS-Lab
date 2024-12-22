#include<stdio.h>
#include<stdlib.h>

int n,a[10][10],vis[25];

void dsf(int);

void main()
{
    int i,j,count=0;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    vis[i]=0;
    }
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("Traversal from vertex 1:\n");
    dsf(1);
    for(i=1;i<=n;i++)
    {
        if(vis[i]==1)
         count++;
    }
    if(count==n)
         printf("\n The graph is Connected ");
    else
        printf("\n The graph is not Connected ");     

    
}

void dsf(int v)
{   
    int i;
    vis[v]=1;
    for(i=1;i<=n;i++)
        if(a[v][i]==1 && vis[i]==0)
        {
          printf("%d->%d\n",v,i); 
          dsf(i);      
        }
        
}

