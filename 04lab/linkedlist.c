#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert in middle
void insertMiddle(int data, int position)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;

    if (position <= 1 || head == NULL)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    head = head->next;

    free(temp);
}

// Delete from end
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete from middle
void deleteMiddle(int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position <= 1)
    {
        struct Node *temp = head;

        head = head->next;

        free(temp);
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);
}

// Display linked list
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);

    insertEnd(40);
    insertEnd(50);

    printf("After insertion: ");
    display();

    // Insert 25 at position 3
    insertMiddle(25, 3);

    printf("After inserting 25 at position 3: ");
    display();

    // Delete from beginning
    deleteBeginning();

    printf("After deleting beginning: ");
    display();

    // Delete from end
    deleteEnd();

    printf("After deleting end: ");
    display();

    // Delete node at position 3
    deleteMiddle(3);

    printf("After deleting node at position 3: ");
    display();

    return 0;
}