/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintaticoP.y"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <muParser.h>
#define bool int
#define TRUE 1
#define FALSE 0
#define LACO 1
#define BLOCO 0
#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;
string Tipagens;
int qtd_simb;
int qtd_tabelas;
int qtd_laco;


struct escopo{
	string label;
	int tipo;
};

struct tabelaSimbolos{
	string nome;
	string tipo;
	string classe;
	string endereco;
	string tam;
	string dim;
	int mod;
	string val;
};
struct atributos
{
	string label;
	string traducao;
	string tipo;
	string classe;
	string val;
	string tam;
};

std::vector <atributos> listaattr;
std::vector<atributos>ref_switch;
std::vector <tabelaSimbolos> listaSimb;
std::vector <escopo> infobloco;
std::vector<vector<tabelaSimbolos>>listaEscopo;

int yylex(void);
void yyerror(string);
string gentempcode(string tipo);
string gentemplabel();
string imprimirFree();
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso, string tamanho, string nDim);
tabelaSimbolos buscarSimbolos(string nome);
atributos funcString(atributos e1, string operador, atributos e2);
atributos buscaEnd(string nome);
escopo buscarbloco(int k);
void modatrib(string nome, string tam);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
void limparpilha();

bool traducao(string op);

#line 144 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    TK_REAL = 259,                 /* TK_REAL  */
    TK_CHAR = 260,                 /* TK_CHAR  */
    TK_STRING = 261,               /* TK_STRING  */
    TK_BOOL = 262,                 /* TK_BOOL  */
    TK_MAIN = 263,                 /* TK_MAIN  */
    TK_ID = 264,                   /* TK_ID  */
    TK_TIPO_INT = 265,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 266,           /* TK_TIPO_FLOAT  */
    TK_TIPO_STRING = 267,          /* TK_TIPO_STRING  */
    TK_GLOBAL = 268,               /* TK_GLOBAL  */
    TK_LOCAL = 269,                /* TK_LOCAL  */
    TK_TIPO_CHAR = 270,            /* TK_TIPO_CHAR  */
    TK_TIPO_BOOL = 271,            /* TK_TIPO_BOOL  */
    TK_CONV = 272,                 /* TK_CONV  */
    TK_MAIOR_IGUAL = 273,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 274,          /* TK_MENOR_IGUAL  */
    TK_MAIOR = 275,                /* TK_MAIOR  */
    TK_MENOR = 276,                /* TK_MENOR  */
    TK_IGUALDADE = 277,            /* TK_IGUALDADE  */
    TK_DESIGUALDADE = 278,         /* TK_DESIGUALDADE  */
    TK_CONJUNCAO = 279,            /* TK_CONJUNCAO  */
    TK_DISNJUNCAO = 280,           /* TK_DISNJUNCAO  */
    TK_ALT = 281,                  /* TK_ALT  */
    TK_START = 282,                /* TK_START  */
    TK_SCANNER = 283,              /* TK_SCANNER  */
    TK_PRINT = 284,                /* TK_PRINT  */
    TK_IF = 285,                   /* TK_IF  */
    TK_ELSE = 286,                 /* TK_ELSE  */
    TK_DO = 287,                   /* TK_DO  */
    TK_WHILE = 288,                /* TK_WHILE  */
    TK_FOR = 289,                  /* TK_FOR  */
    TK_SWITCH = 290,               /* TK_SWITCH  */
    TK_CASE = 291,                 /* TK_CASE  */
    TK_DEFAULT = 292,              /* TK_DEFAULT  */
    TK_BREAK = 293,                /* TK_BREAK  */
    TK_NEXT = 294,                 /* TK_NEXT  */
    TK_FIM = 295,                  /* TK_FIM  */
    TK_ERROR = 296                 /* TK_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_STRING 261
#define TK_BOOL 262
#define TK_MAIN 263
#define TK_ID 264
#define TK_TIPO_INT 265
#define TK_TIPO_FLOAT 266
#define TK_TIPO_STRING 267
#define TK_GLOBAL 268
#define TK_LOCAL 269
#define TK_TIPO_CHAR 270
#define TK_TIPO_BOOL 271
#define TK_CONV 272
#define TK_MAIOR_IGUAL 273
#define TK_MENOR_IGUAL 274
#define TK_MAIOR 275
#define TK_MENOR 276
#define TK_IGUALDADE 277
#define TK_DESIGUALDADE 278
#define TK_CONJUNCAO 279
#define TK_DISNJUNCAO 280
#define TK_ALT 281
#define TK_START 282
#define TK_SCANNER 283
#define TK_PRINT 284
#define TK_IF 285
#define TK_ELSE 286
#define TK_DO 287
#define TK_WHILE 288
#define TK_FOR 289
#define TK_SWITCH 290
#define TK_CASE 291
#define TK_DEFAULT 292
#define TK_BREAK 293
#define TK_NEXT 294
#define TK_FIM 295
#define TK_ERROR 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_NUM = 3,                     /* TK_NUM  */
  YYSYMBOL_TK_REAL = 4,                    /* TK_REAL  */
  YYSYMBOL_TK_CHAR = 5,                    /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 6,                  /* TK_STRING  */
  YYSYMBOL_TK_BOOL = 7,                    /* TK_BOOL  */
  YYSYMBOL_TK_MAIN = 8,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 9,                      /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 10,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 11,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_STRING = 12,            /* TK_TIPO_STRING  */
  YYSYMBOL_TK_GLOBAL = 13,                 /* TK_GLOBAL  */
  YYSYMBOL_TK_LOCAL = 14,                  /* TK_LOCAL  */
  YYSYMBOL_TK_TIPO_CHAR = 15,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_BOOL = 16,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_CONV = 17,                   /* TK_CONV  */
  YYSYMBOL_TK_MAIOR_IGUAL = 18,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 19,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_MAIOR = 20,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MENOR = 21,                  /* TK_MENOR  */
  YYSYMBOL_TK_IGUALDADE = 22,              /* TK_IGUALDADE  */
  YYSYMBOL_TK_DESIGUALDADE = 23,           /* TK_DESIGUALDADE  */
  YYSYMBOL_TK_CONJUNCAO = 24,              /* TK_CONJUNCAO  */
  YYSYMBOL_TK_DISNJUNCAO = 25,             /* TK_DISNJUNCAO  */
  YYSYMBOL_TK_ALT = 26,                    /* TK_ALT  */
  YYSYMBOL_TK_START = 27,                  /* TK_START  */
  YYSYMBOL_TK_SCANNER = 28,                /* TK_SCANNER  */
  YYSYMBOL_TK_PRINT = 29,                  /* TK_PRINT  */
  YYSYMBOL_TK_IF = 30,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 31,                   /* TK_ELSE  */
  YYSYMBOL_TK_DO = 32,                     /* TK_DO  */
  YYSYMBOL_TK_WHILE = 33,                  /* TK_WHILE  */
  YYSYMBOL_TK_FOR = 34,                    /* TK_FOR  */
  YYSYMBOL_TK_SWITCH = 35,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 36,                   /* TK_CASE  */
  YYSYMBOL_TK_DEFAULT = 37,                /* TK_DEFAULT  */
  YYSYMBOL_TK_BREAK = 38,                  /* TK_BREAK  */
  YYSYMBOL_TK_NEXT = 39,                   /* TK_NEXT  */
  YYSYMBOL_TK_FIM = 40,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 41,                  /* TK_ERROR  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_47_ = 47,                       /* '^'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_53_ = 53,                       /* '['  */
  YYSYMBOL_54_ = 54,                       /* ']'  */
  YYSYMBOL_55_ = 55,                       /* '!'  */
  YYSYMBOL_56_ = 56,                       /* '='  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_S = 58,                         /* S  */
  YYSYMBOL_CODS = 59,                      /* CODS  */
  YYSYMBOL_COD = 60,                       /* COD  */
  YYSYMBOL_BLOCO = 61,                     /* BLOCO  */
  YYSYMBOL_INIT = 62,                      /* INIT  */
  YYSYMBOL_INIB = 63,                      /* INIB  */
  YYSYMBOL_COMANDOS = 64,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 65,                   /* COMANDO  */
  YYSYMBOL_LISTA_ID = 66,                  /* LISTA_ID  */
  YYSYMBOL_MODO = 67,                      /* MODO  */
  YYSYMBOL_REF_ARRAY = 68,                 /* REF_ARRAY  */
  YYSYMBOL_CONTROLES = 69,                 /* CONTROLES  */
  YYSYMBOL_REF = 70,                       /* REF  */
  YYSYMBOL_CASES = 71,                     /* CASES  */
  YYSYMBOL_CASE = 72,                      /* CASE  */
  YYSYMBOL_E = 73,                         /* E  */
  YYSYMBOL_ATB = 74,                       /* ATB  */
  YYSYMBOL_ID_F = 75,                      /* ID_F  */
  YYSYMBOL_C_LOOP = 76                     /* C_LOOP  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   581

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    46,     2,     2,
      48,    49,    44,    42,    52,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,    56,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   129,   134,   138,   142,   150,   164,   178,
     192,   197,   202,   206,   210,   214,   218,   222,   226,   230,
     249,   258,   299,   307,   311,   315,   319,   324,   327,   339,
     350,   365,   383,   405,   426,   450,   465,   472,   477,   481,
     506,   514,   630,   680,   730,   780,   831,   882,   894,   900,
     939,   977,  1015,  1053,  1088,  1123,  1140,  1158,  1174,  1189,
    1202,  1216,  1225,  1229,  1233,  1243,  1251,  1259,  1266,  1279,
    1284,  1291,  1354,  1394,  1417,  1447,  1454
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_REAL",
  "TK_CHAR", "TK_STRING", "TK_BOOL", "TK_MAIN", "TK_ID", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_STRING", "TK_GLOBAL", "TK_LOCAL",
  "TK_TIPO_CHAR", "TK_TIPO_BOOL", "TK_CONV", "TK_MAIOR_IGUAL",
  "TK_MENOR_IGUAL", "TK_MAIOR", "TK_MENOR", "TK_IGUALDADE",
  "TK_DESIGUALDADE", "TK_CONJUNCAO", "TK_DISNJUNCAO", "TK_ALT", "TK_START",
  "TK_SCANNER", "TK_PRINT", "TK_IF", "TK_ELSE", "TK_DO", "TK_WHILE",
  "TK_FOR", "TK_SWITCH", "TK_CASE", "TK_DEFAULT", "TK_BREAK", "TK_NEXT",
  "TK_FIM", "TK_ERROR", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('",
  "')'", "'}'", "';'", "','", "'['", "']'", "'!'", "'='", "$accept", "S",
  "CODS", "COD", "BLOCO", "INIT", "INIB", "COMANDOS", "COMANDO",
  "LISTA_ID", "MODO", "REF_ARRAY", "CONTROLES", "REF", "CASES", "CASE",
  "E", "ATB", "ID_F", "C_LOOP", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     146,  -135,  -135,  -135,  -135,  -135,   -27,    32,    52,    52,
      52,    52,  -135,   -42,   -37,   240,    -2,   240,   -21,   240,
    -135,  -135,   240,    73,   240,    34,  -135,   146,  -135,   193,
    -135,   297,  -135,  -135,  -135,   240,   240,    -8,    10,  -135,
    -135,    58,    58,    58,    58,    58,    61,   240,   425,  -135,
     193,   455,    65,    -2,   465,    -9,    26,    42,    43,   375,
     465,  -135,  -135,    52,  -135,   240,   240,   240,   240,   240,
     240,   240,   240,  -135,   240,   240,   240,   240,   240,   240,
    -135,   247,   465,   240,    45,    29,   -20,    -4,    44,    46,
      47,    50,   384,  -135,    54,   193,    51,   193,   -27,    49,
      36,   240,   240,   240,  -135,   534,   534,   534,   534,   504,
     504,   495,   465,    -9,    -9,   -25,   -25,   -25,    70,    53,
     465,    75,    58,  -135,    56,  -135,    57,  -135,  -135,  -135,
      59,    62,    75,    55,    71,    64,    -8,   240,   240,    75,
      67,    36,   465,   465,   465,   240,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,   240,  -135,   331,   425,   193,  -135,
    -135,   284,   341,   240,   193,  -135,  -135,  -135,   416,  -135,
      -2,   193,    68,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    64,    65,    66,    68,    67,    73,    27,    27,    27,
      27,    27,    70,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,     0,     2,     4,     6,    11,
      13,     0,    62,    69,    63,     0,     0,    74,     0,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      11,     0,     0,     0,    36,    47,     0,     0,     0,     0,
      57,     1,     3,    27,    10,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
      12,     0,    71,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     8,    30,    11,     0,    11,     0,     0,
      38,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    41,    42,    43,    44,    45,    46,    28,
      72,     0,     0,    14,     0,    15,     0,    18,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    59,    60,    61,     0,     5,    23,    19,    20,
      21,    22,    31,     7,     0,    32,     0,     0,    11,    35,
      37,     0,     0,     0,    11,    40,    29,    33,     0,    39,
       0,    11,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,    76,  -135,   -93,  -134,   -41,   -26,  -135,   -29,
      33,   -68,  -135,  -135,   -32,  -135,   -15,    63,  -135,  -135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    94,    95,    50,    28,    29,    86,
      41,    37,    30,    53,   140,   141,    31,    32,    33,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    73,    51,    64,    54,   158,    46,    55,    59,    60,
      97,    47,   100,    87,    88,    89,    90,    73,   124,   126,
      81,    82,    79,   164,    96,    49,    35,    52,   146,    36,
     136,   123,    92,    35,    61,    76,    77,    78,    79,   152,
      38,    42,    43,    44,    45,    39,    40,   125,    83,    35,
     105,   106,   107,   108,   109,   110,   111,   112,    84,   113,
     114,   115,   116,   117,   118,    39,    40,    85,   120,   133,
      91,   135,   138,   139,    98,   101,     1,     2,     3,     4,
       5,   122,     6,    56,    57,   132,   142,   143,   144,    58,
      12,   102,   103,   147,   121,   127,    73,   128,   129,   130,
     137,   134,    93,    62,   154,   153,   145,   148,   149,   160,
     150,    20,    21,   151,   155,    99,    22,   159,   173,     0,
       0,    23,   156,   157,     0,     0,     0,     0,    24,   171,
     161,     0,   165,     0,     0,     0,     0,     0,   169,   162,
       0,     0,     0,     0,     0,   172,     0,     0,   168,     1,
       2,     3,     4,     5,     0,     6,     7,     8,     9,     0,
       0,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,     0,    16,    17,
      18,    19,     0,     0,    20,    21,     0,     0,     0,    22,
       0,     0,     0,     0,    23,     0,     1,     2,     3,     4,
       5,    24,     6,    63,     8,     9,     0,     0,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,    16,    17,    18,    19,     0,
       0,    20,    21,     0,     0,     0,    22,     0,     0,     0,
       0,    23,     0,     1,     2,     3,     4,     5,    24,     6,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,    20,    21,
       0,     0,     0,    22,     0,     0,     0,     0,    23,    74,
      75,    76,    77,    78,    79,    24,     0,     0,     0,     0,
       0,   119,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,     0,     0,     0,   166,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    80,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,   163,    74,    75,    76,    77,    78,    79,     0,
       0,     0,   167,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,   104,     0,    74,    75,    76,    77,
      78,    79,     0,   131,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    93,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,     0,   170,     0,    74,    75,    76,
      77,    78,    79,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    49,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    65,    66,    67,    68,    69,    70,    71,
       0,    73,    65,    66,    67,    68,    69,    70,     0,     0,
      73,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    65,    66,    67,    68,     0,     0,     0,     0,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79
};

static const yytype_int16 yycheck[] =
{
      15,    26,    17,    29,    19,   139,    48,    22,    23,    24,
      51,    48,    53,    42,    43,    44,    45,    26,    86,    87,
      35,    36,    47,   157,    50,    27,    53,    48,   121,    56,
      98,    51,    47,    53,     0,    44,    45,    46,    47,   132,
       8,     8,     9,    10,    11,    13,    14,    51,    56,    53,
      65,    66,    67,    68,    69,    70,    71,    72,    48,    74,
      75,    76,    77,    78,    79,    13,    14,     9,    83,    95,
       9,    97,    36,    37,     9,    49,     3,     4,     5,     6,
       7,    52,     9,    10,    11,    31,   101,   102,   103,    16,
      17,    49,    49,   122,    49,    51,    26,    51,    51,    49,
      51,    50,    27,    27,    33,    50,    53,    51,    51,   141,
      51,    38,    39,    51,    50,    52,    43,    50,    50,    -1,
      -1,    48,   137,   138,    -1,    -1,    -1,    -1,    55,   170,
     145,    -1,   158,    -1,    -1,    -1,    -1,    -1,   164,   154,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,   163,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    -1,    32,    33,
      34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    -1,     3,     4,     5,     6,
       7,    55,     9,    10,    11,    12,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    -1,    32,    33,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    -1,     3,     4,     5,     6,     7,    55,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    42,
      43,    44,    45,    46,    47,    55,    -1,    -1,    -1,    -1,
      -1,    54,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    42,    43,    44,    45,
      46,    47,    -1,    49,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    42,    43,    44,
      45,    46,    47,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      15,    16,    17,    28,    29,    30,    32,    33,    34,    35,
      38,    39,    43,    48,    55,    58,    59,    60,    64,    65,
      69,    73,    74,    75,    76,    53,    56,    68,     8,    13,
      14,    67,    67,    67,    67,    67,    48,    48,    73,    27,
      63,    73,    48,    70,    73,    73,    10,    11,    16,    73,
      73,     0,    59,    10,    64,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    42,    43,    44,    45,    46,    47,
      51,    73,    73,    56,    48,     9,    66,    66,    66,    66,
      66,     9,    73,    27,    61,    62,    64,    63,     9,    74,
      63,    49,    49,    49,    49,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    54,
      73,    49,    52,    51,    68,    51,    68,    51,    51,    51,
      49,    49,    31,    64,    50,    64,    68,    51,    36,    37,
      71,    72,    73,    73,    73,    53,    61,    66,    51,    51,
      51,    51,    61,    50,    33,    50,    73,    73,    62,    50,
      71,    73,    73,    51,    62,    64,    54,    51,    73,    64,
      49,    63,    64,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    62,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     1,     3,     1,     1,
       2,     0,     2,     1,     4,     4,     4,     4,     4,     5,
       5,     5,     5,     3,     1,     1,     1,     0,     3,     6,
       3,     5,     5,     7,    11,     5,     1,     2,     0,     4,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     1,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* S: CODS  */
