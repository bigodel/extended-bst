#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(21);
    tree.insert(22);
    tree.insert(104);
    tree.insert(2);
    tree.insert(53);
    tree.insert(9);
    tree.insert(72);
    tree.insert(3);
    if (tree.root == nullptr)
        std::cout << "Deu ruim" << "\n";
    std::cout << tree.toString() << std::endl;
  //  tree.nthElement(7);
    for (int i = 1; i <= 10; ++i) {
       std::cout << tree.nthElement(i) << std::endl;
       //tree.nthElement(i);
       std::cout << std::endl;
    }
    return 0;
}
