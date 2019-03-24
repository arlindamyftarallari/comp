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

%left LPAR RPAR LSQ RSQ
%right NOT
%left STAR DIV MOD
%left PLUS MINUS
%left GE GT LE LT
%left EQ NE
%left AND
%left OR
%right ASSIGN
%left UNARY

%%

Program: PACKAGE ID SEMICOLON Declarations														
;

Declarations: VarDeclaration SEMICOLON Declarations 
	| FuncDeclaration SEMICOLON Declarations									
	|																				
	;

Type: INT 																			
	| FLOAT32 																		
	| BOOL 																			
	| STRING																		
	;

VarDeclaration: VAR VarSpec
	| VAR LPAR VarSpec SEMICOLON RPAR
	;

VarSpec: ID Aux1 Type																
;

Aux1: COMMA ID Aux1																	
	|
	;

FuncDeclaration: FUNC ID LPAR ParametersOpt RPAR TypeOpt FuncBody
	;

ParametersOpt: Parameters
	|
	;

TypeOpt: Type
	|
	;

Parameters: ID Type Aux2															
;

Aux2: COMMA ID Type																	
	|																				
	;

FuncBody: LBRACE VarsAndStatements RBRACE																										
	;

VarsAndStatements: VarsAndStatements Aux7 SEMICOLON	
	|																												
	;

Aux7: VarDeclaration
	| Statement
	|
	;

Statement: ID ASSIGN Expr															
	| LBRACE Aux3 RBRACE
	| IF Expr LBRACE Aux3 RBRACE Aux4
	| FOR ExprOpt LBRACE Aux3 RBRACE
	| RETURN ExprOpt
	| FuncInvocation
	| ParseArgs
	| PRINT LPAR Aux6 RPAR
	| error
	;

Aux6: STRLIT
	| Expr
	;

ExprOpt: Expr
	|
	;

Aux3: Statement SEMICOLON Aux3														
	|																				
	;

Aux4: ELSE LBRACE Aux3 RBRACE														
	|																				;

ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR			
	| ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR
	;

FuncInvocation: ID LPAR Aux40 RPAR
	;

Aux40: Expr Aux41																	
	| error
	|
	;

Aux41: COMMA Expr Aux41																
	|																				
	;

Expr: INTLIT 																		
	| REALLIT 																		
	| ID 																			
	| FuncInvocation 																
	| LPAR Expr RPAR
	| LPAR error RPAR
	| NOT Expr																		
	| MINUS Expr %prec UNARY																	
	| PLUS Expr %prec UNARY														
	| Expr Aux8 Expr																															
	;

Aux8: PLUS																			
	| MINUS																			
	| STAR 																			
	| DIV 																			
	| MOD 
	| OR																			
	| AND	
	| LT																			
	| GT																			
	| EQ																			
	| NE																			
	| LE																			
	| GE																			
	;

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