#include "bst.hpp"
#include "io.hpp"

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

    printTree(&tree);

    std::cout << tree.median() << "\n";

    // TODO: test if the nLeft and nRight are ok
    tree.remove(45);
    tree.remove(150);
    tree.remove(32);
    tree.remove(120);
    tree.remove(45);

    printTree(&tree);

    int nodes = tree.root->nLeft + tree.root->nRight + 1;

    for (int i = 1; i < nodes + 1; ++i)
        std::cout << tree.nthElement(i) << "\n";
    BST PerfectTree;
    PerfectTree.insert(40);
    PerfectTree.insert(20);
    PerfectTree.insert(30);
    PerfectTree.insert(10);
    PerfectTree.insert(60);
    PerfectTree.insert(50);
  //  PerfectTree.insert(70);
    
    std::cout << "Perfect tree test" << PerfectTree.toString() << std::endl;
    std::cout << "Is the tree Perfect?" << PerfectTree.isPerfect() << "\n";
    std::cout << "Is the tree Complete?" << PerfectTree.isComplete() << "\n";
    return 0;
}
