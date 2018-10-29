#include "bst.h"

BST *newBST()
{
    BST *newBST = malloc(sizeof(BST));
    newBST->root = NULL;

    return newBST;
}

bool insertRec(Node *newNode, Node *root)
{
    bool inserted;

    return inserted;
}

void insert(int key, int data, BST *tree)
{
    Node *newNode = newNode(key, data);
    insertRec(newNode, tree->root);
}