#line 99 "sintaticoP.y"
                        {
				int i;
				string codigo = "/*Compilador FOCA*/\n"
								"#include <iostream>\n"
								"#include<string.h>\n"
								"#include<stdio.h>\n"
								"#define TRUE 1\n"
								"#define FALSE 0\n"
								"#define bool int\n"
								"int main(void) {\n";	
				for(i=0; i<listaattr.size(); i++){
					if(listaattr[i].tipo.compare("string") == 0){
						listaattr[i].tipo = "char*";
					}
					codigo += "\t" + listaattr[i].tipo +" "+ listaattr[i].label + ";\n";
				};
				codigo+= "\n";
				codigo += yyvsp[0].traducao + "\n";
								
				codigo += 	"\treturn 0;"
							"\n}";
				
				cout << codigo << endl;

				limparpilha();

				//checarlista();
			}
#line 1547 "y.tab.c"
    break;

  case 3: /* CODS: COD CODS  */
#line 130 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1555 "y.tab.c"
    break;

  case 4: /* CODS: %empty  */
#line 134 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 1563 "y.tab.c"
    break;

  case 5: /* COD: TK_TIPO_INT TK_MAIN '(' ')' BLOCO  */
#line 139 "sintaticoP.y"
            {
				yyval.traducao = yyvsp[0].traducao;
            }
