#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};
struct Node *root = NULL;

struct Node *recurInsert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = recurInsert(p->lchild, key);
    }
    else if (key > p->data)
        p->rchild = recurInsert(p->rchild, key);

    return p;
}

void inorder(struct Node *p)
{

    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}
int main()
{
   //inserting 100,90,80 into binary search tree
    root = recurInsert(root, 100);
    recurInsert(root, 90);
    recurInsert(root, 80);
    inorder(root);   //prints inorder traversal of BST
}