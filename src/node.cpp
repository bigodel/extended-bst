#include "../include/node.hpp"

Node::Node()
{
    key = DEFAULT_KEY;
    left = nullptr;
    right = nullptr;
    nLeft = 0;
    nRight = 0;
}

Node::Node(int key)
{
    this->key = key;
    left = nullptr;
    right = nullptr;
    nLeft = 0;
    nRight = 0;
}

Node::Node(int key, Node* leftNode, Node* rightNode,
              int nLeft, int nRight)
{
    this->key = key;
    this->left = leftNode;
    this->right = rightNode;
    this->nLeft = nLeft;
    this->nRight = nRight;
}
