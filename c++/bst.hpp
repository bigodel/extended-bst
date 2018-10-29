#ifndef BST_H
#define BST_H

#include "node.hpp"
#include <string>
#include <queue>

class BST
{
private:
    Node *root;

    bool insertRec(int key, Node *&root);
    bool removeRec(int key, Node *&root);
    int positionRec(int key, Node *root, int pos);
    int nthElementRec(int n, Node *root);

public:
    BST();
    void insert(int key);
    Node *search(int key, Node *root);
    void remove(int key);
    int nthElement(int n);
    int position(int key);
    int median();
    // perfect binary tree is the same as cheia in portuguese
    bool isPerfect();
    bool isComplete();
    string toString();
};

#endif /* BST_H */

