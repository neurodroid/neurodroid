
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parse1.y"

/* /local/src/master/nrn/src/modlunit/parse1.y,v 1.11 1999/02/27 21:13:50 hines Exp */

#include <../../nmodlconf.h>
#include "model.h"

/* Constructs a parse tree. No translation is done, ie. on exit printing
the intoken list will make an exact copy of the input file.
All tokens and productions are of Item type and consist of STRING, SYMBOL,
and LIST.
SPACE and NEWLINE are in the intoken list but are not yacc tokens.

All explicitly declared names are given their subtype
and a pointer to their declaration. All "used" names are marked with
their usage for later error checking.
*/

extern Symbol *checklocal();
extern Item *title;
extern int declare_level;
extern int parse_pass, restart_pass;
extern List *solvelist;

#define IFP(n)	if (parse_pass == n)
#define IFR(n)	if (restart_pass == n)
#define P1	IFP(1)
#define P2	IFP(2)
#define P3	IFP(3)
#define R0	IFR(0)
#define R1	IFR(1)

static int yylex();

#if YYBISON 
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyps; --yypv; YYERROR
#endif

extern Item *lastok;	/* last token accepted by expr */
static int blocktype;
static int unitflagsave; /*must turn off units in restartpass0 in kinetic block */
static List* netreceive_arglist;
static List* args;
extern int lexcontext;


/* Line 189 of yacc.c  */
#line 123 "parse1.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VERBATIM = 258,
     COMMENT = 259,
     TITLE = 260,
     CONSTANT = 261,
     INDEPENDENT = 262,
     ASSIGNED = 263,
     STATE = 264,
     END_VERBATIM = 265,
     END_COMMENT = 266,
     UNITS = 267,
     BREAKPOINT = 268,
     PARAMETER = 269,
     INITIAL1 = 270,
     DERIVATIVE = 271,
     SOLVE = 272,
     USING = 273,
     WITH = 274,
     STEPPED = 275,
     DISCRETE = 276,
     FROM = 277,
     TO = 278,
     BY = 279,
     WHILE = 280,
     IF = 281,
     ELSE = 282,
     START1 = 283,
     STEP = 284,
     SENS = 285,
     SOLVEFOR = 286,
     PROCEDURE = 287,
     PARTIAL = 288,
     DEL = 289,
     DEL2 = 290,
     DEFINE1 = 291,
     IFERROR = 292,
     DERFUNC = 293,
     EQUATION = 294,
     TERMINAL = 295,
     LINEAR = 296,
     NONLINEAR = 297,
     FUNCTION1 = 298,
     LOCAL = 299,
     METHOD = 300,
     LIN1 = 301,
     NONLIN1 = 302,
     PUTQ = 303,
     GETQ = 304,
     FUNCTION_TABLE = 305,
     INCLUDE1 = 306,
     PROTECT = 307,
     OR = 308,
     AND = 309,
     GT = 310,
     GE = 311,
     LT = 312,
     LE = 313,
     EQ = 314,
     NE = 315,
     NOT = 316,
     NAME = 317,
     PRIME = 318,
     REAL = 319,
     INTEGER = 320,
     DEFINEDVAR = 321,
     KINETIC = 322,
     CONSERVE = 323,
     REACTION = 324,
     REACT1 = 325,
     COMPARTMENT = 326,
     LONGDIFUS = 327,
     PARTEQN = 328,
     STRING = 329,
     PLOT = 330,
     VS = 331,
     LAG = 332,
     RESET = 333,
     MATCH = 334,
     MODEL_LEVEL = 335,
     SWEEP = 336,
     FIRST = 337,
     LAST = 338,
     SPACE = 339,
     NEWLINE = 340,
     TO_EOL = 341,
     STUFF = 342,
     UNITBLK = 343,
     UNITSON = 344,
     UNITSOFF = 345,
     TABLE = 346,
     DEPEND = 347,
     NEURON = 348,
     SUFFIX = 349,
     NONSPECIFIC = 350,
     READ = 351,
     WRITE = 352,
     USEION = 353,
     VALENCE = 354,
     GLOBAL = 355,
     SECTION = 356,
     RANGE = 357,
     POINTER = 358,
     EXTERNAL = 359,
     BEFORE = 360,
     AFTER = 361,
     ELECTRODE_CURRENT = 362,
     CONSTRUCTOR = 363,
     DESTRUCTOR = 364,
     NETRECEIVE = 365,
     FOR_NETCONS = 366,
     WATCH = 367,
     THREADSAFE = 368,
     UNARYMINUS = 369
   };
#endif
/* Tokens.  */
#define VERBATIM 258
#define COMMENT 259
#define TITLE 260
#define CONSTANT 261
#define INDEPENDENT 262
#define ASSIGNED 263
#define STATE 264
#define END_VERBATIM 265
#define END_COMMENT 266
#define UNITS 267
#define BREAKPOINT 268
#define PARAMETER 269
#define INITIAL1 270
#define DERIVATIVE 271
#define SOLVE 272
#define USING 273
#define WITH 274
#define STEPPED 275
#define DISCRETE 276
#define FROM 277
#define TO 278
#define BY 279
#define WHILE 280
#define IF 281
#define ELSE 282
#define START1 283
#define STEP 284
#define SENS 285
#define SOLVEFOR 286
#define PROCEDURE 287
#define PARTIAL 288
#define DEL 289
#define DEL2 290
#define DEFINE1 291
#define IFERROR 292
#define DERFUNC 293
#define EQUATION 294
#define TERMINAL 295
#define LINEAR 296
#define NONLINEAR 297
#define FUNCTION1 298
#define LOCAL 299
#define METHOD 300
#define LIN1 301
#define NONLIN1 302
#define PUTQ 303
#define GETQ 304
#define FUNCTION_TABLE 305
#define INCLUDE1 306
#define PROTECT 307
#define OR 308
#define AND 309
#define GT 310
#define GE 311
#define LT 312
#define LE 313
#define EQ 314
#define NE 315
#define NOT 316
#define NAME 317
#define PRIME 318
#define REAL 319
#define INTEGER 320
#define DEFINEDVAR 321
#define KINETIC 322
#define CONSERVE 323
#define REACTION 324
#define REACT1 325
#define COMPARTMENT 326
#define LONGDIFUS 327
#define PARTEQN 328
#define STRING 329
#define PLOT 330
#define VS 331
#define LAG 332
#define RESET 333
#define MATCH 334
#define MODEL_LEVEL 335
#define SWEEP 336
#define FIRST 337
#define LAST 338
#define SPACE 339
#define NEWLINE 340
#define TO_EOL 341
#define STUFF 342
#define UNITBLK 343
#define UNITSON 344
#define UNITSOFF 345
#define TABLE 346
#define DEPEND 347
#define NEURON 348
#define SUFFIX 349
#define NONSPECIFIC 350
#define READ 351
#define WRITE 352
#define USEION 353
#define VALENCE 354
#define GLOBAL 355
#define SECTION 356
#define RANGE 357
#define POINTER 358
#define EXTERNAL 359
#define BEFORE 360
#define AFTER 361
#define ELECTRODE_CURRENT 362
#define CONSTRUCTOR 363
#define DESTRUCTOR 364
#define NETRECEIVE 365
#define FOR_NETCONS 366
#define WATCH 367
#define THREADSAFE 368
#define UNARYMINUS 369




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 50 "parse1.y"

	Item	*qp;



