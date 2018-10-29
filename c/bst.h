#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef enum bool_e { false, true } bool;

typedef struct BST_s
{
    Node *root;
} BST;

BST *newBST();
bool insertRec(Node *newNode, Node *root);
void insert(int key, int data, BST *tree);
Node *search(int key, Node *root);

#endif /* BST_H */
