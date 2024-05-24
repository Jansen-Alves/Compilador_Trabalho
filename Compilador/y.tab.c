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
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso);
tabelaSimbolos buscarSimbolos(string nome);
escopo buscarbloco(int k);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
void limparpilha();

bool traducao(string op);

#line 136 "y.tab.c"

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
    TK_STR = 259,                  /* TK_STR  */
    TK_REAL = 260,                 /* TK_REAL  */
    TK_CHAR = 261,                 /* TK_CHAR  */
    TK_STRING = 262,               /* TK_STRING  */
    TK_BOOL = 263,                 /* TK_BOOL  */
    TK_MAIN = 264,                 /* TK_MAIN  */
    TK_ID = 265,                   /* TK_ID  */
    TK_TIPO_INT = 266,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 267,           /* TK_TIPO_FLOAT  */
    TK_ST = 268,                   /* TK_ST  */
    TK_GLOBAL = 269,               /* TK_GLOBAL  */
    TK_LOCAL = 270,                /* TK_LOCAL  */
    TK_TIPO_CHAR = 271,            /* TK_TIPO_CHAR  */
    TK_TIPO_BOOL = 272,            /* TK_TIPO_BOOL  */
    TK_CONV = 273,                 /* TK_CONV  */
    TK_MAIOR_IGUAL = 274,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 275,          /* TK_MENOR_IGUAL  */
    TK_MAIOR = 276,                /* TK_MAIOR  */
    TK_MENOR = 277,                /* TK_MENOR  */
    TK_IGUALDADE = 278,            /* TK_IGUALDADE  */
    TK_DESIGUALDADE = 279,         /* TK_DESIGUALDADE  */
    TK_CONJUNCAO = 280,            /* TK_CONJUNCAO  */
    TK_DISNJUNCAO = 281,           /* TK_DISNJUNCAO  */
    TK_ALT = 282,                  /* TK_ALT  */
    TK_START = 283,                /* TK_START  */
    TK_IF = 284,                   /* TK_IF  */
    TK_ELSE = 285,                 /* TK_ELSE  */
    TK_DO = 286,                   /* TK_DO  */
    TK_WHILE = 287,                /* TK_WHILE  */
    TK_FOR = 288,                  /* TK_FOR  */
    TK_SWITCH = 289,               /* TK_SWITCH  */
    TK_CASE = 290,                 /* TK_CASE  */
    TK_DEFAULT = 291,              /* TK_DEFAULT  */
    TK_BREAK = 292,                /* TK_BREAK  */
    TK_NEXT = 293,                 /* TK_NEXT  */
    TK_FIM = 294,                  /* TK_FIM  */
    TK_ERROR = 295                 /* TK_ERROR  */
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
#define TK_ST 268
#define TK_GLOBAL 269
#define TK_LOCAL 270
#define TK_TIPO_CHAR 271
#define TK_TIPO_BOOL 272
#define TK_CONV 273
#define TK_MAIOR_IGUAL 274
#define TK_MENOR_IGUAL 275
#define TK_MAIOR 276
#define TK_MENOR 277
#define TK_IGUALDADE 278
#define TK_DESIGUALDADE 279
#define TK_CONJUNCAO 280
#define TK_DISNJUNCAO 281
#define TK_ALT 282
#define TK_START 283
#define TK_IF 284
#define TK_ELSE 285
#define TK_DO 286
#define TK_WHILE 287
#define TK_FOR 288
#define TK_SWITCH 289
#define TK_CASE 290
#define TK_DEFAULT 291
#define TK_BREAK 292
#define TK_NEXT 293
#define TK_FIM 294
#define TK_ERROR 295

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
  YYSYMBOL_TK_STR = 4,                     /* TK_STR  */
  YYSYMBOL_TK_REAL = 5,                    /* TK_REAL  */
  YYSYMBOL_TK_CHAR = 6,                    /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 7,                  /* TK_STRING  */
  YYSYMBOL_TK_BOOL = 8,                    /* TK_BOOL  */
  YYSYMBOL_TK_MAIN = 9,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 10,                     /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 11,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 12,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_ST = 13,                     /* TK_ST  */
  YYSYMBOL_TK_GLOBAL = 14,                 /* TK_GLOBAL  */
  YYSYMBOL_TK_LOCAL = 15,                  /* TK_LOCAL  */
  YYSYMBOL_TK_TIPO_CHAR = 16,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_BOOL = 17,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_CONV = 18,                   /* TK_CONV  */
  YYSYMBOL_TK_MAIOR_IGUAL = 19,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 20,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_MAIOR = 21,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MENOR = 22,                  /* TK_MENOR  */
  YYSYMBOL_TK_IGUALDADE = 23,              /* TK_IGUALDADE  */
  YYSYMBOL_TK_DESIGUALDADE = 24,           /* TK_DESIGUALDADE  */
  YYSYMBOL_TK_CONJUNCAO = 25,              /* TK_CONJUNCAO  */
  YYSYMBOL_TK_DISNJUNCAO = 26,             /* TK_DISNJUNCAO  */
  YYSYMBOL_TK_ALT = 27,                    /* TK_ALT  */
  YYSYMBOL_TK_START = 28,                  /* TK_START  */
  YYSYMBOL_TK_IF = 29,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 30,                   /* TK_ELSE  */
  YYSYMBOL_TK_DO = 31,                     /* TK_DO  */
  YYSYMBOL_TK_WHILE = 32,                  /* TK_WHILE  */
  YYSYMBOL_TK_FOR = 33,                    /* TK_FOR  */
  YYSYMBOL_TK_SWITCH = 34,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 35,                   /* TK_CASE  */
  YYSYMBOL_TK_DEFAULT = 36,                /* TK_DEFAULT  */
  YYSYMBOL_TK_BREAK = 37,                  /* TK_BREAK  */
  YYSYMBOL_TK_NEXT = 38,                   /* TK_NEXT  */
  YYSYMBOL_TK_FIM = 39,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 40,                  /* TK_ERROR  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_46_ = 46,                       /* '^'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '}'  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '!'  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_S = 55,                         /* S  */
  YYSYMBOL_CODS = 56,                      /* CODS  */
  YYSYMBOL_COD = 57,                       /* COD  */
  YYSYMBOL_BLOCO = 58,                     /* BLOCO  */
  YYSYMBOL_INIT = 59,                      /* INIT  */
  YYSYMBOL_INIB = 60,                      /* INIB  */
  YYSYMBOL_COMANDOS = 61,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 62,                   /* COMANDO  */
  YYSYMBOL_LISTA_ID = 63,                  /* LISTA_ID  */
  YYSYMBOL_MODO = 64,                      /* MODO  */
  YYSYMBOL_CONTROLES = 65,                 /* CONTROLES  */
  YYSYMBOL_REF = 66,                       /* REF  */
  YYSYMBOL_CASES = 67,                     /* CASES  */
  YYSYMBOL_CASE = 68,                      /* CASE  */
  YYSYMBOL_E = 69,                         /* E  */
  YYSYMBOL_ATB = 70,                       /* ATB  */
  YYSYMBOL_C_LOOP = 71                     /* C_LOOP  */
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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   403

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
       2,     2,     2,    52,     2,     2,     2,    45,     2,     2,
      47,    48,    43,    41,    51,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,   117,   122,   126,   130,   138,   152,   166,
     180,   185,   190,   194,   198,   202,   206,   210,   216,   220,
     224,   228,   233,   236,   251,   269,   290,   311,   335,   350,
     357,   362,   366,   391,   399,   461,   511,   561,   611,   662,
     713,   725,   731,   770,   808,   846,   884,   919,   954,   971,
     989,  1005,  1020,  1033,  1047,  1056,  1060,  1064,  1074,  1082,
    1090,  1097,  1106,  1122,  1129,  1153,  1160
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_STR",
  "TK_REAL", "TK_CHAR", "TK_STRING", "TK_BOOL", "TK_MAIN", "TK_ID",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_ST", "TK_GLOBAL", "TK_LOCAL",
  "TK_TIPO_CHAR", "TK_TIPO_BOOL", "TK_CONV", "TK_MAIOR_IGUAL",
  "TK_MENOR_IGUAL", "TK_MAIOR", "TK_MENOR", "TK_IGUALDADE",
  "TK_DESIGUALDADE", "TK_CONJUNCAO", "TK_DISNJUNCAO", "TK_ALT", "TK_START",
  "TK_IF", "TK_ELSE", "TK_DO", "TK_WHILE", "TK_FOR", "TK_SWITCH",
  "TK_CASE", "TK_DEFAULT", "TK_BREAK", "TK_NEXT", "TK_FIM", "TK_ERROR",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('", "')'", "'}'", "';'",
  "','", "'!'", "'='", "$accept", "S", "CODS", "COD", "BLOCO", "INIT",
  "INIB", "COMANDOS", "COMANDO", "LISTA_ID", "MODO", "CONTROLES", "REF",
  "CASES", "CASE", "E", "ATB", "C_LOOP", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     102,  -105,  -105,  -105,  -105,  -105,   -35,     8,     1,     1,
       1,  -105,   157,     3,   157,    -9,   157,  -105,  -105,   157,
      22,   157,    43,  -105,   102,  -105,   140,  -105,   191,  -105,
    -105,   157,     5,  -105,  -105,    52,    52,    52,    52,   282,
    -105,   140,   310,    60,     3,   320,    51,    23,    24,    31,
     243,   320,  -105,  -105,     1,  -105,   157,   157,   157,   157,
     157,   157,   157,   157,  -105,   157,   157,   157,   157,   157,
     157,  -105,   320,    33,    32,    34,    35,    36,    48,  -105,
      63,   140,    50,   140,   -35,    56,     6,   157,   157,   157,
    -105,    46,    46,    46,    46,   357,   357,   348,   320,    51,
      51,   -22,   -22,   -22,    55,    73,    52,  -105,  -105,  -105,
    -105,    73,    53,    85,    72,   157,   157,    73,    75,     6,
     320,   320,   320,  -105,  -105,  -105,  -105,   157,  -105,   201,
     282,   140,  -105,  -105,   233,   157,   140,  -105,  -105,   273,
    -105,     3,   140,    76,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    57,    58,    59,    61,    60,    62,    22,    22,    22,
      22,    63,     0,     0,     0,     0,     0,    65,    66,     0,
       0,     0,     0,     2,     4,     6,    11,    13,     0,    55,
      56,     0,     0,    20,    21,     0,     0,     0,     0,     0,
       9,    11,     0,     0,     0,    29,    40,     0,     0,     0,
       0,    50,     1,     3,    22,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,    12,    64,     0,    19,     0,     0,     0,     0,     8,
      23,    11,     0,    11,     0,     0,    31,     0,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    34,
      35,    36,    37,    38,    39,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      52,    53,    54,     5,    18,    24,     7,     0,    25,     0,
       0,    11,    28,    30,     0,     0,    11,    33,    26,     0,
      32,     0,    11,     0,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,   103,  -105,   -91,  -104,   -41,   -20,  -105,   -26,
      27,  -105,  -105,     7,  -105,   -12,    86,  -105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    22,    23,    24,    80,    81,    41,    25,    26,    75,
      35,    27,    44,   118,   119,    28,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    83,    42,    86,    45,    64,    55,    46,    50,    51,
      76,    77,    78,   131,   123,    33,    34,    32,    31,    72,
     125,    82,    33,    34,    70,     1,   136,     2,     3,     4,
       5,    40,     6,    47,    48,    36,    37,    38,    43,    49,
      11,   116,   117,    52,    91,    92,    93,    94,    95,    96,
      97,    98,    73,    99,   100,   101,   102,   103,   104,    17,
      18,   112,    74,   114,    19,    56,    57,    58,    59,    20,
      84,    87,    88,    64,    21,   120,   121,   122,    64,    89,
     124,   105,    64,   106,   107,   108,   109,    65,    66,    67,
      68,    69,    70,   111,    67,    68,    69,    70,   110,   113,
     142,    79,   126,   129,   130,     1,   115,     2,     3,     4,
       5,   137,     6,     7,     8,   134,   140,   127,     9,    10,
      11,   128,   143,   139,   132,   144,   133,    53,     0,    85,
       0,    12,     0,    13,    14,    15,    16,     0,     0,    17,
      18,     0,     0,     1,    19,     2,     3,     4,     5,    20,
       6,    54,     8,     0,    21,     0,     9,    10,    11,     0,
       1,     0,     2,     3,     4,     5,     0,     6,     0,    12,
       0,    13,    14,    15,    16,    11,     0,    17,    18,     0,
       0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    21,     0,    17,    18,     0,     0,     0,    19,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,    65,    66,    67,    68,    69,    70,     0,     0,
       0,    71,    65,    66,    67,    68,    69,    70,     0,     0,
       0,   135,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,    65,    66,    67,    68,    69,    70,
       0,     0,     0,   138,    65,    66,    67,    68,    69,    70,
       0,    90,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      79,     0,     0,     0,    65,    66,    67,    68,    69,    70,
       0,   141,     0,    65,    66,    67,    68,    69,    70,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    40,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,    65,    66,    67,    68,    69,    70,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    56,    57,    58,
      59,    60,    61,    62,     0,    64,    56,    57,    58,    59,
      60,    61,     0,     0,    64,     0,     0,     0,     0,    65,
      66,    67,    68,    69,    70,     0,     0,     0,    65,    66,
      67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      12,    42,    14,    44,    16,    27,    26,    19,    20,    21,
      36,    37,    38,   117,   105,    14,    15,     9,    53,    31,
     111,    41,    14,    15,    46,     3,   130,     5,     6,     7,
       8,    28,    10,    11,    12,     8,     9,    10,    47,    17,
      18,    35,    36,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    47,    65,    66,    67,    68,    69,    70,    37,
      38,    81,    10,    83,    42,    19,    20,    21,    22,    47,
      10,    48,    48,    27,    52,    87,    88,    89,    27,    48,
     106,    48,    27,    51,    50,    50,    50,    41,    42,    43,
      44,    45,    46,    30,    43,    44,    45,    46,    50,    49,
     141,    28,    49,   115,   116,     3,    50,     5,     6,     7,
       8,   131,    10,    11,    12,   127,   136,    32,    16,    17,
      18,    49,   142,   135,    49,    49,   119,    24,    -1,    43,
      -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,     3,    42,     5,     6,     7,     8,    47,
      10,    11,    12,    -1,    52,    -1,    16,    17,    18,    -1,
       3,    -1,     5,     6,     7,     8,    -1,    10,    -1,    29,
      -1,    31,    32,    33,    34,    18,    -1,    37,    38,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    52,    -1,    37,    38,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    41,    42,    43,    44,    45,    46,
      -1,    48,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    48,    -1,    41,    42,    43,    44,    45,    46,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    10,    11,    12,    16,
      17,    18,    29,    31,    32,    33,    34,    37,    38,    42,
      47,    52,    55,    56,    57,    61,    62,    65,    69,    70,
      71,    53,     9,    14,    15,    64,    64,    64,    64,    69,
      28,    60,    69,    47,    66,    69,    69,    11,    12,    17,
      69,    69,     0,    56,    11,    61,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    41,    42,    43,    44,    45,
      46,    50,    69,    47,    10,    63,    63,    63,    63,    28,
      58,    59,    61,    60,    10,    70,    60,    48,    48,    48,
      48,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    48,    51,    50,    50,    50,
      50,    30,    61,    49,    61,    50,    35,    36,    67,    68,
      69,    69,    69,    58,    63,    58,    49,    32,    49,    69,
      69,    59,    49,    67,    69,    50,    59,    61,    50,    69,
      61,    48,    60,    61,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     1,     3,     1,     1,
       2,     0,     2,     1,     4,     4,     4,     4,     3,     1,
       1,     1,     0,     3,     5,     5,     7,    11,     5,     1,
       2,     0,     4,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1
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
#line 90 "sintaticoP.y"
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
#line 1480 "y.tab.c"
    break;

  case 3: /* CODS: COD CODS  */
