#ifndef BST_H
#define BST_H

#include "node.hpp"

template <typename T>
class BST
{
private:
    int height;
    int nodes;

    void insertRec(T key, Node<T> *root);
    Node<T> *minValue(Node<T> *root);
    Node<T> *removeRec(T key, Node<T> *root);

public:
    Node<T> *root;
    BST();
    void insert(T key);
    Node<T> *search(T key, Node<T> *root);
    void remove(T key);
    // T nthElem(int n);
    // int position(T key);
    // T median();
    // perfect binary tree is the same as cheia in portuguese
    // bool isPerfect();
    // bool isComplete();
    // string toString();
};

#endif /* BST_H */
