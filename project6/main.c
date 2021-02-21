// This program was created by Aleksandar Kostic on 15 Nov 2018 for a Western University assignment.
// This program implements a binary search tree.
// This part of the program contains the main method which allows for user input.

#include <stdio.h>
#include "bst.h"

int main(void) {

    BStree bst;
    char string[500];
    int id, data, size;

    printf("Enter an integer for the size of the tree: ");
    scanf("%d", &size);
    bst = bstree_ini(size);

    printf("Enter a string, integer, and an integer: ");
    while (scanf("%s %d %d", string, &id, &data) == 3) { // will continue to insert into the tree until invalid input

        bstree_insert(bst, key_construct(string, id), data);

    }

    bstree_traversal(bst);

    bstree_free(bst);

    return 0;

}
