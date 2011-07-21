
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
#line 2 "parse.y"


#include <../../nrnconf.h>
/* changes as of 2-jan-89 */
/*  version 7.2.1 2-jan-89 short form of the for statement */

#if AIX
#pragma alloca
#endif

#ifdef ANDROID
#include <stdio.h>
#endif
         
#include "hoc.h"
#include "code.h"
#include "equation.h"

#if LINT
Inst *inlint;
#define code	inlint = Code
#else
#define code	Code
#endif
extern Inst* codei(int i);

#define paction(arg) fprintf(stderr, "%s\n", arg)

/* maintain a list of ierr addresses so we can clear them */
#define HOCERRSIZE 20
static int** hoc_err;
static int hoc_errp;
static int localcnt;

static clean_err() {
	int i;
	for (i=0; i < hoc_errp; ++i) {
		*hoc_err[i] = 0;
	}
	hoc_errp = 0;
}

static pusherr(ip) int* ip; {
	if (!hoc_err) {
		hoc_err = (int**)ecalloc(HOCERRSIZE, sizeof(int*));
		hoc_errp = 0;
	}
	if (hoc_errp >= HOCERRSIZE) {
		clean_err();
		hoc_execerror("error stack full", (char*)0);
	}
	hoc_err[hoc_errp++] = ip;
}

#if YYBISON
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} YYERROR
#endif

#define code2(c1,c2)	code(c1); codein(c2)
#define code3(c1,c2,c3)	code(c1); codesym(c2); code(c3)
#define relative(ip1,ip2,offset)	((ip1-ip2) - offset)
#define CHECK 1	/* check syntactically the consistency of arrays */
#define NOCHECK 0 /* don't check syntactically. For object components */
#define PN pushi(NUMBER)	/* for type checking. expressions are usually numbers */
#define TPD hoc_ob_check(NUMBER);
#define TPDYNAM hoc_ob_check(0);

extern int pipeflag;
extern Symlist *symlist;	/* This list is permanent */
extern Symlist *p_symlist; /* Constants, strings, auto variables */
extern Symbol* hoc_decl();
extern Symbol* hoc_which_template();
extern Symbol* hoc_table_lookup();

extern arayinstal();
extern int indef;
static Inst *prog_error;			/* needed for stmtlist loc if error */
static int ntab;			/* auto indentation */
extern FILE	*fin;				/* input file pointer */

static Inst* argcode(), *argrefcode();
 


/* Line 189 of yacc.c  */
#line 162 "parse.c"

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
     EQNEQ = 258,
     NUMBER = 259,
     STRING = 260,
     PRINT = 261,
     DELETE = 262,
     VAR = 263,
     BLTIN = 264,
     UNDEF = 265,
     WHILE = 266,
     IF = 267,
     ELSE = 268,
     FOR = 269,
     FUNCTION = 270,
     PROCEDURE = 271,
     RETURN = 272,
     FUNC = 273,
     PROC = 274,
     HOCOBJFUNC = 275,
     READ = 276,
     DOUBLE = 277,
     DEBUG = 278,
     EDIT = 279,
     FUN_BLTIN = 280,
     DEPENDENT = 281,
     EQUATION = 282,
     LOCAL = 283,
     HOCOBJFUNCTION = 284,
     BREAK = 285,
     CONTINUE = 286,
     AUTO = 287,
     STRDEF = 288,
     STOPSTMT = 289,
     CSTRING = 290,
     PARALLEL = 291,
     HELP = 292,
     ITERATOR = 293,
     ITERKEYWORD = 294,
     ITERSTMT = 295,
     STRINGFUNC = 296,
     OBJECTFUNC = 297,
     LOCALOBJ = 298,
     AUTOOBJ = 299,
     ARG = 300,
     NUMZERO = 301,
     ARGREF = 302,
     SECTIONKEYWORD = 303,
     SECTION = 304,
     CONNECTKEYWORD = 305,
     ACCESSKEYWORD = 306,
     RANGEVAR = 307,
     MECHANISM = 308,
     INSERTKEYWORD = 309,
     FORALL = 310,
     NRNPNTVAR = 311,
     FORSEC = 312,
     IFSEC = 313,
     UNINSERTKEYWORD = 314,
     SETPOINTERKEYWORD = 315,
     SECTIONREF = 316,
     BEGINTEMPLATE = 317,
     ENDTEMPLATE = 318,
     NEW = 319,
     OBJECTVAR = 320,
     TEMPLATE = 321,
     OBJVARDECL = 322,
     PUBLICDECL = 323,
     EXTERNALDECL = 324,
     OBFUNCTION = 325,
     STRFUNCTION = 326,
     OBJECTARG = 327,
     STRINGARG = 328,
     ROP = 329,
     OR = 330,
     AND = 331,
     NE = 332,
     EQ = 333,
     LE = 334,
     LT = 335,
     GE = 336,
     GT = 337,
     NOT = 338,
     UNARYMINUS = 339
   };
#endif
/* Tokens.  */
#define EQNEQ 258
#define NUMBER 259
#define STRING 260
#define PRINT 261
#define DELETE 262
#define VAR 263
#define BLTIN 264
#define UNDEF 265
#define WHILE 266
#define IF 267
#define ELSE 268
#define FOR 269
#define FUNCTION 270
#define PROCEDURE 271
#define RETURN 272
#define FUNC 273
#define PROC 274
#define HOCOBJFUNC 275
#define READ 276
#define DOUBLE 277
#define DEBUG 278
#define EDIT 279
#define FUN_BLTIN 280
#define DEPENDENT 281
#define EQUATION 282
#define LOCAL 283
#define HOCOBJFUNCTION 284
#define BREAK 285
#define CONTINUE 286
#define AUTO 287
#define STRDEF 288
#define STOPSTMT 289
#define CSTRING 290
#define PARALLEL 291
#define HELP 292
#define ITERATOR 293
#define ITERKEYWORD 294
#define ITERSTMT 295
#define STRINGFUNC 296
#define OBJECTFUNC 297
#define LOCALOBJ 298
#define AUTOOBJ 299
#define ARG 300
#define NUMZERO 301
#define ARGREF 302
#define SECTIONKEYWORD 303
#define SECTION 304
#define CONNECTKEYWORD 305
#define ACCESSKEYWORD 306
#define RANGEVAR 307
#define MECHANISM 308
#define INSERTKEYWORD 309
#define FORALL 310
#define NRNPNTVAR 311
#define FORSEC 312
#define IFSEC 313
#define UNINSERTKEYWORD 314
#define SETPOINTERKEYWORD 315
#define SECTIONREF 316
#define BEGINTEMPLATE 317
#define ENDTEMPLATE 318
#define NEW 319
#define OBJECTVAR 320
#define TEMPLATE 321
#define OBJVARDECL 322
#define PUBLICDECL 323
#define EXTERNALDECL 324
#define OBFUNCTION 325
#define STRFUNCTION 326
#define OBJECTARG 327
#define STRINGARG 328
#define ROP 329
#define OR 330
#define AND 331
#define NE 332
#define EQ 333
#define LE 334
#define LT 335
#define GE 336
#define GT 337
#define NOT 338
#define UNARYMINUS 339




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 90 "parse.y"
				/* stack type */
	Symbol	*sym;			/* symbol table pointer */
	Inst	*inst;			/* machine instruction */
	int	narg;			/* number of arguments */



