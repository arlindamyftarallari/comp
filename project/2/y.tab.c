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
#define YYLSP_NEEDED 0



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
     MINUS = 275,
     MOD = 276,
     NE = 277,
     NOT = 278,
     OR = 279,
     PLUS = 280,
     RBRACE = 281,
     RPAR = 282,
     RSQ = 283,
     ELSE = 284,
     FOR = 285,
     IF = 286,
     VAR = 287,
     INT = 288,
     FLOAT32 = 289,
     BOOL = 290,
     STRING = 291,
     PRINT = 292,
     PARSEINT = 293,
     FUNC = 294,
     CMDARGS = 295,
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
#define MINUS 275
#define MOD 276
#define NE 277
#define NOT 278
#define OR 279
#define PLUS 280
#define RBRACE 281
#define RPAR 282
#define RSQ 283
#define ELSE 284
#define FOR 285
#define IF 286
#define VAR 287
#define INT 288
#define FLOAT32 289
#define BOOL 290
#define STRING 291
#define PRINT 292
#define PARSEINT 293
#define FUNC 294
#define CMDARGS 295
#define RESERVED 296
#define STRLIT 297
#define INTLIT 298
#define ID 299
#define REALLIT 300
#define UNARY 301




/* Copy the first part of user declarations.  */
#line 1 "gocompiler.y"

	/* 
	Hugo Brink 2016227204
	Madalena Santos 2016226726
	*/

	#include <stdio.h>
	#include <string.h>
	#include "structures.h"

	#define YYDEBUG 1

	struct node * root = NULL;
	int yylex(void);
	int yylex_destroy();
	void yyerror(const char *s);
	int errortag = 0, printflag = 0;


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



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 225 "y.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   272

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
      48,     0,    -1,     5,    44,     3,    49,    -1,    51,     3,
      49,    -1,    54,     3,    49,    -1,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    32,    52,    -1,    32,    17,
      52,     3,    27,    -1,    44,    53,    50,    -1,    10,    44,
      53,    -1,    -1,    39,    44,    17,    55,    27,    56,    59,
      -1,    57,    -1,    -1,    50,    -1,    -1,    44,    50,    58,
      -1,    10,    44,    50,    58,    -1,    -1,    15,    60,    26,
      -1,    60,    61,     3,    -1,    -1,    51,    -1,    62,    -1,
      -1,    44,     8,    71,    -1,    15,    65,    26,    -1,    31,
      71,    15,    65,    26,    66,    -1,    30,    64,    15,    65,
      26,    -1,     6,    64,    -1,    68,    -1,    67,    -1,    37,
      17,    63,    27,    -1,     1,    -1,    42,    -1,    71,    -1,
      71,    -1,    -1,    62,     3,    65,    -1,    -1,    29,    15,
      65,    26,    -1,    -1,    44,    10,     4,     8,    38,    17,
      40,    18,    71,    28,    27,    -1,    44,    10,     4,     8,
      38,    17,     1,    27,    -1,    44,    17,    69,    27,    -1,
      44,    17,     1,    27,    -1,    71,    70,    -1,    -1,    10,
      71,    70,    -1,    -1,    17,    71,    27,    -1,    17,     1,
      27,    -1,    23,    71,    -1,    20,    71,    -1,    25,    71,
      -1,    71,    25,    71,    -1,    71,    20,    71,    -1,    71,
       9,    71,    -1,    71,    11,    71,    -1,    71,    21,    71,
      -1,    71,    24,    71,    -1,    71,     7,    71,    -1,    71,
      19,    71,    -1,    71,    14,    71,    -1,    71,    12,    71,
      -1,    71,    22,    71,    -1,    71,    16,    71,    -1,    71,
      13,    71,    -1,    43,    -1,    45,    -1,    44,    -1,    68,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    49,    56,    62,    65,    68,    71,    74,
      79,    82,    87,    95,   105,   108,   120,   123,   129,   132,
     137,   152,   157,   162,   173,   184,   189,   192,   195,   198,
     203,   206,   212,   217,   220,   223,   226,   229,   234,   237,
     242,   245,   248,   254,   257,   263,   266,   269,   274,   280,
     286,   294,   297,   304,   309,   312,   316,   319,   322,   325,
     330,   335,   340,   345,   350,   355,   360,   365,   370,   375,
     380,   385,   390,   393,   396,   399
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "BLANKID", "PACKAGE",
  "RETURN", "AND", "ASSIGN", "STAR", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LSQ", "LT", "MINUS", "MOD", "NE", "NOT", "OR",
  "PLUS", "RBRACE", "RPAR", "RSQ", "ELSE", "FOR", "IF", "VAR", "INT",
  "FLOAT32", "BOOL", "STRING", "PRINT", "PARSEINT", "FUNC", "CMDARGS",
  "RESERVED", "STRLIT", "INTLIT", "ID", "REALLIT", "UNARY", "$accept",
  "Program", "Declarations", "Type", "VarDeclaration", "VarSpec", "IdOpt",
  "FuncDeclaration", "ParametersOpt", "TypeOpt", "Parameters", "OptParam",
  "FuncBody", "VarsAndStatements", "varsAndStatementsOpt", "Statement",
  "Aux6", "ExprOpt", "StatementOpt", "ElseOpt", "ParseArgs",
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
       0,     0,     0,     0,    72,    74,    73,    33,    75,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    57,    56,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,    38,     0,    39,    29,     0,     0,     0,    53,    55,
      54,    65,    61,    62,    68,    71,    67,    70,    66,    60,
      63,    69,    64,    59,    42,     0,     0,    36,     0,    49,
      48,     0,    50,    32,    45,     0,    53,     0,    31,     0,
      52,     0,     0,     0,     0,    47,     0,    44,     0,     0,
      46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    29,     9,    13,    19,    10,    31,    40,
      32,    38,    43,    45,    56,    70,   102,    67,    71,   138,
      58,    68,   107,   132,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int16 yypact[] =
{
      -2,   -25,    31,    48,   -85,   -18,   -15,    12,   -85,    55,
      57,    17,    53,   -85,    56,   -18,   -18,    72,    32,    87,
      34,   -85,   -85,    52,    53,   -85,   -85,   -85,   -85,   -85,
      87,    54,   -85,   -85,   -85,    74,    87,    38,   -85,   -85,
      70,    87,   -85,   -85,    74,    68,   -85,   -85,    93,    71,
     -85,    93,    93,    75,    10,   -85,    84,   -85,   -85,   -85,
      45,    93,    93,    93,   -85,    76,   -85,   -85,   -85,   209,
      88,    78,    92,   171,    86,    93,   110,     5,   -85,    90,
     152,   -85,   -85,   -85,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    71,   -85,    71,
      71,   -85,    97,   209,   209,   111,    98,    99,   190,   -85,
     -85,   226,   -85,   -85,   241,   247,   247,   247,   247,    -4,
     -85,   241,   226,    -4,   -85,   101,   106,   -85,    95,   -85,
     -85,    93,   -85,   -85,   105,   118,   190,   125,   -85,     7,
     -85,    71,   115,   129,   123,   -85,    93,   -85,   132,   128,
     -85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,    51,    23,   113,   139,   138,   -85,   -85,   -85,
     -85,   126,   -85,   -85,   -85,   122,   -85,   124,   -84,   -85,
     -85,   -45,   -85,    33,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      59,    73,    11,     1,    59,    85,   106,    86,   142,    80,
      81,    82,    83,   124,     6,   125,   126,    93,    75,     3,
      76,     7,    60,   103,   104,    61,   108,    77,    62,    12,
      63,     4,   -51,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    79,   143,    64,    65,
      66,     5,    59,    35,    59,    59,    14,   144,    15,    39,
      16,    12,    60,    18,    44,    61,    21,    22,    62,    47,
      63,   -28,    47,    20,    48,    23,    24,    48,    30,    33,
     136,    36,    41,    49,    37,    42,    49,    78,    64,    65,
      66,    97,    74,    77,    50,   148,    59,   -43,    51,    52,
       6,    51,    52,    60,    98,    53,    61,    99,    53,    62,
      60,    63,    54,    61,   105,    54,    62,   109,    63,   128,
      25,    26,    27,    28,   127,   129,   130,   133,   101,    64,
      65,    66,   134,   135,   137,   139,    64,    65,    66,    84,
     141,    85,   145,    86,    87,    88,    89,   146,    90,   147,
      17,    91,    92,    93,    94,   150,    95,    96,    55,    84,
     149,    85,    34,    86,    87,    88,    89,    57,    90,   140,
      46,    91,    92,    93,    94,    72,    95,    96,    84,   110,
      85,     0,    86,    87,    88,    89,   100,    90,     0,     0,
      91,    92,    93,    94,     0,    95,    96,    84,     0,    85,
     131,    86,    87,    88,    89,     0,    90,     0,     0,    91,
      92,    93,    94,     0,    95,    96,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,    91,    92,
      93,    94,     0,    95,    96,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,    91,    92,    93,    94,     0,
      85,    96,    86,     0,    88,    89,    85,    90,    86,     0,
      91,    92,    93,     0,     0,     0,    96,    92,    93,     0,
       0,     0,    96
};

