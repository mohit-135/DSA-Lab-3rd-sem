
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct Node {
    int keys[MAX + 1];
    struct Node *child[MAX + 2];
    struct Node *next;
    int n;
    int leaf;
};

struct Node *root = NULL;

struct Node *createNode(int leaf) {
    struct Node *node = malloc(sizeof(struct Node));

    node->n = 0;
    node->leaf = leaf;
    node->next = NULL;

    for (int i = 0; i < MAX + 2; i++)
        node->child[i] = NULL;

    return node;
}

void insert(int key) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = key;
        root->n = 1;
        return;
    }

    struct Node *path[100];
    int depth = 0;

    struct Node *current = root;

    while (!current->leaf) {
        path[depth++] = current;

        int i = 0;
        while (i < current->n && key >= current->keys[i])
            i++;

        current = current->child[i];
    }

    int i = 0;
    while (i < current->n && current->keys[i] < key)
        i++;

    if (i < current->n && current->keys[i] == key)
        return;

    for (int j = current->n; j > i; j--)
        current->keys[j] = current->keys[j - 1];

    current->keys[i] = key;
    current->n++;

    if (current->n <= MAX)
        return;

    // Split the leaf node
    struct Node *right = createNode(1);
    int mid = (current->n + 1) / 2;

    right->n = current->n - mid;

    for (int j = 0; j < right->n; j++)
        right->keys[j] = current->keys[mid + j];

    current->n = mid;

    right->next = current->next;
    current->next = right;

    int separator = right->keys[0];

    while (1) {
        if (depth == 0) {
            struct Node *newRoot = createNode(0);

            newRoot->keys[0] = separator;
            newRoot->child[0] = current;
            newRoot->child[1] = right;
            newRoot->n = 1;

            root = newRoot;
            return;
        }

        struct Node *parent = path[--depth];

        int pos = 0;
        while (pos < parent->n &&
               parent->child[pos] != current)
            pos++;

        for (int j = parent->n; j > pos; j--)
            parent->keys[j] = parent->keys[j - 1];

        for (int j = parent->n + 1; j > pos + 1; j--)
            parent->child[j] = parent->child[j - 1];

        parent->keys[pos] = separator;
        parent->child[pos + 1] = right;
        parent->n++;

        if (parent->n <= MAX)
            return;

        // Split the internal node
        struct Node *newRight = createNode(0);
        int middle = parent->n / 2;
        int promoted = parent->keys[middle];

        newRight->n = parent->n - middle - 1;

        for (int j = 0; j < newRight->n; j++)
            newRight->keys[j] = parent->keys[middle + 1 + j];

        for (int j = 0; j <= newRight->n; j++)
            newRight->child[j] = parent->child[middle + 1 + j];

        parent->n = middle;

        current = parent;
        right = newRight;
        separator = promoted;
    }
}

void traverse(struct Node *node) {
    if (node == NULL)
        return;

    while (!node->leaf)
        node = node->child[0];

    printf("B+ Tree leaf traversal: ");

    while (node != NULL) {
        for (int i = 0; i < node->n; i++)
            printf("%d ", node->keys[i]);

        node = node->next;
    }

    printf("\n");
}

int main() {
    int n, key;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        insert(key);
    }

    traverse(root);

    return 0;
}
