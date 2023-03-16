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
#line 4 "parser.y"

	#include <stdio.h>
	#include <string.h>
	#include "../extra.h"
	extern int yylineno;
	extern void *arvore;
	extern int contador;
	extern Pilha *myStack;
	int yylex(void);
	void yyerror(const char *);

#line 83 "temp/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_IDENTIFICADOR = 4,           /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_PR_FLOAT = 5,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_CHAR = 6,                 /* TK_PR_CHAR  */
  YYSYMBOL_TK_PR_IF = 7,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_THEN = 8,                 /* TK_PR_THEN  */
  YYSYMBOL_TK_PR_ELSE = 9,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 10,               /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_INPUT = 11,               /* TK_PR_INPUT  */
  YYSYMBOL_TK_PR_OUTPUT = 12,              /* TK_PR_OUTPUT  */
  YYSYMBOL_TK_PR_RETURN = 13,              /* TK_PR_RETURN  */
  YYSYMBOL_TK_PR_FOR = 14,                 /* TK_PR_FOR  */
  YYSYMBOL_TK_PR_BOOL = 15,                /* TK_PR_BOOL  */
  YYSYMBOL_TK_OC_LE = 16,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 17,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 18,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 19,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 20,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 21,                  /* TK_OC_OR  */
  YYSYMBOL_TK_LIT_FALSE = 22,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 23,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_LIT_INT = 24,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 25,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_CHAR = 26,               /* TK_LIT_CHAR  */
  YYSYMBOL_TK_ERRO = 27,                   /* TK_ERRO  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_30_ = 30,                       /* '['  */
  YYSYMBOL_31_ = 31,                       /* ']'  */
  YYSYMBOL_32_ = 32,                       /* '^'  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '<'  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_programa = 47,                  /* programa  */
  YYSYMBOL_lista_de_elementos = 48,        /* lista_de_elementos  */
  YYSYMBOL_declaracao = 49,                /* declaracao  */
  YYSYMBOL_lista_de_nome_de_variaveis = 50, /* lista_de_nome_de_variaveis  */
  YYSYMBOL_multidimensional = 51,          /* multidimensional  */
  YYSYMBOL_lista_literais = 52,            /* lista_literais  */
  YYSYMBOL_cabecalho_funcao = 53,          /* cabecalho_funcao  */
  YYSYMBOL_lista_parametros = 54,          /* lista_parametros  */
  YYSYMBOL_bloco_comandos = 55,            /* bloco_comandos  */
  YYSYMBOL_PSblock = 56,                   /* PSblock  */
  YYSYMBOL_PS = 57,                        /* PS  */
  YYSYMBOL_lista_comandos_simples = 58,    /* lista_comandos_simples  */
  YYSYMBOL_comandos_simples = 59,          /* comandos_simples  */
  YYSYMBOL_declaracao_local = 60,          /* declaracao_local  */
  YYSYMBOL_lista_de_nome_de_variaveis_locais = 61, /* lista_de_nome_de_variaveis_locais  */
  YYSYMBOL_variavel_local = 62,            /* variavel_local  */
  YYSYMBOL_atribuicao_local = 63,          /* atribuicao_local  */
  YYSYMBOL_lista_de_expressoes = 64,       /* lista_de_expressoes  */
  YYSYMBOL_lista_de_expressoes_ = 65,      /* lista_de_expressoes_  */
  YYSYMBOL_chamada_funcao = 66,            /* chamada_funcao  */
  YYSYMBOL_lista_expressoes_funcao = 67,   /* lista_expressoes_funcao  */
  YYSYMBOL_chamada_retorno = 68,           /* chamada_retorno  */
  YYSYMBOL_chamada_ctrl_fluxo = 69,        /* chamada_ctrl_fluxo  */
  YYSYMBOL_ctrl_repeticao = 70,            /* ctrl_repeticao  */
  YYSYMBOL_ctrl_condicional = 71,          /* ctrl_condicional  */
  YYSYMBOL_cond_else = 72,                 /* cond_else  */
  YYSYMBOL_multidimensional_ = 73,         /* multidimensional_  */
  YYSYMBOL_operandos = 74,                 /* operandos  */
  YYSYMBOL_expressao = 75,                 /* expressao  */
  YYSYMBOL_exp1 = 76,                      /* exp1  */
  YYSYMBOL_exp2 = 77,                      /* exp2  */
  YYSYMBOL_exp3 = 78,                      /* exp3  */
  YYSYMBOL_exp4 = 79,                      /* exp4  */
  YYSYMBOL_exp5 = 80,                      /* exp5  */
  YYSYMBOL_exp6 = 81,                      /* exp6  */
  YYSYMBOL_exp7 = 82,                      /* exp7  */
  YYSYMBOL_tipo = 83,                      /* tipo  */
  YYSYMBOL_literal = 84,                   /* literal  */
  YYSYMBOL_IDENTIFICADOR = 85              /* IDENTIFICADOR  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,    45,     2,     2,     2,    44,     2,     2,
      36,    33,    42,    40,    29,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      38,    37,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    66,    67,    68,    69,    70,    76,    85,
      92,    97,   104,   111,   116,   124,   142,   156,   166,   174,
     179,   186,   191,   201,   223,   228,   233,   238,   243,   248,
     253,   261,   269,   276,   281,   293,   302,   327,   339,   352,
     357,   364,   370,   375,   376,   381,   386,   387,   388,   397,
     407,   410,   419,   421,   422,   423,   425,   426,   428,   429,
     431,   432,   433,   435,   436,   437,   438,   439,   442,   443,
     444,   446,   447,   448,   449,   451,   452,   453,   455,   456,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_IDENTIFICADOR", "TK_PR_FLOAT", "TK_PR_CHAR", "TK_PR_IF",
  "TK_PR_THEN", "TK_PR_ELSE", "TK_PR_WHILE", "TK_PR_INPUT", "TK_PR_OUTPUT",
  "TK_PR_RETURN", "TK_PR_FOR", "TK_PR_BOOL", "TK_OC_LE", "TK_OC_GE",
  "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_LIT_FALSE",
  "TK_LIT_TRUE", "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_CHAR", "TK_ERRO",
  "';'", "','", "'['", "']'", "'^'", "')'", "'{'", "'}'", "'('", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "programa", "lista_de_elementos", "declaracao",
  "lista_de_nome_de_variaveis", "multidimensional", "lista_literais",
  "cabecalho_funcao", "lista_parametros", "bloco_comandos", "PSblock",
  "PS", "lista_comandos_simples", "comandos_simples", "declaracao_local",
  "lista_de_nome_de_variaveis_locais", "variavel_local",
  "atribuicao_local", "lista_de_expressoes", "lista_de_expressoes_",
  "chamada_funcao", "lista_expressoes_funcao", "chamada_retorno",
  "chamada_ctrl_fluxo", "ctrl_repeticao", "ctrl_condicional", "cond_else",
  "multidimensional_", "operandos", "expressao", "exp1", "exp2", "exp3",
  "exp4", "exp5", "exp6", "exp7", "tipo", "literal", "IDENTIFICADOR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,   -53,   -53,   -53,   -53,    26,   -53,     7,    69,    45,
     -53,    69,   -53,    17,    34,   -53,    30,   -53,   -53,    28,
      95,    77,    75,    70,    95,   -53,   -53,    79,    81,    85,
      80,    86,    77,   -53,    82,    17,    17,    42,   -53,   -53,
     -53,    85,    87,    89,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,    95,    93,    85,    69,   -53,    14,    42,    42,   -53,
     -53,   -53,   -53,   -53,    42,   102,   102,   -53,   -53,   -53,
     108,   110,    58,   -10,    39,    27,   -53,   -53,   -53,    93,
     -53,   -53,   138,   -53,   104,   115,   -53,    97,   -53,   -53,
     -53,   103,   -17,   -16,   -12,   -11,   -53,   -53,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,   -53,   -53,    95,   132,    42,    42,   -53,    42,   129,
     105,   -53,   110,    58,   -10,   -10,    39,    39,    39,    39,
      27,    27,   -53,   -53,   -53,   -53,   -53,    20,   108,   -53,
     112,    85,   -53,   -53,    85,   -53,   140,   113,   -53,    85,
     -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    80,    81,    82,    83,     0,     2,     0,     6,     0,
       1,     7,     4,    89,     8,    10,    14,     5,    22,     0,
       0,     0,     0,     0,     0,    89,     9,    13,     0,     0,
       0,    18,     0,    11,    89,     0,     0,     0,    20,    21,
      16,     0,     0,     0,    25,    26,    27,    28,    29,    47,
      46,     0,    40,     0,     0,    12,     0,     0,     0,    88,
      87,    84,    85,    86,     0,     0,     0,    55,    54,    79,
      45,    57,    59,    62,    67,    70,    74,    77,    53,    40,
      30,    19,    24,    31,    33,    35,    39,     0,    15,    17,
      42,     0,    44,     0,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    23,     0,     0,     0,     0,    41,     0,     0,
       0,    78,    56,    58,    60,    61,    65,    66,    63,    64,
      68,    69,    71,    72,    73,    32,    34,     0,    36,    43,
       0,     0,    37,    38,     0,    48,    51,     0,    49,     0,
      50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,    37,   -53,   -53,   130,   120,   -53,   109,   -39,
      18,    50,    84,   -53,   -53,    51,   -53,   -53,    88,   -53,
     -28,    52,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -34,
      71,    72,    -7,    57,     1,   -52,    31,     8,    54,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    14,    15,    28,     8,    23,    40,
      41,    19,    42,    43,    44,    83,    84,    45,    87,   115,
      67,    91,    47,    48,    49,    50,   148,    68,    69,    92,
      71,    72,    73,    74,    75,    76,    77,    51,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    46,    80,    70,    98,    98,   102,   103,     9,    98,
      98,    16,   118,    46,    88,    31,     9,   119,    34,     9,
      52,   120,   121,    93,    94,    46,    10,    24,   104,   105,
      95,     1,    52,     2,     3,    11,    59,    60,    61,    62,
      63,    98,    85,     4,    52,    12,    34,    90,    17,    13,
      64,   142,   143,    18,    46,    65,   132,   133,   134,    66,
      21,    22,    24,    20,    59,    60,    61,    62,    63,   108,
     109,   110,     1,    52,     2,     3,   100,   101,    64,   106,
     107,   137,   138,    65,     4,    57,    58,    66,     1,    34,
       2,     3,    35,   124,   125,    36,    96,    97,    37,    25,
       4,    27,   145,    30,    85,   146,    34,   130,   131,    29,
     150,    32,    33,    46,    53,    54,    46,    82,    56,    38,
      39,    46,    81,    86,    59,    60,    61,    62,    63,    98,
      99,   114,    52,   113,   116,    52,   117,   140,    64,   141,
      52,     1,    34,     2,     3,    35,   144,    38,    36,   147,
      26,    37,    55,     4,    59,    60,    61,    62,    63,   126,
     127,   128,   129,    89,   135,   149,   112,   111,   136,   122,
     139,   123,    38
};

static const yytype_uint8 yycheck[] =
{
       9,    29,    41,    37,    21,    21,    16,    17,     0,    21,
      21,    20,    29,    41,    53,    24,     8,    33,     4,    11,
      29,    33,    33,    57,    58,    53,     0,    19,    38,    39,
      64,     3,    41,     5,     6,    28,    22,    23,    24,    25,
      26,    21,    51,    15,    53,     8,     4,    33,    11,     4,
      36,    31,    32,    36,    82,    41,   108,   109,   110,    45,
      30,    33,    54,    29,    22,    23,    24,    25,    26,    42,
      43,    44,     3,    82,     5,     6,    18,    19,    36,    40,
      41,   115,   116,    41,    15,    35,    36,    45,     3,     4,
       5,     6,     7,   100,   101,    10,    65,    66,    13,     4,
      15,    24,   141,    33,   113,   144,     4,   106,   107,    34,
     149,    32,    31,   141,    34,    29,   144,    28,    36,    34,
      35,   149,    35,    30,    22,    23,    24,    25,    26,    21,
      20,    16,   141,    29,    37,   144,    33,     8,    36,    34,
     149,     3,     4,     5,     6,     7,    34,    34,    10,     9,
      20,    13,    32,    15,    22,    23,    24,    25,    26,   102,
     103,   104,   105,    54,   113,   147,    82,    79,   114,    98,
     118,    99,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,    15,    47,    48,    49,    53,    83,
       0,    28,    48,     4,    50,    51,    85,    48,    36,    57,
      29,    30,    33,    54,    83,     4,    51,    24,    52,    34,
      33,    85,    32,    31,     4,     7,    10,    13,    34,    35,
      55,    56,    58,    59,    60,    63,    66,    68,    69,    70,
      71,    83,    85,    34,    29,    52,    36,    57,    57,    22,
      23,    24,    25,    26,    36,    41,    45,    66,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    84,    85,
      55,    35,    28,    61,    62,    85,    30,    64,    55,    54,
      33,    67,    75,    75,    75,    75,    82,    82,    21,    20,
      18,    19,    16,    17,    38,    39,    40,    41,    42,    43,
      44,    64,    58,    29,    16,    65,    37,    33,    29,    33,
      33,    33,    76,    77,    78,    78,    79,    79,    79,    79,
      80,    80,    81,    81,    81,    61,    84,    75,    75,    67,
       8,    34,    31,    32,    34,    55,    55,     9,    72,    56,
      55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    49,    50,
      50,    51,    52,    52,    51,    53,    53,    54,    54,    55,
      56,    55,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    62,    62,    63,    64,    65,    65,
      64,    66,    66,    67,    67,    68,    69,    69,    70,    71,
      72,    72,    73,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    83,    83,    84,    84,    84,    84,    84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     1,     2,     2,     3,
       1,     4,     3,     1,     1,     7,     6,     4,     2,     2,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     3,     1,     4,     4,     3,     0,
       0,     4,     3,     3,     1,     2,     1,     1,     6,     8,
       3,     0,     2,     1,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* programa: lista_de_elementos  */
