#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertStart(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("%d Inserted at start \n",value);
}

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("%d Inserted at end \n",value);
}


void insertMiddle(int value, int position) {
    if (position == 1) {
        insertStart(value);
        return;
    }

    struct Node *temp = head;
    int i = 1;

    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    printf("%d Inserted at position %d \n",value , position);
}


void deleteStart() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("%d Deleted from start \n",temp ->data);
    free(temp);

}

// Delete from End
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Delete from Middle / Position
void deleteMiddle(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        deleteStart();
        return;
    }

    struct Node *temp = head;
    int i = 1;

    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

// Main
int main() {
    // int choice, value, position;

    // while (1) {
    //     printf("\n--- DOUBLY LINKED LIST ---\n");
    //     printf("1. Insert at Start\n");
    //     printf("2. Insert at End\n");
    //     printf("3. Insert at Middle\n");
    //     printf("4. Delete from Start\n");
    //     printf("5. Delete from End\n");
    //     printf("6. Delete from Middle\n");
    //     printf("7. Display\n");
    //     printf("8. Exit\n");

    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {

    //         case 1:
    //             printf("Enter value: ");
    //             scanf("%d", &value);
    //             insertStart(value);
    //             break;

    //         case 2:
    //             printf("Enter value: ");
    //             scanf("%d", &value);
    //             insertEnd(value);
    //             break;

    //         case 3:
    //             printf("Enter value: ");
    //             scanf("%d", &value);

    //             printf("Enter position: ");
    //             scanf("%d", &position);

    //             insertMiddle(value, position);
    //             break;

    //         case 4:
    //             deleteStart();
    //             break;

    //         case 5:
    //             deleteEnd();
    //             break;

    //         case 6:
    //             printf("Enter position: ");
    //             scanf("%d", &position);

    //             deleteMiddle(position);
    //             break;

    //         case 7:
    //             display();
    //             break;

    //         case 8:
    //             exit(0);

    //         default:
    //             printf("Invalid choice\n");
    //     }
    // }

    insertStart(10);
    insertStart(20);
    // insertStart(30);
    // insertStart(40);

    insertEnd(50);
    insertEnd(60);

    insertMiddle(60,3);
    display();

    deleteStart();
    // deleteStart();
    deleteEnd();
    // deleteEnd();
    // deleteMiddle(2);

    display();

    return 0;
}