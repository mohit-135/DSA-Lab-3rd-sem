#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int lthread, rthread;
};

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = 1;
    newNode->rthread = 1;

    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    struct Node *parent = NULL;
    struct Node *current = root;

    while (current != NULL) {
        if (data == current->data) {
            printf("Duplicate values are not allowed\n");
            return root;
        }

        parent = current;

        if (data < current->data) {
            if (current->lthread == 0)
                current = current->left;
            else
                break;
        } else {
            if (current->rthread == 0)
                current = current->right;
            else
                break;
        }
    }

    struct Node *newNode = createNode(data);

    if (parent == NULL) {
        root = newNode;
    } else if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;

        parent->lthread = 0;
        parent->left = newNode;
    } else {
        newNode->left = parent;
        newNode->right = parent->right;

        parent->rthread = 0;
        parent->right = newNode;
    }

    return root;
}

struct Node *leftMost(struct Node *node) {
    if (node == NULL)
        return NULL;

    while (node->lthread == 0)
        node = node->left;

    return node;
}

void inorder(struct Node *root) {
    struct Node *current = leftMost(root);

    while (current != NULL) {
        printf("%d ", current->data);

        if (current->rthread == 1)
            current = current->right;
        else
            current = leftMost(current->right);
    }

    printf("\n");
}

void freeTree(struct Node *root) {
    if (root == NULL)
        return;

    if (root->lthread == 0)
        freeTree(root->left);

    if (root->rthread == 0)
        freeTree(root->right);

    free(root);
}

int main() {
    struct Node *root = NULL;
    int n, data, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &data);

        root = insert(root, data);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    freeTree(root);

    return 0;
}