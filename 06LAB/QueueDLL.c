#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue
void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d Inserted.\n", value);
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;

    printf("Deleted: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }

    free(temp);
}

// Display
void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    return 0;
}