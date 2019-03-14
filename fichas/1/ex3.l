%%
[a-z]       {int c = *yytext; printf(" %c", c-32);}
[A-Z]       {printf("oi");}


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