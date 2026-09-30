#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at end
void insert(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Search
void search(int value) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d\n", value, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("%d not found in the list\n", value);
}

int main() {

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    search(30);
    search(60);

    return 0;
}