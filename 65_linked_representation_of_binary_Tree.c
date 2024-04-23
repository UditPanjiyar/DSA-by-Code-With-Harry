#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int data)
{
    struct Node *n; // creating structure pointer
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data; // setting data of node
    n->left = NULL; // setting  left and right children to null
    n->right = NULL; // setting left and right children to null
    return n;
}

int main()
{
    /*
// Constructing the root node
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 2;
    p->left = p1;
    p->right = p2;

// Constructing the second node
    struct Node *p1;
    p1 = (struct Node *)malloc(sizeof(struct Node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

// Constructing the third node
    struct Node *p2;
    p2 = (struct Node *)malloc(sizeof(struct Node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    */
    // Constructing the root node - Using Function (Recommended)
    struct Node *p = create_node(2);
    struct Node *p1 = create_node(1);
    struct Node *p2 = create_node(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}
