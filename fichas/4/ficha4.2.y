%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "y.tab.h"

int yylex (void);
void yyerror(char* s);

is_program* myprogram;

%}
// %token <tipo de token> TOKEN -> associar o tipo de valor a cada token
%token INTEGER DOUBLE CHARACTER LET IN END WRITE
%token<id>IDENTIFIER
%type<ip>program
%type<ivl>vardeclist
%type<iv>vardec
%type<isl>statementlist
%type<is>statement

//permite que yylval possa assumir vários tipos de valores (char*, is_program*, is_vardec_list*, is_vardec*, is_statement_list*, is_statement*)
%union{
    char *id;
    is_program* ip;
    is_vardec_list* ivl;
    is_vardec* iv;
    is_statement_list* isl;
    is_statement* is;
}
%%
program: LET vardeclist IN statementlist END
                                        {$$=myprogram=insert_program($2, $4);} 
    ;

vardeclist: /*empty*/                   {$$=NULL;}
    | vardeclist vardec                 {$$=...}
    ;

vardec: INTEGER IDENTIFIER              {$$=...}
    | CHARACTER IDENTIFIER              {$$=...}
    | DOUBLE IDENTIFIER                 {$$=...}
    ;

statementlist: /*empty*/                {$$=...}
    | statementlist statement           {$$=...}
    ;

statement: WRITE IDENTIFIER             {$$=...}
    ;

%%

void yyerror(char *msg) {
    printf("%s", msg);
}

