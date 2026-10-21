
#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int vertex) {
    int i;

    printf("%c ", 'A' + vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex\n");
        return 1;
    }

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
