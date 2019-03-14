numero				[0-9]+
float               [0-9]+("."|",")[0-9]+
%%
{numero}				    {printf("integer");}
{numero}l                   {printf("long");}
{numero}f                   {printf("float");}
{numero}u                   {printf("unsigned int");}
{numero}ul                  {printf("unsigned long");}
{float}e("+"|"-"){numero}   {printf("floating point");}
{numero}e("+"|"-"){numero}  {printf("floating point");}
{float}                 	{printf("float");}
"-"{numero}				    {printf("Inteiro negativo");}
"-"{numero}"."{numero}	    {printf("Real negativo");}
ab+c|a*(bc)+                {printf("token!");}

                  
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
