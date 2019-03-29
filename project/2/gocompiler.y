%{
	/* 
	Hugo Brink 2016227204
	Madalena Santos 2016226726
	*/

	#include <stdio.h>
	#include <string.h>
	#include "structures.h"

	#define YYDEBUG 1

	struct node * root = NULL;
	int yylex(void);
	int yylex_destroy();
	void yyerror(const char *s);
	int errortag = 0, printflag = 0;
%}

%union {
	char * string;
	struct node * node;
}

%token error SEMICOLON BLANKID PACKAGE RETURN AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ ELSE FOR IF VAR INT FLOAT32 BOOL STRING PRINT PARSEINT FUNC CMDARGS
%token <string> RESERVED STRLIT INTLIT ID REALLIT
 
%type <node> Program FuncDeclaration Declarations Parameters Expr VarDeclaration ParametersOpt FuncBody Type INT BOOL STRING VarSpec TypeOpt FuncInvocation CallParams OptCallParams IdOpt varsAndStatementsOpt VarsAndStatements OptParam StatementOpt
%type <node> Statement ElseOpt ExprOpt ParseArgs printArgs

%right ASSIGN
%left OR AND
%left EQ NE
%left GE GT LE LT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT UNARY
%left LPAR RPAR LSQ RSQ

%%

Program: PACKAGE ID SEMICOLON Declarations			 				{
																		root = create_node("Program", "");
																		if ($4 != NULL) add_child(root, $4);
																		$$ = root;
																	}
	;

Declarations: VarDeclaration SEMICOLON Declarations					{
																		if ($3 != NULL) {
																			add_sibling($1, $3);
																		}
																		$$ = $1;

																	}
	| FuncDeclaration SEMICOLON Declarations						{
																		if ($3 != NULL) {
																			add_sibling($1, $3);
																		}
																		$$ = $1;
																	}
	|																{ $$ = NULL; }
	;

Type: INT															{
																		$$ = create_node("Int", "");
																	}
	| FLOAT32														{
																		$$ = create_node("Float32", "");
																	}
	| BOOL															{
																		$$ = create_node("Bool", "");
																	}
	| STRING														{
																		$$ = create_node("String", "");
																	}
	;

VarDeclaration: VAR VarSpec											{
																		$$ = $2;
																	}
	| VAR LPAR VarSpec SEMICOLON RPAR								{
																		$$ = $3;
																	}
	;

VarSpec: ID IdOpt Type												{
																		struct node * varDecl = create_node("VarDecl", "");
																		add_child(varDecl, $3);
																		add_child(varDecl, create_node("Id", $1));
																		
																		struct node * newId = $2;
																		struct node * varDecls[100];
																		struct node * ids[100];
																		int i=0;
																		int k=0;

																		//puts all Ids inside array
																		while (newId != NULL) {
																			ids[k] = newId;
																			newId = newId->bro;
																			k++;
																		}

																		newId = $2;
																		struct node * aux;

																		//destroys bro connections between Ids
																		if (newId->bro != NULL) {
																			while(newId != NULL) {
																				aux = newId->bro;
																				newId->bro = NULL;
																				newId = aux;
																			}
 																		}

																		struct node * auxType;

																		//creates a new VarDecl node for each Id received from the IdOpt
																		for (int n=0; n<k; n++) { //iterates ids array
																			varDecls[n] = create_node("VarDecl", "");
																			auxType = create_node($3->type, "");
																			add_child(varDecls[n], auxType);
																			add_child(varDecls[n], ids[n]);
																			i++;
																		}
																		
																		if (i>=1) add_sibling(varDecl, varDecls[0]);

																		for (int j=0; j+1<i; j++) {
																			add_sibling(varDecls[j], varDecls[j+1]);
																		}

																		$$ = varDecl;	
																	}
	;

IdOpt: COMMA ID IdOpt
																	{
																		struct node * id = create_node("Id", $2);
																		if ($3 == NULL) {
																			$$ = id;
																		}
																		else {
																			$$ = add_sibling(id, $3);
																		}
																	}
	|																{$$ = NULL;}
	;

FuncDeclaration: FUNC ID LPAR ParametersOpt RPAR TypeOpt FuncBody	{
																		struct node * funcDecl = create_node("FuncDecl", "");
																		struct node * funcHeader = create_node("FuncHeader", "");
																		add_child(funcHeader, create_node("Id", $2));
																		if ($6 != NULL) add_child(funcHeader, $6);
																		add_child(funcHeader, $4);
																		add_child(funcDecl, funcHeader);
																		add_child(funcDecl, $7);
																		$$ = funcDecl;
																	}
	;

