#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST<int> *tree = new BST<int>();

    tree->insert(10);
    tree->insert(20);

    if (tree->root == nullptr)
        std::cout << "Deu ruim" << "\n";

    return 0;
}