#line 65 "parser.y"
                             {if((yyvsp[0].node)!=NULL){(yyval.node)=(yyvsp[0].node);  arvore = (yyval.node); }}
#line 1539 "temp/parser.tab.c"
    break;

  case 3: /* programa: %empty  */
#line 66 "parser.y"
          {(yyval.node)=NULL;}
#line 1545 "temp/parser.tab.c"
    break;

  case 4: /* lista_de_elementos: cabecalho_funcao lista_de_elementos  */
#line 67 "parser.y"
                                                        { if((yyvsp[0].node)!=NULL) {add_child((yyval.node), (yyvsp[0].node)); } else {(yyval.node)=(yyvsp[-1].node); }}
#line 1551 "temp/parser.tab.c"
    break;

  case 5: /* lista_de_elementos: declaracao ';' lista_de_elementos  */
#line 68 "parser.y"
                                                      {(yyval.node) = (yyvsp[0].node); if((yyvsp[0].node)!=NULL) {add_child((yyval.node), (yyvsp[-2].node));} }
#line 1557 "temp/parser.tab.c"
    break;

  case 6: /* lista_de_elementos: cabecalho_funcao  */
#line 69 "parser.y"
                                     {(yyval.node)=(yyvsp[0].node); }
#line 1563 "temp/parser.tab.c"
    break;

  case 7: /* lista_de_elementos: declaracao ';'  */
