#include <stdio.h>
#include "bst.h"

int main(/*int argc, char *argv[]*/)
{
    BST tree = *initBST();

    insert(100, 32, &tree);
    insert(150, 42, &tree);
    insert(50, 5, &tree);
    insert(40, 20, &tree);
    insert(60, 7, &tree);
    insert(120, 17, &tree);
    insert(170, 71, &tree);

    Node *res = search(120, &tree);
    printf("Search's key: %i\nSearch's data: %i\n\n", res->key, res->data);

    printf("Root's key: %i\nRoot's data: %i\n\n",
           tree.root->key, tree.root->data);
    printf("Right's key: %i\nRight's data: %i\n",
           tree.root->right->key, tree.root->right->data);

    return 0;
}
