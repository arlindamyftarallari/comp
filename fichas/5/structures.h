#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"

typedef struct _s9 {
        char* id;
		int line;
		int column;
}is_write_statement;

typedef enum {d_write} disc_write;

typedef struct _s8 {
        disc_write disc_d;
        union{
                is_write_statement* u_write_statement;
        } data_statement;
} is_statement;

typedef struct _s7 {
        is_statement* val;
        struct _s7* next;
} is_statement_list;

typedef struct _s4 {
        char* id;
		int line;
		int column;
} is_integer_dec;

typedef struct _s5 {
        char* id;
		int line;
		int column;
} is_character_dec;

typedef struct _s6 {
        char* id;
		int line;
		int column;
} is_double_dec;

typedef enum {d_integer, d_character, d_double} disc_vardec;

typedef struct _s3 {
        disc_vardec disc_d; //disc_d can be d_integer, d_character or d_double
        union {
			
			/* data vardec can */

                is_integer_dec* u_integer_dec; 
                is_character_dec* u_character_dec;
                is_double_dec* u_double_dec;
        } data_vardec;
} is_vardec;

typedef struct _s2 {
        is_vardec* val;
        struct _s2* next;
} is_vardec_list;

typedef struct _s1 { //node of a linked list of all programs
    is_vardec_list* vlist;
    is_statement_list* slist;
	table_element * symtab;
	struct _s1 * next;
} is_program;

#endif
