#include<stdio.h>>
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

//CLONING BINARY TREE
Node* cloneTree(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Node* newNode = createNode(root->data);

    newNode->left = cloneTree(root->left);
    newNode->right = cloneTree(root->right);

    return newNode;
}

//Calculate Height
int height(Node* root)
{
    if (root == NULL)
        return -1;  // height in terms of edges
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

//Find Depth
int findDepth(Node* root, int key, int depth)
{
    if (root == NULL)
        return -1;

    if (root->data == key)
        return depth;

    int left = findDepth(root->left, key, depth + 1);
    if (left != -1)
        return left;

    return findDepth(root->right, key, depth + 1);
}

int main()
{
    int ch,data;
    Node* root1;
    while(1)
    {
        printf("\nMENU\n1.Insert Nodes\n2.Recursive Inorder Traversal\n3.Clone Tree\nEnter choice: ");
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
            root1 = cloneTree(root);
            printf("\nCloned Tree: ");
            recursiveIn(root);
            break;
        default:
            printf("\nInvalid option!");
        }
    }
}
