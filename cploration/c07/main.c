/****************************************
 * C-ploration 7 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/

#include "parser.h"
#include <stdio.h>
#include <string.h>
#include "symtable.h" // Include symtable.h

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    parse(file);

    // Print labels from the symbol table
    symtable_print_labels();

    fclose(file);

    return 0;
}
