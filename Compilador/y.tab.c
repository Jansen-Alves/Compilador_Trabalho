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
#define bool int
#define TRUE 1
#define FALSE 0
#define YYSTYPE atributos

using namespace std;

int var_temp_qnt;
string Tipagens;
int qtd_simb;

struct tabelaSimbolos{
	string nome;
	string tipo;
	string classe;
	string endereco;
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

int yylex(void);
void yyerror(string);
string gentempcode(string tipo);
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe);
void alterarSimbolos(tabelaSimbolos x);
bool verificarsimbolos(string nome);
void checarlista();
void tipagem();
tabelaSimbolos buscarSimbolos(string nome);

bool traducao(string op);

tabelaSimbolos Listageral[20];
atributos Listaatributos[50];

#line 118 "y.tab.c"

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
  YYSYMBOL_TK_TIPO_CHAR = 13,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_BOOL = 14,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_CONV = 15,                   /* TK_CONV  */
  YYSYMBOL_TK_MAIOR_IGUAL = 16,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 17,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_MAIOR = 18,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MENOR = 19,                  /* TK_MENOR  */
  YYSYMBOL_TK_IGUALDADE = 20,              /* TK_IGUALDADE  */
  YYSYMBOL_TK_DESIGUALDADE = 21,           /* TK_DESIGUALDADE  */
  YYSYMBOL_TK_CONJUNCAO = 22,              /* TK_CONJUNCAO  */
  YYSYMBOL_TK_DISNJUNCAO = 23,             /* TK_DISNJUNCAO  */
  YYSYMBOL_TK_ALT = 24,                    /* TK_ALT  */
  YYSYMBOL_TK_IF = 25,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 26,                   /* TK_ELSE  */
  YYSYMBOL_TK_DO = 27,                     /* TK_DO  */
  YYSYMBOL_TK_WHILE = 28,                  /* TK_WHILE  */
  YYSYMBOL_TK_FOR = 29,                    /* TK_FOR  */
  YYSYMBOL_TK_SWITCH = 30,                 /* TK_SWITCH  */
  YYSYMBOL_TK_FIM = 31,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 32,                  /* TK_ERROR  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_38_ = 38,                       /* '^'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_S = 47,                         /* S  */
  YYSYMBOL_BLOCO = 48,                     /* BLOCO  */
  YYSYMBOL_COMANDOS = 49,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 50,                   /* COMANDO  */
  YYSYMBOL_CONTROLES = 51,                 /* CONTROLES  */
  YYSYMBOL_E = 52                          /* E  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
       2,     2,     2,    45,     2,     2,     2,    37,     2,     2,
      39,    40,    35,    33,     2,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    96,   102,   107,   112,   116,   119,   123,
     127,   131,   136,   151,   167,   183,   199,   229,   291,   341,
     391,   441,   492,   543,   555,   561,   600,   638,   676,   714,
     749,   784,   801,   819,   835,   849,   862,   876,   880,   904,
     914,   922,   930,   937,   946,   961
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
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL",
  "TK_CONV", "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL", "TK_MAIOR", "TK_MENOR",
  "TK_IGUALDADE", "TK_DESIGUALDADE", "TK_CONJUNCAO", "TK_DISNJUNCAO",
  "TK_ALT", "TK_IF", "TK_ELSE", "TK_DO", "TK_WHILE", "TK_FOR", "TK_SWITCH",
  "TK_FIM", "TK_ERROR", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('",
  "')'", "'{'", "'}'", "';'", "'='", "'!'", "$accept", "S", "BLOCO",
  "COMANDOS", "COMANDO", "CONTROLES", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    -4,     1,   -28,   -30,   -24,   -29,    66,   -30,   -30,
     -30,   -30,   -30,   -30,    -6,    19,    44,    48,    49,   -30,
     120,   -29,   120,    21,   120,   107,   120,    26,    66,   -30,
     150,   120,    18,    42,    43,    45,   262,    59,   262,    79,
     -15,    50,    52,    56,   288,   338,   -30,   -30,   120,   120,
     120,   120,   120,   120,   120,   120,   -30,   120,   120,   120,
     120,   120,   120,   -30,   338,   -30,   -30,   -30,   -30,    71,
     120,   -30,    54,   120,   120,   120,   -30,   384,   384,   384,
     384,   361,   361,    29,   338,   -15,   -15,   -10,   -10,   -10,
     -14,   -29,   178,   120,   338,   338,   338,   -30,   -30,   206,
     120,   234,   120,   313,   -29,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,    39,
      40,    41,    43,    42,    44,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,    33,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     6,    38,     8,     9,    10,    11,    12,
       0,    14,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    17,    18,    19,    20,    21,
      22,     0,     0,     0,    35,    36,    37,    13,    15,     0,
       0,     0,     0,     0,     0,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -21,    73,   -30,   -30,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,    27,    28,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,     4,    36,     1,    38,     3,    40,    44,    45,    56,
      56,     5,     7,    64,    56,    69,     6,    71,    57,    58,
      59,    60,    61,    62,    62,    59,    60,    61,    62,    32,
      77,    78,    79,    80,    81,    82,    83,    84,    31,    85,
      86,    87,    88,    89,    90,    48,    49,    50,    51,    52,
      53,    54,    92,    56,    33,    94,    95,    96,    34,    35,
      39,    65,    57,    58,    59,    60,    61,    62,    46,     9,
      97,    10,    11,    12,    13,    99,    14,    15,    16,    17,
      18,    19,   101,   105,   103,    66,    67,    70,    68,    72,
      73,    20,    74,    21,    22,    23,    75,    91,    93,     0,
      24,    47,     0,     0,     0,    25,     0,     0,     0,     0,
       9,    26,    10,    11,    12,    13,     0,    14,    41,    42,
       0,    43,    19,     9,     0,    10,    11,    12,    13,     0,
      14,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    26,     0,    24,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    26,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,    63,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,    98,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,   100,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,   102,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     7,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,     0,    76,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,     0,   104,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    48,    49,    50,
      51,    52,    53,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    62,
      48,    49,    50,    51,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62
};

static const yytype_int8 yycheck[] =
{
      21,     0,    20,    11,    22,     9,    24,    25,    26,    24,
      24,    39,    41,    31,    24,    36,    40,    38,    33,    34,
      35,    36,    37,    38,    38,    35,    36,    37,    38,    10,
      48,    49,    50,    51,    52,    53,    54,    55,    44,    57,
      58,    59,    60,    61,    62,    16,    17,    18,    19,    20,
      21,    22,    70,    24,    10,    73,    74,    75,    10,    10,
      39,    43,    33,    34,    35,    36,    37,    38,    42,     3,
      91,     5,     6,     7,     8,    93,    10,    11,    12,    13,
      14,    15,   100,   104,   102,    43,    43,    28,    43,    10,
      40,    25,    40,    27,    28,    29,    40,    26,    44,    -1,
      34,    28,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
       3,    45,     5,     6,     7,     8,    -1,    10,    11,    12,
      -1,    14,    15,     3,    -1,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    34,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    43,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    -1,    -1,    41,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,    40,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    -1,    40,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    47,     9,     0,    39,    40,    41,    48,     3,
       5,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      25,    27,    28,    29,    34,    39,    45,    49,    50,    51,
      52,    44,    10,    10,    10,    10,    52,    48,    52,    39,
      52,    11,    12,    14,    52,    52,    42,    49,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    33,    34,    35,
      36,    37,    38,    43,    52,    43,    43,    43,    43,    48,
      28,    48,    10,    40,    40,    40,    40,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    26,    52,    44,    52,    52,    52,    48,    43,    52,
      43,    52,    43,    52,    40,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     2,     1,     3,     3,
       3,     3,     3,     5,     3,     5,    11,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     4,     4,     3,     1,
       1,     1,     1,     1,     1,     1
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
  case 2: /* S: TK_TIPO_INT TK_MAIN '(' ')' BLOCO  */
