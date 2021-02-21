// This program was created by Aleksandar Kostic on 15 Nov 2018 for a Western University assignment.
// This program implements a binary search tree.
// This part of the program contains methods/functions for the binary search tree.

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
//         i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
//         allocate memory for a Node array of size+1 for member tree_nodes
//         allocate memory for an unsigned char array of size+1 for member is_free
//         set all entries of is_free to 1
//         set member size to ’size’;
BStree bstree_ini(int size) {

    BStree_struct * newTree = (BStree_struct *) malloc(sizeof(BStree_struct));

    newTree->tree_nodes = (Node *) malloc((size + 1) * sizeof(Node));
    newTree->is_free = (unsigned char *) malloc((size + 1) * sizeof(unsigned char));

    for (int i = 1; i <= size; i++) { // initialization of is_free for all to 1

        newTree->is_free[i] = 1;

    }

    newTree->size = size;
    return newTree;

}

// Input: ’bst’: a binary search tree
//        ’key’: a pointer to Key
//        ’data’: an integer
//        'position': a position in the tree
// Effect: ’data’ with ’key’ is inserted into ’bst’
//         if ’key’ is already in ’bst’, do nothing
void bstree_insert_helper(BStree bst, Key *key, int data, int position) {

    if (position > (bst->size)) { // this case is when the position would exceed the array bounds

        printf("Node has not been inserted: out of bounds exception.");
        exit(EXIT_FAILURE);

    }

    if (bst->is_free[position]) { // if nothing is in this spot in array, we can put in node here

        bst->tree_nodes[position].key = key;
        bst->tree_nodes[position].data = data;
        bst->is_free[position] = 0;

    }

    else {

        int result = key_comp(*key, *(bst->tree_nodes[position].key)); // compares the keys

        if (result < 0) { // key want to insert is less, go to index of left child

            bstree_insert_helper(bst, key, data, (2 * position));

        }

        else if (result > 0) { // key want to insert is greater, go to index of right child

            bstree_insert_helper(bst, key, data, (2 * position + 1));

        }

        else { // key already exists in the tree; duplicates not allowed. Does not add.

            return;

        }

    }
}

// Input: ’bst’: a binary search tree
//        ’key’: a pointer to Key
//        ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
//         if ’key’ is already in ’bst’, do nothing
//         uses helper function bstree_insert_helper to insert into the tree
void bstree_insert(BStree bst, Key *key, int data) {

    bstree_insert_helper(bst, key, data, 1); // passes parameters provided into a helper function
                                             // helper function keeps track of position; initial is root (1)

}

// Input: 'bst': a binary search tree
//        'position': a position in the tree
// Effect: print all the nodes in vst using inorder traversal
void bstree_traversal_helper(BStree bst, int position) {

    if (position > bst->size) { // ensures traversal does not exceed size of array

        return;

    }

    if (!bst->is_free[2 * position]) { // all if statements are used to ensure we are only printing what is needed

        bstree_traversal_helper(bst, (position * 2)); // traversal of left subtree

    }

    if (!bst->is_free[position]) {

        print_node(bst->tree_nodes[position]); // prints node

    }

    if (!bst->is_free[(2 * position) + 1]) {

        bstree_traversal_helper(bst, (position * 2 + 1)); // traversal of right subtree

    }

}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {

    bstree_traversal_helper(bst, 1); // passes parameters provided into a helper function
                                     // helper function keeps track of position; initial is root (1)

}

// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) {

    free(bst->tree_nodes);
    free(bst->is_free);
    free(bst);

}