#line 70 "parser.y"
                                  {(yyval.node)=(yyvsp[-1].node);}
#line 1569 "temp/parser.tab.c"
    break;

  case 8: /* declaracao: tipo lista_de_nome_de_variaveis  */
#line 77 "parser.y"
{
	(yyval.node)=NULL; 
	Pilha* temp = top_stack(myStack); 
	analisa_e_insere(temp->elemento_pilha, (yyvsp[0].node), (yyvsp[-1].node)); 
	exclude_node((yyvsp[0].node)); 
	free((yyvsp[-1].node));
}
#line 1581 "temp/parser.tab.c"
    break;

  case 9: /* lista_de_nome_de_variaveis: lista_de_nome_de_variaveis ',' multidimensional  */
#line 86 "parser.y"
{
	(yyval.node)=create_node("PROX_VARG", ",");
	add_child((yyval.node), (yyvsp[-2].node)); 
	add_child((yyval.node), (yyvsp[0].node));
}
#line 1591 "temp/parser.tab.c"
    break;

  case 10: /* lista_de_nome_de_variaveis: multidimensional  */
#line 93 "parser.y"
{
	(yyval.node)=(yyvsp[0].node);
}
#line 1599 "temp/parser.tab.c"
    break;

  case 11: /* multidimensional: IDENTIFICADOR '[' lista_literais ']'  */
