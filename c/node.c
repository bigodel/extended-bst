#include "node.h"

Node *newNode(int key, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->nLeft = 0;
    newNode->nRight = 0;

    return newNode;
}
