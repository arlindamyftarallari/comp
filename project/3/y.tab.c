/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "gocompiler.y" /* yacc.c:339  */

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
	int stmtcount = 0;

#line 86 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 21 "gocompiler.y" /* yacc.c:355  */

	char * string;
	struct node * node;

#line 223 "y.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 254 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    56,    65,    72,    76,    80,    84,    88,
      94,    98,   104,   158,   169,   174,   187,   192,   197,   202,
     207,   223,   231,   236,   244,   252,   257,   261,   266,   271,
     278,   289,   298,   306,   312,   316,   320,   325,   332,   336,
     342,   347,   352,   361,   366,   373,   378,   384,   391,   398,
     405,   413,   418,   426,   431,   435,   440,   444,   448,   452,
     458,   464,   470,   476,   482,   488,   494,   500,   506,   512,
     518,   524,   530,   534,   538,   542
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "BLANKID", "PACKAGE",
  "RETURN", "AND", "ASSIGN", "STAR", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LSQ", "LT", "CMDARGS", "MINUS", "MOD", "NE",
  "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ", "ELSE", "FOR", "IF", "VAR",
  "INT", "FLOAT32", "BOOL", "STRING", "PRINT", "PARSEINT", "FUNC",
  "RESERVED", "STRLIT", "INTLIT", "ID", "REALLIT", "UNARY", "$accept",
  "Program", "Declarations", "Type", "VarDeclaration", "VarSpec", "IdOpt",
  "FuncDeclaration", "ParametersOpt", "TypeOpt", "Parameters", "OptParam",
  "FuncBody", "VarsAndStatements", "varsAndStatementsOpt", "Statement",
  "printArgs", "ExprOpt", "StatementOpt", "ElseOpt", "ParseArgs",
  "FuncInvocation", "CallParams", "OptCallParams", "Expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -52

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -13,    51,    50,   -85,   -26,   -15,    16,   -85,    60,
      61,    21,    57,   -85,    55,   -26,   -26,    72,    33,    89,
      35,   -85,   -85,    53,    57,   -85,   -85,   -85,   -85,   -85,
      89,    56,   -85,   -85,   -85,    75,    89,    49,   -85,   -85,
      82,    89,   -85,   -85,    75,    67,   -85,   -85,    96,    77,
     -85,    96,    96,    84,    10,   -85,    99,   -85,   -85,   -85,
      45,    96,    96,    96,   -85,    97,   -85,   -85,   -85,   216,
     103,    91,   101,   176,    86,    96,   115,     4,   -85,   104,
     156,   -85,   -85,   -85,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    77,   -85,    77,
      77,   -85,   105,   216,   216,   119,   106,   107,   196,   -85,
     -85,   252,   -85,   -85,    65,    65,    65,    65,    65,    -3,
     -85,    65,   236,    -3,   -85,   109,   110,   -85,   111,   -85,
     -85,    96,   -85,   -85,   108,   126,   196,   130,   -85,     2,
     -85,    77,   124,   137,   132,   -85,    96,   -85,   135,   125,
     -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,    43,    20,   117,   155,   147,   -85,   -85,   -85,
     -85,   129,   -85,   -85,   -85,   131,   -85,   123,   -84,   -85,
     -85,   -45,   -85,    44,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    29,     9,    13,    19,    10,    31,    40,
      32,    38,    43,    45,    56,    70,   102,    67,    71,   138,
      58,    68,   107,   132,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    73,    11,   142,    59,   106,    85,     6,    86,    80,
      81,    82,    83,   124,     7,   125,   126,     1,    75,    93,
      76,    60,   143,   103,   104,    61,   108,    77,    62,    12,
      63,     3,   -51,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    79,    64,    65,    66,
      35,     4,    59,     5,    59,    59,    39,   144,    21,    22,
      14,    44,    60,    15,    16,    12,    61,    18,    47,    62,
     -28,    63,    20,    48,    85,    23,    86,    24,    47,    30,
     136,    33,    49,    48,    36,    37,    92,    93,    64,    65,
      66,    96,    49,    41,    50,   148,    59,    42,    51,    52,
       6,    74,    78,    60,   -43,    53,    97,    61,    51,    52,
      62,    54,    63,    60,    77,    53,    99,    61,    98,   105,
      62,    54,    63,    25,    26,    27,    28,   128,   101,    64,
      65,    66,   109,   127,   129,   130,   133,   134,   137,    64,
      65,    66,    84,   139,    85,   141,    86,    87,    88,    89,
     135,    90,   145,   150,    91,   146,    92,    93,    94,   147,
      95,    96,    55,    84,   149,    85,    17,    86,    87,    88,
      89,    34,    90,    46,    72,    91,    57,    92,    93,    94,
     140,    95,    96,    84,   110,    85,     0,    86,    87,    88,
      89,   100,    90,     0,     0,    91,     0,    92,    93,    94,
       0,    95,    96,    84,     0,    85,   131,    86,    87,    88,
      89,     0,    90,     0,     0,    91,     0,    92,    93,    94,
       0,    95,    96,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,    91,     0,    92,    93,    94,
       0,    95,    96,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,    91,     0,    92,    93,    94,
       0,    85,    96,    86,    87,    88,    89,     0,    90,     0,
       0,    91,     0,    92,    93,    94,     0,     0,    96
};

