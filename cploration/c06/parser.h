/****************************************
 * C-ploration 6 for CS 271
 * 
 * [NAME] $Chris Ogle$
 * [TERM] FALL $2023$
 * 
 ****************************************/
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH - 2)

typedef uint8_t byte;
typedef uint16_t word;
typedef int16_t hack_addr;
typedef int16_t opcode;

enum instr_type {
    INVALID_INSTR = -1,
    A_TYPE_INSTR,
    C_TYPE_INSTR
};

typedef struct c_instruction {
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;
} c_instruction;

typedef struct a_instruction {
    union {
        hack_addr address;
        char *label;
    };
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union {
        a_instruction a_inst;
        c_instruction c_inst;
    };
    enum instr_type type;
} instruction;

char *strip(char *s);
bool is_Atype(const char *line);
bool is_label(const char *line);
bool is_Ctype(const char *line);
char *extract_label(const char *line, char *label);
void parse(FILE *file);

#endif /* PARSER_H_ */
