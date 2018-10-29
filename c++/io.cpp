#include "io.hpp"

void openInput(ifstream& input, string filename)
{
    input.open(filename);

    if (!input.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }
}

void readTree(string filename, BST &tree)
{
    ifstream treeFile;

    openInput(treeFile, filename);

    int key;

    while (treeFile >> key) {
        tree.insert(key);
    }
}

void printTree(BST &tree)
{
    cout << tree.toString() << endl;
}

void readCmds(string filename, BST &tree)
{
    ifstream cmdsFile;

    openInput(cmdsFile, filename);

    string cmd;
    while (cmdsFile >> cmd) {
        if (cmd == "ENESIMO") {
            int n;
            cmdsFile >> n;

            if (tree.nthElement(n) == -1)
                cout << "Index " << n << " out of bounds." << endl;
            else
                cout << "The " << n << "th element of the tree is "
                     << tree.nthElement(n) << "." << endl;
        }
        else if (cmd == "POSICAO") {
            int n;
            cmdsFile >> n;

            if (tree.position(n) == -1)
                cout << "No such element, " << n << "." << endl;
            else
                cout << "The element " << n << " is at position "
                     << tree.position(n) << "." << endl;
        }
        else if (cmd == "MEDIANA") {
            cout << "The median of this tree is "
                 << tree.median() << "." << endl;
        }
        else if (cmd == "CHEIA") {
            if (tree.isPerfect())
                cout << "This tree is perfect." << endl;
            else
                cout << "This tree is not perfect." << endl;
        }
        else if (cmd == "COMPLETA") {
            if (tree.isComplete())
                cout << "This tree is complete." << endl;
            else
                cout << "This tree is not complete." << endl;
        }
        else if (cmd == "IMPRIMA") {
            cout << "The level traversal of the tree is: ";
            printTree(tree);
        }
        else if (cmd == "REMOVA") {
            int n;
            cmdsFile >> n;

            tree.remove(n);
            cout << "Removed element " << n << " from the tree." << endl;
        }
        else if (cmd == "INSIRA") {
            int n;
            cmdsFile >> n;

            tree.insert(n);
            cout << "Inserted element " << n << " in the tree." << endl;
        }
    }
}

void parseParams(int argc, char *argv[], BST &tree)
{
    if (argc < 2) {
        cerr << " Usage: ./bst <TREE_FILE> <CMDS_FILE>" << endl;
        exit(1);
    }

    readTree(argv[1], tree);
    cout << "Finished creating the tree." << endl;

    readCmds(argv[2], tree);
    cout << "Finished parsing the commands." << endl;
}
