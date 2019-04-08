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

extern is_program* my_program_list;
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
	int i=0;

    yyparse();

	is_program * aux = my_program_list;

	if (aux != NULL) { //there is at least one program
		
		errors = check_program(aux);
		if (errors>0) printf("Program %d has %d errors\n", i, errors);
		show_table(aux->symtab);

		while (aux->next != NULL) { //there is more than one program
			i++;
			errors = check_program(aux->next);
			if (errors > 0) printf("Program %d has %d errors\n", i, errors);
			show_table(aux->next->symtab);
			aux = aux->next;
		}

	}
	
    yylex_destroy();
    return 0;
}

int yywrap(void){
    return 1;
}
/**************************
*****************************/
