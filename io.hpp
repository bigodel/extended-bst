#ifndef IO_H
#define IO_H

#include "bst.hpp"
#include <fstream>

void openInput(ifstream& input, string filename);
BST* readTree(string filename);
void printTree(BST* mainTree);
void readCmds(string filename, BST* mainTree);
void parseParams(int argc, char* argv[], BST* mainTree);

#endif /* IO_H */
