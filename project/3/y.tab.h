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
    AND = 262,
    ASSIGN = 263,
    STAR = 264,
    COMMA = 265,
    DIV = 266,
    EQ = 267,
    GE = 268,
    GT = 269,
    LBRACE = 270,
    LE = 271,
    LPAR = 272,
    LSQ = 273,
    LT = 274,
    CMDARGS = 275,
    MINUS = 276,
    MOD = 277,
    NE = 278,
    NOT = 279,
    OR = 280,
    PLUS = 281,
    RBRACE = 282,
    RPAR = 283,
    RSQ = 284,
    ELSE = 285,
    FOR = 286,
    IF = 287,
    VAR = 288,
    INT = 289,
    FLOAT32 = 290,
    BOOL = 291,
    STRING = 292,
    PRINT = 293,
    PARSEINT = 294,
    FUNC = 295,
    RESERVED = 296,
    STRLIT = 297,
    INTLIT = 298,
    ID = 299,
    REALLIT = 300,
    UNARY = 301
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define BLANKID 259
#define PACKAGE 260
#define RETURN 261
#define AND 262
#define ASSIGN 263
#define STAR 264
#define COMMA 265
#define DIV 266
#define EQ 267
#define GE 268
#define GT 269
#define LBRACE 270
#define LE 271
#define LPAR 272
#define LSQ 273
#define LT 274
#define CMDARGS 275
#define MINUS 276
#define MOD 277
#define NE 278
#define NOT 279
#define OR 280
#define PLUS 281
#define RBRACE 282
#define RPAR 283
#define RSQ 284
#define ELSE 285
#define FOR 286
#define IF 287
#define VAR 288
#define INT 289
#define FLOAT32 290
#define BOOL 291
#define STRING 292
#define PRINT 293
#define PARSEINT 294
#define FUNC 295
#define RESERVED 296
#define STRLIT 297
#define INTLIT 298
#define ID 299
#define REALLIT 300
#define UNARY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "gocompiler.y" /* yacc.c:1909  */

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
