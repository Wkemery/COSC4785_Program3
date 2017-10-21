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
#line 8 "program3.y" /* yacc.c:339  */



#include <iostream>
#include <FlexLexer.h>
#include "Node.h"
#include "Lexeme.h"

using namespace std;

extern vector<Node*> forest;
extern yyFlexLexer scanner;

#define yylex() scanner.yylex()

// need the function prototype for the parser.

void yyerror(const char *);


#line 87 "program3_bison.c" /* yacc.c:339  */

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
   by #include "program3_bison.h".  */
#ifndef YY_YY_PROGRAM3_BISON_H_INCLUDED
# define YY_YY_PROGRAM3_BISON_H_INCLUDED
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
    CLASS = 258,
    THIS = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    RETURN = 263,
    PRINT = 264,
    READ = 265,
    VOID = 266,
    NEW = 267,
    NULLKEYWORD = 268,
    INT = 269,
    ASSIGNOP = 270,
    DOTOP = 271,
    COMMA = 272,
    LPAREN = 273,
    RPAREN = 274,
    LBRACK = 275,
    RBRACK = 276,
    LBRACE = 277,
    RBRACE = 278,
    PLUS = 279,
    MINUS = 280,
    NOT = 281,
    DOUBEQ = 282,
    NOTEQ = 283,
    LESSEQ = 284,
    GREATEQ = 285,
    LESS = 286,
    GREAT = 287,
    TIMES = 288,
    DIVIDE = 289,
    MOD = 290,
    DOUBAND = 291,
    DOUBBAR = 292,
    IDENTIFIER = 293,
    SEMICO = 294,
    NUM = 295,
    NAME = 296,
    EXP = 297,
    RE = 298,
    BIN = 299,
    PRO = 300,
    NEG = 301,
    OPTEXP = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "program3.y" /* yacc.c:355  */

  Node* ttype;
  Lexeme* token;


#line 181 "program3_bison.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM3_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "program3_bison.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    86,    93,   102,   108,   116,   122,   128,
     135,   141,   143,   153,   165,   169,   173,   179,   188,   192,
     197,   203,   209,   215,   224,   229,   231,   241,   252,   256,
     260,   266,   273,   280,   288,   298,   305,   315,   322,   329,
     336,   346,   353,   360,   366,   367,   374,   375,   379,   381,
     382,   383,   387,   388,   389,   390,   391,   392,   395,   396,
     397,   398,   400,   401,   402,   405,   406,   412
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "THIS", "IF", "ELSE", "WHILE",
  "RETURN", "PRINT", "READ", "VOID", "NEW", "NULLKEYWORD", "INT",
  "ASSIGNOP", "DOTOP", "COMMA", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "PLUS", "MINUS", "NOT", "DOUBEQ", "NOTEQ", "LESSEQ",
  "GREATEQ", "LESS", "GREAT", "TIMES", "DIVIDE", "MOD", "DOUBAND",
  "DOUBBAR", "IDENTIFIER", "SEMICO", "NUM", "NAME", "EXP", "RE", "BIN",
  "PRO", "NEG", "OPTEXP", "$accept", "input", "exp", "expression", "name",
  "newexpression", "optExprBrack", "arglist", "unaryop", "relationop",
  "productop", "sumop", "multibracks", "simpletype", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -21

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-21)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,   -21,    95,   -21,   -21,    -7,     7,   -21,   -21,   189,
     -21,   -21,   -21,    36,   -21,   -21,   238,    -4,   -21,   189,
      37,     1,   -21,     0,    11,   -17,   113,   -20,   185,    12,
     -16,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   189,   189,   189,   -13,   189,   189,
     -21,    -5,    34,    14,   -15,   -21,   -21,   189,    15,   189,
      15,   189,   -21,   -21,   -21,   -21,   130,   -21,   -21,    56,
      19,   252,   -21,    -3,   -21,   207,     5,   151,   -21,   -21,
     -21,    41,     8,   185,    64,     9,    64,   -21,   -21,   -21,
     -21,   189,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   224,
     -21,   -21,   -21,   -21
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     1,    28,     0,     0,    15,    67,     0,
      49,    50,    51,     0,    14,     3,    11,    25,    24,     0,
       0,     0,    43,    44,    44,    29,     0,     0,     0,     0,
       0,    63,    62,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    64,     0,     0,     0,     0,    46,     0,
      18,     0,     0,     0,     0,    17,    16,    46,    37,    46,
      41,     0,    23,    22,     6,    65,     0,    12,     5,     0,
       0,    19,    20,    21,    30,    48,     0,     0,     9,    13,
       8,     0,     0,     0,    38,     0,    42,    33,    32,    66,
       7,    46,    27,    26,    34,    31,    10,    36,    35,     0,
      40,    39,    47,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,    -2,   -21,   -21,    62,    26,   -21,   -21,
     -21,   -21,   -19,    81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    15,    75,    17,    18,    58,    76,    19,    44,
      45,    46,    30,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      16,    54,    55,    61,    69,    69,    92,    26,    22,    97,
     100,    21,    47,    67,    48,    79,    49,    50,    57,    64,
      56,     8,    70,    81,    93,    74,    66,    98,   101,    59,
      39,    40,    41,    42,    78,    83,   -29,    27,    51,    84,
     -29,    86,    71,    72,    73,    23,   -29,    77,   -29,   -29,
     -29,    68,   -29,    80,   -29,    65,    28,    52,    90,    66,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,    29,    53,   -29,    89,    -2,     1,
      96,    99,    -2,    82,    69,    85,    60,    24,    -2,     0,
      -2,    -2,    -2,     0,     0,     3,    -2,     0,     0,     4,
       0,     0,    -2,    -2,    -2,     5,     0,     6,     7,     8,
       0,     0,     0,     9,    62,     0,    -2,   102,    -2,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    63,    13,     0,    14,     0,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    88,    94,     0,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,     0,    95,     0,     0,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     4,
       0,     0,     0,     4,     0,     5,     0,     6,     7,     5,
       0,     6,     7,     9,     0,     0,    65,     9,     0,    10,
      11,    12,     0,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,    25,    91,    14,     0,    25,     0,    14,
       0,    31,    32,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   103,     0,     0,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    31,    32,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43
};

