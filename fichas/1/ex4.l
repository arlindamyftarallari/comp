name                [^(\n|\t| |;|,|\")]
%{
    char * emails[10];
    int i = 0;
%}
%%
{name}                              {printf("oi");}
{name}@{name}"."{name}("."{name})*  {emails[i] = yytext; i++;}
.                   {;}\
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