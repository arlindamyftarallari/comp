/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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




/* Copy the first part of user declarations.  */
#line 1 "gocompiler.y"

	/* 
	Hugo Brink 2016227204
	Madalena Santos 2016226726
	*/

	#include <stdio.h>
	#include <string.h>
	#include "semantics.h"

	#define YYDEBUG 1

	int yylex(void);
	int yylex_destroy();
	void yyerror(const char *s);
	int errortag = 0, printflag = 0;
	int stmtcount = 0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "gocompiler.y"
{
	char * string;
	struct node * node;
}
/* Line 193 of yacc.c.  */
#line 212 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 237 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    12,    16,    17,    19,    21,    23,
      25,    28,    34,    38,    42,    43,    51,    53,    54,    56,
      57,    61,    66,    67,    71,    75,    76,    78,    80,    81,
      85,    89,    96,   102,   105,   107,   109,   114,   116,   118,
     120,   122,   123,   127,   128,   133,   134,   146,   155,   160,
     165,   168,   169,   173,   174,   178,   182,   185,   188,   191,
     195,   199,   203,   207,   211,   215,   219,   223,   227,   231,
     235,   239,   243,   245,   247,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,     5,    29,     3,    49,    -1,    51,     3,
      49,    -1,    54,     3,    49,    -1,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    18,    52,    -1,    18,     9,
      52,     3,    13,    -1,    29,    53,    50,    -1,     7,    29,
      53,    -1,    -1,    25,    29,     9,    55,    13,    56,    59,
      -1,    57,    -1,    -1,    50,    -1,    -1,    29,    50,    58,
      -1,     7,    29,    50,    58,    -1,    -1,     8,    60,    12,
      -1,    60,    61,     3,    -1,    -1,    51,    -1,    62,    -1,
      -1,    29,    31,    71,    -1,     8,    65,    12,    -1,    17,
      71,     8,    65,    12,    66,    -1,    16,    64,     8,    65,
      12,    -1,     6,    64,    -1,    68,    -1,    67,    -1,    23,
       9,    63,    13,    -1,     1,    -1,    27,    -1,    71,    -1,
      71,    -1,    -1,    62,     3,    65,    -1,    -1,    15,     8,
      65,    12,    -1,    -1,    29,     7,     4,    31,    24,     9,
      11,    10,    71,    14,    13,    -1,    29,     7,     4,    31,
      24,     9,     1,    13,    -1,    29,     9,    69,    13,    -1,
      29,     9,     1,    13,    -1,    71,    70,    -1,    -1,     7,
      71,    70,    -1,    -1,     9,    71,    13,    -1,     9,     1,
      13,    -1,    32,    71,    -1,    33,    71,    -1,    34,    71,
      -1,    71,    34,    71,    -1,    71,    33,    71,    -1,    71,
      45,    71,    -1,    71,    44,    71,    -1,    71,    43,    71,
      -1,    71,    42,    71,    -1,    71,    41,    71,    -1,    71,
      40,    71,    -1,    71,    39,    71,    -1,    71,    38,    71,
      -1,    71,    36,    71,    -1,    71,    37,    71,    -1,    71,
      35,    71,    -1,    28,    -1,    30,    -1,    29,    -1,    68,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    55,    64,    71,    75,    79,    83,    87,
      93,    97,   103,   160,   171,   176,   189,   194,   200,   205,
     210,   226,   234,   239,   247,   255,   260,   264,   269,   274,
     281,   292,   301,   309,   315,   319,   323,   328,   335,   339,
     345,   350,   355,   364,   369,   376,   381,   387,   394,   401,
     408,   416,   421,   429,   434,   438,   443,   447,   451,   455,
     461,   467,   473,   479,   485,   491,   497,   503,   509,   515,
     521,   527,   533,   537,   541,   545
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "BLANKID", "PACKAGE",
  "RETURN", "COMMA", "LBRACE", "LPAR", "LSQ", "CMDARGS", "RBRACE", "RPAR",
  "RSQ", "ELSE", "FOR", "IF", "VAR", "INT", "FLOAT32", "BOOL", "STRING",
  "PRINT", "PARSEINT", "FUNC", "RESERVED", "STRLIT", "INTLIT", "ID",
  "REALLIT", "ASSIGN", "NOT", "MINUS", "PLUS", "GE", "NE", "LE", "EQ",
  "GT", "LT", "AND", "OR", "MOD", "DIV", "STAR", "UNARY", "$accept",
  "Program", "Declarations", "Type", "VarDeclaration", "VarSpec", "IdOpt",
  "FuncDeclaration", "ParametersOpt", "TypeOpt", "Parameters", "OptParam",
  "FuncBody", "VarsAndStatements", "varsAndStatementsOpt", "Statement",
  "printArgs", "ExprOpt", "StatementOpt", "ElseOpt", "ParseArgs",
  "FuncInvocation", "CallParams", "OptCallParams", "Expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    50,    50,
      51,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    58,    58,    59,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     1,     1,     1,     1,
       2,     5,     3,     3,     0,     7,     1,     0,     1,     0,
       3,     4,     0,     3,     3,     0,     1,     1,     0,     3,
       3,     6,     5,     2,     1,     1,     4,     1,     1,     1,
       1,     0,     3,     0,     4,     0,    11,     8,     4,     4,
       2,     0,     3,     0,     3,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     0,     0,     2,     0,
       0,     0,    14,    10,     0,     5,     5,     0,     0,     0,
      17,     3,     4,     0,    14,     6,     7,     8,     9,    12,
       0,     0,    16,    11,    13,    22,    19,     0,    20,    18,
       0,     0,    25,    15,    22,     0,    21,    37,    41,     0,
      23,    41,     0,     0,     0,    26,     0,    27,    35,    34,
       0,    72,    74,    73,     0,     0,     0,    33,    75,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    56,    57,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,    38,     0,    39,     0,     0,     0,    53,    29,    55,
      54,    60,    59,    71,    69,    70,    68,    67,    66,    65,
      64,    63,    62,    61,    42,     0,     0,    36,     0,    49,
      48,     0,    50,    32,    45,     0,    53,     0,    31,     0,
      52,     0,     0,     0,     0,    47,     0,    44,     0,     0,
      46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    29,     9,    13,    19,    10,    31,    40,
      32,    38,    43,    45,    56,    70,   102,    67,    71,   138,
      58,    68,   106,   132,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
       2,   -13,    20,    21,   -95,    -6,    -7,    17,   -95,    28,
      48,    24,    74,   -95,    76,    -6,    -6,    80,    57,    69,
      65,   -95,   -95,   101,    74,   -95,   -95,   -95,   -95,   -95,
      69,   106,   -95,   -95,   -95,    86,    69,    91,   -95,   -95,
     113,    69,   -95,   -95,    86,   171,   -95,   -95,    41,   174,
     -95,    41,    41,   114,     1,   -95,   122,   -95,   -95,   -95,
      83,   -95,   117,   -95,    41,    41,    41,   -95,   -95,   185,
     124,   116,   121,    64,   183,   127,   109,    41,   -95,   119,
     111,   -95,   -95,   -95,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,   174,   -95,   174,
     174,   -95,   120,   185,    99,   123,   144,    23,   185,   -95,
     -95,    34,    34,   -16,   -16,   -16,   -16,   -16,   -16,   211,
     198,   -95,   -95,   -95,   -95,   146,   161,   -95,   110,   -95,
     -95,    41,   -95,   -95,   163,   167,    23,   173,   -95,    10,
     -95,   174,   172,   125,   181,   -95,    41,   -95,   126,   182,
     -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,    33,    46,   139,   187,   175,   -95,   -95,   -95,
     -95,   152,   -95,   -95,   -95,   156,   -95,   151,   -94,   -95,
     -95,   -45,   -95,    68,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      59,    73,    11,   124,    59,   125,   126,     1,    75,    80,
      76,   142,     6,    81,    82,    83,     3,    84,    85,     7,
       4,   143,    12,   103,     5,   107,   108,    94,    95,    96,
     131,    15,    77,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    14,   144,    21,    22,
      60,    16,    59,    12,    59,    59,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    61,
      62,    63,   100,    64,    65,    66,    35,    94,    95,    96,
     136,    18,    39,    23,    79,    20,    24,    44,    25,    26,
      27,    28,    60,    37,    30,   148,    59,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     105,    61,    62,    63,    33,    64,    65,    66,    60,    36,
      41,    42,   -51,    74,   110,    78,    76,    97,    98,    99,
     128,   104,   109,   127,   135,   146,   129,    61,    62,    63,
     149,    64,    65,    66,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   130,   133,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    47,   134,   -28,    47,   139,    48,   137,    49,
      48,   141,    49,    50,    55,   145,   -43,    51,    52,     6,
      51,    52,    60,   147,    53,   150,    46,    53,    17,    34,
      54,    57,    72,    54,   140,     0,     0,     0,     0,     0,
     101,    61,    62,    63,     0,    64,    65,    66,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,    94,    95,    96,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
      45,    52,     9,    97,    49,    99,   100,     5,     7,    60,
       9,     1,    18,    64,    65,    66,    29,    33,    34,    25,
       0,    11,    29,    74,     3,    76,    77,    43,    44,    45,
       7,     3,    31,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    29,   141,    15,    16,
       9,     3,    97,    29,    99,   100,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    28,
      29,    30,     8,    32,    33,    34,    30,    43,    44,    45,
     131,     7,    36,     3,     1,     9,    29,    41,    19,    20,
      21,    22,     9,     7,    29,   146,   141,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       1,    28,    29,    30,    13,    32,    33,    34,     9,    13,
      29,     8,    13,     9,    13,     3,     9,     3,    12,     8,
      31,     4,    13,    13,    24,    10,    13,    28,    29,    30,
      14,    32,    33,    34,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    13,    12,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     1,    12,     3,     1,     9,     6,    15,     8,
       6,     8,     8,    12,    45,    13,    12,    16,    17,    18,
      16,    17,     9,    12,    23,    13,    44,    23,    11,    24,
      29,    45,    51,    29,   136,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    32,    33,    34,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    45,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    48,    29,     0,     3,    18,    25,    49,    51,
      54,     9,    29,    52,    29,     3,     3,    52,     7,    53,
       9,    49,    49,     3,    29,    19,    20,    21,    22,    50,
      29,    55,    57,    13,    53,    50,    13,     7,    58,    50,
      56,    29,     8,    59,    50,    60,    58,     1,     6,     8,
      12,    16,    17,    23,    29,    51,    61,    62,    67,    68,
       9,    28,    29,    30,    32,    33,    34,    64,    68,    71,
      62,    65,    64,    71,     9,     7,     9,    31,     3,     1,
      71,    71,    71,    71,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     3,    12,     8,
       8,    27,    63,    71,     4,     1,    69,    71,    71,    13,
      13,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    65,    65,    65,    13,    31,    13,
      13,     7,    70,    12,    12,    24,    71,    15,    66,     9,
      70,     8,     1,    11,    65,    13,    10,    12,    71,    14,
      13
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 48 "gocompiler.y"
    {
		root = create_node("Program", "", 0, 0, 0);
		if ((yyvsp[(4) - (4)].node) != NULL) add_child(root, (yyvsp[(4) - (4)].node));
		(yyval.node) = root;
	}
    break;

  case 3:
#line 56 "gocompiler.y"
    {
			if ((yyvsp[(3) - (3)].node) != NULL) {
				add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			}
			(yyval.node) = (yyvsp[(1) - (3)].node);

		}
    break;

  case 4:
#line 65 "gocompiler.y"
    {
			if ((yyvsp[(3) - (3)].node) != NULL) add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
			(yyval.node) = (yyvsp[(1) - (3)].node);
		}
    break;

  case 5:
#line 71 "gocompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 6:
#line 76 "gocompiler.y"
    {
			(yyval.node) = create_node("Int", "", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 0);
		}
    break;

  case 7:
#line 80 "gocompiler.y"
    {
			(yyval.node) = create_node("Float32", "", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 0);
		}
    break;

  case 8:
#line 84 "gocompiler.y"
    {
			(yyval.node) = create_node("Bool", "", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 0);
		}
    break;

  case 9:
#line 88 "gocompiler.y"
    {
			(yyval.node) = create_node("String", "", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 0);
		}
    break;

  case 10:
#line 94 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(2) - (2)].node);
		}
    break;

  case 11:
#line 98 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(3) - (5)].node);
		}
    break;

  case 12:
#line 104 "gocompiler.y"
    {
			struct node * varDecl = create_node("VarDecl", "", 0, 0, 0);
			add_child(varDecl, (yyvsp[(3) - (3)].node));
			add_child(varDecl, create_node("Id", (yyvsp[(1) - (3)].string), (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, 1));

			//when there are several variable declarations inside one VarSpec
			//we need to make new nodes VarDecl for each one and make them siblings
			
			if ((yyvsp[(2) - (3)].node) != NULL) {
				struct node * newId = (yyvsp[(2) - (3)].node);
				struct node * varDecls[100];
				struct node * ids[100];
				int i=0;
				int k=0;

				//puts all Ids inside array
				while (newId != NULL) {
					ids[k] = newId;
					newId = newId->bro;
					k++;
				}

				newId = (yyvsp[(2) - (3)].node);
				struct node * aux;

				//destroys bro connections between Ids
				if (newId->bro != NULL) {
					while(newId != NULL) {
						aux = newId->bro;
						newId->bro = NULL;
						newId = aux;
					}
				}

				struct node * auxType;

				//creates a new VarDecl node for each Id received from the IdOpt
				for (int n=0; n<k; n++) { //iterates ids array
					varDecls[n] = create_node("VarDecl", "", 0, 0, 0);
					auxType = create_node((yyvsp[(3) - (3)].node)->type, "", (yylsp[(3) - (3)]).first_line, (yylsp[(3) - (3)]).first_column, 0);
					add_child(varDecls[n], auxType);
					add_child(varDecls[n], ids[n]);
					i++;
				}
				
				if (i>=1) add_sibling(varDecl, varDecls[0]);

				for (int j=0; j+1<i; j++) {
					add_sibling(varDecls[j], varDecls[j+1]);
				}
			}

			(yyval.node) = varDecl;	
		}
    break;

  case 13:
#line 161 "gocompiler.y"
    {
			struct node * id = create_node("Id", (yyvsp[(2) - (3)].string), (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 1);
			if ((yyvsp[(3) - (3)].node) == NULL) {
				(yyval.node) = id;
			}
			else {
				(yyval.node) = add_sibling(id, (yyvsp[(3) - (3)].node));
			}
		}
    break;

  case 14:
#line 171 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 15:
#line 177 "gocompiler.y"
    {
			struct node * funcDecl = create_node("FuncDecl", "", 0, 0, 0);
			struct node * funcHeader = create_node("FuncHeader", "", 0, 0, 0);
			add_child(funcHeader, create_node("Id", (yyvsp[(2) - (7)].string), (yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, 1));
			if ((yyvsp[(6) - (7)].node) != NULL) add_child(funcHeader, (yyvsp[(6) - (7)].node));
			add_child(funcHeader, (yyvsp[(4) - (7)].node));
			add_child(funcDecl, funcHeader);
			add_child(funcDecl, (yyvsp[(7) - (7)].node));
			(yyval.node) = funcDecl;
		}
    break;

  case 16:
#line 190 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 17:
#line 194 "gocompiler.y"
    {
			(yyval.node) = create_node("FuncParams", "", 0, 0, 0); 
			//this node is not going to have any sons, but it is mandatory
		}
    break;

  case 18:
#line 201 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 19:
#line 205 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 20:
#line 211 "gocompiler.y"
    {
			struct node * funcParams = create_node("FuncParams", "", 0, 0, 0);
			struct node * paramDecl = create_node("ParamDecl", "", 0, 0, 0);
			add_child(paramDecl, (yyvsp[(2) - (3)].node));
			add_child(paramDecl, create_node("Id", (yyvsp[(1) - (3)].string), (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, 1));
			add_child(funcParams, paramDecl);

			if ((yyvsp[(3) - (3)].node) != NULL) {
				add_child(funcParams, (yyvsp[(3) - (3)].node));
			}

			(yyval.node) = funcParams;
		}
    break;

  case 21:
#line 227 "gocompiler.y"
    {
			struct node * paramDecl = create_node("ParamDecl", "", 0, 0, 0);
			add_child(paramDecl, (yyvsp[(3) - (4)].node));
			(yyval.node) = add_child(paramDecl, create_node("Id", (yyvsp[(2) - (4)].string), (yylsp[(2) - (4)]).first_line, (yylsp[(2) - (4)]).first_column, 1));
			if ((yyvsp[(4) - (4)].node) != NULL) add_sibling(paramDecl, (yyvsp[(4) - (4)].node));
		}
    break;

  case 22:
#line 234 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 23:
#line 240 "gocompiler.y"
    {
			struct node* funcBody = create_node("FuncBody", "", 0, 0, 0);
			if ((yyvsp[(2) - (3)].node) != NULL) add_child(funcBody, (yyvsp[(2) - (3)].node));
			(yyval.node) = funcBody;
		}
    break;

  case 24:
#line 248 "gocompiler.y"
    {
			if ((yyvsp[(2) - (3)].node) == NULL && (yyvsp[(1) - (3)].node) == NULL) (yyval.node) = NULL;
			else if ((yyvsp[(1) - (3)].node) == NULL) (yyval.node) = (yyvsp[(2) - (3)].node);
			else if ((yyvsp[(2) - (3)].node) == NULL) (yyval.node) = (yyvsp[(1) - (3)].node);
			else (yyval.node) = add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
		}
    break;

  case 25:
#line 255 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 26:
#line 261 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 27:
#line 265 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 28:
#line 269 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 29:
#line 275 "gocompiler.y"
    {
			struct node * assign = create_node("Assign", (yyvsp[(2) - (3)].string), 0, 0, 0);
			add_child(assign, create_node("Id", (yyvsp[(1) - (3)].string), (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, 1));
			if((yyvsp[(3) - (3)].node)!=NULL) (yyval.node) = add_child(assign, (yyvsp[(3) - (3)].node));
			else (yyval.node) = NULL;
		}
    break;

  case 30:
#line 282 "gocompiler.y"
    {
				if ((yyvsp[(2) - (3)].node) != NULL && (yyvsp[(2) - (3)].node)->bro != NULL) { //creating block for multiple statements
					struct node * block = create_node("Block", "", 0, 0, 0);
					add_child(block, (yyvsp[(2) - (3)].node));
					(yyval.node) = block;
				}
				else { //there is only 1 statement -> no need for block
					(yyval.node) = (yyvsp[(2) - (3)].node);
				}
			}
    break;

  case 31:
#line 293 "gocompiler.y"
    {
			struct node * iff = create_node("If", "", 0, 0, 0);
			if ((yyvsp[(2) - (6)].node)!=NULL) add_child(iff, (yyvsp[(2) - (6)].node));
			struct node * block = create_node("Block", "", 0, 0, 0);
			if ((yyvsp[(4) - (6)].node) != NULL) add_child(block, (yyvsp[(4) - (6)].node));	
			add_child(iff, block);
			(yyval.node) = add_child(iff, (yyvsp[(6) - (6)].node));
		}
    break;

  case 32:
#line 302 "gocompiler.y"
    {
			struct node * forr = create_node("For", "", 0, 0, 0);
			if ((yyvsp[(2) - (5)].node) != NULL) add_child(forr, (yyvsp[(2) - (5)].node));
			struct node * block = create_node("Block", "", 0, 0, 0);
			if ((yyvsp[(4) - (5)].node) != NULL) add_child(block, (yyvsp[(4) - (5)].node));
			(yyval.node) = add_child(forr, block);
		}
    break;

  case 33:
#line 310 "gocompiler.y"
    {
			struct node * returnn = create_node("Return", "", 0, 0, 0);
			if ((yyvsp[(2) - (2)].node) != NULL) add_child(returnn, (yyvsp[(2) - (2)].node));
			(yyval.node) = returnn;
		}
    break;

  case 34:
#line 316 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 35:
#line 320 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 36:
#line 324 "gocompiler.y"
    {
			struct node * print = create_node("Print", "", 0, 0, 0);
			(yyval.node) = add_child(print, (yyvsp[(3) - (4)].node));
		}
    break;

  case 37:
#line 329 "gocompiler.y"
    {
			(yyval.node) = NULL;
			errortag = 1;
		}
    break;

  case 38:
#line 336 "gocompiler.y"
    {
			(yyval.node) = create_node("StrLit", (yyvsp[(1) - (1)].string), (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 1);
		}
    break;

  case 39:
#line 340 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 40:
#line 346 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 41:
#line 350 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 42:
#line 356 "gocompiler.y"
    {
			if ((yyvsp[(1) - (3)].node) == NULL && (yyvsp[(3) - (3)].node) == NULL) (yyval.node) = NULL;
			else if ((yyvsp[(1) - (3)].node) == NULL) (yyval.node) = (yyvsp[(3) - (3)].node);
			else if ((yyvsp[(3) - (3)].node) == NULL) (yyval.node) = (yyvsp[(1) - (3)].node);
			else (yyval.node) = add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));

		}
    break;

  case 43:
#line 364 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 44:
#line 370 "gocompiler.y"
    {
			struct node * block = create_node("Block", "", 0, 0, 0);
			if ((yyvsp[(3) - (4)].node) != NULL) add_child(block, (yyvsp[(3) - (4)].node));
			(yyval.node) = block;
		}
    break;

  case 45:
#line 376 "gocompiler.y"
    {
			(yyval.node) = create_node("Block", "", 0, 0, 0);
		}
    break;

  case 46:
#line 382 "gocompiler.y"
    {
			struct node * parseArgs = create_node("ParseArgs", "", 0, 0, 0);
			add_child(parseArgs, create_node("Id", (yyvsp[(1) - (11)].string), (yylsp[(1) - (11)]).first_line, (yylsp[(1) - (11)]).first_column, 1));
			(yyval.node) = add_child(parseArgs, (yyvsp[(9) - (11)].node));
		}
    break;

  case 47:
#line 388 "gocompiler.y"
    {
			(yyval.node) = NULL;
			errortag = 1;
		}
    break;

  case 48:
#line 395 "gocompiler.y"
    {
			struct node * call = create_node("Call", "", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, 0);
			add_child(call, create_node("Id", (yyvsp[(1) - (4)].string), (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, 1));
			if ((yyvsp[(3) - (4)].node) != NULL) add_child(call, (yyvsp[(3) - (4)].node));
			(yyval.node) = call;
		}
    break;

  case 49:
#line 402 "gocompiler.y"
    {
			(yyval.node) = NULL;
			errortag = 1;
		}
    break;

  case 50:
#line 409 "gocompiler.y"
    {	
			if ((yyvsp[(1) - (2)].node) == NULL && (yyvsp[(2) - (2)].node) == NULL) (yyval.node) = NULL;
			else if((yyvsp[(1) - (2)].node)==NULL) (yyval.node) = (yyvsp[(2) - (2)].node);
			else if((yyvsp[(2) - (2)].node)==NULL) (yyval.node) = (yyvsp[(1) - (2)].node);
			else (yyval.node) = add_sibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
		}
    break;

  case 51:
#line 416 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 52:
#line 422 "gocompiler.y"
    {
			if ((yyvsp[(2) - (3)].node) == NULL && (yyvsp[(3) - (3)].node) == NULL) (yyval.node) = NULL;
			else if((yyvsp[(2) - (3)].node)==NULL) (yyval.node) = (yyvsp[(3) - (3)].node);
			else if((yyvsp[(3) - (3)].node)==NULL) (yyval.node) = (yyvsp[(2) - (3)].node);
			else (yyval.node) = add_sibling((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));	
		}
    break;

  case 53:
#line 429 "gocompiler.y"
    {
			(yyval.node) = NULL;
		}
    break;

  case 54:
#line 435 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(2) - (3)].node);
		}
    break;

  case 55:
#line 439 "gocompiler.y"
    {
			(yyval.node) = NULL;
			errortag = 1;
		}
    break;

  case 56:
#line 444 "gocompiler.y"
    {
			(yyval.node) = add_child(create_node("Not", "!", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, 0), (yyvsp[(2) - (2)].node));
		}
    break;

  case 57:
#line 448 "gocompiler.y"
    {
			(yyval.node) = add_child(create_node("Minus", "-", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, 0), (yyvsp[(2) - (2)].node));
		}
    break;

  case 58:
#line 452 "gocompiler.y"
    {
			(yyval.node) = add_child(create_node("Plus", "-", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, 0), (yyvsp[(2) - (2)].node));
		}
    break;

  case 59:
#line 456 "gocompiler.y"
    {
			struct node * add = create_node("Add", "+", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(add, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(add, (yyvsp[(3) - (3)].node));
		}
    break;

  case 60:
#line 462 "gocompiler.y"
    {
			struct node * sub = create_node("Sub", "-", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(sub, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(sub, (yyvsp[(3) - (3)].node));
		}
    break;

  case 61:
#line 468 "gocompiler.y"
    {
			struct node * mul = create_node("Mul", "*", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(mul, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(mul, (yyvsp[(3) - (3)].node));
		}
    break;

  case 62:
#line 474 "gocompiler.y"
    {
			struct node * div = create_node("Div", "/", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(div, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(div, (yyvsp[(3) - (3)].node));
		}
    break;

  case 63:
#line 480 "gocompiler.y"
    {
			struct node * mod = create_node("Mod", "%", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(mod, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(mod, (yyvsp[(3) - (3)].node));
		}
    break;

  case 64:
#line 486 "gocompiler.y"
    {
			struct node * or = create_node("Or", "||", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(or, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(or, (yyvsp[(3) - (3)].node));
		}
    break;

  case 65:
#line 492 "gocompiler.y"
    {
			struct node * and = create_node("And", "&&", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(and, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(and, (yyvsp[(3) - (3)].node));
		}
    break;

  case 66:
#line 498 "gocompiler.y"
    {
			struct node * lt = create_node("Lt", "<", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(lt, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(lt, (yyvsp[(3) - (3)].node));
		}
    break;

  case 67:
#line 504 "gocompiler.y"
    {
			struct node * gt = create_node("Gt", ">", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(gt, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(gt, (yyvsp[(3) - (3)].node));
		}
    break;

  case 68:
#line 510 "gocompiler.y"
    {
			struct node * eq = create_node("Eq", "==", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(eq, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(eq, (yyvsp[(3) - (3)].node));
		}
    break;

  case 69:
#line 516 "gocompiler.y"
    {
			struct node * ne = create_node("Ne", "!=", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(ne, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(ne, (yyvsp[(3) - (3)].node));
		}
    break;

  case 70:
#line 522 "gocompiler.y"
    {
			struct node * le = create_node("Le", "<=", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(le, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(le, (yyvsp[(3) - (3)].node));
		}
    break;

  case 71:
#line 528 "gocompiler.y"
    {
			struct node * ge = create_node("Ge", ">=", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, 0);
			add_child(ge, (yyvsp[(1) - (3)].node));
			(yyval.node) = add_child(ge, (yyvsp[(3) - (3)].node));
		}
    break;

  case 72:
#line 534 "gocompiler.y"
    {
			(yyval.node) = create_node("IntLit", (yyvsp[(1) - (1)].string), (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 1);
		}
    break;

  case 73:
#line 538 "gocompiler.y"
    {
			(yyval.node) = create_node("RealLit", (yyvsp[(1) - (1)].string), (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 1);
		}
    break;

  case 74:
#line 542 "gocompiler.y"
    {
			(yyval.node) = create_node("Id", (yyvsp[(1) - (1)].string), (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, 1);
		}
    break;

  case 75:
#line 546 "gocompiler.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;


/* Line 1267 of yacc.c.  */
#line 2285 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 551 "gocompiler.y"


int main(int argc, char **argv) {
	yydebug = 0;
	errortag = 0;

    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            printflag = 1;
			yylex();
        }

		if (strcmp(argv[1], "-t") == 0) {
			printflag = 0;
			yyparse();
			if (!errortag) {
				print_node(root, 0);
			}
		}

		if (strcmp(argv[1], "-s") == 0) {
			//code for semantic analysing
			yyparse();
			check_root(root);
			print_table();
			annotate_tree(root, global_symtab);
			print_annotated_node(root, 0);

			//cleaning up
			free_table(global_symtab);
		}

		if (strcmp(argv[1], "-debug") == 0) {
			yydebug = 1;
			printflag = 0;
			yyparse();
		}
    }

	else {
		printflag = 0;
		yyparse();
	}
	yylex_destroy();
    return 0;
}