#line 118 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1488 "y.tab.c"
    break;

  case 4: /* CODS: %empty  */
#line 122 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 1496 "y.tab.c"
    break;

  case 5: /* COD: TK_TIPO_INT TK_MAIN '(' ')' BLOCO  */
#line 127 "sintaticoP.y"
            {
				yyval.traducao = yyvsp[0].traducao;
            }
#line 1504 "y.tab.c"
    break;

  case 6: /* COD: COMANDOS  */
#line 131 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, vazio " << listaEscopo.size() << endl;
			}
#line 1515 "y.tab.c"
    break;

  case 7: /* BLOCO: INIT COMANDOS '}'  */
#line 139 "sintaticoP.y"
                        {
				cout << listaEscopo.size();
				/*std::vector<tabelaSimbolos>v1;
				listaEscopo.push_back(v1);
				qtd_tabelas++;
				cout << "quantidade de escopo: "<<  qtd_tabelas << endl;*/
				yyval.traducao = yyvsp[-1].traducao;
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo " << listaEscopo.size() << endl;
			}
#line 1531 "y.tab.c"
    break;

  case 8: /* INIT: TK_START  */
#line 153 "sintaticoP.y"
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
#line 1547 "y.tab.c"
    break;

  case 9: /* INIB: TK_START  */
