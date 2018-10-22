#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T key;
    Node *left;
    Node *right;
    int nLeft;
    int nRight;

    Node();
    virtual ~Node();
};

#endif /* NODE_H */