static const yytype_int16 yycheck[] =
{
      45,    52,    17,     5,    49,     9,     1,    11,     1,    60,
      61,    62,    63,    97,    32,    99,   100,    21,     8,    44,
      10,    39,    17,    74,    75,    20,    77,    17,    23,    44,
      25,     0,    27,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     1,    40,    43,    44,
      45,     3,    97,    30,    99,   100,    44,   141,     3,    36,
       3,    44,    17,    10,    41,    20,    15,    16,    23,     1,
      25,     3,     1,    17,     6,     3,    44,     6,    44,    27,
     131,    27,    44,    15,    10,    15,    15,     3,    43,    44,
      45,     3,    17,    17,    26,   146,   141,    26,    30,    31,
      32,    30,    31,    17,    26,    37,    20,    15,    37,    23,
      17,    25,    44,    20,     4,    44,    23,    27,    25,     8,
      33,    34,    35,    36,    27,    27,    27,    26,    42,    43,
      44,    45,    26,    38,    29,    17,    43,    44,    45,     7,
      15,     9,    27,    11,    12,    13,    14,    18,    16,    26,
      11,    19,    20,    21,    22,    27,    24,    25,    45,     7,
      28,     9,    24,    11,    12,    13,    14,    45,    16,   136,
      44,    19,    20,    21,    22,    51,    24,    25,     7,    27,
       9,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,     7,    -1,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    25,     7,    -1,     9,    -1,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,     9,    -1,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    19,    20,    21,    22,    -1,
       9,    25,    11,    -1,    13,    14,     9,    16,    11,    -1,
      19,    20,    21,    -1,    -1,    -1,    25,    20,    21,    -1,
      -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    48,    44,     0,     3,    32,    39,    49,    51,
      54,    17,    44,    52,    44,     3,     3,    52,    10,    53,
      17,    49,    49,     3,    44,    33,    34,    35,    36,    50,
      44,    55,    57,    27,    53,    50,    27,    10,    58,    50,
      56,    44,    15,    59,    50,    60,    58,     1,     6,    15,
      26,    30,    31,    37,    44,    51,    61,    62,    67,    68,
      17,    20,    23,    25,    43,    44,    45,    64,    68,    71,
      62,    65,    64,    71,    17,     8,    10,    17,     3,     1,
      71,    71,    71,    71,     7,     9,    11,    12,    13,    14,
      16,    19,    20,    21,    22,    24,    25,     3,    26,    15,
      15,    42,    63,    71,    71,     4,     1,    69,    71,    27,
      27,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    65,    65,    65,    27,     8,    27,
      27,    10,    70,    26,    26,    38,    71,    29,    66,    17,
      70,    15,     1,    40,    65,    27,    18,    26,    71,    28,
      27
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 42 "gocompiler.y"
    {
																		root = create_node("Program", "");
																		if ((yyvsp[(4) - (4)].node) != NULL) add_child(root, (yyvsp[(4) - (4)].node));
																		(yyval.node) = root;
																	}
    break;

  case 3:
#line 49 "gocompiler.y"
    {
																		if ((yyvsp[(3) - (3)].node) != NULL) {
																			add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
																		}
																		(yyval.node) = (yyvsp[(1) - (3)].node);

																	}
    break;

  case 4:
#line 56 "gocompiler.y"
    {
																		if ((yyvsp[(3) - (3)].node) != NULL) {
																			add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
																		}
																		(yyval.node) = (yyvsp[(1) - (3)].node);
																	}
    break;

  case 5:
#line 62 "gocompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 6:
#line 65 "gocompiler.y"
    {
																		(yyval.node) = create_node("Int", "");
																	}
    break;

  case 7:
#line 68 "gocompiler.y"
    {
																		(yyval.node) = create_node("Float32", "");
																	}
    break;

  case 8:
#line 71 "gocompiler.y"
    {
																		(yyval.node) = create_node("Bool", "");
																	}
    break;

  case 9:
#line 74 "gocompiler.y"
    {
																		(yyval.node) = create_node("String", "");
																	}
    break;

  case 10:
#line 79 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(2) - (2)].node);
																	}
    break;

  case 11:
#line 82 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(3) - (5)].node);
																	}
    break;

  case 12:
#line 87 "gocompiler.y"
    {
																		struct node * varDecl = create_node("VarDecl", "");
																		add_child(varDecl, (yyvsp[(3) - (3)].node));
																		if ((yyvsp[(2) - (3)].node) != NULL) add_child(varDecl, (yyvsp[(2) - (3)].node));
																		(yyval.node) = add_child(varDecl, create_node("Id", (yyvsp[(1) - (3)].string)));
																	}
    break;

  case 13:
#line 96 "gocompiler.y"
    {
																		struct node * id = create_node("Id", (yyvsp[(2) - (3)].string));
																		if ((yyvsp[(3) - (3)].node) == NULL) {
																			(yyval.node) = id;
																		}
																		else {
																			(yyval.node) = add_sibling(id, (yyvsp[(3) - (3)].node));
																		}
																	}
    break;

  case 14:
#line 105 "gocompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 15:
#line 108 "gocompiler.y"
    {
																		struct node * funcDecl = create_node("FuncDecl", "");
																		struct node * funcHeader = create_node("FuncHeader", "");
																		add_child(funcHeader, create_node("Id", (yyvsp[(2) - (7)].string)));
																		if ((yyvsp[(6) - (7)].node) != NULL) add_child(funcHeader, (yyvsp[(6) - (7)].node));
																		add_child(funcHeader, (yyvsp[(4) - (7)].node));
																		add_child(funcDecl, funcHeader);
																		add_child(funcDecl, (yyvsp[(7) - (7)].node));
																		(yyval.node) = funcDecl;
																	}
    break;

  case 16:
