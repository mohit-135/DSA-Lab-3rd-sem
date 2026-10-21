#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *createNode(int vertex) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void displayGraph(struct Node *adj[], int vertices) {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < vertices; i++) {
        struct Node *temp = adj[i];

        printf("%d: ", i);

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    struct Node *adj[MAX] = {NULL};
    int vertices, edges;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    displayGraph(adj, vertices);

    return 0;
}