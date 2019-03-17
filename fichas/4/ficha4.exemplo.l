%{
#include "y.tab.h"
extern int yydebug;
%}

%%
[0-9]+              		{yylval.value = atoi(yytext);
                    		return NUMBER;}

[a-zA-Z][a-zA-Z0-9_]*     	{yylval.id = (char*)strdup(yytext);
                     		return VAR;}  

[ \t]               ; //does nothing for whitespaces
\n|.                return yytext[0];

%%
int yywrap() {
    return 1;
}

void yyerror (char *s)
{
	printf ("%s\n", s);
}

int main()
{
	yydebug = 1;
	yyparse();
	return 0;
}