#line 98 "parser.y"
{
	(yyval.node)=create_node("LISTA_LIT", "[]"); 
	add_child((yyval.node), (yyvsp[-3].node)); 
	add_child((yyval.node), (yyvsp[-1].node));
}
#line 1609 "temp/parser.tab.c"
    break;

  case 12: /* lista_literais: TK_LIT_INT '^' lista_literais  */
#line 105 "parser.y"
{
	(yyval.node)=create_node("PROX_LIT", "^"); 
	add_child((yyval.node), create_node_from_token("TK_LIT_INT", (yyvsp[-2].valor_lexico))); 
	add_child((yyval.node), (yyvsp[0].node));
}
#line 1619 "temp/parser.tab.c"
    break;

  case 13: /* lista_literais: TK_LIT_INT  */
#line 112 "parser.y"
{
	(yyval.node)=create_node_from_token("TK_LIT_INT", (yyvsp[0].valor_lexico)); 
}
#line 1627 "temp/parser.tab.c"
    break;

  case 14: /* multidimensional: IDENTIFICADOR  */
#line 117 "parser.y"
{
	(yyval.node)=(yyvsp[0].node);
}
#line 1635 "temp/parser.tab.c"
    break;

  case 15: /* cabecalho_funcao: tipo TK_IDENTIFICADOR PS lista_parametros ')' '{' bloco_comandos  */
#line 125 "parser.y"
{
	(yyval.node) = create_node_from_token("FuncaoL", (yyvsp[-5].valor_lexico)); 
	free((yyvsp[-5].valor_lexico).valor.cadeia); 
	add_child((yyval.node), (yyvsp[-3].node)); 
	if((yyvsp[0].node)!=NULL) 
	{
		add_child((yyval.node), (yyvsp[0].node)); 
	}
	Pilha* temp = top_stack(myStack);  
	pop_stack(myStack);
	temp = top_stack(myStack);

	// Esta linha abaixo serve para adicionar foo ao escopo imediatamente anterior.
	analisa_e_insere(temp->elemento_pilha, (yyval.node), (yyvsp[-6].node));
	free((yyvsp[-6].node));
}
#line 1656 "temp/parser.tab.c"
    break;

  case 16: /* cabecalho_funcao: tipo TK_IDENTIFICADOR PS ')' '{' bloco_comandos  */
#line 143 "parser.y"
{
	(yyval.node) = create_node_from_token("Funcao", (yyvsp[-4].valor_lexico)); 
	free((yyvsp[-4].valor_lexico).valor.cadeia); 
	if((yyvsp[0].node)!=NULL)
	{
		add_child((yyval.node), (yyvsp[0].node)); 
	}  
	pop_stack(myStack);
	Pilha* temp = top_stack(myStack);
	analisa_e_insere(temp->elemento_pilha, (yyval.node), (yyvsp[-5].node));
	free((yyvsp[-5].node));
}
#line 1673 "temp/parser.tab.c"
    break;

  case 17: /* lista_parametros: tipo IDENTIFICADOR ',' lista_parametros  */
#line 157 "parser.y"
{
	(yyval.node)=create_node("LIST_PARAM", ",");
	add_child((yyval.node), (yyvsp[-3].node)); 
	add_child((yyval.node), (yyvsp[0].node)); 
	Pilha* temp = top_stack(myStack); 
	analisa_e_insere(temp->elemento_pilha, (yyvsp[-2].node), (yyvsp[-3].node)); 
	free((yyvsp[-2].node));
}
#line 1686 "temp/parser.tab.c"
    break;

  case 18: /* lista_parametros: tipo IDENTIFICADOR  */
#line 167 "parser.y"
{
	(yyval.node)=(yyvsp[-1].node); 
	Pilha* temp = top_stack(myStack);
	analisa_e_insere(temp->elemento_pilha, (yyvsp[0].node), (yyvsp[-1].node)); 
	free((yyvsp[0].node));
}
#line 1697 "temp/parser.tab.c"
    break;

  case 19: /* bloco_comandos: lista_comandos_simples '}'  */
#line 175 "parser.y"
{
	(yyval.node) = (yyvsp[-1].node); 
}
#line 1705 "temp/parser.tab.c"
    break;

  case 20: /* PSblock: '{'  */
#line 180 "parser.y"
{
	(yyval.node)=NULL; 
	Tabela* temptable = create_simbolo();
	push_stack(temptable, myStack);
}
#line 1715 "temp/parser.tab.c"
    break;

  case 21: /* bloco_comandos: '}'  */
#line 187 "parser.y"
{
	(yyval.node)=NULL; 
}
#line 1723 "temp/parser.tab.c"
    break;

  case 22: /* PS: '('  */
#line 192 "parser.y"
{
	(yyval.node)=NULL; 
	Tabela* temptable = create_simbolo();
	push_stack(temptable, myStack);
}
#line 1733 "temp/parser.tab.c"
    break;

  case 23: /* lista_comandos_simples: comandos_simples ';' lista_comandos_simples  */