#line 72 "sintaticoP.y"
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
				for(i=1; i<=var_temp_qnt; i++){
					codigo += "\t" + Listaatributos[i].tipo +" "+ Listaatributos[i].label + ";\n";
				};
				codigo+= "\n";
				codigo += yyvsp[0].traducao;
								
				codigo += 	"\treturn 0;"
							"\n}";
				
				cout << codigo << endl;
				//checarlista();
			}
#line 1404 "y.tab.c"
    break;

  case 3: /* BLOCO: '{' COMANDOS '}'  */
#line 97 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1412 "y.tab.c"
    break;

  case 4: /* COMANDOS: COMANDO COMANDOS  */
#line 103 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1420 "y.tab.c"
    break;

  case 5: /* COMANDOS: %empty  */
#line 107 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 1428 "y.tab.c"
    break;

  case 6: /* COMANDO: E ';'  */
#line 113 "sintaticoP.y"
                        {
				yyval = yyvsp[-1];
			}
#line 1436 "y.tab.c"
    break;

  case 7: /* COMANDO: CONTROLES  */
#line 116 "sintaticoP.y"
                                  {
				yyval = yyvsp[0];
			}
#line 1444 "y.tab.c"
    break;

  case 8: /* COMANDO: TK_TIPO_INT TK_ID ';'  */