#line 1571 "y.tab.c"
    break;

  case 6: /* COD: COMANDOS  */
#line 143 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao + imprimirFree();
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, vazio " << listaEscopo.size() << endl;
			}
#line 1582 "y.tab.c"
    break;

  case 7: /* BLOCO: INIT COMANDOS '}'  */
#line 151 "sintaticoP.y"
                        {
				cout << listaEscopo.size();
				/*std::vector<tabelaSimbolos>v1;
				listaEscopo.push_back(v1);
				qtd_tabelas++;
				cout << "quantidade de escopo: "<<  qtd_tabelas << endl;*/
				yyval.traducao = yyvsp[-1].traducao + imprimirFree();
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo " << listaEscopo.size() << endl;
			}
#line 1598 "y.tab.c"
    break;

  case 8: /* INIT: TK_START  */
#line 165 "sintaticoP.y"
                        {
				cout << "cheguei" << endl;
				vector<tabelaSimbolos> v1;
				escopo x; 
				x.label = "";
				x.tipo = BLOCO;
				
				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				cout << " tamanho inicio de escopo " << listaEscopo.size() << endl;
			}
#line 1614 "y.tab.c"
    break;

  case 9: /* INIB: TK_START  */
#line 179 "sintaticoP.y"
                        {
				escopo x;
				vector<tabelaSimbolos> v1;
				x.label = gentemplabel();
				x.tipo = LACO;

				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				cout<< "bloco laço, tamanho pilha "<< listaEscopo.size() << endl;
			}
#line 1629 "y.tab.c"
    break;

  case 10: /* COMANDOS: COMANDO COMANDOS  */
#line 193 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1637 "y.tab.c"
    break;

  case 11: /* COMANDOS: %empty  */
#line 197 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 1645 "y.tab.c"
    break;

  case 12: /* COMANDO: E ';'  */
#line 203 "sintaticoP.y"
                        {
				yyval = yyvsp[-1];
			}
#line 1653 "y.tab.c"
    break;

  case 13: /* COMANDO: CONTROLES  */
#line 207 "sintaticoP.y"
                        {
				yyval = yyvsp[0];
			}
#line 1661 "y.tab.c"
    break;

  case 14: /* COMANDO: TK_TIPO_INT MODO LISTA_ID ';'  */
#line 211 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "int", "Number", yyvsp[-2].label, "0", "0");
			}
#line 1669 "y.tab.c"
    break;

  case 15: /* COMANDO: TK_TIPO_FLOAT MODO LISTA_ID ';'  */
#line 215 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "float", "Number", yyvsp[-2].label, "0","0");
			}
#line 1677 "y.tab.c"
    break;

  case 16: /* COMANDO: TK_TIPO_CHAR MODO LISTA_ID ';'  */
#line 219 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "char", "String", yyvsp[-2].label, "0", "0");
			}
#line 1685 "y.tab.c"
    break;

  case 17: /* COMANDO: TK_TIPO_BOOL MODO LISTA_ID ';'  */
#line 223 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "bool", "Boolean", yyvsp[-2].label, "0", "0");
			}
#line 1693 "y.tab.c"
    break;

  case 18: /* COMANDO: TK_TIPO_STRING MODO LISTA_ID ';'  */
#line 227 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "string", "String", yyvsp[-2].label, "0", "0");
			}
#line 1701 "y.tab.c"
    break;

  case 19: /* COMANDO: TK_TIPO_INT MODO LISTA_ID REF_ARRAY ';'  */
#line 231 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				string l1;
				if(yyvsp[-1].tipo.compare("int") != 0){
					yyerror("Tipo incompativel para declarar tamanho");
				}
				inserirSimbolos(yyvsp[-2].label, "int", "Number", yyvsp[-3].label, yyvsp[-1].label, yyvsp[-1].val);
				flag = buscarSimbolos(yyvsp[-2].label);
				l1 = gentempcode("int");

				if(yyvsp[-1].val.compare("0") == 0){
				yyval.traducao = yyvsp[-1].traducao + "\t" + l1 + " = (int*) malloc(" + yyvsp[-1].label+ ");\n" +"\t" +flag.endereco+ "[0] = " +l1+";\n"; 
				}else{
					yyval.traducao = yyvsp[-1].traducao + "\t" + l1 + " = (int*) malloc(" +yyvsp[-1].val+ "*" + yyvsp[-1].label+  ");\n" +"\t" +flag.endereco+ "[0] = " +l1+";\n"; 
				}


			}
#line 1724 "y.tab.c"
    break;

  case 20: /* COMANDO: TK_TIPO_FLOAT MODO LISTA_ID REF_ARRAY ';'  */
#line 250 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				string l1;
				inserirSimbolos(yyvsp[-2].label, "float", "Number", yyvsp[-3].label, yyvsp[-1].label, yyvsp[-1].val);
				flag = buscarSimbolos(yyvsp[-2].label);
				l1 = gentempcode("float");
				yyval.traducao = yyvsp[-1].traducao + "\t" + l1 + " = (float*) malloc(" + yyvsp[-1].label+ ");\n" +"\t" +flag.endereco+ "[0] = " +l1+";\n";
			}
#line 1737 "y.tab.c"
    break;

  case 21: /* COMANDO: TK_SCANNER '(' TK_ID ')' ';'  */
#line 258 "sintaticoP.y"
                                                 {
				tabelaSimbolos flag;
				flag=buscarSimbolos(yyvsp[-2].label);
				yyval.label=flag.nome;
				yyval.tipo=flag.tipo;
				if(flag.tipo.compare("string")==0 && flag.tam.compare("0") !=0){
					yyval.traducao="\tfree("+flag.endereco+")\n\tcin>>"+flag.endereco+";\n";
				}else{
					yyval.traducao="\tcin>>"+flag.endereco+";\n";
				}
				if(flag.tipo.compare("string")==0){
				  string cout=gentempcode("int");
				  string temp=gentempcode("int");
				  string varChar=gentempcode("char");
				  string e1=gentempcode("char");
				  string e2=gentempcode("char");
				  string rel=gentempcode("bool");
				  string relneg=gentempcode("bool");

				  modatrib(cout, "0");
				  modatrib(temp, "0");
				  modatrib(varChar, "1");
				  modatrib(e1, "1");
				  modatrib(e2, "1");
				  modatrib(rel, "0");
				  modatrib(relneg, "0");

				  yyval.traducao= yyval.traducao+"\t"+cout+" = 0;\n\t"+
				  varChar+" = "+flag.endereco+"["+cout+"];\n\tInicio_"+rel+":\n"
				  +"\t"+e1+" = "+varChar+";\n\t"+e2+" = '\\0';\n"+
				  "\t"+rel+" = "+e1+" != "+e2+";\n"+
				  "\t"+relneg+" = !"+rel+";\n"+
				  "\tIF("+relneg+") Goto Fim "+rel+";\n\t"+
				  temp+" = "+cout+";\n\t"+cout+" = "+temp+" + 1;\n\t"+
				  varChar+" = "+flag.endereco+"["+cout+"];\n"
				 +"\tGoto Inicio_"+rel+";\n\tFim "+rel+":\n";
				 flag.tam = cout;
				 alterarSimbolos(flag);
				}	

			}
