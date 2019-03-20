%{
	/* 
	Hugo Brink 2016227204
	Madalena Santos 2016226726
	*/
	#include <stdio.h>
	#include <string.h>
	int yylex(void);
	int yylex_destroy();
	void yyerror(const char *s);
	int error = 0, printflag = 0;
%}

%union {
	char * string;
	//definir nó da árvore
}

%token SEMICOLON BLANKID PACKAGE RETURN AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ ELSE FOR IF VAR INT FLOAT32 BOOL STRING PRINT PARSEINT FUNC CMDARGS
%token <string> RESERVED STRLIT INTLIT ID REALLIT

%%

Program: PACKAGE ID SEMICOLON 														{;};
Declarations: (VarDeclaration SEMICOLON)* | (FuncDeclaration SEMICOLON)* 			{;};
Type: INT | FLOAT32 | BOOL | STRING													{;};
VarDeclaration: VAR VarSpec															{;};
VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR										{;};
VarSpec: ID (COMMA ID)* Type														{;};
FuncDeclaration: FUNC ID LPAR Parameters+ RPAR Type+ FuncBody						{;};	
Parameters: ID Type (COMMA ID Type)*												{;};
FuncBody: LBRACE VarsAndStatements+ RBRACE											{;};
VarsAndStatements: VarsAndStatements (VarDeclaration | Statement)+ SEMICOLON		{;}
		|;																			{;};
Statement: ID ASSIGN Expr															{;};
Statement: LBRACE (Statement SEMICOLON)* RBRACE 									{;};
Statement: IF Expr LBRACE (Statement SEMICOLON)* RBRACE (ELSE LBRACE (Statement SEMICOLON)* RBRACE)+ 	{;};
Statement: FOR Expr+ LBRACE (Statement SEMICOLON)* RBRACE							{;};
Statement: RETURN Expr+																{;};
Statement: FuncInvocation | ParseArgs												{;};
Statement: PRINT LPAR (Expr | STRLIT) RPAR											{;};
ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR			{;};
FuncInvocation: ID LPAR (Expr (COMMA Expr)*)+ RPAR									{;};
Expr: Expr (OR | AND) Expr															{;};
    | Expr (LT | GT | EQ | NE | LE | GE) Expr										{;};
	| Expr (PLUS | MINUS | STAR | DIV | MOD) Expr									{;};
	| (NOT | MINUS | PLUS) Expr														{;};
	| INTLIT | REALLIT | ID | FuncInvocationn | LPAR Expr RPAR						{;};
%%

int main(int argc, char **argv) {
    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            printflag = 1;
			yylex();
        }

		if (strcmp(argv[1], "-t") == 0) {
			printflag = 0;
			yyparse();
			if (!error) {
				//printtree();
			}
		}
    }

	else {
		printflag = 0;
		yyparse();
	}
	yylex_destroy();
    return 0;
}

void yyerror(const char * s) {
	printf("%s\n", s);
}