ParametersOpt: Parameters											{
																		$$ = $1;
																	}
	|																{
																		$$ = create_node("FuncParams", "");
																		//this node is not going to have any sons, but it is mandatory
																	}
	;

TypeOpt: Type														{
																		$$ = $1;
																	}
	|																{
																		$$ = NULL;
																	}
	;

Parameters: ID Type OptParam										{
																		struct node * funcParams = create_node("FuncParams", "");
																		struct node * paramDecl = create_node("ParamDecl", "");
																		add_child(paramDecl, $2);
																		add_child(paramDecl, create_node("Id", $1));
																		add_child(funcParams, paramDecl);

																		if ($3 != NULL) {
																			add_child(funcParams, $3);
																		}

																		$$ = funcParams;
																	}
	;

OptParam: COMMA ID Type OptParam									{
																		struct node * paramDecl = create_node("ParamDecl", "");
																		add_child(paramDecl, $3);
																		$$ = add_child(paramDecl, create_node("Id", $2));
																		if ($4 != NULL) add_child(paramDecl, $4);
																	}
	|																{
																		$$ = NULL;
																	}
	;

FuncBody: LBRACE VarsAndStatements RBRACE							{
																		struct node* funcBody = create_node("FuncBody", "");
																		if ($2 != NULL) add_child(funcBody, $2);
																		$$ = funcBody;
																	}
	;

VarsAndStatements: varsAndStatementsOpt SEMICOLON VarsAndStatements 	{
																			if ($3 == NULL && $1 == NULL) $$ = NULL;
																			else if ($1 == NULL) $$ = $3;
																			else if ($3 == NULL) $$ = $1;
																			else $$ = add_sibling($1, $3);
																		
																		}
	|																{
																		$$ = NULL;
																	}
	;	

varsAndStatementsOpt: VarDeclaration								{
																		$$ = $1;
																	}
	| Statement														{
																		$$ = $1;
																	}
	|																{$$ = NULL;}
	;

Statement: ID ASSIGN Expr											{
																		struct node * assign = create_node("Assign", "");
																		add_child(assign, create_node("Id", $1));
																		$$ = add_child(assign, $3);
																	}
	| LBRACE StatementOpt RBRACE									{
																		if ($2 != NULL && $2->bro != NULL) { //creating block for multiple statements
																			struct node * block = create_node("Block", "");
																			if ($2 != NULL) add_child(block, $2);
																			$$ = block;
																		}
																		else { //there is only 1 statement -> no need for block
																			$$ = $2;
																		}
																	}
	| IF Expr LBRACE StatementOpt RBRACE ElseOpt								{
																		struct node * iff = create_node("If", "");
																		add_child(iff, $2);
																		struct node * block = create_node("Block", "");
																		if ($4 != NULL) add_child(block, $4);	
																		add_child(iff, block);
																		$$ = add_child(iff, $6);
																	}
	| FOR ExprOpt LBRACE StatementOpt RBRACE						{
																		struct node * forr = create_node("For", "");
																		if ($2 != NULL) add_child(forr, $2);
																		struct node * block = create_node("Block", "");
																		if ($4 != NULL) add_child(block, $4);
																		$$ = add_child(forr, block);


																	}
	| RETURN ExprOpt												{
																		struct node * returnn = create_node("Return", "");
																		if ($2 != NULL) add_child(returnn, $2);
																		$$ = returnn;
																	}
	| FuncInvocation												{
																		$$ = $1;
																	}
	| ParseArgs														{
																		$$ = $1;
																	}
	| PRINT LPAR printArgs RPAR											{
																		struct node * print = create_node("Print", "");
																		$$ = add_child(print, $3);
																	}
	| error															{
																		$$ = NULL;
																		errortag = 1;
																	}
	;

printArgs: STRLIT													{
																		$$ = create_node("StrLit", $1);
																	}
	| Expr															{
																		$$ = $1;
																	}
	;

ExprOpt: Expr														{
																		$$ = $1;
																	}
	|																{ $$ = NULL; }
	;

StatementOpt: Statement SEMICOLON StatementOpt						{
																		if ($3 != NULL) add_sibling($1, $3);
																		$$ = $1;
																	}
	|																{ $$ = NULL; }
	;

ElseOpt: ELSE LBRACE StatementOpt RBRACE								{
																		struct node * block = create_node("Block", "");
																		if ($3 != NULL) add_child(block, $3);
																		$$ = block;

																	}
	|																{$$ = create_node("Block", "");}
	;

ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR	{
																				struct node * parseArgs = create_node("ParseArgs", "");
																				add_child(parseArgs, create_node("Id", $1));
																				$$ = add_child(parseArgs, $9);
																			}
	| ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR				{
																		$$ = NULL;
																		errortag = 1;
																	}
	;

