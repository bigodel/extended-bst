#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int key;
    int data;
    struct Node_s *left;
    struct Node_s *right;
    int nLeft;
    int nRight;
} Node;

Node *initNode(int key, int data);
void deleteNode(Node *node);

#endif /* NODE_H */
