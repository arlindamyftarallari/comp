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

extern is_program* my_program_list;
table_element * symtab_list[10];
%}

ID			[a-z][a-z0-9]*

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
	int symtab_index = 0;
	table_element * toclean, *nexttoclean;

    yyparse();

	is_program * aux = my_program_list;

	while (aux != NULL) {
		errors = check_program(aux, symtab_index);
		if (errors > 0) printf("Program %d has %d errors\n", i, errors);
		show_table(symtab_index);
		i++; aux = aux->next; symtab_index++;
	}
	
	//free memory alocated
	for (int i=0; i<10; i++) {
		nexttoclean = symtab_list[i];
		while (nexttoclean != NULL) {
			free(nexttoclean->name);
			toclean = nexttoclean;
			nexttoclean = nexttoclean->next;
			free(toclean);
		}
	}

    yylex_destroy();
    return 0;
}

int yywrap(void){
    return 1;
}