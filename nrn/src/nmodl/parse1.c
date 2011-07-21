
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

/* /local/src/master/nrn/src/nmodl/parse1.y,v 4.11 1999/03/24 18:34:08 hines Exp */

#include <../../nmodlconf.h>
#include "modl.h"
#include <stdlib.h>

#if defined(__STDC__)
#define sdebug(arg1,arg2) {}
#define qdebug(arg1,arg2) {}
#else
#define sdebug(arg1,arg2) {Fprintf(stderr,"arg1:%s\n", arg2); Fflush(stderr);}
#define qdebug(arg1,arg2) {Item *q; Fprintf(stderr,"arg1:");Fflush(stderr);\
	for (q=arg2; q->type != 0; q=q->next){\
		if (q->type == SYMBOL)\
			Fprintf(stderr,"%s\n", SYM(q)->name);\
		else if (q->type == STRING)\
			Fprintf(stderr,"%s\n", STR(q);\
		else\
			Fprintf(stderr,"Illegal Item type\n");\
		Fflush(stderr);}\
		Fprintf(stderr,"\n");Fflush(stderr);}
#endif

#define ldebug(arg1, arg2) qdebug(arg1, arg2->next)

#if YYBISON
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyps; --yypv; YYERROR
#endif

int brkpnt_exists;
int assert_threadsafe;
int usederivstatearray;
extern int protect_;
extern int vectorize;
extern int in_comment_; /* allow non-ascii in a COMMENT */
extern char *modelline;
extern Item* protect_astmt(Item*, Item*);
extern List* toplocal_;
static List* toplocal1_;
extern List *firstlist; /* NAME symbols in order that they appear in file */
extern int lexcontext; /* ':' can return 3 different tokens */
extern List *solveforlist; /* List of symbols that are actually to be solved
				for in a block. See in_solvefor() */
static int stateblock; /* 0 if dependent, 1 if state */
static int blocktype;
static int saw_verbatim_; /* only print the notice once */
static int inequation; /* inside an equation?*/
static int nstate;	/* number of states seen in an expression */
static int leftside;	/* inside left hand side of equation? */
static int pstate;	/* number of state in a primary expression */
static int tstate;	/* number of states in a term */
static Item *lastok;	/* last token accepted by expr */
static int sensused;	/* a SENS statement occurred in this block */
static Symbol *matchindex; /* local symbol for implied MATCH loop */
static int model_level = 0; /* the model level prepended to declaration
				blocks by merge */
static int scopindep = 0;/* SCoP independent explicitly declared if 1 */
static int extdef2 = 0; /* flag that says we are in an EXTDEF2 function */
static List *table_list = LIST0; /* table information for TABLE statement */
static int forallindex = 0;	/* 0 not in FORALL, -1 just starting, 
					>0 index of arrays used (must all
					be the same */
static Item* astmt_end_;	/* see kinetic.c vectorizing */
static int nr_argcnt_, argcnt_; /* for matching number of args in NET_RECEIVE
				 and FOR_NETCONS */


/* Line 189 of yacc.c  */
#line 146 "parse1.c"

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
     MODEL = 260,
     CONSTANT = 261,
     INDEPENDENT = 262,
     DEPENDENT = 263,
     STATE = 264,
     INITIAL1 = 265,
     DERIVATIVE = 266,
     SOLVE = 267,
     USING = 268,
     WITH = 269,
     STEPPED = 270,
     DISCRETE = 271,
     FROM = 272,
     FORALL1 = 273,
     TO = 274,
     BY = 275,
     WHILE = 276,
     IF = 277,
     ELSE = 278,
     START1 = 279,
     STEP = 280,
     SENS = 281,
     SOLVEFOR = 282,
     PROCEDURE = 283,
     PARTIAL = 284,
     DEL = 285,
     DEL2 = 286,
     DEFINE1 = 287,
     IFERROR = 288,
     PARAMETER = 289,
     DERFUNC = 290,
     EQUATION = 291,
     TERMINAL = 292,
     LINEAR = 293,
     NONLINEAR = 294,
     FUNCTION1 = 295,
     LOCAL = 296,
     METHOD = 297,
     LIN1 = 298,
     NONLIN1 = 299,
     PUTQ = 300,
     GETQ = 301,
     TABLE = 302,
     DEPEND = 303,
     BREAKPOINT = 304,
     INCLUDE1 = 305,
     FUNCTION_TABLE = 306,
     PROTECT = 307,
     NRNMUTEXLOCK = 308,
     NRNMUTEXUNLOCK = 309,
     OR = 310,
     AND = 311,
     GT = 312,
     LT = 313,
     LE = 314,
     EQ = 315,
     NE = 316,
     NOT = 317,
     NAME = 318,
     PRIME = 319,
     REAL = 320,
     INTEGER = 321,
     DEFINEDVAR = 322,
     STRING = 323,
     PLOT = 324,
     VS = 325,
     LAG = 326,
     RESET = 327,
     MATCH = 328,
     MODEL_LEVEL = 329,
     SWEEP = 330,
     FIRST = 331,
     LAST = 332,
     KINETIC = 333,
     CONSERVE = 334,
     REACTION = 335,
     REACT1 = 336,
     COMPARTMENT = 337,
     UNITS = 338,
     UNITSON = 339,
     UNITSOFF = 340,
     LONGDIFUS = 341,
     NEURON = 342,
     SUFFIX = 343,
     NONSPECIFIC = 344,
     READ = 345,
     WRITE = 346,
     USEION = 347,
     VALENCE = 348,
     THREADSAFE = 349,
     GLOBAL = 350,
     SECTION = 351,
     RANGE = 352,
     POINTER = 353,
     EXTERNAL = 354,
     BEFORE = 355,
     AFTER = 356,
     WATCH = 357,
     ELECTRODE_CURRENT = 358,
     CONSTRUCTOR = 359,
     DESTRUCTOR = 360,
     NETRECEIVE = 361,
     FOR_NETCONS = 362,
     GE = 363,
     UNARYMINUS = 364
   };
#endif
/* Tokens.  */
#define VERBATIM 258
#define COMMENT 259
#define MODEL 260
#define CONSTANT 261
#define INDEPENDENT 262
#define DEPENDENT 263
#define STATE 264
#define INITIAL1 265
#define DERIVATIVE 266
#define SOLVE 267
#define USING 268
#define WITH 269
#define STEPPED 270
#define DISCRETE 271
#define FROM 272
#define FORALL1 273
#define TO 274
#define BY 275
#define WHILE 276
#define IF 277
#define ELSE 278
#define START1 279
#define STEP 280
#define SENS 281
#define SOLVEFOR 282
#define PROCEDURE 283
#define PARTIAL 284
#define DEL 285
#define DEL2 286
#define DEFINE1 287
#define IFERROR 288
#define PARAMETER 289
#define DERFUNC 290
#define EQUATION 291
#define TERMINAL 292
#define LINEAR 293
#define NONLINEAR 294
#define FUNCTION1 295
#define LOCAL 296
#define METHOD 297
#define LIN1 298
#define NONLIN1 299
#define PUTQ 300
#define GETQ 301
#define TABLE 302
#define DEPEND 303
#define BREAKPOINT 304
#define INCLUDE1 305
#define FUNCTION_TABLE 306
#define PROTECT 307
#define NRNMUTEXLOCK 308
#define NRNMUTEXUNLOCK 309
#define OR 310
#define AND 311
#define GT 312
#define LT 313
#define LE 314
#define EQ 315
#define NE 316
#define NOT 317
#define NAME 318
#define PRIME 319
#define REAL 320
#define INTEGER 321
#define DEFINEDVAR 322
#define STRING 323
#define PLOT 324
#define VS 325
#define LAG 326
#define RESET 327
#define MATCH 328
#define MODEL_LEVEL 329
#define SWEEP 330
#define FIRST 331
#define LAST 332
#define KINETIC 333
#define CONSERVE 334
#define REACTION 335
#define REACT1 336
#define COMPARTMENT 337
#define UNITS 338
#define UNITSON 339
#define UNITSOFF 340
#define LONGDIFUS 341
#define NEURON 342
#define SUFFIX 343
#define NONSPECIFIC 344
#define READ 345
#define WRITE 346
#define USEION 347
#define VALENCE 348
#define THREADSAFE 349
#define GLOBAL 350
#define SECTION 351
#define RANGE 352
#define POINTER 353
#define EXTERNAL 354
#define BEFORE 355
#define AFTER 356
#define WATCH 357
#define ELECTRODE_CURRENT 358
#define CONSTRUCTOR 359
#define DESTRUCTOR 360
#define NETRECEIVE 361
#define FOR_NETCONS 362
#define GE 363
#define UNARYMINUS 364




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 73 "parse1.y"

	Item	*qp;
	char	*str;
	List	*lp;
	int	i;



