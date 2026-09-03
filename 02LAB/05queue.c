#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void isEmpty(){
    if (front == -1)
    {
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
    }
    
}
void isfull(){
    if(rear == MAX-1){
        printf("Queue is full\n");
    }else{
        printf("Queue is not full\n");
    }
}

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d removed from queue\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");

        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main() {
    isEmpty();

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    dequeue();

    isfull();

    display();

    return 0;
}