/* Line 214 of yacc.c  */
#line 393 "parse1.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 405 "parse1.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  146
/* YYNRULES -- Number of rules.  */
#define YYNRULES  345
/* YYNRULES -- Number of states.  */
#define YYNSTATES  672

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   369

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   130,     2,     2,
      55,    56,    61,    60,    67,    62,     2,    63,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
       2,    64,     2,     2,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,    65,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,    68,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   131
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    32,    35,    38,    40,
      42,    45,    49,    52,    54,    56,    57,    62,    64,    66,
      68,    70,    72,    74,    76,    78,    83,    88,    89,    92,
      98,   102,   109,   111,   112,   114,   115,   120,   121,   127,
     128,   132,   137,   138,   141,   146,   150,   154,   156,   158,
     160,   163,   165,   167,   169,   171,   173,   175,   180,   181,
     184,   188,   198,   200,   202,   207,   208,   211,   216,   224,
     233,   245,   247,   248,   251,   256,   257,   260,   266,   269,
     272,   277,   278,   282,   287,   288,   291,   294,   298,   301,
     306,   311,   318,   320,   321,   324,   325,   328,   329,   332,
     333,   336,   337,   340,   341,   344,   345,   348,   349,   352,
     353,   356,   357,   360,   361,   364,   365,   368,   369,   372,
     373,   376,   377,   380,   381,   385,   386,   390,   393,   396,
     399,   402,   405,   408,   411,   415,   420,   423,   426,   429,
     434,   435,   439,   440,   443,   445,   448,   450,   452,   454,
     456,   458,   460,   462,   464,   466,   468,   470,   472,   474,
     476,   478,   480,   482,   484,   486,   488,   490,   492,   494,
     496,   500,   505,   507,   512,   516,   523,   525,   527,   531,
     535,   539,   543,   547,   549,   551,   554,   556,   560,   564,
     568,   572,   576,   580,   584,   588,   592,   596,   600,   604,
     608,   612,   615,   618,   620,   621,   627,   628,   630,   632,
     634,   638,   642,   643,   653,   656,   657,   660,   666,   674,
     675,   683,   684,   687,   690,   694,   699,   704,   708,   712,
     724,   733,   741,   744,   746,   748,   749,   758,   765,   766,
     768,   771,   776,   783,   784,   791,   794,   797,   801,   804,
     809,   810,   817,   820,   824,   830,   833,   834,   837,   838,
     840,   843,   847,   850,   853,   856,   859,   862,   867,   870,
     872,   875,   879,   884,   885,   894,   900,   902,   905,   906,
     915,   921,   923,   926,   928,   932,   937,   947,   955,   963,
     966,   968,   971,   975,   980,   985,   988,   998,   999,  1001,
    1002,  1005,  1008,  1011,  1016,  1018,  1021,  1023,  1030,  1032,
    1034,  1039,  1040,  1046,  1047,  1051,  1054,  1058,  1062,  1066,
    1070,  1074,  1078,  1082,  1086,  1087,  1089,  1095,  1101,  1109,
    1111,  1113,  1117,  1119,  1120,  1123
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     133,     0,    -1,   134,    -1,     1,    -1,    -1,   134,   135,
      -1,   136,    -1,   203,    -1,   141,    -1,   143,    -1,   180,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,     5,
     102,    -1,     3,    10,    -1,     4,    11,    -1,   105,    -1,
     106,    -1,    51,    90,    -1,    36,    78,   161,    -1,    36,
       1,    -1,    78,    -1,   145,    -1,    -1,    96,    81,   144,
     145,    -1,   146,    -1,   163,    -1,   167,    -1,   171,    -1,
     154,    -1,   173,    -1,   176,    -1,   271,    -1,     6,    53,
     147,    54,    -1,    14,    53,   147,    54,    -1,    -1,   147,
     148,    -1,    78,    64,   159,   149,   152,    -1,    78,   149,
     152,    -1,    78,    57,   161,    58,   149,   152,    -1,     1,
      -1,    -1,   150,    -1,    -1,    55,   151,    12,    56,    -1,
      -1,    73,   159,    67,   159,    71,    -1,    -1,    73,   159,
      71,    -1,    20,    53,   155,    54,    -1,    -1,   155,   156,
      -1,    78,    64,   157,   149,    -1,   159,    67,   159,    -1,
     157,    67,   159,    -1,   142,    -1,    79,    -1,   160,    -1,
      62,   160,    -1,   161,    -1,    80,    -1,    81,    -1,    82,
      -1,    80,    -1,   161,    -1,     7,    53,   164,    54,    -1,
      -1,   164,   165,    -1,   164,    97,   165,    -1,    78,    22,
     159,    23,   159,   166,   161,   170,   149,    -1,     1,    -1,
      19,    -1,     8,    53,   168,    54,    -1,    -1,   168,   169,
      -1,   158,   170,   149,   153,    -1,   158,    57,   161,    58,
     170,   149,   153,    -1,   158,    22,   159,    23,   159,   170,
     149,   153,    -1,   158,    57,   161,    58,    22,   159,    23,
     159,   170,   149,   153,    -1,     1,    -1,    -1,    28,   159,
      -1,     9,    53,   172,    54,    -1,    -1,   172,   169,    -1,
      91,   174,    92,   158,   175,    -1,    91,     1,    -1,   158,
     175,    -1,   174,    67,   158,   175,    -1,    -1,    57,   161,
      58,    -1,   104,    53,   177,    54,    -1,    -1,   177,   178,
      -1,   177,   179,    -1,   150,    64,   150,    -1,   150,     1,
      -1,    78,    64,   162,   150,    -1,    78,    64,   150,   150,
      -1,    78,    64,   150,    62,    71,   150,    -1,     1,    -1,
      -1,   181,   198,    -1,    -1,   182,   224,    -1,    -1,   183,
     247,    -1,    -1,   184,   225,    -1,    -1,   185,   226,    -1,
      -1,   186,   231,    -1,    -1,   187,   233,    -1,    -1,   188,
     236,    -1,    -1,   189,   237,    -1,    -1,   190,   248,    -1,
      -1,   191,   227,    -1,    -1,   192,   199,    -1,    -1,   193,
     200,    -1,    -1,   194,   228,    -1,    -1,   195,   259,    -1,
      -1,   196,   121,   201,    -1,    -1,   197,   122,   201,    -1,
      15,   202,    -1,   124,   202,    -1,   125,   202,    -1,    13,
     202,    -1,    17,   202,    -1,    15,   202,    -1,    29,   202,
      -1,    53,   206,    54,    -1,    53,   203,   206,    54,    -1,
      44,   204,    -1,    44,     1,    -1,    78,   205,    -1,   204,
      67,    78,   205,    -1,    -1,    57,   161,    58,    -1,    -1,
     206,   207,    -1,   208,    -1,    52,   208,    -1,   216,    -1,
     219,    -1,   220,    -1,   202,    -1,   212,    -1,   243,    -1,
     137,    -1,   138,    -1,   249,    -1,   260,    -1,   250,    -1,
     252,    -1,   255,    -1,   262,    -1,   263,    -1,   229,    -1,
     266,    -1,    94,    -1,   267,    -1,   139,    -1,   223,    -1,
     239,    -1,   241,    -1,     1,    -1,   209,    64,   211,    -1,
      68,   211,    64,   211,    -1,   158,    -1,   158,    57,   210,
      58,    -1,    78,    59,   161,    -1,    78,    59,   161,    57,
     210,    58,    -1,   142,    -1,   161,    -1,    55,   210,    56,
      -1,   210,    60,   210,    -1,   210,    62,   210,    -1,   210,
      61,   210,    -1,   210,    63,   210,    -1,     1,    -1,   209,
      -1,   162,   149,    -1,   212,    -1,    55,   211,    56,    -1,
     211,    60,   211,    -1,   211,    62,   211,    -1,   211,    61,
     211,    -1,   211,    63,   211,    -1,   211,    65,   211,    -1,
     211,    69,   211,    -1,   211,    70,   211,    -1,   211,    71,
     211,    -1,   211,    73,   211,    -1,   211,    72,   211,    -1,
     211,    74,   211,    -1,   211,    75,   211,    -1,   211,    76,
     211,    -1,    77,   211,    -1,    62,   211,    -1,     1,    -1,
      -1,    78,    55,   213,   214,    56,    -1,    -1,   215,    -1,
     211,    -1,    90,    -1,   214,    67,   211,    -1,   214,    67,
      90,    -1,    -1,    22,    78,    64,   210,    23,   210,   218,
     217,   202,    -1,    22,     1,    -1,    -1,    24,   210,    -1,
      25,    55,   211,    56,   202,    -1,    26,    55,   211,    56,
     202,   221,   222,    -1,    -1,   221,    27,    26,    55,   211,
      56,   202,    -1,    -1,    27,   202,    -1,    15,   202,    -1,
      16,    78,   202,    -1,    41,    78,   245,   202,    -1,    42,
      78,   245,   202,    -1,    21,    78,   202,    -1,    33,    78,
     202,    -1,    89,    79,    64,    78,    61,    35,    55,    78,
      56,    60,    78,    -1,    89,    34,    78,    57,   230,    58,
      64,   211,    -1,    89,    78,    57,   230,    58,    64,   211,
      -1,    89,     1,    -1,    98,    -1,    99,    -1,    -1,    43,
      78,    55,   234,    56,   149,   232,   202,    -1,    50,    78,
      55,   234,    56,   149,    -1,    -1,   235,    -1,   158,   149,
      -1,   235,    67,   158,   149,    -1,    32,    78,    55,   234,
      56,   202,    -1,    -1,   126,    55,   234,    56,   238,   202,
      -1,   126,     1,    -1,   128,   240,    -1,   239,    67,   240,
      -1,   128,     1,    -1,    55,   211,    56,   162,    -1,    -1,
     127,    55,   234,    56,   242,   202,    -1,   127,     1,    -1,
      17,    78,   244,    -1,    17,    78,    18,    45,   244,    -1,
      17,     1,    -1,    -1,    37,   202,    -1,    -1,   246,    -1,
      31,    78,    -1,   246,    67,    78,    -1,    31,     1,    -1,
      13,   202,    -1,    40,   202,    -1,    30,   258,    -1,    30,
       1,    -1,    84,   251,    64,   211,    -1,    84,     1,    -1,
     209,    -1,    81,   209,    -1,   251,    60,   209,    -1,   251,
      60,    81,   209,    -1,    -1,    87,    78,   253,    67,   211,
      53,   254,    54,    -1,    87,   211,    53,   254,    54,    -1,
      78,    -1,   254,    78,    -1,    -1,    88,    78,   256,    67,
     211,    53,   257,    54,    -1,    88,   211,    53,   257,    54,
      -1,    78,    -1,   257,    78,    -1,   142,    -1,   258,    67,
     142,    -1,    83,    78,   245,   202,    -1,    85,   261,    86,
     261,    55,   211,    67,   211,    56,    -1,    85,   261,    73,
      73,    55,   211,    56,    -1,    85,   261,    62,    71,    55,
     211,    56,    -1,    85,     1,    -1,   209,    -1,    81,   209,
      -1,   261,    60,   209,    -1,   261,    60,    81,   209,    -1,
      93,   158,    24,    78,    -1,    93,     1,    -1,   107,   264,
     265,    22,   211,    23,   211,    19,   161,    -1,    -1,   258,
      -1,    -1,   108,   258,    -1,    48,   158,    -1,    49,   158,
      -1,    95,    53,   268,    54,    -1,   269,    -1,   268,   269,
      -1,   158,    -1,   270,    55,   211,    56,    64,   211,    -1,
       1,    -1,   158,    -1,   158,    57,    78,    58,    -1,    -1,
     109,   272,    53,   273,    54,    -1,    -1,   273,   110,    78,
      -1,   273,   275,    -1,   273,   111,   276,    -1,   273,   123,
     276,    -1,   273,   118,   276,    -1,   273,   117,   276,    -1,
     273,   116,   276,    -1,   273,   119,   276,    -1,   273,   120,
     276,    -1,   273,   129,   274,    -1,    -1,   258,    -1,   114,
      78,   112,   276,   277,    -1,   114,    78,   113,   276,   277,
      -1,   114,    78,   112,   276,   113,   276,   277,    -1,     1,
      -1,    78,    -1,   276,    67,    78,    -1,     1,    -1,    -1,
     115,   162,    -1,   115,    62,   162,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   112,   115,   116,   118,   118,   118,   118,
     118,   118,   118,   119,   120,   122,   125,   127,   129,   131,
     134,   137,   139,   141,   144,   145,   145,   148,   148,   148,
     148,   148,   149,   149,   149,   151,   152,   155,   156,   158,
     163,   165,   167,   170,   171,   173,   173,   177,   178,   181,
     182,   184,   187,   188,   190,   193,   194,   196,   197,   199,
     201,   204,   204,   206,   207,   209,   211,   214,   217,   218,
     220,   224,   226,   228,   230,   233,   234,   237,   239,   241,
     243,   245,   249,   250,   252,   255,   256,   259,   260,   262,
     263,   266,   267,   270,   273,   274,   275,   277,   279,   281,
     283,   294,   305,   311,   311,   313,   313,   315,   315,   317,
     317,   319,   319,   321,   321,   323,   323,   325,   325,   327,
     327,   329,   329,   331,   331,   333,   333,   335,   335,   337,
     337,   339,   339,   344,   344,   345,   345,   347,   349,   351,
     353,   354,   355,   356,   358,   360,   363,   364,   366,   368,
     372,   373,   377,   378,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     408,   420,   427,   434,   441,   449,   457,   459,   460,   461,
     462,   463,   464,   465,   467,   468,   474,   475,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   495,   495,   501,   502,   504,   505,
     506,   507,   509,   509,   511,   514,   515,   517,   519,   522,
     523,   526,   527,   529,   531,   534,   537,   540,   543,   546,
     555,   561,   565,   567,   567,   570,   569,   578,   587,   591,
     593,   607,   619,   627,   626,   640,   643,   644,   645,   647,
     650,   649,   678,   681,   683,   685,   688,   689,   693,   694,
     696,   701,   706,   708,   710,   712,   713,   716,   718,   720,
     721,   722,   723,   727,   727,   733,   739,   741,   744,   744,
     750,   756,   758,   761,   762,   764,   767,   769,   771,   773,
     775,   776,   777,   778,   782,   783,   785,   789,   790,   793,
     794,   796,   797,   799,   801,   802,   804,   805,   806,   810,
     811,   815,   814,   824,   825,   827,   828,   830,   832,   834,
     836,   838,   840,   842,   845,   846,   848,   850,   852,   854,
     857,   859,   861,   865,   866,   868
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VERBATIM", "COMMENT", "TITLE",
  "CONSTANT", "INDEPENDENT", "ASSIGNED", "STATE", "END_VERBATIM",
  "END_COMMENT", "UNITS", "BREAKPOINT", "PARAMETER", "INITIAL1",
  "DERIVATIVE", "SOLVE", "USING", "WITH", "STEPPED", "DISCRETE", "FROM",
  "TO", "BY", "WHILE", "IF", "ELSE", "START1", "STEP", "SENS", "SOLVEFOR",
  "PROCEDURE", "PARTIAL", "DEL", "DEL2", "DEFINE1", "IFERROR", "DERFUNC",
  "EQUATION", "TERMINAL", "LINEAR", "NONLINEAR", "FUNCTION1", "LOCAL",
  "METHOD", "LIN1", "NONLIN1", "PUTQ", "GETQ", "FUNCTION_TABLE",
  "INCLUDE1", "PROTECT", "'{'", "'}'", "'('", "')'", "'['", "']'", "'@'",
  "'+'", "'*'", "'-'", "'/'", "'='", "'^'", "':'", "','", "'~'", "OR",
  "AND", "GT", "GE", "LT", "LE", "EQ", "NE", "NOT", "NAME", "PRIME",
  "REAL", "INTEGER", "DEFINEDVAR", "KINETIC", "CONSERVE", "REACTION",
  "REACT1", "COMPARTMENT", "LONGDIFUS", "PARTEQN", "STRING", "PLOT", "VS",
  "LAG", "RESET", "MATCH", "MODEL_LEVEL", "SWEEP", "FIRST", "LAST",
  "SPACE", "NEWLINE", "TO_EOL", "STUFF", "UNITBLK", "UNITSON", "UNITSOFF",
  "TABLE", "DEPEND", "NEURON", "SUFFIX", "NONSPECIFIC", "READ", "WRITE",
  "USEION", "VALENCE", "GLOBAL", "SECTION", "RANGE", "POINTER", "EXTERNAL",
  "BEFORE", "AFTER", "ELECTRODE_CURRENT", "CONSTRUCTOR", "DESTRUCTOR",
  "NETRECEIVE", "FOR_NETCONS", "WATCH", "THREADSAFE", "'%'", "UNARYMINUS",
  "$accept", "top", "all", "all1", "title", "verbatim", "comment",
  "unitflag", "include1", "define1", "Name", "declare", "$@1", "declare1",
  "constblk", "constbody", "constasgn", "units", "Units", "$@2", "limits",
  "tolerance", "stepblk", "stepbdy", "stepped", "numlist", "name",
  "number", "NUMBER", "integer", "real", "indepblk", "indepbody",
  "indepdef", "withby", "depblk", "depbody", "depdef", "opstart",
  "stateblk", "statbody", "plotdecl", "pvlist", "optindex", "unitblk",
  "unitbody", "unitdef", "factordef", "proc", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "initblk", "constructblk", "destructblk",
  "bablk", "stmtlist", "locallist", "locallist1", "locoptarray",
  "stmtlist1", "stmt", "asgn", "varname", "intexpr", "expr", "funccall",
  "$@20", "exprlist", "exprlist1", "fromstmt", "$@21", "opinc",
  "whilestmt", "ifstmt", "optelseif", "optelse", "initstmt", "derivblk",
  "linblk", "nonlinblk", "discretblk", "partialblk", "pareqn", "firstlast",
  "funcblk", "$@22", "functbl", "arglist", "arglist1", "procedblk",
  "netrecblk", "$@23", "watchstmt", "watch1", "fornetcon", "$@24",
  "solveblk", "ifsolerr", "solvefor", "solvefor1", "eqnblk", "terminalblk",
  "sens", "conserve", "consreact", "compart", "$@25", "compartlist",
  "longdifus", "$@26", "ldifuslist", "namelist", "kineticblk", "reaction",
  "react", "lagstmt", "tablestmt", "tablst", "dependlst", "queuestmt",
  "matchblk", "matchlist", "match", "matchname", "neuronblk", "$@27",
  "nrnstmt", "optnamelist", "nrnuse", "nrnlist", "valence", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   123,   125,    40,    41,    91,    93,    64,
      43,    42,    45,    47,    61,    94,    58,    44,   126,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
      37,   369
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   132,   133,   133,   134,   134,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   137,   138,   139,   139,
     140,   141,   141,   142,   143,   144,   143,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148,   149,   149,   151,   150,   152,   152,   153,
     153,   154,   155,   155,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   162,   162,   163,   164,   164,
     164,   165,   165,   166,   167,   168,   168,   169,   169,   169,
     169,   169,   170,   170,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   177,   177,   177,   178,   178,   179,
     179,   179,   179,   181,   180,   182,   180,   183,   180,   184,
     180,   185,   180,   186,   180,   187,   180,   188,   180,   189,
     180,   190,   180,   191,   180,   192,   180,   193,   180,   194,
     180,   195,   180,   196,   180,   197,   180,   198,   199,   200,
     201,   201,   201,   201,   202,   202,   203,   203,   204,   204,
     205,   205,   206,   206,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     208,   208,   209,   209,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   213,   212,   214,   214,   215,   215,
     215,   215,   217,   216,   216,   218,   218,   219,   220,   221,
     221,   222,   222,   223,   224,   225,   226,   227,   228,   229,
     229,   229,   229,   230,   230,   232,   231,   233,   234,   234,
     235,   235,   236,   238,   237,   237,   239,   239,   239,   240,
     242,   241,   241,   243,   243,   243,   244,   244,   245,   245,
     246,   246,   246,   247,   248,   249,   249,   250,   250,   251,
     251,   251,   251,   253,   252,   252,   254,   254,   256,   255,
     255,   257,   257,   258,   258,   259,   260,   260,   260,   260,
     261,   261,   261,   261,   262,   262,   263,   264,   264,   265,
     265,   266,   266,   267,   268,   268,   269,   269,   269,   270,
     270,   272,   271,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   274,   274,   275,   275,   275,   275,
     276,   276,   276,   277,   277,   277
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       2,     3,     2,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     0,     2,     5,
       3,     6,     1,     0,     1,     0,     4,     0,     5,     0,
       3,     4,     0,     2,     4,     3,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     4,     0,     2,
       3,     9,     1,     1,     4,     0,     2,     4,     7,     8,
      11,     1,     0,     2,     4,     0,     2,     5,     2,     2,
       4,     0,     3,     4,     0,     2,     2,     3,     2,     4,
       4,     6,     1,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     3,     0,     3,     2,     2,     2,
       2,     2,     2,     2,     3,     4,     2,     2,     2,     4,
       0,     3,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     4,     3,     6,     1,     1,     3,     3,
       3,     3,     3,     1,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     0,     5,     0,     1,     1,     1,
       3,     3,     0,     9,     2,     0,     2,     5,     7,     0,
       7,     0,     2,     2,     3,     4,     4,     3,     3,    11,
       8,     7,     2,     1,     1,     0,     8,     6,     0,     1,
       2,     4,     6,     0,     6,     2,     2,     3,     2,     4,
       0,     6,     2,     3,     5,     2,     0,     2,     0,     1,
       2,     3,     2,     2,     2,     2,     2,     4,     2,     1,
       2,     3,     4,     0,     8,     5,     1,     2,     0,     8,
       5,     1,     2,     1,     3,     4,     9,     7,     7,     2,
       1,     2,     3,     4,     4,     2,     9,     0,     1,     0,
       2,     2,     2,     4,     1,     2,     1,     6,     1,     1,
       4,     0,     5,     0,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     1,     5,     5,     7,     1,
       1,     3,     1,     0,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     2,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,   321,     5,     6,    11,    12,    13,    14,     8,
       9,    24,    27,    31,    28,    29,    30,    32,    33,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,    34,    16,
      17,    15,    37,    68,    75,    85,    37,    52,    22,     0,
     147,   150,   146,    20,    88,    23,    58,    57,    91,     0,
      25,    94,     0,     0,   104,     0,   106,     0,   108,     0,
     110,     0,   112,     0,   114,     0,   116,     0,   118,     0,
     120,     0,   122,     0,   124,     0,   126,     0,   128,     0,
     130,     0,   132,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    21,     0,   148,     0,     0,    89,     0,
       0,     0,     0,   323,   152,   137,     0,   273,   268,   268,
       0,     0,     0,   255,   248,   274,     0,   138,   139,     0,
     268,     0,     0,     0,     0,   134,   136,    42,    35,    43,
      38,    72,    67,     0,     0,    69,    81,    74,    82,    76,
      84,    86,    36,    51,     0,    53,     0,   150,     0,    91,
      91,    26,   102,    93,    45,     0,     0,    95,    96,     0,
     152,     0,   234,     0,     0,   269,     0,   248,   248,   248,
      43,     0,   249,   237,   238,     0,   140,   142,   141,   143,
       0,     0,    47,    44,     0,    70,     0,     0,     0,    43,
       0,   151,   149,    92,    90,    87,     0,     0,    98,     0,
     339,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,   325,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,    23,     0,     0,     0,
       0,     0,     0,   173,     0,   307,     0,     0,   162,   163,
     175,   182,   159,   153,   154,     0,   160,   156,   157,   158,
     176,   171,   177,   178,   161,   164,   166,   167,   168,   165,
     169,   170,   172,   174,   272,   270,   235,     0,   236,     0,
       0,     0,   250,   253,     0,   295,     0,     0,    62,    43,
      59,    61,     0,    40,     0,     0,    83,     0,    49,    43,
       0,     0,    65,     0,    66,     0,    97,   324,   342,   340,
     326,     0,   330,   329,   328,   331,   332,   327,   293,   335,
     333,   145,   233,   265,   266,   224,     0,     0,     0,   276,
     275,   311,   312,    23,   155,   213,     0,     0,     0,    43,
     194,     0,   196,   214,     0,   278,     0,   279,     0,   299,
       0,   300,     0,    23,     0,    23,     0,   242,     0,     0,
       0,   305,     0,     0,   308,   309,   262,   248,   258,     0,
     256,     0,     0,     0,   271,    43,    43,     0,     0,    43,
      43,    60,    47,     0,     0,     0,    82,     0,    77,     0,
      54,     0,    46,     0,   100,    99,     0,     0,     0,     0,
       0,     0,   263,     0,     0,     0,     0,   212,   211,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   280,     0,     0,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   318,   316,     0,   314,     0,     0,     0,     0,
       0,   193,     0,   186,   187,     0,   180,   257,   245,   247,
     252,   254,   251,    47,    39,     0,     0,    82,     0,    43,
       0,    56,    55,     0,   341,   343,   343,   294,   266,   267,
       0,     0,     0,   197,   198,   200,   199,   201,   181,   202,
     203,   204,   205,   207,   206,   208,   209,   210,   219,   218,
       0,   217,     0,     0,   281,   277,     0,   302,     0,     0,
       0,     0,   286,     0,     0,   291,     0,     0,   243,   244,
       0,     0,   304,     0,   313,   315,     0,   310,     0,   260,
       0,     0,   183,     0,     0,     0,     0,     0,    41,     0,
      73,     0,    43,     0,    49,    50,   101,     0,     0,   336,
     337,   264,     0,   227,   229,   215,     0,     0,   282,   303,
       0,     0,     0,     0,   285,   287,     0,   290,   292,     0,
       0,     0,     0,     0,     0,     0,   259,   188,   189,   191,
     190,   192,   246,    48,    82,    49,     0,    78,   343,     0,
     344,   225,   231,   221,   220,   185,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,     0,   261,    43,    79,
      82,   338,   345,     0,   222,     0,   228,   298,   297,     0,
       0,     0,     0,   241,     0,     0,     0,    71,    43,   226,
       0,     0,   232,     0,   284,   289,   240,     0,   317,     0,
      49,   223,     0,   296,     0,   306,    80,     0,     0,     0,
     239,   230
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    23,    24,   268,   269,   270,    28,    29,
      77,    30,   131,    31,    32,   115,   160,   212,   213,   226,
     313,   408,    33,   120,   175,   319,   271,   309,   310,   324,
     359,    34,   116,   165,   561,    35,   117,   169,   219,    36,
     118,    37,    79,   128,    38,   132,   187,   188,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    84,   106,   108,   155,
     272,    57,    72,   125,   191,   273,   274,   360,   475,   361,
     362,   444,   520,   521,   277,   650,   634,   278,   279,   612,
     636,   280,    86,    90,    92,   104,   110,   281,   540,    94,
     557,    96,   201,   202,    98,   100,   398,   282,   390,   283,
     595,   284,   422,   194,   195,    88,   102,   285,   286,   368,
     287,   454,   533,   288,   456,   536,   339,   112,   289,   372,
     290,   291,   385,   468,   292,   293,   464,   465,   466,    58,
      82,   189,   340,   242,   330,   569
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -557
static const yytype_int16 yypact[] =
{
     712,  -557,    37,   769,  -557,    77,   115,    33,   103,   113,
     123,   142,   184,   189,    79,   106,   190,    21,   207,   204,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
     279,   323,   334,   309,   314,   330,   302,   333,   251,   377,
     406,   321,   329,   418,   381,   350,   361,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,   278,
    -557,   436,   431,  -557,  -557,  -557,  -557,  -557,   451,   -31,
    -557,  -557,   457,   460,  -557,   448,  -557,   460,  -557,   449,
    -557,   450,  -557,   453,  -557,   454,  -557,   468,  -557,    27,
    -557,   460,  -557,   473,  -557,   460,  -557,   460,  -557,   474,
    -557,   475,  -557,    35,    35,    90,     5,    75,    80,   145,
     -10,  -557,  -557,  -557,   278,  -557,   476,   278,  -557,   352,
     352,   390,   250,  -557,   470,  -557,   460,  -557,   491,   491,
     480,   481,   503,  -557,   352,  -557,   460,  -557,  -557,   460,
     491,   460,   460,   460,   460,  -557,  -557,  -557,  -557,   289,
    -557,  -557,  -557,   507,   135,  -557,  -557,  -557,   291,  -557,
    -557,  -557,  -557,  -557,   495,  -557,   505,   436,   514,   451,
     451,  -557,  -557,  -557,  -557,   501,     1,  -557,  -557,   192,
    -557,   508,  -557,   149,   460,   516,   460,   352,   352,   352,
     518,   519,   517,  -557,  -557,   460,  -557,  -557,  -557,  -557,
     278,   310,   512,  -557,   310,  -557,   310,   310,   278,   518,
     310,  -557,  -557,  -557,  -557,  -557,   562,   288,  -557,   518,
    -557,  -557,   510,   151,   513,   151,   151,   151,   151,   151,
     151,   520,  -557,   603,  -557,   460,   176,   177,   539,   544,
     178,   352,   352,    -1,  -557,   252,   169,    34,    52,   388,
     462,    85,    61,  -557,   547,   520,    42,    53,  -557,  -557,
    -557,   548,  -557,  -557,  -557,   545,  -557,  -557,  -557,  -557,
    -557,  -557,   541,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,   532,  -557,   555,
     556,   560,  -557,  -557,   352,  -557,   559,   313,  -557,   518,
    -557,  -557,   310,  -557,   596,   598,  -557,   564,   551,   282,
     563,   570,  -557,   120,  -557,   518,  -557,  -557,  -557,  -557,
     565,   335,   565,   565,   565,   565,   565,   565,  -557,   567,
    -557,  -557,  -557,  -557,    20,  -557,   573,   252,   252,  -557,
     567,  -557,  -557,   568,  -557,  -557,   252,   252,   252,   518,
    -557,  1138,  -557,  -557,   278,  -557,   382,  -557,   256,  -557,
     382,  -557,   132,   307,   860,   365,   884,  -557,   553,   581,
     575,  -557,   616,    95,   567,   533,  -557,   352,  -557,   252,
    -557,    46,   252,   587,  -557,   518,   518,   460,   460,   518,
     518,  -557,   512,   576,   310,   310,    81,   310,  -557,   310,
    -557,   310,  -557,   574,  -557,  -557,   566,   151,   151,   520,
     601,   460,  -557,    46,   953,   974,   995,   582,   582,  -557,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   356,   591,  -557,   347,   252,  -557,
     395,   578,   577,   401,   586,   580,   592,   583,   597,   398,
     584,   585,  -557,   236,    83,  -557,   605,   520,   646,   614,
    1016,  -557,    46,  -557,  -557,   458,  1172,  -557,  -557,  -557,
    -557,  -557,  -557,   512,  -557,   310,   653,   655,   310,   518,
     613,  -557,  -557,   518,  -557,   147,   -55,  -557,   648,  -557,
     263,   460,   460,  -557,   315,   582,   315,   582,  1172,   582,
    1189,   506,   379,   379,   379,   379,   379,   379,  -557,  1172,
     191,  -557,    46,   382,  -557,  1172,   382,  -557,   631,   634,
      -9,   252,  -557,    89,   252,  -557,   129,   398,  -557,  -557,
     635,   633,  -557,   617,  -557,  -557,   252,   567,   252,  -557,
     376,   444,  -557,    46,    46,    46,    46,   460,  -557,   628,
    -557,   278,   518,   677,   551,  -557,  -557,   151,   326,  -557,
    -557,  -557,    46,  -557,  -557,  -557,   154,   487,  -557,  -557,
     252,   252,   252,   908,  -557,  -557,   932,  -557,  -557,   643,
     638,   668,   647,  1037,   836,   460,  -557,  -557,   339,  -557,
     339,  -557,  -557,  -557,   655,   551,   310,  -557,   -55,   376,
    -557,   237,   679,  -557,  1172,  -557,  1058,  1079,  1155,   580,
     583,   640,   252,   652,  -557,   650,   252,  -557,   518,  -557,
     655,  -557,  -557,    46,  -557,    -8,  -557,  -557,  -557,   252,
     167,   205,   252,  1172,   644,   252,   604,  -557,   518,   428,
     460,   656,  -557,  1100,  -557,  -557,  1172,   667,  1172,   278,
     551,  -557,   252,  -557,   664,  -557,  -557,  1121,   651,   460,
    -557,  -557
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -557,  -557,  -557,  -557,  -557,   731,   732,   733,  -557,  -557,
    -171,  -557,  -557,   606,  -557,   672,  -557,  -199,  -106,  -557,
    -388,  -556,  -557,  -557,  -557,  -557,   -12,  -201,   432,   -69,
    -223,  -557,  -557,   579,  -557,  -557,  -557,   622,  -389,  -557,
    -557,  -557,  -557,   322,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,   627,
     -80,   608,  -557,   569,   557,  -557,   496,  -168,  -384,  -167,
    -180,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,  -557,   213,  -557,
    -557,  -557,  -157,  -557,  -557,  -557,  -557,  -557,   358,  -557,
    -557,  -557,   259,   139,  -557,  -557,  -557,  -557,  -557,  -557,
    -557,  -557,   140,  -557,  -557,   138,  -241,  -557,  -557,   308,
    -557,  -557,  -557,  -557,  -557,  -557,  -557,   296,  -557,  -557,
    -557,  -557,  -557,  -557,  -206,  -486
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -320
static const yytype_int16 yytable[] =
{
     123,   302,   228,   135,   325,    78,   161,   137,   607,   350,
     570,   276,   416,   314,   484,   315,   316,   489,   651,   320,
     318,   145,    74,   275,   384,   147,   186,   148,   143,   332,
     333,   334,   335,   336,   337,   365,   129,     4,   420,   500,
     299,   300,   301,   386,   173,   134,   582,   471,   151,   629,
     152,   450,   153,   369,   388,   176,   192,   421,   178,   162,
     568,   130,   381,   276,   154,   229,   203,   255,   174,   204,
     338,   206,   207,   208,   209,   275,   166,   353,    76,   338,
      68,   166,   144,   163,   462,   275,   377,    59,   551,   367,
     371,   157,   374,   376,   338,   558,   462,   387,   562,    75,
      76,   472,   164,   488,   666,   168,   168,    70,   389,   217,
     402,   403,   353,    76,   296,   366,   298,   179,   180,   378,
     410,   323,   631,   326,    75,   305,    60,   121,   122,   167,
     353,    76,   200,   370,   170,    61,   161,   544,   577,    75,
      76,   306,   311,   584,   158,   311,   157,   311,   311,   317,
     294,   311,   328,    75,    76,   355,    62,    69,    75,    76,
     429,    75,    76,   379,   380,   342,    63,   585,   159,   598,
     599,   600,   601,    75,    76,   184,    64,   343,   345,   349,
     424,   425,   413,   587,    71,   200,   200,   200,   611,   426,
     427,   428,   450,   230,   451,    65,   478,   479,   446,   172,
     482,   483,   449,   486,   487,   452,   490,   588,   491,   356,
     492,   495,   496,   163,   416,   628,   357,   414,   453,   415,
     473,   654,   470,   159,   363,   476,   547,   295,   364,   329,
     469,   358,   256,    76,   322,   121,   122,    66,   311,   351,
     352,   648,    67,   311,   613,   585,   231,   575,   497,   649,
     382,   182,   473,   355,   344,   346,    75,    81,   576,   655,
     567,   633,   568,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   519,   196,   524,
      73,   525,   527,   588,   559,   371,   572,   563,    80,   205,
     564,  -319,   399,   543,    83,   445,   338,   553,   554,   555,
     556,   473,   232,   233,   183,   184,   234,   356,   235,   236,
     237,   238,   239,   216,   357,   240,   447,   480,   481,   217,
     448,   241,   474,   553,   554,   555,   556,   596,   185,   358,
     256,    76,   322,   121,   122,   311,   311,   184,   311,    85,
     311,   499,   311,   184,   184,   610,   210,    87,   218,   409,
      89,   473,    95,   211,   474,   578,    91,   355,   579,   121,
     122,   608,   363,   605,   583,    97,   364,   586,   322,   121,
     122,   463,   307,    93,  -283,   200,   431,    99,   433,   593,
     435,   594,   473,   473,   473,   473,   632,   566,   609,   355,
     308,   121,   122,   308,   121,   122,     8,     9,    10,    11,
     554,   473,   556,   474,    12,   630,   322,   121,   122,   614,
      13,   356,  -216,   616,   617,   618,   311,   101,   357,   311,
     363,   573,   574,  -216,   364,   353,    76,   103,   523,   647,
      75,    76,  -288,   358,   256,    76,   322,   121,   122,   430,
     431,   432,   433,   356,   435,   105,   518,   417,   418,   660,
     357,   109,   463,   474,   107,   643,   322,   121,   122,   646,
     353,    76,   473,   355,   111,   358,   373,    76,   322,   121,
     122,   113,   653,   353,    76,   656,   526,   602,   658,   353,
      76,    17,   370,   114,   474,   474,   474,   474,   553,   554,
     555,   556,   604,   124,    19,   667,   538,   539,   126,    22,
     597,   224,   225,   474,   553,   554,   555,   556,   127,   244,
     133,     5,     6,   134,    15,   627,   552,   356,   553,   554,
     555,   556,   193,   245,   357,   246,   136,   138,   139,   214,
     247,   140,   141,   248,   249,   197,   198,   311,   250,   358,
     375,    76,   322,   121,   122,   615,   142,   553,   554,   555,
     556,   146,   149,   150,   177,   652,   251,   252,   199,   220,
     253,   134,   254,   221,   474,   227,   430,   431,   432,   433,
     661,   435,   223,   184,   321,   303,   255,   438,   439,   440,
     441,   442,   443,   297,   304,   312,   256,    76,   327,   671,
     665,   331,   257,   258,   347,   259,   260,   261,    75,   348,
     383,   262,   263,   264,   244,   391,     5,     6,   393,   392,
     394,   395,   396,    20,    21,   265,   397,   400,   245,   404,
     246,   405,   406,   659,   407,   247,   412,   364,   248,   249,
     411,   458,   416,   250,   419,   266,   267,   423,   459,   460,
     461,   467,   389,   485,   494,   493,   498,   435,   522,   528,
     529,   251,   252,   531,   537,   253,   134,   341,   532,   534,
     546,   535,   541,   542,   430,   431,   432,   433,   548,   435,
     549,   255,   560,   436,   437,   438,   439,   440,   441,   442,
     443,   256,    76,   217,   565,   421,   580,   257,   258,   581,
     259,   260,   261,   590,   591,   592,   262,   263,   264,   603,
     606,   621,   622,   623,   642,   624,   635,   644,    20,    21,
     265,   662,    -4,     1,   645,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,   657,   664,   668,    -4,    -4,    -4,    -4,   670,
     266,   267,    -4,    -4,    25,    26,    27,   181,   119,   401,
     171,   156,   190,   215,    -4,    -4,   222,   243,    -4,   354,
     589,   477,    -4,    -4,    -4,    -4,    -4,   571,   641,   640,
     545,   530,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,  -107,    12,  -103,  -105,     0,     0,     0,    13,
    -123,     0,     0,     0,     0,    -4,     0,     0,     0,     0,
       0,  -117,  -129,    -4,     0,    14,     0,     0,    -4,  -121,
    -109,  -111,  -113,    15,     0,     0,    -4,    -4,    -4,  -115,
      16,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -131,     0,     0,     0,     0,     0,     0,   626,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     0,    19,    20,    21,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -133,  -135,     0,  -125,  -127,  -119,   430,   431,   432,   433,
       0,   435,     0,     0,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   455,     0,     0,     0,     0,     0,     0,
     430,   431,   432,   433,     0,   435,     0,     0,     0,   436,
     437,   438,   439,   440,   441,   442,   443,   457,     0,     0,
       0,     0,     0,     0,   430,   431,   432,   433,     0,   435,
       0,     0,     0,   436,   437,   438,   439,   440,   441,   442,
     443,   619,     0,     0,     0,     0,     0,     0,   430,   431,
     432,   433,     0,   435,     0,     0,     0,   436,   437,   438,
     439,   440,   441,   442,   443,   620,     0,     0,     0,     0,
       0,     0,   430,   431,   432,   433,     0,   435,     0,     0,
       0,   436,   437,   438,   439,   440,   441,   442,   443,   501,
       0,     0,     0,   430,   431,   432,   433,     0,   435,     0,
       0,     0,   436,   437,   438,   439,   440,   441,   442,   443,
     502,     0,     0,     0,   430,   431,   432,   433,     0,   435,
       0,     0,     0,   436,   437,   438,   439,   440,   441,   442,
     443,   503,     0,     0,     0,   430,   431,   432,   433,     0,
     435,     0,     0,     0,   436,   437,   438,   439,   440,   441,
     442,   443,   550,     0,     0,     0,   430,   431,   432,   433,
       0,   435,     0,     0,     0,   436,   437,   438,   439,   440,
     441,   442,   443,   625,     0,     0,     0,   430,   431,   432,
     433,     0,   435,     0,     0,     0,   436,   437,   438,   439,
     440,   441,   442,   443,   637,     0,     0,     0,   430,   431,
     432,   433,     0,   435,     0,     0,     0,   436,   437,   438,
     439,   440,   441,   442,   443,   638,     0,     0,     0,   430,
     431,   432,   433,     0,   435,     0,     0,     0,   436,   437,
     438,   439,   440,   441,   442,   443,   663,     0,     0,     0,
     430,   431,   432,   433,     0,   435,     0,     0,     0,   436,
     437,   438,   439,   440,   441,   442,   443,   669,     0,     0,
       0,   430,   431,   432,   433,     0,   435,     0,     0,     0,
     436,   437,   438,   439,   440,   441,   442,   443,   430,   431,
     432,   433,   434,   435,     0,     0,     0,   436,   437,   438,
     439,   440,   441,   442,   443,   430,   431,   432,   433,     0,
     435,     0,   639,     0,   436,   437,   438,   439,   440,   441,
     442,   443,   430,   431,   432,   433,     0,   435,     0,     0,
       0,   436,   437,   438,   439,   440,   441,   442,   443,   430,
     431,   432,   433,     0,   435,     0,     0,     0,     0,   437,
     438,   439,   440,   441,   442,   443
};

static const yytype_int16 yycheck[] =
{
      69,   200,     1,    83,   227,    17,     1,    87,   564,   250,
     496,   191,    67,   214,   402,   216,   217,   406,    26,   220,
     219,   101,     1,   191,   265,   105,   132,   107,     1,   235,
     236,   237,   238,   239,   240,     1,    67,     0,    18,   423,
     197,   198,   199,     1,    54,    53,    55,     1,    13,   605,
      15,    60,    17,     1,     1,   124,   136,    37,   127,    54,
     115,    92,     1,   243,    29,    64,   146,    68,    78,   149,
     241,   151,   152,   153,   154,   243,     1,    78,    79,   250,
       1,     1,    55,    78,     1,   253,     1,    10,   472,   257,
     258,     1,   259,   260,   265,   483,     1,    55,   487,    78,
      79,    55,    97,    22,   660,   117,   118,     1,    55,    28,
     309,   312,    78,    79,   194,    81,   196,   129,   130,    34,
     319,   227,   608,   229,    78,   205,    11,    81,    82,    54,
      78,    79,   144,    81,    54,   102,     1,    54,   522,    78,
      79,   210,   211,    54,    54,   214,     1,   216,   217,   218,
       1,   220,     1,    78,    79,     1,    53,    78,    78,    79,
     359,    78,    79,    78,    79,   245,    53,    78,    78,   553,
     554,   555,   556,    78,    79,    55,    53,     1,     1,     1,
     347,   348,    62,    54,    78,   197,   198,   199,   572,   356,
     357,   358,    60,     1,    62,    53,   395,   396,   366,    54,
     399,   400,   370,   404,   405,    73,   407,    78,   409,    55,
     411,   417,   418,    78,    67,   604,    62,   323,    86,   325,
     391,    54,   389,    78,    55,   392,   467,    78,    59,    78,
     387,    77,    78,    79,    80,    81,    82,    53,   307,   251,
     252,   630,    53,   312,    90,    78,    54,    56,   419,   633,
     262,     1,   423,     1,    78,    78,    78,    53,    67,    54,
     113,    24,   115,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   139,   447,
      90,   448,   450,    78,   485,   453,    23,   488,    81,   150,
     489,    55,   304,    57,    15,   364,   467,    60,    61,    62,
      63,   472,   110,   111,    54,    55,   114,    55,   116,   117,
     118,   119,   120,    22,    62,   123,    60,   397,   398,    28,
      64,   129,   391,    60,    61,    62,    63,   550,    78,    77,
      78,    79,    80,    81,    82,   404,   405,    55,   407,    16,
     409,   421,   411,    55,    55,   568,    57,    13,    57,    67,
      41,   522,    50,    64,   423,   523,    42,     1,   526,    81,
      82,   567,    55,   562,   531,    32,    59,   534,    80,    81,
      82,   383,    62,    43,    67,   387,    61,   126,    63,   546,
      65,   548,   553,   554,   555,   556,   609,   493,    62,     1,
      80,    81,    82,    80,    81,    82,     6,     7,     8,     9,
      61,   572,    63,   472,    14,   606,    80,    81,    82,   576,
      20,    55,    56,   580,   581,   582,   485,    40,    62,   488,
      55,   501,   502,    67,    59,    78,    79,    21,    81,   628,
      78,    79,    67,    77,    78,    79,    80,    81,    82,    60,
      61,    62,    63,    55,    65,   124,    90,   112,   113,   648,
      62,    33,   464,   522,   125,   622,    80,    81,    82,   626,
      78,    79,   633,     1,    83,    77,    78,    79,    80,    81,
      82,   121,   639,    78,    79,   642,    81,   557,   645,    78,
      79,    91,    81,   122,   553,   554,   555,   556,    60,    61,
      62,    63,   561,    57,   104,   662,    98,    99,    67,   109,
      56,   179,   180,   572,    60,    61,    62,    63,    57,     1,
      53,     3,     4,    53,    44,   595,    58,    55,    60,    61,
      62,    63,    31,    15,    62,    17,    78,    78,    78,    22,
      22,    78,    78,    25,    26,    55,    55,   606,    30,    77,
      78,    79,    80,    81,    82,    58,    78,    60,    61,    62,
      63,    78,    78,    78,    78,   635,    48,    49,    55,    64,
      52,    53,    54,    58,   633,    64,    60,    61,    62,    63,
     650,    65,    58,    55,    12,    56,    68,    71,    72,    73,
      74,    75,    76,    67,    67,    73,    78,    79,    78,   669,
     659,    78,    84,    85,    55,    87,    88,    89,    78,    55,
      53,    93,    94,    95,     1,    57,     3,     4,    67,    64,
      78,    56,    56,   105,   106,   107,    56,    58,    15,    23,
      17,    23,    58,    19,    73,    22,    56,    59,    25,    26,
      67,    78,    67,    30,    67,   127,   128,    64,    57,    64,
      24,   108,    55,    67,    78,    71,    45,    65,    57,    71,
      73,    48,    49,    67,    57,    52,    53,    54,    78,    67,
      55,    78,    78,    78,    60,    61,    62,    63,    22,    65,
      56,    68,    19,    69,    70,    71,    72,    73,    74,    75,
      76,    78,    79,    28,    71,    37,    55,    84,    85,    55,
      87,    88,    89,    58,    61,    78,    93,    94,    95,    71,
      23,    58,    64,    35,    64,    58,    27,    55,   105,   106,
     107,    55,     0,     1,    64,     3,     4,     5,     6,     7,
       8,     9,    78,    56,    60,    13,    14,    15,    16,    78,
     127,   128,    20,    21,     3,     3,     3,   131,    66,   307,
     118,   114,   134,   164,    32,    33,   177,   190,    36,   253,
     537,   393,    40,    41,    42,    43,    44,   498,   620,   619,
     464,   453,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    32,    33,    91,    -1,    36,    -1,    -1,    96,    40,
      41,    42,    43,    44,    -1,    -1,   104,   105,   106,    50,
      51,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      91,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,    -1,   124,   125,   126,    60,    61,    62,    63,
      -1,    65,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    65,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    65,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    56,
      -1,    -1,    -1,    60,    61,    62,    63,    -1,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      56,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    65,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    56,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      65,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    56,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    65,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    56,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    65,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    56,    -1,    -1,    -1,    60,    61,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    56,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    56,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    56,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    65,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    60,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    60,    61,    62,    63,    -1,
      65,    -1,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    60,    61,    62,    63,    -1,    65,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    60,
      61,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   133,   134,     0,     3,     4,     5,     6,     7,
       8,     9,    14,    20,    36,    44,    51,    91,    96,   104,
     105,   106,   109,   135,   136,   137,   138,   139,   140,   141,
     143,   145,   146,   154,   163,   167,   171,   173,   176,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   203,   271,    10,
      11,   102,    53,    53,    53,    53,    53,    53,     1,    78,
       1,    78,   204,    90,     1,    78,    79,   142,   158,   174,
      81,    53,   272,    15,   198,    16,   224,    13,   247,    41,
     225,    42,   226,    43,   231,    50,   233,    32,   236,   126,
     237,    40,   248,    21,   227,   124,   199,   125,   200,    33,
     228,    83,   259,   121,   122,   147,   164,   168,   172,   147,
     155,    81,    82,   161,    57,   205,    67,    57,   175,    67,
      92,   144,   177,    53,    53,   202,    78,   202,    78,    78,
      78,    78,    78,     1,    55,   202,    78,   202,   202,    78,
      78,    13,    15,    17,    29,   201,   201,     1,    54,    78,
     148,     1,    54,    78,    97,   165,     1,    54,   158,   169,
      54,   169,    54,    54,    78,   156,   161,    78,   161,   158,
     158,   145,     1,    54,    55,    78,   150,   178,   179,   273,
     203,   206,   202,    31,   245,   246,   245,    55,    55,    55,
     158,   234,   235,   202,   202,   245,   202,   202,   202,   202,
      57,    64,   149,   150,    22,   165,    22,    28,    57,   170,
      64,    58,   205,    58,   175,   175,   151,    64,     1,    64,
       1,    54,   110,   111,   114,   116,   117,   118,   119,   120,
     123,   129,   275,   206,     1,    15,    17,    22,    25,    26,
      30,    48,    49,    52,    54,    68,    78,    84,    85,    87,
      88,    89,    93,    94,    95,   107,   127,   128,   137,   138,
     139,   158,   202,   207,   208,   209,   212,   216,   219,   220,
     223,   229,   239,   241,   243,   249,   250,   252,   255,   260,
     262,   263,   266,   267,     1,    78,   202,    67,   202,   234,
     234,   234,   149,    56,    67,   202,   161,    62,    80,   159,
     160,   161,    73,   152,   159,   159,   159,   161,   149,   157,
     159,    12,    80,   150,   161,   162,   150,    78,     1,    78,
     276,    78,   276,   276,   276,   276,   276,   276,   142,   258,
     274,    54,   202,     1,    78,     1,    78,    55,    55,     1,
     258,   158,   158,    78,   208,     1,    55,    62,    77,   162,
     209,   211,   212,    55,    59,     1,    81,   209,   251,     1,
      81,   209,   261,    78,   211,    78,   211,     1,    34,    78,
      79,     1,   158,    53,   258,   264,     1,    55,     1,    55,
     240,    57,    64,    67,    78,    56,    56,    56,   238,   158,
      58,   160,   149,   159,    23,    23,    58,    73,   153,    67,
     149,    67,    56,    62,   150,   150,    67,   112,   113,    67,
      18,    37,   244,    64,   211,   211,   211,   211,   211,   149,
      60,    61,    62,    63,    64,    65,    69,    70,    71,    72,
      73,    74,    75,    76,   213,   161,   209,    60,    64,   209,
      60,    62,    73,    86,   253,    53,   256,    53,    78,    57,
      64,    24,     1,   158,   268,   269,   270,   108,   265,   234,
     211,     1,    55,   142,   161,   210,   211,   240,   149,   149,
     202,   202,   149,   149,   152,    67,   159,   159,    22,   170,
     159,   159,   159,    71,    78,   276,   276,   142,    45,   202,
     210,    56,    56,    56,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,    90,   211,
     214,   215,    57,    81,   209,   211,    81,   209,    71,    73,
     261,    67,    78,   254,    67,    78,   257,    57,    98,    99,
     230,    78,    78,    57,    54,   269,    55,   258,    22,    56,
      56,   210,    58,    60,    61,    62,    63,   232,   152,   159,
      19,   166,   170,   159,   149,    71,   150,   113,   115,   277,
     277,   244,    23,   202,   202,    56,    67,   210,   209,   209,
      55,    55,    55,   211,    54,    78,   211,    54,    78,   230,
      58,    61,    78,   211,   211,   242,   162,    56,   210,   210,
     210,   210,   202,    71,   161,   149,    23,   153,   276,    62,
     162,   210,   221,    90,   211,    58,   211,   211,   211,    53,
      53,    58,    64,    35,    58,    56,    23,   202,   170,   153,
     159,   277,   162,    24,   218,    27,   222,    56,    56,    67,
     254,   257,    64,   211,    55,    64,   211,   149,   170,   210,
     217,    26,   202,   211,    54,    54,   211,    78,   211,    19,
     149,   202,    55,    56,    56,   161,   153,   211,    60,    56,
      78,   202
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 112 "parse1.y"
    {diag("Illegal block", (char *)0);}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 115 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 123 "parse1.y"
    {P1{if (!title) title = (yyvsp[(2) - (2)].qp);}}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 130 "parse1.y"
    { unitonflag = unitflagsave = 1;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 132 "parse1.y"
    {unitonflag = unitflagsave = 0;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 135 "parse1.y"
    {P1{include_file((yyvsp[(2) - (2)].qp));}}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 138 "parse1.y"
    {P1{define_value((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 139 "parse1.y"
    {myerr("syntax: DEFINE name integer");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 142 "parse1.y"
    {P1{(yyvsp[(1) - (1)].qp)->element = (void *)checklocal(SYM((yyvsp[(1) - (1)].qp)));}}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 145 "parse1.y"
    {declare_level = atoi(STR((yyvsp[(2) - (2)].qp)));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 146 "parse1.y"
    {declare_level = 0;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 155 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 162 "parse1.y"
    {P1{(yyval.qp) = itemarray(7, (yyvsp[(1) - (5)].qp), (yyvsp[(4) - (5)].qp), ITEM0, (yyvsp[(3) - (5)].qp),ITEM0,ITEM0,ITEM0); declare(CONST, (yyvsp[(1) - (5)].qp), (yyval.qp));}}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 164 "parse1.y"
    {P1{(yyval.qp) = itemarray(7, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), ITEM0,ITEM0,ITEM0,ITEM0,ITEM0); declare(CONST, (yyvsp[(1) - (3)].qp), (yyval.qp));}}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 166 "parse1.y"
    {P1{(yyval.qp) = itemarray(7, (yyvsp[(1) - (6)].qp), (yyvsp[(5) - (6)].qp), (yyvsp[(3) - (6)].qp), ITEM0, ITEM0,ITEM0,ITEM0); declare(CONST, (yyvsp[(1) - (6)].qp), (yyval.qp));}}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 167 "parse1.y"
    {myerr("name = number");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 170 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 173 "parse1.y"
    {P1{lex_units();}}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 174 "parse1.y"
    {(yyval.qp) = (yyvsp[(3) - (4)].qp); lastok = (yyvsp[(4) - (4)].qp); P2{unitcheck(STR((yyvsp[(3) - (4)].qp)));}}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 177 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 181 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 187 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 191 "parse1.y"
    {P1{(yyval.qp) = itemarray(3,(yyvsp[(1) - (4)].qp), (yyvsp[(4) - (4)].qp), (yyvsp[(3) - (4)].qp)); declare(STEP1, (yyvsp[(1) - (4)].qp), (yyval.qp));}}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 196 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 197 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 200 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 202 "parse1.y"
    {lastok = (yyvsp[(2) - (2)].qp);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 210 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 212 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 217 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 219 "parse1.y"
    {P1{declare(INDEP, ITMA((yyvsp[(2) - (2)].qp))[0], (yyvsp[(2) - (2)].qp));}}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 221 "parse1.y"
    {P1{ITMA((yyvsp[(3) - (3)].qp))[7] = (yyvsp[(2) - (3)].qp); declare(INDEP, ITMA((yyvsp[(3) - (3)].qp))[0], (yyvsp[(3) - (3)].qp));}}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 225 "parse1.y"
    {P1{(yyval.qp) = itemarray(8, (yyvsp[(1) - (9)].qp), (yyvsp[(9) - (9)].qp), (yyvsp[(3) - (9)].qp), (yyvsp[(5) - (9)].qp), (yyvsp[(6) - (9)].qp), (yyvsp[(7) - (9)].qp), (yyvsp[(8) - (9)].qp), ITEM0);}}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 226 "parse1.y"
    {myerr("name FROM number TO number WITH integer");}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 233 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 235 "parse1.y"
    {P1{declare(DEP, ITMA((yyvsp[(2) - (2)].qp))[0], (yyvsp[(2) - (2)].qp));}}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 238 "parse1.y"
    {P1{(yyval.qp) = itemarray(7, (yyvsp[(1) - (4)].qp), (yyvsp[(3) - (4)].qp), ITEM0, ITEM0, ITEM0, (yyvsp[(2) - (4)].qp), ITEM0);}}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 240 "parse1.y"
    {P1{(yyval.qp) = itemarray(7, (yyvsp[(1) - (7)].qp), (yyvsp[(6) - (7)].qp), (yyvsp[(3) - (7)].qp), ITEM0, ITEM0, (yyvsp[(5) - (7)].qp), ITEM0);}}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 242 "parse1.y"
    {P1{(yyval.qp) = itemarray(7, (yyvsp[(1) - (8)].qp), (yyvsp[(7) - (8)].qp), ITEM0, (yyvsp[(3) - (8)].qp), (yyvsp[(5) - (8)].qp), (yyvsp[(6) - (8)].qp), ITEM0);}}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 244 "parse1.y"
    {P1{(yyval.qp) = itemarray(7, (yyvsp[(1) - (11)].qp), (yyvsp[(10) - (11)].qp), (yyvsp[(3) - (11)].qp), (yyvsp[(6) - (11)].qp), (yyvsp[(8) - (11)].qp), (yyvsp[(9) - (11)].qp), ITEM0);}}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 245 "parse1.y"
    {
diag("name FROM number TO number START number\n",
"FROM...TO and START are optional, name can be name[integer]\n");}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 249 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 250 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 255 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 257 "parse1.y"
    {P1{declare(STAT, ITMA((yyvsp[(2) - (2)].qp))[0], (yyvsp[(2) - (2)].qp));}}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 260 "parse1.y"
    { myerr("PLOT namelist VS name");}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 266 "parse1.y"
    { (yyval.qp) = ITEM0;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 268 "parse1.y"
    { (yyval.qp) = (yyvsp[(2) - (3)].qp);}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 273 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 278 "parse1.y"
    {P1{install_units(STR((yyvsp[(1) - (3)].qp)), STR((yyvsp[(3) - (3)].qp)));}}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 279 "parse1.y"
    {myerr("Unit definition syntax: (units) = (units)");}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 282 "parse1.y"
    {P1{(yyval.qp) = itemarray(3, (yyvsp[(1) - (4)].qp), (yyvsp[(4) - (4)].qp), (yyvsp[(3) - (4)].qp)); declare(UFACTOR, (yyvsp[(1) - (4)].qp), (yyval.qp));}}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 284 "parse1.y"
    {P1{Item *q; double d, unit_mag();
		    Unit_push(STR((yyvsp[(3) - (4)].qp)));
			Unit_push(STR((yyvsp[(4) - (4)].qp))); unit_div();
			dimensionless();
			Sprintf(buf, "%g", unit_mag());
			(yyval.qp) = itemarray(3, (yyvsp[(1) - (4)].qp), (yyvsp[(4) - (4)].qp), lappendstr(misc, buf));
/*printf("%s has value %s and units (%s)\n", SYM($1)->name, buf, STR($5));*/
		    unit_pop();
		    declare(UFACTOR, (yyvsp[(1) - (4)].qp), (yyval.qp));
		}}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 295 "parse1.y"
    {P1{ Item *q; double unit_mag();
		    Unit_push(STR((yyvsp[(3) - (6)].qp))); Unit_push(STR((yyvsp[(6) - (6)].qp))); unit_div();
		    q = lappendstr(misc, unit_str());
		    dimensionless();
		    Sprintf(buf, "%g", 1./unit_mag());
		    (yyval.qp) = itemarray(3, (yyvsp[(1) - (6)].qp), lappendstr(misc, buf), q),
/*printf("%s has value %s and units (%s)\n", SYM($1)->name, STR(q), buf );*/
		    unit_pop();
		    declare(UFACTOR, (yyvsp[(1) - (6)].qp), (yyval.qp));
		}}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 305 "parse1.y"
    {myerr("Unit factor syntax: examples:\n\
foot2inch = (foot) -> (inch)\n\
F = 96520 (coulombs)\n\
R = (k-mole) (joule/degC)");
		}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 311 "parse1.y"
    {blocktype = INITIAL1;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 312 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 313 "parse1.y"
    {lexcontext = NONLINEAR; blocktype = DERIVATIVE;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 314 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 315 "parse1.y"
    {blocktype = BREAKPOINT;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 316 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 317 "parse1.y"
    {lexcontext = blocktype = LINEAR;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 318 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 319 "parse1.y"
    {lexcontext = blocktype = NONLINEAR;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 320 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 321 "parse1.y"
    {blocktype = FUNCTION1;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 322 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 323 "parse1.y"
    {blocktype = FUNCTION_TABLE;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 324 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 325 "parse1.y"
    {blocktype = PROCEDURE;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 326 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 327 "parse1.y"
    {blocktype = PROCEDURE;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 328 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 329 "parse1.y"
    {blocktype = TERMINAL;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 330 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 331 "parse1.y"
    {blocktype = DISCRETE;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 332 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 333 "parse1.y"
    {blocktype = CONSTRUCTOR;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 334 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 335 "parse1.y"
    {blocktype = DESTRUCTOR;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 336 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 337 "parse1.y"
    {lexcontext = blocktype = PARTIAL;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 338 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 339 "parse1.y"
    {lexcontext = blocktype = KINETIC;
		P3 R0{unitflagsave=unitonflag; unitonflag=0;}}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 342 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp); P3{ R0{unitonflag=unitflagsave;}
		R1{clear_compartlist();} parse_restart((yyval.qp), 1);}}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 344 "parse1.y"
    {blocktype = BEFORE;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 344 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (3)].qp);}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 345 "parse1.y"
    {blocktype = AFTER;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 345 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (3)].qp);}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 359 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (3)].qp);}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 361 "parse1.y"
    {P1{poplocal();}}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 364 "parse1.y"
    {myerr("Illegal LOCAL declaration");}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 367 "parse1.y"
    {P1{pushlocal((yyvsp[(1) - (2)].qp), (yyvsp[(2) - (2)].qp));}}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 369 "parse1.y"
    {P1{install_local((yyvsp[(3) - (4)].qp), (yyvsp[(4) - (4)].qp));}}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 372 "parse1.y"
    { (yyval.qp) = ITEM0;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 374 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (3)].qp);}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 377 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 406 "parse1.y"
    {myerr("Illegal statement");}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 409 "parse1.y"
    {
		  P3 {
			if (SYM((yyvsp[(1) - (3)].qp))->subtype & LOCL) {
				SYM((yyvsp[(1) - (3)].qp))->u.str = stralloc(unit_str(), (char *)0);
				unit_pop();
			}else{
			   unit_push((yyvsp[(1) - (3)].qp)); unit_swap();
			   unit_cmp((yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok); unit_pop();
			}
		  }
		}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 421 "parse1.y"
    {
		  P3 {
			unit_cmp((yyvsp[(2) - (4)].qp), (yyvsp[(3) - (4)].qp), lastok); unit_pop();
		  }
		}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 428 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);
		  P1{SYM((yyvsp[(1) - (1)].qp))->usage |= DEP;}
		  P2{ if (SYM((yyvsp[(1) - (1)].qp))->subtype & ARRAY) {
			myerr("variable needs an index");}
		  }
		}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 435 "parse1.y"
    {lastok = (yyvsp[(4) - (4)].qp); 
		  P1{SYM((yyvsp[(1) - (4)].qp))->usage |= DEP;}
		  P2{ if ((SYM((yyvsp[(1) - (4)].qp))->subtype & ARRAY) == 0)
			{myerr("variable is not an array");}
		  }
		}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 442 "parse1.y"
    {lastok = (yyvsp[(3) - (3)].qp);
		  P1{SYM((yyvsp[(1) - (3)].qp))->usage |= DEP;}
		  P2{ if (SYM((yyvsp[(1) - (3)].qp))->subtype & ARRAY) {
			myerr("variable needs an index");}
		  }
		}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 450 "parse1.y"
    {lastok = (yyvsp[(6) - (6)].qp);
		  P1{SYM((yyvsp[(1) - (6)].qp))->usage |= DEP;}
		  P2{ if ((SYM((yyvsp[(1) - (6)].qp))->subtype & ARRAY) == 0)
			{myerr("variable is not an array");}
		  }
		}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 458 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp); P1{SYM((yyvsp[(1) - (1)].qp))->usage |= DEP;}}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 459 "parse1.y"
    { lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 460 "parse1.y"
    { lastok = (yyvsp[(3) - (3)].qp);}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 465 "parse1.y"
    {myerr("Illegal integer expression");}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 467 "parse1.y"
    {P3{unit_push((yyvsp[(1) - (1)].qp));}}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 468 "parse1.y"
    {P3{if ((yyvsp[(2) - (2)].qp)) {
				Unit_push(STR((yyvsp[(2) - (2)].qp)));
			     }else{		
				Unit_push((char *)0);
			     }
			}}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 474 "parse1.y"
    {P3{unit_push((yyvsp[(1) - (1)].qp));}}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 475 "parse1.y"
    { lastok = (yyvsp[(3) - (3)].qp);
			  P3{ifcnvfac((yyvsp[(3) - (3)].qp));}
			}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 478 "parse1.y"
    {P3{unit_cmp((yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 479 "parse1.y"
    {P3{unit_cmp((yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 480 "parse1.y"
    {P3{unit_mul();}}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 481 "parse1.y"
    {P3{unit_div();}}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 482 "parse1.y"
    {P3{unit_exponent((yyvsp[(3) - (3)].qp), lastok);}}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 483 "parse1.y"
    {P3{unit_logic(1, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 484 "parse1.y"
    {P3{unit_logic(1, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 485 "parse1.y"
    {P3{unit_logic(2, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 486 "parse1.y"
    {P3{unit_logic(2, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 487 "parse1.y"
    {P3{unit_logic(2, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 488 "parse1.y"
    {P3{unit_logic(2, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 489 "parse1.y"
    {P3{unit_logic(2, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 490 "parse1.y"
    {P3{unit_logic(2, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), lastok);}}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 491 "parse1.y"
    {P3{unit_pop(); Unit_push("");}}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 493 "parse1.y"
    {myerr("Illegal expression");}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 495 "parse1.y"
    {P3{unit_push_args((yyvsp[(1) - (2)].qp));}}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 496 "parse1.y"
    { lastok = (yyvsp[(5) - (5)].qp); P1{SYM((yyvsp[(1) - (5)].qp))->usage |= FUNCT;}
		  P3{unit_done_args();}
		}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 501 "parse1.y"
    {(yyval.qp) = ITEM0; }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 504 "parse1.y"
    {P3{unit_chk_arg((yyvsp[(1) - (1)].qp), lastok);}}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 506 "parse1.y"
    {P3{unit_chk_arg((yyvsp[(3) - (3)].qp), lastok);}}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 509 "parse1.y"
    {P1{pushlocal((yyvsp[(2) - (7)].qp), ITEM0);}}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 510 "parse1.y"
    {P1{(yyval.qp) = itemarray(6, (yyvsp[(1) - (9)].qp), (yyvsp[(2) - (9)].qp), (yyvsp[(4) - (9)].qp), (yyvsp[(6) - (9)].qp), (yyvsp[(7) - (9)].qp), (yyvsp[(9) - (9)].qp)); poplocal();}}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 511 "parse1.y"
    {
myerr("FROM intvar = intexpr TO intexpr BY intexpr { statements }");}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 514 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 517 "parse1.y"
    {P3{unit_pop();}}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 519 "parse1.y"
    {P3{unit_pop();}}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 522 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 523 "parse1.y"
    {P3{unit_pop();}}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 526 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 532 "parse1.y"
    {P1{(yyval.qp) = itemarray(3, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp)); declare(DERF, (yyvsp[(2) - (3)].qp), (yyval.qp));}}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 535 "parse1.y"
    {P1{(yyval.qp) = itemarray(4, (yyvsp[(1) - (4)].qp), (yyvsp[(2) - (4)].qp), (yyvsp[(3) - (4)].qp), (yyvsp[(4) - (4)].qp)); declare(LINF, (yyvsp[(2) - (4)].qp), (yyval.qp));}}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 538 "parse1.y"
    {P1{(yyval.qp) = itemarray(4, (yyvsp[(1) - (4)].qp), (yyvsp[(2) - (4)].qp), (yyvsp[(3) - (4)].qp), (yyvsp[(4) - (4)].qp)); declare(NLINF, (yyvsp[(2) - (4)].qp), (yyval.qp));}}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 541 "parse1.y"
    {P1{(yyval.qp) = itemarray(3, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp)); declare(DISCF, (yyvsp[(2) - (3)].qp), (yyval.qp));}}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 544 "parse1.y"
    {P1{(yyval.qp) = itemarray(3, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp)); declare(PARF, (yyvsp[(2) - (3)].qp), (yyval.qp));}}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 547 "parse1.y"
    {lastok = (yyvsp[(11) - (11)].qp);
		 P3{
			unit_push((yyvsp[(4) - (11)].qp)); unit_del(2); unit_mul();
			unit_push((yyvsp[(8) - (11)].qp)); unit_mul();
			unit_push((yyvsp[(11) - (11)].qp)); unit_cmp((yyvsp[(4) - (11)].qp), (yyvsp[(10) - (11)].qp), (yyvsp[(11) - (11)].qp));
			unit_push((yyvsp[(2) - (11)].qp)); unit_swap(); unit_cmp((yyvsp[(2) - (11)].qp), (yyvsp[(3) - (11)].qp), (yyvsp[(11) - (11)].qp));
			unit_pop();
		}}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 556 "parse1.y"
    {P3{
			unit_del(1);
			unit_push((yyvsp[(3) - (8)].qp)); unit_mul(); unit_swap();
			unit_cmp((yyvsp[(2) - (8)].qp),(yyvsp[(7) - (8)].qp),lastok); unit_pop();
		}}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 562 "parse1.y"
    {P3{unit_push((yyvsp[(2) - (7)].qp)); unit_swap();
		    unit_cmp((yyvsp[(2) - (7)].qp),(yyvsp[(6) - (7)].qp),lastok); unit_pop();
		}}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 565 "parse1.y"
    {myerr("Illeqal partial diffeq");}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 570 "parse1.y"
    {P1{pushlocal((yyvsp[(2) - (6)].qp), ITEM0); func_unit((yyvsp[(2) - (6)].qp), (yyvsp[(6) - (6)].qp));}}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 572 "parse1.y"
    {P1{
		    declare(FUNCT, (yyvsp[(2) - (8)].qp), itemarray(3, (yyvsp[(2) - (8)].qp), (yyvsp[(6) - (8)].qp), (yyvsp[(4) - (8)].qp)));
		    poplocal(); poplocal(); SYM((yyvsp[(2) - (8)].qp))->usage |= FUNCT;
		   }
		}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 579 "parse1.y"
    {P1{pushlocal((yyvsp[(2) - (6)].qp), ITEM0); func_unit((yyvsp[(2) - (6)].qp), (yyvsp[(6) - (6)].qp));}
		 P1{
		    declare(FUNCT, (yyvsp[(2) - (6)].qp), itemarray(3, (yyvsp[(2) - (6)].qp), (yyvsp[(6) - (6)].qp), (yyvsp[(4) - (6)].qp)));
		    poplocal(); poplocal(); SYM((yyvsp[(2) - (6)].qp))->usage |= FUNCT;
		   }
		}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 587 "parse1.y"
    {(yyval.qp) = ITEM0; P1{pushlocal(ITEM0, ITEM0);}
			if (args) { freelist(&args); }
			args = newlist();
		}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 594 "parse1.y"
    {P1{
		    if (args) { freelist(&args); }
		    args = newlist();
		    (yyval.qp) = (Item *)newlist();
		    pushlocal((yyvsp[(1) - (2)].qp), ITEM0);
		    Lappendsym(args, checklocal(SYM((yyvsp[(1) - (2)].qp))));
		    if ((yyvsp[(2) - (2)].qp)) {
			checklocal(SYM((yyvsp[(1) - (2)].qp)))->u.str = STR((yyvsp[(2) - (2)].qp));
			Lappendstr((List *)(yyval.qp), STR((yyvsp[(2) - (2)].qp)));
		    }else{
			Lappendstr((List *)(yyval.qp), "");
		    }
		}}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 608 "parse1.y"
    {P1{
		    pushlocal((yyvsp[(3) - (4)].qp), ITEM0);
		    Lappendsym(args, checklocal(SYM((yyvsp[(3) - (4)].qp))));
		    if ((yyvsp[(4) - (4)].qp)) {
			checklocal(SYM((yyvsp[(3) - (4)].qp)))->u.str = STR((yyvsp[(4) - (4)].qp));
			Lappendstr((List *)(yyvsp[(1) - (4)].qp), STR((yyvsp[(4) - (4)].qp)));
		    }else{
			Lappendstr((List *)(yyvsp[(1) - (4)].qp), "");
		    }
		}}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 620 "parse1.y"
    {P1{
		    declare(PROCED, (yyvsp[(2) - (6)].qp), itemarray(3, (yyvsp[(2) - (6)].qp), ITEM0, (yyvsp[(4) - (6)].qp)));
		    poplocal(); SYM((yyvsp[(2) - (6)].qp))->usage |= FUNCT;
		   }
		}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 627 "parse1.y"
    {P1{
			List* l; Item* q;
			if ((yyvsp[(3) - (4)].qp) == ITEM0) {
				diag("NET_RECEIVE must have at least one argument", (char*)0);
			}
			l = newlist();
			q = lappendsym(l, install("flag", NAME));
			pushlocal(q, ITEM0);
			Lappendstr((List *)(yyvsp[(3) - (4)].qp), "");
			netreceive_arglist = args; args = (List*)0;
		}}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 639 "parse1.y"
    { P1{poplocal();}}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 640 "parse1.y"
    { myerr("Illegal NETRECEIVE block");}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 645 "parse1.y"
    { myerr("Illegal WATCH statement");}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 650 "parse1.y"
    {P1{ Item* q1, *q2;
		  q1 = netreceive_arglist->next;
		  q2 = args->next;
		  while (q1 != netreceive_arglist && q2 != args) {
			Symbol* s1 = SYM(q1);
			Symbol* s2 = SYM(q2);
			if (s1->u.str) { /* s2 must be nil or same */
				if (s2->u.str) {
					if (strcmp(s1->u.str, s2->u.str) != 0) {
						diag(s1->name, " in FOR_NETCONS arglist does not have same units as corresponding arg in NET_RECEIVE arglist");
					}
				}else{
					s2->u.str = s1->u.str;
				}
			}else{ /* s2 must be nil */
				if (s2->u.str) {
					diag(s1->name, " in FOR_NETCONS arglist does not have same units as corresponding arg in NET_RECEIVE arglist");
				}
			}
/*printf("|%s|%s|  |%s|%s|\n", s1->name, s1->u.str, s2->name, s2->u.str);*/
			q1 = q1->next;
			q2 = q2->next;
		  }
		  if (q1 != netreceive_arglist || q2 != args) {
			diag("NET_RECEIVE and FOR_NETCONS do not have same number of arguments", (char*)0);
		  }
		}}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 678 "parse1.y"
    { myerr("Illegal FOR_NETCONS statement");}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 682 "parse1.y"
    {P1{(yyval.qp) = itemarray(4, (yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), ITEM0, (yyvsp[(3) - (3)].qp)); lappenditem(solvelist, (yyval.qp));}}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 684 "parse1.y"
    {P1{(yyval.qp) = itemarray(4, (yyvsp[(1) - (5)].qp), (yyvsp[(2) - (5)].qp), (yyvsp[(3) - (5)].qp), (yyvsp[(4) - (5)].qp)); lappenditem(solvelist, (yyval.qp));}}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 685 "parse1.y"
    { myerr("Illegal SOLVE statement");}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 688 "parse1.y"
    { (yyval.qp) = ITEM0; }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 690 "parse1.y"
    { (yyval.qp) = (yyvsp[(2) - (2)].qp); }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 693 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 697 "parse1.y"
    { P2{if(!(SYM((yyvsp[(2) - (2)].qp))->subtype&STAT)){
			myerr("Not a STATE");}
		  }
		}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 702 "parse1.y"
    { P2{if(!(SYM((yyvsp[(2) - (3)].qp))->subtype&STAT)){
			myerr("Not a STATE");}
		  }
		}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 706 "parse1.y"
    {myerr("Syntax: SOLVEFOR name, name, ...");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 713 "parse1.y"
    {myerr("syntax is SENS var1, var2, var3, etc");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 717 "parse1.y"
    {P3{unit_cmp((yyvsp[(2) - (4)].qp), (yyvsp[(3) - (4)].qp), lastok);}}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 718 "parse1.y"
    {myerr("Illegal CONSERVE syntax");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 720 "parse1.y"
    {P3{consreact_push((yyvsp[(1) - (1)].qp));}}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 721 "parse1.y"
    {P3{consreact_push((yyvsp[(2) - (2)].qp));}}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 722 "parse1.y"
    {P3{consreact_push((yyvsp[(3) - (3)].qp)); unit_cmp((yyvsp[(1) - (3)].qp),(yyvsp[(2) - (3)].qp),lastok);}}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 723 "parse1.y"
    {
		  P3{consreact_push((yyvsp[(4) - (4)].qp)); unit_cmp((yyvsp[(1) - (4)].qp),(yyvsp[(2) - (4)].qp),lastok);}
		}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 727 "parse1.y"
    {P1{pushlocal((yyvsp[(2) - (2)].qp), ITEM0);}}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 728 "parse1.y"
    {P1{poplocal();}
		  P3{
		    unit_pop();
		  }
		}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 734 "parse1.y"
    { P3{
		    unit_pop();
		  }
		}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 740 "parse1.y"
    {P3 R0{unit_compartlist((yyvsp[(1) - (1)].qp));}}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 742 "parse1.y"
    {P3 R0{unit_compartlist((yyvsp[(2) - (2)].qp));}}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 744 "parse1.y"
    {P1{pushlocal((yyvsp[(2) - (2)].qp), ITEM0);}}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 745 "parse1.y"
    {P1{poplocal();}
		  P3{
		    unit_pop();
		  }
		}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 751 "parse1.y"
    { P3{
		    unit_pop();
		  }
		}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 757 "parse1.y"
    {P3 R0{unit_ldifuslist((yyvsp[(1) - (1)].qp), unitflagsave);}}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 759 "parse1.y"
    {P3 R0{unit_ldifuslist((yyvsp[(2) - (2)].qp), unitflagsave);}}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 765 "parse1.y"
    {P1{declare(KINF, (yyvsp[(2) - (4)].qp), ITEM0);}}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 768 "parse1.y"
    {P3{kinunits((yyvsp[(3) - (9)].qp), restart_pass);}}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 770 "parse1.y"
    {P3{kinunits((yyvsp[(3) - (7)].qp), restart_pass);}}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 772 "parse1.y"
    {P3{kinunits((yyvsp[(3) - (7)].qp), restart_pass);}}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 773 "parse1.y"
    {myerr("Illegal reaction syntax");}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 775 "parse1.y"
    {P3{R1{ureactadd((yyvsp[(1) - (1)].qp));} unit_push((yyvsp[(1) - (1)].qp));}}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 776 "parse1.y"
    {P3{R1{ureactadd((yyvsp[(2) - (2)].qp));} unit_push((yyvsp[(2) - (2)].qp)); Unit_push((char*)0); unit_exponent((yyvsp[(1) - (2)].qp),(yyvsp[(1) - (2)].qp));}}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 777 "parse1.y"
    {P3{R1{ureactadd((yyvsp[(3) - (3)].qp));}unit_push((yyvsp[(3) - (3)].qp)); unit_mul();}}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 778 "parse1.y"
    {
		  P3{R1{ureactadd((yyvsp[(4) - (4)].qp));}unit_push((yyvsp[(4) - (4)].qp)); Unit_push((char*)0); unit_exponent((yyvsp[(3) - (4)].qp),(yyvsp[(3) - (4)].qp)); unit_mul();}
		}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 783 "parse1.y"
    {myerr("Lag syntax is: LAG name BY const");}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 786 "parse1.y"
    {P3{unit_pop(); unit_pop();}}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 789 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 793 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 807 "parse1.y"
    {myerr("MATCH syntax is state0 or state(expr)=expr or\
state[i](expr(i)) = expr(i)");}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 815 "parse1.y"
    {
			  lastok = (yyvsp[(1) - (1)].qp);
#if NRNUNIT
			  P2{nrn_unit_chk();}
#endif
			}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 822 "parse1.y"
    {lastok = (yyvsp[(3) - (5)].qp);}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 826 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 829 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp),(yyvsp[(3) - (3)].qp));}}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 831 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp),(yyvsp[(3) - (3)].qp));}}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 833 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 835 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 837 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 839 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 841 "parse1.y"
    { P1{nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 845 "parse1.y"
    {(yyval.qp) = NULL;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 849 "parse1.y"
    {P1{nrn_use((yyvsp[(2) - (5)].qp), (yyvsp[(4) - (5)].qp), ITEM0);}}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 851 "parse1.y"
    {P1{nrn_use((yyvsp[(2) - (5)].qp), ITEM0, (yyvsp[(4) - (5)].qp));}}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 853 "parse1.y"
    {P1{nrn_use((yyvsp[(2) - (7)].qp), (yyvsp[(4) - (7)].qp), (yyvsp[(6) - (7)].qp));}}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 855 "parse1.y"
    {myerr("syntax is: USEION ion READ list WRITE list");}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 858 "parse1.y"
    {P1{(yyval.qp) = (Item *)newlist(); Lappendsym((List *)(yyval.qp), SYM((yyvsp[(1) - (1)].qp)));}}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 860 "parse1.y"
    {P1{ Lappendsym((List *)(yyvsp[(1) - (3)].qp), SYM((yyvsp[(3) - (3)].qp)));}}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 862 "parse1.y"
    {myerr("syntax is: keyword name , name, ..., name");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 865 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 867 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 869 "parse1.y"
    {(yyval.qp) = (yyvsp[(3) - (3)].qp);}
    break;



/* Line 1455 of yacc.c  */
#line 4129 "parse1.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 871 "parse1.y"

	/* end of grammar */

yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	Fprintf(stderr, "%s:\n ", s);
}

static int yylex() {return next_intoken(&(yylval.qp));}

#if !NRNUNIT
nrn_list(q1, q2)
	Item *q1, *q2;
{
	/*ARGSUSED*/
}
nrn_use(q1, q2, q3)
	Item *q1, *q2, *q3;
{
	/*ARGSUSED*/
}
#endif


