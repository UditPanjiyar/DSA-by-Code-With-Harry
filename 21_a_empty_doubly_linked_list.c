#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node * AddtoEmpty(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = NULL;
    ptr->prev = NULL;

    // head = ptr;
    // return head;

    // (or)

    return ptr;
}

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));

    //     head->data = 10;
    //     head->prev = NULL;
    //     head->next= NULL;
    //   printf("%d",head->data);

        // [NULL|head|NULL]
        
    head = NULL;
    head = AddtoEmpty(head, 10);
    printf("%d\n", head->data);

    return 0;
}