#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST tree;

    tree.insert(100);
    tree.insert(40);
    tree.insert(150);
    tree.insert(35);
    tree.insert(50);
    tree.insert(120);
    tree.insert(170);
    tree.insert(25);
    tree.insert(45);
    tree.insert(130);

    std::cout << tree.toString() << std::endl;

    std::cout << tree.median() << "\n";

    tree.remove(45);
    tree.remove(170);
    tree.remove(32);

    std::cout << tree.toString() << std::endl;

    int nodes = tree.root->nLeft + tree.root->nRight + 1;

    for (int i = 1; i < nodes + 1; ++i)
        std::cout << tree.nthElement(i) << "\n";

    return 0;
}
