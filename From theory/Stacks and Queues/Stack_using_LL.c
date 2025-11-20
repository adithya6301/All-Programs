#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->data=data;
    return newNode;
}
void push(int data)
{
    Node* newNode= createNode(data);
    if(!newNode)
    {
        printf("Stack Overflow!!!\n");
        exit(0);
        return;
    }
    newNode->next = top;
    top = newNode;
    printf("%d pushed successfully\n",data);
    return;
}

void pop()
{
    if(!top)
    {
        printf("Stack Underflow!!!\n");
        return;
    }
    Node* temp = top;
    top=temp->next;
    free(temp);
    printf("Pop Successful\n");
    return;
}

void peek()
{
    if(!top)
    {
        printf("Stack Empty!!!\n");
        return;
    }
    printf("TOP element: %d\n",top->data);
    return;
}

void display()
{
    if(!top)
    {
        printf("Stack Empty!!!\n");
        return;
    }
    Node* temp = top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    return;
}

int main()
{
    int ch,data;
    while(1)
    {
        printf("---MENU---\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter element to push: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Option\nPlease try again!\n");
        }
    }
    return 0;
}
