/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 200

char *strip(char *s);

bool is_Atype(const char *line);
bool is_label(const char *line);
bool is_Ctype(const char *line);

void parse(FILE *file);