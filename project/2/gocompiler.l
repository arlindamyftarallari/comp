%{
	/* 
	Hugo Brink 2016227204
	Madalena Santos 2016226726
	*/
    #define COLUMN column+=yyleng;
    #define LINE line++; column=1;
	#include "y.tab.h"
    int line = 1, column = 1, errorflag = 0, errorline, errorcol;
	extern int errortag;
    int printflag; // 0 = print errors only, 1 = print tokens
	int parse_error = 0;

    void printtoken(char * type, char * msg);
    char result[100] = "";

	extern int yydebug;
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

{reserved}											{parse_error=0; printtoken("RESERVED", yytext); COLUMN; if (!printflag) return RESERVED;}

";"													{parse_error=0; printtoken("SEMICOLON", yytext); COLUMN; if (!printflag) return SEMICOLON;}
"_"													{parse_error=0; printtoken("BLANKID", yytext); COLUMN; if (!printflag) return BLANKID;}
package												{parse_error=0; printtoken("PACKAGE", yytext); COLUMN; if (!printflag) return PACKAGE;}
return												{parse_error=0; printtoken("RETURN", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RETURN;}
"&&"												{parse_error=0; printtoken("AND", yytext); COLUMN; if (!printflag) return AND;}
"="													{parse_error=0; printtoken("ASSIGN", yytext); COLUMN; if (!printflag) return ASSIGN;}
"*"													{parse_error=0; printtoken("STAR", yytext); COLUMN; if (!printflag) return STAR;}
","													{parse_error=0; printtoken("COMMA", yytext); COLUMN; if (!printflag) return COMMA;}
"/"													{parse_error=0; printtoken("DIV", yytext); COLUMN; if (!printflag) return DIV;}
"=="												{parse_error=0; printtoken("EQ", yytext); COLUMN; if (!printflag) return EQ;}
">="												{parse_error=0; printtoken("GE", yytext); COLUMN; if (!printflag) return GE;}
">"													{parse_error=0; printtoken("GT", yytext); COLUMN; if (!printflag) return GT;}
"{"													{parse_error=0; printtoken("LBRACE", yytext); COLUMN; if (!printflag) return LBRACE;}
"<="												{parse_error=0; printtoken("LE", yytext); COLUMN; if (!printflag) return LE;}
"("													{parse_error=0; printtoken("LPAR", yytext); COLUMN; if (!printflag) return LPAR;}
"["													{parse_error=0; printtoken("LSQ", yytext); COLUMN; if (!printflag) return LSQ;}
"<"													{parse_error=0; printtoken("LT", yytext); COLUMN; if (!printflag) return LT;}
"-"													{parse_error=0; printtoken("MINUS", yytext); COLUMN; if (!printflag) return MINUS;}
"%"													{parse_error=0; printtoken("MOD", yytext); COLUMN; if (!printflag) return MOD;}
"!="												{parse_error=0; printtoken("NE", yytext); COLUMN; if (!printflag) return NE;}
"!"													{parse_error=0; printtoken("NOT", yytext); COLUMN; if (!printflag) return NOT;}
"||"												{parse_error=0; printtoken("OR", yytext); COLUMN; if (!printflag) return OR;}
"+"													{parse_error=0; printtoken("PLUS", yytext); COLUMN; if (!printflag) return PLUS;}
"}"													{parse_error=0; printtoken("RBRACE", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RBRACE;}
")"													{parse_error=0; printtoken("RPAR", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RPAR;}
"]"													{parse_error=0; printtoken("RSQ", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RSQ;}
else												{parse_error=0; printtoken("ELSE", yytext); COLUMN; if (!printflag) return ELSE;}
for													{parse_error=0; printtoken("FOR", yytext); COLUMN; if (!printflag) return FOR;}
if													{parse_error=0; printtoken("IF", yytext); COLUMN; if (!printflag) return IF;}
var													{parse_error=0; printtoken("VAR", yytext); COLUMN; if (!printflag) return VAR;}
int													{parse_error=0; printtoken("INT", yytext); COLUMN; if (!printflag) return INT;}
float32												{parse_error=0; printtoken("FLOAT32", yytext); COLUMN; if (!printflag) return FLOAT32;}
bool												{parse_error=0; printtoken("BOOL", yytext); COLUMN; if (!printflag) return BOOL;}
string												{parse_error=0; printtoken("STRING", yytext); COLUMN; if (!printflag) return STRING;}
fmt.Println											{parse_error=0; printtoken("PRINT", yytext); COLUMN; if (!printflag) return PRINT;}
strconv.Atoi										{parse_error=0; printtoken("PARSEINT", yytext); COLUMN; if (!printflag) return PARSEINT;}
func												{parse_error=0; printtoken("FUNC", yytext); COLUMN; if (!printflag) return FUNC;}
os.Args												{parse_error=0; printtoken("CMDARGS", yytext); COLUMN; if (!printflag) return CMDARGS;}

{id}												{parse_error=0; printtoken("ID", yytext); COLUMN; BEGIN SEMICOLON_STATE; yylval.string=(char*)strdup(yytext); if (!printflag) return ID;}
{int_lit}											{parse_error=0; printtoken("INTLIT", yytext); COLUMN; BEGIN SEMICOLON_STATE; yylval.string=(char*)strdup(yytext); if (!printflag) return INTLIT;}
{real_lit}											{parse_error=0; printtoken("REALLIT", yytext); COLUMN; BEGIN SEMICOLON_STATE; yylval.string=(char*)strdup(yytext); if (!printflag) return REALLIT;}

\"													{parse_error=0; BEGIN STRINGLIT; strcpy(result,yytext); errorline=line; errorcol=column; errorflag=0; COLUMN;}
<STRINGLIT>\"										{parse_error=0; strcat(result,"\""); COLUMN;if(errorflag==0){printtoken("STRLIT",result); BEGIN SEMICOLON_STATE; yylval.string=(char*)strdup(result); if (!printflag){yytext=result;return STRLIT;}} else BEGIN 0;}
<STRINGLIT>{stringlit}								{parse_error=0; strcat(result,yytext); COLUMN;}
<STRINGLIT>{lineterminator}                			{parse_error=0; printf("Line %d, column %d: unterminated string literal\n", errorline, errorcol); LINE; BEGIN 0;}
<STRINGLIT>\\(.?)									{parse_error=0; printf("Line %d, column %d: invalid escape sequence (%s)\n", line, column, yytext); errorflag=1; COLUMN;}
<STRINGLIT><<EOF>>									{parse_error=0; printf("Line %d, column %d: unterminated string literal\n", errorline, errorcol); BEGIN 0;}

{singlelinecomment}.*								{parse_error=0; errorcol=column; errorline=line;}

{commentstart}										{parse_error=0; BEGIN COMMENT; errorline=line; errorcol=column; COLUMN;}
<COMMENT>{lineterminator}							{parse_error=0; LINE;}
<COMMENT><<EOF>>									{parse_error=0; printf("Line %d, column %d: unterminated comment\n", errorline, errorcol); errorline=line; errorcol=column; parse_error=1; return 0;}
<COMMENT>{commentend}								{parse_error=0; COLUMN; BEGIN 0;}
<COMMENT>.											{parse_error=0; COLUMN;}

<COMMENT_SEMICOLON>{lineterminator}					{parse_error=0; errorline=line; errorcol=column;LINE; if (!printflag) return SEMICOLON; BEGIN 0;}
<COMMENT_SEMICOLON><<EOF>>							{parse_error=0; parse_error = 1; printf("Line %d, column %d: unterminated comment\n", errorline, errorcol);if (!printflag) return SEMICOLON;}
<COMMENT_SEMICOLON>{commentend}						{parse_error=0; COLUMN; BEGIN SEMICOLON_STATE;}
<COMMENT_SEMICOLON>.								{parse_error=0; COLUMN;}

<SEMICOLON_STATE>{whitespace}						{parse_error=0; COLUMN;}
<SEMICOLON_STATE>";"								{parse_error=0; printtoken("SEMICOLON", yytext); COLUMN; BEGIN 0; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>{lineterminator}					{parse_error=0; printtoken("SEMICOLON", yytext); errorline=line; errorcol=column; parse_error=1; LINE; BEGIN 0; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>{singlelinecomment}.*				{parse_error=0; printtoken("SEMICOLON", yytext); BEGIN 0; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>{commentstart}						{parse_error=0; errorline=line; errorcol=column; COLUMN; BEGIN COMMENT_SEMICOLON;}
<SEMICOLON_STATE><<EOF>>							{parse_error=0; printtoken("SEMICOLON", yytext); BEGIN 0; errorcol=column; errorline=line; parse_error=1;if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>""/.								{parse_error=0; COLUMN; BEGIN 0;}

{whitespace}										{COLUMN;}
{carriagereturn}									{COLUMN;}
{lineterminator}									{errorcol=column; errorline=line; LINE;}
<<EOF>>												{parse_error=1; return 0;}
.													{parse_error=0; printf("Line %d, column %d: illegal character (%s)\n", line, column, yytext); COLUMN;}

%%

void printtoken(char * type, char * msg) {

    if (printflag == 1) { //if user runs program with printflag -l, all tokens will be printed
        if ((strcmp(type, "ID") == 0) || (strcmp(type, "STRLIT") == 0) || (strcmp(type, "INTLIT") == 0) || (strcmp(type, "REALLIT") == 0) || (strcmp(type, "RESERVED") == 0)) {
            printf("%s(%s)\n", type, msg);
        }
        
        else {
			printf("%s\n", type);     
        }
    }
}

void yyerror(const char * s) {
	errortag = 1;
	if (parse_error) printf("Line %d, column %d: %s: %s\n", errorline, errorcol, s, "");
 	else printf("Line %d, column %d: %s: %s\n", line, (int)(column-strlen(yytext)), s, yytext);
}

int yywrap() {
	return 1;
}