/* Line 214 of yacc.c  */
#line 374 "parse.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 386 "parse.c"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2838

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNRULES -- Number of states.  */
#define YYNSTATES  546

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,    93,     2,     2,     2,     2,
      92,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    88,   104,     2,
      94,    95,    86,    84,    99,    85,    98,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,   103,
       2,    75,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    96,     2,    97,    91,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,     2,   101,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      76,    77,    78,    79,    80,    81,    82,    83,    89,    90
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    19,    23,    27,
      31,    35,    39,    43,    44,    49,    52,    56,    60,    65,
      69,    77,    81,    85,    86,    90,    92,    94,    99,   105,
     111,   113,   115,   116,   123,   126,   127,   131,   134,   136,
     138,   141,   144,   148,   150,   153,   157,   162,   164,   167,
     171,   174,   178,   182,   186,   190,   193,   195,   197,   203,
     205,   207,   211,   215,   217,   219,   221,   223,   225,   227,
     229,   232,   235,   238,   245,   248,   251,   254,   257,   263,
     266,   272,   279,   280,   281,   292,   293,   294,   306,   311,
     316,   324,   325,   330,   332,   336,   341,   349,   357,   358,
     365,   368,   371,   374,   377,   380,   384,   395,   402,   403,
     411,   412,   413,   424,   425,   431,   432,   439,   440,   447,
     448,   455,   456,   463,   468,   469,   472,   473,   477,   482,
     483,   486,   488,   491,   495,   500,   502,   504,   508,   509,
     513,   515,   520,   522,   525,   527,   532,   536,   537,   539,
     543,   546,   550,   553,   555,   556,   557,   558,   561,   564,
     566,   568,   570,   572,   574,   577,   579,   584,   586,   588,
     594,   599,   604,   609,   613,   616,   620,   624,   628,   632,
     636,   640,   643,   647,   651,   655,   659,   663,   667,   671,
     675,   678,   680,   682,   684,   686,   690,   694,   697,   701,
     706,   708,   711,   712,   717,   721,   724,   726,   727,   732,
     734,   736,   740,   744,   746,   747,   754,   755,   762,   763,
     770,   771,   778,   780,   782,   784,   786,   788,   789,   796,
     797,   799,   801,   805,   807,   809,   812,   818,   821,   822,
     828,   830,   834,   837,   840,   841,   847,   848,   851,   852,
     855,   856,   858,   861,   865,   866,   868,   871,   875,   877,
     879,   881,   883,   885,   887,   889,   891,   893,   895,   897,
     899,   901,   903,   905,   907,   909,   911,   913,   915,   917,
     919
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,    -1,   106,    92,    -1,   106,   176,    92,
      -1,   106,   108,    92,    -1,   106,   126,    92,    -1,   106,
     163,    92,    -1,   106,    23,    92,    -1,   106,    24,    92,
      -1,   106,   122,    92,    -1,   106,   115,    92,    -1,   106,
      93,    92,    -1,    -1,   106,    37,   107,    92,    -1,   106,
       1,    -1,   169,    74,   163,    -1,    45,    74,   163,    -1,
      47,   172,    74,   163,    -1,   149,    74,   163,    -1,   112,
      74,    64,   201,    94,   184,    95,    -1,   112,    74,   163,
      -1,   169,    74,     1,    -1,    -1,    65,   110,   171,    -1,
      72,    -1,    44,    -1,    66,    96,   163,    97,    -1,    42,
     160,    94,   184,    95,    -1,    29,   160,    94,   184,    95,
      -1,   112,    -1,   109,    -1,    -1,   112,    98,   201,   113,
     171,   114,    -1,    65,     1,    -1,    -1,    94,   184,    95,
      -1,    62,   201,    -1,   119,    -1,   120,    -1,    63,   201,
      -1,    62,     1,    -1,    67,   160,   117,    -1,   118,    -1,
     118,   167,    -1,   117,    99,   118,    -1,   117,    99,   118,
     167,    -1,   201,    -1,    68,   201,    -1,   119,    99,   201,
      -1,    69,     8,    -1,   120,    99,     8,    -1,   123,    74,
     122,    -1,   112,    74,   122,    -1,   123,    74,   111,    -1,
     123,     1,    -1,   123,    -1,    35,    -1,    41,   160,    94,
     184,    95,    -1,     5,    -1,    73,    -1,    33,   160,   125,
      -1,   124,    99,   125,    -1,   201,    -1,   163,    -1,   124,
      -1,   165,    -1,   116,    -1,   121,    -1,   122,    -1,     7,
     175,    -1,    17,   160,    -1,    17,   163,    -1,    17,    64,
     201,    94,   184,    95,    -1,    40,   160,    -1,    30,   160,
      -1,    34,   160,    -1,    31,   160,    -1,    16,   160,    94,
     184,    95,    -1,     6,   174,    -1,    14,   160,   141,   126,
     161,    -1,   153,   154,   155,   156,   126,   161,    -1,    -1,
      -1,    14,   169,   127,    74,   163,    99,   163,   128,   126,
     161,    -1,    -1,    -1,    36,    14,   169,   129,    74,   163,
      99,   163,   130,   126,   161,    -1,   158,   157,   126,   161,
      -1,   159,   157,   126,   161,    -1,   159,   157,   126,   161,
      13,   126,   161,    -1,    -1,   100,   131,   162,   101,    -1,
     187,    -1,    48,   160,   147,    -1,    50,   145,    99,   163,
      -1,    50,   145,    99,   143,    94,   163,    95,    -1,    60,
     149,    94,   163,    95,    99,   152,    -1,    -1,    60,   160,
     132,   111,    99,   152,    -1,    51,   143,    -1,    51,   111,
      -1,    54,    53,    -1,    59,    53,    -1,   143,   126,    -1,
     111,   126,   161,    -1,   149,    94,   163,   102,   163,    95,
      74,   163,   102,   163,    -1,   149,    94,   163,    95,    74,
     163,    -1,    -1,    14,    94,   169,    95,   133,   126,   161,
      -1,    -1,    -1,    14,    94,   169,    99,   134,   163,    95,
     135,   126,   161,    -1,    -1,    55,   160,   136,   126,   161,
      -1,    -1,    57,   160,   122,   137,   126,   161,    -1,    -1,
      58,   160,   122,   138,   126,   161,    -1,    -1,    57,   160,
     111,   139,   126,   161,    -1,    -1,    58,   160,   111,   140,
     126,   161,    -1,    38,    94,   184,    95,    -1,    -1,   142,
     111,    -1,    -1,    49,   144,   171,    -1,   143,    94,   163,
      95,    -1,    -1,   146,   111,    -1,   148,    -1,   148,   167,
      -1,   147,    99,   148,    -1,   147,    99,   148,   167,    -1,
     201,    -1,   150,    -1,   143,    98,   150,    -1,    -1,    52,
     151,   171,    -1,   169,    -1,   149,    94,   163,    95,    -1,
     111,    -1,   149,     1,    -1,    47,    -1,    14,    94,   126,
     103,    -1,    14,    94,   103,    -1,    -1,   163,    -1,   103,
     126,    95,    -1,   103,    95,    -1,    94,   163,    95,    -1,
      11,   154,    -1,    12,    -1,    -1,    -1,    -1,   162,    92,
      -1,   162,   126,    -1,     1,    -1,     4,    -1,    46,    -1,
     169,    -1,    45,    -1,    47,   172,    -1,   149,    -1,   149,
      94,   163,    95,    -1,   111,    -1,   108,    -1,   164,   160,
      94,   184,    95,    -1,   169,    94,   184,    95,    -1,    21,
      94,   169,    95,    -1,     9,    94,   163,    95,    -1,    94,
     163,    95,    -1,    94,     1,    -1,   163,    84,   163,    -1,
     163,    85,   163,    -1,   163,    86,   163,    -1,   163,    87,
     163,    -1,   163,    88,   163,    -1,   163,    91,   163,    -1,
      85,   163,    -1,   163,    83,   163,    -1,   163,    82,   163,
      -1,   163,    81,   163,    -1,   163,    80,   163,    -1,   163,
      79,   163,    -1,   163,    78,   163,    -1,   163,    77,   163,
      -1,   163,    76,   163,    -1,    89,   163,    -1,    15,    -1,
      25,    -1,    70,    -1,    71,    -1,    22,   160,   166,    -1,
     165,    99,   166,    -1,   168,   167,    -1,    96,   163,    97,
      -1,   167,    96,   163,    97,    -1,   200,    -1,    32,   160,
      -1,    -1,     8,   160,   170,   171,    -1,   143,    98,     8,
      -1,   160,   173,    -1,   173,    -1,    -1,   173,    96,   163,
      97,    -1,   163,    -1,   122,    -1,   174,    99,   163,    -1,
     174,    99,   122,    -1,     8,    -1,    -1,    18,   181,   177,
      94,    95,   182,    -1,    -1,    19,   181,   178,    94,    95,
     182,    -1,    -1,    39,   181,   179,    94,    95,   182,    -1,
      -1,    20,   181,   180,    94,    95,   182,    -1,   200,    -1,
      15,    -1,    16,    -1,    38,    -1,    29,    -1,    -1,   100,
     196,   198,   183,   162,   101,    -1,    -1,   185,    -1,   186,
      -1,   185,    99,   186,    -1,   122,    -1,   163,    -1,   104,
     152,    -1,    64,   201,    94,   184,    95,    -1,    26,   189,
      -1,    -1,    27,   169,   102,   188,   190,    -1,   169,    -1,
     189,    99,   169,    -1,   192,     3,    -1,     3,   194,    -1,
      -1,   102,   191,   192,     3,   194,    -1,    -1,   193,   163,
      -1,    -1,   195,   163,    -1,    -1,   197,    -1,    28,   201,
      -1,   197,    99,   201,    -1,    -1,   199,    -1,    43,   201,
      -1,   199,    99,   201,    -1,     8,    -1,     5,    -1,     8,
      -1,    10,    -1,    15,    -1,    16,    -1,    25,    -1,    49,
      -1,    52,    -1,    56,    -1,    65,    -1,    66,    -1,    70,
      -1,    32,    -1,    44,    -1,    61,    -1,    53,    -1,     9,
      -1,    71,    -1,    29,    -1,    38,    -1,    41,    -1,    42,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   145,   146,   147,   149,   151,   153,   155,
     157,   161,   163,   165,   165,   166,   176,   180,   182,   185,
     189,   195,   201,   205,   205,   207,   209,   211,   213,   216,
     221,   224,   225,   225,   235,   238,   239,   242,   243,   244,
     245,   246,   248,   251,   253,   255,   257,   260,   270,   272,
     275,   277,   282,   284,   289,   291,   294,   295,   297,   301,
     303,   307,   309,   311,   324,   326,   327,   329,   331,   332,
     334,   336,   338,   347,   351,   357,   359,   361,   363,   365,
     367,   372,   383,   387,   382,   394,   398,   393,   406,   410,
     414,   420,   419,   425,   428,   429,   431,   433,   435,   435,
     438,   440,   442,   444,   446,   448,   451,   455,   460,   459,
     468,   471,   467,   477,   476,   484,   483,   490,   489,   496,
     495,   503,   502,   514,   519,   519,   525,   525,   529,   530,
     530,   540,   542,   544,   546,   549,   557,   559,   561,   561,
     564,   566,   568,   570,   571,   577,   579,   583,   585,   588,
     590,   593,   596,   599,   603,   606,   609,   610,   621,   622,
     627,   629,   631,   633,   635,   638,   640,   644,   647,   648,
     650,   652,   654,   656,   658,   660,   662,   664,   666,   668,
     670,   672,   674,   676,   678,   680,   682,   684,   686,   688,
     690,   693,   694,   695,   696,   698,   701,   706,   709,   711,
     714,   717,   720,   719,   726,   734,   769,   776,   777,   781,
     783,   785,   787,   790,   795,   794,   801,   800,   807,   806,
     813,   812,   819,   825,   826,   827,   828,   830,   830,   837,
     838,   840,   842,   845,   847,   849,   850,   855,   858,   857,
     863,   865,   868,   869,   871,   870,   875,   875,   880,   880,
     885,   886,   888,   895,   907,   908,   910,   920,   931,   939,
     939,   939,   939,   939,   939,   939,   939,   940,   940,   940,
     940,   940,   940,   940,   941,   941,   941,   941,   941,   941,
     942
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQNEQ", "NUMBER", "STRING", "PRINT",
  "DELETE", "VAR", "BLTIN", "UNDEF", "WHILE", "IF", "ELSE", "FOR",
  "FUNCTION", "PROCEDURE", "RETURN", "FUNC", "PROC", "HOCOBJFUNC", "READ",
  "DOUBLE", "DEBUG", "EDIT", "FUN_BLTIN", "DEPENDENT", "EQUATION", "LOCAL",
  "HOCOBJFUNCTION", "BREAK", "CONTINUE", "AUTO", "STRDEF", "STOPSTMT",
  "CSTRING", "PARALLEL", "HELP", "ITERATOR", "ITERKEYWORD", "ITERSTMT",
  "STRINGFUNC", "OBJECTFUNC", "LOCALOBJ", "AUTOOBJ", "ARG", "NUMZERO",
  "ARGREF", "SECTIONKEYWORD", "SECTION", "CONNECTKEYWORD", "ACCESSKEYWORD",
  "RANGEVAR", "MECHANISM", "INSERTKEYWORD", "FORALL", "NRNPNTVAR",
  "FORSEC", "IFSEC", "UNINSERTKEYWORD", "SETPOINTERKEYWORD", "SECTIONREF",
  "BEGINTEMPLATE", "ENDTEMPLATE", "NEW", "OBJECTVAR", "TEMPLATE",
  "OBJVARDECL", "PUBLICDECL", "EXTERNALDECL", "OBFUNCTION", "STRFUNCTION",
  "OBJECTARG", "STRINGARG", "ROP", "'='", "OR", "AND", "NE", "EQ", "LE",
  "LT", "GE", "GT", "'+'", "'-'", "'*'", "'/'", "'%'", "NOT", "UNARYMINUS",
  "'^'", "'\\n'", "'\\005'", "'('", "')'", "'['", "']'", "'.'", "','",
  "'{'", "'}'", "':'", "';'", "'&'", "$accept", "list", "$@1", "asgn",
  "object", "$@2", "ob", "ob1", "$@3", "func_or_range_array_case",
  "template", "objvarlist", "objvarlst1", "obvarname", "publiclist",
  "externallist", "strnasgn", "string1", "string2", "strlist", "string",
  "stmt", "@4", "@5", "@6", "@7", "$@8", "$@9", "@10", "$@11", "@12",
  "@13", "@14", "@15", "@16", "@17", "iterator", "$@18", "section", "$@19",
  "section_or_ob", "@20", "sectiondecl", "sectionname", "rangevar",
  "rangevar1", "$@21", "pointer", "for_init", "for_st", "for_cond",
  "for_inc", "cond", "while", "if", "begin", "end", "stmtlist", "expr",
  "function", "doublelist", "newarray", "numdimen", "newname", "varname",
  "$@22", "wholearray", "argrefdim", "array", "prlist", "delsym", "defn",
  "$@23", "$@24", "$@25", "$@26", "procname", "procstmt", "$@27",
  "arglist", "arglist1", "arglist2", "eqn_list", "$@28", "dep_list",
  "equation", "$@29", "lhs", "$@30", "rhs", "$@31", "local", "local1",
  "localobj", "local2", "ckvar", "anyname", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    61,   330,   331,   332,   333,
     334,   335,   336,   337,    43,    45,    42,    47,    37,   338,
     339,    94,    10,     5,    40,    41,    91,    93,    46,    44,
     123,   125,    58,    59,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   106,   106,   108,   108,   108,   108,
     108,   108,   108,   110,   109,   109,   109,   109,   109,   109,
     111,   112,   113,   112,   112,   114,   114,   115,   115,   115,
     115,   115,   116,   117,   117,   117,   117,   118,   119,   119,
     120,   120,   121,   121,   121,   121,   122,   122,   122,   123,
     123,   124,   124,   125,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   128,   126,   129,   130,   126,   126,   126,
     126,   131,   126,   126,   126,   126,   126,   126,   132,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   133,   126,
     134,   135,   126,   136,   126,   137,   126,   138,   126,   139,
     126,   140,   126,   141,   142,   141,   144,   143,   145,   146,
     145,   147,   147,   147,   147,   148,   149,   149,   151,   150,
     152,   152,   152,   152,   152,   153,   153,   154,   155,   156,
     156,   157,   158,   159,   160,   161,   162,   162,   162,   162,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   164,   164,   164,   164,   165,   165,   166,   167,   167,
     168,   169,   170,   169,   169,   171,   172,   173,   173,   174,
     174,   174,   174,   175,   177,   176,   178,   176,   179,   176,
     180,   176,   181,   181,   181,   181,   181,   183,   182,   184,
     184,   185,   185,   186,   186,   186,   186,   187,   188,   187,
     189,   189,   190,   190,   191,   190,   193,   192,   195,   194,
     196,   196,   197,   197,   198,   198,   199,   199,   200,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     4,     2,     3,     3,     4,     3,
       7,     3,     3,     0,     3,     1,     1,     4,     5,     5,
       1,     1,     0,     6,     2,     0,     3,     2,     1,     1,
       2,     2,     3,     1,     2,     3,     4,     1,     2,     3,
       2,     3,     3,     3,     3,     2,     1,     1,     5,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     6,     2,     2,     2,     2,     5,     2,
       5,     6,     0,     0,    10,     0,     0,    11,     4,     4,
       7,     0,     4,     1,     3,     4,     7,     7,     0,     6,
       2,     2,     2,     2,     2,     3,    10,     6,     0,     7,
       0,     0,    10,     0,     5,     0,     6,     0,     6,     0,
       6,     0,     6,     4,     0,     2,     0,     3,     4,     0,
       2,     1,     2,     3,     4,     1,     1,     3,     0,     3,
       1,     4,     1,     2,     1,     4,     3,     0,     1,     3,
       2,     3,     2,     1,     0,     0,     0,     2,     2,     1,
       1,     1,     1,     1,     2,     1,     4,     1,     1,     5,
       4,     4,     4,     3,     2,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     3,     3,     2,     3,     4,
       1,     2,     0,     4,     3,     2,     1,     0,     4,     1,
       1,     3,     3,     1,     0,     6,     0,     6,     0,     6,
       0,     6,     1,     1,     1,     1,     1,     0,     6,     0,
       1,     1,     3,     1,     1,     2,     5,     2,     0,     5,
       1,     3,     2,     2,     0,     5,     0,     2,     0,     2,
       0,     1,     2,     3,     0,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    15,   160,    59,     0,     0,   154,     0,
     147,   153,   154,   191,   154,   154,     0,     0,     0,     0,
     154,     0,     0,   192,     0,     0,   154,   154,   154,   154,
     154,   154,    57,     0,    13,     0,   154,   154,   154,    26,
     163,   161,   207,   154,   126,   129,     0,   138,     0,   154,
     154,   154,     0,   154,     0,     0,     0,     0,   154,     0,
       0,   193,   194,    25,    60,     0,     0,     3,     0,     0,
      91,   168,    31,   167,    30,     0,    67,    38,    39,    68,
       0,     0,    65,     0,     0,   165,   136,   147,     0,     0,
       0,   154,    66,   162,     0,    93,   168,   167,    30,   210,
      56,     0,   165,   209,    79,   213,    70,   202,     0,   152,
       0,     0,   124,    82,     0,     0,    71,    72,   258,   223,
     224,   226,   225,   214,   222,   216,   220,     0,     0,     8,
       9,   240,   237,     0,     0,    75,    77,   201,     0,    76,
       0,     0,   218,    74,     0,     0,     0,   164,   206,     0,
     154,     0,     0,     0,   101,    30,   100,   154,   102,   113,
       0,     0,   103,     0,     0,    98,    41,   259,   260,   275,
     261,   262,   263,   264,   277,   271,   278,   279,   280,   272,
     265,   266,   274,   267,   273,   268,   269,   270,   276,    37,
      40,    34,   154,     0,     0,    48,    50,   181,   190,    12,
     174,     0,     0,     5,    69,   155,    64,     0,     0,    11,
       0,     0,    10,    55,     0,     0,     6,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,   229,     4,     0,     0,     0,   154,     0,
     146,     0,   162,     0,     0,     0,     0,     0,   229,     0,
       0,     0,     0,     0,   195,     0,   200,     0,   238,   229,
      61,    63,    85,    14,     0,   229,   229,    17,     0,     0,
      94,   131,   135,   207,   127,     0,     0,   130,   139,     0,
     119,   115,   121,   117,     0,     0,     0,    24,     0,    42,
      43,    47,   173,   159,     0,   105,     0,    53,    21,    32,
      49,    51,    54,    52,    62,   204,   137,    19,     0,     0,
     148,     0,   155,   155,   189,   188,   187,   186,   185,   184,
     183,   182,   175,   176,   177,   178,   179,   180,   229,   196,
      22,    16,     0,     0,   233,   234,     0,   230,   231,     0,
     212,   211,   203,   172,   145,   108,   110,   229,   155,   125,
       0,     0,   229,     0,     0,     0,   171,     0,   197,   241,
     246,     0,     0,     0,     0,     0,    18,     0,     0,   132,
     205,     0,     0,    95,   155,     0,     0,     0,     0,     0,
       0,    27,     0,    44,   157,    92,   158,     0,   154,   166,
       0,     0,     0,   151,    88,    89,     0,     0,   144,   142,
       0,   235,   140,   170,     0,   166,     0,     0,     0,    80,
       0,    78,     0,     0,     0,     0,     0,     0,   248,   244,
     239,     0,     0,    29,     0,     0,    58,    28,   208,   133,
     128,     0,   114,   155,   155,   155,   155,     0,     0,    45,
     229,    35,     0,     0,   150,     0,   155,     0,   169,   229,
     143,     0,   232,   155,     0,   123,     0,    73,   250,   215,
     217,   221,   198,     0,   243,     0,   246,   242,   247,     0,
     219,   134,     0,   120,   116,   122,   118,     0,    99,    46,
       0,   229,    33,   107,     0,   149,    81,   155,     0,     0,
     109,   111,    83,     0,   254,   251,   199,   249,     0,     0,
      96,    97,    20,     0,     0,    90,   236,   141,     0,     0,
     252,     0,   227,   255,     0,   248,    86,    36,     0,   155,
     155,   256,     0,     0,   253,   245,     0,     0,   112,    84,
       0,   257,   155,   106,   228,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   141,    96,    72,   192,    97,    98,   398,   492,
      75,    76,   299,   300,    77,    78,    79,   204,    81,    82,
     270,   396,   257,   519,   372,   536,   202,   296,   416,   417,
     518,   289,   386,   388,   385,   387,   255,   256,   101,   150,
     152,   153,   280,   281,   102,    86,   157,   411,    87,   109,
     319,   402,   223,    88,    89,   283,   305,   304,   206,    91,
      92,   264,   368,   265,    93,   248,   284,   147,   148,   104,
     106,    94,   260,   261,   274,   262,   123,   469,   532,   346,
     347,   348,    95,   370,   132,   430,   476,   431,   432,   474,
     475,   504,   505,   522,   523,   124,   271
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -423
static const yytype_int16 yypact[] =
{
    -423,  1136,  -423,  -423,  -423,  -423,  2166,    10,  -423,   -75,
    -423,  -423,     5,  -423,  -423,  2220,   105,   105,   105,   -66,
    -423,   -52,   -50,  -423,     2,     2,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,    16,  -423,   105,  -423,  -423,  -423,  -423,
     -33,  -423,  -423,  -423,  -423,    11,    15,  -423,     8,  -423,
    -423,  -423,    32,    30,  2387,  2446,   912,   -10,  -423,  2446,
      81,  -423,  -423,  -423,  -423,  2328,  2328,  -423,    -2,  1970,
    -423,     9,  -423,  1892,   -65,    12,  -423,    -8,    -6,  -423,
      19,  1032,    -5,    24,  1698,   -63,  -423,  -423,    25,    25,
    2730,  -423,    27,   -62,    36,  -423,  -423,  -423,   -59,  -423,
    -423,    31,   -51,  2747,    40,  -423,  -423,  -423,  2328,  -423,
    1402,    33,    59,  -423,    28,  2446,  -423,  2747,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,     2,    92,  -423,
    -423,  -423,    41,     0,    47,  -423,  -423,  -423,  2446,  -423,
       2,    38,  -423,  -423,    52,    57,  2328,    29,    39,  2446,
    -423,    60,    54,    83,  -423,    58,  -423,  -423,  -423,  -423,
     103,   103,  -423,    64,    72,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  2328,  2446,  -423,  -423,    67,    67,  -423,
    -423,  2530,  1233,  -423,  -423,  -423,  2747,  2095,  2446,  -423,
    2446,   162,  -423,  -423,   103,  2446,  -423,     6,  -423,  2328,
    2328,  2328,  2328,  1892,  1892,  2328,  2328,  2328,  2328,  2328,
    2328,  2328,  2328,  2328,  2328,  2328,  2328,  2328,  2328,  -423,
      78,    92,  2024,  1311,  -423,  2274,  2328,  2166,  -423,  2550,
    -423,    70,   -28,   166,    84,  1892,    83,   106,  1311,    85,
      87,   100,   107,    82,  -423,   101,  -423,     2,  -423,  1311,
    -423,  -423,  -423,  -423,   108,  1311,  1311,  2747,  2328,  2328,
     110,   101,  -423,  -423,  -423,  2328,  2328,  -423,  -423,  1892,
    -423,  -423,  -423,  -423,   147,  2328,    83,  -423,  2442,   111,
     101,  -423,  -423,  -423,  1502,  -423,  2446,  -423,  2747,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  2747,   805,    97,
    2747,  2570,  -423,  -423,  2000,   775,   104,   104,   104,   104,
     104,   104,   -13,   -13,    67,    67,    67,    67,  1311,  -423,
    -423,  2747,  2446,   209,  -423,  2747,   112,   113,  -423,  2590,
    -423,  2747,  -423,  -423,  -423,  -423,  -423,  1311,  -423,  -423,
    2328,   116,  1311,   119,   120,   121,  -423,  2328,   124,  -423,
       3,   126,   130,   131,   134,   136,  2747,  2464,  2446,   124,
      39,  2610,   -69,  2747,  -423,  1892,  1892,  1892,  1892,  2630,
     133,  -423,  2446,   124,  -423,  -423,  -423,   139,  -423,   132,
    2328,  1795,  1892,  -423,  -423,   192,   140,   142,  -423,  -423,
       1,  -423,  -423,  -423,  1311,  -423,  1892,  2328,   145,  -423,
     272,  -423,   148,   125,   125,   125,  2486,  2328,  -423,  -423,
    -423,   205,  2328,  -423,  2328,   125,  -423,  -423,  -423,   101,
    -423,  2328,  -423,  -423,  -423,  -423,  -423,   135,   209,   101,
    1311,   150,  2328,  2650,  -423,   153,  -423,  1892,  -423,  1311,
    -423,  2328,  -423,  -423,  2670,  -423,  2328,  -423,   217,  -423,
    -423,  -423,  -423,  2508,  -423,  2328,  -423,  -423,  2747,   653,
    -423,   124,  2690,  -423,  -423,  -423,  -423,   209,  -423,   124,
     154,  1311,  -423,  2747,   176,  -423,  -423,  -423,   157,  2710,
    -423,  -423,  2747,  2446,   214,   163,  -423,  2747,   261,  2328,
    -423,  -423,  -423,   170,  2328,  -423,  -423,  -423,  1892,  1892,
    -423,  2446,  -423,   167,  2446,  -423,  2747,  -423,   238,  -423,
    -423,  -423,  1233,  2446,  -423,  -423,  1892,  2328,  -423,  -423,
    1600,  -423,  -423,  2747,  -423,  -423
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -423,  -423,  -423,   266,  -423,  -423,    -1,     4,  -423,  -423,
    -423,  -423,  -423,  -120,  -423,  -423,  -423,   415,   417,  -423,
      53,   109,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,    23,  -423,
    -423,  -423,  -423,  -105,   114,  -210,  -423,  -422,  -423,   189,
    -423,  -423,   188,  -423,  -423,   651,  -260,  -253,   361,  -423,
    -423,    42,  -278,  -423,    -4,  -423,  -156,  -423,    -3,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,    35,  -408,  -423,  -220,
    -423,  -130,  -423,  -423,  -423,  -423,  -423,  -191,  -423,  -239,
    -423,  -423,  -423,  -423,  -423,  -124,   502
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -157
static const yytype_int16 yytable[] =
{
      73,   288,   460,   379,   266,    74,   428,   316,   113,   207,
       8,   219,   242,     8,   315,   245,   470,   471,   105,   108,
     131,   133,   393,   219,    84,   441,   488,   480,   127,   217,
     140,   220,   243,   208,    29,   111,   297,    29,   361,   208,
     129,   146,   130,   246,    26,   154,   242,   111,   111,   371,
     155,    44,   125,   126,    44,   374,   375,    38,    47,    39,
      44,   158,   404,   405,    44,   511,   243,   355,   151,   156,
     142,   356,    73,   235,   236,   237,   163,    74,   238,    44,
      56,    57,    47,    73,   316,   162,   193,    63,    74,   196,
     199,   210,   352,   211,   215,   461,    84,   254,   419,   110,
     118,   203,   268,   278,   209,   429,   252,    84,     5,    73,
      83,   212,    26,   118,    74,    85,   216,   266,   406,   222,
     119,   120,   258,   263,   442,    38,   241,    39,   244,   217,
     273,   253,    26,    84,   121,   279,   272,   418,    32,   247,
     267,   269,   422,   122,    37,    38,   275,    39,    56,    57,
     111,   276,   287,   286,   285,    63,   208,   155,   238,   290,
     292,   481,   294,   111,   155,   155,   295,   164,    56,    57,
     311,   489,   338,   354,   315,    63,    64,   366,   357,   362,
     360,   363,   205,   483,   484,   485,   486,    85,   233,   234,
     235,   236,   237,   218,   364,   238,   496,   367,    85,    47,
     401,   365,   373,   500,   434,   457,   452,   413,   477,   378,
     392,   421,   414,   312,   423,   424,   425,     8,   155,   251,
     427,   433,    73,    73,    85,   468,   435,    74,    74,   436,
     490,   437,   448,   450,   487,   458,   459,   515,    26,   498,
     465,    29,   451,   467,   491,   503,    84,    84,   495,   512,
     514,    38,   516,    39,    73,   359,   408,   521,    44,    74,
     155,    47,   524,   369,   525,   527,   533,    71,   314,   538,
     539,   513,   449,   439,    56,    57,   221,   224,    84,   540,
     380,    63,   545,   339,   462,   508,   535,     0,    73,     0,
     111,     0,     0,    74,     0,   390,     0,     0,     0,     0,
     155,     0,     0,    73,     0,     0,     0,     0,    74,   382,
       0,     0,    84,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    84,     0,   238,
       0,     0,   322,   323,     0,     0,     0,    85,    85,   412,
     537,     0,   409,     0,     0,     0,     0,   155,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,    90,   238,   358,     0,     0,   103,     0,    85,
       0,   466,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,    73,    73,    73,    73,     0,    74,
      74,    74,    74,     0,     0,     0,     0,     0,   384,     0,
      73,    73,     0,    85,     0,    74,    74,     0,    84,    84,
      84,    84,     0,     0,     0,    73,    80,     0,    85,     0,
      74,    99,     0,   100,    84,    84,   197,   198,     0,     0,
     201,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,   412,     0,     0,   409,     0,     0,
       0,     0,   155,     0,     0,     0,    73,   410,     0,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,   412,     0,     0,   409,     0,     0,     0,
       0,   155,     0,     0,   443,   444,   445,   446,     0,    85,
      85,    85,    85,     0,     0,     0,     0,   277,     0,     0,
     455,   456,     0,     0,     0,    85,    85,    73,    73,     0,
       0,     0,    74,    74,     0,   463,     0,     0,     0,     0,
      85,     0,     0,     0,     0,    73,     0,     0,     0,    73,
      74,    84,    84,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,     0,   189,   190,     0,    84,
       0,   195,   410,    84,     0,     0,   497,     0,   308,     0,
       0,    85,     0,     0,     0,   291,   293,   100,   100,     0,
     317,   318,   320,   321,     0,     0,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
       0,   410,     0,   341,   345,     0,   308,   349,   351,     0,
       0,     0,     0,     0,     0,     0,     0,   259,     0,   345,
       0,     0,   307,     0,   100,     0,     0,   529,   530,   313,
     345,   100,    85,    85,     0,     0,   345,   345,     0,   376,
     377,     0,     0,     0,     0,   542,   381,   383,     0,     0,
      85,   282,     0,     0,    85,     0,   389,     0,   344,   107,
     100,     0,   350,   112,   100,   114,   116,     0,     0,     0,
       0,   128,     0,   344,     0,   100,     0,   134,   135,   136,
     137,   138,   139,     0,   344,     0,   100,   143,   144,   145,
     344,   344,   100,   100,   149,     0,   301,     0,     0,   345,
     159,   160,   161,     0,   165,     0,     0,     0,     0,   194,
     309,     0,   310,     0,     0,     0,     0,     0,   345,     0,
       0,   420,     0,   345,     0,     0,     0,     0,   426,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   240,     0,   238,     0,     0,     0,     0,     0,
       0,     0,   509,   344,     0,   100,     0,     0,     0,     0,
       0,   453,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   344,     0,   100,   345,     0,   344,   464,   100,
       0,     0,     0,     0,     0,     0,     0,     0,   473,     0,
       0,     0,     0,   478,     0,   479,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,   397,     0,
       0,   345,     0,   493,     0,     0,     0,     0,     0,     0,
     345,     0,   499,     0,     0,     0,     0,   502,     0,   344,
       0,   100,     0,     0,     0,     0,   507,     0,     0,     0,
       0,     0,     0,     0,   407,     0,     0,     0,     0,     0,
       0,     0,   345,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   344,   238,   100,     0,     0,
     526,     0,     0,     0,   344,   528,   100,     0,     0,     0,
     282,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   301,     0,   238,     0,   543,     0,
     399,     0,     0,     0,     0,     0,   344,   400,   100,     0,
       0,     0,     0,   191,     0,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,   -23,   -23,     0,     0,   -23,   -23,   -23,
       0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,
       0,     0,   -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,     0,   -23,
     -23,   -23,   -23,     0,     0,     0,     0,   -23,   -23,   -23,
       0,     0,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   520,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,     0,     0,     0,     0,
       0,     0,     0,   531,     0,     0,   534,     0,     0,     0,
       0,     0,     0,   213,     0,   541,   -56,   -56,   -56,   -56,
     -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
       0,     0,     0,   -56,   -56,     0,     0,   -56,   -56,   -56,
       0,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,     0,
       0,     0,   -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,     0,   -56,
     -56,   -56,   -56,     0,     0,     0,     0,   -56,   -56,   -56,
       0,     0,   -56,   -56,   -56,   -56,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -56,     0,     0,
       0,   -56,     0,     0,   -56,     0,   -56,   -56,     0,     0,
       0,     0,   -56,   -56,     0,   -56,     2,     3,     0,     0,
       4,     5,     6,     7,     8,     9,     0,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,     0,    50,    51,    52,    53,     0,    54,    55,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,    66,     0,     0,    67,    68,
      69,     0,     0,     0,   303,     0,    70,  -156,  -156,  -156,
    -156,  -156,  -156,     0,  -156,  -156,     0,  -156,  -156,  -156,
    -156,     0,     0,     0,  -156,  -156,     0,     0,  -156,  -156,
    -156,     0,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
       0,     0,     0,  -156,  -156,  -156,     0,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,     0,  -156,  -156,     0,
    -156,  -156,  -156,  -156,     0,     0,     0,     0,  -156,  -156,
    -156,     0,     0,  -156,  -156,  -156,  -156,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,  -156,     8,
       9,     0,  -156,     0,     0,  -156,    13,  -156,     0,     0,
       0,     0,    19,  -156,  -156,     0,    23,     0,     0,     0,
      26,     0,     0,    29,     0,     0,    32,     0,     0,     0,
       0,     0,    37,    38,     0,    39,    40,    41,    42,     0,
      44,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   342,    56,    57,     0,     0,
       0,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
      66,     0,     0,     0,     0,    69,     4,     5,     6,     7,
       8,     9,     0,    10,    11,   343,    12,    13,    14,    15,
       0,     0,     0,    19,    20,     0,     0,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,    36,    37,    38,     0,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,     0,    50,
      51,    52,    53,     0,     0,     0,     0,    56,    57,    58,
       0,     0,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,    66,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,    70,     0,     0,   250,     4,     5,     6,     7,
       8,     9,     0,    10,    11,     0,    12,    13,    14,    15,
       0,     0,     0,    19,    20,     0,     0,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,    36,    37,    38,     0,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,     0,    50,
      51,    52,    53,     0,     0,     0,     0,    56,    57,    58,
       0,     0,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,    66,     0,     0,   394,     0,    69,     0,     0,     0,
       0,     0,    70,   395,     4,     5,     6,     7,     8,     9,
       0,    10,    11,     0,    12,    13,    14,    15,     0,     0,
       0,    19,    20,     0,     0,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,     0,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,     0,    50,    51,    52,
      53,     0,     0,     0,     0,    56,    57,    58,     0,     0,
      61,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    66,
       0,     0,   394,     0,    69,     0,     0,     0,     0,     0,
      70,   544,     4,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    12,    13,    14,    15,     0,     0,     0,    19,
      20,     0,     0,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,     0,     0,     0,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,     0,    50,    51,    52,    53,     0,
       0,     0,     0,    56,    57,    58,     0,     0,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,     0,    66,     0,     0,
       0,     0,    69,     0,     0,     0,   217,     0,    70,     4,
       5,     6,     7,     8,     9,     0,    10,    11,     0,    12,
      13,    14,    15,     0,     0,     0,    19,    20,     0,     0,
      23,    24,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,     0,    36,    37,    38,     0,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,     0,    50,    51,    52,    53,     0,     0,     0,     0,
      56,    57,    58,     0,     0,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,    66,     0,     0,     0,     0,    69,
     454,     0,     0,     0,     0,    70,     4,     5,     6,     7,
       8,     9,     0,    10,    11,     0,    12,    13,    14,    15,
       0,     0,     0,    19,    20,     0,     0,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,    36,    37,    38,     0,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,     0,    50,
      51,    52,    53,     0,     0,     0,     0,    56,    57,    58,
       0,     0,    61,    62,    63,    64,     0,     0,     0,     0,
       0,   200,     0,     0,     4,     0,     0,    65,     8,     9,
       0,    66,     0,     0,     0,    13,    69,     0,     0,     0,
       0,    19,    70,     0,     0,    23,     0,     0,     0,    26,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    39,    40,    41,    42,     0,    44,
       0,     0,    47,     0,     0,   340,     0,     0,     4,     0,
       0,     0,     8,     9,     0,    56,    57,     0,     0,    13,
      61,    62,    63,     0,     0,    19,     0,     0,     0,    23,
       0,     0,     0,    26,     0,    65,    29,     0,     0,    66,
       0,     0,     0,     0,    69,     0,    38,     0,    39,    40,
      41,    42,     0,    44,     0,     0,    47,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    56,
      57,   238,     0,     0,    61,    62,    63,     0,     0,     4,
       5,     0,     0,     8,     9,     0,     0,     0,     0,    65,
      13,     0,     0,    66,     0,     0,    19,     0,    69,     0,
      23,     0,     0,     0,    26,     0,     0,    29,     0,     0,
      32,     0,     0,     0,     0,     0,    37,    38,     0,    39,
      40,    41,    42,     0,    44,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
      56,    57,     0,     0,     0,    61,    62,    63,    64,     0,
       4,     5,     0,     0,     8,     9,     0,     0,     0,     0,
      65,    13,     0,     0,    66,     0,     0,    19,     0,    69,
       0,    23,     0,     0,     0,    26,     0,     0,    29,     0,
       0,    32,     0,     0,     0,     0,     0,    37,    38,     0,
      39,    40,    41,    42,     0,    44,     0,     0,    47,     0,
       0,     0,     0,     0,     4,     0,     0,     0,     8,     9,
       0,    56,    57,     0,     0,    13,    61,    62,    63,    64,
       0,    19,     0,     0,     0,    23,     0,     0,     0,    26,
       0,    65,    29,     0,     0,    66,     0,     0,     0,     0,
      69,     0,    38,     0,    39,    40,    41,    42,     0,    44,
       0,     0,    47,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     8,     9,   115,    56,    57,     0,     0,    13,
      61,    62,    63,     0,     0,    19,     0,     0,     0,    23,
       0,     0,     0,    26,     0,    65,    29,     0,     0,    66,
       0,     0,     0,     0,    69,     0,    38,     0,    39,    40,
      41,    42,     0,    44,     0,     0,    47,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     8,     9,   306,    56,
      57,     0,     0,    13,    61,    62,    63,     0,     0,    19,
       0,     0,     0,    23,     0,     0,     0,    26,     0,    65,
      29,     0,     0,    66,     0,     0,     0,     0,    69,     0,
      38,     0,    39,    40,    41,    42,     0,    44,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   167,    56,    57,   168,   169,   170,    61,    62,
      63,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,   173,    65,     0,     0,   174,    66,     0,   175,
       0,     0,    69,     0,     0,   176,     0,     0,   177,   178,
       0,   179,     0,     0,     0,     0,   180,     0,     0,   181,
     182,     0,     0,   183,     0,     0,     0,     0,   184,     0,
       0,   167,   185,   186,   168,   169,   170,   187,   188,     0,
       0,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,   174,     0,     0,   175,     0,
       0,     0,     0,     0,   176,     0,     0,   177,   178,     0,
     179,     0,     0,     0,     0,   180,     0,     0,   181,   182,
       0,     0,   183,     0,     0,     0,     0,   184,     0,     0,
       0,   185,   186,     0,     0,     0,   187,   188,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,     0,   238,     0,     0,     0,     0,     0,   391,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     0,     0,   238,     0,     0,     0,     0,
       0,   438,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     0,     0,   238,     0,     0,
       0,     0,     0,   472,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     0,     0,   238,
       0,     0,     0,     0,     0,   506,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   302,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   353,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   403,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   415,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   440,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   447,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   494,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   501,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   510,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,     0,     0,     0,   517,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,   238,   239,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,     0,   238
};

static const yytype_int16 yycheck[] =
{
       1,   157,     1,   281,   128,     1,     3,   217,    12,    74,
       8,    74,    74,     8,     8,    74,   424,   425,     8,    94,
      24,    25,   300,    74,     1,    94,   448,   435,    94,    98,
      14,    94,    94,    98,    32,    12,   192,    32,   258,    98,
      92,    74,    92,    94,    29,    46,    74,    24,    25,   269,
      46,    49,    17,    18,    49,   275,   276,    42,    52,    44,
      49,    53,   322,   323,    49,   487,    94,    95,    45,    46,
      35,    99,    73,    86,    87,    88,    53,    73,    91,    49,
      65,    66,    52,    84,   294,    53,    96,    72,    84,     8,
      92,    99,   248,    99,    99,    94,    73,    38,   358,    94,
       8,    92,   102,    74,    92,   102,   110,    84,     5,   110,
       1,    92,    29,     8,   110,     1,    92,   241,   338,    94,
      15,    16,    94,   127,   384,    42,    99,    44,    92,    98,
      92,    98,    29,   110,    29,    96,   140,   357,    35,    99,
      99,    94,   362,    38,    41,    42,    94,    44,    65,    66,
     127,    94,   153,    99,    94,    72,    98,   153,    91,   160,
     161,   439,    98,   140,   160,   161,    94,    53,    65,    66,
       8,   449,    94,   103,     8,    72,    73,    95,    94,    94,
      74,    94,    73,   443,   444,   445,   446,    73,    84,    85,
      86,    87,    88,    84,    94,    91,   456,    96,    84,    52,
     103,    94,    94,   463,    74,    13,    74,    95,     3,    99,
      99,    95,    99,   214,    95,    95,    95,     8,   214,   110,
      96,    95,   223,   224,   110,   100,    95,   223,   224,    95,
     450,    95,    99,    94,    99,    95,    94,   497,    29,   459,
      95,    32,   398,    95,    94,    28,   223,   224,    95,    95,
      74,    42,    95,    44,   255,   256,    47,    43,    49,   255,
     256,    52,    99,   267,     3,    95,    99,     1,   215,   529,
     530,   491,   392,   378,    65,    66,    87,    89,   255,   532,
     283,    72,   542,   241,   414,   476,   525,    -1,   289,    -1,
     267,    -1,    -1,   289,    -1,   296,    -1,    -1,    -1,    -1,
     296,    -1,    -1,   304,    -1,    -1,    -1,    -1,   304,   286,
      -1,    -1,   289,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   304,    -1,    91,
      -1,    -1,   223,   224,    -1,    -1,    -1,   223,   224,   343,
     102,    -1,   343,    -1,    -1,    -1,    -1,   343,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,     1,    91,   255,    -1,    -1,     6,    -1,   255,
      -1,    99,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,   386,   387,   388,    -1,   385,
     386,   387,   388,    -1,    -1,    -1,    -1,    -1,   289,    -1,
     401,   402,    -1,   289,    -1,   401,   402,    -1,   385,   386,
     387,   388,    -1,    -1,    -1,   416,     1,    -1,   304,    -1,
     416,     6,    -1,     6,   401,   402,    65,    66,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,   448,    -1,    -1,   448,    -1,    -1,
      -1,    -1,   448,    -1,    -1,    -1,   457,   343,    -1,    -1,
      -1,   457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     457,    -1,    -1,   487,    -1,    -1,   487,    -1,    -1,    -1,
      -1,   487,    -1,    -1,   385,   386,   387,   388,    -1,   385,
     386,   387,   388,    -1,    -1,    -1,    -1,   146,    -1,    -1,
     401,   402,    -1,    -1,    -1,   401,   402,   518,   519,    -1,
      -1,    -1,   518,   519,    -1,   416,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,    -1,   536,    -1,    -1,    -1,   540,
     536,   518,   519,    -1,   540,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    54,    55,    -1,   536,
      -1,    59,   448,   540,    -1,    -1,   457,    -1,   207,    -1,
      -1,   457,    -1,    -1,    -1,   160,   161,   160,   161,    -1,
     219,   220,   221,   222,    -1,    -1,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,   487,    -1,   242,   243,    -1,   245,   246,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,   258,
      -1,    -1,   207,    -1,   207,    -1,    -1,   518,   519,   214,
     269,   214,   518,   519,    -1,    -1,   275,   276,    -1,   278,
     279,    -1,    -1,    -1,    -1,   536,   285,   286,    -1,    -1,
     536,   149,    -1,    -1,   540,    -1,   295,    -1,   243,     8,
     243,    -1,   247,    12,   247,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,   258,    -1,   258,    -1,    26,    27,    28,
      29,    30,    31,    -1,   269,    -1,   269,    36,    37,    38,
     275,   276,   275,   276,    43,    -1,   194,    -1,    -1,   338,
      49,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,    58,
     208,    -1,   210,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,   360,    -1,   362,    -1,    -1,    -1,    -1,   367,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    91,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   338,    -1,   338,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   357,    -1,   357,   414,    -1,   362,   417,   362,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    -1,   432,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,   306,    -1,
      -1,   450,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,
     459,    -1,   461,    -1,    -1,    -1,    -1,   466,    -1,   414,
      -1,   414,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   491,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,   450,    91,   450,    -1,    -1,
     509,    -1,    -1,    -1,   459,   514,   459,    -1,    -1,    -1,
     378,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   392,    -1,    91,    -1,   537,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   491,   102,   491,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,   503,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   521,    -1,    -1,   524,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,   533,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    95,    -1,    -1,
      -1,    -1,   100,   101,    -1,   103,     0,     1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    57,    58,    59,    60,    -1,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,     1,    -1,   100,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    15,    16,
      17,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    85,     8,
       9,    -1,    89,    -1,    -1,    92,    15,    94,    -1,    -1,
      -1,    -1,    21,   100,   101,    -1,    25,    -1,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    94,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,   104,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,   100,    -1,    -1,   103,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    -1,    -1,    -1,
      -1,    -1,   100,   101,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,
      -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    -1,
     100,   101,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,   100,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    14,
      15,    16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,   100,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,     4,    -1,    -1,    85,     8,     9,
      -1,    89,    -1,    -1,    -1,    15,    94,    -1,    -1,    -1,
      -1,    21,   100,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,     1,    -1,    -1,     4,    -1,
      -1,    -1,     8,     9,    -1,    65,    66,    -1,    -1,    15,
      70,    71,    72,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,    85,    32,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    94,    -1,    42,    -1,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    52,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    65,
      66,    91,    -1,    -1,    70,    71,    72,    -1,    -1,     4,
       5,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    85,
      15,    -1,    -1,    89,    -1,    -1,    21,    -1,    94,    -1,
      25,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
       4,     5,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      85,    15,    -1,    -1,    89,    -1,    -1,    21,    -1,    94,
      -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,     8,     9,
      -1,    65,    66,    -1,    -1,    15,    70,    71,    72,    73,
      -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    85,    32,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      94,    -1,    42,    -1,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    -1,     8,     9,    64,    65,    66,    -1,    -1,    15,
      70,    71,    72,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    -1,    85,    32,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    94,    -1,    42,    -1,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    -1,     8,     9,    64,    65,
      66,    -1,    -1,    15,    70,    71,    72,    -1,    -1,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    85,
      32,    -1,    -1,    89,    -1,    -1,    -1,    -1,    94,    -1,
      42,    -1,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     5,    65,    66,     8,     9,    10,    70,    71,
      72,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    85,    -1,    -1,    29,    89,    -1,    32,
      -1,    -1,    94,    -1,    -1,    38,    -1,    -1,    41,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,     5,    65,    66,     8,     9,    10,    70,    71,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    65,    66,    -1,    -1,    -1,    70,    71,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    97,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    97,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    92,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   106,     0,     1,     4,     5,     6,     7,     8,     9,
      11,    12,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    39,    40,    41,    42,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      57,    58,    59,    60,    62,    63,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    85,    89,    92,    93,    94,
     100,   108,   109,   111,   112,   115,   116,   119,   120,   121,
     122,   123,   124,   126,   143,   149,   150,   153,   158,   159,
     163,   164,   165,   169,   176,   187,   108,   111,   112,   122,
     123,   143,   149,   163,   174,     8,   175,   160,    94,   154,
      94,   143,   160,   169,   160,    64,   160,   163,     8,    15,
      16,    29,    38,   181,   200,   181,   181,    94,   160,    92,
      92,   169,   189,   169,   160,   160,   160,   160,   160,   160,
      14,   107,   181,   160,   160,   160,    74,   172,   173,   160,
     144,   143,   145,   146,   111,   112,   143,   151,    53,   160,
     160,   160,    53,   143,   149,   160,     1,     5,     8,     9,
      10,    15,    16,    25,    29,    32,    38,    41,    42,    44,
      49,    52,    53,    56,    61,    65,    66,    70,    71,   201,
     201,     1,   110,    96,   160,   201,     8,   163,   163,    92,
       1,   163,   131,    92,   122,   126,   163,    74,    98,    92,
      99,    99,    92,     1,    74,    99,    92,    98,   126,    74,
      94,   154,    94,   157,   157,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    91,    92,
     160,    99,    74,    94,    92,    74,    94,    99,   170,   163,
     103,   126,   169,    98,    38,   141,   142,   127,    94,   201,
     177,   178,   180,   169,   166,   168,   200,    99,   102,    94,
     125,   201,   169,    92,   179,    94,    94,   163,    74,    96,
     147,   148,   201,   160,   171,    94,    99,   111,   171,   136,
     111,   122,   111,   122,    98,    94,   132,   171,   163,   117,
     118,   201,    95,     1,   162,   161,    64,   122,   163,   201,
     201,     8,   111,   122,   125,     8,   150,   163,   163,   155,
     163,   163,   126,   126,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,    94,   166,
       1,   163,    64,   104,   122,   163,   184,   185,   186,   163,
     122,   163,   171,    95,   103,    95,    99,    94,   126,   111,
      74,   184,    94,    94,    94,    94,    95,    96,   167,   169,
     188,   184,   129,    94,   184,   184,   163,   163,    99,   167,
     173,   163,   143,   163,   126,   139,   137,   140,   138,   163,
     111,    97,    99,   167,    92,   101,   126,   201,   113,    95,
     102,   103,   156,    95,   161,   161,   184,   201,    47,   111,
     149,   152,   169,    95,    99,    95,   133,   134,   184,   161,
     163,    95,   184,    95,    95,    95,   163,    96,     3,   102,
     190,   192,   193,    95,    74,    95,    95,    95,    97,   148,
      95,    94,   161,   126,   126,   126,   126,    95,    99,   118,
      94,   171,    74,   163,    95,   126,   126,    13,    95,    94,
       1,    94,   186,   126,   163,    95,    99,    95,   100,   182,
     182,   182,    97,   163,   194,   195,   191,     3,   163,   163,
     182,   167,   163,   161,   161,   161,   161,    99,   152,   167,
     184,    94,   114,   163,    95,    95,   161,   126,   184,   163,
     161,    95,   163,    28,   196,   197,    97,   163,   192,    99,
      95,   152,    95,   184,    74,   161,    95,    95,   135,   128,
     201,    43,   198,   199,    99,     3,   163,    95,   163,   126,
     126,   201,   183,    99,   201,   194,   130,   102,   161,   161,
     162,   201,   126,   163,   101,   161
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
#line 144 "parse.y"
    { ntab = 0;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 145 "parse.y"
    { return '\n';}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 146 "parse.y"
    { return '\n';}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 148 "parse.y"
    { hoc_ob_check(-1); code2(nopop, STOP); return 1; }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 150 "parse.y"
    { codein(STOP); return 1; }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 152 "parse.y"
    { TPDYNAM; code2(print, STOP); return 1; }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 154 "parse.y"
    { debug(); return '\n';}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 156 "parse.y"
    { return 'e';}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 158 "parse.y"
    {code3(prstr, hoc_newline, STOP); return 1; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 161 "parse.y"
    { return '\n';}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 164 "parse.y"
    { plt(-3,0.,0.); return '\n';}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 165 "parse.y"
    {hoc_help();}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 165 "parse.y"
    { return '\n'; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 167 "parse.y"
    {clean_err(); hoc_execerror("parse error", (char*)0);
#if LINT
if (0) {
if(yydebug);
goto yynewstate;
}
#endif
		}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 177 "parse.y"
    {Symbol *s; TPD; s = spop();
		hoc_obvar_declare(s, VAR, 1);
		code3(varpush, s, assign); codei((yyvsp[(2) - (3)].narg)); PN;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 181 "parse.y"
    {  TPD; defnonly("$"); argcode(argassign, (yyvsp[(1) - (3)].narg)); codei((yyvsp[(2) - (3)].narg)); (yyval.inst)=(yyvsp[(3) - (3)].inst); PN;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 183 "parse.y"
    { TPD; defnonly("$&"); argrefcode(hoc_argrefasgn, (yyvsp[(1) - (4)].narg), (yyvsp[(2) - (4)].narg)); codei((yyvsp[(3) - (4)].narg)); (yyval.inst)=(yyvsp[(4) - (4)].inst); PN;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 186 "parse.y"
    { TPD; code(range_const); codesym(spop()); codei((yyvsp[(2) - (3)].narg)); PN;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 190 "parse.y"
    { Inst* p; hoc_opasgn_invalid((yyvsp[(2) - (7)].narg));
		 code(hoc_newobj); codesym(hoc_which_template((yyvsp[(4) - (7)].sym))); codei((yyvsp[(6) - (7)].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 196 "parse.y"
    {Inst* p; TPDYNAM; code(hoc_object_asgn); codei((yyvsp[(2) - (3)].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 201 "parse.y"
    {myerr("assignment to variable, make sure right side is a number");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 205 "parse.y"
    {pushi(OBJECTVAR);pushs((yyvsp[(1) - (1)].sym)); pushi(CHECK);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 206 "parse.y"
    {(yyval.inst) = (yyvsp[(3) - (3)].inst); code(hoc_objectvar); spop(); codesym((yyvsp[(1) - (3)].sym));}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 208 "parse.y"
    {defnonly("$o"); (yyval.inst) = argcode(hoc_objectarg, (yyvsp[(1) - (1)].narg)); pushi(OBJECTVAR);}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 210 "parse.y"
    {(yyval.inst) = code(hoc_autoobject); codesym((yyvsp[(1) - (1)].sym)); pushi(OBJECTVAR);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 212 "parse.y"
    {TPD; (yyval.inst) = (yyvsp[(3) - (4)].inst); code(hoc_constobject); codesym((yyvsp[(1) - (4)].sym)); pushi(OBJECTVAR);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 214 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 217 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 221 "parse.y"
    { spop(); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 224 "parse.y"
    { pushs((Symbol*)0); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 225 "parse.y"
    {pushs((yyvsp[(3) - (3)].sym));pushi(NOCHECK);}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 226 "parse.y"
    {int isfunc; Inst* p;
		 isfunc = ipop();
		 code(hoc_object_component); codesym(spop()); codei(ipop());
		 codei((yyvsp[(6) - (6)].narg));
		 codei(0); codesym(0);
		 p = codei(isfunc); /* for USE_PYTHON */
		 spop();
		 pushs((Symbol*)p); /* in case assigning to a PythonObject we will want to update isfunc to 2 */
		}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 235 "parse.y"
    {myerr("object syntax is o1.o2.o3.");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 238 "parse.y"
    {(yyval.narg) = 0; pushi(0);}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 240 "parse.y"
    {(yyval.narg) = (yyvsp[(2) - (3)].narg); pushi(1);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 242 "parse.y"
    {hoc_begintemplate((yyvsp[(2) - (2)].sym));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 245 "parse.y"
    {hoc_endtemplate((yyvsp[(2) - (2)].sym));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 246 "parse.y"
    {myerr("begintemplate Name\npublic namelist\nexternal namelist\n...\nendtemplate Name");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 249 "parse.y"
    {(yyval.inst) = (yyvsp[(2) - (3)].inst);}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 252 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(1) - (1)].sym)); codei(0);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 254 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(1) - (2)].sym)); codei((yyvsp[(2) - (2)].narg));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 256 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(3) - (3)].sym)); codei(0);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 258 "parse.y"
    {code(hoc_objvardecl); codesym((yyvsp[(3) - (4)].sym)); codei((yyvsp[(4) - (4)].narg));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 261 "parse.y"
    {
		  Symbol* s;
		  s = hoc_decl((yyvsp[(1) - (1)].sym));
		  if (s->type != UNDEF && s->type != OBJECTVAR) {
			acterror(s->name, " already declared");
		  }
		  (yyval.sym) = s;
		}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 271 "parse.y"
    {hoc_add_publiclist((yyvsp[(2) - (2)].sym));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 273 "parse.y"
    {hoc_add_publiclist((yyvsp[(3) - (3)].sym));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 276 "parse.y"
    {hoc_external_var((yyvsp[(2) - (2)].sym));}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 278 "parse.y"
    {hoc_external_var((yyvsp[(3) - (3)].sym));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 283 "parse.y"
    {hoc_opasgn_invalid((yyvsp[(2) - (3)].narg)); code(assstr);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 285 "parse.y"
    {Inst* p = (Inst*) spop(); pushi(STRING); TPDYNAM; code(hoc_object_asgn);
		 hoc_opasgn_invalid((yyvsp[(2) - (3)].narg)); codei((yyvsp[(2) - (3)].narg)); hoc_ob_check(-1); code(nopop);
		 if (p) { p->i += 2; }
		}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 290 "parse.y"
    {code(hoc_asgn_obj_to_str); hoc_opasgn_invalid((yyvsp[(2) - (3)].narg)); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 291 "parse.y"
    {myerr("string assignment: both sides need to be a string");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 296 "parse.y"
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[(1) - (1)].sym));}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 298 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg));}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 302 "parse.y"
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[(1) - (1)].sym));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 304 "parse.y"
    {defnonly("$s"); (yyval.inst) = argcode(hoc_stringarg, (yyvsp[(1) - (1)].narg));}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 308 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 312 "parse.y"
    {
			Symbol* s = hoc_decl((yyvsp[(1) - (1)].sym));
			if (s->type == UNDEF) {
				hoc_obvar_declare(s, STRING, 0);
				OPSTR(s) = (char**)emalloc(sizeof(char*));
				*OPSTR(s) = 0;
			}else if (s->type != STRING) {
				acterror(s->name, " already declared");
			}
			hoc_assign_str(OPSTR(s), "");
		}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 325 "parse.y"
    { code(nopop); hoc_ob_check(-1); /*don't check*/}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 333 "parse.y"
    { code(nopop); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 335 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst);}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 337 "parse.y"
    { defnonly("return"); (yyval.inst)=(yyvsp[(2) - (2)].inst); code(procret); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 339 "parse.y"
    {  if (indef == 3) {
			TPDYNAM; (yyval.inst) = (yyvsp[(2) - (2)].inst);
			code(hocobjret);
		   }else{
			TPD; defnonly("return"); (yyval.inst)=(yyvsp[(2) - (2)].inst);
			code(funcret);
		   }
		}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 348 "parse.y"
    {(yyval.inst) = code(hoc_newobj_ret); codesym(hoc_which_template((yyvsp[(3) - (6)].sym))); codei((yyvsp[(5) - (6)].narg));
		 code(hocobjret);
		}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 352 "parse.y"
    { if (indef != 2) {
acterror("iterator_statement used outside an iterator declaration", 0);
		  }
			code(hoc_iterator_stmt);
		}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 358 "parse.y"
    { code(Break); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 360 "parse.y"
    { code(Stop); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 362 "parse.y"
    { code(Continue); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 364 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg)); code(nopop); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 366 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); code(hoc_newline); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 368 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst);
		  ((yyvsp[(3) - (5)].inst))[0].i = relative((yyvsp[(4) - (5)].inst), (yyvsp[(3) - (5)].inst), 0); /* body */
		  ((yyvsp[(3) - (5)].inst))[1].i = relative((yyvsp[(5) - (5)].inst), (yyvsp[(3) - (5)].inst), 1); /* exit */
		}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 373 "parse.y"
    {
			((yyvsp[(2) - (6)].inst))[1].i =relative((yyvsp[(5) - (6)].inst), (yyvsp[(2) - (6)].inst), 1);	/* body */
			((yyvsp[(2) - (6)].inst))[2].i =relative((yyvsp[(6) - (6)].inst), (yyvsp[(2) - (6)].inst), 2); /* exit from the for */
			((yyvsp[(2) - (6)].inst))[3].i  =relative((yyvsp[(4) - (6)].inst), (yyvsp[(2) - (6)].inst), 3);	/* increment */
			(yyval.inst) = (yyvsp[(1) - (6)].inst);
#if LINT
if (0){YYERROR;}
#endif
			}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 383 "parse.y"
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 387 "parse.y"
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[(4) - (7)].narg)); 
		    (yyval.inst) = code(shortfor); codei(0); codei(0);}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 390 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (10)].inst); ((yyvsp[(8) - (10)].inst))[1].i = relative((yyvsp[(9) - (10)].inst), (yyvsp[(8) - (10)].inst), 1); /* body */
			   ((yyvsp[(8) - (10)].inst))[2].i = relative((yyvsp[(10) - (10)].inst), (yyvsp[(8) - (10)].inst), 2); /* exit */
		  }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 394 "parse.y"
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 398 "parse.y"
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[(5) - (8)].narg)); 
		     code(hoc_parallel_begin);
		     (yyval.inst) = code(shortfor); codei(0); codei(0);}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 402 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (11)].inst); ((yyvsp[(9) - (11)].inst))[1].i = relative((yyvsp[(10) - (11)].inst), (yyvsp[(9) - (11)].inst), 1); /* body */
			   ((yyvsp[(9) - (11)].inst))[2].i = relative((yyvsp[(11) - (11)].inst), (yyvsp[(9) - (11)].inst), 2); /* exit */
			code(hoc_parallel_end);
		  }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 407 "parse.y"
    {
		((yyvsp[(1) - (4)].inst))[1].i = relative((yyvsp[(3) - (4)].inst), (yyvsp[(1) - (4)].inst), 1);	/* body of loop */
		((yyvsp[(1) - (4)].inst))[2].i = relative((yyvsp[(4) - (4)].inst), (yyvsp[(1) - (4)].inst), 2); }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 411 "parse.y"
    {
		((yyvsp[(1) - (4)].inst))[1].i = relative((yyvsp[(3) - (4)].inst), (yyvsp[(1) - (4)].inst), 1);	/* thenpart */
		((yyvsp[(1) - (4)].inst))[3].i = relative((yyvsp[(4) - (4)].inst), (yyvsp[(1) - (4)].inst), 3); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 415 "parse.y"
    {
		((yyvsp[(1) - (7)].inst))[1].i = relative((yyvsp[(3) - (7)].inst), (yyvsp[(1) - (7)].inst), 1);	/* thenpart */
		((yyvsp[(1) - (7)].inst))[2].i = relative((yyvsp[(6) - (7)].inst), (yyvsp[(1) - (7)].inst), 2);	/* elsepart */
		((yyvsp[(1) - (7)].inst))[3].i = relative((yyvsp[(7) - (7)].inst), (yyvsp[(1) - (7)].inst), 3); }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 420 "parse.y"
    { ntab++;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 422 "parse.y"
    {
		ntab--; (yyval.inst) = (yyvsp[(3) - (4)].inst);
		}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 428 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 430 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (4)].inst); code(connectsection);}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 432 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (7)].inst); code(simpleconnectsection);}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 434 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (7)].inst); code(connectpointer); codesym(spop());}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 435 "parse.y"
    {code(nrn_cppp);}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 436 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); code(connect_point_process_pointer);
			 hoc_ob_check(-1);}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 439 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); code(sec_access);}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 441 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); hoc_ob_check(SECTION); code(sec_access_object);}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 443 "parse.y"
    { (yyval.inst) = Code(mech_access); codesym((yyvsp[(2) - (2)].sym));}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 445 "parse.y"
    { (yyval.inst) = Code(mech_uninsert); codesym((yyvsp[(2) - (2)].sym));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 447 "parse.y"
    { code(sec_access_pop);}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 449 "parse.y"
    { code(sec_access_pop); hoc_ob_check(-1);
			insertcode((yyvsp[(2) - (3)].inst), (yyvsp[(3) - (3)].inst), ob_sec_access);}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 452 "parse.y"
    { TPD; TPD; TPD; TPD; code(range_interpolate); codesym(spop());
		  codei((yyvsp[(7) - (10)].narg));
		}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 456 "parse.y"
    { TPD; TPD; code(range_interpolate_single); codesym(spop());
		  codei((yyvsp[(5) - (6)].narg));
		}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 460 "parse.y"
    {Symbol *s; code(varpush); codesym(s = spop());
		 hoc_obvar_declare(s, VAR, 1);
		 (yyval.inst) = code(for_segment); codei(0); codei(0);}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 464 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (7)].inst); ((yyvsp[(5) - (7)].inst))[1].i = relative((yyvsp[(6) - (7)].inst), (yyvsp[(5) - (7)].inst), 1); /* body */
			((yyvsp[(5) - (7)].inst))[2].i = relative((yyvsp[(7) - (7)].inst), (yyvsp[(5) - (7)].inst), 2); /* exit */
		}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 468 "parse.y"
    {Symbol *s; code(varpush); codesym(s = spop());
		hoc_obvar_declare(s, VAR, 1);}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 471 "parse.y"
    { TPD; (yyval.inst) = code(for_segment1); codei(0); codei(0);}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 473 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (10)].inst); ((yyvsp[(8) - (10)].inst))[1].i = relative((yyvsp[(9) - (10)].inst), (yyvsp[(8) - (10)].inst), 1); /* body */
			((yyvsp[(8) - (10)].inst))[2].i = relative((yyvsp[(10) - (10)].inst), (yyvsp[(8) - (10)].inst), 2); /* exit */
		}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 477 "parse.y"
    {	code(hoc_push_string); codesym((Symbol*)0);
			(yyval.inst) = code(forall_section); codei(0); codei(0);}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 480 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); ((yyvsp[(3) - (5)].inst))[1].i = relative((yyvsp[(4) - (5)].inst), (yyvsp[(3) - (5)].inst), 1); /* body */
			((yyvsp[(3) - (5)].inst))[2].i = relative((yyvsp[(5) - (5)].inst), (yyvsp[(3) - (5)].inst), 2); /* exit */
		}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 484 "parse.y"
    { (yyval.inst) = code(forall_section); codei(0); codei(0);}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 486 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 490 "parse.y"
    { (yyval.inst) = code(hoc_ifsec); codei(0); codei(0);}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 492 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 496 "parse.y"
    {hoc_ob_check(-1);
		(yyval.inst) = code(forall_sectionlist); codei(0); codei(0); }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 499 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 503 "parse.y"
    { hoc_ob_check(-1);
		 (yyval.inst) = code(hoc_ifseclist); codei(0); codei(0);
		}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 508 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (6)].inst); ((yyvsp[(4) - (6)].inst))[1].i = relative((yyvsp[(5) - (6)].inst), (yyvsp[(4) - (6)].inst), 1); /* body */
			((yyvsp[(4) - (6)].inst))[2].i = relative((yyvsp[(6) - (6)].inst), (yyvsp[(4) - (6)].inst), 2); /* exit */
		}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 515 "parse.y"
    {
		  code(hoc_iterator); codesym((yyvsp[(1) - (4)].sym)); codei((yyvsp[(3) - (4)].narg));
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 519 "parse.y"
    {code(hoc_push_current_object);}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 520 "parse.y"
    {codei(ITERATOR);
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 525 "parse.y"
    {pushs((yyvsp[(1) - (1)].sym)); pushi(CHECK);}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 526 "parse.y"
    {code(sec_access_push); codesym(spop()); (yyval.inst) = (yyvsp[(3) - (3)].inst);}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 529 "parse.y"
    {TPD;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 530 "parse.y"
    {(yyval.inst) = progp; code(connect_obsec_syntax);}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 531 "parse.y"
    {
#if 0
		 acterror("Sorry. The \"connect ob.sec...\" syntax ",
			"is not implemented");
#endif
		 hoc_ob_check(SECTION); code(ob_sec_access);
		}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 541 "parse.y"
    { code(add_section); codesym((yyvsp[(1) - (1)].sym)); codei(0);}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 543 "parse.y"
    { code(add_section); codesym((yyvsp[(1) - (2)].sym)); codei((yyvsp[(2) - (2)].narg));}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 545 "parse.y"
    {code(add_section); codesym((yyvsp[(3) - (3)].sym)); codei(0);}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 547 "parse.y"
    { code(add_section); codesym((yyvsp[(3) - (4)].sym)); codei((yyvsp[(4) - (4)].narg));}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 550 "parse.y"
    {
			Symbol* s;
			s = hoc_decl((yyvsp[(1) - (1)].sym));
			if (s->type != UNDEF && s->type != SECTION)
				acterror(s->name, " already declared");
		}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 558 "parse.y"
    { code(sec_access_push); codesym((Symbol *)0);}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 561 "parse.y"
    {pushs((yyvsp[(1) - (1)].sym)); pushi(CHECK);}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 562 "parse.y"
    {(yyval.inst) = (yyvsp[(3) - (3)].inst);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 565 "parse.y"
    { code3(varpush, spop(), hoc_evalpointer);}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 567 "parse.y"
    { TPD; code(rangevarevalpointer); codesym(spop());}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 569 "parse.y"
    {hoc_ipop(); code(hoc_ob_pointer);}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 570 "parse.y"
    {myerr("rangevariable needs explicit arc position,eg. v(.5)");}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 572 "parse.y"
    {(yyval.inst) = argcode(hoc_argrefarg, (yyvsp[(1) - (1)].narg));}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 578 "parse.y"
    { (yyval.inst) = (yyvsp[(3) - (4)].inst);}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 580 "parse.y"
    { (yyval.inst) = progp; }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 583 "parse.y"
    { (yyval.inst) = code(forcode); codei(0); codei(0); codei(0); }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 586 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(1) - (1)].inst); codein(STOP);}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 589 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); code(STOP);}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 591 "parse.y"
    { (yyval.inst) = progp; code(STOP);}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 594 "parse.y"
    { TPD; codein(STOP); (yyval.inst) = (yyvsp[(2) - (3)].inst);}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 597 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 600 "parse.y"
    { (yyval.inst)=code(ifcode); codei(0); codei(0); codei(0); }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 603 "parse.y"
    { (yyval.inst) = progp; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 606 "parse.y"
    { codein(STOP); (yyval.inst) = progp; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 609 "parse.y"
    { (yyval.inst) = progp; prog_error = (yyval.inst); }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 611 "parse.y"
    {
			prog_parse_recover = progp;
			prog_error = (yyval.inst);
			if (fin == stdin && !pipeflag)
			{	int i;
				Printf(">");
				for (i = 0; i < ntab; i++)
					Printf("	");
			}
		}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 623 "parse.y"
    {myerr("syntax error in compound statement");}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 628 "parse.y"
    { (yyval.inst) = code(constpush); codesym((yyvsp[(1) - (1)].sym)); PN;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 630 "parse.y"
    { (yyval.inst) = code(pushzero); PN;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 632 "parse.y"
    { code3(varpush, spop(), eval); PN;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 634 "parse.y"
    { defnonly("$"); (yyval.inst) = argcode(arg, (yyvsp[(1) - (1)].narg)); PN;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 636 "parse.y"
    { defnonly("$&"); (yyval.inst) = argrefcode(hoc_argref, (yyvsp[(1) - (2)].narg), (yyvsp[(2) - (2)].narg)); PN;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 639 "parse.y"
    {code(rangepoint); codesym(spop()); PN;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 641 "parse.y"
    { TPD; code(rangevareval); codesym(spop()); PN;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 645 "parse.y"
    {code(hoc_object_eval);}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 649 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); code(call); codesym((yyvsp[(1) - (5)].sym)); codei((yyvsp[(4) - (5)].narg)); PN;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 651 "parse.y"
    { code(call); codesym(spop()); codei((yyvsp[(3) - (4)].narg)); PN;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 653 "parse.y"
    { (yyval.inst)=(yyvsp[(3) - (4)].inst); code(varread); codesym(spop()); PN;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 655 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(3) - (4)].inst); code(bltin); codesym((yyvsp[(1) - (4)].sym)); PN;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 657 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (3)].inst); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 659 "parse.y"
    {myerr("syntax error in expression");}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 661 "parse.y"
    { TPD; TPD; code(add); PN; }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 663 "parse.y"
    { TPD; TPD;code(sub); PN;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 665 "parse.y"
    { TPD; TPD; code(mul); PN;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 667 "parse.y"
    { TPD; TPD; code(hoc_div); PN;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 669 "parse.y"
    { TPD; TPD; code(hoc_cyclic); PN;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 671 "parse.y"
    { TPD; TPD; code(power); PN;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 673 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (2)].inst); code(negate); PN;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 675 "parse.y"
    { TPD; TPD; code(gt); PN;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 677 "parse.y"
    { TPD; TPD; code(ge); PN;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 679 "parse.y"
    { TPD; TPD; code(lt); PN;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 681 "parse.y"
    { TPD; TPD; code(le); PN;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 683 "parse.y"
    { hoc_ob_check(-1); hoc_ob_check(-1); code(eq); PN;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 685 "parse.y"
    { hoc_ob_check(-1); hoc_ob_check(-1); code(ne); PN;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 687 "parse.y"
    { TPD; TPD; code(hoc_and); PN;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 689 "parse.y"
    { TPD; TPD; code(hoc_or); PN;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 691 "parse.y"
    { TPD; (yyval.inst) = (yyvsp[(2) - (2)].inst); code(hoc_not); PN;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 699 "parse.y"
    {Symbol *s; code(varpush); codesym(s=spop()); (yyval.inst) = (yyvsp[(2) - (3)].inst);
		code(arayinstal); codei((yyvsp[(3) - (3)].narg)); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 702 "parse.y"
    {Symbol *s; code(varpush); codesym(s = spop());
		code(arayinstal); codei((yyvsp[(3) - (3)].narg)); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 707 "parse.y"
    {pushs((yyvsp[(1) - (2)].sym)); (yyval.narg) = (yyvsp[(2) - (2)].narg);}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 710 "parse.y"
    {  TPD; (yyval.narg) = 1; }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 712 "parse.y"
    {  TPD;(yyval.narg) = (yyval.narg) + 1; }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 718 "parse.y"
    { pushs((yyvsp[(1) - (2)].sym)); (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 720 "parse.y"
    { if ((yyvsp[(1) - (2)].sym)->subtype == USERPROPERTY) {
			code(sec_access_push); codesym((Symbol *)0);
		  }
		pushs((yyvsp[(1) - (2)].sym)); pushi(CHECK);
		}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 725 "parse.y"
    {(yyval.inst) = (yyvsp[(2) - (4)].inst);}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 727 "parse.y"
    { if ((yyvsp[(3) - (3)].sym)->subtype != USERPROPERTY) {
			acterror((yyvsp[(3) - (3)].sym)->name, "not a section variable");
		  }
		(yyval.inst) = (yyvsp[(1) - (3)].inst); pushs((yyvsp[(3) - (3)].sym));
		}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 741 "parse.y"
    {
		int d1, chk;
		Symbol *sym;
		d1 = ipop();
		chk = ipop();
		sym = spop();
   if (chk) {
	if (!ISARRAY(sym)) {
		if (d1)
			acterror(sym->name, "not an array variable");
	}else{
		if ( d1 == 0 ) { /*fake index list with all 0's*/
			int i;
			for (i=0; i<sym->arayinfo->nsub; i++) {
				code(pushzero);
			}
		}			
		else if ( d1 != sym->arayinfo->nsub) {
			acterror("wrong # of subscripts",sym->name);
		}
	}
   }else {
	pushi(d1); /* must check dynamically */
   }
		pushs(sym);
		}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 770 "parse.y"
    {
			(yyval.narg) = ipop();
		}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 776 "parse.y"
    { pushi(0); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 778 "parse.y"
    {  TPD;pushi(ipop() + 1); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 782 "parse.y"
    { TPDYNAM; code(prexpr);}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 784 "parse.y"
    { code(prstr); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 786 "parse.y"
    { TPDYNAM; code(prexpr);}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 788 "parse.y"
    { code(prstr); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 791 "parse.y"
    { (yyval.inst) = code(hoc_delete_symbol); codesym((yyvsp[(1) - (1)].sym)); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 795 "parse.y"
    {(yyvsp[(2) - (2)].sym)->type=FUNCTION; indef=1; }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 797 "parse.y"
    { code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto=(yyvsp[(6) - (6)].narg); indef=0; }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 801 "parse.y"
    { (yyvsp[(2) - (2)].sym)->type=PROCEDURE; indef=1; }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 803 "parse.y"
    { code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto=(yyvsp[(6) - (6)].narg); indef=0; }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 807 "parse.y"
    { (yyvsp[(2) - (2)].sym)->type = ITERATOR; indef=2; }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 809 "parse.y"
    {code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto = (yyvsp[(6) - (6)].narg); indef = 0; }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 813 "parse.y"
    { (yyvsp[(2) - (2)].sym)->type=HOCOBJFUNCTION; indef=3; }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 815 "parse.y"
    { code(procret); hoc_define((yyvsp[(2) - (6)].sym));
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nobjauto = (yyvsp[(6) - (6)].narg) - localcnt;
		 (yyvsp[(2) - (6)].sym)->u.u_proc->nauto=(yyvsp[(6) - (6)].narg); indef=0; }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 820 "parse.y"
    { Symbol *s; s=yylval.sym;
		if(s->type != UNDEF) acterror(s->name, "already defined");
		s->u.u_proc = (Proc *)emalloc(sizeof(Proc));
		s->u.u_proc->defn.in = STOP;
		s->u.u_proc->list = (Symlist *)0; }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 830 "parse.y"
    {ntab++;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 831 "parse.y"
    {
		ntab--;
		(yyval.narg) = (yyvsp[(2) - (6)].narg) + (yyvsp[(3) - (6)].narg);
		}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 837 "parse.y"
    { (yyval.narg) = 0; }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 841 "parse.y"
    {(yyval.narg) = 1;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 843 "parse.y"
    {(yyval.narg) = (yyvsp[(1) - (3)].narg) + 1;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 846 "parse.y"
    {}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 848 "parse.y"
    { hoc_ob_check(-1);}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 851 "parse.y"
    {
		 code(hoc_newobj_arg); codesym(hoc_which_template((yyvsp[(2) - (5)].sym))); codei((yyvsp[(4) - (5)].narg));
		}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 856 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (2)].inst); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 858 "parse.y"
    {code3(varpush, spop(), eqn_name);
		do_equation = 1; }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 861 "parse.y"
    { (yyval.inst) = (yyvsp[(2) - (5)].inst); do_equation = 0; }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 864 "parse.y"
    {Symbol *s; code3(varpush,s= spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 866 "parse.y"
    {Symbol *s; code3(varpush, s=spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 871 "parse.y"
    { code(eqn_init); }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 875 "parse.y"
    { code(eqn_lhs); }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 877 "parse.y"
    { codein(STOP); TPD; }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 880 "parse.y"
    { code(eqn_rhs); }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 882 "parse.y"
    { codein(STOP); TPD; }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 885 "parse.y"
    { (yyval.narg) = 0; localcnt = (yyval.narg);}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 889 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = 1; localcnt = (yyval.narg);
		sp = install((yyvsp[(2) - (2)].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 896 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; localcnt = (yyval.narg);
		if (hoc_table_lookup((yyvsp[(3) - (3)].sym)->name, p_symlist)) {
			acterror((yyvsp[(3) - (3)].sym)->name, "already declared local");
		}
		sp = install((yyvsp[(3) - (3)].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 907 "parse.y"
    { (yyval.narg) = 0;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 911 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = 1;
		if (hoc_table_lookup((yyvsp[(2) - (2)].sym)->name, p_symlist)) {
			acterror((yyvsp[(2) - (2)].sym)->name, "already declared local");
		}
		sp = install((yyvsp[(2) - (2)].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 921 "parse.y"
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[(1) - (3)].narg) + 1;
		if (hoc_table_lookup((yyvsp[(3) - (3)].sym)->name, p_symlist)) {
			acterror((yyvsp[(3) - (3)].sym)->name, "already declared local");
		}
		sp = install((yyvsp[(3) - (3)].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 932 "parse.y"
    {  Symbol* s;
	   s = hoc_decl((yyvsp[(1) - (1)].sym));
	   if (s->subtype != NOTUSER)
		acterror("can't redeclare user variable", s->name);
	   (yyval.sym) = s;
	}
    break;



/* Line 1455 of yacc.c  */
#line 4394 "parse.c"
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
#line 944 "parse.y"

	/* end of grammar */

yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	execerror(s, (char *)0);
}

acterror(s, t)	/* recover from action error while parsing */
	char *s, *t;
{
	execerror(s,t);
}

static Inst* argrefcode(pfri, i, j) Pfri pfri; int i, j; {
	Inst* in;
	in = argcode(pfri, i);
	codei(j);
	return in;
}

static Inst* argcode(pfri, i)
	Pfri pfri;
	int i;
{
	Inst* in;
	if (i == 0) {
		Symbol* si = hoc_lookup("i");
		if (si->type != AUTO) {
			acterror("arg index used and i is not a LOCAL variable", 0);
		}
		in = code3(varpush, si, eval);		
		Code(pfri);
		codei(0);
	}else{
		in = Code(pfri);
		codei(i);
	}
	return in;
}

hoc_opasgn_invalid(op) int op; {
        if (op) {
                acterror("Invalid assignment operator.", "Only '=' allowed. ");
        }
} 


