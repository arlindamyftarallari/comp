%X START TITLE CHAPTER SECTION ENUMERATE ITEMIZE ENUMERATE_ITEM ITEMIZE_ITEM
%{
    #include <ctype.h>
    int numChapter = 0;
    int numSection = 0;
    int item;
%}
word                        [a-z|0-9|A-Z|.^"///"]+
%%
(\\documentclass.*)|(\\usepackage.*)      {;}
<START>\\title\{                          {BEGIN TITLE;}
<TITLE>{word}(" "{word})*                 {printf("\t"); while(*yytext){printf("%c", toupper(*yytext)); yytext++;};}
<TITLE>\}                                 {BEGIN START;}
<START>\\chapter\{                        {BEGIN CHAPTER; numChapter++; numSection=0;}
<CHAPTER>{word}(" "{word})*               {printf("%d. %s", numChapter, yytext);}
<CHAPTER>\}                               {BEGIN START;}
<START>{word}(" "{word})*                 {printf("%s", yytext);}
<START>\\section\{                        {BEGIN SECTION; numSection++;}
<SECTION>{word}(" "{word})*               {printf("%d.%d. %s", numChapter, numSection, yytext);}
<SECTION>\}                               {BEGIN START;}
<START>\\begin\{enumerate\}               {BEGIN ENUMERATE; item=1;}
<ENUMERATE>\\item                         {BEGIN ENUMERATE_ITEM;}
<ENUMERATE_ITEM>{word}(" "{word})*        {printf("%d - %s", item, yytext); item++; BEGIN ENUMERATE;}
<ENUMERATE>\\end\{enumerate\}             {BEGIN START;}
<START>\\begin\{itemize\}                 {BEGIN ITEMIZE;}
<ITEMIZE>\\item                           {BEGIN ITEMIZE_ITEM;}
<ITEMIZE_ITEM>{word}(" "{word})*          {printf(". %s", yytext); BEGIN ITEMIZE;}
<ITEMIZE>\\end\{itemize\}                 {BEGIN START;}
\\begin\{{word}\}                         {BEGIN START;}  
<START>\\end\{{word}\}                    {BEGIN 0;}
<START>.                                  {;}

%%
int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}