#line 167 "sintaticoP.y"
                        {
				escopo x;
				vector<tabelaSimbolos> v1;
				x.label = gentemplabel();
				x.tipo = LACO;

				listaEscopo.push_back(v1);
				infobloco.push_back(x);
				cout<< "bloco laço, tamanho pilha "<< listaEscopo.size() << endl;
			}
#line 1562 "y.tab.c"
    break;

  case 10: /* COMANDOS: COMANDO COMANDOS  */
#line 181 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1570 "y.tab.c"
    break;

  case 11: /* COMANDOS: %empty  */
#line 185 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 1578 "y.tab.c"
    break;

  case 12: /* COMANDO: E ';'  */
#line 191 "sintaticoP.y"
                        {
				yyval = yyvsp[-1];
			}
#line 1586 "y.tab.c"
    break;

  case 13: /* COMANDO: CONTROLES  */
#line 195 "sintaticoP.y"
                        {
				yyval = yyvsp[0];
			}
#line 1594 "y.tab.c"
    break;

  case 14: /* COMANDO: TK_TIPO_INT MODO LISTA_ID ';'  */
#line 199 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "int", "Number", yyvsp[-2].label);
			}
#line 1602 "y.tab.c"
    break;

  case 15: /* COMANDO: TK_TIPO_FLOAT MODO LISTA_ID ';'  */