#line 1783 "y.tab.c"
    break;

  case 22: /* COMANDO: TK_PRINT '(' E ')' ';'  */
#line 299 "sintaticoP.y"
                                           {
				yyval.traducao=yyvsp[-2].traducao+"\tcout<<"+yyvsp[-2].label+"<<endl;\n";
				if(yyvsp[-2].tipo.compare("string")==0){
				 yyval.traducao=yyval.traducao+"\tfree("+yyvsp[-2].label+");\n";
				}
			}
#line 1794 "y.tab.c"
    break;

  case 23: /* LISTA_ID: TK_ID ',' LISTA_ID  */
#line 308 "sintaticoP.y"
                        {
				yyval.label = yyvsp[-2].label;
			}
#line 1802 "y.tab.c"
    break;

  case 24: /* LISTA_ID: TK_ID  */
#line 312 "sintaticoP.y"
                        {
				yyval.label = yyvsp[0].label;
			}
#line 1810 "y.tab.c"
    break;

  case 25: /* MODO: TK_GLOBAL  */
#line 316 "sintaticoP.y"
                        {
				yyval.label = "global";
			}
#line 1818 "y.tab.c"
    break;

  case 26: /* MODO: TK_LOCAL  */
#line 320 "sintaticoP.y"
                        {
				yyval.label = "local";
			}
#line 1826 "y.tab.c"
    break;

  case 27: /* MODO: %empty  */
#line 324 "sintaticoP.y"
                        {
				yyval.label = "global";
			}
#line 1834 "y.tab.c"
    break;

  case 28: /* REF_ARRAY: '[' E ']'  */
#line 328 "sintaticoP.y"
            {
				if(yyvsp[-1].tipo.compare("int") == 0){
				yyval.label = yyvsp[-1].label;
				yyval.tipo = yyvsp[-1].tipo;
				yyval.val = "0";
				yyval.traducao = yyvsp[-1].traducao;
				}else{
					yyerror("Tipo incompativel para declaração de tamanho ");
				}

			}
#line 1850 "y.tab.c"
    break;

  case 29: /* REF_ARRAY: '[' E ']' '[' E ']'  */
#line 340 "sintaticoP.y"
                        {
				if(yyvsp[-4].tipo.compare("int") == 0 &&  yyvsp[-1].tipo.compare("int") == 0){
					yyval.label = yyvsp[-1].label;
				    yyval.tipo = yyvsp[-4].tipo;
					yyval.val = yyvsp[-4].label;
					yyval.traducao = yyvsp[-4].traducao + yyvsp[-1].traducao;
				}else{
					yyerror("Tipo incompativel para declaração de tamanho ");
				}
			}
#line 1865 "y.tab.c"
    break;

  case 30: /* CONTROLES: TK_IF E BLOCO  */
