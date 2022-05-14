#include <iostream>
#include <algorithm>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
};
TNode *createTNode(int);

typedef TNode *Tree;
void createTree(Tree &);
void NLR(Tree); // pre - order
void LNR(Tree); // in - order
void LRN(Tree); // post - order
int numberNode(Tree);
int numberLeafNode(Tree);
int height(Tree);
void clear(Tree);

int main()
{
    return 0;
}

TNode *createTNode(int d)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    p->data = d;
    p->left = p->right = NULL;
    return p;
}

void createTree(Tree &t)
{
    t = NULL;
}
void NLR(Tree t)
{
    if (t != NULL)
    {
        // <Xử lý root>;
        NLR(t->left);
        NLR(t->right);
    }
}
void LNR(Tree t)
{
    if (t != NULL)
    {
        LNR(t->left);
        // <Xử lý root>;
        LNR(t->right);
    }
}
void LRN(Tree t)
{
    if (t != NULL)
    {
        LRN(t->left);
        LRN(t->right);
        // <Xử lý root>;
    }
}
int numberNode(Tree t)
{
    if (t == NULL)
        return 0;
    return 1 + numberNode(t->left) + numberNode(t->right);
}
int numberLeafNode(Tree t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;
    return numberLeafNode(t->left) + numberLeafNode(t->right);
}
int height(Tree t)
{
    if (t == NULL)
        return 0;
    return 1 + max(height(t->left), height(t->right));
}
void clear(Tree t)
{
    if (t != NULL)
    {
        clear(t->left);
        clear(t->right);
        delete t;
        t = NULL;
    }
}