#line 120 "gocompiler.y"
    {
																	
																	}
    break;

  case 17:
#line 123 "gocompiler.y"
    {
																		(yyval.node) = create_node("FuncParams", "");
																		//this node is not going to have any sons, but it is mandatory
																	}
    break;

  case 18:
#line 129 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(1) - (1)].node);
																	}
    break;

  case 19:
#line 132 "gocompiler.y"
    {
																		(yyval.node) = NULL;
																	}
    break;

  case 20:
#line 137 "gocompiler.y"
    {
																		struct node * funcParams = create_node("FuncParams", "");
																		struct node * paramDecl = create_node("ParamDecl", "");
																		add_child(paramDecl, (yyvsp[(2) - (3)].node));
																		add_child(paramDecl, create_node("Id", (yyvsp[(1) - (3)].string)));
																		add_child(funcParams, paramDecl);

																		if ((yyvsp[(3) - (3)].node) != NULL) {
																			add_child(funcParams, (yyvsp[(3) - (3)].node));
																		}

																		(yyval.node) = funcParams;
																	}
    break;

  case 21:
#line 152 "gocompiler.y"
    {
																		struct node * paramDecl = create_node("ParamDecl", "");
																		add_child(paramDecl, (yyvsp[(3) - (4)].node));
																		(yyval.node) = add_child(paramDecl, create_node("Id", (yyvsp[(2) - (4)].string)));
																	}
    break;

  case 22:
#line 157 "gocompiler.y"
    {
																		(yyval.node) = NULL;
																	}
    break;

  case 23:
#line 162 "gocompiler.y"
    {
																		struct node* funcBody = create_node("FuncBody", "");
																		if ((yyvsp[(2) - (3)].node) == NULL) {
																			(yyval.node) = funcBody;
																		}
																		else {
																			(yyval.node) = add_child(funcBody, (yyvsp[(2) - (3)].node));
																		}
																	}
    break;

  case 24:
