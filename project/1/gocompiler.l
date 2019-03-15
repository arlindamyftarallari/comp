%{
    #define COLUMN column+=yyleng;
    #define LINE line++; column=1;
    int line = 1, column = 1, errorflag = 0, errorline, errorcol;
    int flag = 0;
    int debug = 0;

    void printtoken(char * type, char * msg);
    void printerror(int type);
    char result[100] = "";
%}

%x COMMENT SEMICOLON STRLIT

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

{reserved}											{printtoken("RESERVED", yytext); COLUMN;}

";"													{printtoken("SEMICOLON", yytext); COLUMN;}
"_"													{printtoken("BLANKID", yytext); COLUMN;}
package												{printtoken("PACKAGE", yytext); COLUMN;}
return												{printtoken("RETURN", yytext); COLUMN; BEGIN SEMICOLON;}
"&&"												{printtoken("AND", yytext); COLUMN;}
"="													{printtoken("ASSIGN", yytext); COLUMN;}
"*"													{printtoken("STAR", yytext); COLUMN;}
","													{printtoken("COMMA", yytext); COLUMN;}
"/"													{printtoken("DIV", yytext); COLUMN;}
"=="												{printtoken("EQ", yytext); COLUMN;}
">="												{printtoken("GE", yytext); COLUMN;}
">"													{printtoken("GT", yytext); COLUMN;}
"{"													{printtoken("LBRACE", yytext); COLUMN;}
"<="												{printtoken("LE", yytext); COLUMN;}
"("													{printtoken("LPAR", yytext); COLUMN;}
"["													{printtoken("LSQ", yytext); COLUMN;}
"<"													{printtoken("LT", yytext); COLUMN;}
"-"													{printtoken("MINUS", yytext); COLUMN;}
"%"													{printtoken("MOD", yytext); COLUMN;}
"!="												{printtoken("NE", yytext); COLUMN;}
"!"													{printtoken("NOT", yytext); COLUMN;}
"||"												{printtoken("OR", yytext); COLUMN;}
"+"													{printtoken("PLUS", yytext); COLUMN;}
"}"													{printtoken("RBRACE", yytext); COLUMN; BEGIN SEMICOLON;}
")"													{printtoken("RPAR", yytext); COLUMN; BEGIN SEMICOLON;}
"]"													{printtoken("RSQ", yytext); COLUMN; BEGIN SEMICOLON;}
else												{printtoken("ELSE", yytext); COLUMN;}
for													{printtoken("FOR", yytext); COLUMN;}
if													{printtoken("IF", yytext); COLUMN;}
var													{printtoken("VAR", yytext); COLUMN;}
int													{printtoken("INT", yytext); COLUMN;}
float32												{printtoken("FLOAT32", yytext); COLUMN;}
bool												{printtoken("BOOL", yytext); COLUMN;}
string												{printtoken("STRING", yytext); COLUMN;}
fmt.Println											{printtoken("PRINT", yytext); COLUMN;}
strconv.Atoi										{printtoken("PARSEINT", yytext); COLUMN;}
func												{printtoken("FUNC", yytext); COLUMN;}
os.Args												{printtoken("CMDARGS", yytext); COLUMN;}

{id}												{printtoken("ID", yytext); COLUMN; BEGIN SEMICOLON;}
{int_lit}											{printtoken("INTLIT", yytext); COLUMN; BEGIN SEMICOLON;}
{real_lit}											{printtoken("REALLIT", yytext); COLUMN; BEGIN SEMICOLON;}

\"													{printtoken("STRLIT START", yytext); BEGIN STRLIT; strcpy(result,"\""); errorline=line; errorcol=column; errorflag=0; COLUMN;}
<STRLIT>\"											{printtoken("STRLIT END", yytext); strcat(result,"\""); if(errorflag==0){printtoken("STRLIT",result); BEGIN SEMICOLON;} else BEGIN 0; COLUMN;}
<STRLIT>{lineterminator}                			{printf("Line %d, column %d: unterminated string literal\n", errorline, errorcol); LINE; BEGIN 0;}
<STRLIT><<EOF>>										{printf("Line %d, column %d: unterminated string literal\n", errorline, errorcol); BEGIN 0;}
<STRLIT>{invalidescape}								{printf("Line %d, column %d: invalid escape sequence (%s)\n", line, column, yytext); errorflag=1; COLUMN;}
<STRLIT>{stringlit}									{strcat(result,yytext); COLUMN;}
<STRLIT>.											{strcat(result, yytext); COLUMN;}

{singlelinecomment}.*								{printtoken("COMMENT", yytext);}

{commentstart}										{BEGIN COMMENT; errorline=line; errorcol=column; COLUMN; printtoken("COMMENT START", yytext);}
<COMMENT>{lineterminator}							{LINE;}
<COMMENT><<EOF>>									{printf("Line %d, column %d: unterminated comment\n", errorline, errorcol); return 0;}
<COMMENT>{commentend}								{BEGIN 0; COLUMN; printtoken("COMMENT END", yytext);}
<COMMENT>.											{COLUMN; printtoken("COMMENT", yytext);}

<SEMICOLON>{whitespace}								{COLUMN;}
<SEMICOLON>";"										{printtoken("SEMICOLON", yytext); COLUMN; BEGIN 0;}
<SEMICOLON>{lineterminator}							{printtoken("SEMICOLON", yytext); LINE; BEGIN 0;}
<SEMICOLON>{singlelinecomment}.*					{printtoken("SEMICOLON", yytext); printtoken("COMMENT", yytext); LINE; BEGIN 0;}
<SEMICOLON>{commentstart}							{printtoken("COMMENT START", yytext); COLUMN; BEGIN COMMENT;}
<SEMICOLON><<EOF>>									{printtoken("SEMICOLON", yytext); return 0;}
<SEMICOLON>""/.									    {COLUMN; BEGIN 0;}

{whitespace}										{COLUMN;}
{carriagereturn}									{COLUMN;}
{lineterminator}									{LINE;}
.													{printf("Line %d, column %d: illegal character (%s)\n", line, column, yytext); COLUMN;}

%%

void printtoken(char * type, char * msg) {

    if (flag == 1) { //if user runs program with flag -l, all tokens will be printed
        if ((strcmp(type, "ID") == 0) || (strcmp(type, "STRLIT") == 0) || (strcmp(type, "INTLIT") == 0) || (strcmp(type, "REALLIT") == 0) || (strcmp(type, "RESERVED") == 0)) {
            printf("%s(%s)\n", type, msg);
        }
        
        else {
            if (strcmp(type, "COMMENT") == 0 || strcmp(type, "ASPAS") == 0 || strcmp(type, "COMMENT START") == 0 || strcmp(type, "COMMENT END") == 0 || strcmp(type, "STRLIT START") == 0 || strcmp(type, "STRLIT END") == 0){}
            else printf("%s\n", type);     
        }
    }
    else if (debug == 1) { //just for debug and for printing ID, STRLIT, INTLIT & REALLIT
        printf("%s(%s)\n", type, msg);

    }
}

void printerror(int type) {
    if (type == 1) {
        printf("Line %d, column %d: unterminated comment\n", line, column);
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            flag = 1;
        }
    }
    yylex();
    return 0;
}

int yywrap()
{
return 1;
}