#line 203 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "float", "Number", yyvsp[-2].label);
			}
#line 1610 "y.tab.c"
    break;

  case 16: /* COMANDO: TK_TIPO_CHAR MODO LISTA_ID ';'  */
#line 207 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "char", "Character", yyvsp[-2].label);
			}
#line 1618 "y.tab.c"
    break;

  case 17: /* COMANDO: TK_TIPO_BOOL MODO LISTA_ID ';'  */
#line 211 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "bool", "Boolean", yyvsp[-2].label);
			}
#line 1626 "y.tab.c"
    break;

  case 18: /* LISTA_ID: TK_ID ',' LISTA_ID  */
#line 217 "sintaticoP.y"
                        {
				yyval.label = yyvsp[-2].label;
			}
#line 1634 "y.tab.c"
    break;

  case 19: /* LISTA_ID: TK_ID  */
#line 221 "sintaticoP.y"
                        {
				yyval.label = yyvsp[0].label;
			}
#line 1642 "y.tab.c"
    break;

  case 20: /* MODO: TK_GLOBAL  */
#line 225 "sintaticoP.y"
                        {
				yyval.label = "global";
			}
#line 1650 "y.tab.c"
    break;

  case 21: /* MODO: TK_LOCAL  */
#line 229 "sintaticoP.y"
                        {
				yyval.label = "local";
			}
