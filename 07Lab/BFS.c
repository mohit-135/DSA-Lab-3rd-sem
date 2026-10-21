
#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

void BFS(int start) {
    int front = 0, rear = 0;
    int vertex, i;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        vertex = queue[front++];
        printf("%c ", 'A' + vertex);

        for (i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
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

    printf("BFS Traversal: ");
    BFS(start);
    printf("\n");

    return 0;
}
