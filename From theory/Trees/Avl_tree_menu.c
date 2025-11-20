#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// GLOBAL ROOT
Node* root = NULL;

//-------------------------------------------
// Utility
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* n) {
    return (n == NULL) ? 0 : n->height;
}

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

//-------------------------------------------
// Rotations

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

//-------------------------------------------
// AVL INSERT
Node* insertAVL(Node* node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insertAVL(node->left, key);

    else if (key > node->data)
        node->right = insertAVL(node->right, key);

    else {
        printf("Duplicate %d ignored.\n", key);
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

//-------------------------------------------
// MIN SEARCH
Node* minSearch(Node* node)
{
    Node* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

//-------------------------------------------
// AVL DELETE

Node* deleteAVL(Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteAVL(root->left, key);

    else if (key > root->data)
        root->right = deleteAVL(root->right, key);

    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            Node* temp = minSearch(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//-------------------------------------------
// Traversals

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

//-------------------------------------------
// MENU

int main() {
    int choice, val;

    while (1) {
        printf("\n\n====== AVL TREE MENU ======\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Height\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insertAVL(root, val);   // ← DIRECT CHANGE
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                root = deleteAVL(root, val);   // ← DIRECT CHANGE
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Height = %d\n", height(root));
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
