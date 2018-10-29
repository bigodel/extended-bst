#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef enum bool_e { false, true } bool;

typedef enum printChoice_e {
    INORDER = 1,
    PREORDER = 2,
    POSORDER = 3,
    LEVEL = 4
} printChoice;

typedef struct BST_s
{
    Node *root;
} BST;

BST *initBST();
bool insertRec(Node *newNode, Node **root);
void insert(int key, int data, BST *tree);
Node *searchRec(int key, Node *root);
Node *search(int key, BST *tree);
bool removeRec(int key, Node *root);
// this needed to be named removeNode instead
// of remove because of a conflict in names
void removeNode(int key, BST *tree);
void printTree(BST *tree);

#endif /* BST_H */
