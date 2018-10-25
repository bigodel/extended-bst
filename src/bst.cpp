#include "../include/bst.hpp"

BST::BST()
{
    root = nullptr;
    height = 0;
    nodes = 1;
}

void BST::insert(int key)
{
    if (search(key, root))
        return;
    else
        this->root = insertRec(key, this->root);
}

Node* BST::insertRec(int key, Node* root)
{
    if (root == nullptr)
        return new Node(key);

    if (key < root->key) {
        root->nLeft++;
        root->left = insertRec(key, root->left);
    }
    else if (key > root->key) {
        root->nRight++;
        root->right = insertRec(key, root->right);
    }

    return root;
}

Node* BST::search(int key, Node* root)
{
    // if the root is null than we couldn't find the value of key in the tree
    if (root == nullptr || key == root->key)
        return root;

    if (key < root->key)
        return search(key, root->left);
    else
        return search(key, root->right);
}

Node* BST::minValue(Node* root)
{
    Node* curr = root;

    while (curr->left != nullptr)
        curr = curr->left;

    return curr;
}

void BST::remove(int key)
{
    if (!search(key, root))
        return;
    else
        this->root = removeRec(key, this->root);
}

Node* BST::removeRec(int key, Node* root)
{
    if (root == nullptr)
        return root;

    if (key < root->key) {
        root->nLeft--;
        root->left = removeRec(key, root->left);
    }
    else if (key > root->key) {
        root->nRight--;
        root->right = removeRec(key, root->right);
    }
    // this is when we reached the key we want to remove
    else {
        // case where both the children are null
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
        }
        // case where the left child is null
        else if (root->left == nullptr) {
            Node* tmp = root->right;
            delete(root);
            return tmp;
        }
        // case where the right child is null
        else if (root->right == nullptr) {
            Node* tmp = root->left;
            delete(root);
            return tmp;
        }

        // the node has both a left and right non-nil sub-tree
        // create a temporary node with the smallest node of the left sub-tree
        Node* tmp = minValue(root->right);

        root->key = tmp->key;

        root->right = removeRec(tmp->key, root->right);
    }

    return root;
}

string BST::toString()
{
    string nodesByDepth;
    queue<Node> queue;

    if (root != nullptr) {
        queue.push(*root);

        while (!queue.empty()) {
            Node node = queue.front();
            queue.pop();
            nodesByDepth += to_string(node.key) + " ";

            if(node.left != nullptr)
                queue.push(*node.left);

            if(node.right != nullptr)
                queue.push(*node.right);
        }
    }

    return nodesByDepth;
}
