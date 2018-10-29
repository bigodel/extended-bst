#include "bst.hpp"

BST::BST()
{
    root = nullptr;
}

void BST::insert(int key)
{
    insertRec(key, this->root);
}

bool BST::insertRec(int key, Node *&root)
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

Node *BST::search(int key, Node *root)
{
    // if the root is null than we couldn't find the value of key in the tree
    if (root == nullptr || key == root->key)
        return root;

    if (key < root->key)
        return search(key, root->left);
    else
        return search(key, root->right);
}

void BST::swapNodes(Node *&node1, Node *&node2)
{
    Node *aux = node1;
    node1 = node2;
    node2 = aux;
}

void BST::remove(int key)
{
    removeRec(key, this->root);
}

bool BST::removeRec(int key, Node *&root)
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
            Node *tmp = root;
            root = root->right;
            delete tmp;
            return true;
        }
        // case where the right child is null
        else if (root->right == nullptr) {
            Node *tmp = root;
            root = root->left;
            delete tmp;
            return true;
        }

        /* the node has both a left and right non-nil sub-tree
           create a node that will have the reference to the inorder successor
           of root */
        Node **minNode = &root->right;

        /* find the inorder successor of root and update the number of left
           subtrees at each step
           (just get the most far node to the left) */
        while ((*minNode)->left != nullptr) {
            (*minNode)->nLeft--;
            minNode = &(*minNode)->left;
        }

        root->key = (*minNode)->key;

        // delete the successor using the pointer to it and set the deleted
        // memory region to null so we know it was deleted
        delete *minNode;
        *minNode = nullptr;

        removed = true;
    }

    return removed;
}

int BST::nthElement(int n)
{
    return nthElementRec(n, this->root);
}

int BST::nthElementRec(int n, Node *root)
{
    if (root == nullptr) return -1;

    int pos = root->nLeft + 1;

    if (n < pos)
        return nthElementRec(n, root->left);
    else if (n > pos)
        return nthElementRec(n - pos, root->right);

    return root->key;
}

int BST::position(int key)
{
    return positionRec(key, this->root, 0);
}

int BST::positionRec(int key, Node *root, int pos)
{
    if (root == nullptr) return -1;

    int currPos = pos + (root->nLeft + 1);

    if (key < root->key)
        return positionRec(key, root->left, pos);
    else if (key > root->key)
        return positionRec(key, root->right, currPos);

    return currPos;
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

bool BST::isPerfect()
{
    if (root == nullptr) return true;

    queue<Node> queue;
    queue.push(*root);

    while (!queue.empty()) {
        Node node = queue.front();
        queue.pop();

        if (node.nLeft != node.nRight)
            return false;
        else if (node.left != nullptr) {
            queue.push(*node.left);
            queue.push(*node.right);
        }
    }

    return true;
}

bool BST::isComplete()
{
    if (root == nullptr) return true;

    int NodesInCurrentDepth = 1;
    int currentNodeOrdering = 0;
    bool nextLevelIsTheLastOne = false;
    bool LastLevel = false;
    queue<Node> queue;

    queue.push(*root);

    while (!queue.empty()) {
        currentNodeOrdering++;

        Node node = queue.front();
        queue.pop();

        if ((node.left != nullptr or node.right != nullptr) and
            (LastLevel == true)) return false;

        if (node.left == nullptr or node.right == nullptr)
            nextLevelIsTheLastOne = true;

        if (node.left != nullptr)
            queue.push(*node.left);

        if (node.right != nullptr)
            queue.push(*node.right);

        if (currentNodeOrdering == NodesInCurrentDepth) {
            NodesInCurrentDepth *= 2;
            currentNodeOrdering = 0;

            if (nextLevelIsTheLastOne == true)
                LastLevel = true;
        }
    }

    return true;
}
