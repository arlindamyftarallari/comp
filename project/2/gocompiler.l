%{
	/* 
	Hugo Brink 2016227204
	Madalena Santos 2016226726
	*/
    #define COLUMN column+=yyleng;
    #define LINE line++; column=1;
	#include "y.tab.h"
    int line = 1, column = 1, errorflag = 0, errorline, errorcol;
    int printflag; // 0 = print errors only, 1 = print tokens

    void printtoken(char * type, char * msg);
    char result[100] = "";

	extern int yydebug;
%}

%x COMMENT SEMICOLON_STATE STRINGLIT

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
invalidescape		\\[^trnf\"\\]


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

{reserved}											{printtoken("RESERVED", yytext); COLUMN; if (!printflag) return RESERVED;}

";"													{printtoken("SEMICOLON", yytext); COLUMN; if (!printflag) return SEMICOLON;}
"_"													{printtoken("BLANKID", yytext); COLUMN; if (!printflag) return BLANKID;}
package												{printtoken("PACKAGE", yytext); COLUMN; if (!printflag) return PACKAGE;}
return												{printtoken("RETURN", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RETURN;}
"&&"												{printtoken("AND", yytext); COLUMN; if (!printflag) return AND;}
"="													{printtoken("ASSIGN", yytext); COLUMN; if (!printflag) return ASSIGN;}
"*"													{printtoken("STAR", yytext); COLUMN; if (!printflag) return STAR;}
","													{printtoken("COMMA", yytext); COLUMN; if (!printflag) return COMMA;}
"/"													{printtoken("DIV", yytext); COLUMN; if (!printflag) return DIV;}
"=="												{printtoken("EQ", yytext); COLUMN; if (!printflag) return EQ;}
">="												{printtoken("GE", yytext); COLUMN; if (!printflag) return GE;}
">"													{printtoken("GT", yytext); COLUMN; if (!printflag) return GT;}
"{"													{printtoken("LBRACE", yytext); COLUMN; if (!printflag) return LBRACE;}
"<="												{printtoken("LE", yytext); COLUMN; if (!printflag) return LE;}
"("													{printtoken("LPAR", yytext); COLUMN; if (!printflag) return LPAR;}
"["													{printtoken("LSQ", yytext); COLUMN; if (!printflag) return LSQ;}
"<"													{printtoken("LT", yytext); COLUMN; if (!printflag) return LT;}
"-"													{printtoken("MINUS", yytext); COLUMN; if (!printflag) return MINUS;}
"%"													{printtoken("MOD", yytext); COLUMN; if (!printflag) return MOD;}
"!="												{printtoken("NE", yytext); COLUMN; if (!printflag) return NE;}
"!"													{printtoken("NOT", yytext); COLUMN; if (!printflag) return NOT;}
"||"												{printtoken("OR", yytext); COLUMN; if (!printflag) return OR;}
"+"													{printtoken("PLUS", yytext); COLUMN; if (!printflag) return PLUS;}
"}"													{printtoken("RBRACE", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RBRACE;}
")"													{printtoken("RPAR", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RPAR;}
"]"													{printtoken("RSQ", yytext); COLUMN; BEGIN SEMICOLON_STATE; if (!printflag) return RSQ;}
else												{printtoken("ELSE", yytext); COLUMN; if (!printflag) return ELSE;}
for													{printtoken("FOR", yytext); COLUMN; if (!printflag) return FOR;}
if													{printtoken("IF", yytext); COLUMN; if (!printflag) return IF;}
var													{printtoken("VAR", yytext); COLUMN; if (!printflag) return VAR;}
int													{printtoken("INT", yytext); COLUMN; if (!printflag) return INT;}
float32												{printtoken("FLOAT32", yytext); COLUMN; if (!printflag) return FLOAT32;}
bool												{printtoken("BOOL", yytext); COLUMN; if (!printflag) return BOOL;}
string												{printtoken("STRING", yytext); COLUMN; if (!printflag) return STRING;}
fmt.Println											{printtoken("PRINT", yytext); COLUMN; if (!printflag) return PRINT;}
strconv.Atoi										{printtoken("PARSEINT", yytext); COLUMN; if (!printflag) return PARSEINT;}
func												{printtoken("FUNC", yytext); COLUMN; if (!printflag) return FUNC;}
os.Args												{printtoken("CMDARGS", yytext); COLUMN; if (!printflag) return CMDARGS;}

{id}												{printtoken("ID", yytext); COLUMN; BEGIN SEMICOLON_STATE; yylval.string=(char*)strdup(yytext); if (!printflag) return ID;}
{int_lit}											{printtoken("INTLIT", yytext); COLUMN; BEGIN SEMICOLON_STATE; yylval.string=(char*)strdup(yytext); if (!printflag) return INTLIT;}
{real_lit}											{printtoken("REALLIT", yytext); COLUMN; BEGIN SEMICOLON_STATE; yylval.string=(char*)strdup(yytext); if (!printflag) return REALLIT;}

\"													{BEGIN STRINGLIT; strcpy(result,"\""); errorline=line; errorcol=column; errorflag=0; COLUMN;}
<STRINGLIT>\"										{strcat(result,"\""); if(errorflag==0){printtoken("STRLIT",result); BEGIN SEMICOLON_STATE;  yylval.string=(char*)strdup(result); if (!printflag) return STRLIT;} else BEGIN 0; COLUMN;}
<STRINGLIT>{lineterminator}                			{printf("Line %d, column %d: unterminated string literal\n", errorline, errorcol); LINE; BEGIN 0;}
<STRINGLIT><<EOF>>									{printf("Line %d, column %d: unterminated string literal\n", errorline, errorcol); BEGIN 0;}
<STRINGLIT>{invalidescape}							{printf("Line %d, column %d: invalid escape sequence (%s)\n", line, column, yytext); errorflag=1; COLUMN;}
<STRINGLIT>{stringlit}								{strcat(result,yytext); COLUMN;}
<STRINGLIT>.										{strcat(result, yytext); COLUMN;}

