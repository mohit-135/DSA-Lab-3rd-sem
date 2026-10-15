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
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    // First node
    if (front == NULL) {
        front = rear = newNode;

        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->next = front;
        newNode->prev = rear;

        rear->next = newNode;
        front->prev = newNode;

        rear = newNode;
    }

    printf("%d inserted\n", value);
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;

    // Only one node
    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;

        front->prev = rear;
        rear->next = front;
    }

    printf("%d deleted\n", temp->data);
    free(temp);
}

// Display
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;

    printf("Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    display();

    enqueue(50);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}