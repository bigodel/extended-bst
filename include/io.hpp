#ifndef IO_H
#define IO_H

#include "bst.hpp"
#include <fstream>
#include <string>

void openInput(ifstream &input, string filename);

template<typename T>
BST<T> *readTree(string filename);
void parseParams(int argc, char *argv[]);
void printTree();
void readCmds(string filename);

#endif /* IO_H */
