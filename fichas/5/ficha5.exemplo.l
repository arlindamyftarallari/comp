%{
#include "structures.h"
#include "symbol_table.h"
#include "semantics.h"
#include "y.tab.h"

#define LOCATION yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = yycolumn; \
	yylloc.last_column = yycolumn + yyleng - 1; \
	yycolumn += yyleng;

int yycolumn = 1;

table_element *symtab=NULL;

extern is_program* myprogram;
%}

ID       [a-z][a-z0-9]*

%%
integer     {LOCATION; return INTEGER;}
double      {LOCATION; return DOUBLE;}
char        {LOCATION; return CHARACTER;}
let         {LOCATION; return LET;}
in          {LOCATION; return IN;}
end         {LOCATION; return END;}
write       {LOCATION; return WRITE;}
{ID}        {LOCATION; yylval.id = strdup(yytext); return IDENTIFIER;}
[ \t]		{yycolumn+=yyleng;}
\n			{yylineno++; yycolumn=1;}
.           {yycolumn+=yyleng; return yytext[0];}
%%

int main(int argc, char **argv) {
    int errors;

    yyparse();
    errors=check_program(myprogram);
    if(errors>0)
        printf("The program has %d errors!\n", errors);
    show_table();
    yylex_destroy();
    return 0;
}

int yywrap(void){
    return 1;
}
/**************************
*****************************/