{singlelinecomment}.*								{;}

{commentstart}										{BEGIN COMMENT; errorline=line; errorcol=column; COLUMN;}
<COMMENT>{lineterminator}							{LINE;}
<COMMENT><<EOF>>									{printf("Line %d, column %d: unterminated comment\n", errorline, errorcol); return 0;}
<COMMENT>{commentend}								{BEGIN 0; COLUMN;}
<COMMENT>.											{COLUMN;}

<SEMICOLON_STATE>{whitespace}						{COLUMN;}
<SEMICOLON_STATE>";"								{printtoken("SEMICOLON", yytext); COLUMN; BEGIN 0; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>{lineterminator}					{printtoken("SEMICOLON", yytext); LINE; BEGIN 0; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>{singlelinecomment}.*				{printtoken("SEMICOLON", yytext); LINE; BEGIN 0; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>{commentstart}						{COLUMN; BEGIN COMMENT; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE><<EOF>>							{printtoken("SEMICOLON", yytext); return 0; if (!printflag) return SEMICOLON;}
<SEMICOLON_STATE>""/.								{COLUMN; BEGIN 0;}

{whitespace}										{COLUMN;}
{carriagereturn}									{COLUMN;}
{lineterminator}									{LINE;}
.													{printf("Line %d, column %d: illegal character (%s)\n", line, column, yytext); COLUMN;}

%%

void printtoken(char * type, char * msg) {

    if (printflag == 1) { //if user runs program with printflag -l, all tokens will be printed
        if ((strcmp(type, "ID") == 0) || (strcmp(type, "STRINGLIT") == 0) || (strcmp(type, "INTLIT") == 0) || (strcmp(type, "REALLIT") == 0) || (strcmp(type, "RESERVED") == 0)) {
            printf("%s(%s)\n", type, msg);
        }
        
        else {
			printf("%s\n", type);     
        }
    }
}

void yyerror(const char * s) {
	printf("Line %d, column %d: %s: %s\n", line, (int)(column-yyleng) , s, yytext);
}


int yywrap() {
	return 1;
}