#line 120 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "int", "Number");
			}
#line 1452 "y.tab.c"
    break;

  case 9: /* COMANDO: TK_TIPO_FLOAT TK_ID ';'  */
#line 124 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "float", "Number");
			}
#line 1460 "y.tab.c"
    break;

  case 10: /* COMANDO: TK_TIPO_CHAR TK_ID ';'  */
#line 128 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "char", "Character");
			}
#line 1468 "y.tab.c"
    break;

  case 11: /* COMANDO: TK_TIPO_BOOL TK_ID ';'  */
#line 132 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "bool", "Boolean");
			}
#line 1476 "y.tab.c"
    break;

  case 12: /* CONTROLES: TK_IF E BLOCO  */
#line 137 "sintaticoP.y"
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
#line 1495 "y.tab.c"
    break;

  case 13: /* CONTROLES: TK_IF E BLOCO TK_ELSE BLOCO  */
#line 152 "sintaticoP.y"
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
#line 1515 "y.tab.c"
    break;

  case 14: /* CONTROLES: TK_WHILE E BLOCO  */
#line 168 "sintaticoP.y"
                        {
				string jp, ciclowhile, iniwhile;
				atributos tst;
				if(yyvsp[-1].tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				iniwhile = "\tinicio_"+tst.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ yyvsp[-1].label+";\n";
				jp = iniwhile +yyvsp[-1].traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+tst.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				yyval.traducao = jp + yyvsp[0].traducao + ciclowhile + "\tFIM "+tst.label+";\n";

			}
#line 1535 "y.tab.c"
    break;

  case 15: /* CONTROLES: TK_DO BLOCO TK_WHILE E ';'  */
#line 184 "sintaticoP.y"
                        {
				string jp, ciclowhile, iniwhile;
				atributos tst;
				if(yyvsp[-1].tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tst.label = gentempcode("bool");
				iniwhile = "\tinicio_"+tst.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ yyvsp[-1].label+";\n";
				jp = iniwhile +yyvsp[-3].traducao + yyvsp[-1].traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+tst.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				yyval.traducao = jp + ciclowhile + "\tFIM "+tst.label+";\n";

			}
#line 1555 "y.tab.c"
    break;

  case 16: /* CONTROLES: TK_FOR '(' TK_ID '=' E ';' E ';' E ')' BLOCO  */
#line 200 "sintaticoP.y"
                        {
				/*string jp, E1;
				atributos tst, vari;
				if($7.tipo.compare("bool") != 0){
					yyerror("Expressão incompativel para a operação de controle");
				}
				tabelaSimbolos flag;
				flag = buscarSimbolos($3.label);
				if(flag.endereco.compare("") == 0){
					flag = inserirSimbolos($3.label, $5.tipo, $5.classe);
				}else if(flag.tipo.compare($5.tipo) != 0){
					//checarlista();
					yyerror("Atribuição incorreta, tipo de variavel incompativel");
					
				}
				vari.label = flag.
				flag.val = vari.val;
				alterarSimbolos(flag);
				//cout << flag.nome << endl;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $3.label + ";\n";
				tst.label = gentempcode("bool");
				iniwhile = "\tinicio_"+tst.label +";\n";

				tst.traducao = "\t"+tst.label + " = " +"!"+ $4.label+";\n";
				jp = iniwhile +$2.traducao + $4.traducao + tst.traducao+"\tif("+ tst.label+") go to FIM "+tst.label+";\n";
				ciclowhile = "\tgo to inicio_"+tst.label +";\n";
				$$.traducao = jp + ciclowhile + "\tFIM "+tst.label+";\n";*/
			}
#line 1588 "y.tab.c"
    break;

  case 17: /* E: E '+' E  */
#line 230 "sintaticoP.y"
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
#line 1654 "y.tab.c"
    break;

  case 18: /* E: E '-' E  */
#line 292 "sintaticoP.y"
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
#line 1708 "y.tab.c"
    break;

  case 19: /* E: E '*' E  */
#line 342 "sintaticoP.y"
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
#line 1762 "y.tab.c"
    break;

  case 20: /* E: E '/' E  */
#line 392 "sintaticoP.y"
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
#line 1816 "y.tab.c"
    break;

  case 21: /* E: E '%' E  */
#line 442 "sintaticoP.y"
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
#line 1871 "y.tab.c"
    break;

  case 22: /* E: E '^' E  */
#line 493 "sintaticoP.y"
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
#line 1926 "y.tab.c"
    break;

  case 23: /* E: '-' E  */
#line 544 "sintaticoP.y"
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
#line 1942 "y.tab.c"
    break;

  case 24: /* E: '(' E ')'  */
#line 556 "sintaticoP.y"
                        {
				yyval.label = gentempcode(yyvsp[-1].tipo);
				yyval.tipo = yyvsp[-1].tipo;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label +";\n";
			}
#line 1952 "y.tab.c"
    break;

  case 25: /* E: E TK_MAIOR_IGUAL E  */
#line 562 "sintaticoP.y"
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
#line 1995 "y.tab.c"
    break;

  case 26: /* E: E TK_MENOR_IGUAL E  */
#line 601 "sintaticoP.y"
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
#line 2037 "y.tab.c"
    break;

  case 27: /* E: E TK_MAIOR E  */
#line 639 "sintaticoP.y"
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
#line 2079 "y.tab.c"
    break;

  case 28: /* E: E TK_MENOR E  */
#line 677 "sintaticoP.y"
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
#line 2121 "y.tab.c"
    break;

  case 29: /* E: E TK_IGUALDADE E  */
#line 715 "sintaticoP.y"
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
#line 2160 "y.tab.c"
    break;

  case 30: /* E: E TK_DESIGUALDADE E  */
#line 750 "sintaticoP.y"
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
#line 2199 "y.tab.c"
    break;

  case 31: /* E: E TK_CONJUNCAO E  */
#line 785 "sintaticoP.y"
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
#line 2220 "y.tab.c"
    break;

  case 32: /* E: E TK_DISNJUNCAO E  */
#line 802 "sintaticoP.y"
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
#line 2242 "y.tab.c"
    break;

  case 33: /* E: '!' E  */
#line 820 "sintaticoP.y"
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
						" = " +"!"+ yyvsp[0].label +"("+ yyval.val+ ")"+ ";\n";
			}
#line 2262 "y.tab.c"
    break;

  case 34: /* E: E TK_ALT  */
#line 836 "sintaticoP.y"
                        {
				string x;
				if(yyvsp[-1].classe.compare("Number") != 0){
					yyerror("Tipo incompativeis para essa operação");
				}
				yyval.label = gentempcode(yyvsp[-1].tipo);
				yyval.tipo = yyvsp[-1].tipo;
				yyval.classe = yyvsp[-1].classe;

				yyvsp[-1].tipo.compare("int") == 0 ?  x = "1" : x = "1.0000";
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label + " "+ yyvsp[0].label[0] + " "+ x +";\n";
				
			}
#line 2280 "y.tab.c"
    break;

  case 35: /* E: '(' TK_TIPO_INT ')' E  */
#line 850 "sintaticoP.y"
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
#line 2297 "y.tab.c"
    break;

  case 36: /* E: '(' TK_TIPO_FLOAT ')' E  */
#line 863 "sintaticoP.y"
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
#line 2315 "y.tab.c"
    break;

  case 37: /* E: '(' TK_TIPO_BOOL ')' E  */
#line 877 "sintaticoP.y"
                        {
				yyerror("Tipo de expressão incompativel para a conversão");
			}
#line 2323 "y.tab.c"
    break;

  case 38: /* E: TK_ID '=' E  */
#line 881 "sintaticoP.y"
                        {
				tabelaSimbolos flag;

				flag = buscarSimbolos(yyvsp[-2].label);
				if(flag.endereco.compare("") == 0){
					flag = inserirSimbolos(yyvsp[-2].label, yyvsp[0].tipo, yyvsp[0].classe);
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
#line 2351 "y.tab.c"
    break;

  case 39: /* E: TK_NUM  */
#line 905 "sintaticoP.y"
                        {
				yyval.label = gentempcode("int");
				yyval.tipo = "int";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";

				//cout << "Variavel atribuida " << $$.val << endl;
			}
#line 2365 "y.tab.c"
    break;

  case 40: /* E: TK_REAL  */
#line 915 "sintaticoP.y"
                        {
				yyval.label = gentempcode("float");
				yyval.tipo = "float";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2377 "y.tab.c"
    break;

  case 41: /* E: TK_CHAR  */
#line 923 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.tipo = "char";
				yyval.classe = "String";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2389 "y.tab.c"
    break;

  case 42: /* E: TK_BOOL  */
#line 930 "sintaticoP.y"
                                {
				yyval.label = gentempcode("bool");
				yyval.tipo = "bool";
				yyval.classe = "Boolean";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label +";\n";
			}
#line 2401 "y.tab.c"
    break;

  case 43: /* E: TK_STRING  */
#line 938 "sintaticoP.y"
                        {
				cout << yyvsp[0].label << endl;
				yyval.label = gentempcode("string");
				yyval.tipo = "string";
				yyval.classe = "String";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label +";\n";
			}
#line 2414 "y.tab.c"
    break;

  case 44: /* E: TK_ID  */
#line 947 "sintaticoP.y"
                        {
				tabelaSimbolos flag;
				flag = buscarSimbolos(yyvsp[0].label);
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
#line 2433 "y.tab.c"
    break;

  case 45: /* E: TK_CONV  */
#line 962 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.val = yyvsp[0].label;
				//cout << $$.val << endl;
			}
#line 2443 "y.tab.c"
    break;


#line 2447 "y.tab.c"

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

#line 969 "sintaticoP.y"


#include "lex.yy.c"

int yyparse();

string gentempcode(string tipo)
{
	atributos x;
	var_temp_qnt++;
	x.label = "t" + to_string(var_temp_qnt);
	x.tipo = tipo;

	Listaatributos[var_temp_qnt] = x;
	return "t" + to_string(var_temp_qnt);
}
using namespace std;
bool traducao(string op){
	bool resp;
	if(op.compare("TRUE") ==0){
		resp = TRUE;
	}else{
		resp = FALSE;
	}
	return resp;
}
void tipagem(){
	int i;
	tabelaSimbolos x;

	for(i=0; i<qtd_simb; i++){
		x = Listageral[i];
		cout<< "\t" << x.tipo << " " << x.nome << endl;
	}
}
void checarlista(){
	int i;
	tabelaSimbolos x;

	for(i=0; i<qtd_simb; i++){
		x = Listageral[i];
		cout<< "\t nome: " << x.nome << " "<< "val: "<< x.val << " " <<" tipo: " << x.tipo << '-' << x.endereco << endl;
	}
}
tabelaSimbolos buscarSimbolos(string nome){
	tabelaSimbolos x;
	x.nome = "";
	x.tipo = "";
	x.endereco = "";
	int i;
	for(i = 0; i< qtd_simb; i++){
		if(nome.compare(Listageral[i].nome) == 0){
			//printf("Achei");
			x = Listageral[i];	
			return x;
		}
	}
	return x;
}
void alterarSimbolos(tabelaSimbolos x){
	int i;
	for(i = 0; i< qtd_simb; i++){
		if(x.nome.compare(Listageral[i].nome) == 0){
			Listageral[i] = x;
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
tabelaSimbolos inserirSimbolos(string nome, string tipo, string classe){
	tabelaSimbolos var; 
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
	var.endereco = gentempcode(tipo);
	
	//cout << var.nome << ' ' << var.tipo << ' ' << var.endereco <<endl;
	Listageral[qtd_simb] = var;
	qtd_simb++;

	return var;

}
int main(int argc, char* argv[])
{
	tabelaSimbolos x;
	int i;
	var_temp_qnt = 0;
	qtd_simb = 0;

	yyparse();
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				
