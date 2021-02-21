// This program was created by Aleksandar Kostic on 15 Nov 2018 for a Western University assignment.

#include "data.h"

typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void bstree_insert_helper(BStree bst, Key *key, int data, int position);
void bstree_traversal_helper(BStree bst, int position);