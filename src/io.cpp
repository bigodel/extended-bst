#include "../include/io.hpp"

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

void readCmds(string filename, BST* mainTree)
{
    ifstream cmdsFile;

    openInput(cmdsFile, filename);

    string cmd;
    while (cmdsFile >> cmd) {
        // this is where there is going to be a switch case for the commands
        if (cmd == "ENESIMO") {
            int n;
            cmdsFile >> n;

            // here we call the nthElem function from the tree
        }
        else if (cmd == "POSICAO") {
            int n;
            cmdsFile >> n;

            // here we call the position function from the tree
        }
        else if (cmd == "MEDIANA") {
            // here we call the median function from the tree
        }
        else if (cmd == "CHEIA") {
            // here we call the isPerfect function from the tree
        }
        else if (cmd == "COMPLETA") {
            // here we call the isComplete function from the tree
        }
        else if (cmd == "IMPRIMA") {
            // here we call the print function from here
            // TODO: print function
        }
        else if (cmd == "REMOVA") {
            int n;
            cmdsFile >> n;

            // here we call the remove function from the tree
        }
        else if (cmd == "INSIRA") {
            int n;
            cmdsFile >> n;

            // here we call the insert function from the tree
        }
    }
}

void parseParams(int argc, char* argv[], BST* mainTree)
{
    if (argc < 2) {
        cerr << " Usage: ./bst <TREE_FILE> <CMDS_FILE>";
        exit(1);
    }

    mainTree = readTree(argv[1]);
    readCmds(argv[2], mainTree);
}