#line 1658 "y.tab.c"
    break;

  case 22: /* MODO: %empty  */
#line 233 "sintaticoP.y"
                        {
				yyval.label = "global";
			}
#line 1666 "y.tab.c"
    break;

  case 23: /* CONTROLES: TK_IF E BLOCO  */
#line 237 "sintaticoP.y"
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
#line 1685 "y.tab.c"
    break;

  case 24: /* CONTROLES: TK_IF E BLOCO TK_ELSE BLOCO  */
#line 252 "sintaticoP.y"
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
#line 1707 "y.tab.c"
    break;

  case 25: /* CONTROLES: TK_WHILE E INIB COMANDOS '}'  */
#line 270 "sintaticoP.y"
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
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, while" << listaEscopo.size() << endl;
				
			}
#line 1732 "y.tab.c"
    break;

  case 26: /* CONTROLES: TK_DO INIB COMANDOS '}' TK_WHILE E ';'  */
#line 291 "sintaticoP.y"
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
				jp = iniwhile +yyvsp[-4].traducao + yyvsp[-1].traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+laco.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				yyval.traducao = jp + ciclowhile + "\tFIM "+laco.label+";\n";

				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, Do while" << listaEscopo.size() << endl;
			}
#line 1757 "y.tab.c"
    break;

  case 27: /* CONTROLES: TK_FOR '(' ATB ';' E ';' E ')' INIB COMANDOS '}'  */