#line 202 "parser.y"
{
	if ((yyvsp[-2].node)!=NULL)  
		if((yyvsp[0].node)!=NULL) 
		{
			(yyval.node)=(yyvsp[-2].node);  
			if(!strcmp((yyvsp[-2].node)->label, "<=")) 
			{
				(yyvsp[-2].node)=ultimaInit((yyvsp[-2].node));
			}
			add_child((yyvsp[-2].node), (yyvsp[0].node)); 
		} 
		else 
		{
			(yyval.node)=(yyvsp[-2].node); 
		} 
	else 
	{
		(yyval.node)=(yyvsp[0].node); 
	}
}
#line 1758 "temp/parser.tab.c"
    break;

  case 24: /* lista_comandos_simples: comandos_simples ';'  */
#line 224 "parser.y"
{
	(yyval.node)=(yyvsp[-1].node);
}
#line 1766 "temp/parser.tab.c"
    break;

  case 25: /* comandos_simples: declaracao_local  */
#line 229 "parser.y"
{
	(yyval.node)=(yyvsp[0].node); 
}
#line 1774 "temp/parser.tab.c"
    break;

  case 26: /* comandos_simples: atribuicao_local  */
#line 234 "parser.y"
{
	(yyval.node)=(yyvsp[0].node); 
}
#line 1782 "temp/parser.tab.c"
    break;

  case 27: /* comandos_simples: chamada_funcao  */
#line 239 "parser.y"
{
	(yyval.node)=(yyvsp[0].node); 
}
#line 1790 "temp/parser.tab.c"
    break;

  case 28: /* comandos_simples: chamada_retorno  */
#line 244 "parser.y"
{
	(yyval.node)=(yyvsp[0].node); 
}
#line 1798 "temp/parser.tab.c"
    break;

  case 29: /* comandos_simples: chamada_ctrl_fluxo  */
#line 249 "parser.y"
{
	(yyval.node)=(yyvsp[0].node); 
}
#line 1806 "temp/parser.tab.c"
    break;

  case 30: /* comandos_simples: PSblock bloco_comandos  */
#line 254 "parser.y"
{
	(yyval.node)=(yyvsp[0].node); 
}
#line 1814 "temp/parser.tab.c"
    break;

  case 31: /* declaracao_local: tipo lista_de_nome_de_variaveis_locais  */
#line 262 "parser.y"
{
	(yyval.node) = (yyvsp[0].node); 
	Pilha* temp = top_stack(myStack); 
	analisa_e_insere(temp->elemento_pilha, (yyvsp[0].node), (yyvsp[-1].node)); 
	free((yyvsp[-1].node));
}
#line 1825 "temp/parser.tab.c"
    break;

  case 32: /* lista_de_nome_de_variaveis_locais: variavel_local ',' lista_de_nome_de_variaveis_locais  */
#line 270 "parser.y"
{ 
	(yyval.node)=create_node("PROX_VARL", ","); 
	add_child((yyval.node), (yyvsp[-2].node)); 
	add_child((yyval.node), (yyvsp[0].node)); 
}
#line 1835 "temp/parser.tab.c"
    break;

  case 33: /* lista_de_nome_de_variaveis_locais: variavel_local  */
#line 277 "parser.y"
{
	(yyval.node) = (yyvsp[0].node); 
}
#line 1843 "temp/parser.tab.c"
    break;

  case 34: /* variavel_local: IDENTIFICADOR TK_OC_LE literal  */
#line 282 "parser.y"
{
	(yyval.node) = create_node("TK_OC_LE", "<="); 
	add_child((yyval.node), (yyvsp[-2].node)); 
	free((yyvsp[-1].valor_lexico).valor.cadeia); 
	add_child((yyval.node), (yyvsp[0].node)); 
	(yyval.node)->codigo = (yyvsp[0].node)->codigo;
	char *string_temp;
	sprintf(string_temp, "storeAI temporario%d => rfp, endereco_deslocamento\n", contador);
	strcat((yyval.node)->codigo, string_temp);
}
#line 1858 "temp/parser.tab.c"
    break;

  case 35: /* variavel_local: IDENTIFICADOR  */
#line 294 "parser.y"
{
	(yyval.node)=(yyvsp[0].node);
}
#line 1866 "temp/parser.tab.c"
    break;

  case 36: /* atribuicao_local: IDENTIFICADOR lista_de_expressoes '=' expressao  */
#line 303 "parser.y"
{
	(yyval.node) = create_node("ATRIBUICAO", "="); 
	if ((yyvsp[-2].node)!= NULL) 
	{ 
		add_child((yyvsp[-2].node), (yyvsp[-3].node));  
		add_child((yyval.node), (yyvsp[-2].node));
		enum Tipo tipoLeft;
		enum Tipo tipoRight;
		tipoLeft = analisa_uso(top_stack(myStack)->elemento_pilha, (yyvsp[-2].node));
		tipoRight = analisa_uso(top_stack(myStack)->elemento_pilha, (yyvsp[0].node));
		compareTypes(tipoLeft, tipoRight);
	}
	else 
	{ 
		add_child((yyval.node), (yyvsp[-3].node));
		enum Tipo tipoLeft;
		enum Tipo tipoRight;
		tipoLeft = analisa_uso(top_stack(myStack)->elemento_pilha, (yyvsp[-3].node));
		tipoRight = analisa_uso(top_stack(myStack)->elemento_pilha, (yyvsp[0].node));
		compareTypes(tipoLeft, tipoRight);
	} 
	add_child((yyval.node), (yyvsp[0].node));
	}
