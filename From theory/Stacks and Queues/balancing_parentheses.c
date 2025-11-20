#include<stdio.h>
#include<stdlib.h>
#define Max 100

typedef struct stack
{
    char arr[Max];
    int top;
}Stack;

void push(Stack* stack , char ch)
{
    if(stack->top==Max-1)
    {
        printf("Stack Overflow!!!\n");
        return;
    }
    stack->arr[++stack->top]=ch;
    return;
}

char pop(Stack* stack)
{
    if(stack->top==-1)
    {
        printf("Stack Empty!!!\n");
        return '/0';
    }
    return stack->arr[stack->top--];
}

int isMatching(char open,char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *expr)
{
    Stack stack;
    stack.top=-1;

    for(int i=0; expr[i]!='\0'; i++)
    {
        char ch = expr[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(&stack,expr[i]);
        }
        else if(ch==')' || ch==']' || ch=='}')
        {
            char topChar=pop(&stack);
            if(!isMatching(topChar,ch))
            {
                return 0;
            }
        }
    }
    return (stack.top==-1);
}

int main()
{
    char expr[Max];
    printf("Enter the statement:\n");
    scanf("%s",expr);

    if(isBalanced(expr)){
        printf("Balanced Expression\n");
    }else
    {
        printf("Not Balanced\n");
    }
    return 0;
}
