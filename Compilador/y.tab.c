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
    TK_BOOL = 262,                 /* TK_BOOL  */
    TK_MAIN = 263,                 /* TK_MAIN  */
    TK_ID = 264,                   /* TK_ID  */
    TK_TIPO_INT = 265,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 266,           /* TK_TIPO_FLOAT  */
    TK_TIPO_CHAR = 267,            /* TK_TIPO_CHAR  */
    TK_TIPO_BOOL = 268,            /* TK_TIPO_BOOL  */
    TK_CONV = 269,                 /* TK_CONV  */
    TK_MAIOR_IGUAL = 270,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 271,          /* TK_MENOR_IGUAL  */
    TK_MAIOR = 272,                /* TK_MAIOR  */
    TK_MENOR = 273,                /* TK_MENOR  */
    TK_IGUALDADE = 274,            /* TK_IGUALDADE  */
    TK_DESIGUALDADE = 275,         /* TK_DESIGUALDADE  */
    TK_CONJUNCAO = 276,            /* TK_CONJUNCAO  */
    TK_DISNJUNCAO = 277,           /* TK_DISNJUNCAO  */
    TK_FIM = 278,                  /* TK_FIM  */
    TK_ERROR = 279                 /* TK_ERROR  */
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
#define TK_BOOL 262
#define TK_MAIN 263
#define TK_ID 264
#define TK_TIPO_INT 265
#define TK_TIPO_FLOAT 266
#define TK_TIPO_CHAR 267
#define TK_TIPO_BOOL 268
#define TK_CONV 269
#define TK_MAIOR_IGUAL 270
#define TK_MENOR_IGUAL 271
#define TK_MAIOR 272
#define TK_MENOR 273
#define TK_IGUALDADE 274
#define TK_DESIGUALDADE 275
#define TK_CONJUNCAO 276
#define TK_DISNJUNCAO 277
#define TK_FIM 278
#define TK_ERROR 279

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
  YYSYMBOL_TK_BOOL = 7,                    /* TK_BOOL  */
  YYSYMBOL_TK_MAIN = 8,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 9,                      /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 10,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 11,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_CHAR = 12,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_BOOL = 13,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_CONV = 14,                   /* TK_CONV  */
  YYSYMBOL_TK_MAIOR_IGUAL = 15,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 16,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_MAIOR = 17,                  /* TK_MAIOR  */
  YYSYMBOL_TK_MENOR = 18,                  /* TK_MENOR  */
  YYSYMBOL_TK_IGUALDADE = 19,              /* TK_IGUALDADE  */
  YYSYMBOL_TK_DESIGUALDADE = 20,           /* TK_DESIGUALDADE  */
  YYSYMBOL_TK_CONJUNCAO = 21,              /* TK_CONJUNCAO  */
  YYSYMBOL_TK_DISNJUNCAO = 22,             /* TK_DISNJUNCAO  */
  YYSYMBOL_TK_FIM = 23,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 24,                  /* TK_ERROR  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_30_ = 30,                       /* '^'  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '!'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_S = 39,                         /* S  */
  YYSYMBOL_BLOCO = 40,                     /* BLOCO  */
  YYSYMBOL_COMANDOS = 41,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 42,                   /* COMANDO  */
  YYSYMBOL_E = 43                          /* E  */
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
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  79

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
       2,     2,     2,    36,     2,     2,     2,    29,     2,     2,
      31,    32,    27,    25,     2,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    94,   100,   105,   110,   114,   118,   122,
     126,   132,   194,   244,   294,   344,   395,   446,   458,   464,
     503,   541,   579,   617,   652,   687,   704,   722,   738,   751,
     765,   769,   788,   798,   806,   814,   821,   836
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
  "TK_REAL", "TK_CHAR", "TK_BOOL", "TK_MAIN", "TK_ID", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL", "TK_CONV",
  "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL", "TK_MAIOR", "TK_MENOR",
  "TK_IGUALDADE", "TK_DESIGUALDADE", "TK_CONJUNCAO", "TK_DISNJUNCAO",
  "TK_FIM", "TK_ERROR", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('",
  "')'", "'{'", "'}'", "';'", "'!'", "'='", "$accept", "S", "BLOCO",
  "COMANDOS", "COMANDO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    -4,     5,   -18,   -26,   -21,   -17,    39,   -26,   -26,
     -26,   -26,   -26,   -25,     6,     8,     9,    24,   -26,    71,
      53,    71,     0,    39,    93,    71,     1,     2,     3,    12,
     -20,    11,    22,    23,   114,   132,   -26,   -26,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   -26,   132,   -26,   -26,   -26,   -26,    71,    71,
      71,   -26,   170,   170,   170,   170,   164,   164,   148,   132,
     -20,   -20,   -16,   -16,   -16,   -26,   132,   132,   132
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,    32,
      33,    34,    35,    36,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    27,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,    31,     7,     8,     9,    10,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      11,    12,    13,    14,    15,    16,    28,    29,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -26,    34,   -26,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,    22,    23,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    34,    35,     1,     3,     4,    53,    48,    49,    50,
      51,     6,    25,     5,    51,    26,     7,    27,    28,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    29,    36,     0,    54,    55,    56,    76,
      77,    78,     9,    58,    10,    11,    12,    57,    13,    14,
      15,    16,    17,    18,    59,    60,     9,    37,    10,    11,
      12,     0,    13,    31,    32,    19,    33,    18,     0,     0,
      20,     0,     0,     0,     9,    21,    10,    11,    12,    19,
      13,     0,     0,     0,    20,    18,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    21,    38,    39,
      40,    41,    42,    43,    44,    45,     0,     0,    46,    47,
      48,    49,    50,    51,     0,     0,     0,     0,    52,    38,
      39,    40,    41,    42,    43,    44,    45,     0,     0,    46,
      47,    48,    49,    50,    51,     0,    61,    38,    39,    40,
      41,    42,    43,    44,    45,     0,     0,    46,    47,    48,
      49,    50,    51,    38,    39,    40,    41,    42,    43,    44,
       0,     0,     0,    46,    47,    48,    49,    50,    51,    38,
      39,    40,    41,    42,    43,    38,    39,    40,    41,    46,
      47,    48,    49,    50,    51,    46,    47,    48,    49,    50,
      51
};

