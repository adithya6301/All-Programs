#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *head=NULL;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("\nMemory allocation failed!");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return;
}

void insertBefore()
{
    
}