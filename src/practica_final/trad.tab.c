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
#line 3 "trad.y"
                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata
#define INC(x) x=x+1;
#define DEC(x) x=x-1;

int yylex () ;
int yyerror (char*) ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;

int en_funcion = 0;        // 0 si es variable global, 1 si esta dentro de una función
char nombre_funcion[256];   // Nombre de la función local
char *vars_locales[256];    // Tabla de nombres de variables locales
int n_vars_locales = 0;     // Número de variables locales
int nivel_rama = 0;            // Si nivel_rama en_rama == 0, se está fuera de un if/for/switch/while. Si > 0, indica que se está dentro de una rama
int nivel_en_return = 0;       // Guarda el valor de nivel_rama cuando se parsea el return

void insertar_local(char *nombre); 
int es_local(char *nombre);
void limpiar_locales();
char *nombre_local(char *var);
char *wrap_progn(char *codigo);

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr


#line 128 "trad.tab.c"

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

#include "trad.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_PUTS = 7,                       /* PUTS  */
  YYSYMBOL_PRINTF = 8,                     /* PRINTF  */
  YYSYMBOL_MAIN = 9,                       /* MAIN  */
  YYSYMBOL_OR = 10,                        /* OR  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_NEQ = 12,                       /* NEQ  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_LTEQ = 14,                      /* LTEQ  */
  YYSYMBOL_GTEQ = 15,                      /* GTEQ  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_INC = 19,                       /* INC  */
  YYSYMBOL_DEC = 20,                       /* DEC  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_SWITCH = 22,                    /* SWITCH  */
  YYSYMBOL_CASE = 23,                      /* CASE  */
  YYSYMBOL_BREAK = 24,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 25,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_UNARY_SIGN = 36,                /* UNARY_SIGN  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_axioma = 47,                    /* axioma  */
  YYSYMBOL_declaraciones_funciones = 48,   /* declaraciones_funciones  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_decl_global = 51,               /* decl_global  */
  YYSYMBOL_funcion = 52,                   /* funcion  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_lista_args = 54,                /* lista_args  */
  YYSYMBOL_r_lista_args = 55,              /* r_lista_args  */
  YYSYMBOL_funcion_main = 56,              /* funcion_main  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_cuerpo = 58,                    /* cuerpo  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_abre_rama = 60,                 /* abre_rama  */
  YYSYMBOL_bucle_while = 61,               /* bucle_while  */
  YYSYMBOL_bucle_for = 62,                 /* bucle_for  */
  YYSYMBOL_inicializ = 63,                 /* inicializ  */
  YYSYMBOL_oper_for = 64,                  /* oper_for  */
  YYSYMBOL_control_if = 65,                /* control_if  */
  YYSYMBOL_control_switch = 66,            /* control_switch  */
  YYSYMBOL_switch_cases = 67,              /* switch_cases  */
  YYSYMBOL_sentencia = 68,                 /* sentencia  */
  YYSYMBOL_lista_params = 69,              /* lista_params  */
  YYSYMBOL_r_lista_params = 70,            /* r_lista_params  */
  YYSYMBOL_elemento = 71,                  /* elemento  */
  YYSYMBOL_mult_elementos = 72,            /* mult_elementos  */
  YYSYMBOL_mult_asign = 73,                /* mult_asign  */
  YYSYMBOL_expresion = 74,                 /* expresion  */
  YYSYMBOL_termino = 75,                   /* termino  */
  YYSYMBOL_operando = 76                   /* operando  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  220

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
       2,     2,     2,    35,     2,     2,     2,    34,     2,     2,
      40,    41,    32,    30,    44,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
      29,    27,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   101,   101,   103,   103,   105,   108,   110,
     112,   114,   116,   121,   120,   131,   133,   136,   138,   142,
     141,   152,   156,   162,   164,   166,   168,   171,   171,   182,
     184,   187,   192,   198,   203,   208,   214,   222,   225,   231,
     236,   240,   244,   247,   254,   260,   267,   274,   281,   287,
     289,   291,   298,   306,   308,   311,   313,   316,   317,   321,
     327,   330,   337,   344,   351,   360,   361,   363,   365,   367,
     369,   371,   373,   375,   377,   379,   381,   383,   385,   389,
     390,   391,   393,   397,   402,   404,   405,   408
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "PUTS", "PRINTF", "MAIN", "OR", "AND", "NEQ", "EQ",
  "LTEQ", "GTEQ", "FOR", "WHILE", "IF", "INC", "DEC", "ELSE", "SWITCH",
  "CASE", "BREAK", "DEFAULT", "RETURN", "'='", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "UNARY_SIGN", "';'", "'['", "']'", "'('",
  "')'", "'{'", "'}'", "','", "':'", "$accept", "axioma",
  "declaraciones_funciones", "$@1", "$@2", "decl_global", "funcion", "$@3",
  "lista_args", "r_lista_args", "funcion_main", "$@4", "cuerpo", "$@5",
  "abre_rama", "bucle_while", "bucle_for", "inicializ", "oper_for",
  "control_if", "control_switch", "switch_cases", "sentencia",
  "lista_params", "r_lista_params", "elemento", "mult_elementos",
  "mult_asign", "expresion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -29,    12,    27,    62,    15,  -167,    34,    -6,  -167,
      50,  -167,  -167,     2,   112,    57,   114,   116,   125,  -167,
      90,     2,  -167,   101,  -167,   102,    95,   -19,  -167,  -167,
     142,  -167,   108,  -167,  -167,     6,  -167,   109,   148,   104,
    -167,   -36,    30,    30,    30,     6,    71,  -167,  -167,   104,
     101,    13,   149,   115,   117,   119,   120,   121,   122,     6,
     127,   104,   104,   104,   104,   140,     6,     6,  -167,  -167,
    -167,   161,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,  -167,   135,  -167,     6,     6,
       6,    80,   173,   174,    43,     6,     6,   177,   285,  -167,
    -167,  -167,  -167,  -167,   104,   243,   158,   154,  -167,    63,
     330,   182,   182,   106,   106,   106,   106,    55,    55,  -167,
    -167,  -167,  -167,   323,   255,   159,     6,   198,  -167,   168,
     175,   190,   214,   183,   193,   218,   194,  -167,  -167,  -167,
    -167,     6,  -167,   209,  -167,    71,   199,  -167,    14,     6,
     210,     6,   197,   200,   201,   104,   154,     6,  -167,  -167,
    -167,   196,   323,   323,     6,   295,  -167,  -167,     3,  -167,
    -167,   323,    14,   203,   323,    94,   104,   104,   238,   215,
     202,   196,  -167,   221,   222,   223,   220,   235,   234,  -167,
    -167,  -167,   276,   277,   248,  -167,   270,  -167,   104,   251,
     252,  -167,   259,   104,   278,  -167,  -167,   104,  -167,   279,
     267,   268,   104,   275,  -167,  -167,   287,     3,  -167,  -167
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,    21,     0,     5,    16,     8,     1,
       0,     2,     3,     7,     0,     0,     0,     0,     0,    11,
       0,     7,     6,    18,    13,     9,     0,    64,    19,     4,
       0,    15,     0,    10,    12,     0,    62,     0,     0,    29,
      84,    83,     0,     0,     0,     0,    63,    65,    79,    29,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    29,    29,    29,     0,     0,    54,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,    17,     0,     0,
      54,    45,     0,     0,     0,     0,     0,     0,     0,    14,
      23,    25,    24,    26,    29,     0,     0,    56,    85,    71,
      70,    72,    73,    75,    77,    76,    74,    66,    67,    68,
      69,    78,    20,    48,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    22,    87,
      86,     0,    53,     0,    50,    43,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    29,    56,     0,    47,    51,
      58,    60,    57,    33,     0,     0,    30,    30,    42,    28,
      55,    52,     0,     0,    34,     0,    29,    29,     0,     0,
       0,    60,    44,     0,     0,     0,     0,     0,     0,    30,
      39,    59,     0,     0,     0,    31,    37,    30,    29,     0,
       0,    30,     0,    29,     0,    35,    36,    29,    30,     0,
       0,     0,    29,     0,    41,    32,     0,    42,    38,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,     9,  -167,  -167,  -167,  -167,  -167,  -167,   271,
    -167,  -167,   -49,  -167,  -166,  -167,  -167,  -167,  -167,  -167,
    -167,   103,  -167,   241,   184,   167,   160,   -22,   -16,  -167,
     100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    21,    13,     5,     6,    32,    15,    31,
      11,    37,    60,   155,   176,    61,    62,   133,   185,    63,
      64,   180,    65,   106,   142,   161,   173,    19,   107,    47,
      48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,   177,    66,    33,    67,    36,     1,     2,    35,    40,
      41,     7,   100,   101,   102,   103,     8,    40,    41,    46,
     160,    16,    22,   198,    85,    18,   178,     9,   179,    71,
      29,   203,    17,    40,    41,   207,    42,    43,    18,    14,
      88,    44,   212,    98,    42,    43,    45,   131,   132,    44,
     105,    89,    12,    90,    45,   138,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   128,
      45,    10,   123,   124,    73,    74,    75,    76,    77,   134,
     135,    72,    73,    74,    75,    76,    77,    82,    83,    84,
      20,    78,    79,    80,    81,    82,    83,    84,    24,    78,
      79,    80,    81,    82,    83,    84,   169,   126,    51,    52,
     145,    53,    54,   183,   184,    18,    23,    25,   127,    26,
      55,    56,    57,   158,    18,   156,    58,   186,   187,    27,
      59,    28,   162,   163,    34,   165,    80,    81,    82,    83,
      84,   171,    68,    69,    70,    30,    18,    38,   174,   204,
      39,    49,    50,    91,   209,    92,   162,    93,   211,    94,
      95,    96,    97,   216,    72,    73,    74,    75,    76,    77,
      99,    72,    73,    74,    75,    76,    77,   104,   122,   129,
     130,   136,    78,    79,    80,    81,    82,    83,    84,    78,
      79,    80,    81,    82,    83,    84,    76,    77,   141,   140,
     144,   146,   108,    72,    73,    74,    75,    76,    77,   147,
      78,    79,    80,    81,    82,    83,    84,   149,   150,   148,
     151,    78,    79,    80,    81,    82,    83,    84,    72,    73,
      74,    75,    76,    77,   152,   154,   157,   164,   159,   166,
     172,   188,   167,   168,   182,   190,    78,    79,    80,    81,
      82,    83,    84,    72,    73,    74,    75,    76,    77,   153,
     189,   192,   193,   195,   194,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   196,   197,
     199,   200,   139,    78,    79,    80,    81,    82,    83,    84,
     201,   202,   205,   206,   143,    72,    73,    74,    75,    76,
      77,   208,   210,   213,   214,    72,    73,    74,    75,    76,
      77,   215,   217,    78,    79,    80,    81,    82,    83,    84,
     219,    87,   137,    78,    79,    80,    81,    82,    83,    84,
     218,   125,   175,    72,    73,    74,    75,    76,    77,   181,
     170,   191,    74,    75,    76,    77,     0,     0,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    78,    79,
      80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      49,   167,    38,    25,    40,    27,     4,     5,    27,     3,
       4,    40,    61,    62,    63,    64,     4,     3,     4,    35,
       6,    27,    13,   189,    46,    44,    23,     0,    25,    45,
      21,   197,    38,     3,     4,   201,    30,    31,    44,     5,
      27,    35,   208,    59,    30,    31,    40,     4,     5,    35,
      66,    38,    37,    40,    40,   104,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    91,
      40,     9,    88,    89,    11,    12,    13,    14,    15,    95,
      96,    10,    11,    12,    13,    14,    15,    32,    33,    34,
      40,    28,    29,    30,    31,    32,    33,    34,    41,    28,
      29,    30,    31,    32,    33,    34,   155,    27,     4,     5,
     126,     7,     8,    19,    20,    44,     4,     3,    38,     3,
      16,    17,    18,   145,    44,   141,    22,   176,   177,     4,
      26,    41,   148,   149,    39,   151,    30,    31,    32,    33,
      34,   157,    42,    43,    44,    44,    44,     5,   164,   198,
      42,    42,     4,     4,   203,    40,   172,    40,   207,    40,
      40,    40,    40,   212,    10,    11,    12,    13,    14,    15,
      43,    10,    11,    12,    13,    14,    15,    37,    43,     6,
       6,     4,    28,    29,    30,    31,    32,    33,    34,    28,
      29,    30,    31,    32,    33,    34,    14,    15,    44,    41,
      41,     3,    41,    10,    11,    12,    13,    14,    15,    41,
      28,    29,    30,    31,    32,    33,    34,    27,     4,    44,
      37,    28,    29,    30,    31,    32,    33,    34,    10,    11,
      12,    13,    14,    15,    41,    41,    27,    27,    39,    42,
      44,     3,    42,    42,    41,    43,    28,    29,    30,    31,
      32,    33,    34,    10,    11,    12,    13,    14,    15,    41,
      45,    40,    40,    43,    41,    10,    11,    12,    13,    14,
      15,    28,    29,    30,    31,    32,    33,    34,    43,    45,
       4,     4,    39,    28,    29,    30,    31,    32,    33,    34,
      42,    21,    41,    41,    39,    10,    11,    12,    13,    14,
      15,    42,    24,    24,    37,    10,    11,    12,    13,    14,
      15,    43,    37,    28,    29,    30,    31,    32,    33,    34,
     217,    50,    37,    28,    29,    30,    31,    32,    33,    34,
      43,    90,    37,    10,    11,    12,    13,    14,    15,   172,
     156,   181,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    28,    29,
      30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    47,    48,    51,    52,    40,     4,     0,
       9,    56,    37,    50,     5,    54,    27,    38,    44,    73,
      40,    49,    48,     4,    41,     3,     3,     4,    41,    48,
      44,    55,    53,    73,    39,    27,    73,    57,     5,    42,
       3,     4,    30,    31,    35,    40,    74,    75,    76,    42,
       4,     4,     5,     7,     8,    16,    17,    18,    22,    26,
      58,    61,    62,    65,    66,    68,    38,    40,    76,    76,
      76,    74,    10,    11,    12,    13,    14,    15,    28,    29,
      30,    31,    32,    33,    34,    73,    58,    55,    27,    38,
      40,     4,    40,    40,    40,    40,    40,    40,    74,    43,
      58,    58,    58,    58,    37,    74,    69,    74,    41,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    43,    74,    74,    69,    27,    38,    73,     6,
       6,     4,     5,    63,    74,    74,     4,    37,    58,    39,
      41,    44,    70,    39,    41,    74,     3,    41,    44,    27,
       4,    37,    41,    41,    41,    59,    74,    27,    73,    39,
       6,    71,    74,    74,    27,    74,    42,    42,    42,    58,
      70,    74,    44,    72,    74,    37,    60,    60,    23,    25,
      67,    71,    41,    19,    20,    64,    58,    58,     3,    45,
      43,    72,    40,    40,    41,    43,    43,    45,    60,     4,
       4,    42,    21,    60,    58,    41,    41,    60,    42,    58,
      24,    58,    60,    24,    37,    43,    58,    37,    43,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    49,    48,    50,    48,    48,    51,    51,
      51,    51,    51,    53,    52,    54,    54,    55,    55,    57,
      56,    56,    58,    58,    58,    58,    58,    59,    58,    58,
      60,    61,    62,    63,    63,    64,    64,    65,    65,    66,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     4,     0,     3,     0,     2,     4,
       5,     3,     5,     0,     8,     3,     0,     4,     0,     0,
       7,     0,     3,     2,     2,     2,     2,     0,     5,     0,
       0,     8,    12,     3,     4,     4,     4,     8,    13,     7,
       8,     6,     0,     4,     7,     2,     3,     5,     3,     4,
       4,     5,     6,     2,     0,     3,     0,     1,     1,     3,
       0,     5,     3,     4,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     2,     1,     1,     3,     4,     4
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
  case 2: /* axioma: declaraciones_funciones funcion_main  */
