#ifndef BST_H
#define BST_H

#include "node.hpp"
#include <string>
#include <queue>

class BST
{
private:
    int height;
    int nodes;

    Node* insertRec(int key, Node* root);
    Node* minValue(Node* root);
    Node* removeRec(int key, Node* root);
<<<<<<< HEAD
    int positionRec(int key, Node* root, int pos);
||||||| merged common ancestors
=======
    int nthElementRec(int n, Node* root);
>>>>>>> nthElement

public:
    Node* root;
    BST();
    void insert(int key);
    Node* search(int key, Node* root);
    void remove(int key);
<<<<<<< HEAD
    // int nthElem(int n);
    int position(int key);
||||||| merged common ancestors
    // int nthElem(int n);
    // int position(int key);
=======
    int nthElement(int n);
    // int position(int key);
>>>>>>> nthElement
    // int median();
    // perfect binary tree is the same as cheia in portuguese
    // bool isPerfect();
    // bool isComplete();
    string toString();
};

#endif /* BST_H */

