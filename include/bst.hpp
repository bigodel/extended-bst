#ifndef BST_H
#define BST_H

#include "node.hpp"

template <class T>
class BST
{
private:
    Node<T> *root;
    int height;
    int nodes;

public:
    BST();
    void insert(T key);
    void remove(T key);
    T nthElem(int n);
    int position(T key);
    T median();
    // perfect binary tree is the same as cheia in portuguese
    bool isPerfect();
    bool isComplete();
    string toString();
    virtual ~BST();
};

#endif /* BST_H */
