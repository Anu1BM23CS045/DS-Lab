#include<stdio.h>
#include<string.h>
#include<conio.h>

int top=-1,indx=0,pos=0,length;
char symbol,temp,infix[20],postfix[20],stack[20];

void infixtopostfix();
void push(char symbol);
char pop();
int pred(char symbol);

void main()
{
    
    printf("Enter the infix expression:");
    scanf("%s",infix);

    infixtopostfix();

    printf("Infix expression: %s \n",infix);
    printf("Postfix expression: %s",postfix);
    getch();
}
 void infixtopostfix()
 {
    length=strlen(infix);
    push('#');
    while(indx<length)
    {
        symbol=infix[indx];
        switch(symbol)
        {
            case'(':push(symbol);
                    break;

            case')':temp=pop();
                    while(temp!='(')
                    {
                        postfix[pos]=temp;
                        pos++;
                        temp=pop();
                    }break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'^':while(pred(stack[top])>=pred(symbol))
                    {
                        temp=pop();
                        postfix[pos++]=temp;
                    }
                    push(symbol);
                    break;
            default: postfix[pos++]=symbol;

        }
        indx++;
    }
    while(top>0)
    {
        temp=pop();
        postfix[pos++]=temp;
    }
 }
 

 void push(char symbol)
 {
    top=top+1;
    stack[top]=symbol;
 }

 char pop()
{
    char symb;
    symb=stack[top];
    top=top-1;
    return symb;
}

int pred(char symbol)
{
    int p;
    switch(symbol)
    {
      case'^':p=3;break;
      case'*':
      case'/':p=2;break;
      case'+':
      case'-':p=1;break;
      case'(':p=0;break;
      case'#':p=-1;break;        
    }
    return p;
}
