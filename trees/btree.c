
#include <stdio.h>
#include <stdlib.h>

#define T 3

struct BTreeNode {
    int keys[2 * T - 1];
    struct BTreeNode *child[2 * T];
    int n;
    int leaf;
};

struct BTreeNode* createNode(int leaf) {
    struct BTreeNode *node =
        (struct BTreeNode*)malloc(sizeof(struct BTreeNode));

    node->n = 0;
    node->leaf = leaf;

    for (int i = 0; i < 2 * T; i++)
        node->child[i] = NULL;

    return node;
}

void traverse(struct BTreeNode *root) {
    if (root == NULL)
        return;

    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->child[i]);

        printf("%d ", root->keys[i]);
    }

    if (!root->leaf)
        traverse(root->child[i]);
}

void splitChild(struct BTreeNode *parent, int i,
                struct BTreeNode *full) {
    struct BTreeNode *right = createNode(full->leaf);
    right->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        right->keys[j] = full->keys[j + T];

    if (!full->leaf) {
        for (int j = 0; j < T; j++)
            right->child[j] = full->child[j + T];
    }

    full->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->child[j + 1] = parent->child[j];

    parent->child[i + 1] = right;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = full->keys[T - 1];
    parent->n++;
}

void insertNonFull(struct BTreeNode *node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        if (i >= 0 && key == node->keys[i])
            return;

        node->keys[i + 1] = key;
        node->n++;
    } else {
        while (i >= 0 && key < node->keys[i])
            i--;

        i++;

        if (i > 0 && key == node->keys[i - 1])
            return;

        if (node->child[i]->n == 2 * T - 1) {
            splitChild(node, i, node->child[i]);

            if (key > node->keys[i])
                i++;
            else if (key == node->keys[i])
                return;
        }

        insertNonFull(node->child[i], key);
    }
}

struct BTreeNode* insert(struct BTreeNode *root, int key) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = key;
        root->n = 1;
        return root;
    }

    if (root->n == 2 * T - 1) {
        struct BTreeNode *newRoot = createNode(0);
        newRoot->child[0] = root;

        splitChild(newRoot, 0, root);

        int i = 0;
        if (key > newRoot->keys[0])
            i++;

        if (key == newRoot->keys[0])
            return newRoot;

        insertNonFull(newRoot->child[i], key);
        return newRoot;
    }

    insertNonFull(root, key);
    return root;
}

int main() {
    struct BTreeNode *root = NULL;
    int n, key;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("\nB-Tree traversal: ");
    traverse(root);
    printf("\n");

    return 0;
}
