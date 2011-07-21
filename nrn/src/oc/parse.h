
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 90 "parse.y"
				/* stack type */
	Symbol	*sym;			/* symbol table pointer */
	Inst	*inst;			/* machine instruction */
	int	narg;			/* number of arguments */



/* Line 1676 of yacc.c  */
#line 228 "parse.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


