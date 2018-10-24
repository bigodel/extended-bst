#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST tree;

    tree.insert(10);
    tree.insert(20);

    if (tree.root == nullptr)
        std::cout << "Deu ruim" << "\n";
    std::cout << tree.toString() << std::endl;
    return 0;
}
