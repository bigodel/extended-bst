#include "../include/node.hpp"

template <typename T>
Node<T>::Node()
{
    key = DEFAULT_KEY;
    Node *left = nullptr;
    Node *right = nullptr;
    nLeft = 0;
    nRight = 0;
}

template <typename T>
Node<T>::Node(T key)
{
    this();
    this->key = key;
}

template <typename T>
Node<T>::Node(T key, Node<T> *leftNode, Node<T> *rightNode,
              int nLeft, int nRight)
{
    this->key = key;
    this->left = leftNode;
    this->right = rightNode;
    this->nLeft = nLeft;
    this->nRight = nRight;
}
