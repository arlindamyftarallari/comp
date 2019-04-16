%{
	/* 
	Hugo Brink 2016227204
	Madalena Santos 2016226726
	*/
    #define LINE yylineno ++; yycolumn = 1;

	//location is used each time a token is read; different actions are taken when treating strlits and comments
	#define LOCATION yylloc.first_line = yylloc.last_line = yylineno; \
		yylloc.first_column = yycolumn; \
		yylloc.last_column = yycolumn + yyleng - 1; \
		yycolumn += yyleng;

	#include "y.tab.h"
    int line = 1, column = 1, errorflag = 0, errorline, errorcol;
	int yycolumn = 1; //variable used to store column number for tokens

	extern int errortag;
    int printflag; // 0 = print errors only, 1 = print tokens
	int parse_error = 0; //if there is no error, prints tree

	int handle_token(char * type, char * value);
	int return_token(int token);
    char result[100] = "";

	extern int yydebug;
	int aux;
%}

%x COMMENT SEMICOLON_STATE STRINGLIT COMMENT_SEMICOLON

reserved			break|default|interface|select|case|defer|go|map|struct|chan|goto|switch|const|fallthrough|range|type|continue|import|"++"|"--"

letter				[A-Za-z_]
decimal_digit		[0-9]
octal_digit			[0-7]
hex_digit			[0-9A-Fa-f]
decimal_lit 		{decimal_digit}{decimal_digit}*
octal_lit			0{octal_digit}+
hex_lit				0[xX]{hex_digit}+
decimals			{decimal_digit}+
exponent            [eE][+-]?{decimal_digit}+
escape              \\n|\\f|\\r|\\\\|\\\"|\\t


id					{letter}({letter}|{decimal_digit})*
int_lit				{decimal_lit}|{octal_lit}|{hex_lit}
real_lit			{decimals}"."{decimals}?{exponent}?|{decimals}{exponent}|"."{decimals}{exponent}?
stringlit 			([^\n\r\\\"]|{escape})*	

commentstart        "/*"
commentend          "*/"
singlelinecomment   "//"

carriagereturn      "\r"
lineterminator      "\n"|"\r\n"
whitespace          " "|"\t"

%%

{reserved}				{
							parse_error=0; 
							LOCATION; 
							yylval.string = yytext;
							if (!handle_token("RESERVED", "")) return RESERVED;
						}

";"						{
							parse_error=0; 
							LOCATION; 
							if (!handle_token("SEMICOLON", "")) return SEMICOLON;
						}
"_"						{
							parse_error=0; 
							LOCATION; 
							if (!handle_token("BLANKID", "")) return BLANKID; 
						}
package					{
							parse_error=0;
							LOCATION;
							if (!handle_token("PACKAGE", "")) return PACKAGE;
						}
return					{
							parse_error=0;
							LOCATION;
							BEGIN SEMICOLON_STATE;
							if (!handle_token("RETURN", "")) return RETURN;
						}
"&&"					{
							parse_error=0;
							LOCATION;
							if (!handle_token("AND", "")) return AND;
						}
"="						{
							parse_error=0;
							LOCATION;
							if (!handle_token("ASSIGN", "")) return ASSIGN;
						}
"*"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("STAR", "")) return STAR;
						}
","						{
							parse_error=0;
							LOCATION;
							if (!handle_token("COMMA", "")) return COMMA;
						}
"/"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("DIV", "")) return DIV;
						}
"=="					{
							parse_error=0;
							LOCATION;
							if (!handle_token("EQ", "")) return EQ;
						}
">="					{
							parse_error=0;
							LOCATION;
							if (!handle_token("GE", "")) return GE;
						}
">"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("GT", "")) return GT;
						}
"{"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("LBRACE", "")) return LBRACE;
						}
"<="					{
							parse_error=0;
							LOCATION;
							if (!handle_token("LE", "")) return LE;
						}
"("						{
							parse_error=0;
							LOCATION;
							if (!handle_token("LPAR", "")) return LPAR;
						}
"["						{
							parse_error=0;
							LOCATION;
							if (!handle_token("LSQ", "")) return LSQ;
						}
"<"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("LT", "")) return LT;
						}
"-"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("MINUS", "")) return MINUS;
						}
"%"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("MOD", "")) return MOD;
						}
"!="					{
							parse_error=0;
							LOCATION;
							if (!handle_token("NE", "")) return NE;
						}
