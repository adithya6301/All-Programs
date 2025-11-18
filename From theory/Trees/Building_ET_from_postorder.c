#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(char data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if(!temp){
        printf("\nMemory alloc failed!!");
        exit(1);
    }
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//Stack for appending the expression
typedef struct
{
    Node* arr[100];
    int top;
}Stack;

void init(Stack* s) {s->top=-1;}

void push(Stack* s , Node* n){
    s->arr[++s->top] = n;
}

Node* pop(Stack* s)
{
    return s->arr[s->top--];
}

Node* buildingET(char postfix[])
{
    Stack s;
    init(&s);
    int i;
    for(i=0;postfix[i]!='\0';i++)
    {
        char symbol = postfix[i];
        if(symbol == ' ')
        {continue;}
        if(isalnum(symbol))
        {
            Node* temp = createNode(symbol);
            push(&s,temp);
        }
        else
        {
            Node* right = pop(&s);
            Node* left = pop(&s);

            Node* op = createNode(symbol);
            op->left=left;
            op->right=right;
            push(&s,op);
        }
    }
    return pop(&s);
}

//Traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}


//Building Expression Tree
int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%[^\n]", postfix);

    Node* root = buildingET(postfix);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}