#line 1894 "temp/parser.tab.c"
    break;

  case 37: /* lista_de_expressoes: '[' lista_de_expressoes_ expressao ']'  */
#line 328 "parser.y"
{
	(yyval.node) = create_node("ARRANJO", "[]");  
	if ((yyvsp[-2].node)!= NULL) 
	{ 
		add_child((yyvsp[-2].node), (yyvsp[-1].node)); 
		add_child((yyval.node), (yyvsp[-2].node));
	} 
	else 
		add_child((yyval.node), (yyvsp[-1].node)); 
}
#line 1909 "temp/parser.tab.c"
    break;

  case 38: /* lista_de_expressoes_: lista_de_expressoes_ expressao '^'  */
#line 340 "parser.y"
{
	(yyval.node) = create_node("LISTA_EXP", "^");  
	if ((yyvsp[-2].node)!=NULL) 
	{
		add_child((yyvsp[-2].node), (yyvsp[-1].node));
		add_child((yyval.node), (yyvsp[-2].node));
	} 
	else 
		add_child((yyval.node), (yyvsp[-1].node)); 
}
#line 1924 "temp/parser.tab.c"
    break;

  case 39: /* lista_de_expressoes_: %empty  */
#line 352 "parser.y"
{
	(yyval.node)=NULL;
}
#line 1932 "temp/parser.tab.c"
    break;

  case 40: /* lista_de_expressoes: %empty  */
#line 357 "parser.y"
{
	(yyval.node)=NULL;
}
#line 1940 "temp/parser.tab.c"
    break;

  case 41: /* chamada_funcao: TK_IDENTIFICADOR '(' lista_expressoes_funcao ')'  */
#line 364 "parser.y"
                                                                  {
	(yyval.node) = create_node_from_token("CHAMA_FUNCAO", (yyvsp[-3].valor_lexico)); 
	add_child((yyval.node), (yyvsp[-1].node));
	analisa_uso(top_stack(myStack)->elemento_pilha, (yyval.node));
	free((yyvsp[-3].valor_lexico).valor.cadeia); 
	}
#line 1951 "temp/parser.tab.c"
    break;

  case 42: /* chamada_funcao: TK_IDENTIFICADOR '(' ')'  */
#line 370 "parser.y"
                                          {
	(yyval.node) = create_node_from_token("CHAMA_FUNCAO", (yyvsp[-2].valor_lexico));
	analisa_uso(top_stack(myStack)->elemento_pilha, (yyval.node));
	free((yyvsp[-2].valor_lexico).valor.cadeia); 
	}
#line 1961 "temp/parser.tab.c"
    break;

  case 43: /* lista_expressoes_funcao: expressao ',' lista_expressoes_funcao  */
#line 375 "parser.y"
                                                               {(yyval.node) = (yyvsp[-2].node);  add_child((yyval.node), (yyvsp[0].node)); }
#line 1967 "temp/parser.tab.c"
    break;

  case 44: /* lista_expressoes_funcao: expressao  */
#line 376 "parser.y"
                                   {(yyval.node) = (yyvsp[0].node); }
#line 1973 "temp/parser.tab.c"
    break;

  case 45: /* chamada_retorno: TK_PR_RETURN expressao  */
#line 381 "parser.y"
                                        {(yyval.node) = create_node("TK_PR_RETURN", "return"); add_child((yyval.node), (yyvsp[0].node)); free((yyvsp[-1].valor_lexico).valor.cadeia); }
#line 1979 "temp/parser.tab.c"
    break;

  case 46: /* chamada_ctrl_fluxo: ctrl_condicional  */
#line 386 "parser.y"
                                     {(yyval.node) = (yyvsp[0].node); }
#line 1985 "temp/parser.tab.c"
    break;

  case 47: /* chamada_ctrl_fluxo: ctrl_repeticao  */
#line 387 "parser.y"
                                   {(yyval.node) = (yyvsp[0].node); }
#line 1991 "temp/parser.tab.c"
    break;

  case 48: /* ctrl_repeticao: TK_PR_WHILE PS expressao ')' '{' bloco_comandos  */
#line 388 "parser.y"
                                                                {
	(yyval.node) = create_node("TK_PR_WHILE", "while");
	add_child((yyval.node), (yyvsp[-3].node));
	free((yyvsp[-5].valor_lexico).valor.cadeia);
	add_child((yyval.node), (yyvsp[0].node));
	
	Pilha* temp = top_stack(myStack); 
	pop_stack(myStack);
	}
#line 2005 "temp/parser.tab.c"
    break;

  case 49: /* ctrl_condicional: TK_PR_IF PS expressao ')' TK_PR_THEN '{' bloco_comandos cond_else  */
#line 397 "parser.y"
                                                                                    {
	(yyval.node) = create_node("TK_PR_IF", "if"); 
	add_child((yyval.node), (yyvsp[-5].node)); 
	add_child((yyval.node), (yyvsp[-1].node)); 
	free((yyvsp[-7].valor_lexico).valor.cadeia);
	free((yyvsp[-3].valor_lexico).valor.cadeia); 
	if((yyvsp[0].node) != NULL){add_child((yyval.node), (yyvsp[0].node)); } 
	Pilha* temp = top_stack(myStack);
	pop_stack(myStack);
	}
