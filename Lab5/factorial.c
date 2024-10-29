#include<stdio.h>
int fact(int n)
{
    if(n==1)
        return 1;
    else
    return(n*fact(n-1));
}

void main()
{
    int n;
    printf("enter no.:");
    scanf("%d",&n);
    printf("Factorial of %d is %d",n,fact(n));
}
