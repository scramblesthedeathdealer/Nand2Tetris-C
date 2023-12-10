/****************************************
 * C-ploration 7 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/

#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Symbol* hashArray[SYMBOL_TABLE_SIZE];

unsigned long symtable_hash(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return (unsigned long)(hash % SYMBOL_TABLE_SIZE);
}

struct Symbol* symtable_find(const char* key) {
    unsigned long hashIndex = symtable_hash(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->name != NULL && strcmp(hashArray[hashIndex]->name, key) == 0)
            return hashArray[hashIndex];
        
        ++hashIndex;
        hashIndex %= SYMBOL_TABLE_SIZE;
    }        
    
    return NULL;        
}

void symtable_insert(const char* key, hack_addr addr) {
    unsigned long hashIndex = symtable_hash(key);

    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {
        ++hashIndex;
        hashIndex %= SYMBOL_TABLE_SIZE;
    }
    
    struct Symbol* item = (struct Symbol*)malloc(sizeof(struct Symbol));
    item->name = strdup(key);
    item->addr = addr;

    hashArray[hashIndex] = item;
}

void symtable_display_table() {
    // NOTE: Remove this function call before submitting to Gradescope
    // This function displays the content of the symbol table (for debugging purposes)

    for (int i = 0; i < SYMBOL_TABLE_SIZE; i++) {
        if (hashArray[i] != NULL && hashArray[i]->name != NULL)
            printf(" (%s, %d)", hashArray[i]->name, hashArray[i]->addr);
        else
            printf(" ~~ ");
    }
    
    printf("\n");
}

void symtable_print_labels() {
    printf("Labels:\n");
    for (int i = 0; i < SYMBOL_TABLE_SIZE; i++) {
        if (hashArray[i] != NULL && hashArray[i]->name != NULL)
            printf("{%s,%d}\n", hashArray[i]->name, hashArray[i]->addr);
    }
}
