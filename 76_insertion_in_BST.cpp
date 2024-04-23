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
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder_traversal(struct Node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void insert(struct Node *root, int key)
{
    // int a;
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;

        if (root->data == key)
        {
            printf("insertion not possible due to duplicate element: %d\n", key);
            // root = NULL;
            //  a = 1;
        }
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    // if (a != 1)
    // {

        struct Node *NEW = create_node(key);
        if (key < prev->data)
            prev->left = NEW;
        else if (key > prev->data)
        
            prev->right = NEW;
    // }
}

int main()
{
    // Finally The tree looks like this:
    //       5 (p)
    //     /   \
    //    3(p1) 8(p2)
    //   / \
    //  1   4
    // (p3) (p4)

    struct Node *p = create_node(5);
    struct Node *p1 = create_node(3);
    struct Node *p2 = create_node(8);
    struct Node *p3 = create_node(1);
    struct Node *p4 = create_node(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 8);
    // printf("%d",p->right->left->data);

    return 0;
}
