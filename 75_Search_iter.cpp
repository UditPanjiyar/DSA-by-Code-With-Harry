#include <iostream>
using namespace std;

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
// Finally The tree looks like this:
//       5 (p)
//     /   \
    //    3(p1) 6(p2)
//   / \
    //  1   4
// (p3) (p4)

struct Node *search_iter(struct Node *root, int key)
{
    struct Node *n = root;
    while (root != NULL)
    {
        if (n == NULL)
            return NULL;
        if (n->data == key)
            return n;
        else if (key < n->data)
        {
            n = n->left;
        }
        else
        {
            n = n->right;
        }
    }
    return NULL;
}

int main()
{
    struct Node *p = create_node(5);
    struct Node *p1 = create_node(3);
    struct Node *p2 = create_node(6);
    struct Node *p3 = create_node(1);
    struct Node *p4 = create_node(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct Node *x = search_iter(p, 5);
    if (x != NULL)
    {
        printf("\nFound: %d", (x->data));
    }
    else
    {
        printf("element not found");
    }
    return 0;
}