#line 351 "sintaticoP.y"
                        {
				string jp;
				atributos tst;
				if(yyvsp[-1].tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				tst.traducao = "\t"+tst.label + " = " +"!"+ yyvsp[-1].label+";\n";
				jp = yyvsp[-1].traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+tst.label+";\n";

				yyval.traducao = jp + yyvsp[0].traducao +"\tIF-"+ tst.label + ";\n";


			}
#line 1884 "y.tab.c"
    break;

  case 31: /* CONTROLES: TK_IF E BLOCO TK_ELSE BLOCO  */
#line 366 "sintaticoP.y"
                        {
				string jp, finif;
				atributos tst;
				atributos tfin;
				if(yyvsp[-3].tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				tst.traducao = "\t"+tst.label + " = " +"!"+ yyvsp[-3].label+";\n";
				jp = yyvsp[-3].traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+tst.label+";\n";
				
				tfin.label = gentempcode("bool");
				tfin.traducao = "\tgo to Else-" + tfin.label +";\n";
				
				yyval.traducao = jp + yyvsp[-2].traducao + tfin.traducao +"\tIF-"+ tst.label +";\n" +  yyvsp[0].traducao +"\tElse-" + tfin.label +";\n";

			}
#line 1906 "y.tab.c"
    break;

  case 32: /* CONTROLES: TK_WHILE E INIB COMANDOS '}'  */
#line 384 "sintaticoP.y"
                        {
				string jp, ciclowhile, iniwhile;
				atributos tst;
				escopo laco;
				if(yyvsp[-3].tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				laco = buscarbloco(1);
				tst.traducao = "\t"+tst.label + " = " +"!"+ yyvsp[-3].label+";\n";

				iniwhile = "\tinicio_"+laco.label+";\n" ;
				jp =  iniwhile +yyvsp[-3].traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";
				ciclowhile = "\tgo to inicio_"+laco.label +";\n";
				yyval.traducao = jp + yyvsp[-1].traducao + ciclowhile + "\tFIM "+laco.label+";\n";
				yyval.traducao += imprimirFree();
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, while" << listaEscopo.size() << endl;
				
			}
#line 1932 "y.tab.c"
    break;

  case 33: /* CONTROLES: TK_DO INIB COMANDOS '}' TK_WHILE E ';'  */
#line 406 "sintaticoP.y"
                        {
				string jp, ciclowhile, iniwhile;
				atributos tst;
				escopo laco;
				if(yyvsp[-1].tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				laco = buscarbloco(1);
				iniwhile = "\tinicio_"+laco.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ yyvsp[-1].label+";\n";
				jp = iniwhile +yyvsp[-4].traducao + imprimirFree()+ yyvsp[-1].traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				yyval.traducao = jp + ciclowhile + "\tFIM "+laco.label+";\n";

				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, Do while" << listaEscopo.size() << endl;
			}
#line 1957 "y.tab.c"
    break;

  case 34: /* CONTROLES: TK_FOR '(' ATB ';' E ';' E ')' INIB COMANDOS '}'  */
#line 427 "sintaticoP.y"
                        {
				escopo laco;
				atributos tst;
				string jp, E1, atrib, cicloI, cicloF;
				if(yyvsp[-8].classe.compare("Number") != 0 and yyvsp[-6].classe.compare("Boolean") != 0){
					yyerror("Atribuição incorreta para essa operação");
				}
				
				tst.label = gentempcode("bool");
				laco = buscarbloco(1);
				cicloI = "\tinicio_"+laco.label +";\n";
				

				tst.traducao = "\t"+tst.label + " = " +"!"+ yyvsp[-6].label+";\n";
				cicloF = "\tgo to inicio_"+laco.label +";\n";
				jp = yyvsp[-8].traducao + cicloI+ yyvsp[-6].traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";

				yyval.traducao = jp + yyvsp[-1].traducao + imprimirFree()+ yyvsp[-4].traducao + cicloF +"\tFIM "+ laco.label + ";\n";
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, for" << listaEscopo.size() << endl;

			}
#line 1985 "y.tab.c"
    break;

  case 35: /* CONTROLES: TK_SWITCH REF INIB CASES '}'  */
#line 451 "sintaticoP.y"
                        {
				string fim;
			 	escopo laco;

				laco = buscarbloco(1);
				fim = "\tFIM " + laco.label + ";\n";
				yyval.traducao = yyvsp[-3].traducao + yyvsp[-1].traducao + imprimirFree() +fim;

				listaEscopo.pop_back();
				infobloco.pop_back();
				ref_switch.clear();
			}
#line 2002 "y.tab.c"
    break;

  case 36: /* REF: E  */
#line 466 "sintaticoP.y"
                        {
				atributos x;
				x.label = yyvsp[0].label;
				ref_switch.push_back(x);
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2013 "y.tab.c"
    break;

  case 37: /* CASES: CASE CASES  */
#line 473 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 2021 "y.tab.c"
    break;

  case 38: /* CASES: %empty  */
#line 477 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 2029 "y.tab.c"
    break;

  case 39: /* CASE: TK_CASE E INIT COMANDOS  */
#line 482 "sintaticoP.y"
                        {
				escopo laco;
				atributos tst, comp, ref;
				int cont;
				string inicio, jp; 

				comp.label = gentempcode("bool");
				tst.label = gentempcode("bool");
				cont = ref_switch.size() -1;
				ref = ref_switch[cont];

				laco = buscarbloco(1);
			
				comp.traducao = "\t" + comp.label + " = " + ref.label +" == "+ yyvsp[-2].label +";\n";
				
				tst.traducao = "\t"+tst.label + " = " +"!"+ comp.label+";\n";

				jp = yyvsp[-2].traducao + comp.traducao + tst.traducao+"\tif("+ tst.label+") go to IF-"+tst.label+";\n";
				
				yyval.traducao = jp + yyvsp[0].traducao +"\tIF-"+ tst.label +";\n";
				listaEscopo.pop_back();
				infobloco.pop_back();

			}
#line 2058 "y.tab.c"
    break;

  case 40: /* CASE: TK_DEFAULT INIT COMANDOS  */
#line 507 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
				listaEscopo.pop_back();
				infobloco.pop_back();
				
			}
#line 2069 "y.tab.c"
    break;

  case 41: /* E: E '+' E  */
#line 515 "sintaticoP.y"
                        {
				int r1;
				int result;
				float r2;

				if((yyvsp[-2].tipo.compare("string") == 0||yyvsp[-2].tipo.compare("char") == 0 )&&(yyvsp[0].tipo.compare("string") == 0||yyvsp[0].tipo.compare("char") == 0)){
					atributos resultado = funcString(yyvsp[-2], "+", yyvsp[0]);
					yyval.label = gentempcode(resultado.tipo);
					yyval.tipo = resultado.tipo;
					atributos temp1=buscaEnd(yyvsp[-2].label);
					atributos temp2=buscaEnd(yyvsp[0].label);
					atributos temp3=buscaEnd(resultado.label);
					string label4=gentempcode("int");
					string label5=gentempcode("int");

					cout << "traducao de $2" << yyvsp[-1].traducao << endl;
					cout << "traducao de soma" << resultado.traducao << endl;

					if(temp1.tipo.compare("char") == 0 && temp2.tipo.compare("char") == 0){
						string vetor2= gentempcode("string");
						string labelx2=gentempcode("int");

						yyval.traducao=resultado.traducao+"\t"+labelx2+" =  2;\n\t"+vetor2+"= (char*)malloc("+labelx2+");\n\t"+vetor2+"[0] = "+yyvsp[-2].label+";\n";

						yyval.traducao += "\t"+label4+" = "+labelx2+"- 1;\n\t"+
						label5+"="+temp3.tam+"+"+label4+";\n";
						modatrib(yyval.label, label5);
						yyval.traducao += "\t"+yyval.label+" = (char*) malloc("+label5+");\n"+
					"\t"+yyval.label+" = strcat("+resultado.label+","+vetor2+");\n"+"\tfree("+vetor2+");\n";
					}
					else if(temp1.tipo.compare("char")==0){
						yyval.traducao = resultado.traducao+"\t"+label4+" = "+temp2.tam+"- 1;\n\t"+
						label5+"="+temp3.tam+"+"+label4+";\n";
						modatrib(yyval.label, label5);
						yyval.traducao = yyval.traducao+ "\t"+yyval.label+" = (char*) malloc("+label5+");\n"+
					"\t"+yyval.label+" = strcat("+resultado.label+","+yyvsp[0].label+");\n"+"\tfree("+yyvsp[0].label+");\n";
					}else{
						yyval.traducao = resultado.traducao+"\t"+label4+" = "+temp3.tam+"- 1;\n\t"+
						label5+"="+temp1.tam+"+"+label4+";\n";
						modatrib(yyval.label, label5);

						yyval.traducao += "\t"+yyval.label+" = (char*) malloc("+label5+");\n"+
						"\t"+yyval.label+" = strcat("+yyvsp[-2].label+","+resultado.label+");\n"+"\tfree("+resultado.label+");\n";
					}
					// $$.traducao = elemento.traducao+
					// "\t"+label4+"="+temp2.tam+"- 1;\n\t"+
					// label5+"="+temp1.tam+"+"+temp2.tam+";\n";

					// insereTabela($$.label,$$.tipo,true,"",label5);
					// $$.traducao = $$.traducao+ "\t"+$$.label+"= (char*) malloc("+label5+");\n"
					// +"\t"+$$.label+" = strcat("+$1.label+","+$3.label+") ;\n"+"\tfree("+$3.label+");\n"; 
				}
				else if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0 ){
					atributos conv;
					int x;
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n"; 
						yyvsp[-2].tipo = "float";
						x = 0;

					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n"; 
						yyvsp[0].tipo = "float";
						x = 1;

					}else if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("char") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + " = " + "(int) " + yyvsp[0].label + ";\n"; 
						yyvsp[0].tipo = "int";
						x = 1;

					}else if(yyvsp[-2].tipo.compare("char") == 0 && yyvsp[0].tipo.compare("int") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + "=" + "(int) " + yyvsp[-2].label + ";\n"; 
						yyvsp[-2].tipo = "int";
						x = 0;
						
					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
					
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " + " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " + " + conv.label + ";\n";
					}

				}
				else{
					if(yyvsp[-2].tipo.compare("bool")==0){
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
				
				
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
				}
				yyval.val = yyvsp[-2].val + "+" + yyvsp[0].val;
				
				/*parser.SetExpr($$.val);
				result = parser.Eval();
				cout << "conta" << $$.val << " = "<< result << endl;*/
				
			}
#line 2189 "y.tab.c"
    break;

  case 42: /* E: E '-' E  */
#line 631 "sintaticoP.y"
                        {
				int r1;
				float r2;
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0 ){
					atributos conv;
					int x;
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n"; 
						yyvsp[-2].tipo = "float";
						x = 0;

					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n"; 
						yyvsp[0].tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
					
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " - " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " - " + conv.label + ";\n";
					}

				}
				else{
					if(yyvsp[-2].tipo.compare("bool")==0 || yyvsp[-2].tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
				
				
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
				}
				
			}
#line 2243 "y.tab.c"
    break;

  case 43: /* E: E '*' E  */
#line 681 "sintaticoP.y"
                        {
				int r1;
				float r2;
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0 ){
					atributos conv;
					int x;
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n"; 
						yyvsp[-2].tipo = "float";
						x = 0;

					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n"; 
						yyvsp[0].tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
					
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " * " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " * " + conv.label + ";\n";
					}

				}
				else{
					if(yyvsp[-2].tipo.compare("bool")==0 || yyvsp[-2].tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
				
				
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
				}
				
			}
#line 2297 "y.tab.c"
    break;

  case 44: /* E: E '/' E  */
#line 731 "sintaticoP.y"
                        {
				int r1;
				float r2;
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0 ){
					atributos conv;
					int x;
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n"; 
						yyvsp[-2].tipo = "float";
						x = 0;

					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n"; 
						yyvsp[0].tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
					
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " / " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " / " + conv.label + ";\n";
					}

				}
				else{
					if(yyvsp[-2].tipo.compare("bool")==0 || yyvsp[-2].tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
				
				
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
				}
				
			}
#line 2351 "y.tab.c"
    break;

  case 45: /* E: E '%' E  */
#line 781 "sintaticoP.y"
                        {
				int r1;
				float r2;
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0 ){
					atributos conv;
					int x;
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + " = " + "(int) " + yyvsp[-2].label + ";\n"; 
						yyvsp[-2].tipo = "float";
						x = 0;

					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						conv.label = gentempcode("int");
						conv.traducao = "\t" + conv.label + " = " + "(int) " + yyvsp[0].label + ";\n"; 
						yyvsp[0].tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
					
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " % " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " % " + conv.label + ";\n";
					}

				}
				else{
					if(yyvsp[-2].tipo.compare("bool")==0 || yyvsp[-2].tipo.compare("char") == 0 || yyvsp[-2].tipo.compare("float") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
				
				
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " % " + yyvsp[0].label + ";\n";
				}
				
			}
#line 2406 "y.tab.c"
    break;

  case 46: /* E: E '^' E  */
#line 832 "sintaticoP.y"
                        {
				int r1;
				float r2;
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0 ){
					atributos conv;
					int x;
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n"; 
						yyvsp[-2].tipo = "float";
						x = 0;

					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n"; 
						yyvsp[0].tipo = "float";
						x = 1;

					}else{
						yyerror("Tipos incompativeis para essa operação");
					}
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
					
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " ^ " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " ^ " + conv.label + ";\n";
					}

				}
				else{
					if(yyvsp[-2].tipo.compare("bool")==0 || yyvsp[-2].tipo.compare("char") == 0){
						yyerror("Tipos incompativeis para essa operação");
					}
					
					yyval.label = gentempcode(yyvsp[-2].tipo);
					yyval.tipo = yyvsp[-2].tipo;
					yyval.classe = yyvsp[-2].classe;
				
				
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " ^ " + yyvsp[0].label + ";\n";
				}
				
			}
