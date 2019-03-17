%{
#include "structures.h"
#include "symbol_table.h"
#include "y.tab.h"

table_element *symtab = NULL;
/*typedef struct _t1{
	char name[32];
	basic_type type;
	struct _t1 *next;
} table_element;*/

extern is_program* myprogram;
/* typedef struct _s1 {
    is_vardec_list* vlist;
    is_statement_list* slist;
} is_program; */
%}

ID       [a-z][a-z0-9]*

%%
integer     {return INTEGER;}
double      {return DOUBLE;}
char        {return CHARACTER;}
let         {return LET;}
in          {return IN;}
end         {return END;}
write       {return WRITE;    }
{ID}        {yylval.id = strdup(yytext); return IDENTIFIER;}
[ \t\n]+    /* ignorar espacos em branco e mudancas de linha*/
.           {return yytext[0];}
%%

int main(int argc, char **argv) {
    int errors;

    yyparse();
    return 0;
}



int yywrap(void){
    return 1;
}
/**************************
*****************************/
