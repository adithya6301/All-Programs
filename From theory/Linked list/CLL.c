#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(int data);
int main()
{
    int ch,data;
    printf("Menu\n1.Insert Front\n")
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            printf("Enter data:\n");
            scanf("%d",&data);
            insertFront(data);
            break;
    }
}

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->data=data;
    return newNode;
}

void insertFront(int data)
{
    Node* newNode= createNode(data);
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
        return;
    }

    Node* temp= head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newNode->next=head;
    temp->next=newNode;
    head=newNode;
    return;
}

void insertEnd(int data)
{
    Node* newNode=createNode(data);

    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
        return;
    }
    Node* temp = head;
    newNode->next=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return;
}

void insertAtPos(int data,int pos)
{
    if(pos==1 || head==NULL)
    {
        insertFront(data);
        return;
    }
    Node* newNode=createNode(data);
    Node* temp = head;
    for(int i=1;i<pos-1 && temp->next!=head ;i++)
    {
        temp=temp->next;
    }
    newNode->next = temp->next;
    temp->next=newNode;
}
