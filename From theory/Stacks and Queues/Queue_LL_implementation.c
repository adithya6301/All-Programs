#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* front = NULL , *rear = NULL;

int isEmpty()
{
    return(front==NULL);
}

void enqueue(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("\nMemory allocation failed");
        return;
    }
    newNode->data=data;
    newNode->next=NULL;

    if(rear==NULL)
    {
        front = rear = newNode;
        return;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d successfully added to the queue.",data);
}

void dequeue()
{
    if(isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }
    Node* temp = front;
    printf("\n%d has been successfully removed",temp->data);
    front= front->next;
    if(front==NULL)
    {
        rear==NULL;
    }
    free(temp);
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }
    Node* temp = front;
    printf("\nQueue Elements:");
    while(temp!= NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
}

int main()
{
    return 0;
}
