#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST tree;

    tree.insert(100);
    tree.insert(150);
    tree.insert(50);
    tree.insert(45);
    tree.insert(120);

    std::cout << tree.root->nRight << "\n";

    std::cout << tree.toString() << std::endl;

    return 0;
}