FuncInvocation: ID LPAR CallParams RPAR									{
																		struct node * call = create_node("Call", "");
																		add_child(call, create_node("Id", $1));
																		if ($3 != NULL) add_child(call, $3);
																		$$ = call;
																	}
	| ID LPAR error RPAR											{
																		$$ = NULL;
																		errortag = 1;
																	}
	;

CallParams: Expr OptCallParams										{	
																		if ($2 == NULL) {
																			$$ = $1;
																		}
																		else {
																			$$ = add_sibling($1, $2);
																		}
																	}
	|																{$$ = NULL;}
	;

OptCallParams: COMMA Expr OptCallParams								{
																		if ($3 == NULL) {
																			$$ = $2;
																		} else {
																			$$ = add_sibling($2, $3);
																		}	
																	}
	|																{
																		$$ = NULL;
																	}
	;

Expr: LPAR Expr RPAR												{
																		$$ = $2;
																	}
	| LPAR error RPAR												{
																		$$ = NULL;
																		errortag = 1;
																	}
	| NOT Expr														{	
																		$$ = add_child(create_node("Not", ""), $2);
																	}
	| MINUS Expr %prec UNARY										{
																		$$ = add_child(create_node("Minus", ""), $2);
																	}
	| PLUS Expr %prec UNARY											{
																		$$ = add_child(create_node("Plus", ""), $2);
																	}
	| Expr PLUS Expr												{
																		struct node * add = create_node("Add", "");
																		add_child(add, $1);
																		$$ = add_child(add, $3);
																	}
	| Expr MINUS Expr												{	
																		struct node * sub = create_node("Sub", "");
																		add_child(sub, $1);
																		$$ = add_child(sub, $3);
																	}
	| Expr STAR Expr												{
																		struct node * mul = create_node("Mul", "");
																		add_child(mul, $1);
																		$$ = add_child(mul, $3);
																	}
	| Expr DIV Expr													{
																		struct node * div = create_node("Div", "");
																		add_child(div, $1);
																		$$ = add_child(div, $3);
																	}
	| Expr MOD Expr													{
																			struct node * mod = create_node("Mod", "");
																		add_child(mod, $1);
																		$$ = add_child(mod, $3);
																	}
	| Expr OR Expr													{
																		struct node * or = create_node("Or", "");
																		add_child(or, $1);
																		$$ = add_child(or, $3);
																	}
	| Expr AND Expr													{
																		struct node * and = create_node("And", "");
																		add_child(and, $1);
																		$$ = add_child(and, $3);
																	}
	| Expr LT Expr													{
																		struct node * lt = create_node("Lt", "");
																		add_child(lt, $1);
																		$$ = add_child(lt, $3);
																	}
	| Expr GT Expr													{
																		struct node * gt = create_node("Gt", "");
																		add_child(gt, $1);
																		$$ = add_child(gt, $3);
																	}
	| Expr EQ Expr													{
																		struct node * eq = create_node("Eq", "");
																			add_child(eq, $1);
																		$$ = add_child(eq, $3);
																	}
	| Expr NE Expr													{
																		struct node * ne = create_node("Ne", "");
																		add_child(ne, $1);
																		$$ = add_child(ne, $3);
																	}
	| Expr LE Expr													{
																		struct node * le = create_node("Le", "");
																		add_child(le, $1);
																		$$ = add_child(le, $3);
																	}
	| Expr GE Expr													{
																		struct node * ge = create_node("Ge", "");
																		add_child(ge, $1);
																		$$ = add_child(ge, $3);
																	}
	| INTLIT														{
																		$$ = create_node("IntLit", $1);
																	}
	| REALLIT														{
																		$$ = create_node("RealLit", $1);
																	}
	| ID															{
																		$$ = create_node("Id", $1);
																	}
	| FuncInvocation												{
																		$$ = $1;
																	}
	;	

%%

int main(int argc, char **argv) {
	yydebug = 0;
	errortag = 0;

    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            printflag = 1;
			yylex();
        }

		if (strcmp(argv[1], "-t") == 0) {
			printflag = 0;
			yyparse();
			if (!errortag) {
				print_node(root, 0);
			}
		}

		if (strcmp(argv[1], "-debug") == 0) {
			yydebug = 1;
			printflag = 0;
			yyparse();
		}
    }

	else {
		printflag = 0;
		yyparse();
	}
	yylex_destroy();
    return 0;
}