#line 312 "sintaticoP.y"
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

				yyval.traducao = jp + yyvsp[-1].traducao + yyvsp[-4].traducao + cicloF +"\tFIM "+ laco.label + ";\n";
				listaEscopo.pop_back();
				infobloco.pop_back();
				cout << " tamanho final de escopo, for" << listaEscopo.size() << endl;

			}
#line 1785 "y.tab.c"
    break;

  case 28: /* CONTROLES: TK_SWITCH REF INIB CASES '}'  */
#line 336 "sintaticoP.y"
                        {
				string fim;
			 	escopo laco;

				laco = buscarbloco(1);
				fim = "\tFIM" + laco.label + ";\n";
				yyval.traducao = yyvsp[-3].traducao + yyvsp[-1].traducao + fim;

				listaEscopo.pop_back();
				infobloco.pop_back();
				ref_switch.clear();
			}
#line 1802 "y.tab.c"
    break;

  case 29: /* REF: E  */
#line 351 "sintaticoP.y"
                        {
				atributos x;
				x.label = yyvsp[0].label;
				ref_switch.push_back(x);
				yyval.traducao = yyvsp[0].traducao;
			}
#line 1813 "y.tab.c"
    break;

  case 30: /* CASES: CASE CASES  */
#line 358 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1821 "y.tab.c"
    break;

  case 31: /* CASES: %empty  */
#line 362 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 1829 "y.tab.c"
    break;

  case 32: /* CASE: TK_CASE E INIT COMANDOS  */
#line 367 "sintaticoP.y"
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
#line 1858 "y.tab.c"
    break;

  case 33: /* CASE: TK_DEFAULT INIT COMANDOS  */
#line 392 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
				listaEscopo.pop_back();
				infobloco.pop_back();
				
			}
#line 1869 "y.tab.c"
    break;

  case 34: /* E: E '+' E  */
#line 400 "sintaticoP.y"
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
				
			}
#line 1935 "y.tab.c"
    break;

  case 35: /* E: E '-' E  */
#line 462 "sintaticoP.y"
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
#line 1989 "y.tab.c"
    break;

  case 36: /* E: E '*' E  */
#line 512 "sintaticoP.y"
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
#line 2043 "y.tab.c"
    break;

  case 37: /* E: E '/' E  */
