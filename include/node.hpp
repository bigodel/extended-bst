#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node
{
public:
    int static const DEFAULT_KEY = 100;
    int key;
    Node* left;
    Node* right;
    int nLeft;
    int nRight;

    Node();
    Node(int key);
    Node(int key, Node* leftNode, Node* rightNode, int nLeft, int nRight);
};

#endif /* NODE_H */
