#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlist_Traversal(struct Node *head)
{
    struct Node *ptr = head;
    
    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // allocate meamory for nodes in linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second node
    head->data = 10;
    head->next = second;

    // link second and third  node
    second->data = 20;
    second->next = third;

    // link third and  fourth node
    third->data = 30;
    third->next = fourth;

    // terminating the list at the fourth node
    fourth->data = 40;
    fourth->next = NULL;

    linkedlist_Traversal(head);
    return 0;
}