#include "../include/bst.hpp"

int main(/*int argc, char *argv[]*/)
{
    BST tree;

<<<<<<< HEAD
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
||||||| merged common ancestors
    tree.insert(10);
    tree.insert(20);
=======
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
>>>>>>> nthElement

    std::cout << tree.toString() << std::endl;
<<<<<<< HEAD

||||||| merged common ancestors
=======

    for (int i = 1; i < 11; ++i)
        std::cout << tree.nthElement(i) << "\n";

>>>>>>> nthElement
    return 0;
}
