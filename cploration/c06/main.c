/****************************************
 * C-ploration 6 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/

#include "parser.h"
#include <stdio.h>
#include <string.h>

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

    char line[MAX_LINE_LENGTH]; // Declare line here

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        strip(line);
        char inst_type = ' ';

        if (is_Atype(line)) {
            inst_type = 'A';
        } else if (is_label(line)) {
            inst_type = 'L';
            char label[MAX_LABEL_LENGTH];
            extract_label(line, label);
            strcpy(line, label);
        } else if (is_Ctype(line)) {
            inst_type = 'C';
        }

        if (inst_type != ' ') {
            printf("%c  %s\n", inst_type, line);
        }
    }

    fclose(file);

    return 0;
}

