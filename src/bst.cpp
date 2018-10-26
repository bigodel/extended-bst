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

void BST::swapNodes(Node* &node1, Node* &node2)
{
    Node* aux = node1;
    node1 = node2;
    node2 = aux;
}

void BST::remove(int key)
{
    removeRec(key, this->root);
}

bool BST::removeRec(int key, Node* &root)
{
    bool removed;

    if (root == nullptr)
        return false;

    if (key < root->key) {
        bool removed = removeRec(key, root->left);

        if (removed)
            root->nLeft--;

        return removed;
    }
    else if (key > root->key) {
        bool removed = removeRec(key, root->right);

        if (removed)
            root->nRight--;

        return removed;
    }
    else {
        // case where both children are null
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            return true;
        }
        // case where the left child is null
        if (root->left == nullptr) {
            swapNodes(root, root->right);
            delete root->right;
            root->right = nullptr;
            return true;
        }
        // case where the right child is null
        else if (root->right == nullptr) {
            swapNodes(root, root->left);
            delete root->left;
            root->left = nullptr;
            return true;
        }

        /* the node has both a left and right non-nil sub-tree
           create a node that will have the reference to the inorder successor
           of root */
        Node** minNode = &root->right;

        /* find the inorder successor of root and update the number of left
           subtrees at each step
           (just get the most far node to the left) */
        while ((*minNode)->left != nullptr) {
            (*minNode)->nLeft--;
            minNode = &(*minNode)->left;
        }

        // delete the successor using the pointer to it and set the deleted
        // memory region to null so we know it was deleted
        delete *minNode;
        *minNode = nullptr;

        removed = true;
    }

    return removed;
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
