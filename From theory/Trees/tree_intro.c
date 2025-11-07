#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

//DEFINING ROOT
Node* root = NULL;

//CREATING NODE
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("\nMemory allocation failed!");
        exit(1);
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//INSERTION


void insertNode(int data)
{
    Node* newNode = createNode(data);
    if(root==NULL){
        root = newNode;
        return;
    }

    Node* curr = root;
    Node* parent=NULL;
    while(curr!=NULL)
    {
        parent=curr;
        if(data<curr->data)
        {
            curr= curr->left;
        }
        else if(data>curr->data)
        {
            curr=curr->right;
        }
        else
        {
            printf("\n %d already exists in the tree hence cannot insert.",data);
            free(newNode);
            return;
        }
    }
    if(data<parent->data)
    {
        parent->left=newNode;
    }
    else
    {
        parent->right=newNode;
    }
    return NULL;

}

//RECURSIVE INORDER
void recursiveIn(Node* root)
{
    if(root!=NULL)
    {
        recursiveIn(root->left);
        printf("%d ",root->data);
        recursiveIn(root->right);
    }
}

//ITERATIVE INORDER
void iterativeIn(Node* root)
{
    Node* current = root;
    Node* stack[100];
    int top=-1;
    while(current!=NULL || top!=-1)
    {
        while(current!= NULL)
        {
            stack[++top]=current;
            current=current->left;
        }
        current=stack[top--];
        printf("%d ",current->data);
        current=current->right;
    }
}

int main()
{
    int ch,data;
    while(1)
    {
        printf("\nMENU\n1.Insert Nodes\n2.Recursive Inorder Traversal\n3.Iterative Inorder Traversal\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            insertNode(data);
            break;
        case 2:
            printf("\nRecursive Inorder Traversal : ");
            recursiveIn(root);
            break;
        case 3:
            printf("\nIterative Inorder Traversal : ");
            iterativeIn(root);
            break;
        default:
            printf("\nInvalid option! Try again! ");
        }
    }
    return 0;
}