static const yytype_int8 yycheck[] =
{
      19,    20,    21,    10,     8,     0,    25,    27,    28,    29,
      30,    32,    37,    31,    30,     9,    33,     9,     9,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     9,    34,    -1,    35,    35,    35,    58,
      59,    60,     3,    32,     5,     6,     7,    35,     9,    10,
      11,    12,    13,    14,    32,    32,     3,    23,     5,     6,
       7,    -1,     9,    10,    11,    26,    13,    14,    -1,    -1,
      31,    -1,    -1,    -1,     3,    36,     5,     6,     7,    26,
       9,    -1,    -1,    -1,    31,    14,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    27,    28,    29,    30,    -1,    32,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    27,
      28,    29,    30,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    15,
      16,    17,    18,    19,    20,    15,    16,    17,    18,    25,
      26,    27,    28,    29,    30,    25,    26,    27,    28,    29,
      30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    39,     8,     0,    31,    32,    33,    40,     3,
       5,     6,     7,     9,    10,    11,    12,    13,    14,    26,
      31,    36,    41,    42,    43,    37,     9,     9,     9,     9,
      43,    10,    11,    13,    43,    43,    34,    41,    15,    16,
      17,    18,    19,    20,    21,    22,    25,    26,    27,    28,
      29,    30,    35,    43,    35,    35,    35,    35,    32,    32,
      32,    32,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    41,    41,    42,    42,    42,    42,
      42,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     4,     4,
       4,     3,     1,     1,     1,     1,     1,     1
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
#line 70 "sintaticoP.y"
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
#line 1321 "y.tab.c"
    break;

  case 3: /* BLOCO: '{' COMANDOS '}'  */
#line 95 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1329 "y.tab.c"
    break;

  case 4: /* COMANDOS: COMANDO COMANDOS  */
#line 101 "sintaticoP.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1337 "y.tab.c"
    break;

  case 5: /* COMANDOS: %empty  */
#line 105 "sintaticoP.y"
                        {
				yyval.traducao = "";
			}
#line 1345 "y.tab.c"
    break;

  case 6: /* COMANDO: E ';'  */
#line 111 "sintaticoP.y"
                        {
				yyval = yyvsp[-1];
			}
#line 1353 "y.tab.c"
    break;

  case 7: /* COMANDO: TK_TIPO_INT TK_ID ';'  */
#line 115 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "int", "Number");
			}
#line 1361 "y.tab.c"
    break;

  case 8: /* COMANDO: TK_TIPO_FLOAT TK_ID ';'  */
#line 119 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "float", "Number");
			}
#line 1369 "y.tab.c"
    break;

  case 9: /* COMANDO: TK_TIPO_CHAR TK_ID ';'  */
#line 123 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "char", "Character");
			}
#line 1377 "y.tab.c"
    break;

  case 10: /* COMANDO: TK_TIPO_BOOL TK_ID ';'  */
#line 127 "sintaticoP.y"
                        {
				inserirSimbolos(yyvsp[-1].label, "bool", "Boolean");
			}
#line 1385 "y.tab.c"
    break;

  case 11: /* E: E '+' E  */
#line 133 "sintaticoP.y"
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
#line 1451 "y.tab.c"
    break;

  case 12: /* E: E '-' E  */
