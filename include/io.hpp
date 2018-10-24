#ifndef IO_H
#define IO_H

#include "bst.hpp"
#include <fstream>

void openInput(ifstream &input, string filename);

template<typename T>
BST<T> *readTree(string filename);
void parseParams(char *argv[], int argc);
void readCmds(string filename);

#endif /* IO_H */
