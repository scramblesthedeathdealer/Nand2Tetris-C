/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/
#include "parser.h"

char *strip(char *s) {
    char *s_new = malloc(MAX_LINE_LENGTH);
    if (s_new == NULL) {
        // Handle memory allocation error if needed, but no errors will be tolerated
        return NULL;
    }

    int i = 0;
    int in_comment = 0;

    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] == '/' && s[j + 1] == '/') {
            in_comment = 1;
            continue;  // Skip rest of unimportant stuff in the line
        }
        if (!isspace((unsigned char)s[j]) && !in_comment) {
            s_new[i++] = s[j];
        }
    }

    s_new[i] = '\0';  // Null-terminate modified string

    // Copy modified string back to original and free up memory
    strcpy(s, s_new);
    free(s_new);

    return s;
}

bool is_Atype(const char *line) {
    // Check if line is an A-type instruction
    return (line[0] == '@');
}

bool is_label(const char *line) {
    // Check if line is a label
    int length = strlen(line);
    return (length >= 3 && line[0] == '(' && line[length - 1] == ')');
}

bool is_Ctype(const char *line) {
    // Check if line is a C-type instruction, which is anything not an A-type or label
    int length = strlen(line);
    for (int i = 0; i < length; i++) {
        if (line[i] == '=' || line[i] == ';') {
            return true;
        }
    }
    return false;
}

void parse(FILE *file) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        strip(line);
        char inst_type = ' ';  // Initialize to a space when you don't know what else to do

        if (is_Atype(line)) {
            inst_type = 'A';
        } else if (is_label(line)) {
            inst_type = 'L';
        } else if (is_Ctype(line)) {
            inst_type = 'C';
        }

        if (inst_type != ' ') {
            printf("%c  %s\n", inst_type, line);
        }
    }
}