#line 173 "gocompiler.y"
    {
																		if ((yyvsp[(1) - (3)].node) == NULL && (yyvsp[(2) - (3)].node) != NULL) {
																			(yyval.node) = (yyvsp[(2) - (3)].node);
																		}
																		else if ((yyvsp[(1) - (3)].node) != NULL && (yyvsp[(2) - (3)].node) == NULL) {
																			(yyval.node) = (yyvsp[(1) - (3)].node);
																		}
																		else {
																			(yyval.node) = add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
																		}
																	}
    break;

  case 25:
#line 184 "gocompiler.y"
    {
																		(yyval.node) = NULL;
																	}
    break;

  case 26:
#line 189 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(1) - (1)].node);
																	}
    break;

  case 27:
#line 192 "gocompiler.y"
    {
																	
																	}
    break;

  case 28:
#line 195 "gocompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 29:
#line 198 "gocompiler.y"
    {
																		struct node * assign = create_node("Assign", "");
																		add_child(assign, create_node("Id", (yyvsp[(1) - (3)].string)));
																		(yyval.node) = add_child(assign, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 30:
#line 203 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(2) - (3)].node);
																	}
    break;

  case 31:
#line 206 "gocompiler.y"
    {
																		struct node * iff = create_node("If", "");
																		add_child(iff, (yyvsp[(2) - (6)].node));
																		add_child(iff, (yyvsp[(4) - (6)].node));
																		(yyval.node) = add_child(iff, (yyvsp[(6) - (6)].node));	
																	}
    break;

  case 32:
#line 212 "gocompiler.y"
    {
																		struct node * forr = create_node("For", "");
																		if ((yyvsp[(2) - (5)].node) != NULL) add_child(forr, (yyvsp[(2) - (5)].node));
																		(yyval.node) = add_child(forr, (yyvsp[(4) - (5)].node));
																	}
    break;

  case 33:
#line 217 "gocompiler.y"
    {
																		struct node * returnn = create_node()
																	}
    break;

  case 34:
#line 220 "gocompiler.y"
    {
																		
																	}
    break;

  case 35:
#line 223 "gocompiler.y"
    {
																		
																	}
    break;

  case 36:
#line 226 "gocompiler.y"
    {
																		
																	}
    break;

  case 37:
#line 229 "gocompiler.y"
    {
																		
																	}
    break;

  case 38:
#line 234 "gocompiler.y"
    {
																		
																	}
    break;

  case 39:
#line 237 "gocompiler.y"
    {
																		
																	}
    break;

  case 40:
#line 242 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(1) - (1)].node);
																	}
    break;

  case 41:
#line 245 "gocompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 42:
#line 248 "gocompiler.y"
    {
																		struct node * block = create_node("Block", "");
																		if ((yyvsp[(3) - (3)].node) != NULL) (yyval.node) = add_sibling((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
																		(yyval.node) = add_child(block, (yyvsp[(1) - (3)].node));

																	}
    break;

  case 43:
#line 254 "gocompiler.y"
    { (yyval.node) = NULL; }
    break;

  case 44:
#line 257 "gocompiler.y"
    {
																		struct node * block = create_node("Block", "");
																		if ((yyvsp[(3) - (4)].node) != NULL) add_child(block, (yyvsp[(3) - (4)].node));
																		(yyval.node) = block;

																	}
    break;

  case 45:
#line 263 "gocompiler.y"
    {(yyval.node) = create_node("Block", "");}
    break;

  case 46:
#line 266 "gocompiler.y"
    {

																			}
    break;

  case 47:
#line 269 "gocompiler.y"
    {
																		
																	}
    break;

  case 48:
#line 274 "gocompiler.y"
    {
																		struct node * call = create_node("Call", "");
																		add_child(call, create_node("Id", (yyvsp[(1) - (4)].string)));
																		if ((yyvsp[(3) - (4)].node) != NULL) add_child(call, (yyvsp[(3) - (4)].node));
																		(yyval.node) = call;
																	}
    break;

  case 49:
#line 280 "gocompiler.y"
    {
																		(yyval.node) = NULL;
																		errortag = 1;
																	}
    break;

  case 50:
#line 286 "gocompiler.y"
    {	
																		if ((yyvsp[(2) - (2)].node) == NULL) {
																			(yyval.node) = (yyvsp[(1) - (2)].node);
																		}
																		else {
																			(yyval.node) = add_sibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
																		}
																	}
    break;

  case 51:
#line 294 "gocompiler.y"
    {(yyval.node) = NULL;}
    break;

  case 52:
#line 297 "gocompiler.y"
    {
																		if ((yyvsp[(3) - (3)].node) == NULL) {
																			(yyval.node) = (yyvsp[(2) - (3)].node);
																		} else {
																			(yyval.node) = add_sibling((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
																		}	
																	}
    break;

  case 53:
#line 304 "gocompiler.y"
    {
																		(yyval.node) = NULL;
																	}
    break;

  case 54:
#line 309 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(2) - (3)].node);
																	}
    break;

  case 55:
#line 312 "gocompiler.y"
    {
																		(yyval.node) = NULL;
																		errortag = 1;
																	}
    break;

  case 56:
#line 316 "gocompiler.y"
    {	
																		(yyval.node) = add_child(create_node("Not", ""), (yyvsp[(2) - (2)].node));
																	}
    break;

  case 57:
#line 319 "gocompiler.y"
    {
																		(yyval.node) = add_child(create_node("Minus", ""), (yyvsp[(2) - (2)].node));
																	}
    break;

  case 58:
#line 322 "gocompiler.y"
    {
																		(yyval.node) = add_child(create_node("Plus", ""), (yyvsp[(2) - (2)].node));
																	}
    break;

  case 59:
#line 325 "gocompiler.y"
    {
																		struct node * add = create_node("Add", "");
																		add_child(add, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(add, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 60:
#line 330 "gocompiler.y"
    {	
																		struct node * sub = create_node("Sub", "");
																		add_child(sub, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(sub, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 61:
#line 335 "gocompiler.y"
    {
																		struct node * mul = create_node("Mul", "");
																		add_child(mul, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(mul, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 62:
#line 340 "gocompiler.y"
    {
																		struct node * div = create_node("Div", "");
																		add_child(div, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(div, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 63:
#line 345 "gocompiler.y"
    {
																			struct node * mod = create_node("Mod", "");
																		add_child(mod, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(mod, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 64:
#line 350 "gocompiler.y"
    {
																		struct node * or = create_node("Or", "");
																		add_child(or, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(or, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 65:
#line 355 "gocompiler.y"
    {
																		struct node * and = create_node("And", "");
																		add_child(and, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(and, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 66:
#line 360 "gocompiler.y"
    {
																		struct node * lt = create_node("Lt", "");
																		add_child(lt, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(lt, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 67:
#line 365 "gocompiler.y"
    {
																		struct node * gt = create_node("Gt", "");
																		add_child(gt, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(gt, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 68:
#line 370 "gocompiler.y"
    {
																		struct node * eq = create_node("Eq", "");
																			add_child(eq, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(eq, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 69:
#line 375 "gocompiler.y"
    {
																		struct node * ne = create_node("Ne", "");
																		add_child(ne, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(ne, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 70:
#line 380 "gocompiler.y"
    {
																		struct node * le = create_node("Le", "");
																		add_child(le, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(le, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 71:
#line 385 "gocompiler.y"
    {
																		struct node * ge = create_node("Ge", "");
																		add_child(ge, (yyvsp[(1) - (3)].node));
																		(yyval.node) = add_child(ge, (yyvsp[(3) - (3)].node));
																	}
    break;

  case 72:
#line 390 "gocompiler.y"
    {
																		(yyval.node) = create_node("IntLit", (yyvsp[(1) - (1)].string));
																	}
    break;

  case 73:
#line 393 "gocompiler.y"
    {
																		(yyval.node) = create_node("RealLit", (yyvsp[(1) - (1)].string));
																	}
    break;

  case 74:
#line 396 "gocompiler.y"
    {
																		(yyval.node) = create_node("Id", (yyvsp[(1) - (1)].string));
																	}
    break;

  case 75:
#line 399 "gocompiler.y"
    {
																		(yyval.node) = (yyvsp[(1) - (1)].node);
																	}
    break;


/* Line 1267 of yacc.c.  */
#line 2187 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 404 "gocompiler.y"


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


