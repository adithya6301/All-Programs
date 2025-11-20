#include<stdio.h>
#include<stdlib.h>
#define Max 100

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n)
    {
        printf("\nMemory allocation failed!!");
        exit(1);
    }
    n->data=data;
    n->left = NULL;
    n->right=NULL;
    return n;
}
//--------------------------------------INSERTION---------------------------
Node* insertRec(Node* root , int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }

    if(data<root->data)
    {
        root->left = insertRec(root->left,data);
    }
    else if(data>root->data)
    {
        root->right = insertRec(root->right,data);
    }
    else
    {
        printf("\nDuplicate data %d not inserted.",data);
    }
    return root;
}

void insertIter(Node** root,int data)
{
    Node* temp = createNode(data);

    if(*root==NULL)
    {
        *root = temp;
        return;
    }

    Node* curr = *root;
    Node* parent = NULL;

    while(curr != NULL)
    {
        parent = curr;
        if(data<curr->data)
        {
            curr=curr->left;
        }
        else if(data>curr->data)
        {
            curr=curr->right;
        }
        else
        {
            printf("\nDuplicate %d was not inserted.",data);
            free(temp);
            return;
        }
    }
    if(data<parent->data)
    {
        parent->left = temp;
    }
    else
    {
        parent->right= temp;
    }
}

//----------------------------------------SEARCHING----------------------------------------
int iterSearch(Node* root,int key)
{
    while(root!=NULL)
    {
        if(key == root->data)
        {
            return 1;
        }
        else if(key>root->data)
        {
            root= root->right;
        }
        else{
            root=root->left;
        }
    }
    return 0;
}

Node* recSearch(Node* root, int key)
{
    if(root==NULL || root->data ==key)
    {
        return root;
    }
    if(key < root->data)
        return recSearch(root->left,key);

    return recSearch(root->right,key);
}

//--------------------------------------Find Min/Max----------------------------
Node* minSearch(Node* root)
{
    if (root == NULL)
    {
        printf("Tree is empty!\n");
        return NULL;
    }
    Node* temp = root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

Node* maxSearch(Node* root)
{
    if (root == NULL)
    {
        printf("Tree is empty!\n");
        return NULL;
    }
    Node* temp = root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}

//----------------------------------------Deletion----------------------------------
Node* deleteRec(Node* root , int key)
{
    if(!root){
        return NULL;
    }
    if(key<root->data)
    {
        root->left = deleteRec(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = deleteRec(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node* temp = minSearch(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right,temp->data);
        }
    }
    return root;
}

//----------------------------------------Height  of tree-----------------
int findHeight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left = findHeight(root->left);
    int right = findHeight(root->right);
    return (left>right ? left:right)+1;
}

//----------------------------------------Traversal----------------------

void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        printf(" %d",root->data);
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    Node* root = NULL;
    int choice, value;
    Node* result;

    while (1)
    {
        printf("\n\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Insert (Recursive)\n");
        printf("2. Insert (Iterative)\n");
        printf("3. Search (Recursive)\n");
        printf("4. Search (Iterative)\n");
        printf("5. Delete (Recursive)\n");
        printf("6. Inorder Traversal\n");
        printf("7. Preorder Traversal\n");
        printf("8. Postorder Traversal\n");
        printf("9. Find Minimum\n");
        printf("10. Find Maximum\n");
        printf("11. Height of Tree\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertRec(root, value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertIter(&root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = recSearch(root, value);
                if (result)
                    printf("Value %d found in tree.\n", value);
                else
                    printf("Value %d NOT found.\n", value);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (iterSearch(root, value))
                    printf("Value %d found in tree.\n", value);
                else
                    printf("Value %d NOT found.\n", value);
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteRec(root, value);
                break;

            case 6:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 7:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 8:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 9:
                result = minSearch(root);
                if (result)
                    printf("Minimum value = %d\n", result->data);
                break;

            case 10:
                result = maxSearch(root);
                if (result)
                    printf("Maximum value = %d\n", result->data);
                break;

            case 11:
                printf("Height of tree = %d\n", findHeight(root));
                break;

            case 12:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
