/****************************************
 * C-ploration 3 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 200

int main(int argc, const char *argv[]) {
    // Check if user provided one argument
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input file
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    // Create the output file name
    char out_file[MAX_LINE_LENGTH];
    strcpy(out_file, argv[1]);
    strcat(out_file, ".echo");

    // Open the output file
    FILE *fout = fopen(out_file, "w+");
    if (fout == NULL) {
        perror("Unable to open output file!");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_num = 0;

    while (fgets(line, sizeof(line), fin)) {
        // Increment line number
        line_num++;

        // Print line number and line text
        fprintf(stdout, "[%04d] %s", line_num, line);

        // Write line to output file
        fprintf(fout, "%s", line);
    }

    // Close file pointers
    fclose(fin);
    fclose(fout);

    return 0;
}
