/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_NUM = 258,                  /* TK_NUM  */
    TK_STR = 259,                  /* TK_STR  */
    TK_REAL = 260,                 /* TK_REAL  */
    TK_CHAR = 261,                 /* TK_CHAR  */
    TK_STRING = 262,               /* TK_STRING  */
    TK_BOOL = 263,                 /* TK_BOOL  */
    TK_MAIN = 264,                 /* TK_MAIN  */
    TK_ID = 265,                   /* TK_ID  */
    TK_TIPO_INT = 266,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 267,           /* TK_TIPO_FLOAT  */
    TK_TIPO_CHAR = 268,            /* TK_TIPO_CHAR  */
    TK_TIPO_BOOL = 269,            /* TK_TIPO_BOOL  */
    TK_CONV = 270,                 /* TK_CONV  */
    TK_MAIOR_IGUAL = 271,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 272,          /* TK_MENOR_IGUAL  */
    TK_MAIOR = 273,                /* TK_MAIOR  */
    TK_MENOR = 274,                /* TK_MENOR  */
    TK_IGUALDADE = 275,            /* TK_IGUALDADE  */
    TK_DESIGUALDADE = 276,         /* TK_DESIGUALDADE  */
    TK_CONJUNCAO = 277,            /* TK_CONJUNCAO  */
    TK_DISNJUNCAO = 278,           /* TK_DISNJUNCAO  */
    TK_ALT = 279,                  /* TK_ALT  */
    TK_IF = 280,                   /* TK_IF  */
    TK_ELSE = 281,                 /* TK_ELSE  */
    TK_DO = 282,                   /* TK_DO  */
    TK_WHILE = 283,                /* TK_WHILE  */
    TK_FOR = 284,                  /* TK_FOR  */
    TK_SWITCH = 285,               /* TK_SWITCH  */
    TK_FIM = 286,                  /* TK_FIM  */
    TK_ERROR = 287                 /* TK_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_NUM 258
#define TK_STR 259
#define TK_REAL 260
#define TK_CHAR 261
#define TK_STRING 262
#define TK_BOOL 263
#define TK_MAIN 264
#define TK_ID 265
#define TK_TIPO_INT 266
#define TK_TIPO_FLOAT 267
#define TK_TIPO_CHAR 268
#define TK_TIPO_BOOL 269
#define TK_CONV 270
#define TK_MAIOR_IGUAL 271
#define TK_MENOR_IGUAL 272
#define TK_MAIOR 273
#define TK_MENOR 274
#define TK_IGUALDADE 275
#define TK_DESIGUALDADE 276
#define TK_CONJUNCAO 277
#define TK_DISNJUNCAO 278
#define TK_ALT 279
#define TK_IF 280
#define TK_ELSE 281
#define TK_DO 282
#define TK_WHILE 283
#define TK_FOR 284
#define TK_SWITCH 285
#define TK_FIM 286
#define TK_ERROR 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
