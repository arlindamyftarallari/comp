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

Declarations: VarDeclaration SEMICOLON Declarations 
	| FuncDeclaration SEMICOLON Declarations										{;}
	|																				{;};

Type: INT 																			{;}
	| FLOAT32 																		{;}
	| BOOL 																			{;}
	| STRING																		{;};

VarDeclaration: VAR VarSpec															{;};
	| VAR LPAR VarSpec SEMICOLON RPAR												{;};

VarSpec: ID Aux1 Type																{;};

Aux1: COMMA ID Aux1																	{;}
	|																				{;};

FuncDeclaration: FUNC ID LPAR Parameters RPAR Type FuncBody							{;}
	| FUNC ID LPAR Parameters RPAR FuncBody											{;}
	| FUNC ID LPAR RPAR Type FuncBody												{;}
	| FUNC ID LPAR RPAR FuncBody													{;};

Parameters: ID Type Aux2															{;};

Aux2: COMMA ID Type																	{;}
	|																				{;};

FuncBody: LBRACE VarsAndStatements RBRACE											{;}
	| LBRACE RBRACE																	{;};

VarsAndStatements: VarsAndStatements SEMICOLON										{;}
	| VarsAndStatements VarDeclaration SEMICOLON									{;}
	| VarsAndStatements Statement SEMICOLON											{;}
	|																				{;};

Statement: ID ASSIGN Expr															{;}
	| LBRACE Aux3 RBRACE 															{;}
	| IF Expr LBRACE Aux3 RBRACE Aux4												{;}
	| FOR Expr LBRACE Aux3 RBRACE 													{;}
	| FOR LBRACE Aux3 RBRACE														{;}
	| RETURN Aux6																	{;}
	| FuncInvocation 																{;}
	| ParseArgs																		{;}
	| PRINT LPAR STRLIT RPAR														{;}
	| PRINT LPAR Expr RPAR															{;};

Aux6: Expr																			{;}
	|																				{;};

Aux3: Statement SEMICOLON															{;}
	|																				{;};

Aux4: ELSE LBRACE Aux3 RBRACE														{;}
	|																				{;};

ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR			{;};

FuncInvocation: ID LPAR Aux40 RPAR													{;};
Aux40: Expr Aux41																	{;}
	|																				{;};

Aux41: COMMA Expr Aux41																{;}
	|																				{;};

Expr: INTLIT 																		{;}
	| REALLIT 																		{;}
	| ID 																			{;}
	| FuncInvocation 																{;}
	| LPAR Expr RPAR																{;}
	| NOT Expr																		{;}
	| MINUS Expr																	{;}
	| PLUS Expr																		{;}
	| Expr Aux5 Expr																{;}
	| Expr Aux42 Expr																{;}
	| Expr Aux43 Expr																{;};

Aux5: PLUS																			{;}
	| MINUS																			{;}
	| STAR 																			{;}
	| DIV 																			{;}
	| MOD 																			{;};

Aux42: OR																			{;}
	| AND																			{;};

Aux43: LT																			{;}
	| GT																			{;}
	| EQ																			{;}
	| NE																			{;}
	| LE																			{;}
	| GE																			{;};

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