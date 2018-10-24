#include "../include/io.hpp"

void openInput(ifstream &input, string filename)
{
    input.open(filename);

    if (!input.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }
}

template<typename T>
BST<T> *readTree(string filename)
{
    ifstream treeFile;

    openInput(treeFile, filename);

    BST<T> *newTree = new BST<T>();
    int key;

    while (treeFile >> key) {
        newTree->insert(key);
    }

    return newTree;
}

void readCmds(string filename)
{
    ifstream cmdsFile;

    openInput(cmdsFile, filename);
}

void parseParams(char *argv[], int argc)
{
    if (argc < 2) {
        cerr << " Usage: ./bst <TREE_FILE> <CMDS_FILE>";
        exit(1);
    }

    // readTree(argv[1]);
    // readCmds(argv[2]);
}
