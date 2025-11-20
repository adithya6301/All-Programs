#include<stdio.h>
#define Max 50
char stack[Max];
int top=-1;

void push(char ch)
{
    stack[++top]=ch;
    return;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

//check precedence
int precedence(char op)
{
    if(op=='^')
        return 3;
    else if(op=='*' || op=='/')
        return 2;
    else if(op=='+' || op=='-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[],char postfix[])
{
    int i,k=0;
    char ch;
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
            postfix[k++]=ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')')
        {
            while(top!=-1 && peek()!='(')
            {
                postfix[k++]=pop();
            }
            pop();
        }
        else//operator
        {
            while(top!=-1 && precedence(peek())>=precedence(ch))
            {
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1)
        postfix[k++]=pop();
    postfix[k]='\0';
}
int main()
{
    char infix[Max],postfix[50];
    printf("Enter the infix expression:\n");
    scanf("%s",&infix);
    infixToPostfix(infix,postfix);
    printf("Postfix expression: %s",postfix);
    return 0;
}
