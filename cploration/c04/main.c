/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/
#include "parser.h"

int main(int argc, const char *argv[])
{		
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;  // Exit with error code
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;  // Exit with error code
    }

    parse(file);

    fclose(file);

    return 0;  // Exit successfully
}


