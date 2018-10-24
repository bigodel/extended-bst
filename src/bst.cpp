#include "../include/bst.hpp"

template <typename T>
BST<T>::BST()
{
    root = nullptr;
    height = 0;
    nodes = 1;
}

template<typename T>
void BST<T>::insert(T key)
{
    this->root = insertRec(key, this->root);
}

template <typename T>
Node<T> *BST<T>::insertRec(T key, Node<T> *root)
{
    if (root == nullptr)
        return new Node<T>(key);

    if (key < root->key)
        root->left = insertRec(key, root->left);
    else if (key > root->key)
        root->right = insertRec(key, root->right);

    return root;
}

template <typename T>
Node<T> *BST<T>::search(T key, Node<T> *root)
{
    // if the root is null than we couldn't find the value of key in the tree
    if (root == nullptr || key == root->key)
        return root;

    if (key < root->key)
        return search(key, root->left);
    else
        return search(key, root->right);
}

template<typename T>
Node<T> *BST<T>::minValue(Node<T> *root)
{
    Node<T> *curr = root;

    while (curr->left != nullptr)
        curr = curr->left;

    return curr;
}

template<typename T>
void BST<T>::remove(T key)
{
    this->root = removeRec(key, this->root);
}

template<typename T>
Node<T> *BST<T>::removeRec(T key, Node<T> *root)
{
    if (root == nullptr)
        return root;

    if (key < root->key) {
        root->left = remove(key, root->left);
    }
    else if (key > root->key) {
        root->right = remove(key, root->right);
    }
    // this is when we reached the key we want to remove
    else {
        // case where both the children are null
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
        }
        // case where the left child is null
        else if (root->left == nullptr) {
            Node<T> *tmp = root->right;
            delete(root);
            return tmp;
        }
        // case where the right child is null
        else if (root->right == nullptr) {
            Node<T> *tmp = root->left;
            delete(root);
            return tmp;
        }

        // the node has both a left and right non-nil sub-tree
        // create a temporary node with the smallest node of the left sub-tree
        Node<T> *tmp = minValue(root->right);

        root->key = tmp->key;

        root->right = remove(tmp->key, root->right);
    }

    return root;
}