static const yytype_int8 yycheck[] =
{
       2,    20,     1,    20,    20,    20,     1,     9,     1,     1,
       1,    18,    16,     1,    18,     1,    20,    19,    18,    39,
      19,    14,    38,    38,    19,    38,    28,    19,    19,    18,
      33,    34,    35,    36,    39,    20,     0,     1,     1,    58,
       4,    60,    44,    45,    46,    38,    10,    49,    12,    13,
      14,    39,    16,    39,    18,    21,    20,    20,    39,    61,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    38,    40,    21,     0,     1,
      39,    83,     4,    57,    20,    59,    24,     6,    10,    -1,
      12,    13,    14,    -1,    -1,     0,    18,    -1,    -1,     4,
      -1,    -1,    24,    25,    26,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    18,     1,    -1,    38,    91,    40,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    19,    38,    -1,    40,    -1,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    21,     1,    -1,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     4,
      -1,    -1,    -1,     4,    -1,    10,    -1,    12,    13,    10,
      -1,    12,    13,    18,    -1,    -1,    21,    18,    -1,    24,
      25,    26,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    17,    40,    -1,    38,    -1,    40,
      -1,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    21,    -1,    -1,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    49,     0,     4,    10,    12,    13,    14,    18,
      24,    25,    26,    38,    40,    50,    51,    52,    53,    56,
      61,    18,     1,    38,    61,    38,    51,     1,    20,    38,
      60,    24,    25,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    57,    58,    59,    16,    18,    20,
      51,     1,    20,    38,    60,     1,    19,    18,    54,    18,
      54,    20,     1,    19,    39,    21,    51,     1,    39,    20,
      38,    51,    51,    51,    38,    51,    55,    51,    39,     1,
      39,    38,    55,    20,    60,    55,    60,     1,    21,    21,
      39,    17,     1,    19,     1,    21,    39,     1,    19,    51,
       1,    19,    55,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    55,    55,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    59,    59,    59,    60,    60,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     3,     3,     4,     3,     3,
       4,     1,     3,     3,     1,     1,     3,     3,     2,     3,
       3,     3,     3,     3,     1,     1,     4,     4,     1,     1,
       3,     4,     4,     4,     4,     5,     5,     3,     4,     5,
       5,     3,     4,     2,     0,     4,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* CLASS  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1132 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 4: /* THIS  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1138 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 5: /* IF  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1144 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 6: /* ELSE  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1150 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 7: /* WHILE  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1156 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 8: /* RETURN  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1162 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 9: /* PRINT  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1168 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 10: /* READ  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1174 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 11: /* VOID  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1180 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 12: /* NEW  */
#line 59 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1186 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 13: /* NULLKEYWORD  */
#line 60 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1192 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 14: /* INT  */
#line 60 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1198 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 15: /* ASSIGNOP  */
#line 60 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1204 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 16: /* DOTOP  */
#line 60 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1210 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 17: /* COMMA  */
#line 60 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1216 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 18: /* LPAREN  */
#line 60 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1222 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 19: /* RPAREN  */
#line 60 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1228 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 20: /* LBRACK  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1234 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 21: /* RBRACK  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1240 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 22: /* LBRACE  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1246 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 23: /* RBRACE  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1252 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 24: /* PLUS  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1258 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 25: /* MINUS  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1264 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 26: /* NOT  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1270 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 27: /* DOUBEQ  */
#line 61 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1276 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 28: /* NOTEQ  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1282 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 29: /* LESSEQ  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1288 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 30: /* GREATEQ  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1294 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 31: /* LESS  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1300 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 32: /* GREAT  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1306 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 33: /* TIMES  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1312 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 34: /* DIVIDE  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1318 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 35: /* MOD  */
#line 62 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1324 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 36: /* DOUBAND  */
#line 63 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1330 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 37: /* DOUBBAR  */
#line 63 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1336 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 38: /* IDENTIFIER  */
#line 63 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1342 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 39: /* SEMICO  */
#line 63 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1348 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 40: /* NUM  */
#line 63 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).token));}
#line 1354 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 50: /* exp  */
#line 67 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1360 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 51: /* expression  */
#line 65 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1366 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 52: /* name  */
#line 65 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1372 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 53: /* newexpression  */
#line 67 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1378 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 54: /* optExprBrack  */
#line 66 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1384 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 55: /* arglist  */
#line 66 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1390 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 56: /* unaryop  */
#line 65 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1396 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 57: /* relationop  */
#line 66 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1402 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 58: /* productop  */
#line 66 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1408 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 59: /* sumop  */
#line 66 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1414 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 60: /* multibracks  */
#line 65 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1420 "program3_bison.c" /* yacc.c:1257  */
        break;

    case 61: /* simpletype  */
#line 65 "program3.y" /* yacc.c:1257  */
      {delete(((*yyvaluep).ttype));}
#line 1426 "program3_bison.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 86 "program3.y" /* yacc.c:1646  */
    { 
          if((yyvsp[0].ttype)!=0) 
          {
            if(!(yyvsp[0].ttype)->getErr()) forest.push_back((yyvsp[0].ttype));
            else delete (yyvsp[0].ttype);
          }
        }
#line 1696 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "program3.y" /* yacc.c:1646  */
    {
          cerr << "Got no idea Around " << yylval.token->line << ":" 
          << yylval.token->column <<endl << endl; 
          yyclearin;
          yyerrok;
          
        }
#line 1708 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "program3.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new VarDec((yyvsp[-2].token)->value, (yyvsp[-1].token)->value);
            delete (yyvsp[-2].token);
            delete (yyvsp[-1].token);
            delete (yyvsp[0].token);
}
#line 1719 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "program3.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = 0;
            cerr << "-> before ; at " << (yyvsp[0].token)->line << ":" << (yyvsp[0].token)->column << endl 
            << endl;
            yyerrok;
            delete (yyvsp[-2].token);
            delete (yyvsp[0].token);
          }
