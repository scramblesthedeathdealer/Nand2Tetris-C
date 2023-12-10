/****************************************
 * C-ploration 7 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/

#ifndef SYMTABLE_H_
#define SYMTABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SYMBOL_TABLE_SIZE 1000

typedef int16_t hack_addr;

struct Symbol {
    char* name;
    hack_addr addr;
};

unsigned long symtable_hash(const char* str);
struct Symbol* symtable_find(const char* key);
void symtable_insert(const char* key, hack_addr addr);
void symtable_display_table();
void symtable_print_labels();

#endif /* SYMTABLE_H_ */
