#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void doubly_linkedlist_traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *Insert_at_beginning(struct Node *head, int element)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;

    head = ptr;
    return head;
}

struct Node *Insert_at_last(struct Node *head, int element)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;

    struct Node *p = head;
    // int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        // i++;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;

    return head;
}

struct Node *Insert_in_netween(struct Node *head, int element, int index)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;

    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;

    return head;
}

struct Node * Insert_after_node(struct Node * head, struct Node * previousNode, int element)
{
    struct Node *ptr = (struct Node * )malloc(sizeof(struct Node));
    ptr->data = element;

    ptr->next = previousNode->next;
    previousNode->next = ptr;
    ptr->prev = previousNode;

    return head;


}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = NULL;

    doubly_linkedlist_traversal(head);

    // head = Insert_at_beginning(head, 1);
    // doubly_linkedlist_traversal(head);

    Insert_at_last(head, 50);
    doubly_linkedlist_traversal(head);

    // Insert_in_netween(head,25,2);
    // doubly_linkedlist_traversal(head);

    // Insert_after_node(head, second,100);
    // doubly_linkedlist_traversal(head);

    return 0;
}