#line 1732 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "program3.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new VarDec((yyvsp[-3].token)->value, (yyvsp[-1].token)->value, (yyvsp[-2].ttype));
            delete (yyvsp[-3].token);
            delete (yyvsp[-1].token);
            delete (yyvsp[0].token);
      }
#line 1743 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "program3.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new VarDec("int", (yyvsp[-1].token)->value);
            delete (yyvsp[-1].token);
            delete (yyvsp[0].token);
            delete (yyvsp[-2].ttype);
      }
#line 1754 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "program3.y" /* yacc.c:1646  */
    {
        (yyval.ttype) = 0;
        cerr << " -> before ; at " << (yyvsp[0].token)->line << ":" << (yyvsp[0].token)->column << endl << endl;
        yyerrok;
        delete (yyvsp[0].token);
        delete (yyvsp[-2].ttype);
      }
#line 1766 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "program3.y" /* yacc.c:1646  */
    {
            (yyval.ttype) = new VarDec("int", (yyvsp[-1].token)->value, (yyvsp[-2].ttype));
            delete (yyvsp[-1].token);
            delete (yyvsp[0].token);
            delete (yyvsp[-3].ttype);
      }
#line 1777 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "program3.y" /* yacc.c:1646  */
    { (yyval.ttype) = (yyvsp[0].ttype); }
