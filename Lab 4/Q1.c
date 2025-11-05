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
    return newNode;
}

void display()
{
    if(!head)
    {
        printf("\nEmpty List!");
        return;
    }
    Node* temp = head;
    printf("\nList elements: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    return;
}

void append(int data)
{
    Node* newNode = createNode(data);
    if(!head)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return;
}

void deleteNode(int elt){
    if(!head)
    {
        printf("\nEmpty List!");
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    if(head->data == elt)
    {
        head = head->next;
        free(temp);
        printf("\nDeleted %d", elt);
        return;
    }
    while(temp->next!=NULL && temp->data!=elt){
        prev=temp;
        temp=temp->next;
    }
    if(temp->data==elt){
        prev->next = temp->next;
        free(temp);
        printf("\nDeleted %d",elt);
        return;
    }
    else{
        printf("\n%d not found in the list",elt);
        return;
    }
}

void reverseList()
{
    if(!head){
        printf("\nList empty");
        return;
    }
    Node *prev=NULL,*curr=head,*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev;
    return;
}

void bubbleSort()
{
    if(!head){
        printf("\nList empty");
        return;
    }
    int swapped;
    Node* ptr;
    do
    {
        swapped=0;
        ptr=head;
        while(ptr->next !=NULL)
        {
            if(ptr->data>ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data=temp;
                swapped=1;
            }
            ptr=ptr->next;
        }
    }while(swapped);

}

void deleteAlternate()
{
    if(!head)
    {
        printf("\nList empty!");
        return;
    }
    Node *curr = head;
    Node *temp;

    while (curr != NULL && curr->next != NULL)
    {
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
        curr = curr->next;
    }
    printf("\nDeleted every alternate node (starting from 2nd)!");
}


void insertBefore(int data,int elt)
{
    if(!head)
    {
        printf("\nList is empty");
        return;
    }
    Node* newNode = createNode(data);
    if(head->data == elt)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    Node* prev=NULL;
    while(temp!=NULL && temp->data!=elt)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp == NULL)
    {
        printf("\nElement %d not found", elt);
        free(newNode);
        return;
    }
    prev->next = newNode;
    newNode->next = temp;
    return;
}

void insertSorted(int data)
{
    Node *newNode = createNode(data);

    // Case 1: Empty list OR insert before the head
    if (head == NULL || data < head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Traverse to find correct position
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < data)
    {
        curr = curr->next;
    }

    // Insert after curr
    newNode->next = curr->next;
    curr->next = newNode;
}


int main()
{
    int data,ch,elt;
    while(1)
    {
        printf("\nMenu\n1.append\n2.Insert before\n3.Delete Node\n4.Display\n5.Reverse List\n6.Sort List\n7.Delete Alt\n8.Enter into sorted list\n9.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            append(data);
            display();
            break;

            case 2:
            printf("\nEnter data: ");
            scanf("%d",&data);
            printf("\nEnter the element before which to insert: ");
            scanf("%d",&elt);
            insertBefore(data,elt);
            display();
            break;

            case 3:
            printf("\nEnter the element to delete: ");
            scanf("%d",&elt);
            deleteNode(elt);
            display();
            break;

            case 4:
            display();
            break;

            case 5:
            reverseList();
            display();
            break;

            case 6:
            bubbleSort();
            display();
            break;

            case 7:
            deleteAlternate();
            display();
            break;

            case 8:
            printf("\nEnter data: ");
            scanf("%d",&data);
            insertSorted(data);
            display();
            break;

            case 9:
            exit(1);

            default:
            printf("\nEnter valid option");
        }

    }
}
