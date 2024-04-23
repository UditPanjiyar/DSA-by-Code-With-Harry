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
    n->data = data;  // setting data of node
    n->left = NULL;  // setting  left and right children to null
    n->right = NULL; // setting left and right children to null
    return n;
}

void pre_order_traversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

int main()
{
    // Finally The tree looks like this:
    //       5 (p)
    //     /   \
    //    3(p1) 6(p2)
    //   / \
    //  1   4
    // (p3) (p4)

    // Constructing the root node - Using Function (Recommended)
    struct Node *p = create_node(5);
    struct Node *p1 = create_node(3);
    struct Node *p2 = create_node(6);
    struct Node *p3 = create_node(1);
    struct Node *p4 = create_node(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    pre_order_traversal(p);

    return 0;
}