#line 1783 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "program3.y" /* yacc.c:1646  */
    {
                                  (yyval.ttype) = new VarDec((yyvsp[-2].token)->value, (yyvsp[-1].token)->value);
                                  (yyval.ttype)->setErr();
                                  cerr << "Expected Semicolon At "<< (yyvsp[-1].token)->line 
                                  << ":" << (yyvsp[-1].token)->column+(yyvsp[-1].token)->value.length() 
                                  << endl << endl;
                                  yyerrok;
                                  delete (yyvsp[-2].token);
                                  delete (yyvsp[-1].token); 
}
#line 1798 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "program3.y" /* yacc.c:1646  */
    {
                            (yyval.ttype) = new VarDec("int", (yyvsp[-1].token)->value);
                            (yyval.ttype)->setErr();
                              cerr << "Expected Semicolon At "<< (yyvsp[-1].token)->line << ":" 
                              << (yyvsp[-1].token)->column+(yyvsp[-1].token)->value.length() <<endl << endl;
                              yyerrok;
                            delete (yyvsp[-1].token);
                            delete (yyvsp[-2].ttype);
                                }
#line 1812 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 14:
#line 165 "program3.y" /* yacc.c:1646  */
    { 
                (yyval.ttype) = new Expression((yyvsp[0].token)->value, EXPNUM);
                delete (yyvsp[0].token);
}
#line 1821 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "program3.y" /* yacc.c:1646  */
    { 
                (yyval.ttype) = new Expression("null", EXPNULL); 
                delete (yyvsp[0].token);
            }
#line 1830 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 16:
#line 173 "program3.y" /* yacc.c:1646  */
    { 
                (yyval.ttype) = new Expression("read", EXPREAD); 
                delete (yyvsp[-2].token);
                delete (yyvsp[-1].token);
                delete (yyvsp[0].token);
            }
#line 1841 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "program3.y" /* yacc.c:1646  */
    {
                      (yyval.ttype) = new Expression("read", EXPREAD); 
                      (yyval.ttype)->setErr();
                      cerr << "Expected Right Parenthesis At "<< (yyvsp[-1].token)->line << ":" 
                      << (yyvsp[-1].token)->column <<endl << endl;
                      yyerrok;
                      delete (yyvsp[-2].token);
                      delete (yyvsp[-1].token);
                     }
#line 1855 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 18:
#line 188 "program3.y" /* yacc.c:1646  */
    { 
                    (yyval.ttype) = new Expression((yyvsp[-1].ttype), (yyvsp[0].ttype), EXPUNARY); 
                    if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
                    if((yyvsp[0].ttype)->getErr()) (yyval.ttype)->setErr();}
#line 1864 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 19:
#line 192 "program3.y" /* yacc.c:1646  */
    { 
                    (yyval.ttype) = new Expression((yyvsp[-2].ttype), (yyvsp[-1].ttype), (yyvsp[0].ttype), EXPRELATION);  
                    if((yyvsp[-2].ttype)->getErr()) (yyval.ttype)->setErr();
                    if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
                    if((yyvsp[0].ttype)->getErr()) (yyval.ttype)->setErr();}
#line 1874 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 20:
#line 197 "program3.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new Expression((yyvsp[-2].ttype), (yyvsp[-1].ttype), (yyvsp[0].ttype), EXPPRODUCT); 
                    if((yyvsp[-2].ttype)->getErr()) (yyval.ttype)->setErr();
                    if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
                    if((yyvsp[0].ttype)->getErr()) (yyval.ttype)->setErr();
            }
