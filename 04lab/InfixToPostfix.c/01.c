#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // Operand
        if (isalnum(c)) {
            postfix[j++] = c;
        }

        // Opening bracket
        else if (c == '(') {
            push(c);
        }

        // Closing bracket
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // remove '('
        }

        // Operator
        else {
            while (top != -1 &&
                    peek() != '(' &&
                    precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }

            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}