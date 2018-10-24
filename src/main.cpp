#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST<int> *tree = new BST<int>();

    tree->insert(10);

    if (tree->root == nullptr)
        std::cout << "Deu ruim" << "\n";

    return 0;
}