#line 1885 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 21:
#line 203 "program3.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new Expression((yyvsp[-2].ttype), (yyvsp[-1].ttype), (yyvsp[0].ttype), EXPSUMOP); 
                    if((yyvsp[-2].ttype)->getErr()) (yyval.ttype)->setErr();
                    if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
                    if((yyvsp[0].ttype)->getErr()) (yyval.ttype)->setErr();
            }
#line 1896 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 22:
#line 209 "program3.y" /* yacc.c:1646  */
    { 
                  (yyval.ttype) = new Expression((yyvsp[-1].ttype), EXPPAREN);
                  if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
                  delete (yyvsp[-2].token);
                  delete (yyvsp[0].token);
            }
#line 1907 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 23:
#line 215 "program3.y" /* yacc.c:1646  */
    { 
                    (yyval.ttype) = new Expression((yyvsp[-1].ttype), EXPPAREN);
                    (yyval.ttype)->setErr();
                    cerr << "Expected Right Parenthesis At "
                    << yylval.token->line << ":" << yylval.token->column 
                    <<endl << endl;
                    yyerrok;
                    delete (yyvsp[-2].token);
            }
#line 1921 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 24:
#line 224 "program3.y" /* yacc.c:1646  */
    { 
                            if((yyvsp[0].ttype)!= 0) (yyval.ttype) = new Expression((yyvsp[0].ttype), EXPNEW); 
                            else (yyval.ttype) = 0;
                            if((yyvsp[0].ttype)->getErr()) (yyval.ttype)->setErr();
                            }
#line 1931 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 25:
#line 229 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new Expression((yyvsp[0].ttype), EXPNAME);
                  if((yyvsp[0].ttype)->getErr()) (yyval.ttype)->setErr();}
#line 1938 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 26:
#line 231 "program3.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new Expression((yyvsp[-3].ttype), (yyvsp[-1].ttype), EXPNAMEARG);
                  if((yyvsp[-3].ttype)->getErr()) (yyval.ttype)->setErr();
                  if((yyvsp[-1].ttype)!= 0)
                  {
                    if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
                  }
                  delete (yyvsp[-2].token);
                  delete (yyvsp[0].token);
            }
#line 1953 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 27:
#line 241 "program3.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new Expression((yyvsp[-3].ttype), (yyvsp[-1].ttype), EXPNAMEARG);
                    (yyval.ttype)->setErr();
                    cerr << "Expected Right Parenthesis At "
                    << yylval.token->line << ":" << yylval.token->column 
                    <<endl << endl;
                    yyerrok;
                    delete (yyvsp[-2].token);
            }
#line 1967 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 28:
#line 252 "program3.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name("this", NAMETHIS); 
            delete (yyvsp[0].token);
}
#line 1976 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 29:
#line 256 "program3.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name((yyvsp[0].token)->value, NAMEID);
            delete (yyvsp[0].token);
      }
#line 1985 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 30:
#line 260 "program3.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name((yyvsp[-2].ttype), (yyvsp[0].token)->value, NAMEDOTID);
            if((yyvsp[-2].ttype)->getErr()) (yyval.ttype)->setErr();
            delete (yyvsp[0].token);
            delete (yyvsp[-1].token);
      }
#line 1996 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 31:
#line 266 "program3.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name((yyvsp[-3].ttype), (yyvsp[-1].ttype), NAMEEXP);
            if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
            if((yyvsp[-3].ttype)->getErr()) (yyval.ttype)->setErr();
            delete (yyvsp[-2].token);
            delete (yyvsp[0].token);
      }
#line 2008 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 32:
#line 273 "program3.y" /* yacc.c:1646  */
    {
        (yyval.ttype) = new Name((yyvsp[-1].ttype), (yyvsp[-3].token)->value, NAMEIDEXP);
        if((yyvsp[-1].ttype)->getErr()) (yyval.ttype)->setErr();
        delete (yyvsp[-3].token);
        delete (yyvsp[-2].token);
        delete (yyvsp[0].token);
      }
