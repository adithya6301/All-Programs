#include<stdio.h>
#include<stdlib.h>

//DLL
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

//global head
Node *head = NULL;

Node* create_Node(int data);
void insertion_beginning(Node **head, int data);
void insertion_end(Node **head, int data);
void insertion_after(Node **head, int aft_data, int new_data);
void delete_beginning(Node **head);
void delete_last(Node **head);
void display(Node *head);

int main()
{
    int ch,data,prev_data;
    while(1)
    {
        printf("\nMenu\n1.Insertion at Beginning\n2.Insertion at end\n3.Insertion after\n4.Delete beginning\n5.Delete Last\n6.Display\n7.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter Data to insert:");
            scanf("%d",&data);
            insertion_beginning(&head,data);
            break;


        case 2:
            printf("\nEnter Data to insert:");
            scanf("%d",&data);
            insertion_end(&head,data);
            break;

        case 3:
            printf("\nEnter the data after which to insert:");
            scanf("%d",&prev_data);
            printf("\nEnter Data to insert:");
            scanf("%d",&data);
            insertion_after(&head,prev_data,data);
            break;

        case 4:
            delete_beginning(&head);
            printf("\nDeleted Successfully");
            break;
        case 5:
            delete_last(&head);
            printf("\nDeleted Successfully");
            break;
        case 6:
            printf("\n");
            display(head);
            break;
        case 7:
            exit(1);
        default:
            printf("\nInvalid Option!!!\n");
        }
    }
    return 0;
}

Node* create_Node(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertion_beginning(Node **head,int data)
{
    Node* newNode=create_Node(data);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    newNode->prev=NULL;
    newNode->next=*head;
    (newNode->next)->prev=newNode;
    *head=newNode;
    return;
}

void insertion_end(Node **head,int data)
{
    Node* newNode= create_Node(data);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }

    Node* temp = *head;
    while((temp->next)!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return;
}

void insertion_after(Node **head,int aft_data,int new_data)
{
    Node* newNode= create_Node(new_data);
    if((*head)==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    int flag=0;
    Node* temp = *head;
    while(temp!=NULL)
    {
        if(temp->data==aft_data)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\nThe given value %d is not in the list.",aft_data);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return;
}

void delete_beginning(Node **head)
{
    if((*head)==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;

    if((*head)->next!=NULL) //if multiple nodes are there
    {
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(temp);
        return;
    }
    *head=NULL;//if only one node is present
    free(temp);
    return;
}

void delete_last(Node **head)
{
    if(*head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = *head;
    if((*head)->next==NULL)
    {
        free(temp);
        *head=NULL;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    (temp->prev)->next=NULL;
    free(temp);
    return;
}

void display(Node *head)
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    printf("\nLinked List:");
    Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    return;
}