#line 2020 "temp/parser.tab.c"
    break;

  case 50: /* cond_else: TK_PR_ELSE PSblock bloco_comandos  */
#line 407 "parser.y"
                                             { //botar no else o PS trocar o TK+PR po só ELSE e o ELSE ser o TKpr com o push
	(yyval.node) = (yyvsp[0].node); 
	free((yyvsp[-2].valor_lexico).valor.cadeia);}
#line 2028 "temp/parser.tab.c"
    break;

  case 51: /* cond_else: %empty  */
#line 410 "parser.y"
           {(yyval.node)=NULL;}
#line 2034 "temp/parser.tab.c"
    break;

  case 52: /* multidimensional_: IDENTIFICADOR lista_de_expressoes  */
#line 419 "parser.y"
                                                     {if ((yyvsp[0].node)==NULL) (yyval.node)=(yyvsp[-1].node); else {(yyval.node)=(yyvsp[0].node); add_child((yyval.node), (yyvsp[-1].node));}}
#line 2040 "temp/parser.tab.c"
    break;

  case 53: /* operandos: literal  */
#line 421 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2046 "temp/parser.tab.c"
    break;

  case 54: /* operandos: multidimensional_  */
#line 422 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2052 "temp/parser.tab.c"
    break;

  case 55: /* operandos: chamada_funcao  */
#line 423 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2058 "temp/parser.tab.c"
    break;

  case 56: /* expressao: expressao TK_OC_OR exp1  */
#line 425 "parser.y"
                                   {(yyval.node) = create_node("OR", "||" );  add_child((yyval.node), (yyvsp[-2].node)); free((yyvsp[-1].valor_lexico).valor.cadeia);  add_child((yyval.node), (yyvsp[0].node));  }
#line 2064 "temp/parser.tab.c"
    break;

  case 57: /* expressao: exp1  */
#line 426 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2070 "temp/parser.tab.c"
    break;

  case 58: /* exp1: exp1 TK_OC_AND exp2  */
#line 428 "parser.y"
                          {(yyval.node) = create_node("AND", "&&" );  add_child((yyval.node), (yyvsp[-2].node)); free((yyvsp[-1].valor_lexico).valor.cadeia); add_child((yyval.node), (yyvsp[0].node));  }
#line 2076 "temp/parser.tab.c"
    break;

  case 59: /* exp1: exp2  */
#line 429 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2082 "temp/parser.tab.c"
    break;

  case 60: /* exp2: exp2 TK_OC_EQ exp3  */
#line 431 "parser.y"
                         {(yyval.node) = create_node("EQ", "==" );  add_child((yyval.node), (yyvsp[-2].node)); free((yyvsp[-1].valor_lexico).valor.cadeia);  add_child((yyval.node), (yyvsp[0].node)); }
#line 2088 "temp/parser.tab.c"
    break;

  case 61: /* exp2: exp2 TK_OC_NE exp3  */
#line 432 "parser.y"
                         {(yyval.node) = create_node("NE", "!=" );  add_child((yyval.node), (yyvsp[-2].node)); free((yyvsp[-1].valor_lexico).valor.cadeia);  add_child((yyval.node), (yyvsp[0].node)); }
#line 2094 "temp/parser.tab.c"
    break;

  case 62: /* exp2: exp3  */
#line 433 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 2100 "temp/parser.tab.c"
    break;

  case 63: /* exp3: exp3 '<' exp4  */
#line 435 "parser.y"
                    {(yyval.node) = create_node("LT", "<" );  add_child((yyval.node), (yyvsp[-2].node));   add_child((yyval.node), (yyvsp[0].node)); }
#line 2106 "temp/parser.tab.c"
    break;

  case 64: /* exp3: exp3 '>' exp4  */
#line 436 "parser.y"
                    {(yyval.node) = create_node("GT", ">" );  add_child((yyval.node), (yyvsp[-2].node));  add_child((yyval.node), (yyvsp[0].node)); }
#line 2112 "temp/parser.tab.c"
    break;

  case 65: /* exp3: exp3 TK_OC_LE exp4  */
#line 437 "parser.y"
                         {(yyval.node) = create_node("LE", "<=" );  add_child((yyval.node), (yyvsp[-2].node));  free((yyvsp[-1].valor_lexico).valor.cadeia); add_child((yyval.node), (yyvsp[0].node));  }
#line 2118 "temp/parser.tab.c"
    break;

  case 66: /* exp3: exp3 TK_OC_GE exp4  */
#line 438 "parser.y"
                         {(yyval.node) = create_node("GE", ">=" );  add_child((yyval.node), (yyvsp[-2].node));  free((yyvsp[-1].valor_lexico).valor.cadeia); add_child((yyval.node), (yyvsp[0].node));  }
#line 2124 "temp/parser.tab.c"
    break;

  case 67: /* exp3: exp4  */
#line 439 "parser.y"
           { (yyval.node) = (yyvsp[0].node);  }
#line 2130 "temp/parser.tab.c"
    break;

  case 68: /* exp4: exp4 '+' exp5  */
#line 442 "parser.y"
                    {(yyval.node) = create_node("SOMA", "+" );  add_child((yyval.node), (yyvsp[-2].node));  add_child((yyval.node), (yyvsp[0].node));  }
#line 2136 "temp/parser.tab.c"
    break;

  case 69: /* exp4: exp4 '-' exp5  */