#line 2020 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 33:
#line 280 "program3.y" /* yacc.c:1646  */
    {
        (yyval.ttype) = new Name((yyvsp[-1].ttype), (yyvsp[-3].token)->value, NAMEIDEXP);
        (yyval.ttype)->setErr();
        cerr << "Expected Right Bracket At " << yylval.token->line << ":" 
        << yylval.token->column << endl << endl;
        delete (yyvsp[-2].token);
        delete (yyvsp[-3].token);
      }
#line 2033 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 34:
#line 288 "program3.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new Name((yyvsp[-3].ttype), (yyvsp[-1].ttype), NAMEIDEXP);
            (yyval.ttype)->setErr();
            cerr<< "Expected Right Bracket At " << yylval.token->line << ":"
            << yylval.token->column << endl << endl;
            yyerrok;
            delete (yyvsp[-3].ttype);
            delete (yyvsp[-2].token);
      }
#line 2047 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 35:
#line 298 "program3.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new NewExpression((yyvsp[-3].token)->value, (yyvsp[-1].ttype), NEWEXPARG);
                    delete (yyvsp[-3].token);
                    delete (yyvsp[-4].token);
                    delete (yyvsp[-2].token);
                    delete (yyvsp[0].token);
}
#line 2059 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 36:
#line 305 "program3.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new NewExpression((yyvsp[-3].token)->value, (yyvsp[-1].ttype), NEWEXPARG);
                (yyval.ttype)->setErr();
                cerr << "Expected Right Parenthesis At " << yylval.token->line 
                << ":" << yylval.token->column << endl << endl;
                      yyerrok;
                      delete (yyvsp[-3].token);
                      delete (yyvsp[-4].token);
                      delete (yyvsp[-2].token);
              }
#line 2074 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 37:
#line 315 "program3.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].ttype) != 0) ((BrackExpression*)(yyvsp[0].ttype))->reverse();
                if((yyvsp[0].ttype) == 0) (yyval.ttype) = new NewExpression((yyvsp[-1].token)->value, (yyvsp[0].ttype), 0, NEWEXP);
                else (yyval.ttype) = new NewExpression((yyvsp[-1].token)->value, (yyvsp[0].ttype), 0, NEWEXPBRACK);
                delete (yyvsp[-1].token);
                delete (yyvsp[-2].token);
              }
#line 2086 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 38:
#line 322 "program3.y" /* yacc.c:1646  */
    {
                if((yyvsp[-1].ttype) != 0) ((BrackExpression*)(yyvsp[-1].ttype))->reverse();
                if((yyvsp[-1].ttype) == 0) (yyval.ttype) = new NewExpression((yyvsp[-2].token)->value, (yyvsp[-1].ttype), (yyvsp[0].ttype), NEWEXPMULTI);
                else (yyval.ttype) = new NewExpression((yyvsp[-2].token)->value, (yyvsp[-1].ttype), (yyvsp[0].ttype), NEWEXPBRACKMULTI);
                delete (yyvsp[-2].token);
                delete (yyvsp[-3].token);
              }
#line 2098 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 39:
#line 329 "program3.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new NewExpression("int", (yyvsp[-1].ttype), NEWEXPARG);
                    delete (yyvsp[-4].token);
                    delete (yyvsp[-3].ttype);
                    delete (yyvsp[-2].token);
                    delete (yyvsp[0].token);
              }
#line 2110 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 40:
#line 336 "program3.y" /* yacc.c:1646  */
    {
                (yyval.ttype) = new NewExpression("int", (yyvsp[-1].ttype), NEWEXPARG);
                (yyval.ttype)->setErr();
                cerr << "Expected Right Parenthesis At " << yylval.token->line 
                << ":" << yylval.token->column <<endl << endl;
                      yyerrok;
                      delete (yyvsp[-4].token);
                      delete (yyvsp[-3].ttype);
                      delete (yyvsp[-2].token);
              }
#line 2125 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 41:
#line 346 "program3.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].ttype) != 0) ((BrackExpression*)(yyvsp[0].ttype))->reverse();
                    if((yyvsp[0].ttype) == 0) (yyval.ttype) =  new NewExpression("int", (yyvsp[0].ttype), 0,NEWEXP);
                    else (yyval.ttype)=  new NewExpression("int", (yyvsp[0].ttype), 0,NEWEXPBRACK);
                    delete (yyvsp[-2].token);
                    delete (yyvsp[-1].ttype);
              }
