#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T static const DEFAULT_KEY = 100;
    T key;
    Node *left;
    Node *right;
    int nLeft;
    int nRight;

    Node();
    Node(T key);
    Node(T key, Node<T> *leftNode, Node<T> *rightNode, int nLeft, int nRight);
};

#endif /* NODE_H */
