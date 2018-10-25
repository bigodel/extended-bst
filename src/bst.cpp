#include "../include/bst.hpp"

BST::BST()
{
    root = nullptr;
}

void BST::insert(int key)
{
    insertRec(key, this->root);
}

bool BST::insertRec(int key, Node* &root)
{
    if (root == nullptr) {
        root = new Node(key);
        return true;
    }

    if (key < root->key) {
        bool inserted = insertRec(key, root->left);

        if (inserted)
            root->nLeft++;

        return inserted;
    }
    else if (key > root->key) {
        bool inserted = insertRec(key, root->right);

        if (inserted)
            root->nRight++;

        return inserted;
    }

    return false;
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

void BST::newRemove(int key)
{
    newRemoveRec(key, this->root);
}

bool BST::newRemoveRec(int key, Node* &root)
{
    bool removed;

    if (root == nullptr)
        delete(root);

    if (key < root->key) {
        bool removed = newRemoveRec(key, root->left);

        if (removed)
            root->nLeft--;

        return removed;
    }
    else if (key > root->key) {
        bool removed = newRemoveRec(key, root->right);

        if (removed)
            root->nRight--;

        return removed;
    }
    else {
        // case where both children are null
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
            return true;
        }
        // case where the left child is null
        if (root->left == nullptr) {
            Node* tmp = root;
            root = root->right;
            delete(tmp);
            return true;
        }
        // case where the right child is null
        else if (root->right == nullptr) {
            Node* tmp = root;
            root = root->left;
            delete(tmp);
            return true;
        }

        // the node has both a left and right non-nil sub-tree
        // create a temporary node with the smallest node of the left sub-tree
        Node* tmp = minValue(root->right);

        root->key = tmp->key;

        removed = removeRec(tmp->key, root->right);
    }

    return removed;
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
        // case where both children are null
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
            return nullptr;
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

int BST::position(int key)
{
    return positionRec(key, this->root, 0);
}

int BST::positionRec(int key, Node* root, int pos)
{
    if (key < root->key)
        return positionRec(key, root->left, pos);
    else if (key > root->key)
        return positionRec(key, root->right, pos + (root->nLeft + 1));

    return pos + root->nLeft + 1;
}

int BST::nthElement(int n)
{
    return nthElementRec(n, this->root);
}

int BST::nthElementRec(int n, Node* root)
{
    if (root == nullptr)
        return -1;

    int pos = root->nLeft + 1;

    if (n < pos)
        return nthElementRec(n, root->left);
    else if (n > pos)
        return nthElementRec(n - pos, root->right);

    return root->key;
}

int BST::median()
{
    int nNodes = root->nLeft + root->nRight + 1;

    if (nNodes % 2 == 0)
        return nthElement(nNodes/2);

    return nthElement(nNodes/2 + 1);
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
