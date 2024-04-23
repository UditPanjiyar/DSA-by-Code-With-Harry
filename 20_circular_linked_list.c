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
    /*
    while (ptr->next != head)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("element: %d\n", ptr->data);
    */

    do
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
 
    printf("\n");
}

struct Node *Insert_at_beginning(struct Node *head, int element)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = element;

    struct Node *p = head;

    int i = 0;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;

    // return ptr;
    // (or)
    head = ptr;
    return head;
}

struct Node *Insert_in_between(struct Node *head, int index, int element)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;

    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    // for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        i++;
    }
   
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *Insert_at_last(struct Node *head,  int element)
{
    struct Node * ptr;
    ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr->data = element;
    struct Node * p = head;
    int i=0;
    while(p->next != head)
    {
        p= p->next;
        i++;
    }
    p->next = ptr;
    ptr->next = head;
    return head;

}

struct Node * Insert_after_node(struct Node *head,struct Node * previousNode, int element )
{
    struct Node* ptr;
    ptr = (struct Node* )malloc(sizeof(struct Node));
    ptr->data= element;

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
    fourth->next = head;

    printf("circular linked list before insertion\n ");

    linkedlist_Traversal(head);

    printf("circular linked list before insertion \n");

    // head = Insert_at_beginning(head, 5);
    // linkedlist_Traversal(head);

    // Insert_in_between(head,2,25);
    // linkedlist_Traversal(head);

    // Insert_at_last(head,50);
    // linkedlist_Traversal(head);

    Insert_after_node(head, third, 35);
    linkedlist_Traversal(head);
    
    return 0;
}