#line 2461 "y.tab.c"
    break;

  case 47: /* E: '-' E  */
#line 883 "sintaticoP.y"
                        {
				if(yyvsp[0].tipo.compare("int") == 0 or yyvsp[0].tipo.compare("float") == 0){
					yyval.label = gentempcode(yyvsp[0].tipo);
					yyval.tipo = yyvsp[0].tipo;
					yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + 
							" = " + "-" + yyvsp[0].label + ";\n";

				}else{
					yyerror("Tipo da expressão é incompativel para essa operação");
				}
			}
#line 2477 "y.tab.c"
    break;

  case 48: /* E: '(' E ')'  */
#line 895 "sintaticoP.y"
                        {
				yyval.label = yyvsp[-1].label;
				yyval.tipo = yyvsp[-1].tipo;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label +";\n";
			}
#line 2487 "y.tab.c"
    break;

  case 49: /* E: E TK_MAIOR_IGUAL E  */
#line 901 "sintaticoP.y"
                        {
				bool x;
				atributos conv; 
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0){
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n";
					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " >= " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " >= " + conv.label + ";\n";
					}
				}else{
					if(yyvsp[-2].traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
				}
				
			}
#line 2530 "y.tab.c"
    break;

  case 50: /* E: E TK_MENOR_IGUAL E  */
#line 940 "sintaticoP.y"
                        {
				bool x;
				atributos conv; 
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0){
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n";
					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " <= " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " <= " + conv.label + ";\n";
					}
				}else{
					if(yyvsp[-2].traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
				}
			}
#line 2572 "y.tab.c"
    break;

  case 51: /* E: E TK_MAIOR E  */
#line 978 "sintaticoP.y"
                        {
				bool x;
				atributos conv; 
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0){
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n";
					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " > " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " > " + conv.label + ";\n";
					}
				}else{
					if(yyvsp[-2].traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
				}
			}
#line 2614 "y.tab.c"
    break;

  case 52: /* E: E TK_MENOR E  */
#line 1016 "sintaticoP.y"
                        {
				bool x;
				atributos conv; 
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0){
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n";
					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " < " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " < " + conv.label + ";\n";
					}
				}else{
					if(yyvsp[-2].traducao.compare("bool") == 0){
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
				}
			}
#line 2656 "y.tab.c"
    break;

  case 53: /* E: E TK_IGUALDADE E  */
#line 1054 "sintaticoP.y"
                        {
				bool x;
				atributos conv; 
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0){
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[-2].label + ";\n";
					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + " = " + "(float) " + yyvsp[0].label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " == " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " == " + conv.label + ";\n";
					}
				}else{
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
				}
			}
#line 2695 "y.tab.c"
    break;

  case 54: /* E: E TK_DESIGUALDADE E  */
#line 1089 "sintaticoP.y"
                        {
				bool x;
				atributos conv; 
				if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) != 0){
					if(yyvsp[-2].tipo.compare("int") == 0 && yyvsp[0].tipo.compare("float") == 0){
						x = 1;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + "=" + "(float) " + yyvsp[-2].label + ";\n";
					}else if(yyvsp[-2].tipo.compare("float") == 0 && yyvsp[0].tipo.compare("int") == 0){
						x = 0;
						conv.label = gentempcode("float");
						conv.traducao = "\t" + conv.label + "=" + "(float) " + yyvsp[0].label + ";\n";
					}else{
						yyerror("Tipo incompativel para operações lógicas");
					}
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					
					if(x == 0){
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + conv.label + " != " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + conv.traducao +"\t" + yyval.label + 
							" = " + yyvsp[-2].label + " != " + conv.label + ";\n";
					}
				}else{
					yyval.label = gentempcode("bool");
					yyval.tipo = "bool";
					yyval.classe = "Boolean";
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
				}
			}
#line 2734 "y.tab.c"
    break;

  case 55: /* E: E TK_CONJUNCAO E  */
#line 1124 "sintaticoP.y"
                        {
				bool x;
				if(yyvsp[-2].tipo.compare("bool") == 0 && yyvsp[0].tipo.compare("bool") == 0){
					x = traducao(yyvsp[-2].val) && traducao(yyvsp[0].val);
				}else{
					yyerror("Tipos incompativeis para essa operação");
				}

				yyval.val = yyvsp[-2].label +" && " + yyvsp[0].label;
				yyval.label = gentempcode("bool");
				yyval.tipo = "bool";
				yyval.classe = "Boolean";

				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
			}
#line 2755 "y.tab.c"
    break;

  case 56: /* E: E TK_DISNJUNCAO E  */
#line 1141 "sintaticoP.y"
                        {
				bool x;
				if(yyvsp[-2].tipo.compare("bool") == 0 && yyvsp[0].tipo.compare("bool") == 0){
					x = traducao(yyvsp[-2].val) || traducao(yyvsp[0].val);
				}else{
					yyerror("Tipos incompativeis para essa operação");
				}


				yyval.val = yyvsp[-2].label +" || " + yyvsp[0].label;
				yyval.label = gentempcode("bool");
				yyval.tipo = "bool";
				yyval.classe = "Boolean";

				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + 
						" = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
			}
#line 2777 "y.tab.c"
    break;

  case 57: /* E: '!' E  */
#line 1159 "sintaticoP.y"
                        {
				bool x;
				if(yyvsp[0].tipo.compare("bool") == 0){
					x = !traducao(yyvsp[0].val);
				}else{
					yyerror("Tipo incompativeis para essa operação");
				}
				yyval.val = "!" +yyvsp[0].label;
				yyval.label = gentempcode("bool");
				yyval.tipo = "bool";
				yyval.classe = "Boolean";

				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + 
						" = " +"!"+ yyvsp[0].label + ";\n";
			}
#line 2797 "y.tab.c"
    break;

  case 58: /* E: E TK_ALT  */
#line 1175 "sintaticoP.y"
                        {
				string x;
				if(yyvsp[-1].classe.compare("Number") != 0){
					yyerror("Tipo incompativeis para essa operação");
				}
				yyval.label = yyvsp[-1].label;
				cout << "incremento da var"<< yyval.label <<endl;
				yyval.tipo = yyvsp[-1].tipo;
				yyval.classe = yyvsp[-1].classe;

				yyvsp[-1].tipo.compare("int") == 0 ?  x = "1" : x = "1.0000";
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label + " "+ yyvsp[0].label[0] + " "+ x +";\n";
				
			}
#line 2816 "y.tab.c"
    break;

  case 59: /* E: '(' TK_TIPO_INT ')' E  */
#line 1190 "sintaticoP.y"
                        {
				int conv;
				if(yyvsp[0].tipo.compare("int") == 0 || yyvsp[0].tipo.compare("float") == 0){
					yyval.label = gentempcode("int");
					yyval.tipo = "int";
					conv = stoi(yyvsp[0].val);
					yyval.val = to_string(conv);
					yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = " + "(int) " + yyvsp[0].label + ";\n"; 
				}else{
					yyerror("Tipo de expressão incompativel para a conversão");
				}
			}
#line 2833 "y.tab.c"
    break;

  case 60: /* E: '(' TK_TIPO_FLOAT ')' E  */
#line 1203 "sintaticoP.y"
                        {
				float conv;
				if(yyvsp[0].tipo.compare("int") == 0 || yyvsp[0].tipo.compare("float") == 0){
					yyval.label = gentempcode("int");
					yyval.tipo = "float";
					conv = stof(yyvsp[0].val);
					yyval.val = to_string(conv);
					yyval.traducao =  yyvsp[0].traducao +"\t" + yyval.label + " = " + "(float) " + yyvsp[0].label+";\n"; 
				}else{
					yyerror("Tipo de expressão incompativel para a conversão");
				}

			}
#line 2851 "y.tab.c"
    break;

  case 61: /* E: '(' TK_TIPO_BOOL ')' E  */
#line 1217 "sintaticoP.y"
                        {
				if(yyvsp[0].tipo.compare("bool") != 0){
				yyerror("Tipo de expressão incompativel para a conversão");
				}
				yyval.label = gentempcode("bool");
				yyval.tipo = yyvsp[0].tipo;
				yyval.traducao =  yyvsp[0].traducao +"\t" + yyval.label + " = " + "(bool) " + yyvsp[0].label+";\n"; 
			}
#line 2864 "y.tab.c"
    break;

  case 62: /* E: ATB  */
#line 1226 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2872 "y.tab.c"
    break;

  case 63: /* E: C_LOOP  */