#line 195 "sintaticoP.y"
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
#line 1505 "y.tab.c"
    break;

  case 13: /* E: E '*' E  */
#line 245 "sintaticoP.y"
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
#line 1559 "y.tab.c"
    break;

  case 14: /* E: E '/' E  */
#line 295 "sintaticoP.y"
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
#line 1613 "y.tab.c"
    break;

  case 15: /* E: E '%' E  */
#line 345 "sintaticoP.y"
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
#line 1668 "y.tab.c"
    break;

  case 16: /* E: E '^' E  */
#line 396 "sintaticoP.y"
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
#line 1723 "y.tab.c"
    break;

  case 17: /* E: '-' E  */
#line 447 "sintaticoP.y"
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
#line 1739 "y.tab.c"
    break;

  case 18: /* E: '(' E ')'  */
#line 459 "sintaticoP.y"
                        {
				yyval.label = gentempcode(yyvsp[-1].tipo);
				yyval.tipo = yyvsp[-1].tipo;
				yyval.traducao = yyvsp[-1].traducao + "\t" + yyval.label + " = " + yyvsp[-1].label +";\n";
			}
#line 1749 "y.tab.c"
    break;

  case 19: /* E: E TK_MAIOR_IGUAL E  */
#line 465 "sintaticoP.y"
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
#line 1792 "y.tab.c"
    break;

  case 20: /* E: E TK_MENOR_IGUAL E  */
#line 504 "sintaticoP.y"
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
#line 1834 "y.tab.c"
    break;

  case 21: /* E: E TK_MAIOR E  */
#line 542 "sintaticoP.y"
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
#line 1876 "y.tab.c"
    break;

  case 22: /* E: E TK_MENOR E  */
#line 580 "sintaticoP.y"
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
#line 1918 "y.tab.c"
    break;

  case 23: /* E: E TK_IGUALDADE E  */
#line 618 "sintaticoP.y"
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
#line 1957 "y.tab.c"
    break;

  case 24: /* E: E TK_DESIGUALDADE E  */
#line 653 "sintaticoP.y"
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
#line 1996 "y.tab.c"
    break;

  case 25: /* E: E TK_CONJUNCAO E  */
#line 688 "sintaticoP.y"
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
#line 2017 "y.tab.c"
    break;

  case 26: /* E: E TK_DISNJUNCAO E  */
#line 705 "sintaticoP.y"
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
#line 2039 "y.tab.c"
    break;

  case 27: /* E: '!' E  */
#line 723 "sintaticoP.y"
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
#line 2059 "y.tab.c"
    break;

  case 28: /* E: '(' TK_TIPO_INT ')' E  */
#line 739 "sintaticoP.y"
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
#line 2076 "y.tab.c"
    break;

  case 29: /* E: '(' TK_TIPO_FLOAT ')' E  */
#line 752 "sintaticoP.y"
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
#line 2094 "y.tab.c"
    break;

  case 30: /* E: '(' TK_TIPO_BOOL ')' E  */
#line 766 "sintaticoP.y"
                        {
				yyerror("Tipo de expressão incompativel para a conversão");
			}
#line 2102 "y.tab.c"
    break;

  case 31: /* E: TK_ID '=' E  */
#line 770 "sintaticoP.y"
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
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2125 "y.tab.c"
    break;

  case 32: /* E: TK_NUM  */
#line 789 "sintaticoP.y"
                        {
				yyval.label = gentempcode("int");
				yyval.tipo = "int";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";

				//cout << "Variavel atribuida " << $$.val << endl;
			}
#line 2139 "y.tab.c"
    break;

  case 33: /* E: TK_REAL  */
#line 799 "sintaticoP.y"
                        {
				yyval.label = gentempcode("float");
				yyval.tipo = "float";
				yyval.classe = "Number";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2151 "y.tab.c"
    break;

  case 34: /* E: TK_CHAR  */
#line 807 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.tipo = "char";
				yyval.classe = "String";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2163 "y.tab.c"
    break;

  case 35: /* E: TK_BOOL  */
#line 814 "sintaticoP.y"
                                {
				yyval.label = gentempcode("bool");
				yyval.tipo = "bool";
				yyval.classe = "Boolean";
				yyval.val = yyvsp[0].label;
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label +";\n";
			}
#line 2175 "y.tab.c"
    break;

  case 36: /* E: TK_ID  */
#line 822 "sintaticoP.y"
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
#line 2194 "y.tab.c"
    break;

  case 37: /* E: TK_CONV  */
#line 837 "sintaticoP.y"
                        {
				yyval.label = gentempcode("char");
				yyval.val = yyvsp[0].label;
				//cout << $$.val << endl;
			}
#line 2204 "y.tab.c"
    break;


#line 2208 "y.tab.c"

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

#line 844 "sintaticoP.y"


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
