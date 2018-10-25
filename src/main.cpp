#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST tree;

    tree.insert(100);
    tree.insert(150);
    tree.insert(40);
    tree.insert(35);
    tree.insert(50);
    tree.insert(120);
    tree.insert(170);
    tree.insert(25);
    tree.insert(45);
    tree.insert(130);
    tree.insert(25);
    tree.insert(25);

    std::cout << tree.root->nLeft << "\n";

    std::cout << tree.toString() << std::endl;

    return 0;
}
