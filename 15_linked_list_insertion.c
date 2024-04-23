#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlist_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
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

    // head = ptr;      // 1
    // return head;     // 2
    

    // (or)

    return ptr;         // 3
}

struct Node *Insert_between(struct Node *head, int element, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    ptr->data = element;
    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *Insert_at_last(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = element;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *Insert_after_node(struct Node *head, struct Node *previousNode, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = previousNode->next;
    previousNode->next = ptr;
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
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    linkedlist_traversal(head);

    // head = Insert_at_beginning(head, 50);
    // linkedlist_traversal(head);

    Insert_between(head, 33, 2);
    linkedlist_traversal(head);

    // Insert_at_last(head,100);
    // linkedlist_traversal(head);

    // Insert_after_node(head, second, 25);
    // linkedlist_traversal(head);
    return 0;
}