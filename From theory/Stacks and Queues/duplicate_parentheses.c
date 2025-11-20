#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 100

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(char i)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("\nStack overflow");
        return;
    }
    newNode->data = i;
    newNode->next=top;
    top=newNode;
    return;
}

char pop()
{
    if(!top)
    {
        printf("\nStack underflow!");
        return '\0';
    }
    Node* temp = top;
    char i=temp->data;
    top=top->next;
    free(temp);
    return i;
}

bool isDuplicate(char* s)
{
    for(int i=0;i<strlen(s);i++)
    {
        char ch = s[i];
        if(ch==')')
        {
            if(top && top->data=='(')
                return true;

            while(top && top->data!='(')
            {
                pop();
            }
            if(top)
                pop();
        }
        else
        {
            push(ch);
        }
    }
    return 0;
}
int main()
{

    int ch,dupe;
    char str[100];
    printf("\nEnter the string: ");
    scanf("%s",str);
    if(isDuplicate(str))
        printf("\n Duplicated");
    else
        printf("\n Not duplicate");
}