#line 562 "sintaticoP.y"
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
#line 2097 "y.tab.c"
    break;

  case 38: /* E: E '%' E  */
#line 612 "sintaticoP.y"
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
#line 2152 "y.tab.c"
    break;

  case 39: /* E: E '^' E  */
#line 663 "sintaticoP.y"
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
#line 2207 "y.tab.c"
    break;

  case 40: /* E: '-' E  */
#line 714 "sintaticoP.y"
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
#line 2223 "y.tab.c"
    break;

  case 41: /* E: '(' E ')'  */
#line 726 "sintaticoP.y"
                        {
				yyval.label = yyvsp[-1].label;
				yyval.tipo = yyvsp[-1].tipo;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label +";\n";
			}
#line 2233 "y.tab.c"
    break;

  case 42: /* E: E TK_MAIOR_IGUAL E  */
#line 732 "sintaticoP.y"
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
#line 2276 "y.tab.c"
    break;

  case 43: /* E: E TK_MENOR_IGUAL E  */
#line 771 "sintaticoP.y"
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
#line 2318 "y.tab.c"
    break;

  case 44: /* E: E TK_MAIOR E  */
#line 809 "sintaticoP.y"
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
#line 2360 "y.tab.c"
    break;

  case 45: /* E: E TK_MENOR E  */
#line 847 "sintaticoP.y"
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
#line 2402 "y.tab.c"
    break;

  case 46: /* E: E TK_IGUALDADE E  */
#line 885 "sintaticoP.y"
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
#line 2441 "y.tab.c"
    break;

  case 47: /* E: E TK_DESIGUALDADE E  */
#line 920 "sintaticoP.y"
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
#line 2480 "y.tab.c"
    break;

  case 48: /* E: E TK_CONJUNCAO E  */
#line 955 "sintaticoP.y"
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
#line 2501 "y.tab.c"
    break;

  case 49: /* E: E TK_DISNJUNCAO E  */
#line 972 "sintaticoP.y"
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
#line 2523 "y.tab.c"
    break;

  case 50: /* E: '!' E  */
#line 990 "sintaticoP.y"
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
#line 2543 "y.tab.c"
    break;

  case 51: /* E: E TK_ALT  */
#line 1006 "sintaticoP.y"
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
#line 2562 "y.tab.c"
    break;

  case 52: /* E: '(' TK_TIPO_INT ')' E  */
#line 1021 "sintaticoP.y"
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
#line 2579 "y.tab.c"
    break;

  case 53: /* E: '(' TK_TIPO_FLOAT ')' E  */
#line 1034 "sintaticoP.y"
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
#line 2597 "y.tab.c"
    break;

  case 54: /* E: '(' TK_TIPO_BOOL ')' E  */
#line 1048 "sintaticoP.y"
                        {
				if(yyvsp[0].tipo.compare("bool") != 0){
				yyerror("Tipo de expressão incompativel para a conversão");
				}
				yyval.label = gentempcode("bool");
				yyval.tipo = yyvsp[0].tipo;
				yyval.traducao =  yyvsp[0].traducao +"\t" + yyval.label + " = " + "(bool) " + yyvsp[0].label+";\n"; 
			}
#line 2610 "y.tab.c"
    break;

  case 55: /* E: ATB  */
#line 1057 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2618 "y.tab.c"
    break;

  case 56: /* E: C_LOOP  */
#line 1061 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2626 "y.tab.c"
    break;

  case 57: /* E: TK_NUM  */
#line 1065 "sintaticoP.y"
                        {
				yyval.label = gentempcode("int");
				yyval.tipo = "int";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";

				//cout << "Variavel atribuida " << $$.val << endl;
			}
#line 2640 "y.tab.c"
    break;

  case 58: /* E: TK_REAL  */
