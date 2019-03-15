%{
    #include <stdio.h>
    int yylex(void);
    void yyerror (const char *s);
	
	struct entry {
		int value;
		char* name;
	}

	entry * table[100];
	int tablesize = 0;

	entry * lookup(char* name) {
		int i, size = sizeof(table) / sizeof(entry);

		for (i=0; i<size; i++) {
			if (strcmp(table[i]->name, name) == 0) {
				return table[i];
			}
		}

		//se não chegou aqui, é porque a entrada ainda não existe
		entry newentry;
		newentry->name = name;
		return newentry;
	}	
%}

%token NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

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
	| '(' expression ')'				{$$=$2;}										
	| '-' expression %prec UMINUS		{$$=-$2;}
	| expression '=' expression 		{}
    | NUMBER                          	{$$=$1;}
    ;
%%

int main() {
    yyparse();
    return 0;
}

