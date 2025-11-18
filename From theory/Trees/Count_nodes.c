// Counting number of nodes and leaf nodes in a binary tree
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* root = NULL;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("\nMemory allocation failed");
        exit(1);
    }
    newNode->data=data;
    newNode->left =NULL;
    newNode->right =NULL;
    return newNode;
}

Node* createTree()
{
    int data;
    printf("\nEnter data (-1 for no Node): ");
    scanf("%d",&data);

    if(data==-1)
    {
        return NULL;
    }
    Node* node = createNode(data);

    printf("\nEnter data for left child of %d",data);
    node->left = createTree();
    printf("\nEnter data for right child of %d",data);
    node->right = createTree();

    return node;
}

void insertBT(int data)
{
    Node* newNode = createNode(data);

    if(!root){
        root = newNode;
        return;
    }

    Node* Queue[100];
    int rear = 0 ,front = 0;

    Queue[rear++] = root;
    while(front<rear)
    {
        Node* current = Queue[front++];

        if(current->left==NULL)
        {
            current->left=newNode;
            printf("\n%d is inserted as left child of %d",data,current->data);
            return;
        }
        else if(current->right==NULL)
        {
            current->right=newNode;
            printf("\n%d is inserted as right child of %d",data,current->data);
            return;
        }

        Queue[rear++]=current->left;
        Queue[rear++]=current->right;
    }
}

void inOrder(Node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void inorderCount(Node* root, int* count)
{
    if (root != NULL)
    {
        inorderCount(root->left, count);

        (*count)++;      // Node visited
        printf("%d ", root->data);

        inorderCount(root->right, count);
    }
}

int countLeafNodes(Node* root)
{
    if (root == NULL)
        return 0;

    // If this node is a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Otherwise count in left + right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}



int main()
{
    int ch,data;
    int lCount =0 ,count =0;
    while(1)
    {
        printf("\nMENU\n1.Create BT\n2.Insert node to BT\n3.Display\n4.Node count\n5.Leaf Node count\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nBINARY TREE CREATION\n");
            root = createTree();
            break;
        case 2:
            printf("\nNode Insertion\n");
            printf("Enter data: ");
            scanf("%d",&data);
            insertBT(data);
            break;

        case 3:
            printf("\nBinary Tree");
            inOrder(root);
            break;
        case 4:
            inorderCount(root,&count);
            printf("\nNode count: %d",count);
            break;
        case 5:
            lCount = countLeafNodes(root);
            printf("\nLeaf Node count: %d",lCount);
            break;
        default:
            printf("\nInvalid option!");
        }
    }
}
