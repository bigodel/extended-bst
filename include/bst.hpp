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
    void nthElement(Node , int ,std::vector<int> *);

public:
    Node* root;
    BST();
    void insert(int key);
    Node* search(int key, Node* root);
    void remove(int key);
    int nthElement(int n);
    // int position(int key);
    // int median();
    // perfect binary tree is the same as cheia in portuguese
    // bool isPerfect();
    // bool isComplete();
    string toString();
};

#endif /* BST_H */

