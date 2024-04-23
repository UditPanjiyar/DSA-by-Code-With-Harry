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
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *delete_at_first(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    printf("deleted element is %d\n",ptr->data);
    free(ptr);
    return head;
}

struct Node *delete_in_between(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q;
    q = head->next;

    for (int i = 0; i < (index - 1); i++)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct Node *delete_at_last(struct Node *head)
{
    struct Node *p = head;
    struct Node *q;
    q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

struct Node *delete_at_index(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q;
    q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

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

    // head = delete_at_first(head);
    // linkedlist_traversal(head);

    // delete_in_between(head,2);
    // linkedlist_traversal(head);

    // delete_at_last(head);
    // linkedlist_traversal(head);

    // delete_at_index(head,30);
    // linkedlist_traversal(head);

    delete_at_index(head, 50);
    linkedlist_traversal(head);

    return 0;
}