#line 1075 "sintaticoP.y"
                        {
				yyval.label = gentempcode("float");
				yyval.tipo = "float";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2652 "y.tab.c"
    break;

  case 59: /* E: TK_CHAR  */
#line 1083 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.tipo = "char";
				yyval.classe = "String";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2664 "y.tab.c"
    break;

  case 60: /* E: TK_BOOL  */
#line 1090 "sintaticoP.y"
                                {
				yyval.label = gentempcode("bool");
				yyval.tipo = "bool";
				yyval.classe = "Boolean";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label +";\n";
			}
#line 2676 "y.tab.c"
    break;

  case 61: /* E: TK_STRING  */
#line 1098 "sintaticoP.y"
                        {
				cout << yyvsp[0].label << endl;
				yyval.label = gentempcode("string");
				yyval.tipo = "string";
				yyval.classe = "String";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label +";\n";
			}
#line 2689 "y.tab.c"
    break;

  case 62: /* E: TK_ID  */
#line 1107 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				flag = buscarSimbolos(yyvsp[0].label);
				cout <<"variavel encontrada. " << flag.endereco << endl;
				if(flag.endereco.compare("") == 0){
					yyerror("Variavel não declarada");
				}
				yyval.label = flag.endereco;
				yyval.val = flag.val;
				yyval.tipo = flag.tipo;
				yyval.classe = flag.classe;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				//cout << "Variavel atribuida " << $$.val << endl;

			}
#line 2709 "y.tab.c"
    break;

  case 63: /* E: TK_CONV  */
#line 1123 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.val = yyvsp[0].label;
				//cout << $$.val << endl;
			}
#line 2719 "y.tab.c"
    break;

  case 64: /* ATB: TK_ID '=' E  */
#line 1130 "sintaticoP.y"
                        {
				tabelaSimbolos flag;

				flag = buscarSimbolos(yyvsp[-2].label);
				if(flag.endereco.compare("") == 0){
					flag = inserirSimbolos(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].classe, "local");
				}else if(flag.tipo.compare(yyvsp[0].tipo) != 0){
					//checarlista();
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				yyval.label = flag.endereco;
				yyval.tipo = yyvsp[0].tipo;
				yyval.val = yyvsp[0].val;
				flag.val = yyval.val;
				alterarSimbolos(flag);
				//cout << flag.nome << endl;
				if(yyvsp[0].tipo.compare("string") != 0){
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				}else{
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t"+ "strcpy(" + yyval.label + ","+ yyvsp[0].label + ");\n";
				}
			}
#line 2747 "y.tab.c"
    break;

  case 65: /* C_LOOP: TK_BREAK  */
#line 1154 "sintaticoP.y"
                        {
				escopo alvo;
				alvo = buscarbloco(1);

				yyval.traducao = "\tgo to FIM " + alvo.label + ";\n";
			}
#line 2758 "y.tab.c"
    break;

  case 66: /* C_LOOP: TK_NEXT  */
#line 1161 "sintaticoP.y"
                        {
				escopo alvo;
				alvo = buscarbloco(1);

				yyval.traducao = "\tgo to inicio-" + alvo.label + ";\n";
			}
#line 2769 "y.tab.c"
    break;


#line 2773 "y.tab.c"

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

#line 1168 "sintaticoP.y"


#include "lex.yy.c"

int yyparse();
using namespace std;
string gentempcode(string tipo)
{
	atributos x;
	var_temp_qnt++;
	x.label = "t" + to_string(var_temp_qnt);
	x.tipo = tipo;

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
			cout << j << " simbolo " << listaEscopo[i][j].nome<< endl;
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
void alterarSimbolos(tabelaSimbolos x){
	int i, j, k, cont;
	cont = listaEscopo.size()-1;
	cout << "alterando variavel" <<endl;
	for(i = cont; i >=0; i--){
		for(j = 0; j<listaEscopo[i].size(); j++){
		//	cout << j << " simbolos " << listaEscopo[i][j].nome<< endl;
			if(x.nome.compare(listaEscopo[i][j].nome) == 0  && (i == cont || listaEscopo[i][j].mod == 1) ){
				listaEscopo[i].insert(listaEscopo[i].begin()+j, x);
				k += j;
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
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe, string acesso){
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