#line 1230 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2880 "y.tab.c"
    break;

  case 64: /* E: TK_NUM  */
#line 1234 "sintaticoP.y"
                        {
				yyval.label = gentempcode("int");
				yyval.tipo = "int";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";

				//cout << "Variavel atribuida " << $$.val << endl;
			}
#line 2894 "y.tab.c"
    break;

  case 65: /* E: TK_REAL  */
#line 1244 "sintaticoP.y"
                        {
				yyval.label = gentempcode("float");
				yyval.tipo = "float";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2906 "y.tab.c"
    break;

  case 66: /* E: TK_CHAR  */
#line 1252 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.tipo = "char";
				yyval.classe = "String";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2918 "y.tab.c"
    break;

  case 67: /* E: TK_BOOL  */
#line 1259 "sintaticoP.y"
                                {
				yyval.label = gentempcode("bool");
				yyval.tipo = "bool";
				yyval.classe = "Boolean";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label +";\n";
			}
#line 2930 "y.tab.c"
    break;

  case 68: /* E: TK_STRING  */
#line 1267 "sintaticoP.y"
                        {
				string l1;
				yyval.label = gentempcode("char*");
				l1 = gentempcode("int");
				yyval.tipo = "string";
				yyval.classe = "String";
				yyval.traducao = "\t"+l1+" = "+to_string(yyvsp[0].label.size()-1)+";\n";
				yyval.val = yyvsp[0].label;
				modatrib(yyval.label, l1);
				yyval.traducao += "\t" + yyval.label + " = (char*) malloc(" + l1 +");\n"+"\tstrcpy("+yyval.label+","+yyvsp[0].label+");\n";
			    
			}
#line 2947 "y.tab.c"
    break;

  case 69: /* E: ID_F  */
#line 1280 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;

			}
#line 2956 "y.tab.c"
    break;

  case 70: /* E: TK_CONV  */
#line 1285 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.val = yyvsp[0].label;
				//cout << $$.val << endl;
			}
#line 2966 "y.tab.c"
    break;

  case 71: /* ATB: TK_ID '=' E  */
#line 1292 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				bool TS;
				flag = buscarSimbolos(yyvsp[-2].label);
				
				cout << "atribuindo" << endl;
				if(flag.endereco.compare("") == 0){
					cout << "não existia" << endl;
					flag = inserirSimbolos(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].classe, "global", "0", "0");
				}else if(flag.classe.compare(yyvsp[0].classe) == 0  && flag.classe.compare("String") == 0 && flag.tipo.compare("string") == 0){
					TS = true;
				}
				else if(flag.tipo.compare(yyvsp[0].tipo) != 0){
					//checarlista();
					cout << flag.tipo << " " <<  yyvsp[0].tipo << endl;
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				yyval.label = flag.endereco;
				yyval.tipo = yyvsp[0].tipo;
				yyval.val = yyvsp[0].val;
				flag.val = yyval.val;
				alterarSimbolos(flag);
				cout << flag.nome <<" yo "<< flag.tipo << endl;


				if(flag.tipo.compare("string") !=0){
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				
				}
				else if(yyvsp[0].classe.compare("String") == 0){
					yyvsp[-2].tipo = flag.tipo;
					yyvsp[-2].label = flag.endereco;
					atributos resultado = funcString(yyvsp[-2], "=", yyvsp[0]);
					//cout<< resultado.traducao << endl;
					if(yyvsp[-2].tipo.compare("string") == 0 && yyvsp[0].tipo.compare("char") == 0){						
						yyvsp[0]=resultado;
						cout<< flag.nome <<yyvsp[0].tipo << endl;
					}

					if(yyvsp[-2].tipo.compare(yyvsp[0].tipo) == 0){
						cout << "entrou segundo if " <<yyvsp[0].label << endl;
						atributos a = buscaEnd(yyvsp[0].label);
						cout << "busca por tam " <<a.tam << endl;
						if(flag.tam.compare("0") != 0){
							yyval.traducao= resultado.traducao+"\tfree("+yyvsp[-2].label+");\n";
							yyval.traducao=yyval.traducao+"\t"+yyvsp[-2].label+" = (char*) malloc("+a.tam+");\n\tstrcpy("
						+yyvsp[-2].label+","+yyvsp[0].label+");\n"+
						"\tfree("+yyvsp[0].label+");\n";
						}else{
							yyval.traducao=resultado.traducao+"\t"+yyvsp[-2].label+" = (char*) malloc("+a.tam+");\n\tstrcpy("
					+yyvsp[-2].label+","+yyvsp[0].label+");\n"+"\tfree("+yyvsp[0].label+");\n";

					//cout << $$.traducao << endl;
						}
						//$$.traducao = $1.traducao + $3.traducao + "\t"+ "strcpy(" + $$.label + ","+ $3.label + ");\n";
					flag.tam = a.tam;
					alterarSimbolos(flag);
					modatrib(flag.endereco, a.tam);
					}
				}
			}
#line 3033 "y.tab.c"
    break;

  case 72: /* ATB: TK_ID REF_ARRAY '=' E  */
#line 1355 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				string l1, l2;
				bool TS;
				flag = buscarSimbolos(yyvsp[-3].label);
				
				cout << "atribuindo" << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("variavel não declarada");
				}else if(yyvsp[-2].tipo.compare("int") != 0){
					yyerror("Expressão incompativel para localizar elemento no array");
			
				}else if(flag.tipo.compare(yyvsp[0].tipo) != 0){
					//checarlista();
					cout << flag.tipo << " " <<  yyvsp[-1].tipo << endl;
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				yyval.label = flag.endereco;
				yyval.tipo = yyvsp[-2].tipo;
				yyval.val = yyvsp[-2].val;
				flag.val = yyval.val;
				alterarSimbolos(flag);
				cout << flag.nome <<" yo "<< flag.tipo << endl;
				l1 = gentempcode("int");
				l2 = gentempcode("int");


				if(flag.tipo.compare("string") !=0){
					if(yyvsp[-2].val.compare("0") == 0){
						yyval.traducao = yyvsp[-3].traducao + yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + "["+ yyvsp[-2].label +"] = " + yyvsp[0].label + ";\n";
					}else{
						yyval.traducao = yyvsp[-3].traducao + yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + l1 + " = " + yyvsp[-2]. val + " * "+ flag.tam +";\n\t" + l2 + " = " + l1 + " + "+ yyvsp[-2].label +";\n\t" + yyval.label + "["+ l2 +"] = " + yyvsp[0].label + ";\n";
					}
				
				}
				
			}
#line 3076 "y.tab.c"
    break;

  case 73: /* ID_F: TK_ID  */
#line 1395 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				flag = buscarSimbolos(yyvsp[0].label);
				cout << yyvsp[0].label <<endl;
				cout <<"variavel encontrada. " << flag.endereco << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("Variavel não declarada");
				}
				yyval.label = flag.endereco;
				yyval.val = flag.val;
				yyval.tipo = flag.tipo;
				yyval.classe = flag.classe;
				yyval.val = flag.nome;
				if(flag.tipo.compare("string") == 0){
					yyval.tam = flag.tam;
					yyval.traducao = "\t"+yyval.label+"= (char*) malloc("+flag.tam+");\n"+
				"\tstrcpy("+ yyval.label+"," +flag.endereco + ");\n";
				}else{
				yyval.traducao = "\t" + yyval.label + " = " + yyval.label + ";\n";
				//cout << "Variavel atribuida " << $$.val << endl;
				}
			}
#line 3103 "y.tab.c"
    break;

  case 74: /* ID_F: TK_ID REF_ARRAY  */
#line 1418 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				string l1, l2;
				flag = buscarSimbolos(yyvsp[-1].label);
				cout << yyvsp[-1].label <<endl;
				//cout <<"variavel encontrada. " << flag.endereco << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("Variavel não declarada");
				}else if(yyvsp[0].tipo.compare("int") != 0){
					yyerror("indice incompativel");
				}

				yyval.label = gentempcode("int");
				yyval.val = flag.val;
				yyval.tipo = flag.tipo;
				yyval.classe = flag.classe;
				yyval.val = flag.nome;
				yyval.tam = "0";
				l1 = gentempcode("int");
				l2 = gentempcode("int");
				if(flag.dim.compare("0") == 0){
				yyval.traducao = yyvsp[0].traducao + "\t" + l1 + " = " + yyvsp[0].label + ";\n\t" + yyval.label + " = " + flag.endereco + "["+ l1 +"];\n";
				}else{
					yyval.traducao = yyvsp[0].traducao + "\t" + l1 + " = " + yyvsp[0]. val + " * "+ flag.tam +";\n\t" + l2 + " = " + l1 + " + "+ yyvsp[0].label +";\n\t"+ yyval.label + " = " + flag.endereco + "["+ l2 +"];\n";
				}

				//cout << "Variavel atribuida " << $$.val << endl;
				
			}
