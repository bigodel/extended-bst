#include "node.h"

Node *initNode(int key, int data)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->data = data;
    node->left = node->right = NULL;
    node->nLeft = node->nRight = 0;

    return node;
}

void deleteNode(Node *node)
{
    free(node);
}
