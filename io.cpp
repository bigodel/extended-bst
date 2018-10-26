#include "io.hpp"

void openInput(ifstream& input, string filename)
{
    input.open(filename);

    if (!input.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }
}

BST* readTree(string filename)
{
    ifstream treeFile;

    openInput(treeFile, filename);

    BST *newTree = new BST();
    int key;

    while (treeFile >> key) {
        newTree->insert(key);
    }

    return newTree;
}

void printTree(BST* mainTree)
{
    cout << mainTree->toString() << endl;
}

void readCmds(string filename, BST &mainTree)
{
    ifstream cmdsFile;

    openInput(cmdsFile, filename);

    string cmd;
    while (cmdsFile >> cmd) {
        // this is where there is going to be a switch case for the commands
        if (cmd == "ENESIMO") {
            int n;
            cmdsFile >> n;

            cout << "The " << n << "th element of the this tree is "
                 << mainTree.nthElement(n) << "." << endl;
        }
        else if (cmd == "POSICAO") {
            int n;
            cmdsFile >> n;

            cout << "The element at position " << n << " of this tree is "
                 << mainTree.position(n) << "." << endl;
        }
        else if (cmd == "MEDIANA") {
            cout << "The median of this tree is "
                 << mainTree.median() << "." << endl;
        }
        else if (cmd == "CHEIA") {
            if (mainTree.isPerfect())
                cout << "This tree is perfect." << endl;
            else
                cout << "This tree is not perfect." << endl;
        }
        else if (cmd == "COMPLETA") {
            if (mainTree.isComplete())
                cout << "This tree is complete." << endl;
            else
                cout << "This tree is not complete." << endl;
        }
        else if (cmd == "IMPRIMA") {
            cout << "The level traversal of the tree is: ";
            printTree(mainTree);
        }
        else if (cmd == "REMOVA") {
            int n;
            cmdsFile >> n;

            mainTree.remove(n);
            cout << "Removed element " << n << " from the tree." << endl;
        }
        else if (cmd == "INSIRA") {
            int n;
            cmdsFile >> n;

            mainTree.insert(n);
            cout << "Inserted element " << n << " in the tree." << endl;
        }
    }
}

void parseParams(int argc, char* argv[], BST* mainTree)
{
    if (argc < 2) {
        cerr << " Usage: ./bst <TREE_FILE> <CMDS_FILE>" << endl;
        exit(1);
    }

    mainTree = readTree(argv[1]);
    readCmds(argv[2], mainTree);
}
