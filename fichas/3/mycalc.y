%{
    #include <stdio.h>
    int yylex(void);
    void yyerror (const char *s);
%}

%token NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc '-'

%%

calc: expression                        {printf("%d\n", $1);}

expression: expression '+' expression   {$$=$1+$3;}
    |   expression '-' expression       {$$=$1-$3;}
    |   expression '*' expression       {$$=$1*$3;}
    |   expression '/' expression       {if ($3 == 0) {
											printf("Divide by zero!\n");
										}
											else $$=$1/$3;
										}
	| '-'NUMBER							{$$=-$2;}
    |   NUMBER                          {$$=$1;}
    ;
%%

int main() {
    yyparse();
    return 0;
}