#line 98 "trad.y"
                                                        { ; }
#line 1355 "trad.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 101 "trad.y"
                                         { printf("%s\n", yyvsp[-1].code) ; }
#line 1361 "trad.tab.c"
    break;

  case 4: /* declaraciones_funciones: decl_global ';' $@1 declaraciones_funciones  */
#line 101 "trad.y"
                                                                                                          { yyval.code = gen_code("") ; }
#line 1367 "trad.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 103 "trad.y"
                                  { printf("%s\n", yyvsp[0].code) ; }
#line 1373 "trad.tab.c"
    break;

  case 6: /* declaraciones_funciones: funcion $@2 declaraciones_funciones  */
#line 103 "trad.y"
                                                                                                          { yyval.code = gen_code("") ; }
#line 1379 "trad.tab.c"
    break;

  case 7: /* declaraciones_funciones: %empty  */
#line 105 "trad.y"
                                                                            { yyval.code = gen_code("") ; }
#line 1385 "trad.tab.c"
    break;

  case 8: /* decl_global: INTEGER IDENTIF  */
#line 108 "trad.y"
                                                        { sprintf(temp, "(setq %s 0)", yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1392 "trad.tab.c"
    break;

  case 9: /* decl_global: INTEGER IDENTIF '=' NUMBER  */
#line 110 "trad.y"
                                                        { sprintf(temp, "(setq %s %d)", yyvsp[-2].code, yyvsp[0].value) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1399 "trad.tab.c"
    break;

  case 10: /* decl_global: INTEGER IDENTIF '=' NUMBER mult_asign  */
#line 112 "trad.y"
                                                        { sprintf(temp, "(setq %s %d) %s", yyvsp[-3].code, yyvsp[-1].value, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1406 "trad.tab.c"
    break;

  case 11: /* decl_global: INTEGER IDENTIF mult_asign  */
#line 114 "trad.y"
                                                        { sprintf(temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1413 "trad.tab.c"
    break;

  case 12: /* decl_global: INTEGER IDENTIF '[' NUMBER ']'  */
#line 116 "trad.y"
                                                        { sprintf(temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1420 "trad.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 121 "trad.y"
                                                        { strcpy(nombre_funcion, yyvsp[-3].code) ; 
                                                          limpiar_locales();
                                                          en_funcion = 1;}
#line 1428 "trad.tab.c"
    break;

  case 14: /* funcion: IDENTIF '(' lista_args ')' $@3 '{' cuerpo '}'  */
#line 126 "trad.y"
                                                        {en_funcion = 0;
                                                          sprintf(temp, "(defun %s (%s)\n%s)", yyvsp[-7].code, yyvsp[-5].code, yyvsp[-1].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1436 "trad.tab.c"
    break;

  case 15: /* lista_args: INTEGER IDENTIF r_lista_args  */
#line 131 "trad.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1443 "trad.tab.c"
    break;

  case 16: /* lista_args: %empty  */
#line 133 "trad.y"
                                                        { yyval.code = gen_code("") ; }
#line 1449 "trad.tab.c"
    break;

  case 17: /* r_lista_args: ',' INTEGER IDENTIF r_lista_args  */
#line 136 "trad.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1456 "trad.tab.c"
    break;

  case 18: /* r_lista_args: %empty  */
#line 138 "trad.y"
                                                        { yyval.code = gen_code("") ; }
#line 1462 "trad.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 142 "trad.y"
                                                        { strcpy(nombre_funcion, "main") ;
                                                          limpiar_locales();
                                                          en_funcion = 1; }
#line 1470 "trad.tab.c"
    break;

  case 20: /* funcion_main: MAIN '(' ')' $@4 '{' cuerpo '}'  */
#line 147 "trad.y"
                                                        { en_funcion = 0; 
                                                          sprintf(temp, "(defun main ()\n%s)", yyvsp[-1].code) ; 
                                                          yyval.code = gen_code(temp) ; 
                                                          printf("%s\n", yyval.code) ; }
#line 1479 "trad.tab.c"
    break;

  case 21: /* funcion_main: %empty  */
#line 152 "trad.y"
                                                        { yyval.code = gen_code("") ; 
                                                          printf("%s\n", yyval.code) ; }
#line 1486 "trad.tab.c"
    break;

  case 22: /* cuerpo: sentencia ';' cuerpo  */
#line 156 "trad.y"
                                                        { if (strlen(yyvsp[0].code) > 0) {
                                                            sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                                        } else {
                                                            sprintf(temp, "%s", yyvsp[-2].code) ;
                                                        }
                                                          yyval.code = gen_code(temp) ; }
#line 1497 "trad.tab.c"
    break;

  case 23: /* cuerpo: bucle_while cuerpo  */
#line 162 "trad.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1504 "trad.tab.c"
    break;

  case 24: /* cuerpo: control_if cuerpo  */
#line 164 "trad.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1511 "trad.tab.c"
    break;

  case 25: /* cuerpo: bucle_for cuerpo  */
#line 166 "trad.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1518 "trad.tab.c"
    break;

  case 26: /* cuerpo: control_switch cuerpo  */
#line 168 "trad.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1525 "trad.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 171 "trad.y"
                                   { nivel_en_return = nivel_rama ; }
#line 1531 "trad.tab.c"
    break;

  case 28: /* cuerpo: RETURN expresion ';' $@5 cuerpo  */
#line 172 "trad.y"
                                                        { if (strlen(yyvsp[0].code) > 0 || nivel_en_return > 0) {
                                                            if (strlen(yyvsp[0].code) > 0) {
                                                                sprintf(temp, "(return-from %s %s)\n%s", nombre_funcion, yyvsp[-3].code, yyvsp[0].code) ;
                                                            } else {
                                                                sprintf(temp, "(return-from %s %s)", nombre_funcion, yyvsp[-3].code) ;
                                                            }     
                                                          } else {
                                                            sprintf(temp, "%s", yyvsp[-3].code) ;
                                                          }
                                                          yyval.code = gen_code(temp) ; }
#line 1546 "trad.tab.c"
    break;

  case 29: /* cuerpo: %empty  */
#line 182 "trad.y"
                                                        { yyval.code = gen_code("") ; }
#line 1552 "trad.tab.c"
    break;

  case 30: /* abre_rama: %empty  */
#line 184 "trad.y"
                         {nivel_rama++ ;}
#line 1558 "trad.tab.c"
    break;

  case 31: /* bucle_while: WHILE '(' expresion ')' '{' abre_rama cuerpo '}'  */
#line 187 "trad.y"
                                                                         { nivel_rama-- ;
                                                                            sprintf (temp, "(loop while %s do\n%s)", yyvsp[-5].code, yyvsp[-1].code) ;
                                                                            yyval.code = gen_code(temp) ; }
#line 1566 "trad.tab.c"
    break;

  case 32: /* bucle_for: FOR '(' inicializ ';' expresion ';' oper_for ')' '{' abre_rama cuerpo '}'  */
#line 193 "trad.y"
                                                                             {  nivel_rama--;
                                                                                sprintf(temp, "%s\n(loop while %s do\n%s\n%s)", yyvsp[-9].code, yyvsp[-7].code, yyvsp[-1].code, yyvsp[-5].code) ;
                                                                                yyval.code = gen_code(temp) ; }
#line 1574 "trad.tab.c"
    break;

  case 33: /* inicializ: IDENTIF '=' expresion  */
#line 198 "trad.y"
                                                                      { if (en_funcion && es_local(yyvsp[-2].code))
                                                                            sprintf(temp, "(setf %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                        else
                                                                            sprintf(temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                                        yyval.code = gen_code(temp) ; }
#line 1584 "trad.tab.c"
    break;

  case 34: /* inicializ: INTEGER IDENTIF '=' expresion  */
#line 203 "trad.y"
                                                                      { insertar_local(yyvsp[-2].code) ;
                                                                        sprintf(temp, "(setq %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;  
                                                                        yyval.code = gen_code(temp) ;}
#line 1592 "trad.tab.c"
    break;

  case 35: /* oper_for: INC '(' IDENTIF ')'  */
#line 208 "trad.y"
                                                                       { if (en_funcion && es_local(yyvsp[-1].code)) {
                                                                            sprintf(temp, "(setf %s (+ %s 1))", nombre_local(yyvsp[-1].code), nombre_local(yyvsp[-1].code)) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf %s (+ %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1603 "trad.tab.c"
    break;

  case 36: /* oper_for: DEC '(' IDENTIF ')'  */
#line 214 "trad.y"
                                                                       { if (en_funcion && es_local(yyvsp[-1].code)) {
                                                                            sprintf(temp, "(setf %s (- %s 1))", nombre_local(yyvsp[-1].code), nombre_local(yyvsp[-1].code)) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf %s (- %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1614 "trad.tab.c"
    break;

  case 37: /* control_if: IF '(' expresion ')' '{' abre_rama cuerpo '}'  */
#line 222 "trad.y"
                                                                        { nivel_rama-- ; 
                                                                         sprintf(temp, "(if %s\n%s)", yyvsp[-5].code, wrap_progn(yyvsp[-1].code)) ;
                                                                         yyval.code = gen_code(temp) ; }
#line 1622 "trad.tab.c"
    break;

  case 38: /* control_if: IF '(' expresion ')' '{' abre_rama cuerpo '}' ELSE '{' abre_rama cuerpo '}'  */
#line 226 "trad.y"
                                                                        { nivel_rama -= 2 ; 
                                                                          sprintf(temp, "(if %s\n%s\n%s)", yyvsp[-10].code, wrap_progn(yyvsp[-6].code), wrap_progn(yyvsp[-1].code)) ;
                                                                          yyval.code = gen_code(temp) ; }
#line 1630 "trad.tab.c"
    break;

  case 39: /* control_switch: SWITCH '(' IDENTIF ')' '{' switch_cases '}'  */
#line 232 "trad.y"
                                                            { sprintf(temp, "(case %s\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1637 "trad.tab.c"
    break;

  case 40: /* switch_cases: CASE NUMBER ':' abre_rama cuerpo BREAK ';' switch_cases  */
#line 237 "trad.y"
                                                            { nivel_rama-- ;
                                                              sprintf(temp, "(%d\n%s)\n%s", yyvsp[-6].value, yyvsp[-3].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1645 "trad.tab.c"
    break;

  case 41: /* switch_cases: DEFAULT ':' abre_rama cuerpo BREAK ';'  */
#line 241 "trad.y"
                                                            { nivel_rama-- ;
                                                              sprintf(temp, "(otherwise\n%s)", yyvsp[-2].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1653 "trad.tab.c"
    break;

  case 42: /* switch_cases: %empty  */
#line 244 "trad.y"
                                                            { yyval.code = gen_code("") ; }
#line 1659 "trad.tab.c"
    break;

  case 43: /* sentencia: INTEGER IDENTIF '=' expresion  */
#line 247 "trad.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-2].code) ;
                                                                            sprintf (temp, "(setq %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                         } else {
                                                                            sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                                         }
                                                                        yyval.code = gen_code (temp) ; }
#line 1671 "trad.tab.c"
    break;

  case 44: /* sentencia: PRINTF '(' STRING ',' elemento mult_elementos ')'  */
#line 254 "trad.y"
                                                                       { if (strlen(yyvsp[-1].code) > 0) {
                                                                            sprintf (temp, "(princ %s)\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(princ %s)", yyvsp[-2].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1682 "trad.tab.c"
    break;

  case 45: /* sentencia: INTEGER IDENTIF  */
#line 260 "trad.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[0].code);
                                                                            sprintf (temp, "(setq %s 0)", nombre_local(yyvsp[0].code)) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1694 "trad.tab.c"
    break;

  case 46: /* sentencia: INTEGER IDENTIF mult_asign  */
#line 267 "trad.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-1].code);
                                                                            sprintf (temp, "(setq %s 0) %s", nombre_local(yyvsp[-1].code), yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1706 "trad.tab.c"
    break;

  case 47: /* sentencia: INTEGER IDENTIF '=' expresion mult_asign  */
#line 274 "trad.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-3].code);
                                                                            sprintf (temp, "(setq %s %s) %s", nombre_local(yyvsp[-3].code), yyvsp[-1].code, yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s %s) %s", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1718 "trad.tab.c"
    break;

  case 48: /* sentencia: IDENTIF '=' expresion  */
#line 281 "trad.y"
                                                                       { if (en_funcion && es_local(yyvsp[-2].code)) {
                                                                            sprintf (temp, "(setf %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1729 "trad.tab.c"
    break;

  case 49: /* sentencia: PUTS '(' STRING ')'  */
#line 287 "trad.y"
                                                                       { sprintf(temp, "(print \"%s\")", yyvsp[-1].code) ;
                                                                        yyval.code = gen_code (temp) ; }
#line 1736 "trad.tab.c"
    break;

  case 50: /* sentencia: IDENTIF '(' lista_params ')'  */
#line 289 "trad.y"
                                                                       { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                                        yyval.code = gen_code(temp) ; }
#line 1743 "trad.tab.c"
    break;

  case 51: /* sentencia: INTEGER IDENTIF '[' NUMBER ']'  */
#line 291 "trad.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-3].code) ;
                                                                            sprintf(temp, "(setq %s (make-array %d))", nombre_local(yyvsp[-3].code), yyvsp[-1].value) ;
                                                                        } else {
                                                                            sprintf(temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1755 "trad.tab.c"
    break;

  case 52: /* sentencia: IDENTIF '[' expresion ']' '=' expresion  */
#line 298 "trad.y"
                                                                       { if (en_funcion && es_local(yyvsp[-5].code)) {
                                                                            sprintf(temp, "(setf (aref %s %s) %s)", nombre_local(yyvsp[-5].code), yyvsp[-3].code, yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf (aref %s %s) %s)", yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1766 "trad.tab.c"
    break;

  case 53: /* lista_params: expresion r_lista_params  */
#line 306 "trad.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1773 "trad.tab.c"
    break;

  case 54: /* lista_params: %empty  */
#line 308 "trad.y"
                                                        { yyval.code = gen_code("") ; }
#line 1779 "trad.tab.c"
    break;

  case 55: /* r_lista_params: ',' expresion r_lista_params  */
#line 311 "trad.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1786 "trad.tab.c"
    break;

  case 56: /* r_lista_params: %empty  */
#line 313 "trad.y"
                                                        { yyval.code = gen_code("") ; }
#line 1792 "trad.tab.c"
    break;

  case 57: /* elemento: expresion  */
#line 316 "trad.y"
                                                        { yyval.code = yyvsp[0].code ; }
#line 1798 "trad.tab.c"
    break;

  case 58: /* elemento: STRING  */
#line 317 "trad.y"
                                                        { sprintf(temp, "\"%s\"", yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1805 "trad.tab.c"
    break;

  case 59: /* mult_elementos: ',' elemento mult_elementos  */
#line 321 "trad.y"
                                                        { if (strlen(yyvsp[0].code) > 0) {
                                                              sprintf(temp, "(princ %s)\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          } else {
                                                              sprintf(temp, "(princ %s)", yyvsp[-1].code) ;
                                                          }
                                                          yyval.code = gen_code(temp) ; }
#line 1816 "trad.tab.c"
    break;

  case 60: /* mult_elementos: %empty  */
#line 327 "trad.y"
                                                        { yyval.code = gen_code("") ; }
#line 1822 "trad.tab.c"
    break;

  case 61: /* mult_asign: ',' IDENTIF '=' expresion mult_asign  */
#line 330 "trad.y"
                                                        { if (en_funcion) {
                                                              insertar_local(yyvsp[-3].code) ;
                                                              sprintf (temp, "(setq %s %s) %s", nombre_local(yyvsp[-3].code), yyvsp[-1].code, yyvsp[0].code) ;
                                                          } else {
                                                              sprintf (temp, "(setq %s %s) %s", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code) ;
                                                          }
                                                          yyval.code = gen_code (temp) ; }
#line 1834 "trad.tab.c"
    break;

  case 62: /* mult_asign: ',' IDENTIF mult_asign  */
#line 337 "trad.y"
                                                        { if (en_funcion) {
                                                              insertar_local(yyvsp[-1].code) ;
                                                              sprintf (temp, "(setq %s 0) %s", nombre_local(yyvsp[-1].code), yyvsp[0].code) ;
                                                          } else {
                                                              sprintf (temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          }
                                                          yyval.code = gen_code (temp) ; }
#line 1846 "trad.tab.c"
    break;

  case 63: /* mult_asign: ',' IDENTIF '=' expresion  */
#line 344 "trad.y"
                                                        { if (en_funcion) {
                                                              insertar_local(yyvsp[-2].code) ;
                                                              sprintf (temp, "(setq %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                          } else {
                                                              sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                          }
                                                          yyval.code = gen_code (temp) ; }
#line 1858 "trad.tab.c"
    break;

  case 64: /* mult_asign: ',' IDENTIF  */
#line 351 "trad.y"
                                                        { if (en_funcion) {
                                                              insertar_local(yyvsp[0].code) ;
                                                              sprintf (temp, "(setq %s 0)", nombre_local(yyvsp[0].code)) ;
                                                          } else {
                                                              sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                                          }
                                                          yyval.code = gen_code (temp) ; }
#line 1870 "trad.tab.c"
    break;

  case 65: /* expresion: termino  */
#line 360 "trad.y"
                                         { yyval = yyvsp[0] ; }
#line 1876 "trad.tab.c"
    break;

  case 66: /* expresion: expresion '+' expresion  */
#line 361 "trad.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1883 "trad.tab.c"
    break;

  case 67: /* expresion: expresion '-' expresion  */
#line 363 "trad.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1890 "trad.tab.c"
    break;

  case 68: /* expresion: expresion '*' expresion  */
#line 365 "trad.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1897 "trad.tab.c"
    break;

  case 69: /* expresion: expresion '/' expresion  */
#line 367 "trad.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1904 "trad.tab.c"
    break;

  case 70: /* expresion: expresion AND expresion  */
#line 369 "trad.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1911 "trad.tab.c"
    break;

  case 71: /* expresion: expresion OR expresion  */
#line 371 "trad.y"
                                        { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1918 "trad.tab.c"
    break;

  case 72: /* expresion: expresion NEQ expresion  */
#line 373 "trad.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1925 "trad.tab.c"
    break;

  case 73: /* expresion: expresion EQ expresion  */
#line 375 "trad.y"
                                        { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1932 "trad.tab.c"
    break;

  case 74: /* expresion: expresion '<' expresion  */
#line 377 "trad.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1939 "trad.tab.c"
    break;

  case 75: /* expresion: expresion LTEQ expresion  */
#line 379 "trad.y"
                                          { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1946 "trad.tab.c"
    break;

  case 76: /* expresion: expresion '>' expresion  */
#line 381 "trad.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1953 "trad.tab.c"
    break;

  case 77: /* expresion: expresion GTEQ expresion  */
#line 383 "trad.y"
                                          { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1960 "trad.tab.c"
    break;

  case 78: /* expresion: expresion '%' expresion  */
#line 385 "trad.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1967 "trad.tab.c"
    break;

  case 79: /* termino: operando  */
#line 389 "trad.y"
                                                   { yyval = yyvsp[0] ; }
#line 1973 "trad.tab.c"
    break;

  case 80: /* termino: '+' operando  */
#line 390 "trad.y"
                                                   { yyval = yyvsp[0] ; }
#line 1979 "trad.tab.c"
    break;

  case 81: /* termino: '-' operando  */
#line 391 "trad.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1986 "trad.tab.c"
    break;

  case 82: /* termino: '!' operando  */
#line 393 "trad.y"
                                                   { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ;}
#line 1993 "trad.tab.c"
    break;

  case 83: /* operando: IDENTIF  */
#line 397 "trad.y"
                                            { if (en_funcion && es_local(yyvsp[0].code))
                                                sprintf(temp, "%s", nombre_local(yyvsp[0].code)) ;
                                              else
                                                sprintf(temp, "%s", yyvsp[0].code) ;
                                            yyval.code = gen_code(temp) ; }
#line 2003 "trad.tab.c"
    break;

  case 84: /* operando: NUMBER  */
#line 402 "trad.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 2010 "trad.tab.c"
    break;

  case 85: /* operando: '(' expresion ')'  */
#line 404 "trad.y"
                                         { yyval = yyvsp[-1] ; }
#line 2016 "trad.tab.c"
    break;

  case 86: /* operando: IDENTIF '(' lista_params ')'  */
#line 406 "trad.y"
                                          { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ; 
                                            yyval.code = gen_code(temp) ; }
#line 2023 "trad.tab.c"
    break;

  case 87: /* operando: IDENTIF '[' expresion ']'  */
#line 408 "trad.y"
                                            { if (en_funcion && es_local(yyvsp[-3].code)) {
                                                sprintf(temp, "(aref %s %s)", nombre_local(yyvsp[-3].code), yyvsp[-1].code) ;
                                              } else {
                                                sprintf(temp, "(aref %s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                              }
                                              yyval.code = gen_code(temp) ; }
#line 2034 "trad.tab.c"
    break;


#line 2038 "trad.tab.c"

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

#line 417 "trad.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

void insertar_local(char *nombre) {
    vars_locales[n_vars_locales++] = gen_code(nombre);
}

int es_local(char *nombre) {
    int i;
    for (i = 0; i < n_vars_locales; i++) {
        if (strcmp(vars_locales[i], nombre) == 0) return 1;
    }
    return 0;
}

void limpiar_locales() {
    n_vars_locales = 0;
}

char *nombre_local(char *var) {
    static char buf[512];
    sprintf(buf, "%s_%s", nombre_funcion, var);
    return buf;
}

char *wrap_progn(char *codigo) {
    static char buf[4096];
    if (strchr(codigo, '\n') != NULL) {
        sprintf(buf, "(progn\n%s)", codigo);
    } else {
        sprintf(buf, "%s", codigo);
    }
    return gen_code(buf);
}

int yyerror (char* mensaje) {
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n) {
    char ltemp [2048] ;

    sprintf (ltemp, "%d", n) ;

    return gen_code (ltemp) ;
}

char *char_to_string (char c) {
    char ltemp [2048] ;

    sprintf (ltemp, "%c", c) ;

    return gen_code (ltemp) ;
}

char *my_malloc (int nbytes) { // reserva n bytes de memoria dinamica 
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = {          // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "while",       WHILE,
    "switch",      SWITCH,
    "case",        CASE,
    "break",       BREAK,
    "default",     DEFAULT,
    "puts",        PUTS,
    "printf",      PRINTF,
    "||",          OR,
    "&&",          AND,
    "==",          EQ,
    "!=",          NEQ,
    ">=",          GTEQ,
    "<=",          LTEQ,
    "if",          IF,
    "else",        ELSE,
    "for",         FOR,
    "inc",         INC,
    "dec",         DEC,
    "return",      RETURN,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                               // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
