#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void isEmpty() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

void isfull() {
    if (top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
    }
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    isEmpty();

    push(10);
    push(20);
    push(30);

    display();

    pop();
    pop();

    isfull();
    display();

    return 0;
}