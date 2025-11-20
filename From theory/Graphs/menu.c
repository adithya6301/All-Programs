#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

// Node structure for adjacency list
typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* graph[MAX_VERTICES];   // adjacency list
int visited[MAX_VERTICES];   // visited array
int n;                       // number of vertices
int isDirected = 0;          // flag: 0 = undirected, 1 = directed

//----------------------------------
// Create a new node
//----------------------------------
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

//----------------------------------
// Add Edge (supports directed & undirected)
//----------------------------------
void addEdge(int src, int dest) {
    // Insert dest into src's list
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    // For undirected graph, also add reverse edge
    if (!isDirected) {
        newNode = createNode(src);
        newNode->next = graph[dest];
        graph[dest] = newNode;
    }
}

//----------------------------------
// Display adjacency list
//----------------------------------
void displayGraph() {
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//----------------------------------
// DFS using recursion
//----------------------------------
void dfs(int v) {
    Node* w;
    visited[v] = TRUE;
    printf("%5d", v);

    for (w = graph[v]; w != NULL; w = w->next) {
        if (!visited[w->vertex])
            dfs(w->vertex);
    }
}

//----------------------------------
// BFS using linked queue
//----------------------------------

typedef struct queue {
    int vertex;
    struct queue* link;
} QueueNode;

typedef QueueNode* queue_pointer;

void addq(queue_pointer* front, queue_pointer* rear, int v) {
    queue_pointer temp = (queue_pointer)malloc(sizeof(QueueNode));
    temp->vertex = v;
    temp->link = NULL;
    if (*rear)
        (*rear)->link = temp;
    else
        *front = temp;
    *rear = temp;
}

int deleteq(queue_pointer* front) {
    if (!(*front))
        return -1;

    queue_pointer temp = *front;
    int v = temp->vertex;
    *front = temp->link;
    free(temp);
    return v;
}

void bfs(int start) {
    Node* w;
    queue_pointer front = NULL, rear = NULL;

    printf("%5d", start);
    visited[start] = TRUE;
    addq(&front, &rear, start);

    while (front) {
        int v = deleteq(&front);
        for (w = graph[v]; w; w = w->next) {
            if (!visited[w->vertex]) {
                printf("%5d", w->vertex);
                visited[w->vertex] = TRUE;
                addq(&front, &rear, w->vertex);
            }
        }
    }
}

//----------------------------------
// Reset visited[] to 0
//----------------------------------
void resetVisited() {
    for (int i = 0; i < n; i++)
        visited[i] = FALSE;
}

//----------------------------------
// Main Menu
//----------------------------------
int main() {
    int choice, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        graph[i] = NULL;

    printf("\nChoose Graph Type:\n");
    printf("1. Undirected\n");
    printf("2. Directed\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 2) isDirected = 1;

    while (1) {
        printf("\n========== GRAPH MENU ==========\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. DFS Traversal\n");
        printf("4. BFS Traversal\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter edge (source destination): ");
            scanf("%d %d", &src, &dest);
            addEdge(src, dest);
            break;

        case 2:
            displayGraph();
            break;

        case 3:
            resetVisited();
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &start);
            printf("DFS Order: ");
            dfs(start);
            printf("\n");
            break;

        case 4:
            resetVisited();
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &start);
            printf("BFS Order: ");
            bfs(start);
            printf("\n");
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}