/* Line 214 of yacc.c  */
#line 409 "parse1.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 421 "parse1.c"

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
#define YYLAST   1354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  388
/* YYNRULES -- Number of states.  */
#define YYNSTATES  762

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   125,     2,     2,
      57,    58,    63,    62,    69,    64,     2,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,     2,
       2,    66,     2,     2,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,    70,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   126
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    11,    14,    17,    20,
      21,    27,    28,    32,    35,    38,    41,    45,    48,    49,
      53,    56,    58,    60,    62,    64,    66,    68,    70,    72,
      74,    76,    81,    82,    85,    91,    95,   102,   104,   105,
     107,   108,   112,   114,   116,   117,   123,   128,   129,   132,
     137,   141,   145,   147,   149,   151,   154,   156,   158,   160,
     162,   164,   166,   171,   172,   175,   176,   181,   191,   193,
     195,   196,   202,   203,   206,   211,   219,   228,   240,   242,
     243,   246,   247,   251,   252,   258,   264,   267,   270,   275,
     276,   280,   281,   284,   285,   288,   289,   292,   293,   296,
     297,   300,   301,   304,   305,   308,   309,   312,   313,   316,
     317,   320,   321,   324,   325,   328,   329,   332,   333,   336,
     337,   340,   341,   345,   346,   350,   354,   358,   362,   363,
     367,   371,   372,   376,   379,   382,   387,   388,   392,   393,
     394,   398,   401,   403,   405,   407,   409,   412,   414,   416,
     418,   420,   422,   424,   426,   428,   430,   432,   434,   436,
     438,   440,   442,   444,   446,   448,   450,   452,   454,   455,
     459,   460,   463,   465,   469,   474,   479,   481,   486,   490,
     497,   499,   501,   505,   509,   513,   517,   521,   523,   525,
     528,   530,   534,   538,   542,   546,   550,   554,   558,   562,
     566,   570,   574,   578,   582,   586,   589,   592,   594,   596,
     598,   600,   602,   605,   609,   613,   615,   619,   623,   625,
     627,   629,   633,   635,   636,   642,   643,   645,   647,   651,
     655,   656,   667,   670,   671,   674,   675,   681,   684,   691,
     700,   701,   710,   711,   715,   720,   721,   728,   734,   739,
     744,   747,   759,   768,   776,   778,   780,   787,   788,   798,
     799,   800,   803,   806,   811,   820,   821,   829,   832,   836,
     840,   846,   849,   850,   854,   855,   857,   860,   864,   867,
     871,   875,   879,   883,   887,   891,   893,   896,   900,   903,
     910,   912,   914,   915,   923,   926,   928,   931,   933,   937,
     941,   945,   949,   953,   957,   960,   962,   965,   968,   970,
     974,   975,   981,   984,   985,   994,  1000,  1001,  1010,  1016,
    1018,  1021,  1027,  1028,  1039,  1047,  1055,  1058,  1060,  1063,
    1067,  1072,  1077,  1080,  1083,  1086,  1087,  1093,  1095,  1098,
    1100,  1107,  1109,  1111,  1116,  1121,  1122,  1125,  1128,  1132,
    1135,  1140,  1145,  1152,  1154,  1159,  1160,  1166,  1176,  1179,
    1180,  1182,  1184,  1188,  1189,  1192,  1197,  1198,  1202,  1205,
    1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1243,  1249,
    1257,  1260,  1262,  1266,  1268,  1269,  1271,  1272,  1275
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     128,     0,    -1,   129,    -1,     1,    -1,    -1,   129,   132,
      -1,   129,   193,    -1,   129,   134,    -1,   129,   136,    -1,
      -1,   129,    90,    82,   130,   136,    -1,    -1,   129,   131,
     170,    -1,   129,     3,    -1,   129,     4,    -1,   129,   143,
      -1,   129,    50,    84,    -1,     5,   133,    -1,    -1,    32,
      79,    82,    -1,    32,     1,    -1,    79,    -1,   137,    -1,
     154,    -1,   159,    -1,   165,    -1,   145,    -1,   167,    -1,
     286,    -1,   276,    -1,   280,    -1,    34,    55,   138,    56,
      -1,    -1,   138,   139,    -1,    79,    66,   150,   140,   144,
      -1,    79,   140,   144,    -1,    79,    59,   152,    60,   140,
     144,    -1,     1,    -1,    -1,   141,    -1,    -1,    57,   142,
      58,    -1,   100,    -1,   101,    -1,    -1,    74,   153,    69,
     153,    73,    -1,    15,    55,   146,    56,    -1,    -1,   146,
     147,    -1,    79,    66,   148,   140,    -1,   150,    69,   150,
      -1,   148,    69,   150,    -1,   135,    -1,    80,    -1,   151,
      -1,    64,   151,    -1,   152,    -1,    81,    -1,    82,    -1,
      83,    -1,    81,    -1,   152,    -1,     7,    55,   155,    56,
      -1,    -1,   155,   157,    -1,    -1,   155,    91,   156,   157,
      -1,    79,    17,   150,    19,   150,   158,   152,   163,   140,
      -1,     1,    -1,    14,    -1,    -1,     8,   160,    55,   161,
      56,    -1,    -1,   161,   162,    -1,   149,   163,   140,   164,
      -1,   149,    59,   152,    60,   163,   140,   164,    -1,   149,
      17,   150,    19,   150,   163,   140,   164,    -1,   149,    59,
     152,    60,    17,   150,    19,   150,   163,   140,   164,    -1,
       1,    -1,    -1,    24,   150,    -1,    -1,    74,   153,    73,
      -1,    -1,     9,   166,    55,   161,    56,    -1,    85,   168,
      86,   149,   169,    -1,    85,     1,    -1,   149,   169,    -1,
     168,    69,   149,   169,    -1,    -1,    59,    82,    60,    -1,
      -1,   171,   188,    -1,    -1,   172,   225,    -1,    -1,   173,
     247,    -1,    -1,   174,   226,    -1,    -1,   175,   228,    -1,
      -1,   176,   234,    -1,    -1,   177,   239,    -1,    -1,   178,
     240,    -1,    -1,   179,   248,    -1,    -1,   180,   229,    -1,
      -1,   181,   230,    -1,    -1,   182,   265,    -1,    -1,   183,
     189,    -1,    -1,   184,   190,    -1,    -1,   185,   233,    -1,
      -1,   186,   116,   249,    -1,    -1,   187,   117,   249,    -1,
      10,   191,    56,    -1,   120,   191,    56,    -1,   121,   191,
      56,    -1,    -1,    55,   192,   197,    -1,    55,   193,   197,
      -1,    -1,    41,   194,   195,    -1,    41,     1,    -1,    79,
     196,    -1,   195,    69,    79,   196,    -1,    -1,    59,   152,
      60,    -1,    -1,    -1,   197,   198,   199,    -1,   197,   200,
      -1,   216,    -1,   219,    -1,   221,    -1,   222,    -1,   191,
      56,    -1,   243,    -1,     3,    -1,     4,    -1,   256,    -1,
     260,    -1,   262,    -1,   258,    -1,   269,    -1,   270,    -1,
      88,    -1,   271,    -1,   231,    -1,   282,    -1,   143,    -1,
     242,    -1,   250,    -1,   253,    -1,    53,    -1,    54,    -1,
       1,    -1,   203,    -1,    -1,    52,   201,   203,    -1,    -1,
     202,   266,    -1,   213,    -1,   204,    66,   206,    -1,   207,
     206,    66,   206,    -1,   208,   209,    66,   210,    -1,   149,
      -1,   149,    59,   205,    60,    -1,    79,    61,   152,    -1,
      79,    61,   152,    59,   205,    60,    -1,   135,    -1,   152,
      -1,    57,   205,    58,    -1,   205,    62,   205,    -1,   205,
      64,   205,    -1,   205,    63,   205,    -1,   205,    65,   205,
      -1,     1,    -1,   204,    -1,   153,   140,    -1,   213,    -1,
      57,   206,    58,    -1,   206,    62,   206,    -1,   206,    64,
     206,    -1,   206,    63,   206,    -1,   206,    65,   206,    -1,
     206,    67,   206,    -1,   206,    71,   206,    -1,   206,    72,
     206,    -1,   206,    73,   206,    -1,   206,    74,   206,    -1,
     206,   124,   206,    -1,   206,    75,   206,    -1,   206,    76,
     206,    -1,   206,    77,   206,    -1,    78,   206,    -1,    64,
     206,    -1,     1,    -1,    44,    -1,    43,    -1,   210,    -1,
     211,    -1,    64,   211,    -1,   210,    62,   211,    -1,   210,
      64,   211,    -1,   212,    -1,   211,    63,   212,    -1,   211,
      65,   212,    -1,   204,    -1,   153,    -1,   213,    -1,    57,
     206,    58,    -1,     1,    -1,    -1,    79,    57,   214,   215,
      58,    -1,    -1,   206,    -1,    84,    -1,   215,    69,   206,
      -1,   215,    69,    84,    -1,    -1,    17,    79,   217,    66,
     205,    19,   205,   218,   191,    56,    -1,    17,     1,    -1,
      -1,    20,   205,    -1,    -1,    18,    79,   220,   191,    56,
      -1,    18,     1,    -1,    21,    57,   206,    58,   191,    56,
      -1,    22,    57,   206,    58,   191,    56,   223,   224,    -1,
      -1,   223,    23,    22,    57,   206,    58,   191,    56,    -1,
      -1,    23,   191,    56,    -1,    11,    79,   191,    56,    -1,
      -1,    38,    79,   245,   227,   191,    56,    -1,    39,    79,
     245,   191,    56,    -1,    16,    79,   191,    56,    -1,    29,
      79,   191,    56,    -1,    29,     1,    -1,    70,    80,    66,
      79,    63,    31,    57,    79,    58,    62,    79,    -1,    70,
      30,    79,    59,   232,    60,    66,   206,    -1,    70,    79,
      59,   232,    60,    66,   206,    -1,    92,    -1,    93,    -1,
      51,    79,    57,   236,    58,   140,    -1,    -1,    40,    79,
      57,   236,    58,   140,   235,   191,    56,    -1,    -1,    -1,
     237,   238,    -1,   149,   140,    -1,   238,    69,   149,   140,
      -1,    28,    79,    57,   236,    58,   140,   191,    56,    -1,
      -1,   122,    57,   236,    58,   241,   191,    56,    -1,   122,
       1,    -1,    10,   191,    56,    -1,    12,    79,   244,    -1,
      12,    79,    13,    42,   244,    -1,    12,     1,    -1,    -1,
      33,   191,    56,    -1,    -1,   246,    -1,    27,    79,    -1,
     246,    69,    79,    -1,    27,     1,    -1,    49,   191,    56,
      -1,    37,   191,    56,    -1,    49,   191,    56,    -1,    12,
     191,    56,    -1,    10,   191,    56,    -1,    25,   191,    56,
      -1,     1,    -1,   118,   251,    -1,   250,    69,   251,    -1,
     118,     1,    -1,    57,   255,   252,   255,    58,   153,    -1,
      73,    -1,    74,    -1,    -1,   123,    57,   236,    58,   254,
     191,    56,    -1,   123,     1,    -1,   204,    -1,   153,   140,
      -1,   213,    -1,    57,   255,    58,    -1,   255,    62,   255,
      -1,   255,    64,   255,    -1,   255,    63,   255,    -1,   255,
      65,   255,    -1,   255,    67,   255,    -1,    64,   255,    -1,
       1,    -1,    26,   257,    -1,    26,     1,    -1,   204,    -1,
     257,    69,   204,    -1,    -1,    95,   259,   268,    66,   206,
      -1,    95,     1,    -1,    -1,    98,    79,    69,   261,   206,
      55,   264,    56,    -1,    98,   206,    55,   264,    56,    -1,
      -1,   102,    79,    69,   263,   206,    55,   264,    56,    -1,
     102,   206,    55,   264,    56,    -1,    79,    -1,   264,    79,
      -1,    94,    79,   245,   191,    56,    -1,    -1,    96,   268,
      97,   267,   268,    57,   206,    69,   206,    58,    -1,    96,
     268,    74,    74,    57,   206,    58,    -1,    96,   268,    64,
      73,    57,   206,    58,    -1,    96,     1,    -1,   204,    -1,
     152,   204,    -1,   268,    62,   204,    -1,   268,    62,   152,
     204,    -1,    87,   149,    20,    79,    -1,    87,     1,    -1,
      45,   149,    -1,    46,   149,    -1,    -1,    89,   272,    55,
     273,    56,    -1,   274,    -1,   273,   274,    -1,   149,    -1,
     275,    57,   206,    58,    66,   206,    -1,     1,    -1,   149,
      -1,   149,    59,    79,    60,    -1,    99,    55,   277,    56,
      -1,    -1,   277,   278,    -1,   277,   279,    -1,   141,    66,
     141,    -1,   141,     1,    -1,    79,    66,   153,   141,    -1,
      79,    66,   141,   141,    -1,    79,    66,   141,    64,    73,
     141,    -1,     1,    -1,     6,    55,   281,    56,    -1,    -1,
     281,    79,    66,   150,   140,    -1,    47,   283,   285,    17,
     206,    19,   206,    14,    82,    -1,    47,     1,    -1,    -1,
     284,    -1,   135,    -1,   284,    69,   135,    -1,    -1,    48,
     284,    -1,   103,    55,   287,    56,    -1,    -1,   287,   104,
      79,    -1,   287,   288,    -1,   287,   105,   289,    -1,   287,
     119,   289,    -1,   287,   112,   289,    -1,   287,   113,   289,
      -1,   287,   111,   289,    -1,   287,   114,   289,    -1,   287,
     115,   289,    -1,   287,   110,   290,    -1,   108,    79,   106,
     289,   291,    -1,   108,    79,   107,   289,   291,    -1,   108,
      79,   106,   289,   107,   289,   291,    -1,   108,     1,    -1,
      79,    -1,   289,    69,    79,    -1,     1,    -1,    -1,   289,
      -1,    -1,   109,   153,    -1,   109,    64,   153,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   129,   131,   132,   133,   146,   147,   148,
     148,   151,   150,   156,   165,   172,   173,   176,   180,   182,
     191,   193,   199,   199,   199,   199,   199,   200,   200,   200,
     200,   202,   204,   205,   209,   213,   215,   220,   222,   223,
     225,   225,   229,   230,   233,   234,   240,   242,   243,   246,
     250,   251,   253,   254,   256,   257,   264,   264,   266,   267,
     269,   270,   276,   278,   279,   281,   281,   286,   291,   293,
     295,   295,   297,   298,   301,   305,   311,   315,   321,   325,
     326,   329,   330,   335,   335,   337,   342,   344,   352,   356,
     357,   360,   360,   362,   362,   363,   363,   364,   364,   365,
     365,   366,   366,   367,   367,   368,   368,   369,   369,   370,
     370,   371,   371,   372,   372,   373,   373,   374,   374,   375,
     375,   376,   376,   377,   377,   379,   382,   385,   388,   388,
     389,   393,   392,   401,   403,   418,   433,   434,   437,   438,
     438,   440,   442,   443,   444,   445,   446,   447,   448,   458,
     460,   461,   462,   463,   464,   465,   466,   468,   469,   470,
     474,   475,   476,   477,   478,   479,   480,   483,   486,   486,
     490,   490,   493,   497,   517,   526,   533,   548,   571,   574,
     578,   586,   587,   588,   589,   590,   591,   592,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   617,   619,
     624,   626,   629,   632,   635,   639,   645,   651,   657,   658,
     659,   661,   664,   669,   668,   686,   687,   688,   689,   690,
     692,   692,   715,   718,   719,   721,   721,   740,   743,   745,
     747,   748,   755,   756,   763,   767,   767,   773,   779,   783,
     788,   792,   794,   796,   799,   799,   801,   828,   827,   855,
     856,   856,   858,   862,   867,   885,   884,   902,   904,   912,
     915,   917,   920,   921,   925,   929,   931,   935,   937,   939,
     943,   946,   948,   950,   952,   954,   956,   958,   960,   962,
     965,   966,   968,   968,   978,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   991,   992,   995,  1000,  1002,  1005,
    1009,  1009,  1013,  1016,  1015,  1019,  1023,  1022,  1026,  1029,
    1030,  1032,  1039,  1039,  1041,  1043,  1045,  1047,  1048,  1049,
    1050,  1052,  1054,  1056,  1057,  1059,  1059,  1062,  1063,  1065,
    1067,  1074,  1078,  1080,  1085,  1089,  1090,  1091,  1093,  1095,
    1097,  1103,  1113,  1122,  1128,  1130,  1131,  1138,  1153,  1156,
    1157,  1159,  1161,  1165,  1166,  1169,  1172,  1173,  1175,  1176,
    1178,  1180,  1182,  1184,  1186,  1188,  1190,  1193,  1195,  1197,
    1199,  1202,  1203,  1205,  1209,  1210,  1213,  1214,  1216
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VERBATIM", "COMMENT", "MODEL",
  "CONSTANT", "INDEPENDENT", "DEPENDENT", "STATE", "INITIAL1",
  "DERIVATIVE", "SOLVE", "USING", "WITH", "STEPPED", "DISCRETE", "FROM",
  "FORALL1", "TO", "BY", "WHILE", "IF", "ELSE", "START1", "STEP", "SENS",
  "SOLVEFOR", "PROCEDURE", "PARTIAL", "DEL", "DEL2", "DEFINE1", "IFERROR",
  "PARAMETER", "DERFUNC", "EQUATION", "TERMINAL", "LINEAR", "NONLINEAR",
  "FUNCTION1", "LOCAL", "METHOD", "LIN1", "NONLIN1", "PUTQ", "GETQ",
  "TABLE", "DEPEND", "BREAKPOINT", "INCLUDE1", "FUNCTION_TABLE", "PROTECT",
  "NRNMUTEXLOCK", "NRNMUTEXUNLOCK", "'{'", "'}'", "'('", "')'", "'['",
  "']'", "'@'", "'+'", "'*'", "'-'", "'/'", "'='", "'^'", "':'", "','",
  "'~'", "OR", "AND", "GT", "LT", "LE", "EQ", "NE", "NOT", "NAME", "PRIME",
  "REAL", "INTEGER", "DEFINEDVAR", "STRING", "PLOT", "VS", "LAG", "RESET",
  "MATCH", "MODEL_LEVEL", "SWEEP", "FIRST", "LAST", "KINETIC", "CONSERVE",
  "REACTION", "REACT1", "COMPARTMENT", "UNITS", "UNITSON", "UNITSOFF",
  "LONGDIFUS", "NEURON", "SUFFIX", "NONSPECIFIC", "READ", "WRITE",
  "USEION", "VALENCE", "THREADSAFE", "GLOBAL", "SECTION", "RANGE",
  "POINTER", "EXTERNAL", "BEFORE", "AFTER", "WATCH", "ELECTRODE_CURRENT",
  "CONSTRUCTOR", "DESTRUCTOR", "NETRECEIVE", "FOR_NETCONS", "GE", "'%'",
  "UNARYMINUS", "$accept", "top", "all", "$@1", "$@2", "model", "line",
  "define1", "Name", "declare", "parmblk", "parmbody", "parmasgn", "units",
  "unit", "@3", "uniton", "limits", "stepblk", "stepbdy", "stepped",
  "numlist", "name", "number", "NUMBER", "integer", "real", "indepblk",
  "indepbody", "$@4", "indepdef", "withby", "depblk", "$@5", "depbody",
  "depdef", "opstart", "abstol", "stateblk", "$@6", "plotdecl", "pvlist",
  "optindex", "proc", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "$@23", "initblk", "constructblk", "destructblk", "stmtlist", "$@24",
  "locallist", "$@25", "locallist1", "locoptarray", "stmtlist1", "$@26",
  "ostmt", "astmt", "$@27", "$@28", "asgn", "varname", "intexpr", "expr",
  "nonlineqn", "lineqn", "leftlinexpr", "linexpr", "primary", "term",
  "funccall", "$@29", "exprlist", "fromstmt", "$@30", "opinc",
  "forallstmt", "$@31", "whilestmt", "ifstmt", "optelseif", "optelse",
  "derivblk", "linblk", "$@32", "nonlinblk", "discretblk", "partialblk",
  "pareqn", "firstlast", "functableblk", "funcblk", "$@33", "arglist",
  "$@34", "arglist1", "procedblk", "netrecblk", "$@35", "initstmt",
  "solveblk", "ifsolerr", "solvefor", "solvefor1", "brkptblk",
  "terminalblk", "bablk", "watchstmt", "watch1", "watchdir", "fornetcon",
  "$@36", "aexpr", "sens", "senslist", "conserve", "$@37", "compart",
  "$@38", "ldifus", "$@39", "namelist", "kineticblk", "reaction", "$@40",
  "react", "lagstmt", "queuestmt", "matchblk", "$@41", "matchlist",
  "match", "matchname", "unitblk", "unitbody", "unitdef", "factordef",
  "constblk", "conststmt", "tablestmt", "tablst", "tablst1", "dependlst",
  "neuronblk", "nrnstmt", "nrnuse", "nrnlist", "optnrnlist", "valence", 0
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
     305,   306,   307,   308,   309,   123,   125,    40,    41,    91,
      93,    64,    43,    42,    45,    47,    61,    94,    58,    44,
     126,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    37,   364
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   127,   128,   128,   129,   129,   129,   129,   129,   130,
     129,   131,   129,   129,   129,   129,   129,   132,   133,   134,
     134,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   138,   138,   139,   139,   139,   139,   140,   140,
     142,   141,   143,   143,   144,   144,   145,   146,   146,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   155,   155,   156,   155,   157,   157,   158,
     160,   159,   161,   161,   162,   162,   162,   162,   162,   163,
     163,   164,   164,   166,   165,   167,   167,   168,   168,   169,
     169,   171,   170,   172,   170,   173,   170,   174,   170,   175,
     170,   176,   170,   177,   170,   178,   170,   179,   170,   180,
     170,   181,   170,   182,   170,   183,   170,   184,   170,   185,
     170,   186,   170,   187,   170,   188,   189,   190,   192,   191,
     191,   194,   193,   193,   195,   195,   196,   196,   197,   198,
     197,   197,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   200,   201,   200,
     202,   200,   200,   203,   203,   203,   204,   204,   204,   204,
     205,   205,   205,   205,   205,   205,   205,   205,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   207,   208,
     209,   210,   210,   210,   210,   211,   211,   211,   212,   212,
     212,   212,   212,   214,   213,   215,   215,   215,   215,   215,
     217,   216,   216,   218,   218,   220,   219,   219,   221,   222,
     223,   223,   224,   224,   225,   227,   226,   228,   229,   230,
     230,   231,   231,   231,   232,   232,   233,   235,   234,   236,
     237,   236,   238,   238,   239,   241,   240,   240,   242,   243,
     243,   243,   244,   244,   245,   245,   246,   246,   246,   247,
     248,   249,   249,   249,   249,   249,   250,   250,   250,   251,
     252,   252,   254,   253,   253,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   256,   256,   257,   257,
     259,   258,   258,   261,   260,   260,   263,   262,   262,   264,
     264,   265,   267,   266,   266,   266,   266,   268,   268,   268,
     268,   269,   269,   270,   270,   272,   271,   273,   273,   274,
     274,   274,   275,   275,   276,   277,   277,   277,   278,   278,
     279,   279,   279,   279,   280,   281,   281,   282,   282,   283,
     283,   284,   284,   285,   285,   286,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   288,   288,   288,
     288,   289,   289,   289,   290,   290,   291,   291,   291
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     2,     2,     0,
       5,     0,     3,     2,     2,     2,     3,     2,     0,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     2,     5,     3,     6,     1,     0,     1,
       0,     3,     1,     1,     0,     5,     4,     0,     2,     4,
       3,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     4,     0,     2,     0,     4,     9,     1,     1,
       0,     5,     0,     2,     4,     7,     8,    11,     1,     0,
       2,     0,     3,     0,     5,     5,     2,     2,     4,     0,
       3,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     3,     0,     3,     3,     3,     3,     0,     3,
       3,     0,     3,     2,     2,     4,     0,     3,     0,     0,
       3,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     2,     1,     3,     4,     4,     1,     4,     3,     6,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     2,     3,     3,     1,     3,     3,     1,     1,
       1,     3,     1,     0,     5,     0,     1,     1,     3,     3,
       0,    10,     2,     0,     2,     0,     5,     2,     6,     8,
       0,     8,     0,     3,     4,     0,     6,     5,     4,     4,
       2,    11,     8,     7,     1,     1,     6,     0,     9,     0,
       0,     2,     2,     4,     8,     0,     7,     2,     3,     3,
       5,     2,     0,     3,     0,     1,     2,     3,     2,     3,
       3,     3,     3,     3,     3,     1,     2,     3,     2,     6,
       1,     1,     0,     7,     2,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     2,     2,     1,     3,
       0,     5,     2,     0,     8,     5,     0,     8,     5,     1,
       2,     5,     0,    10,     7,     7,     2,     1,     2,     3,
       4,     4,     2,     2,     2,     0,     5,     1,     2,     1,
       6,     1,     1,     4,     4,     0,     2,     2,     3,     2,
       4,     4,     6,     1,     4,     0,     5,     9,     2,     0,
       1,     1,     3,     0,     2,     4,     0,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     5,     7,
       2,     1,     3,     1,     0,     1,     0,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,    11,     1,    13,    14,    18,     0,     0,
      70,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,    91,     5,     7,     8,    22,    15,    26,
      23,    24,    25,    27,     6,    29,    30,    28,    17,   355,
      63,     0,     0,    47,    20,     0,    32,   133,     0,    16,
      86,    21,    53,    52,    89,     0,     9,   345,   366,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      72,     0,    19,     0,   136,   132,     0,    87,     0,     0,
       0,     0,     0,     0,    92,     0,    94,     0,    96,     0,
      98,     0,   100,     0,   102,     0,   104,     0,   106,     0,
     108,     0,   110,     0,   112,     0,   114,     0,   116,     0,
     118,     0,   120,     0,     0,   354,     0,    68,    62,     0,
      65,    64,     0,     0,    46,     0,    48,    37,    31,    38,
      33,     0,   134,     0,     0,    89,    89,    10,   353,   344,
      40,     0,     0,   346,   347,   365,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,   128,     0,     0,
       0,   274,   274,     0,     0,   267,   260,     0,     0,   250,
       0,   274,     0,     0,     0,   285,     0,     0,     0,     0,
     122,   124,     0,     0,     0,    78,    71,    79,    73,    84,
       0,     0,     0,    44,    39,    58,    59,     0,   136,    90,
      88,    85,     0,     0,   349,     0,   367,   383,   381,   369,
     380,     0,   385,   376,   373,   371,   372,   374,   375,   370,
     138,   138,   125,     0,   279,     0,   245,   275,     0,   260,
     260,     0,     0,   280,     0,     0,     0,   126,   127,   260,
       0,     0,     0,     0,     0,    57,    38,    54,    56,     0,
      66,     0,     0,     0,    38,    38,     0,     0,    38,     0,
      35,   137,   135,    41,    60,     0,    61,     0,   348,     0,
       0,     0,   139,   139,   244,   278,   276,     0,     0,     0,
       0,     0,   265,    38,   261,   248,   249,     0,     0,   283,
     282,   284,   281,    55,   356,     0,     0,    80,     0,    81,
       0,    49,     0,    38,    44,     0,     0,   351,   350,   382,
     386,   386,   209,   208,   168,    21,   176,     0,   141,     0,
     167,     0,     0,     0,   172,     0,   277,   247,    38,    38,
       0,   262,     0,   321,    38,     0,     0,    79,     0,    74,
      51,    50,    44,    34,     0,     0,     0,     0,   377,   378,
       0,   223,     0,     0,   166,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   165,     0,
       0,   156,   335,     0,     0,     0,     0,     0,   160,     0,
     140,   142,   143,   144,   145,   158,   161,   147,   162,   163,
     150,   153,   151,   152,   154,   155,   157,   159,     0,   171,
       0,   207,     0,     0,     0,    38,   188,     0,   190,   222,
       0,     0,   219,   218,     0,   210,   211,   215,   220,   246,
     257,     0,     0,    38,   256,    69,     0,    79,     0,    38,
       0,    36,     0,   352,   386,     0,   387,    21,   169,     0,
     178,   187,     0,   180,   181,     0,     0,   271,   272,   232,
     230,   237,   235,     0,     0,   307,   308,   306,   333,   334,
     358,   361,   363,   360,     0,     0,     0,   332,     0,     0,
     312,     0,    21,     0,    21,     0,   288,     0,   286,   294,
     260,   146,     0,   326,     0,   327,     0,   173,     0,   206,
     205,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,     0,     0,
       0,     0,     0,     0,     0,   266,   263,    79,    38,     0,
      81,    82,    45,   379,   388,   227,   226,     0,     0,     0,
     177,     0,     0,     0,     0,   268,     0,     0,   269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,   316,     0,   305,     0,     0,
      38,   295,   297,     0,     0,   287,   328,     0,     0,     0,
     322,   191,   192,   194,   193,   195,   174,   196,   197,   198,
     199,   200,   202,   203,   204,   201,   221,   175,   213,   214,
     216,   217,     0,   264,    38,    81,     0,    75,   224,     0,
       0,   182,   183,   185,   184,   186,   272,     0,     0,     0,
       0,     0,   309,   364,     0,   362,     0,   254,   255,     0,
       0,   331,   341,   339,     0,   337,     0,     0,     0,   319,
       0,     0,     0,     0,   304,   296,     0,     0,     0,     0,
       0,   290,   291,     0,   292,     0,   329,     0,     0,     0,
     258,    67,    76,    79,   229,   228,   179,   270,   273,     0,
     236,     0,     0,     0,     0,     0,     0,     0,   336,   338,
       0,   311,     0,   315,   320,     0,   318,   298,   299,   301,
     300,   302,   303,     0,     0,   330,     0,     0,     0,    38,
       0,   238,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,   233,   242,     0,
       0,   253,     0,   343,     0,     0,     0,   289,   293,   325,
     324,     0,    77,     0,     0,     0,   239,     0,   252,     0,
       0,   314,   317,     0,   234,     0,     0,     0,   357,     0,
     340,     0,   231,     0,   243,     0,   323,     0,   251,     0,
       0,   241
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,    23,    24,    38,    25,    53,    26,
      27,    83,   140,   203,   204,   212,    28,   270,    29,    81,
     136,   265,   326,   256,   257,   276,   415,    30,    78,   194,
     131,   436,    31,    41,   132,   198,   264,   349,    32,    42,
      33,    55,    87,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    94,   118,   120,   168,   230,    34,    48,    85,   142,
     282,   327,   390,   328,   360,   329,   330,   416,   455,   417,
     332,   333,   424,   425,   426,   427,   418,   449,   537,   391,
     549,   734,   392,   550,   393,   394,   718,   736,    96,   100,
     287,   102,   112,   114,   395,   629,   122,   104,   523,   241,
     242,   294,   106,   108,   340,   396,   397,   548,   236,   237,
      98,   110,   190,   398,   488,   653,   399,   694,   573,   400,
     467,   401,   481,   402,   638,   403,   641,   640,   116,   409,
     659,   496,   404,   405,   406,   479,   634,   635,   636,    35,
      91,   153,   154,    36,    77,   407,   472,   473,   555,    37,
      92,   166,   219,   223,   358
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -554
static const yytype_int16 yypact[] =
{
     648,  -554,   105,   771,  -554,  -554,  -554,  -554,   -23,    -8,
    -554,  -554,    79,    17,    85,    65,    75,    45,    80,   116,
    -554,  -554,   132,   469,  -554,  -554,  -554,  -554,  -554,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,
    -554,   171,   177,  -554,  -554,    86,  -554,  -554,   184,  -554,
    -554,  -554,  -554,  -554,   195,   -35,  -554,  -554,  -554,  -554,
     256,   276,   257,   315,   332,   337,   356,   272,   379,   411,
     417,   378,   355,   381,   463,   410,   405,   -39,    54,  -554,
    -554,   -11,  -554,   165,   482,   476,   471,  -554,   101,   101,
     348,   287,  1098,   499,  -554,   477,  -554,   499,  -554,   483,
    -554,   486,  -554,   487,  -554,   491,  -554,    10,  -554,   499,
    -554,   500,  -554,    69,  -554,   503,  -554,   499,  -554,   499,
    -554,   522,  -554,   385,   385,  -554,   542,  -554,  -554,   592,
    -554,  -554,    32,   149,  -554,   544,  -554,  -554,  -554,   395,
    -554,   190,  -554,   541,   552,   195,   195,  -554,  -554,  -554,
    -554,   555,     5,  -554,  -554,  -554,   557,    74,   162,   203,
      74,    74,    74,    74,    74,    74,  -554,   599,   585,   499,
     588,   615,   615,   589,   590,  -554,   602,   605,   499,  -554,
     499,   615,   622,   623,   614,  -554,   499,   499,   499,   499,
    -554,  -554,   324,   324,   185,  -554,  -554,    19,  -554,  -554,
     324,   190,   324,   607,  -554,  -554,  -554,   624,   482,  -554,
    -554,  -554,   625,   196,  -554,   637,  -554,  -554,  -554,   631,
    -554,   186,   631,  -554,   631,   631,   631,   631,   631,   631,
    -554,  -554,  -554,   647,  -554,   266,  -554,   635,   499,   602,
     602,   657,   101,  -554,   650,   674,   499,  -554,  -554,   602,
     675,   676,   684,   685,   386,  -554,   637,  -554,  -554,   686,
    -554,   324,   324,   190,   637,    63,   659,   683,   637,   406,
    -554,  -554,  -554,  -554,  -554,    23,  -554,   637,  -554,   671,
      74,    74,   421,   515,  -554,  -554,  -554,   499,   673,   697,
     696,   698,  -554,   637,   690,  -554,  -554,   699,   702,  -554,
    -554,  -554,  -554,  -554,  -554,   324,   743,  -554,   703,   693,
     324,  -554,   324,   637,   607,   712,   710,  -554,  -554,  -554,
     367,   -40,  -554,  -554,  -554,   248,   713,   792,  -554,   688,
    -554,   716,   524,   586,  -554,   729,  -554,  -554,   637,   637,
     499,  -554,   101,  -554,   637,   780,   324,    89,   406,  -554,
    -554,  -554,   607,  -554,   406,   637,    74,   446,  -554,  -554,
     241,  -554,   190,    94,  -554,  -554,  -554,   499,   273,   285,
     289,   740,   741,    47,   101,   101,    37,  -554,  -554,   215,
      81,  -554,  -554,   129,   535,   709,    20,    29,  -554,   745,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,   730,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,   178,  -554,
     524,  -554,   524,   524,   524,   637,  -554,  1158,  -554,  -554,
     524,   118,  -554,  -554,   742,   275,   277,  -554,  -554,  -554,
    -554,   499,   750,   637,  -554,  -554,   190,   783,   324,   637,
     738,  -554,   746,  -554,   -40,   406,  -554,   754,  -554,   638,
     761,  -554,    94,  -554,  -554,   610,   768,  -554,    26,  -554,
    -554,  -554,  -554,   524,   524,  -554,  -554,   763,  -554,  -554,
    -554,  -554,   782,   765,   757,   774,   775,  -554,   822,   788,
    -554,   433,   442,   849,   478,   872,  -554,   644,  -554,  -554,
     602,  -554,   801,  -554,   245,  -554,   284,  1194,   949,   797,
     797,  -554,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   969,   277,   586,   118,
     118,   118,   118,   499,   803,  -554,  -554,   783,   637,   846,
     693,  -554,  -554,  -554,  -554,  -554,  1194,   -32,    94,   786,
    -554,    94,    94,    94,    94,  -554,   824,   499,  -554,   802,
     499,   989,  1012,   245,   796,   850,   796,   810,   307,   798,
     799,   145,   314,  -554,   804,  -554,   804,  -554,   644,   644,
     637,  -554,  -554,   672,   818,  -554,  -554,   433,   809,   811,
    -554,  -554,   513,   797,   513,   797,  1194,   797,  1211,  1230,
     790,   790,   790,   790,   790,   790,  -554,   275,   277,   277,
    -554,  -554,   828,  -554,   637,   693,   324,  -554,  -554,   361,
     649,  -554,   354,  -554,   354,  -554,   853,   832,    94,   833,
     499,   499,  -554,   765,   524,  -554,   307,  -554,  -554,   831,
     834,  -554,  -554,   485,   154,  -554,   838,   524,   524,  -554,
     113,   524,   157,   510,   829,  -554,   644,   644,   644,   644,
     644,  -554,  -554,   644,  -554,   245,  -554,   841,   842,   433,
    -554,  -554,  -554,   783,  -554,  1194,  -554,  -554,  -554,   328,
    -554,   844,   845,   419,   843,   836,   874,   827,  -554,  -554,
     524,  1194,   895,  -554,  -554,   926,  -554,  -554,   533,   829,
     533,   829,   829,   764,   499,  -554,   524,   524,   219,   637,
      94,  -554,  -554,   524,   851,   524,   852,   847,  1032,   804,
     804,   406,   862,  1052,  1075,   524,   693,   350,   885,   175,
     524,  1194,   840,  -554,   863,   270,   282,  -554,  -554,  -554,
    -554,  1178,  -554,    94,   499,    -6,  -554,   848,  1194,   870,
     524,  -554,  -554,   524,   628,   875,   876,   882,  -554,   878,
    1194,  1095,  -554,   524,  -554,   873,  -554,  1115,  -554,   499,
     886,  -554
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -169,   861,
    -554,  -554,  -554,  -237,   -84,  -554,   626,  -289,  -554,  -554,
    -554,  -554,   -15,  -158,   678,  -140,  -190,  -554,  -554,  -554,
     747,  -554,  -554,  -554,   881,  -554,  -344,  -521,  -554,  -554,
    -554,  -554,   263,  -554,  -554,  -554,  -554,  -554,  -554,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,
    -554,  -554,  -554,  -554,   -97,  -554,   787,  -554,  -554,   748,
     724,  -554,  -554,  -554,  -554,  -554,   603,   -98,  -444,   120,
    -554,  -554,  -554,   447,  -411,    16,  -218,  -554,  -554,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,
    -554,  -554,  -554,  -554,  -554,   338,  -554,  -554,  -554,  -225,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,   358,  -131,  -554,
    -554,  -554,   854,  -554,   484,  -554,  -554,  -554,  -511,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,  -553,  -554,  -554,
    -554,  -477,  -554,  -554,  -554,  -554,  -554,   341,  -554,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,  -554,   423,  -554,  -554,
    -554,  -554,    55,  -554,  -316
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -385
static const yytype_int16 yytable[] =
{
     170,   207,    54,   439,   562,   359,   214,   152,   539,   607,
     517,   175,   177,   642,   290,   291,   746,   125,    44,   304,
     182,   486,   183,   277,   298,   353,   608,   309,   311,   279,
     489,   314,    39,   195,    88,   259,   261,   609,   470,   546,
     126,   238,   266,   262,   268,   134,    50,    40,   465,   167,
     246,    89,   258,   258,  -359,   127,   341,   643,   644,   547,
     258,   267,   258,   441,   334,   334,    47,   176,   135,   357,
     179,   215,   233,   145,   146,   217,   352,   487,   263,   315,
     150,   244,   477,   245,   662,  -359,   490,   316,   196,   250,
     251,   252,   253,   528,   610,   451,    45,   612,   613,   614,
     615,   430,   431,   306,   307,     4,   438,   434,   598,   599,
     128,    51,    52,   262,   258,   428,    51,   197,   197,   419,
     150,   258,   258,   308,    51,    52,   447,    52,   533,   275,
     480,   278,   310,   129,    43,   688,   689,   690,   691,   692,
      46,   289,   693,   422,  -131,   130,   632,   345,   180,   297,
     195,   452,   350,   218,   351,   632,   725,   726,   440,    49,
      51,    52,    56,   220,   442,   258,   137,   446,    82,   683,
     258,    57,   258,    51,   669,   420,   205,   206,   501,   493,
      51,    52,   698,   604,   331,   331,   127,    58,   437,   737,
     335,   317,   684,   318,   453,   732,   526,   325,    52,   274,
     205,   206,   530,   428,   217,   199,   258,   471,  -310,  -310,
     678,  -310,  -310,   686,   222,   224,   225,   226,   227,   228,
     229,   138,   450,   454,    51,    52,    79,   293,    51,    52,
     389,   422,    80,    51,    52,   423,   684,   502,   503,   504,
     505,   221,   507,   432,   139,   474,   508,   509,   510,   511,
     512,   513,   514,   150,    86,   534,   717,   447,    52,  -384,
     205,   206,   331,    84,   129,   574,    93,   285,   494,   572,
     456,   443,   205,   206,   457,   466,   715,   274,   205,   206,
     529,   577,   218,   453,   322,   323,   459,    95,   148,   744,
     461,   605,   280,   281,   475,   476,   527,   570,   258,   515,
     428,   428,   428,   428,   428,   361,    97,  -384,  -384,   362,
     495,  -384,   454,  -384,  -384,  -384,  -384,  -384,  -384,   699,
     447,    52,  -384,   423,   447,    52,   741,   433,   422,   422,
     422,   422,   422,   645,   524,   320,   321,   519,   742,   520,
     521,   494,   522,   149,   150,   286,   577,   700,   578,   684,
     572,   572,   458,    99,     8,     9,    10,    11,   579,   468,
     469,   684,   411,    12,   460,   478,   151,   661,   462,   453,
     733,   101,   453,   453,   453,   453,   577,   103,   570,   570,
     637,   580,    14,   495,   105,   471,   185,   625,   254,   571,
     541,   542,   543,   544,   107,   186,   576,   187,   454,   627,
     628,   454,   454,   454,   454,   255,   205,   206,   210,   211,
     188,   444,   541,   542,   543,   544,   109,   542,   412,   544,
     423,   423,   423,   423,   423,   413,   602,   111,   572,   572,
     572,   572,   572,    17,   189,   572,   279,   655,   703,   414,
     325,    52,   274,   205,   206,   664,   113,    19,   663,   453,
     617,    22,   150,   619,   201,   622,   570,   570,   570,   570,
     570,   202,   716,   570,   322,   323,   258,   255,   205,   206,
     571,   571,   115,   324,   356,   117,   357,  -129,   454,   656,
     -93,   502,   503,   504,   505,  -109,   507,   274,   205,   206,
     508,   509,   510,   511,   512,   513,   514,  -103,  -111,   361,
     325,    52,   119,   362,   483,   485,  -107,   -97,   -99,  -101,
     445,   563,   447,    52,   121,   205,   206,  -170,   -95,   494,
    -119,   727,   124,   671,   672,   411,   123,   274,   205,   206,
     497,   453,   498,   499,   500,   361,   411,   600,   601,   362,
     516,   141,  -342,   515,   677,   143,   633,   565,   571,   571,
     571,   571,   571,   144,   167,   571,   169,   695,   322,   323,
     454,   495,   171,  -113,   453,   172,   173,   324,   687,   536,
     174,  -130,   646,   647,   648,   649,   503,   650,   505,   178,
     507,   412,   181,   551,   552,  -121,  -123,   419,   413,  -115,
    -117,  -105,   412,   454,   325,    52,   647,   712,   649,   413,
     650,   184,   414,   325,    52,   274,   205,   206,   192,   193,
     200,  -170,   209,   414,   482,    52,   274,   205,   206,   633,
     208,   213,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   216,   745,   747,   411,
      15,   232,   235,   420,   234,   567,   239,   240,    -4,     1,
     421,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
    -259,   243,   760,    -4,    -4,   325,    52,   274,   205,   206,
     540,   249,   541,   542,   543,   544,    -4,    -4,   247,   248,
      -4,   269,    -4,   273,   271,    -4,    -4,    -4,    -4,    -4,
     541,   542,   543,   544,   150,   412,  -225,    -4,    -4,    -4,
     279,   568,   413,   284,   288,   305,   295,  -225,   569,   666,
     411,   541,   542,   543,   544,   292,   414,   325,    52,   274,
     205,   206,   535,   325,    52,   274,   205,   206,   312,   665,
     296,   299,   300,    -4,   646,   647,   648,   649,    -4,   650,
     301,   302,    -4,   313,   673,   651,   652,    -4,    -4,    -4,
     319,    -4,   336,   337,   338,   343,   339,   681,   682,   342,
     344,   685,   346,   347,    -4,    -4,   412,   348,    -4,    -4,
      -4,    -2,   363,   413,     5,     6,     7,     8,     9,    10,
      11,   354,   410,   355,   408,   429,    12,   414,   484,    52,
     274,   205,   206,   364,   435,   365,   366,   463,   464,   492,
     708,   491,   367,    13,   368,    14,   525,   262,   518,   369,
     370,   531,    15,   371,   372,   362,   713,   714,   373,   532,
     538,    16,   711,   719,   545,   721,   646,   647,   648,   649,
     554,   650,   553,   558,   556,   731,   557,   374,   375,   376,
     738,   559,   560,   561,   611,   377,   378,   167,   541,   542,
     543,   544,   502,   503,   504,   505,    17,   507,   487,   603,
     750,    18,   379,   751,   507,   606,   616,   624,   618,   626,
      19,    20,    21,   757,    22,    51,   654,   630,   631,   380,
     381,   382,   657,   639,   660,   658,   547,   383,   668,   670,
     384,   675,    20,    21,   385,   680,   650,   676,   696,   697,
     701,   702,   705,   704,   564,   706,   707,   723,   735,   722,
     386,   502,   503,   504,   505,   387,   507,   720,   728,   739,
     508,   509,   510,   511,   512,   513,   514,   566,   749,   740,
     748,   752,   303,   753,   502,   503,   504,   505,   754,   507,
     755,   260,   761,   508,   509,   510,   511,   512,   513,   514,
     709,   147,   758,   388,   231,   283,   272,   502,   503,   504,
     505,   133,   507,   448,   674,   597,   508,   509,   510,   511,
     512,   513,   514,   515,   667,   679,   575,   623,   191,     0,
       0,   710,     0,     0,     0,     0,     0,     0,   502,   503,
     504,   505,     0,   507,     0,     0,   515,   508,   509,   510,
     511,   512,   513,   514,     0,     0,     0,   581,     0,     0,
       0,   502,   503,   504,   505,     0,   507,     0,     0,   515,
     508,   509,   510,   511,   512,   513,   514,   596,     0,     0,
       0,   502,   503,   504,   505,     0,   507,     0,     0,     0,
     508,   509,   510,   511,   512,   513,   514,   620,     0,     0,
     515,   502,   503,   504,   505,     0,   507,     0,     0,     0,
     508,   509,   510,   511,   512,   513,   514,     0,     0,     0,
     621,     0,     0,   515,   502,   503,   504,   505,     0,   507,
       0,     0,     0,   508,   509,   510,   511,   512,   513,   514,
     724,     0,     0,   515,   502,   503,   504,   505,     0,   507,
       0,     0,     0,   508,   509,   510,   511,   512,   513,   514,
     729,     0,     0,   515,   502,   503,   504,   505,     0,   507,
       0,     0,     0,   508,   509,   510,   511,   512,   513,   514,
       0,     0,     0,   730,     0,     0,   515,   502,   503,   504,
     505,     0,   507,     0,     0,     0,   508,   509,   510,   511,
     512,   513,   514,   756,   155,     0,   515,   502,   503,   504,
     505,     0,   507,     0,     0,     0,   508,   509,   510,   511,
     512,   513,   514,   759,     0,     0,   515,   502,   503,   504,
     505,     0,   507,     0,     0,     0,   508,   509,   510,   511,
     512,   513,   514,     0,     0,     0,     0,     0,     0,   515,
       0,     0,   156,   157,     0,     0,   158,     0,   159,   160,
     161,   162,   163,   164,     0,     0,     0,   165,     0,   515,
     502,   503,   504,   505,   506,   507,     0,     0,     0,   508,
     509,   510,   511,   512,   513,   514,     0,     0,     0,   515,
     502,   503,   504,   505,     0,   507,     0,   743,     0,   508,
     509,   510,   511,   512,   513,   514,   502,   503,   504,   505,
       0,   507,     0,     0,     0,   508,   509,   510,   511,   512,
     513,   514,     0,   502,   503,   504,   505,     0,   507,     0,
       0,     0,   515,   509,   510,   511,   512,   513,   514,     0,
       0,     0,   502,   503,   504,   505,     0,   507,     0,     0,
       0,     0,   515,   510,   511,   512,   513,   514,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   515,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   515,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   515
};

static const yytype_int16 yycheck[] =
{
      97,   141,    17,   347,   481,   321,     1,    91,   452,   530,
     421,     1,   109,   566,   239,   240,    22,    56,     1,   256,
     117,     1,   119,   213,   249,   314,    58,   264,   265,    69,
       1,   268,    55,     1,    69,   193,    17,    69,     1,    13,
      79,   172,   200,    24,   202,    56,     1,    55,     1,    55,
     181,    86,   192,   193,    17,     1,   293,   568,   569,    33,
     200,   201,   202,   352,   282,   283,     1,    57,    79,   109,
       1,    66,   169,    88,    89,     1,   313,    57,    59,   269,
      57,   178,     1,   180,   605,    48,    57,    64,    56,   186,
     187,   188,   189,   437,   538,     1,    79,   541,   542,   543,
     544,   338,   339,   261,   262,     0,    17,   344,   519,   520,
      56,    79,    80,    24,   254,   333,    79,   132,   133,     1,
      57,   261,   262,   263,    79,    80,    79,    80,   444,   213,
       1,   215,    69,    79,    55,   646,   647,   648,   649,   650,
      55,   238,   653,   333,    79,    91,     1,   305,    79,   246,
       1,    57,   310,    79,   312,     1,   709,   710,   348,    84,
      79,    80,    82,     1,   354,   305,     1,   357,    82,    56,
     310,    55,   312,    79,   618,    57,    82,    83,   415,     1,
      79,    80,   659,   527,   282,   283,     1,    55,   346,    14,
     287,   275,    79,   277,   363,   716,   433,    79,    80,    81,
      82,    83,   439,   421,     1,    56,   346,   376,    79,    80,
      56,    82,    83,    56,   159,   160,   161,   162,   163,   164,
     165,    56,   362,   363,    79,    80,    55,   242,    79,    80,
     327,   421,    55,    79,    80,   333,    79,    62,    63,    64,
      65,    79,    67,   340,    79,    30,    71,    72,    73,    74,
      75,    76,    77,    57,    59,   445,   700,    79,    80,    56,
      82,    83,   360,    79,    79,   490,    10,     1,   408,   487,
     367,   355,    82,    83,     1,   373,    57,    81,    82,    83,
     438,    62,    79,   452,    43,    44,     1,    11,     1,   733,
       1,   528,   106,   107,    79,    80,   436,   487,   438,   124,
     518,   519,   520,   521,   522,    57,    49,   104,   105,    61,
     408,   108,   452,   110,   111,   112,   113,   114,   115,   663,
      79,    80,   119,   421,    79,    80,    56,   342,   518,   519,
     520,   521,   522,   570,   431,   280,   281,    62,    56,    64,
      63,   481,    65,    56,    57,    79,    62,    19,    64,    79,
     568,   569,    79,    38,     6,     7,     8,     9,    74,   374,
     375,    79,     1,    15,    79,   380,    79,   604,    79,   538,
      20,    39,   541,   542,   543,   544,    62,    40,   568,   569,
      66,    97,    34,   481,    28,   554,     1,   556,    64,   487,
      62,    63,    64,    65,   122,    10,   494,    12,   538,    92,
      93,   541,   542,   543,   544,    81,    82,    83,   145,   146,
      25,   356,    62,    63,    64,    65,    37,    63,    57,    65,
     518,   519,   520,   521,   522,    64,   523,    16,   646,   647,
     648,   649,   650,    85,    49,   653,    69,   577,    19,    78,
      79,    80,    81,    82,    83,    84,    29,    99,   606,   618,
     547,   103,    57,   550,    59,   553,   646,   647,   648,   649,
     650,    66,   699,   653,    43,    44,   606,    81,    82,    83,
     568,   569,    94,    52,   107,   120,   109,    56,   618,   577,
      11,    62,    63,    64,    65,    16,    67,    81,    82,    83,
      71,    72,    73,    74,    75,    76,    77,    28,    29,    57,
      79,    80,   121,    61,   384,   385,    37,    38,    39,    40,
      64,    69,    79,    80,    51,    82,    83,    96,    49,   659,
      51,   711,   117,   620,   621,     1,   116,    81,    82,    83,
     410,   700,   412,   413,   414,    57,     1,   521,   522,    61,
     420,    59,    57,   124,    59,    69,   561,    69,   646,   647,
     648,   649,   650,    82,    55,   653,    79,   655,    43,    44,
     700,   659,    79,    94,   733,    79,    79,    52,    58,   449,
      79,    56,    62,    63,    64,    65,    63,    67,    65,    79,
      67,    57,    79,   463,   464,   116,   117,     1,    64,   120,
     121,   122,    57,   733,    79,    80,    63,   694,    65,    64,
      67,    79,    78,    79,    80,    81,    82,    83,    66,    17,
      66,    96,    60,    78,    79,    80,    81,    82,    83,   634,
      79,    66,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,    79,   734,   735,     1,
      41,    56,    27,    57,    56,     1,    57,    57,     0,     1,
      64,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      58,    56,   759,    15,    16,    79,    80,    81,    82,    83,
      60,    57,    62,    63,    64,    65,    28,    29,    56,    56,
      32,    74,    34,    58,    60,    37,    38,    39,    40,    41,
      62,    63,    64,    65,    57,    57,    58,    49,    50,    51,
      69,    57,    64,    56,    69,    19,    56,    69,    64,    60,
       1,    62,    63,    64,    65,    58,    78,    79,    80,    81,
      82,    83,    84,    79,    80,    81,    82,    83,    69,   609,
      56,    56,    56,    85,    62,    63,    64,    65,    90,    67,
      56,    56,    94,    60,   624,    73,    74,    99,   100,   101,
      79,   103,    79,    56,    58,    56,    58,   637,   638,    69,
      58,   641,    19,    60,   116,   117,    57,    74,   120,   121,
     122,     0,    59,    64,     3,     4,     5,     6,     7,     8,
       9,    69,    66,    73,    96,    56,    15,    78,    79,    80,
      81,    82,    83,     1,    14,     3,     4,    57,    57,    69,
     680,    56,    10,    32,    12,    34,    56,    24,    66,    17,
      18,    73,    41,    21,    22,    61,   696,   697,    26,    73,
      59,    50,    58,   703,    56,   705,    62,    63,    64,    65,
      48,    67,    69,    59,    69,   715,    79,    45,    46,    47,
     720,    66,    20,    55,    58,    53,    54,    55,    62,    63,
      64,    65,    62,    63,    64,    65,    85,    67,    57,    56,
     740,    90,    70,   743,    67,    19,    42,    17,    66,    59,
      99,   100,   101,   753,   103,    79,    58,    79,    79,    87,
      88,    89,    73,    79,    56,    74,    33,    95,    56,    56,
      98,    60,   100,   101,   102,    57,    67,    63,    57,    57,
      56,    56,    66,    60,    55,    31,    79,    60,    23,    57,
     118,    62,    63,    64,    65,   123,    67,    66,    56,    79,
      71,    72,    73,    74,    75,    76,    77,    55,    58,    66,
      82,    56,   254,    57,    62,    63,    64,    65,    56,    67,
      62,   194,    56,    71,    72,    73,    74,    75,    76,    77,
      55,    90,    79,   327,   167,   231,   208,    62,    63,    64,
      65,    80,    67,   360,   626,   518,    71,    72,    73,    74,
      75,    76,    77,   124,   616,   634,   492,   554,   124,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    67,    -1,    -1,   124,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    67,    -1,    -1,   124,
      71,    72,    73,    74,    75,    76,    77,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    58,    -1,    -1,
     124,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      58,    -1,    -1,   124,    62,    63,    64,    65,    -1,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      58,    -1,    -1,   124,    62,    63,    64,    65,    -1,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      58,    -1,    -1,   124,    62,    63,    64,    65,    -1,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    58,    -1,    -1,   124,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    58,    56,    -1,   124,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    58,    -1,    -1,   124,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,   104,   105,    -1,    -1,   108,    -1,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,    -1,   124,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   124,
      62,    63,    64,    65,    -1,    67,    -1,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    62,    63,    64,    65,
      -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    -1,    62,    63,    64,    65,    -1,    67,    -1,
      -1,    -1,   124,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      -1,    -1,   124,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   128,   129,     0,     3,     4,     5,     6,     7,
       8,     9,    15,    32,    34,    41,    50,    85,    90,    99,
     100,   101,   103,   131,   132,   134,   136,   137,   143,   145,
     154,   159,   165,   167,   193,   276,   280,   286,   133,    55,
      55,   160,   166,    55,     1,    79,    55,     1,   194,    84,
       1,    79,    80,   135,   149,   168,    82,    55,    55,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   281,   155,    55,
      55,   146,    82,   138,    79,   195,    59,   169,    69,    86,
     130,   277,   287,    10,   188,    11,   225,    49,   247,    38,
     226,    39,   228,    40,   234,    28,   239,   122,   240,    37,
     248,    16,   229,    29,   230,    94,   265,   120,   189,   121,
     190,    51,   233,   116,   117,    56,    79,     1,    56,    79,
      91,   157,   161,   161,    56,    79,   147,     1,    56,    79,
     139,    59,   196,    69,    82,   149,   149,   136,     1,    56,
      57,    79,   141,   278,   279,    56,   104,   105,   108,   110,
     111,   112,   113,   114,   115,   119,   288,    55,   191,    79,
     191,    79,    79,    79,    79,     1,    57,   191,    79,     1,
      79,    79,   191,   191,    79,     1,    10,    12,    25,    49,
     249,   249,    66,    17,   156,     1,    56,   149,   162,    56,
      66,    59,    66,   140,   141,    82,    83,   152,    79,    60,
     169,   169,   142,    66,     1,    66,    79,     1,    79,   289,
       1,    79,   289,   290,   289,   289,   289,   289,   289,   289,
     192,   193,    56,   191,    56,    27,   245,   246,   245,    57,
      57,   236,   237,    56,   191,   191,   245,    56,    56,    57,
     191,   191,   191,   191,    64,    81,   150,   151,   152,   150,
     157,    17,    24,    59,   163,   148,   150,   152,   150,    74,
     144,    60,   196,    58,    81,   141,   152,   153,   141,    69,
     106,   107,   197,   197,    56,     1,    79,   227,    69,   191,
     236,   236,    58,   149,   238,    56,    56,   191,   236,    56,
      56,    56,    56,   151,   140,    19,   150,   150,   152,   140,
      69,   140,    69,    60,   140,   153,    64,   141,   141,    79,
     289,   289,    43,    44,    52,    79,   149,   198,   200,   202,
     203,   204,   207,   208,   213,   191,    79,    56,    58,    58,
     241,   140,    69,    56,    58,   150,    19,    60,    74,   164,
     150,   150,   140,   144,    69,    73,   107,   109,   291,   291,
     201,    57,    61,    59,     1,     3,     4,    10,    12,    17,
      18,    21,    22,    26,    45,    46,    47,    53,    54,    70,
      87,    88,    89,    95,    98,   102,   118,   123,   143,   191,
     199,   216,   219,   221,   222,   231,   242,   243,   250,   253,
     256,   258,   260,   262,   269,   270,   271,   282,    96,   266,
      66,     1,    57,    64,    78,   153,   204,   206,   213,     1,
      57,    64,   153,   204,   209,   210,   211,   212,   213,    56,
     140,   140,   191,   149,   140,    14,   158,   150,    17,   163,
     153,   144,   153,   141,   289,    64,   153,    79,   203,   214,
     152,     1,    57,   135,   152,   205,   191,     1,    79,     1,
      79,     1,    79,    57,    57,     1,   204,   257,   149,   149,
       1,   135,   283,   284,    30,    79,    80,     1,   149,   272,
       1,   259,    79,   206,    79,   206,     1,    57,   251,     1,
      57,    56,    69,     1,   152,   204,   268,   206,   206,   206,
     206,   140,    62,    63,    64,    65,    66,    67,    71,    72,
      73,    74,    75,    76,    77,   124,   206,   211,    66,    62,
      64,    63,    65,   235,   191,    56,   140,   152,   163,   150,
     140,    73,    73,   291,   153,    84,   206,   215,    59,   205,
      60,    62,    63,    64,    65,    56,    13,    33,   244,   217,
     220,   206,   206,    69,    48,   285,    69,    79,    59,    66,
      20,    55,   268,    69,    55,    69,    55,     1,    57,    64,
     153,   204,   213,   255,   236,   251,   204,    62,    64,    74,
      97,    58,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,    58,   210,   211,   211,
     212,   212,   191,    56,   163,   140,    19,   164,    58,    69,
     205,    58,   205,   205,   205,   205,    42,   191,    66,   191,
      58,    58,   204,   284,    17,   135,    59,    92,    93,   232,
      79,    79,     1,   149,   273,   274,   275,    66,   261,    79,
     264,   263,   264,   255,   255,   140,    62,    63,    64,    65,
      67,    73,    74,   252,    58,   152,   204,    73,    74,   267,
      56,   140,   164,   150,    84,   206,    60,   244,    56,   205,
      56,   191,   191,   206,   232,    60,    63,    59,    56,   274,
      57,   206,   206,    56,    79,   206,    56,    58,   255,   255,
     255,   255,   255,   255,   254,   204,    57,    57,   268,   163,
      19,    56,    56,    19,    60,    66,    31,    79,   206,    55,
      55,    58,   191,   206,   206,    57,   140,   205,   223,   206,
      66,   206,    57,    60,    58,   264,   264,   153,    56,    58,
      58,   206,   164,    20,   218,    23,   224,    14,   206,    79,
      66,    56,    56,    69,   205,   191,    22,   191,    82,    58,
     206,   206,    56,    57,    56,    62,    58,   206,    79,    58,
     191,    56
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
        case 2:

/* Line 1455 of yacc.c  */
#line 128 "parse1.y"
    {/*ldebug(top, intoken)*/;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 129 "parse1.y"
    {diag("Illegal block", (char *)0);}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 135 "parse1.y"
    {Item* q; replacstr((yyvsp[(2) - (2)].qp), "static double");
		vectorize_substitute((yyvsp[(2) - (2)].qp), "/*Top LOCAL");
		vectorize_substitute(lastok->next, "*/\n");
		movelist((yyvsp[(2) - (2)].qp), lastok->next, firstlist);
		if (!toplocal_) {toplocal_ = newlist();}
		ITERATE(q, toplocal1_) {
			assert(SYM(q)->name[0] == '_' && SYM(q)->name[1] == 'l');
			SYM(q)->name[1] = 'z';
		}
		movelist(toplocal1_->next, toplocal1_->prev, toplocal_);
		}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 148 "parse1.y"
    {model_level = atoi(STR((yyvsp[(3) - (3)].qp)));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 149 "parse1.y"
    {model_level = 0;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 151 "parse1.y"
    {if (sensused)
			diag("sensitivity analysis not implemented for",
				" this block type");
		}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 158 "parse1.y"
    {inblock(SYM((yyvsp[(2) - (2)].qp))->name); replacstr((yyvsp[(2) - (2)].qp), "\n/*VERBATIM*/\n");
		if (!assert_threadsafe && !saw_verbatim_) {
 		 fprintf(stderr, "Notice: VERBATIM blocks are not thread safe\n");
		 saw_verbatim_ = 1;
		 vectorize = 0;
		}
		movelist((yyvsp[(2) - (2)].qp),intoken->prev, procfunc);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 167 "parse1.y"
    {
		in_comment_ = 1;
		inblock(SYM((yyvsp[(2) - (2)].qp))->name); deltokens((yyvsp[(2) - (2)].qp), intoken->prev);
		in_comment_ = 0;
		}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 174 "parse1.y"
    {include_file((yyvsp[(3) - (3)].qp));}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 177 "parse1.y"
    {if (modelline == NULL) modelline = (yyvsp[(2) - (2)].str);
			deltokens((yyvsp[(1) - (2)].qp), intoken->prev);}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 180 "parse1.y"
    {(yyval.str) = inputline();}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 185 "parse1.y"
    { Symbol *sp = SYM((yyvsp[(2) - (3)].qp));
	 if (sp->subtype)
		diag(sp->name, " used before DEFINEed");
	 sp->u.str = STR((yyvsp[(3) - (3)].qp));
	 sp->type = DEFINEDVAR;
	 deltokens((yyvsp[(1) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 191 "parse1.y"
    {myerr("syntax: DEFINE name integer");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 194 "parse1.y"
    { Symbol *checklocal();
		  SYM((yyvsp[(1) - (1)].qp)) = checklocal(SYM((yyvsp[(1) - (1)].qp)));  /* it was a bug
			when this was done to the lookahead token in lex */
		}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 202 "parse1.y"
    {deltokens((yyvsp[(1) - (4)].qp), (yyvsp[(4) - (4)].qp));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 206 "parse1.y"
    { explicit_decl(model_level, (yyvsp[(2) - (2)].qp));}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 212 "parse1.y"
    {parminstall(SYM((yyvsp[(1) - (5)].qp)), STR((yyvsp[(3) - (5)].qp)), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 214 "parse1.y"
    {parminstall(SYM((yyvsp[(1) - (3)].qp)), "0", (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 216 "parse1.y"
    { int i = atoi(STR((yyvsp[(3) - (6)].qp)));
		  if (i < 1) diag("Array index must be > 0", (char*)0);
		  parm_array_install(SYM((yyvsp[(1) - (6)].qp)), "0", (yyvsp[(5) - (6)].str), (yyvsp[(6) - (6)].str), i);
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 220 "parse1.y"
    {diag("name = number", (char *)0);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 222 "parse1.y"
    {(yyval.str) = stralloc("", (char *)0);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 225 "parse1.y"
    {(yyval.str) = inputtopar();}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 227 "parse1.y"
    {(yyval.str) = (yyvsp[(2) - (3)].str); delete((yyvsp[(1) - (3)].qp)); delete((yyvsp[(3) - (3)].qp));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 229 "parse1.y"
    {replacstr((yyvsp[(1) - (1)].qp), "");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 230 "parse1.y"
    {replacstr((yyvsp[(1) - (1)].qp), "");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 233 "parse1.y"
    {(yyval.str) = stralloc("", (char*)0);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 235 "parse1.y"
    {
		 Sprintf(buf, "%s %s", STR((yyvsp[(2) - (5)].qp)), STR((yyvsp[(4) - (5)].qp)));
		 (yyval.str) = stralloc(buf, (char*)0);
		}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 240 "parse1.y"
    {deltokens((yyvsp[(1) - (4)].qp), (yyvsp[(4) - (4)].qp));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 244 "parse1.y"
    { explicit_decl(model_level, (yyvsp[(2) - (2)].qp)); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 248 "parse1.y"
    {steppedinstall(SYM((yyvsp[(1) - (4)].qp)), (yyvsp[(3) - (4)].qp), lastok, (yyvsp[(4) - (4)].str));}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 256 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 259 "parse1.y"
    { Sprintf(buf, "-%s", STR((yyvsp[(2) - (2)].qp)));
		 STR((yyvsp[(2) - (2)].qp)) = stralloc(buf, STR((yyvsp[(2) - (2)].qp))); (yyval.qp) = (yyvsp[(2) - (2)].qp);
		delete((yyvsp[(1) - (2)].qp)); lastok = (yyvsp[(2) - (2)].qp);
		}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 267 "parse1.y"
    {replacstr((yyvsp[(1) - (1)].qp), SYM((yyvsp[(1) - (1)].qp))->u.str);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 269 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 271 "parse1.y"
    {Sprintf(buf, "%s.0", STR((yyvsp[(1) - (1)].qp)));
		STR((yyvsp[(1) - (1)].qp)) = stralloc(buf, STR((yyvsp[(1) - (1)].qp)));
		lastok = (yyvsp[(1) - (1)].qp);
		}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 276 "parse1.y"
    {deltokens((yyvsp[(1) - (4)].qp), (yyvsp[(4) - (4)].qp));}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 280 "parse1.y"
    { explicit_decl(model_level, (yyvsp[(2) - (2)].qp)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 281 "parse1.y"
    {scopindep = 1;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 282 "parse1.y"
    { explicit_decl(model_level, (yyvsp[(4) - (4)].qp));
		  scopindep = 0;
		}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 288 "parse1.y"
    {indepinstall(SYM((yyvsp[(1) - (9)].qp)), STR((yyvsp[(3) - (9)].qp)),
		 STR((yyvsp[(5) - (9)].qp)), STR((yyvsp[(7) - (9)].qp)), (yyvsp[(8) - (9)].qp), (yyvsp[(9) - (9)].str), scopindep);
		}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 291 "parse1.y"
    {diag("name FROM number TO number WITH integer\n", (char *)0);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 295 "parse1.y"
    {stateblock = 0;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 295 "parse1.y"
    {deltokens((yyvsp[(1) - (5)].qp), (yyvsp[(5) - (5)].qp));}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 299 "parse1.y"
    { explicit_decl(model_level, (yyvsp[(2) - (2)].qp));}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 303 "parse1.y"
    {depinstall(stateblock, SYM((yyvsp[(1) - (4)].qp)), 0, "0", "1", (yyvsp[(3) - (4)].str), (yyvsp[(2) - (4)].qp), 1, (yyvsp[(4) - (4)].str));
		 }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 306 "parse1.y"
    {int i = atoi(STR((yyvsp[(3) - (7)].qp)));
		 if (i < 1) diag("Array index must be > 0", (char *)0);
		 depinstall(stateblock, SYM((yyvsp[(1) - (7)].qp)), i,
			 "0", "1", (yyvsp[(6) - (7)].str), (yyvsp[(5) - (7)].qp), 1, (yyvsp[(7) - (7)].str));
		}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 312 "parse1.y"
    {depinstall(stateblock, SYM((yyvsp[(1) - (8)].qp)), 0, STR((yyvsp[(3) - (8)].qp)),
		 STR((yyvsp[(5) - (8)].qp)), (yyvsp[(7) - (8)].str), (yyvsp[(6) - (8)].qp), 1, (yyvsp[(8) - (8)].str));
		}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 316 "parse1.y"
    {int i = atoi(STR((yyvsp[(3) - (11)].qp)));
		 if (i < 1) diag("Array index must be > 0", (char *)0);
		 depinstall(stateblock, SYM((yyvsp[(1) - (11)].qp)), i,
		 STR((yyvsp[(6) - (11)].qp)), STR((yyvsp[(8) - (11)].qp)), (yyvsp[(10) - (11)].str), (yyvsp[(9) - (11)].qp), 1, (yyvsp[(11) - (11)].str));
		}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 321 "parse1.y"
    {
diag("name FROM number TO number START number\n",
"FROM...TO and START are optional, name can be name[integer]\n");}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 325 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 326 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 329 "parse1.y"
    { (yyval.str) = stralloc("", (char*)0);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 331 "parse1.y"
    {
			(yyval.str) = stralloc(STR((yyvsp[(2) - (3)].qp)), (char*)0);
		}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 335 "parse1.y"
    {stateblock = 1;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 335 "parse1.y"
    {deltokens((yyvsp[(1) - (5)].qp), (yyvsp[(5) - (5)].qp));}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 339 "parse1.y"
    { Item *q;
		 q = linsertsym(plotlist, SYM((yyvsp[(4) - (5)].qp))); Insertstr(q->next, (yyvsp[(5) - (5)].str)); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 342 "parse1.y"
    { diag("PLOT namelist VS name", (char *)0);}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 345 "parse1.y"
    { if (plotlist->next == plotlist) {
			Lappendsym(plotlist, SYM((yyvsp[(1) - (2)].qp)));
			Lappendstr(plotlist, (yyvsp[(2) - (2)].str));
		  }else{
			diag("Only one PLOT declaration allowed", (char *)0);
		  }
		}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 353 "parse1.y"
    { Lappendsym(plotlist, SYM((yyvsp[(3) - (4)].qp))); Lappendstr(plotlist, (yyvsp[(4) - (4)].str));}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 356 "parse1.y"
    { (yyval.str) = "-1";}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 358 "parse1.y"
    { (yyval.str) = STR((yyvsp[(2) - (3)].qp));}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 360 "parse1.y"
    {blocktype = INITIAL1;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 362 "parse1.y"
    {lexcontext = NONLINEAR; blocktype = DERIVATIVE;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 363 "parse1.y"
    {blocktype = BREAKPOINT;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 364 "parse1.y"
    {lexcontext = blocktype = LINEAR;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 365 "parse1.y"
    {lexcontext = blocktype = NONLINEAR;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 366 "parse1.y"
    {blocktype = FUNCTION1;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 367 "parse1.y"
    {blocktype = PROCEDURE;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 368 "parse1.y"
    {blocktype = NETRECEIVE;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 369 "parse1.y"
    {blocktype = TERMINAL;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 370 "parse1.y"
    {blocktype = DISCRETE;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 371 "parse1.y"
    {lexcontext = blocktype = PARTIAL;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 372 "parse1.y"
    {lexcontext = blocktype = KINETIC;ostmt_start();}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 372 "parse1.y"
    {see_ostmt();}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 373 "parse1.y"
    {blocktype = CONSTRUCTOR;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 374 "parse1.y"
    {blocktype = DESTRUCTOR;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 375 "parse1.y"
    {blocktype = FUNCTION_TABLE;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 376 "parse1.y"
    {blocktype = BEFORE;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 377 "parse1.y"
    {blocktype = AFTER;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 380 "parse1.y"
    {movelist((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp), initfunc);}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 383 "parse1.y"
    {movelist((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp), constructorfunc);}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 386 "parse1.y"
    {movelist((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp), destructorfunc);}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 388 "parse1.y"
    {pushlocal();}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 388 "parse1.y"
    {poplocal();}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 390 "parse1.y"
    {poplocal();}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 393 "parse1.y"
    {
		  if (toplocal1_) {freelist(&toplocal1_);}
		  toplocal1_ = newlist();
		}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 398 "parse1.y"
    { replacstr((yyvsp[(1) - (3)].qp), "double");
		  Insertstr(lastok->next, ";\n");
		}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 401 "parse1.y"
    {myerr("Illegal LOCAL declaration");}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 406 "parse1.y"
    {int a2; pushlocal();
		 a2 = SYM((yyvsp[(1) - (2)].qp))->assigned_to_; /* in case marked threadsafe */
		 SYM((yyvsp[(1) - (2)].qp)) = copylocal(SYM((yyvsp[(1) - (2)].qp)));
		 SYM((yyvsp[(1) - (2)].qp))->assigned_to_ = a2;
		 lappendsym(toplocal1_, SYM((yyvsp[(1) - (2)].qp)));
		 if ((yyvsp[(2) - (2)].i)) {
			SYM((yyvsp[(1) - (2)].qp))->araydim = (yyvsp[(2) - (2)].i);
			SYM((yyvsp[(1) - (2)].qp))->subtype |= ARRAY;
		 }else{
			lastok = (yyvsp[(1) - (2)].qp);
		 }
		}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 419 "parse1.y"
    {
		 int a2 = SYM((yyvsp[(3) - (4)].qp))->assigned_to_; /* in case marked threadsafe */
		 SYM((yyvsp[(3) - (4)].qp)) = copylocal(SYM((yyvsp[(3) - (4)].qp)));
		 SYM((yyvsp[(3) - (4)].qp))->assigned_to_ = a2;
		 lappendsym(toplocal1_, SYM((yyvsp[(3) - (4)].qp)));
		 if ((yyvsp[(4) - (4)].i)) {
			SYM((yyvsp[(3) - (4)].qp))->araydim = (yyvsp[(4) - (4)].i);
			SYM((yyvsp[(3) - (4)].qp))->subtype |= ARRAY;
		 }else{
			lastok = (yyvsp[(3) - (4)].qp);
		 }
		}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 433 "parse1.y"
    {(yyval.i) = 0;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 435 "parse1.y"
    {(yyval.i) = atoi(STR((yyvsp[(2) - (3)].qp))); lastok = (yyvsp[(3) - (3)].qp);}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 438 "parse1.y"
    {if (blocktype == KINETIC) see_ostmt();}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 439 "parse1.y"
    {if (blocktype == KINETIC) see_ostmt();}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 440 "parse1.y"
    {if (blocktype == KINETIC) { see_astmt((yyvsp[(2) - (2)].qp), astmt_end_); }}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 449 "parse1.y"
    {inblock(SYM((yyvsp[(1) - (1)].qp))->name);
		replacstr((yyvsp[(1) - (1)].qp), "\n/*VERBATIM*/\n");
		if (!assert_threadsafe && !saw_verbatim_) {
 		 fprintf(stderr, "Notice: VERBATIM blocks are not thread safe\n");
		 saw_verbatim_ = 1;
		 vectorize = 0;
		}
		}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 459 "parse1.y"
    {inblock(SYM((yyvsp[(1) - (1)].qp))->name); deltokens((yyvsp[(1) - (1)].qp), intoken->prev);}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 461 "parse1.y"
    {check_block(KINETIC, blocktype, "COMPARTMENT");}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 462 "parse1.y"
    {check_block(KINETIC, blocktype, "LONGDIFUS");}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 463 "parse1.y"
    {check_block(KINETIC, blocktype, "CONSERVE");}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 467 "parse1.y"
    { replacstr((yyvsp[(1) - (1)].qp), " _reset = 1;\n"); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 471 "parse1.y"
    {if (blocktype !=FUNCTION1 && blocktype != PROCEDURE) {
			diag("TABLE valid only for FUNCTION or PROCEDURE", (char *)0);
		}}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 478 "parse1.y"
    { nrnmutex(1,(yyvsp[(1) - (1)].qp)); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 479 "parse1.y"
    { nrnmutex(0,(yyvsp[(1) - (1)].qp)); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 481 "parse1.y"
    {myerr("Illegal statement");}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 485 "parse1.y"
    {astmt_end_ = insertsym(lastok->next, semi);}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 486 "parse1.y"
    {protect_ = 1;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 487 "parse1.y"
    {protect_ = 0; astmt_end_ = insertsym(lastok->next, semi);
			astmt_end_ = protect_astmt((yyvsp[(1) - (3)].qp), astmt_end_);
		}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 490 "parse1.y"
    {inequation = 1;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 490 "parse1.y"
    {
		(yyval.qp) = (yyvsp[(2) - (2)].qp); inequation = 0;
		astmt_end_ = insertstr(lastok->next->next->next, "");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 494 "parse1.y"
    {astmt_end_ = insertsym(lastok->next, semi);}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 499 "parse1.y"
    { if (blocktype == DERIVATIVE && SYM((yyvsp[(1) - (3)].qp))->type == PRIME) {
			/* put Dvar in a derivative used list */
			deriv_used(SYM((yyvsp[(1) - (3)].qp)), (yyvsp[(3) - (3)].qp), lastok);
			}
		  if (blocktype == DERIVATIVE && (SYM((yyvsp[(1) - (3)].qp))->subtype & STAT)) {
			Fprintf(stderr,
"WARNING: %s (a STATE) is assigned a value\
 in a DERIVATIVE block.\n Multistep integrators (such as Runge) may not\
 work correctly.\n", SYM((yyvsp[(1) - (3)].qp))->name);
		  }
		  if (blocktype == DISCRETE && SYM((yyvsp[(1) - (3)].qp))->type == NAME
			&& (SYM((yyvsp[(1) - (3)].qp))->subtype & STAT)) {
			SYM((yyvsp[(1) - (3)].qp))->used++;
			}
#if NOCMODL
		  nrn_var_assigned(SYM((yyvsp[(1) - (3)].qp)));
#endif
		}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 519 "parse1.y"
    { inequation = 0;
		Insertstr((yyvsp[(2) - (4)].qp), " -(");
		replacstr((yyvsp[(3) - (4)].qp), ") + ");
		if (nstate == 0)
{yyerror("previous equation contains no state variables"); YYERROR;}
		 eqnqueue((yyvsp[(1) - (4)].qp));
		}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 527 "parse1.y"
    { inequation = 0;
		delete((yyvsp[(3) - (4)].qp));
		if (nstate == 0)
{yyerror("previous equation contains no state variables"); YYERROR;}
		}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 535 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);
		if (!extdef2){SYM((yyvsp[(1) - (1)].qp))->usage |= DEP;}
		if (SYM((yyvsp[(1) - (1)].qp))->subtype & ARRAY && !extdef2)
			{myerr("variable needs an index");}
		if (inequation && (SYM((yyvsp[(1) - (1)].qp))->subtype & STAT) && in_solvefor(SYM((yyvsp[(1) - (1)].qp)))) {
			SYM((yyvsp[(1) - (1)].qp))->used++;
			nstate++; pstate++; tstate++;
		}
		if (SYM((yyvsp[(1) - (1)].qp))->subtype & INTGER) {
			lastok = insertstr((yyvsp[(1) - (1)].qp)->next, ")");
			(yyvsp[(1) - (1)].qp) = insertstr((yyvsp[(1) - (1)].qp), "((double)");
		}
		}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 549 "parse1.y"
    {lastok = (yyvsp[(4) - (4)].qp);
		if (SYM((yyvsp[(1) - (4)].qp))->type == PRIME) {
			usederivstatearray = 1;
		}
		SYM((yyvsp[(1) - (4)].qp))->usage |= DEP;
		if ((SYM((yyvsp[(1) - (4)].qp))->subtype & ARRAY) == 0)
			{myerr("variable is not an array");}
		if (inequation && (SYM((yyvsp[(1) - (4)].qp))->subtype & STAT) && in_solvefor(SYM((yyvsp[(1) - (4)].qp)))) {
			SYM((yyvsp[(1) - (4)].qp))->used++;
			nstate++; pstate++; tstate++;
		}
		  if (forallindex) {
			if (forallindex == -1) {
				forallindex = SYM((yyvsp[(1) - (4)].qp))->araydim;
			}
			if (forallindex != SYM((yyvsp[(1) - (4)].qp))->araydim) {
Sprintf(buf, "%s dimension not same as other dimensions used in FORALL statement",
SYM((yyvsp[(1) - (4)].qp))->name);
				diag(buf, (char *)0);
			}
		  }
		}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 572 "parse1.y"
    {lastok = (yyvsp[(3) - (3)].qp);
		SYM((yyvsp[(1) - (3)].qp))->usage |= DEP; disc_var_seen((yyvsp[(1) - (3)].qp), (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp), 0);}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 575 "parse1.y"
    {lastok = (yyvsp[(6) - (6)].qp);
		SYM((yyvsp[(1) - (6)].qp))->usage |= DEP; disc_var_seen((yyvsp[(1) - (6)].qp), (yyvsp[(2) - (6)].qp), (yyvsp[(3) - (6)].qp), ARRAY);}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 579 "parse1.y"
    {lastok = (yyvsp[(1) - (1)].qp);
		 SYM((yyvsp[(1) - (1)].qp))->usage |= DEP;
		 if (!(SYM((yyvsp[(1) - (1)].qp))->subtype & INTGER)) {
		 	lastok = insertstr((yyvsp[(1) - (1)].qp)->next, ")");
			(yyvsp[(1) - (1)].qp) = insertstr((yyvsp[(1) - (1)].qp), "((int)");
		 }
		}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 586 "parse1.y"
    { lastok = (yyvsp[(1) - (1)].qp);}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 587 "parse1.y"
    { lastok = (yyvsp[(3) - (3)].qp);}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 592 "parse1.y"
    {myerr("Illegal integer expression");}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 597 "parse1.y"
    {lastok = (yyvsp[(3) - (3)].qp);}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 603 "parse1.y"
    { (yyval.qp) = insertstr((yyvsp[(1) - (3)].qp), "pow("); replacstr((yyvsp[(2) - (3)].qp), ",");
			lastok = insertstr(lastok->next, ")"); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 605 "parse1.y"
    {replacstr((yyvsp[(2) - (3)].qp), " ||");}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 606 "parse1.y"
    {replacstr((yyvsp[(2) - (3)].qp), " &&");}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 611 "parse1.y"
    {replacstr((yyvsp[(2) - (3)].qp), " ==");}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 612 "parse1.y"
    {replacstr((yyvsp[(2) - (3)].qp), " !=");}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 613 "parse1.y"
    {replacstr((yyvsp[(1) - (2)].qp), " !");}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 615 "parse1.y"
    {myerr("Illegal expression");}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 617 "parse1.y"
    {inequation = 1; nstate = 0;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 621 "parse1.y"
    {inequation = 1; nstate = 0;
		pstate = 0; tstate = 0; init_lineq((yyvsp[(1) - (1)].qp)); leftside = -1;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 624 "parse1.y"
    {leftside = 1;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 628 "parse1.y"
    {linterm((yyvsp[(1) - (1)].qp), lastok, pstate, leftside); pstate = 0;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 630 "parse1.y"
    {delete((yyvsp[(1) - (2)].qp));
		linterm((yyvsp[(2) - (2)].qp), lastok, pstate, -leftside); pstate = 0;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 633 "parse1.y"
    {delete((yyvsp[(2) - (3)].qp));
		linterm((yyvsp[(3) - (3)].qp), lastok, pstate, leftside); pstate = 0;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 636 "parse1.y"
    {delete((yyvsp[(2) - (3)].qp));
		linterm((yyvsp[(3) - (3)].qp), lastok, pstate, -leftside); pstate = 0;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 640 "parse1.y"
    { if (tstate == 1) {
			lin_state_term((yyvsp[(1) - (1)].qp), lastok);
		  }
		  tstate = 0;
		}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 646 "parse1.y"
    { if (tstate == 1) {
			lin_state_term((yyvsp[(3) - (3)].qp), lastok);
		  }
		  tstate = 0;
		}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 652 "parse1.y"
    { if (tstate) {
			diag("state ocurs in denominator", (char *)0);
		  }
		}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 659 "parse1.y"
    {if (tstate) diag("states not permitted in function calls",
			(char *)0);}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 661 "parse1.y"
    { lastok = (yyvsp[(3) - (3)].qp);
			if (tstate) diag("states not permitted between ",
				"parentheses");}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 665 "parse1.y"
    {diag("Some operators are not permitted in linear\n",
"expressions unless the terms containing them are\nenclosed in parentheses");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 669 "parse1.y"
    { if (SYM((yyvsp[(1) - (2)].qp))->subtype & EXTDEF2) { extdef2 = 1;}}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 671 "parse1.y"
    {lastok = (yyvsp[(5) - (5)].qp); SYM((yyvsp[(1) - (5)].qp))->usage |= FUNCT;
		 if (SYM((yyvsp[(1) - (5)].qp))->subtype & EXTDEF2) { extdef2 = 0;}
		 if (SYM((yyvsp[(1) - (5)].qp))->subtype & EXTDEF3) { add_reset_args((yyvsp[(2) - (5)].qp));}
		 if (SYM((yyvsp[(1) - (5)].qp))->subtype & EXTDEF4) { add_nrnthread_arg((yyvsp[(2) - (5)].qp));}
		 if (SYM((yyvsp[(1) - (5)].qp))->subtype & EXTDEF5) {
			if (!assert_threadsafe) {
fprintf(stderr, "Notice: %s is not thread safe\n", SYM((yyvsp[(1) - (5)].qp))->name);
				vectorize = 0;
			}
		 }
#if VECTORIZE
		 vectorize_use_func((yyvsp[(1) - (5)].qp),(yyvsp[(2) - (5)].qp),(yyvsp[(4) - (5)].qp),(yyvsp[(5) - (5)].qp),blocktype);
#endif
		}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 686 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 692 "parse1.y"
    {pushlocal(); SYM((yyvsp[(2) - (2)].qp)) = copylocal(SYM((yyvsp[(2) - (2)].qp)));
			SYM((yyvsp[(2) - (2)].qp))->subtype |= INTGER;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 696 "parse1.y"
    { replacstr((yyvsp[(1) - (10)].qp), "{int ");
		poplocal();
		Insertstr((yyvsp[(4) - (10)].qp), ";for (");
		Insertstr((yyvsp[(4) - (10)].qp), SYM((yyvsp[(2) - (10)].qp))->name);
		Insertstr((yyvsp[(6) - (10)].qp), ";");
		Insertstr((yyvsp[(6) - (10)].qp), SYM((yyvsp[(2) - (10)].qp))->name);
		replacstr((yyvsp[(6) - (10)].qp), "<=");
		if ((yyvsp[(8) - (10)].qp)) {
			Insertstr((yyvsp[(8) - (10)].qp), ";");
			Insertstr((yyvsp[(8) - (10)].qp), SYM((yyvsp[(2) - (10)].qp))->name);
			replacstr((yyvsp[(8) - (10)].qp), "+=");
		} else {
			Insertstr((yyvsp[(9) - (10)].qp), ";");
			Insertstr((yyvsp[(9) - (10)].qp), SYM((yyvsp[(2) - (10)].qp))->name);
			Insertstr((yyvsp[(9) - (10)].qp), "++");
		}
		Insertstr((yyvsp[(9) - (10)].qp), ")");
		Insertstr((yyvsp[(10) - (10)].qp), "}");
		}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 715 "parse1.y"
    {
myerr("FROM intvar = intexpr TO intexpr BY intexpr { statements }");}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 718 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 721 "parse1.y"
    {pushlocal(); SYM((yyvsp[(2) - (2)].qp)) = copylocal(SYM((yyvsp[(2) - (2)].qp)));
			  SYM((yyvsp[(2) - (2)].qp))->subtype |= INTGER;
			  if (forallindex) {
diag("Nested FORALL statements not allowed", (char *)0);
			  }
			  forallindex = -1;
			}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 730 "parse1.y"
    { replacstr((yyvsp[(1) - (5)].qp), "{int ");
		poplocal();
		if (forallindex == -1) {
diag("FORALL range is undefined since no arrays used", " within the statement");
		}
		Sprintf(buf, "; for (%s=0; %s<%d; %s++)", SYM((yyvsp[(2) - (5)].qp))->name,
			SYM((yyvsp[(2) - (5)].qp))->name, forallindex, SYM((yyvsp[(2) - (5)].qp))->name);
		Insertstr((yyvsp[(4) - (5)].qp), buf);
		Insertstr((yyvsp[(5) - (5)].qp), "}");
		}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 740 "parse1.y"
    {
myerr("FORALL intvar { statements }");}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 749 "parse1.y"
    {
#if VECTORIZE
			vectorize_if_else_stmt(blocktype);
#endif
		}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 757 "parse1.y"
    {
#if VECTORIZE
			vectorize_if_else_stmt(blocktype);
#endif
		}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 765 "parse1.y"
    {massagederiv((yyvsp[(1) - (4)].qp), (yyvsp[(2) - (4)].qp), (yyvsp[(3) - (4)].qp), (yyvsp[(4) - (4)].qp), sensused); sensused = 0;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 767 "parse1.y"
    {init_linblk((yyvsp[(2) - (3)].qp));}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 769 "parse1.y"
    {massage_linblk((yyvsp[(1) - (6)].qp), (yyvsp[(2) - (6)].qp), (yyvsp[(5) - (6)].qp), (yyvsp[(6) - (6)].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 775 "parse1.y"
    {massagenonlin((yyvsp[(1) - (5)].qp), (yyvsp[(2) - (5)].qp), (yyvsp[(4) - (5)].qp), (yyvsp[(5) - (5)].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 781 "parse1.y"
    {massagediscblk((yyvsp[(1) - (4)].qp), (yyvsp[(2) - (4)].qp), (yyvsp[(3) - (4)].qp), (yyvsp[(4) - (4)].qp));}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 785 "parse1.y"
    {massagepartial((yyvsp[(1) - (4)].qp), (yyvsp[(2) - (4)].qp), (yyvsp[(3) - (4)].qp), (yyvsp[(4) - (4)].qp));
		lexcontext = 0;
		}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 788 "parse1.y"
    {
diag("within the PARTIAL block must occur an equation with the syntax ---\n",
"~ V' = F*DEL2(V) + G\n"); }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 793 "parse1.y"
    {partial_eqn((yyvsp[(2) - (11)].qp), (yyvsp[(4) - (11)].qp), (yyvsp[(8) - (11)].qp), (yyvsp[(11) - (11)].qp));}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 795 "parse1.y"
    {partial_bndry(0, (yyvsp[(3) - (8)].qp), (yyvsp[(5) - (8)].qp), (yyvsp[(8) - (8)].qp), lastok);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 797 "parse1.y"
    {partial_bndry(2, (yyvsp[(2) - (7)].qp), (yyvsp[(4) - (7)].qp), (yyvsp[(7) - (7)].qp), lastok);}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 802 "parse1.y"
    {Item *b1, *b2;
		Symbol* s = SYM((yyvsp[(2) - (6)].qp));
		b1 = insertstr((yyvsp[(5) - (6)].qp)->next, "{\n");
		b2 = insertstr(b1->next, "}\n");

#define GLOBFUNCT 1
#if GLOBFUNCT && NMODL
		replacstr((yyvsp[(1) - (6)].qp), "\ndouble");
#else
		replacstr((yyvsp[(1) - (6)].qp), "\nstatic double");
#endif
		defarg((yyvsp[(3) - (6)].qp), (yyvsp[(5) - (6)].qp));
		movelist((yyvsp[(1) - (6)].qp), b2, procfunc);
		if (SYM((yyvsp[(2) - (6)].qp))->subtype & FUNCT) {
			diag(SYM((yyvsp[(2) - (6)].qp))->name, " declared as FUNCTION twice");
		}
		SYM((yyvsp[(2) - (6)].qp))->subtype |= FUNCT;
		SYM((yyvsp[(2) - (6)].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[(3) - (6)].qp), (yyvsp[(5) - (6)].qp));
#endif
		function_table(s, (yyvsp[(3) - (6)].qp), (yyvsp[(5) - (6)].qp), b1, b2);
		poplocal();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 828 "parse1.y"
    {IGNORE(copylocal(SYM((yyvsp[(2) - (6)].qp))));}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 832 "parse1.y"
    { Symbol *s = SYM((yyvsp[(2) - (9)].qp));
		table_massage(table_list, (yyvsp[(1) - (9)].qp), (yyvsp[(2) - (9)].qp), (yyvsp[(4) - (9)].lp)); freelist(&table_list);
#if GLOBFUNCT && NMODL
		replacstr((yyvsp[(1) - (9)].qp), "\ndouble");
#else
		replacstr((yyvsp[(1) - (9)].qp), "\nstatic double");
#endif
		defarg((yyvsp[(3) - (9)].qp), (yyvsp[(5) - (9)].qp));
		Sprintf(buf, "double _l%s;\n", s->name);
		Insertstr((yyvsp[(8) - (9)].qp)->next, buf);
		Sprintf(buf, "\nreturn _l%s;\n", s->name);
		Insertstr((yyvsp[(9) - (9)].qp), buf);
		movelist((yyvsp[(1) - (9)].qp), (yyvsp[(9) - (9)].qp), procfunc);
		if (SYM((yyvsp[(2) - (9)].qp))->subtype & FUNCT) {
			diag(SYM((yyvsp[(2) - (9)].qp))->name, " declared as FUNCTION twice");
		}
		SYM((yyvsp[(2) - (9)].qp))->subtype |= FUNCT;
		SYM((yyvsp[(2) - (9)].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[(3) - (9)].qp), (yyvsp[(5) - (9)].qp));
#endif
		poplocal(); freelist(&(yyvsp[(4) - (9)].lp));}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 855 "parse1.y"
    {pushlocal(); (yyval.lp) = LIST0; argcnt_ = 0;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 856 "parse1.y"
    {pushlocal();}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 856 "parse1.y"
    {(yyval.lp) = (yyvsp[(2) - (2)].lp);}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 859 "parse1.y"
    {SYM((yyvsp[(1) - (2)].qp)) = copylocal(SYM((yyvsp[(1) - (2)].qp))); argcnt_ = 1;
		 (yyval.lp) = newlist(); Lappendsym((yyval.lp), SYM((yyvsp[(1) - (2)].qp)));
		}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 863 "parse1.y"
    {SYM((yyvsp[(3) - (4)].qp)) = copylocal(SYM((yyvsp[(3) - (4)].qp))); Lappendsym((yyval.lp), SYM((yyvsp[(3) - (4)].qp)));
		 ++argcnt_;
		}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 868 "parse1.y"
    {Symbol *s = SYM((yyvsp[(2) - (8)].qp));
		s->u.i = 0; 	/* avoid objectcenter warning if solved */
		table_massage(table_list, (yyvsp[(1) - (8)].qp), (yyvsp[(2) - (8)].qp), (yyvsp[(4) - (8)].lp)); freelist(&table_list);
		replacstr((yyvsp[(1) - (8)].qp), "\nstatic int "); defarg((yyvsp[(3) - (8)].qp), (yyvsp[(5) - (8)].qp));
		Insertstr((yyvsp[(8) - (8)].qp), " return 0;");
		movelist((yyvsp[(1) - (8)].qp), (yyvsp[(8) - (8)].qp), procfunc);
		if (SYM((yyvsp[(2) - (8)].qp))->subtype & PROCED) {
			diag(SYM((yyvsp[(2) - (8)].qp))->name, " declared as PROCEDURE twice");
		}
		SYM((yyvsp[(2) - (8)].qp))->subtype |= PROCED;
		SYM((yyvsp[(2) - (8)].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[(3) - (8)].qp), (yyvsp[(5) - (8)].qp));
#endif
		poplocal(); freelist(&(yyvsp[(4) - (8)].lp));}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 885 "parse1.y"
    {
			nr_argcnt_ = argcnt_;
			/* add flag arg */
			if ((yyvsp[(3) - (4)].lp) == LIST0) {
diag("NET_RECEIVE block"," must have at least one argument");
			}
			Lappendsym((yyvsp[(3) - (4)].lp), copylocal(install("flag", NAME)));
		}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 894 "parse1.y"
    {
		replacstr((yyvsp[(1) - (7)].qp), "\nstatic _net_receive");
		movelist((yyvsp[(1) - (7)].qp), (yyvsp[(7) - (7)].qp), procfunc);
#if NMODL
		net_receive((yyvsp[(3) - (7)].lp), (yyvsp[(2) - (7)].qp), (yyvsp[(4) - (7)].qp), (yyvsp[(6) - (7)].qp), (yyvsp[(7) - (7)].qp));
#endif
		poplocal(); freelist(&(yyvsp[(3) - (7)].lp));
		}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 902 "parse1.y"
    { myerr("syntax: NET_RECEIVE ( weight ) {stmtlist}");}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 905 "parse1.y"
    {
			check_block(NETRECEIVE, blocktype, "INITIAL");
#if NMODL
			net_init((yyvsp[(1) - (3)].qp), (yyvsp[(3) - (3)].qp));
#endif
		}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 914 "parse1.y"
    { solvequeue((yyvsp[(2) - (3)].qp), ITEM0, blocktype, (yyvsp[(3) - (3)].qp)); }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 916 "parse1.y"
    { solvequeue((yyvsp[(2) - (5)].qp), (yyvsp[(4) - (5)].qp), blocktype, (yyvsp[(5) - (5)].qp)); }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 917 "parse1.y"
    { myerr("Illegal SOLVE statement");}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 920 "parse1.y"
    { (yyval.qp) = ITEM0; }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 922 "parse1.y"
    { (yyval.qp) = (yyvsp[(3) - (3)].qp); }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 925 "parse1.y"
    { if (solveforlist) {
			freelist(&solveforlist);
		  }
		}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 932 "parse1.y"
    { solveforlist = newlist(); Lappendsym(solveforlist, SYM((yyvsp[(2) - (2)].qp)));
		  delete((yyvsp[(1) - (2)].qp)); delete((yyvsp[(2) - (2)].qp));
		}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 936 "parse1.y"
    { Lappendsym(solveforlist, SYM((yyvsp[(3) - (3)].qp))); delete((yyvsp[(2) - (3)].qp)); delete((yyvsp[(3) - (3)].qp));}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 937 "parse1.y"
    { myerr("Syntax: SOLVEFOR name, name, ...");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 941 "parse1.y"
    {brkpnt_exists = 1; movelist((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp), modelfunc);}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 944 "parse1.y"
    {movelist((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp), termfunc);}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 947 "parse1.y"
    {bablk(blocktype, BREAKPOINT, (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 949 "parse1.y"
    {bablk(blocktype, SOLVE, (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 951 "parse1.y"
    {bablk(blocktype, INITIAL1, (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 953 "parse1.y"
    {bablk(blocktype, STEP, (yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 954 "parse1.y"
    {myerr("[BEFORE AFTER] [BREAKPOINT SOLVE INITIAL STEP] { stmt }");}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 957 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp); delete((yyvsp[(1) - (2)].qp));}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 959 "parse1.y"
    {delete((yyvsp[(2) - (3)].qp));}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 960 "parse1.y"
    {myerr("WATCH (expr > expr) flag");}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 963 "parse1.y"
    {watchstmt((yyvsp[(1) - (6)].qp), (yyvsp[(3) - (6)].qp), (yyvsp[(5) - (6)].qp), (yyvsp[(6) - (6)].qp), blocktype); (yyval.qp)=(yyvsp[(6) - (6)].qp);}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 968 "parse1.y"
    {
			if (blocktype != NETRECEIVE) {
				diag("\"FOR_NETCONS\" statement only allowed in NET_RECEIVE block", (char*)0);
			}
			if (argcnt_ != nr_argcnt_) {
				diag("FOR_NETCONS and NET_RECEIVE do not have same number of arguments", (char*)0);
			}
		}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 977 "parse1.y"
    {fornetcon((yyvsp[(1) - (7)].qp), (yyvsp[(2) - (7)].qp), (yyvsp[(3) - (7)].lp), (yyvsp[(4) - (7)].qp), (yyvsp[(6) - (7)].qp), (yyvsp[(7) - (7)].qp)); (yyval.qp) = (yyvsp[(7) - (7)].qp); }
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 978 "parse1.y"
    { myerr("syntax: FOR_NETCONS(args,like,netreceive) { stmtlist}");}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 983 "parse1.y"
    {lastok = (yyvsp[(3) - (3)].qp);}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 989 "parse1.y"
    { (yyval.qp) = insertstr((yyvsp[(1) - (3)].qp), "pow("); replacstr((yyvsp[(2) - (3)].qp), ",");
			lastok = insertstr(lastok->next, ")"); }
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 992 "parse1.y"
    {myerr("Illegal expression");}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 997 "parse1.y"
    { sensused = 1;
		  delete((yyvsp[(1) - (2)].qp));
		}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1000 "parse1.y"
    {myerr("syntax is SENS var1, var2, var3, etc");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1004 "parse1.y"
    { sensparm((yyvsp[(1) - (1)].qp)); delete((yyvsp[(1) - (1)].qp));}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1006 "parse1.y"
    { sensparm((yyvsp[(3) - (3)].qp)); deltokens((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1009 "parse1.y"
    {extdef2 = 0; }
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1010 "parse1.y"
    {/* react originally designed for reactions and is unchanged*/
		extdef2 = 0;
		massageconserve((yyvsp[(1) - (5)].qp), (yyvsp[(4) - (5)].qp), lastok);}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1013 "parse1.y"
    {myerr("Illegal CONSERVE syntax");}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1016 "parse1.y"
    {pushlocal(); SYM((yyvsp[(2) - (3)].qp)) = copylocal(SYM((yyvsp[(2) - (3)].qp)));}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1018 "parse1.y"
    {massagecompart((yyvsp[(5) - (8)].qp), (yyvsp[(6) - (8)].qp), (yyvsp[(8) - (8)].qp), SYM((yyvsp[(2) - (8)].qp))); poplocal();}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1020 "parse1.y"
    {massagecompart((yyvsp[(2) - (5)].qp), (yyvsp[(3) - (5)].qp), (yyvsp[(5) - (5)].qp), SYM0);}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1023 "parse1.y"
    {pushlocal(); SYM((yyvsp[(2) - (3)].qp)) = copylocal(SYM((yyvsp[(2) - (3)].qp)));}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1025 "parse1.y"
    {massageldifus((yyvsp[(5) - (8)].qp), (yyvsp[(6) - (8)].qp), (yyvsp[(8) - (8)].qp), SYM((yyvsp[(2) - (8)].qp))); poplocal();}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1027 "parse1.y"
    {massageldifus((yyvsp[(2) - (5)].qp), (yyvsp[(3) - (5)].qp), (yyvsp[(5) - (5)].qp), SYM0);}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1035 "parse1.y"
    {massagekinetic((yyvsp[(1) - (5)].qp), (yyvsp[(2) - (5)].qp), (yyvsp[(4) - (5)].qp), (yyvsp[(5) - (5)].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1039 "parse1.y"
    {leftreact();}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1040 "parse1.y"
    {massagereaction((yyvsp[(1) - (10)].qp),(yyvsp[(3) - (10)].qp),(yyvsp[(6) - (10)].qp),(yyvsp[(8) - (10)].qp),(yyvsp[(10) - (10)].qp));}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1042 "parse1.y"
    {flux((yyvsp[(1) - (7)].qp), (yyvsp[(3) - (7)].qp), (yyvsp[(7) - (7)].qp));}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1044 "parse1.y"
    {flux((yyvsp[(1) - (7)].qp), (yyvsp[(3) - (7)].qp), (yyvsp[(7) - (7)].qp));}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1045 "parse1.y"
    {myerr("Illegal reaction syntax");}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1047 "parse1.y"
    {reactname((yyvsp[(1) - (1)].qp), lastok, ITEM0);}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1048 "parse1.y"
    {reactname((yyvsp[(2) - (2)].qp), lastok, (yyvsp[(1) - (2)].qp));}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1049 "parse1.y"
    {reactname((yyvsp[(3) - (3)].qp), lastok, ITEM0);}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1050 "parse1.y"
    {reactname((yyvsp[(4) - (4)].qp), lastok, (yyvsp[(3) - (4)].qp));}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1053 "parse1.y"
    {lag_stmt((yyvsp[(1) - (4)].qp), blocktype);}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1054 "parse1.y"
    {myerr("Lag syntax is: LAG name BY const");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1056 "parse1.y"
    {queue_stmt((yyvsp[(1) - (2)].qp), (yyvsp[(2) - (2)].qp));}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1057 "parse1.y"
    {queue_stmt((yyvsp[(1) - (2)].qp), (yyvsp[(2) - (2)].qp));}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1059 "parse1.y"
    {checkmatch(blocktype);}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1060 "parse1.y"
    {deltokens((yyvsp[(1) - (5)].qp), (yyvsp[(5) - (5)].qp));}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1066 "parse1.y"
    {matchinitial((yyvsp[(1) - (1)].qp));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1068 "parse1.y"
    { matchbound((yyvsp[(1) - (6)].qp), (yyvsp[(2) - (6)].qp), (yyvsp[(4) - (6)].qp), (yyvsp[(6) - (6)].qp), lastok, matchindex);
		  if (matchindex) {
			poplocal();
			matchindex = SYM0;
		  }
		}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1075 "parse1.y"
    {myerr("MATCH syntax is state0 or state(expr)=expr or\
state[i](expr(i)) = expr(i)");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1079 "parse1.y"
    {matchindex = SYM0;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1081 "parse1.y"
    { pushlocal();
		  matchindex = copylocal(SYM((yyvsp[(3) - (4)].qp)));
		}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1086 "parse1.y"
    { deltokens((yyvsp[(1) - (4)].qp),(yyvsp[(4) - (4)].qp));}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1089 "parse1.y"
    {modl_units();}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1094 "parse1.y"
    {install_units((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1095 "parse1.y"
    {myerr("Unit definition syntax: (units) = (units)");}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1098 "parse1.y"
    { SYM((yyvsp[(1) - (4)].qp))->subtype |= CONST;
		  Sprintf(buf, "static double %s = %s;\n", SYM((yyvsp[(1) - (4)].qp))->name,
			STR((yyvsp[(3) - (4)].qp)));
		  Lappendstr(firstlist, buf);
		}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1104 "parse1.y"
    {Item *q; double d, unit_mag();
		    Unit_push((yyvsp[(3) - (4)].str));
			Unit_push((yyvsp[(4) - (4)].str)); unit_div();
		    SYM((yyvsp[(1) - (4)].qp))->subtype |= CONST;
		    Sprintf(buf, "static double %s = %g;\n", SYM((yyvsp[(1) - (4)].qp))->name,
			unit_mag());
		    Lappendstr(firstlist, buf);
		    unit_pop();
		}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1114 "parse1.y"
    { double unit_mag();
		    Unit_push((yyvsp[(3) - (6)].str)); Unit_push((yyvsp[(6) - (6)].str)); unit_div();
		    SYM((yyvsp[(1) - (6)].qp))->subtype |= CONST;
		    Sprintf(buf, "static double %s = %g;\n", SYM((yyvsp[(1) - (6)].qp))->name,
			unit_mag());
		    Lappendstr(firstlist, buf);
		    unit_pop();
		}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1122 "parse1.y"
    {myerr("Unit factor syntax: examples:\n\
foot2inch = (foot) -> (inch)\n\
F = 96520 (coulomb)\n\
R = (k-mole) (joule/degC)");
		}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1132 "parse1.y"
    { SYM((yyvsp[(2) - (5)].qp))->subtype |= CONST;
		  Sprintf(buf, "static double %s = %s;\n", SYM((yyvsp[(2) - (5)].qp))->name,
			STR((yyvsp[(4) - (5)].qp)));
		  Lappendstr(firstlist, buf);
		}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1139 "parse1.y"
    { Item *q;
		  if (table_list) {
			diag("only one TABLE per function", (char *)0);
		  }
		  table_list = newlist();
		  Lappendlst(table_list, (yyvsp[(2) - (9)].lp));
		  q = lappendlst(table_list, newlist());
		  movelist((yyvsp[(4) - (9)].qp)->next, (yyvsp[(6) - (9)].qp)->prev, LST(q));
		  q = lappendlst(table_list, newlist());
		  movelist((yyvsp[(6) - (9)].qp)->next, (yyvsp[(8) - (9)].qp)->prev, LST(q));
		  Lappendstr(table_list, STR((yyvsp[(9) - (9)].qp)));
		  Lappendlst(table_list, (yyvsp[(3) - (9)].lp));
		  deltokens((yyvsp[(1) - (9)].qp), (yyvsp[(9) - (9)].qp));
		}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1153 "parse1.y"
    { myerr("syntax: TABLE [list] [DEPEND list] FROM expr TO expr WITH integer");}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1156 "parse1.y"
    {(yyval.lp) = LIST0;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1160 "parse1.y"
    {(yyval.lp) = newlist(); Lappendsym((yyval.lp), SYM((yyvsp[(1) - (1)].qp)));}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1162 "parse1.y"
    { Lappendsym((yyvsp[(1) - (3)].lp), SYM((yyvsp[(3) - (3)].qp)));}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1165 "parse1.y"
    {(yyval.lp) = LIST0;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1167 "parse1.y"
    {(yyval.lp) = (yyvsp[(2) - (2)].lp);}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1170 "parse1.y"
    { deltokens((yyvsp[(1) - (4)].qp),(yyvsp[(4) - (4)].qp));}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1174 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1177 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp),(yyvsp[(3) - (3)].qp));}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1179 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp),(yyvsp[(3) - (3)].qp));}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1181 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1183 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1185 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1187 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1189 "parse1.y"
    { nrn_list((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp));}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1191 "parse1.y"
    { threadsafe_seen((yyvsp[(2) - (3)].qp), (yyvsp[(3) - (3)].qp)); }
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1194 "parse1.y"
    {nrn_use((yyvsp[(2) - (5)].qp), (yyvsp[(4) - (5)].qp), ITEM0, (yyvsp[(5) - (5)].qp));}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1196 "parse1.y"
    {nrn_use((yyvsp[(2) - (5)].qp), ITEM0, (yyvsp[(4) - (5)].qp), (yyvsp[(5) - (5)].qp));}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1198 "parse1.y"
    {nrn_use((yyvsp[(2) - (7)].qp), (yyvsp[(4) - (7)].qp), (yyvsp[(6) - (7)].qp), (yyvsp[(7) - (7)].qp));}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1200 "parse1.y"
    {myerr("syntax is: USEION ion READ list WRITE list");}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1204 "parse1.y"
    { delete((yyvsp[(2) - (3)].qp)); (yyval.qp) = (yyvsp[(3) - (3)].qp);}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1206 "parse1.y"
    {myerr("syntax is: keyword name , name, ..., name");}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1209 "parse1.y"
    {(yyval.qp) = NULL;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1213 "parse1.y"
    {(yyval.qp) = ITEM0;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1215 "parse1.y"
    {(yyval.qp) = (yyvsp[(2) - (2)].qp);}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1218 "parse1.y"
    { Sprintf(buf, "-%s", STR((yyvsp[(3) - (3)].qp)));
		 STR((yyvsp[(3) - (3)].qp)) = stralloc(buf, STR((yyvsp[(3) - (3)].qp))); (yyval.qp) = (yyvsp[(3) - (3)].qp);
		delete((yyvsp[(2) - (3)].qp)); lastok = (yyvsp[(3) - (3)].qp);
		}
    break;



/* Line 1455 of yacc.c  */
#line 4803 "parse1.c"
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
#line 1223 "parse1.y"

yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	Fprintf(stderr, "%s:\n ", s);
}


#if !NMODL
nrn_list(q1, q2)
	Item *q1, *q2;
{
	/*ARGSUSED*/
}
nrn_use(q1, q2, q3, q4)
	Item *q1, *q2, *q3, *q4;
{
	/*ARGSUSED*/
}
#endif

