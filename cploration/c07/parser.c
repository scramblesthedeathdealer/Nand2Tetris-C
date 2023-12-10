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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



char *strip(char *s) {
    // Implementation for strip function
    // Remove leading and trailing whitespaces, comments, etc.
    // Example: Skip implementation for now and return the input string as-is
    return s;
}

bool is_Atype(const char *line) {
    // Implementation for is_Atype function
    // Check if the line represents an A-type instruction
    // Example: Check if the line starts with '@' character
    return (line[0] == '@');
}

bool is_label(const char *line) {
    // Implementation for is_label function
    // Check if the line represents a label
    // Example: Check if the line starts with '(' and ends with ')'
    int length = strlen(line);
    return (length >= 3 && line[0] == '(' && line[length - 1] == ')');
}

bool is_Ctype(const char *line) {
    // Implementation for is_Ctype function
    // Check if the line represents a C-type instruction
    // Example: Check if the line contains '=' or ';'
    int length = strlen(line);
    for (int i = 0; i < length; i++) {
        if (line[i] == '=' || line[i] == ';') {
            return true;
        }
    }
    return false;
}

char *extract_label(const char *line, char *label) {
    // Implementation for extract_label function
    // Extract the label from the line if it represents a label
    // Example: Copy the label from line to label variable
    const char *start = strchr(line, '(');
    if (start != NULL) {
        const char *end = strchr(start, ')');
        if (end != NULL) {
            size_t length = end - start - 1;
            strncpy(label, start + 1, length);
            label[length] = '\0';
            return label;
        }
    }
    return NULL;
}

void parse(FILE *file) {
    // Implementation for parse function
    // Iterate through the file, parse each line, and perform necessary actions
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        strip(line);

        if (is_Atype(line)) {
            // Handle A-type instruction
        } else if (is_label(line)) {
            // Handle label
            char label[MAX_LABEL_LENGTH];
            extract_label(line, label);
            // Process the extracted label
        } else if (is_Ctype(line)) {
            // Handle C-type instruction
        }
    }
}
