#ifndef IO_H
#define IO_H

#include "bst.hpp"
#include <fstream>

void openInput(ifstream& input, string filename);
void readTree(string filename, BST &tree);
void printTree(BST &tree);
void readCmds(string filename, BST &tree);
void parseParams(int argc, char *argv[], BST &tree);

#endif /* IO_H */
