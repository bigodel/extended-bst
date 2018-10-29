#include "bst.h"

BST *initBST()
{
    BST *newBST = (BST *) malloc(sizeof(BST));
    newBST->root = NULL;

    return newBST;
}

bool insertRec(Node *newNode, Node **root)
{
    if (*root == NULL) {
        *root = newNode;
        return true;
    }

    if (newNode->key < (*root)->key) {
        bool inserted = insertRec(newNode, &(*root)->left);

        if (inserted)
            (*root)->nLeft++;

        return inserted;
    }
    else if (newNode->key > (*root)->key) {
        bool inserted = insertRec(newNode, &(*root)->right);

        if (inserted)
            (*root)->nRight++;

        return inserted;
    }

    return false;
}

void insert(int key, int data, BST *tree)
{
    insertRec(initNode(key, data), &tree->root);
}

Node *searchRec(int key, Node *root)
{
    if (root == NULL || key == root->key) return root;

    if (key < root->key)
        return searchRec(key, root->left);
    else
        return searchRec(key, root->right);
}

Node *search(int key, BST *tree)
{
    return searchRec(key, tree->root);
}

bool removeRec(int key, Node *root)
{
    bool removed;

    if (root == NULL) return false;

    if (key < root->key) {
        bool removed = removeRec(key, root->left);

        if (removed)
            root->nLeft--;

        return removed;
    }
    else if (key > root->key) {
        bool removed = removeRec(key, root->right);

        if (removed)
            root->nRight--;

        return removed;
    }
    else {
        // case where both children are null (i.e. root is a leaf)
        if (root->left == NULL && root->right == NULL) {
            deleteNode(root);
            root = NULL;
            return true;
        }
        // case where the left child is null and the right isn't
        if (root->left == NULL) {
            Node *tmp = root;
            root = root->right;
            tmp = NULL;
            deleteNode(tmp);
            return true;
        }
        // case where the right child is null and the left isn't
        else if (root->right == NULL) {
            Node *tmp = root;
            root = root->left;
            tmp = NULL;
            deleteNode(tmp);
            return true;
        }
        /* case where the root has both left and right children as not null
           sub-trees */

        /* here we create a node that will have the reference to the inorder
           successor or root*/
        Node **minNode = (Node **) &root->right;

        /* find the in-order successor of root and update the number of left
           sub-trees in each step (its basically getting the left most node of
           minNode) */
        while ((*minNode)->left != NULL) {
            (*minNode)->nLeft--;
            minNode = (Node **) &(*minNode)->left;
        }

        // assign the key of the in-order successor of root to root
        root->key = (*minNode)->key;

        /* delete the successor using the pointer to it and set the deleted
           memory region to null so we know it was deleted */
        deleteNode(*minNode);
        *minNode = NULL;

        removed = true;
    }

    return removed;
}

void removeNode(int key, BST *tree)
{
    removeRec(key, tree->root);
}

void printTree(BST *tree)
{
    printChoice choice = LEVEL;
    printf("Please chose a traversal to print the tree.\n");
    printf("[1] In-order\n");
    printf("[2] Pre-order\n");
    printf("[3] Post-order\n");
    printf("[4] Level\n");
    scanf("%i", &choice);

    if (choice < 1 || choice > 4) {
        printf("Chose a valid option!\n");
        printTree(tree);
    }
    /* TODO: the traversals (might need to implement stack) */
}
