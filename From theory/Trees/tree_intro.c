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

//RECURSIVE POSTORDER
void recursivePost(Node* root)
{
    if(root!=NULL){
        recursivePost(root->left);
        recursivePost(root->right);
        printf("%d ",root->data);
    }
}

//ITERATIVE POSTORDER
void iterativePost(Node* root)
{
    if(root==NULL){
        printf("\nEmpty");
        return;
    }
    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1,top2 = -1;

    stack1[++top1] = root;
    while(top1!=-1)
    {
        Node* node = stack1[top1--];
        stack2[++top2] = node;
        if(node->left)
            stack1[++top1] = node->left;
        if(node->right)
            stack1[++top1] = node->right;
    }

    while(top2!= -1)
    {
        printf("%d ",stack2[top2--]->data);
    }
}

//RECURSIVE PREORDER
void recursivePre(Node* root)
{
    if(root!=NULL){
        printf("%d ",root->data);
        recursivePre(root->left);
        recursivePre(root->right);
    }
}

//ITERATIVE PREORDER
void iterativePre(Node* root)
{
    if(root==NULL){
        printf("\nEmpty!");
        return;
    }
    Node* stack[100];
    int top = -1;
    stack[++top]=root;
    while(top!=-1)
    {
        Node* node = stack[top--];
        printf("%d ",node->data);

        if(node->right)
            stack[++top]=node->right;
        if(node->left)
            stack[++top]=node->left;
    }
}

int main()
{
    int ch,data;
    while(1)
    {
        printf("\nMENU\n1.Insert Nodes\n2.Recursive Inorder Traversal\n3.Iterative Inorder Traversal\n4.Recursive Postorder\n5.Iterative postorder\n6.Recursive Preorder\n7.Iterative Preorder\nEnter choice: ");
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
        case 4:
            printf("\nRecursive Postorder Traversal : ");
            recursivePost(root);
            break;
        case 5:
            printf("\nIterative Postorder Traversal : ");
            iterativePost(root);
            break;
        case 6:
            printf("\nRecursive Preorder Traversal : ");
            recursivePre(root);
            break;
        case 7:
            printf("\nIterative Preorder Traversal : ");
            iterativePre(root);
            break;
        default:
            printf("\nInvalid option! Try again! ");
        }
    }
    return 0;
}