"!"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("NOT", "")) return NOT;
						}
"||"					{
							parse_error=0;
							LOCATION;
							if (!handle_token("OR", "")) return OR;
						}
"+"						{
							parse_error=0;
							LOCATION;
							if (!handle_token("PLUS", "")) return PLUS;
						}
"}"						{
							parse_error=0;
							LOCATION;
							BEGIN SEMICOLON_STATE;
							if (!handle_token("RBRACE", "")) return RBRACE;
						}
")"						{
							parse_error=0;
							LOCATION;
							BEGIN SEMICOLON_STATE;
							if (!handle_token("RPAR", "")) return RPAR;
						}
"]"						{
							parse_error=0;
							LOCATION;
							BEGIN SEMICOLON_STATE;
							if (!handle_token("RSQ", "")) return RSQ;
						}
else					{
							parse_error=0;
							LOCATION;
							if (!handle_token("ELSE", "")) return ELSE;
						}
for						{
							parse_error=0;
							LOCATION;
							if (!handle_token("FOR", "")) return FOR;
						}
if						{
							parse_error=0;
							LOCATION;
							if (!handle_token("IF", "")) return IF;
						}
var						{
							parse_error=0;
							LOCATION;
							if (!handle_token("VAR", "")) return VAR;
						}
int						{
							parse_error=0;
							LOCATION;
							if (!handle_token("INT", "")) return INT;
						}
float32					{
							parse_error=0;
							LOCATION;
							if (!handle_token("FLOAT32", "")) return FLOAT32;
						}
bool					{
							parse_error=0;
							LOCATION;
							if (!handle_token("BOOL", "")) return BOOL;
						}
string					{
							parse_error=0;
							LOCATION;
							if (!handle_token("STRING", "")) return STRING;
						}
fmt.Println				{
							parse_error=0;
							LOCATION;
							if (!handle_token("PRINT", "")) return PRINT;
						}
strconv.Atoi			{
							parse_error=0;
							LOCATION;
							if (!handle_token("PARSEINT", "")) return PARSEINT;
						}
func					{
							parse_error=0;
							LOCATION;
							if (!handle_token("FUNC", "")) return FUNC;
						}
os.Args					{
							parse_error=0;
							LOCATION;
							if (!handle_token("CMDARGS", "")) return CMDARGS;
						}

{id}					{
							parse_error=0;
							LOCATION;
							BEGIN SEMICOLON_STATE;
							yylval.string=(char*)strdup(yytext);
							if (!handle_token("ID", yytext)) return ID;
						}
{int_lit}				{
							parse_error=0;
							LOCATION;
							BEGIN SEMICOLON_STATE;
							yylval.string=(char*)strdup(yytext);
							if (!handle_token("INTLIT", yytext)) return INTLIT;
						}
{real_lit}				{
							parse_error=0;
							LOCATION;
							BEGIN SEMICOLON_STATE;
							yylval.string=(char*)strdup(yytext);
							if (!handle_token("REALLIT", yytext)) return REALLIT;
						}

\"						{
							parse_error=0;
							BEGIN STRINGLIT;
							strcpy(result,yytext);
							errorflag=0;

							//sets the first line and column of the token as the beginning of the strlit
							yylloc.first_line = yylineno;
							yylloc.first_column = yycolumn;
							yycolumn += yyleng;
						}
<STRINGLIT>\"			{
							parse_error=0;
							strcat(result,"\"");
							yycolumn += yyleng;

							if (!errorflag) {
								BEGIN SEMICOLON_STATE;
								yylval.string = (char*)strdup(result);
								yytext = result;

								//if the strlit is legal, then the first line and column of it will be pointing to the first quotation mark
								//lets make the last line and column point to the last quotation mark

								yylloc.last_column = yycolumn - 1;
								yylloc.last_line = yylineno;
								if (!handle_token("STRLIT", result)) return STRLIT;
							}
							else BEGIN 0;
						}
<STRINGLIT>{stringlit}	{
							parse_error=0;
							yycolumn += yyleng;
							strcat(result,yytext);
						}
<STRINGLIT>{lineterminator}	{
								parse_error=0;
								//error points to the beggining of the strlit
								printf("Line %d, column %d: unterminated string literal\n", yylloc.first_line, yylloc.first_column);
								LINE;
								BEGIN 0;
							}
