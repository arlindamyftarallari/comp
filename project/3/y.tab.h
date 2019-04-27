/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    BLANKID = 259,
    PACKAGE = 260,
    RETURN = 261,
    COMMA = 262,
    LBRACE = 263,
    LPAR = 264,
    LSQ = 265,
    CMDARGS = 266,
    RBRACE = 267,
    RPAR = 268,
    RSQ = 269,
    ELSE = 270,
    FOR = 271,
    IF = 272,
    VAR = 273,
    INT = 274,
    FLOAT32 = 275,
    BOOL = 276,
    STRING = 277,
    PRINT = 278,
    PARSEINT = 279,
    FUNC = 280,
    RESERVED = 281,
    STRLIT = 282,
    INTLIT = 283,
    ID = 284,
    REALLIT = 285,
    ASSIGN = 286,
    NOT = 287,
    MINUS = 288,
    PLUS = 289,
    GE = 290,
    NE = 291,
    LE = 292,
    EQ = 293,
    GT = 294,
    LT = 295,
    AND = 296,
    OR = 297,
    MOD = 298,
    DIV = 299,
    STAR = 300,
    UNARY = 301
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define BLANKID 259
#define PACKAGE 260
#define RETURN 261
#define COMMA 262
#define LBRACE 263
#define LPAR 264
#define LSQ 265
#define CMDARGS 266
#define RBRACE 267
#define RPAR 268
#define RSQ 269
#define ELSE 270
#define FOR 271
#define IF 272
#define VAR 273
#define INT 274
#define FLOAT32 275
#define BOOL 276
#define STRING 277
#define PRINT 278
#define PARSEINT 279
#define FUNC 280
#define RESERVED 281
#define STRLIT 282
#define INTLIT 283
#define ID 284
#define REALLIT 285
#define ASSIGN 286
#define NOT 287
#define MINUS 288
#define PLUS 289
#define GE 290
#define NE 291
#define LE 292
#define EQ 293
#define GT 294
#define LT 295
#define AND 296
#define OR 297
#define MOD 298
#define DIV 299
#define STAR 300
#define UNARY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "gocompiler.y" /* yacc.c:1909  */

	char * string;
	struct node * node;

#line 151 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