#line 3137 "y.tab.c"
    break;

  case 75: /* C_LOOP: TK_BREAK  */
#line 1448 "sintaticoP.y"
                        {
				escopo alvo;
				alvo = buscarbloco(1);

				yyval.traducao = "\tgo to FIM " + alvo.label + ";\n";
			}
#line 3148 "y.tab.c"
    break;

  case 76: /* C_LOOP: TK_NEXT  */
#line 1455 "sintaticoP.y"
                        {
				escopo alvo;
				alvo = buscarbloco(1);

				yyval.traducao = "\tgo to inicio-" + alvo.label + ";\n";
			}
#line 3159 "y.tab.c"
    break;


#line 3163 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1462 "sintaticoP.y"


#include "lex.yy.c"

int yyparse();
using namespace std;
string gentempcode(string tipo)
{
	atributos x;
	var_temp_qnt++;
	x.label = "t" + to_string(var_temp_qnt);
	x.tipo = tipo;
	x.tam = "0";

	listaattr.push_back(x);
	return "t" + to_string(var_temp_qnt);
}

string gentemplabel(){
	string x;
	qtd_laco++;
	x = "P" + to_string(qtd_laco);

	return x;
}

bool traducao(string op){
	bool resp;
	if(op.compare("TRUE") ==0){
		resp = TRUE;
	}else{
		resp = FALSE;
	}
	return resp;
}

void checarlista(){
	int i, j, cont;
	tabelaSimbolos x; 

	cont = listaEscopo.size()-1;
	for(i = cont; i >=0; i--){
		for(j=0; j<listaEscopo[i].size(); j++){
		x = listaEscopo[i][j];
		cout << "\t nome: " << x.nome << " "<< "val: "<< x.val << " " <<" tipo: " << x.tipo << '-' << x.endereco << endl;
		}
	}
}
tabelaSimbolos buscarSimbolos(string nome){
	tabelaSimbolos x;
	x.nome = "";
	x.tipo = "";
	x.endereco = "";
	int i, j,cont;

	cout << "busca por "<< nome <<endl;
	cont = listaEscopo.size()-1;
	for(i = cont; i >=0; i--){
		for(j=0; j<listaEscopo[i].size(); j++){
			//cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
			if(nome.compare(listaEscopo[i][j].nome) == 0  && (i == cont || listaEscopo[i][j].mod == 1)){
				printf("Achei ");
				x = listaEscopo[i][j];
				cout<< x.endereco<< endl;	
				
				return x;
			}
			}
	}
	return x;
}
void modatrib(string nome, string tam){
	atributos x;
	x.label = nome;
	x.tam = tam;
	int i, j, k;
	j = 0;
	k = 0;

	cout << " mudanca de atributo " << nome <<  endl;
	for(i=0; i<listaattr.size(); i++){
		
		if(nome.compare(listaattr[i].label) == 0){
			x.tipo = listaattr[i].tipo;
			listaattr.insert(listaattr.begin()+j, x);
			k = j +1;
			cout << j << " " << k << endl;
			
			listaattr.erase(listaattr.begin() + k);
				return;
		}
		j++;
	}
	
}
atributos buscaEnd(string nome){
	atributos x;
	int i, k;
	x.label = "";
	x.tipo = "";
	x.tam = "";

	
	for(i=0; i<listaattr.size(); i++){
		//cout << i << " simbolo " << listaattr[i].label<< endl;
		if(nome.compare(listaattr[i].label) == 0){
			printf("Achei ");
			x = listaattr[i];
			cout<< listaattr[i].tam<< endl;	
				
			return x;
		}
	}
	
	return x;
}

void alterarSimbolos(tabelaSimbolos x){
	int i, j, k, cont;
	cont = listaEscopo.size()-1;
	cout << "alterando variavel" <<endl;
	for(i = cont; i >=0; i--){
		for(j = 0; j<listaEscopo[i].size(); j++){
			cout << j << " simbolos " << listaEscopo[i][j].nome<< endl;
			if(x.nome.compare(listaEscopo[i][j].nome) == 0  && (i == cont || listaEscopo[i][j].mod == 1) ){
				listaEscopo[i].insert(listaEscopo[i].begin()+j, x);
				k = j +1;
				listaEscopo[i].erase(listaEscopo[i].begin() + k);
				return;
			}
		}
	
	}
}
bool verificarsimbolos(string nome){
	tabelaSimbolos x; 

	x = buscarSimbolos(nome);
	if(x.endereco.compare("") == 0){
		return false;
	}
	return true;

}
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso, string tamanho, string nDim){
	tabelaSimbolos var; 
	int cont;
	bool v;

	v = verificarsimbolos(nome);
	//cout << v << endl;
	if(v == true){
		checarlista();
		yyerror("Nome de variavel já declarada");
	}
	var.nome = nome;
	var.tipo = tipo;
	var.classe = classe;
	var.val = "";
	var.tam = tamanho;
	var.dim = nDim;
	//if(stoi(tamanho) < 0){
	//	yyerror("Tamanho inválido para uma matriz");
	//}
	if(acesso.compare("global") == 0){
		var.mod = 1;
	}else{
		var.mod = 0;
	}
	cout << acesso << endl;
	var.endereco = gentempcode(tipo);
	
	cont = listaEscopo.size()-1;
	cout <<"var "<< var.nome << ' ' << var.tipo << ' ' << var.endereco <<endl;
	listaEscopo[cont].push_back(var);
	//cout << "inseriu: " << listaEscopo[cont].size() <<endl;

	return var;

}
atributos funcString(atributos e1, string operador, atributos e2){
	atributos result;
	
	cout<< e1.tipo << e2.tipo << endl;
	if(e1.tipo.compare(e2.tipo) == 0 && e1.tipo.compare("string") == 0 && operador.compare("=") == 0){
		cout<< "primeira alternativa" << endl;
		result.tipo=e1.tipo;
		result.label="";	
		result.traducao=e1.traducao+e2.traducao;
		return result;
		
	}else if (((operador.compare("+") == 0) && (e1.tipo.compare(e2.tipo) != 0)  && ((e1.tipo.compare("string")== 0)||(e1.tipo.compare("char")==0)) && ((e2.tipo.compare("string")==0)||(e2.tipo.compare("char")==0))) || ((operador.compare("=") == 0) && (e1.tipo.compare("string") ==0) && (e2.tipo.compare("char")==0))||((operador.compare("+") == 0) && (e1.tipo.compare(e2.tipo) == 0) && (e1.tipo.compare("char") ==0))){
		result.tipo = "string";
		result.label = gentempcode("string");
		string labelx = gentempcode("string");

		cout<< "segunda alternativa" << result.tipo<< endl;

		if(e1.tipo.compare("char") == 0){
			result.traducao=e1.traducao + e2.traducao+"\t"+labelx+" =  2;\n\t"+result.label+" = (char*)malloc("+labelx+");\n\t"+result.label+"[0] = "+e1.label+";\n";
		}else{
			result.traducao= e1.traducao + e2.traducao+"\t"+labelx+" =  2;\n\t"+result.label+" = (char*)malloc("+labelx+");\n\t"+result.label+"[0] = "+e2.label+";\n";
		}
		modatrib(result.label, labelx);
		cout <<"label" << result.label  << endl;
		return result;
	}else if((operador=="+"&& e1.tipo.compare(e2.tipo) == 0 && e1.tipo.compare("string") == 0)){
		result.tipo=e1.tipo;
		result.label=e2.label;	
		result.traducao=e1.traducao+e2.traducao;
		cout<< "ultima alternativa" << endl;
		return result;
	}
	
}
escopo buscarbloco(int k){
	int i, cont;

	cont = listaEscopo.size()-1;
	for(i= cont; i>=0; i--){
		if(infobloco[i].tipo == 1 and k == 1){
			return infobloco[i];
		}

	}
	yyerror("Nenhum bloco de laço existente para essa operação");
}
string imprimirFree(){
	int i, j, cont;
	string declaracao="";
	cont = listaEscopo.size()-1;
	for(i = cont; i >=0; i--){
		for(j=0; j<listaEscopo[i].size(); j++){
			//cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
			if(listaEscopo[i][j].tipo.compare("string") == 0){
				declaracao += "\tfree("+listaEscopo[i][j].endereco+");\n";
			}
			}
			return declaracao;
	}
	
}
void limparpilha(){
	listaEscopo.clear();
	infobloco.clear();
	listaattr.clear();
}
int main(int argc, char* argv[])
{
	tabelaSimbolos x;
	escopo y; 
	int i;
	var_temp_qnt = 0;
	y.label = "";
	y.tipo = BLOCO;
	listaEscopo.push_back(listaSimb);
	infobloco.push_back(y);

	yyparse();
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				
