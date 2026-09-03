#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

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

    printf("Linked List: ");
    display();

    deleteBeginning();

    printf("After deleting beginning: ");
    display();

    deleteEnd();

    printf("After deleting end: ");
    display();

    return 0;
}