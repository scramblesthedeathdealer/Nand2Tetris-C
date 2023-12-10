/****************************************
 * C-ploration 7 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 ****************************************/

#include "parser.h"
#include "symtable.h"
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void parse(FILE *file) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        strip(line);

        // Commenting out printf lines
        // printf("%c  %s\n", inst_type, line);

        // Commenting out inst_type variable usage
        // char inst_type = ' ';

        if (is_Atype(line)) {
            // inst_type = 'A';
            // printf("%c  %s\n", inst_type, line);

            // Assuming label is the line without '@'
            char label[MAX_LABEL_LENGTH];
            strncpy(label, line + 1, strlen(line)); // Extracting label
            symtable_insert(label, -1); // Insert label into symtable with address -1
        } else if (is_label(line)) {
            // inst_type = 'L';
            char label[MAX_LABEL_LENGTH];
            extract_label(line, label);
            strcpy(line, label);

            // Insert extracted label into symtable
            symtable_insert(label, -1);
        } else if (is_Ctype(line)) {
            // inst_type = 'C';
        }

        // Commenting out inst_type variable usage
        // if (inst_type != ' ') {
        //     printf("%c  %s\n", inst_type, line);
        // }
    }
}
