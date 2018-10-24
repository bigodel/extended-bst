#ifndef IO_H
#define IO_H

#include "bst.hpp"
#include <fstream>
#include <string>

void openInput(ifstream &input, string filename);
template<typename T>
BST<T> *readTree(string filename);
template<typename T>
void printTree(BST<T> *mainTree);
template<typename T>
void readCmds(string filename, BST<T> *mainTree);
template<typename T>
void parseParams(int argc, char *argv[], BST<T> *mainTree);

#endif /* IO_H */