#line 2137 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 42:
#line 353 "program3.y" /* yacc.c:1646  */
    {
                if((yyvsp[-1].ttype) != 0) ((BrackExpression*)(yyvsp[-1].ttype))->reverse();
                if((yyvsp[-1].ttype) == 0) (yyval.ttype)=  new NewExpression("int", (yyvsp[-1].ttype), (yyvsp[0].ttype), NEWEXPMULTI);
                else (yyval.ttype) =  new NewExpression("int", (yyvsp[-1].ttype), (yyvsp[0].ttype), NEWEXPBRACKMULTI);
                delete (yyvsp[-3].token);
                delete (yyvsp[-2].ttype);
              }
#line 2149 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 43:
#line 360 "program3.y" /* yacc.c:1646  */
    { (yyval.ttype) = 0;
                  cerr << " -> after new at " << (yyvsp[-1].token)->line << ":" << (yyvsp[-1].token)->column 
                  << endl << endl; 
                  yyerrok;}
#line 2158 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 44:
#line 366 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = 0;}
#line 2164 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 45:
#line 367 "program3.y" /* yacc.c:1646  */
    {
                    (yyval.ttype) = new BrackExpression((yyvsp[-1].ttype), (yyvsp[-3].ttype));
                    delete (yyvsp[-2].token);
                    delete (yyvsp[0].token);
              }
#line 2174 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 46:
#line 374 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = 0;}
#line 2180 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 47:
#line 375 "program3.y" /* yacc.c:1646  */
    { 
            (yyval.ttype) = new ArgList((yyvsp[-2].ttype), (yyvsp[0].ttype));
            delete (yyvsp[-1].token);
          }
#line 2189 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 48:
#line 379 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ArgList((yyvsp[0].ttype), 0);}
#line 2195 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 49:
#line 381 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new UnaryOp("+"); delete (yyvsp[0].token);}
#line 2201 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 50:
#line 382 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new UnaryOp("-"); delete (yyvsp[0].token);}
#line 2207 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 51:
#line 383 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new UnaryOp("!"); delete (yyvsp[0].token);}
#line 2213 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 52:
#line 387 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("=="); delete (yyvsp[0].token);}
#line 2219 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 53:
#line 388 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("!="); delete (yyvsp[0].token);}
#line 2225 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 54:
#line 389 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("<="); delete (yyvsp[0].token);}
#line 2231 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 55:
#line 390 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp(">="); delete (yyvsp[0].token);}
#line 2237 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 56:
#line 391 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp("<"); delete (yyvsp[0].token);}
#line 2243 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 57:
#line 392 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new RelationOp(">"); delete (yyvsp[0].token);}
#line 2249 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 58:
#line 395 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("*"); delete (yyvsp[0].token);}
#line 2255 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 59:
#line 396 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("/"); delete (yyvsp[0].token);}
#line 2261 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 60:
#line 397 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("%"); delete (yyvsp[0].token);}
#line 2267 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 61:
#line 398 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new ProductOp("&&"); delete (yyvsp[0].token);}
#line 2273 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 62:
#line 400 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new SumOp("-"); delete (yyvsp[0].token);}
#line 2279 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 63:
#line 401 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new SumOp("+"); delete (yyvsp[0].token);}
#line 2285 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 64:
#line 402 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new SumOp("||"); delete (yyvsp[0].token);}
#line 2291 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new Multibracks(); delete (yyvsp[-1].token); delete (yyvsp[0].token);}
#line 2297 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 66:
#line 406 "program3.y" /* yacc.c:1646  */
    {(yyval.ttype) = new Multibracks((yyvsp[-2].ttype)); delete (yyvsp[0].token);delete (yyvsp[-1].token);}
#line 2303 "program3_bison.c" /* yacc.c:1646  */
    break;

  case 67:
#line 412 "program3.y" /* yacc.c:1646  */
    {
                  (yyval.ttype) = new SimpleType("int");
                  delete (yyvsp[0].token);
                }
#line 2312 "program3_bison.c" /* yacc.c:1646  */
    break;


#line 2316 "program3_bison.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 421 "program3.y" /* yacc.c:1906  */

