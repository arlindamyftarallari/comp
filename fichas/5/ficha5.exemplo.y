%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "y.tab.h"

int yylex (void);
void yyerror(char* s);
is_program * my_program_list;

%}

%token INTEGER DOUBLE CHARACTER LET IN END WRITE
%token<id>IDENTIFIER
%type<ip>program
%type<ivl>vardeclist
%type<iv>vardec
%type<isl>statementlist
%type<is>statement

%locations 

%union{
    char *id;
    is_program* ip;
    is_vardec_list* ivl;
    is_vardec* iv;
    is_statement_list* isl;
    is_statement* is;
}
%%

program: program LET vardeclist IN statementlist END	{$$ = my_program_list = insert_program($3, $5);}
	| LET vardeclist IN statementlist END				{$$ = my_program_list = insert_program($2, $4);}
	;

vardeclist: /*empty*/                   {$$=NULL;}
    | vardeclist vardec             	{$$=insert_vardec_list($1,$2);}
    ;

vardec: INTEGER IDENTIFIER              {$$=insert_integer_dec($2, @2.first_line, @2.first_column);}
    | CHARACTER IDENTIFIER              {$$=insert_character_dec($2, @2.first_line, @2.first_column);} 
    | DOUBLE IDENTIFIER                 {$$=insert_double_dec($2, @2.first_line, @2.first_column);} 
    ;

statementlist: /*empty*/                {$$=NULL;}    
    | statementlist statement           {$$=insert_statement_list($1, $2);}
    ;

statement: WRITE IDENTIFIER             {$$=insert_write_statement($2, @2.first_line, @2.first_column);}
    ;

%%

void yyerror(char *msg) {
    printf("%s", msg);
}

