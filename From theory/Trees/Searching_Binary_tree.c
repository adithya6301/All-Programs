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

//Inorder: Left -> Root -> Right
Node* searchInorder(Node* root, int key, int* steps)
{
    if (root == NULL)
        return NULL;

    Node* found = searchInorder(root->left, key, steps);
    if (found)
        return found;

    (*steps)++;
    if (root->data == key)
        return root;

    return searchInorder(root->right, key,steps);
}

int main()
{
    int ch,data;
    while(1)
    {
        printf("\nMENU\n1.Insert Nodes\n2.Recursive Inorder Traversal\n3.Search element\nEnter choice: ");
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
            printf("\nEnter elt to search: ");
            scanf("%d",&data);
            int steps = 0;
            Node* found = searchInorder(root, data,&steps);
            if (found)
                printf("\nElement %d found after %d steps.\n", data, steps);
            else
                printf("\nElement %d not found after %d steps.\n", data, steps);
            break;
        default:
            printf("\nInvalid option!");
        }
    }
}