<STRINGLIT>\\(.?)		{
							parse_error=0;

							// error points to the beggining of the invalid escape sequence
							printf("Line %d, column %d: invalid escape sequence (%s)\n", yylineno, yycolumn, yytext);
							errorflag=1;
							yycolumn += yyleng;
						}
<STRINGLIT><<EOF>>		{
							parse_error=0;
							//error points to the beggining of the strlit
							printf("Line %d, column %d: unterminated string literal\n", yylloc.first_line, yylloc.first_column);
							yycolumn += yyleng;
							BEGIN 0;
						}

{singlelinecomment}.*	{
							parse_error=0;
							LOCATION;
						}

{commentstart}			{
							parse_error=0;
							BEGIN COMMENT;
							LOCATION;
						}
<COMMENT>{lineterminator}	{
								parse_error=0;
								LINE;
							}
<COMMENT><<EOF>>		{
							parse_error=0;
							printf("Line %d, column %d: unterminated comment\n", yylloc.first_line, yylloc.first_column);
							parse_error=1;
							return 0;
						}
<COMMENT>{commentend}	{
							parse_error=0;
							yycolumn += yyleng;
							BEGIN 0;
						}
<COMMENT>.				{
							parse_error=0;
							yycolumn += yyleng;
						}

<COMMENT_SEMICOLON>{lineterminator}	{
										parse_error=0;
										LOCATION;
										LINE;
										if (!handle_token("SEMICOLON", "")) return SEMICOLON;
										BEGIN 0;
									}

<COMMENT_SEMICOLON><<EOF>>	{
								parse_error=0;
								parse_error = 1;
								printf("Line %d, column %d: unterminated comment\n", yylloc.first_line, yylloc.first_column);
								if (!handle_token("SEMICOLON", "")) return SEMICOLON;
							}
<COMMENT_SEMICOLON>{commentend}	{
									parse_error=0;
									yycolumn += yyleng;
									BEGIN SEMICOLON_STATE;
								}
<COMMENT_SEMICOLON>.	{
							parse_error=0;
							yycolumn += yyleng;
						}

<SEMICOLON_STATE>{whitespace}	{
									parse_error=0;
									yycolumn += yyleng;
								}
<SEMICOLON_STATE>";"	{
							parse_error=0;
							LOCATION;
							BEGIN 0;
							if (!handle_token("SEMICOLON", "")) return SEMICOLON;
						}
<SEMICOLON_STATE>{lineterminator}	{
										parse_error=0;
										LOCATION;
										parse_error=1;
										LINE;
										BEGIN 0;
										if (!handle_token("SEMICOLON", "")) return SEMICOLON;
									}
<SEMICOLON_STATE>{singlelinecomment}.*	{
											parse_error=0;
											BEGIN 0;
											if (!handle_token("SEMICOLON", "")) return SEMICOLON;
										}
<SEMICOLON_STATE>{commentstart}	{
									parse_error=0;
									LOCATION;
									BEGIN COMMENT_SEMICOLON;
								}
<SEMICOLON_STATE><<EOF>>	{
								parse_error=0;
								BEGIN 0;
								LOCATION;
								parse_error=1;
								if (!handle_token("SEMICOLON", "")) return SEMICOLON;
							}
<SEMICOLON_STATE>""/.	{
							parse_error=0;
							yycolumn += yyleng;
							BEGIN 0;
						}

{whitespace}			{
							yycolumn += yyleng;
						}
{carriagereturn}		{
							yycolumn += yyleng;
						}
{lineterminator}		{
							LOCATION;
							LINE;
						}
<<EOF>>					{
							parse_error=1;
							return 0;
						}
.						{
							parse_error=0;
							printf("Line %d, column %d: illegal character (%s)\n", yylineno, yycolumn, yytext);
							yycolumn += yyleng;
						}

%%

int handle_token(char * type, char * value) {
	if (printflag) {
		if (strcmp(value,"") != 0)  //if the token has a value, print it!
			printf("%s(%s)\n", type, value);
		else printf("%s\n", type);  //if it doesn't have a value, just print the type
		return 1;
	}
	else return 0;
}

int return_token(int token) {
	return SEMICOLON;
}

void yyerror(const char * s) {
	errortag = 1;
	if (parse_error) printf("Line %d, column %d: %s: %s\n", yylloc.first_line, yylloc.first_column, s, "");
 	else printf("Line %d, column %d: %s: %s\n", yylineno, (int)(yycolumn-strlen(yytext)), s, yytext);
}

int yywrap() {
	return 1;
}