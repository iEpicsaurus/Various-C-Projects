// This program was created by Aleksandar Kostic on 15 Nov 2018 for a Western University assignment.
// This program implements a binary search tree.
// This part of the program contains methods/functions for the key.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// Input: ’in_name’: a string ends with ’\0’
//        ’in_id’: an integer
// Output: a pointer of type pointer to Key,
//         pointing to an allocated memory containing a Key
// Effect: dynamically allocate memory to hold a Key
//         set Key’s id to be in_id
//         dynamically allocate memory for the Key’s name
//         so that name will contain what is in ’in_name’.
// Note:   may use strdup()
Key *key_construct(char *in_name, int in_id) {

    Key *key;

    key = (Key *) malloc(sizeof(Key));
    key->name = strdup(in_name);
    key->id = in_id;

    return key;

}

// Input:  ’key1’ and ’key2’ are two Keys
// Output: if return value < 0, then key1 < key2,
//         if return value = 0, then key1 = key2,
//         if return value > 0, then key1 > key2,
// Note:   use strcmp() to compare key1.name and key2.name
//         if key1.name = key2.name, then compare key1.id with key2.id
int key_comp(Key key1, Key key2) {

    int comparisonResult = strcmp(key1.name, key2.name);

    if (comparisonResult == 0) {

        if (key1.id == key2.id) {

            return 0; // key is the same

        }

        else if (key1.id < key2.id) {

            return -1; // key1 is less than key2

        }

        else {

            return 1; // key1 is larger than key2

        }

    }

    else if (comparisonResult < 0) {

        return -1; // key1 is less than key2

    }

    else {

        return 1; // key1 is larger than key2

    }

}

// Input: ’key’: a pointer to Key
// Effect: ( key->name key->id ) is printed
void print_key(Key *key) {

    printf("%s, %d", key->name, key->id);

}

// Input: ’node’: a node
// Effect: node.key is printed and then the node.data is printed
void print_node(Node node) {

    print_key(node.key);
    printf(" %d\n", node.data);

}