#line 443 "parser.y"
                    {(yyval.node) = create_node("SUB", "-" );  add_child((yyval.node), (yyvsp[-2].node));  add_child((yyval.node), (yyvsp[0].node));  }
#line 2142 "temp/parser.tab.c"
    break;

  case 70: /* exp4: exp5  */
#line 444 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 2148 "temp/parser.tab.c"
    break;

  case 71: /* exp5: exp5 '*' exp6  */
#line 446 "parser.y"
                    {(yyval.node) = create_node("MULT", "*" );  add_child((yyval.node), (yyvsp[-2].node));  add_child((yyval.node), (yyvsp[0].node));  }
#line 2154 "temp/parser.tab.c"
    break;

  case 72: /* exp5: exp5 '/' exp6  */
#line 447 "parser.y"
                    {(yyval.node) = create_node("DIV", "/" );  add_child((yyval.node), (yyvsp[-2].node));   add_child((yyval.node), (yyvsp[0].node));  }
#line 2160 "temp/parser.tab.c"
    break;

  case 73: /* exp5: exp5 '%' exp6  */
#line 448 "parser.y"
                    {(yyval.node) = create_node("RESTO", "%" );  add_child((yyval.node), (yyvsp[-2].node));  add_child((yyval.node), (yyvsp[0].node)); }
#line 2166 "temp/parser.tab.c"
    break;

  case 74: /* exp5: exp6  */
#line 449 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 2172 "temp/parser.tab.c"
    break;

  case 75: /* exp6: '-' exp7  */
#line 451 "parser.y"
               { (yyval.node) = create_node("SUB_UNARIO", "-"); add_child((yyval.node), (yyvsp[0].node)); }
#line 2178 "temp/parser.tab.c"
    break;

  case 76: /* exp6: '!' exp7  */
#line 452 "parser.y"
               { (yyval.node) = create_node("NOT", "!"); add_child((yyval.node), (yyvsp[0].node)); }
#line 2184 "temp/parser.tab.c"
    break;

  case 77: /* exp6: exp7  */
#line 453 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 2190 "temp/parser.tab.c"
    break;

  case 78: /* exp7: '(' expressao ')'  */
#line 455 "parser.y"
                        { (yyval.node) = (yyvsp[-1].node);  }
#line 2196 "temp/parser.tab.c"
    break;

  case 79: /* exp7: operandos  */
#line 456 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2202 "temp/parser.tab.c"
    break;

  case 80: /* tipo: TK_PR_INT  */
#line 459 "parser.y"
                {(yyval.node)=create_node("int", "i"); free((yyvsp[0].valor_lexico).valor.cadeia);}
#line 2208 "temp/parser.tab.c"
    break;

  case 81: /* tipo: TK_PR_FLOAT  */
#line 460 "parser.y"
                  {(yyval.node)=create_node("float", "f"); free((yyvsp[0].valor_lexico).valor.cadeia);}
#line 2214 "temp/parser.tab.c"
    break;

  case 82: /* tipo: TK_PR_CHAR  */
#line 461 "parser.y"
                 {(yyval.node)=create_node("char", "c"); free((yyvsp[0].valor_lexico).valor.cadeia);}
#line 2220 "temp/parser.tab.c"
    break;

  case 83: /* tipo: TK_PR_BOOL  */
#line 462 "parser.y"
                 {(yyval.node)=create_node("bool", "b"); free((yyvsp[0].valor_lexico).valor.cadeia);}
#line 2226 "temp/parser.tab.c"
    break;

  case 84: /* literal: TK_LIT_INT  */
#line 463 "parser.y"
                    {(yyval.node) = create_node_from_token("TK_LIT_INT", (yyvsp[0].valor_lexico)); sprintf((yyval.node)->codigo, "LoadI %d => temporario%d\n", (yyvsp[0].valor_lexico).valor.inteiro, gera_rotulo());}
#line 2232 "temp/parser.tab.c"
    break;

  case 85: /* literal: TK_LIT_FLOAT  */
#line 464 "parser.y"
                      {(yyval.node) = create_node_from_token("TK_LIT_FLOAT", (yyvsp[0].valor_lexico)); }
#line 2238 "temp/parser.tab.c"
    break;

  case 86: /* literal: TK_LIT_CHAR  */
#line 465 "parser.y"
                     {(yyval.node) = create_node_from_token("TK_LIT_CHAR", (yyvsp[0].valor_lexico));  }
#line 2244 "temp/parser.tab.c"
    break;

  case 87: /* literal: TK_LIT_TRUE  */
#line 466 "parser.y"
                     {(yyval.node) = create_node_from_token("TK_LIT_TRUE", (yyvsp[0].valor_lexico)); }
#line 2250 "temp/parser.tab.c"
    break;

  case 88: /* literal: TK_LIT_FALSE  */
#line 467 "parser.y"
                      {(yyval.node) = create_node_from_token("TK_LIT_FALSE", (yyvsp[0].valor_lexico)); }
#line 2256 "temp/parser.tab.c"
    break;

  case 89: /* IDENTIFICADOR: TK_IDENTIFICADOR  */
#line 468 "parser.y"
                                { (yyval.node) = create_node_from_token("TK_IDENTIFICADOR", (yyvsp[0].valor_lexico)); free((yyvsp[0].valor_lexico).valor.cadeia); }
#line 2262 "temp/parser.tab.c"
    break;


#line 2266 "temp/parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 471 "parser.y"

void yyerror(const char *mensagem){
	printf("Erro Sintático: [%s] na linha %d\n", mensagem, yylineno);
	return;
}


