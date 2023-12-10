/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/
#include "parser.h"

/* Function: strip
 * -------------
 * remove whitespace and comments from a line
 *
 * s: the char* string to strip
 *
 * returns: the stripped char* string
 */
char *strip(char *s) {
    char *s_new = malloc(MAX_LINE_LENGTH);  // Allocate memory for modified string
    if (s_new == NULL) {
        // Handle memory allocation error if needed
        return NULL;
    }

    int i = 0;
    int in_comment = 0;

    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] == '/' && s[j + 1] == '/') {
            in_comment = 1;
            continue;  // Skip rest of line
        }
        if (!isspace((unsigned char)s[j]) && !in_comment) {
            s_new[i++] = s[j];
        }
    }

    s_new[i] = '\0';  // Null-terminate the modified string

    // Copy modified string back to original and free allocated memory
    strcpy(s, s_new);
    free(s_new);

    return s;
}

/* Function: parse
 * -------------
 * iterate each line in the file and strip whitespace and comments. 
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 */
void parse(FILE *file) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        strip(line);
        if (*line) {
            printf("%s\n", line);  // Add a newline character after the line
        }
    }
}