static const yytype_int16 yycheck[] =
{
      45,    52,    17,     1,    49,     1,     9,    33,    11,    60,
      61,    62,    63,    97,    40,    99,   100,     5,     8,    22,
      10,    17,    20,    74,    75,    21,    77,    17,    24,    44,
      26,    44,    28,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     1,    43,    44,    45,
      30,     0,    97,     3,    99,   100,    36,   141,    15,    16,
      44,    41,    17,     3,     3,    44,    21,    10,     1,    24,
       3,    26,    17,     6,     9,     3,    11,    44,     1,    44,
     131,    28,    15,     6,    28,    10,    21,    22,    43,    44,
      45,    26,    15,    44,    27,   146,   141,    15,    31,    32,
      33,    17,     3,    17,    27,    38,     3,    21,    31,    32,
      24,    44,    26,    17,    17,    38,    15,    21,    27,     4,
      24,    44,    26,    34,    35,    36,    37,     8,    42,    43,
      44,    45,    28,    28,    28,    28,    27,    27,    30,    43,
      44,    45,     7,    17,     9,    15,    11,    12,    13,    14,
      39,    16,    28,    28,    19,    18,    21,    22,    23,    27,
      25,    26,    45,     7,    29,     9,    11,    11,    12,    13,
      14,    24,    16,    44,    51,    19,    45,    21,    22,    23,
     136,    25,    26,     7,    28,     9,    -1,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    -1,    21,    22,    23,
      -1,    25,    26,     7,    -1,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    19,    -1,    21,    22,    23,
      -1,    25,    26,     7,    -1,     9,    -1,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    19,    -1,    21,    22,    23,
      -1,    25,    26,     7,    -1,     9,    -1,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    19,    -1,    21,    22,    23,
      -1,     9,    26,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    48,    44,     0,     3,    33,    40,    49,    51,
      54,    17,    44,    52,    44,     3,     3,    52,    10,    53,
      17,    49,    49,     3,    44,    34,    35,    36,    37,    50,
      44,    55,    57,    28,    53,    50,    28,    10,    58,    50,
      56,    44,    15,    59,    50,    60,    58,     1,     6,    15,
      27,    31,    32,    38,    44,    51,    61,    62,    67,    68,
      17,    21,    24,    26,    43,    44,    45,    64,    68,    71,
      62,    65,    64,    71,    17,     8,    10,    17,     3,     1,
      71,    71,    71,    71,     7,     9,    11,    12,    13,    14,
      16,    19,    21,    22,    23,    25,    26,     3,    27,    15,
      15,    42,    63,    71,    71,     4,     1,    69,    71,    28,
      28,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    65,    65,    65,    28,     8,    28,
      28,    10,    70,    27,    27,    39,    71,    30,    66,    17,
      70,    15,     1,    20,    65,    28,    18,    27,    71,    29,
      28
};

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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
#line 49 "gocompiler.y" /* yacc.c:1646  */
    {
		root = create_node("Program", "");
		if ((yyvsp[0].node) != NULL) add_child(root, (yyvsp[0].node));
		(yyval.node) = root;
	}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "gocompiler.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].node) != NULL) {
				add_sibling((yyvsp[-2].node), (yyvsp[0].node));
			}
			(yyval.node) = (yyvsp[-2].node);

		}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "gocompiler.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].node) != NULL) add_sibling((yyvsp[-2].node), (yyvsp[0].node));
			(yyval.node) = (yyvsp[-2].node);
		}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "gocompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("Int", "");
		}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("Float32", "");
		}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 85 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("Bool", "");
		}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 89 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("String", "");
		}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node );
		}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[-2].node );
		}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * varDecl = create_node("VarDecl", "");
			add_child(varDecl, (yyvsp[0].node));
			add_child(varDecl, create_node("Id", (yyvsp[-2].string)));
			
			if ((yyvsp[-1].node ) != NULL) {
				struct node * newId = (yyvsp[-1].node );
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

				newId = (yyvsp[-1].node );
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
					varDecls[n] = create_node("VarDecl", "");
					auxType = create_node((yyvsp[0].node)->type, "");
					add_child(varDecls[n], auxType);
					add_child(varDecls[n], ids[n]);
					i++;
				}
				
				if (i>=1) add_sibling(varDecl, varDecls[0]);

				for (int j=0; j+1<i; j++) {
					add_sibling(varDecls[j], varDecls[j+1]);
				}
			}

			(yyval.node ) = varDecl;	
		}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 159 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * id = create_node("Id", (yyvsp[-1].string));
			if ((yyvsp[0].node ) == NULL) {
				(yyval.node ) = id;
			}
			else {
				(yyval.node ) = add_sibling(id, (yyvsp[0].node ));
			}
		}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 169 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = NULL;
		}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 175 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * funcDecl = create_node("FuncDecl", "");
			struct node * funcHeader = create_node("FuncHeader", "");
			add_child(funcHeader, create_node("Id", (yyvsp[-5].string)));
			if ((yyvsp[-1].node ) != NULL) add_child(funcHeader, (yyvsp[-1].node ));
			add_child(funcHeader, (yyvsp[-3].node));
			add_child(funcDecl, funcHeader);
			add_child(funcDecl, (yyvsp[0].node));
			(yyval.node) = funcDecl;
		}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 188 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 192 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("FuncParams", ""); //this node is not going to have any sons, but it is mandatory
		}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = (yyvsp[0].node);
		}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 202 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = NULL;
		}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 208 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * funcParams = create_node("FuncParams", "");
			struct node * paramDecl = create_node("ParamDecl", "");
			add_child(paramDecl, (yyvsp[-1].node));
			add_child(paramDecl, create_node("Id", (yyvsp[-2].string)));
			add_child(funcParams, paramDecl);

			if ((yyvsp[0].node) != NULL) {
				add_child(funcParams, (yyvsp[0].node));
			}

			(yyval.node) = funcParams;
		}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * paramDecl = create_node("ParamDecl", "");
			add_child(paramDecl, (yyvsp[-1].node));
			(yyval.node) = add_child(paramDecl, create_node("Id", (yyvsp[-2].string)));
			if ((yyvsp[0].node) != NULL) add_sibling(paramDecl, (yyvsp[0].node));
		}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 231 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = NULL;
		}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node* funcBody = create_node("FuncBody", "");
			if ((yyvsp[-1].node) != NULL) add_child(funcBody, (yyvsp[-1].node));
			(yyval.node) = funcBody;
		}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 245 "gocompiler.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].node ) == NULL && (yyvsp[-2].node) == NULL) (yyval.node) = NULL;
			else if ((yyvsp[-2].node) == NULL) (yyval.node) = (yyvsp[-1].node );
			else if ((yyvsp[-1].node ) == NULL) (yyval.node) = (yyvsp[-2].node);
			else (yyval.node) = add_sibling((yyvsp[-2].node), (yyvsp[-1].node ));
		}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 252 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = NULL;
		}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 258 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = (yyvsp[0].node);
		}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 262 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = (yyvsp[0].node);
		}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 266 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = NULL;
		}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 272 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * assign = create_node("Assign", "");
			add_child(assign, create_node("Id", (yyvsp[-2].string)));
			if((yyvsp[0].node)!=NULL) (yyval.node) = add_child(assign, (yyvsp[0].node));
			else (yyval.node) = NULL;
		}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 279 "gocompiler.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->bro != NULL) { //creating block for multiple statements
					struct node * block = create_node("Block", "");
					add_child(block, (yyvsp[-1].node));
					(yyval.node) = block;
				}
				else { //there is only 1 statement -> no need for block
					(yyval.node) = (yyvsp[-1].node);
				}
			}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 290 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * iff = create_node("If", "");
			if ((yyvsp[-4].node)!=NULL) add_child(iff, (yyvsp[-4].node));
			struct node * block = create_node("Block", "");
			if ((yyvsp[-2].node) != NULL) add_child(block, (yyvsp[-2].node));	
			add_child(iff, block);
			(yyval.node) = add_child(iff, (yyvsp[0].node));
		}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 299 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * forr = create_node("For", "");
			if ((yyvsp[-3].node) != NULL) add_child(forr, (yyvsp[-3].node));
			struct node * block = create_node("Block", "");
			if ((yyvsp[-1].node) != NULL) add_child(block, (yyvsp[-1].node));
			(yyval.node) = add_child(forr, block);
		}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 307 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * returnn = create_node("Return", "");
			if ((yyvsp[0].node) != NULL) add_child(returnn, (yyvsp[0].node));
			(yyval.node) = returnn;
		}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 313 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node );
		}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 317 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 321 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * print = create_node("Print", "");
			(yyval.node) = add_child(print, (yyvsp[-1].node));
		}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 326 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = NULL;
			errortag = 1;
		}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 333 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("StrLit", (yyvsp[0].string));
		}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 337 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 343 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 347 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = NULL;
		}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 353 "gocompiler.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].node) == NULL && (yyvsp[0].node) == NULL) (yyval.node) = NULL;
			else if ((yyvsp[-2].node) == NULL) (yyval.node) = (yyvsp[0].node);
			else if ((yyvsp[0].node) == NULL) (yyval.node) = (yyvsp[-2].node);
			else (yyval.node) = add_sibling((yyvsp[-2].node), (yyvsp[0].node));

		}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 361 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = NULL;
		}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 367 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * block = create_node("Block", "");
			if ((yyvsp[-1].node) != NULL) add_child(block, (yyvsp[-1].node));
			(yyval.node) = block;
		}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 373 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("Block", "");
		}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 379 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * parseArgs = create_node("ParseArgs", "");
			add_child(parseArgs, create_node("Id", (yyvsp[-10].string)));
			(yyval.node) = add_child(parseArgs, (yyvsp[-2].node));
		}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 385 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = NULL;
			errortag = 1;
		}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 392 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * call = create_node("Call", "");
			add_child(call, create_node("Id", (yyvsp[-3].string)));
			if ((yyvsp[-1].node ) != NULL) add_child(call, (yyvsp[-1].node ));
			(yyval.node ) = call;
		}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 399 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = NULL;
			errortag = 1;
		}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 406 "gocompiler.y" /* yacc.c:1646  */
    {	
			if ((yyvsp[-1].node) == NULL && (yyvsp[0].node ) == NULL) (yyval.node ) = NULL;
			else if((yyvsp[-1].node)==NULL) (yyval.node ) = (yyvsp[0].node );
			else if((yyvsp[0].node )==NULL) (yyval.node ) = (yyvsp[-1].node);
			else (yyval.node ) = add_sibling((yyvsp[-1].node), (yyvsp[0].node ));
		}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 413 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = NULL;
		}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 419 "gocompiler.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].node) == NULL && (yyvsp[0].node ) == NULL) (yyval.node ) = NULL;
			else if((yyvsp[-1].node)==NULL) (yyval.node ) = (yyvsp[0].node );
			else if((yyvsp[0].node )==NULL) (yyval.node ) = (yyvsp[-1].node);
			else (yyval.node ) = add_sibling((yyvsp[-1].node), (yyvsp[0].node ));	
		}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 426 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node ) = NULL;
		}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 432 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[-1].node);
		}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 436 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = NULL;
			errortag = 1;
		}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 441 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = add_child(create_node("Not", ""), (yyvsp[0].node));
		}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 445 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = add_child(create_node("Minus", ""), (yyvsp[0].node));
		}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 449 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = add_child(create_node("Plus", ""), (yyvsp[0].node));
		}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 453 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * add = create_node("Add", "");
			add_child(add, (yyvsp[-2].node));
			(yyval.node) = add_child(add, (yyvsp[0].node));
		}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 459 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * sub = create_node("Sub", "");
			add_child(sub, (yyvsp[-2].node));
			(yyval.node) = add_child(sub, (yyvsp[0].node));
		}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 465 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * mul = create_node("Mul", "");
			add_child(mul, (yyvsp[-2].node));
			(yyval.node) = add_child(mul, (yyvsp[0].node));
		}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 471 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * div = create_node("Div", "");
			add_child(div, (yyvsp[-2].node));
			(yyval.node) = add_child(div, (yyvsp[0].node));
		}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 477 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * mod = create_node("Mod", "");
			add_child(mod, (yyvsp[-2].node));
			(yyval.node) = add_child(mod, (yyvsp[0].node));
		}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 483 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * or = create_node("Or", "");
			add_child(or, (yyvsp[-2].node));
			(yyval.node) = add_child(or, (yyvsp[0].node));
		}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 489 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * and = create_node("And", "");
			add_child(and, (yyvsp[-2].node));
			(yyval.node) = add_child(and, (yyvsp[0].node));
		}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 495 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * lt = create_node("Lt", "");
			add_child(lt, (yyvsp[-2].node));
			(yyval.node) = add_child(lt, (yyvsp[0].node));
		}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 501 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * gt = create_node("Gt", "");
			add_child(gt, (yyvsp[-2].node));
			(yyval.node) = add_child(gt, (yyvsp[0].node));
		}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 507 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * eq = create_node("Eq", "");
			add_child(eq, (yyvsp[-2].node));
			(yyval.node) = add_child(eq, (yyvsp[0].node));
		}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 513 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * ne = create_node("Ne", "");
			add_child(ne, (yyvsp[-2].node));
			(yyval.node) = add_child(ne, (yyvsp[0].node));
		}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 519 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * le = create_node("Le", "");
			add_child(le, (yyvsp[-2].node));
			(yyval.node) = add_child(le, (yyvsp[0].node));
		}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 525 "gocompiler.y" /* yacc.c:1646  */
    {
			struct node * ge = create_node("Ge", "");
			add_child(ge, (yyvsp[-2].node));
			(yyval.node) = add_child(ge, (yyvsp[0].node));
		}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 531 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("IntLit", (yyvsp[0].string));
		}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 535 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("RealLit", (yyvsp[0].string));
		}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 539 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = create_node("Id", (yyvsp[0].string));
		}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 543 "gocompiler.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node );
		}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2299 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 548 "gocompiler.y" /* yacc.c:1906  */


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
