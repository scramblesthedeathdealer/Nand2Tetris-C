/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/
#include "parser.h"

int main(int argc, const char *argv[]) {		
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;  // Exit with an error code. But there will be no errors.
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;  // Exit with an error code. Why is there an error? There's no errors.
    }

    parse(file);

    fclose(file);

    return 0; 
}


