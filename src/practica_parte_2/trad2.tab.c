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
#line 3 "trad2.y"
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


#line 128 "trad2.tab.c"

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
    NUMBER = 258,                  /* NUMBER  */
    IDENTIF = 259,                 /* IDENTIF  */
    INTEGER = 260,                 /* INTEGER  */
    STRING = 261,                  /* STRING  */
    PUTS = 262,                    /* PUTS  */
    PRINTF = 263,                  /* PRINTF  */
    MAIN = 264,                    /* MAIN  */
    OR = 265,                      /* OR  */
    AND = 266,                     /* AND  */
    NEQ = 267,                     /* NEQ  */
    EQ = 268,                      /* EQ  */
    LTEQ = 269,                    /* LTEQ  */
    GTEQ = 270,                    /* GTEQ  */
    FOR = 271,                     /* FOR  */
    WHILE = 272,                   /* WHILE  */
    IF = 273,                      /* IF  */
    INC = 274,                     /* INC  */
    DEC = 275,                     /* DEC  */
    ELSE = 276,                    /* ELSE  */
    SWITCH = 277,                  /* SWITCH  */
    CASE = 278,                    /* CASE  */
    BREAK = 279,                   /* BREAK  */
    DEFAULT = 280,                 /* DEFAULT  */
    RETURN = 281,                  /* RETURN  */
    UNARY_SIGN = 282               /* UNARY_SIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_axioma = 45,                    /* axioma  */
  YYSYMBOL_declaraciones_funciones = 46,   /* declaraciones_funciones  */
  YYSYMBOL_decl_global = 47,               /* decl_global  */
  YYSYMBOL_funcion = 48,                   /* funcion  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_lista_args = 50,                /* lista_args  */
  YYSYMBOL_r_lista_args = 51,              /* r_lista_args  */
  YYSYMBOL_funcion_main = 52,              /* funcion_main  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_cuerpo = 54,                    /* cuerpo  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_abre_rama = 56,                 /* abre_rama  */
  YYSYMBOL_bucle_while = 57,               /* bucle_while  */
  YYSYMBOL_bucle_for = 58,                 /* bucle_for  */
  YYSYMBOL_inicializ = 59,                 /* inicializ  */
  YYSYMBOL_expr_cond = 60,                 /* expr_cond  */
  YYSYMBOL_oper_for = 61,                  /* oper_for  */
  YYSYMBOL_control_if = 62,                /* control_if  */
  YYSYMBOL_control_switch = 63,            /* control_switch  */
  YYSYMBOL_switch_cases = 64,              /* switch_cases  */
  YYSYMBOL_sentencia = 65,                 /* sentencia  */
  YYSYMBOL_lista_params = 66,              /* lista_params  */
  YYSYMBOL_r_lista_params = 67,            /* r_lista_params  */
  YYSYMBOL_elemento = 68,                  /* elemento  */
  YYSYMBOL_mult_elementos = 69,            /* mult_elementos  */
  YYSYMBOL_mult_asign = 70,                /* mult_asign  */
  YYSYMBOL_expresion = 71,                 /* expresion  */
  YYSYMBOL_termino = 72,                   /* termino  */
  YYSYMBOL_operando = 73                   /* operando  */
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
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

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
      38,    39,    32,    30,    42,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    37,
      29,    27,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
       0,    98,    98,   103,   105,   107,   110,   112,   114,   116,
     120,   119,   130,   132,   135,   137,   141,   140,   149,   152,
     154,   156,   158,   160,   163,   163,   174,   176,   179,   184,
     189,   191,   196,   199,   205,   213,   216,   222,   227,   231,
     235,   238,   245,   247,   254,   261,   268,   274,   276,   280,
     282,   285,   287,   290,   291,   295,   297,   300,   302,   304,
     306,   310,   311,   313,   315,   317,   319,   321,   323,   325,
     327,   329,   331,   333,   335,   339,   340,   341,   343,   347,
     352,   354,   355
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
  "'*'", "'/'", "'%'", "'!'", "UNARY_SIGN", "';'", "'('", "')'", "'{'",
  "'}'", "','", "':'", "$accept", "axioma", "declaraciones_funciones",
  "decl_global", "funcion", "$@1", "lista_args", "r_lista_args",
  "funcion_main", "$@2", "cuerpo", "$@3", "abre_rama", "bucle_while",
  "bucle_for", "inicializ", "expr_cond", "oper_for", "control_if",
  "control_switch", "switch_cases", "sentencia", "lista_params",
  "r_lista_params", "elemento", "mult_elementos", "mult_asign",
  "expresion", "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -32,     7,    16,    31,     5,    75,    45,   -19,  -153,
       9,  -153,    75,  -153,    50,    77,   117,   118,  -153,    84,
    -153,    86,  -153,    87,   -18,  -153,   121,  -153,    91,  -153,
      14,  -153,    92,   129,   275,  -153,    96,    -1,    -1,    -1,
      14,    79,  -153,  -153,   275,    86,     8,   131,    98,    99,
     102,   103,   104,   105,    14,   106,   275,   275,   275,   275,
     108,    14,  -153,  -153,  -153,   151,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,  -153,
     109,  -153,    14,    14,   -17,   143,   145,    83,    14,    14,
     148,   223,  -153,  -153,  -153,  -153,  -153,   275,   128,   144,
    -153,    71,   256,   244,   244,    42,    42,    42,    42,    36,
      36,  -153,  -153,  -153,  -153,   233,   130,    14,  -153,   132,
     126,   133,   166,   150,   181,   193,   149,  -153,  -153,  -153,
      14,  -153,  -153,    79,  -153,     1,    14,   162,    14,   157,
     158,   159,   275,   144,  -153,  -153,   160,   233,   233,    14,
     163,   233,  -153,  -153,     3,  -153,  -153,     1,   177,   233,
      95,   275,   275,   198,   174,   178,   160,  -153,   180,   190,
     191,   188,   199,   196,  -153,  -153,  -153,   227,   237,   202,
    -153,   228,  -153,   275,   211,   242,  -153,   254,   275,   271,
    -153,  -153,   275,  -153,   272,   261,   258,   275,   263,     3,
    -153,   262,     3,  -153,  -153,  -153
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,    18,     0,     5,    13,     6,     1,
       0,     2,     5,     4,     0,     0,     0,     0,     9,     0,
       3,    15,    10,     7,    60,    16,     0,    12,     0,     8,
       0,    58,     0,     0,    26,    80,    79,     0,     0,     0,
       0,    59,    61,    75,    26,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    26,    26,    26,
       0,    50,    76,    77,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,    14,     0,    50,    43,     0,     0,     0,     0,     0,
       0,     0,    11,    20,    22,    21,    23,    26,     0,    52,
      81,    67,    66,    68,    69,    71,    73,    72,    70,    62,
      63,    64,    65,    74,    17,    46,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    19,    82,
       0,    49,    48,    41,    47,     0,     0,     0,     0,     0,
       0,     0,    26,    52,    45,    54,    56,    53,    30,     0,
       0,    32,    27,    27,    40,    25,    51,     0,     0,    31,
       0,    26,    26,     0,     0,     0,    56,    42,     0,     0,
       0,     0,     0,     0,    27,    37,    55,     0,     0,     0,
      28,    35,    27,    26,     0,     0,    27,     0,    26,     0,
      33,    34,    26,    27,     0,     0,     0,    26,     0,    40,
      29,     0,    40,    39,    36,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,    21,  -153,  -153,  -153,  -153,   257,  -153,  -153,
     -44,  -153,  -152,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -151,  -153,   221,   164,   152,   139,    -3,   -11,  -153,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    28,    15,    27,    11,    32,
      55,   142,   161,    56,    57,   123,   150,   170,    58,    59,
     165,    60,    98,   131,   146,   158,    18,    99,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      80,   162,    35,    36,    35,    36,     7,   145,    16,    30,
     117,     8,    93,    94,    95,    96,     9,    35,    36,    41,
      29,    31,   183,    17,    17,    17,   163,    13,   164,    65,
     188,    37,    38,    20,   192,    82,    39,    40,    79,    40,
      10,   197,    12,    91,    37,    38,    83,    19,   203,    39,
      14,   205,    40,   128,    21,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    76,    77,
      78,   115,    74,    75,    76,    77,    78,   124,   125,     1,
       2,   118,    67,    68,    69,    70,    71,   121,   122,    66,
      67,    68,    69,    70,    71,    62,    63,    64,   155,    72,
      73,    74,    75,    76,    77,    78,   133,    72,    73,    74,
      75,    76,    77,    78,   168,   169,    22,   171,   172,   143,
      23,    17,    24,    25,   147,   148,    33,   151,    26,    17,
     144,    34,    44,    45,    61,    84,    85,    86,   159,   189,
      87,    88,    89,    90,   194,    97,   147,    92,   196,   119,
     114,   120,   126,   201,    66,    67,    68,    69,    70,    71,
     136,    66,    67,    68,    69,    70,    71,   129,   135,   132,
     137,   134,    72,    73,    74,    75,    76,    77,    78,    72,
      73,    74,    75,    76,    77,    78,   130,   138,   141,   149,
     100,    66,    67,    68,    69,    70,    71,   152,   153,   154,
     160,   173,   157,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,   167,   174,   177,   175,
     139,    72,    73,    74,    75,    76,    77,    78,   178,   180,
     179,   184,   140,    66,    67,    68,    69,    70,    71,   182,
     181,   185,   186,    66,    67,    68,    69,    70,    71,   187,
     190,    72,    73,    74,    75,    76,    77,    78,    70,    71,
     127,    72,    73,    74,    75,    76,    77,    78,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    46,
      47,   191,    48,    49,    72,    73,    74,    75,    76,    77,
      78,    50,    51,    52,   193,   195,   198,    53,   199,   200,
     202,    54,    81,   204,   116,   176,     0,   156,     0,   166
};

static const yytype_int16 yycheck[] =
{
      44,   153,     3,     4,     3,     4,    38,     6,    27,    27,
      27,     4,    56,    57,    58,    59,     0,     3,     4,    30,
      23,    24,   174,    42,    42,    42,    23,     6,    25,    40,
     182,    30,    31,    12,   186,    27,    35,    38,    41,    38,
       9,   193,    37,    54,    30,    31,    38,    38,   199,    35,
       5,   202,    38,    97,     4,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    32,    33,
      34,    82,    30,    31,    32,    33,    34,    88,    89,     4,
       5,    84,    11,    12,    13,    14,    15,     4,     5,    10,
      11,    12,    13,    14,    15,    37,    38,    39,   142,    28,
      29,    30,    31,    32,    33,    34,   117,    28,    29,    30,
      31,    32,    33,    34,    19,    20,    39,   161,   162,   130,
       3,    42,     4,    39,   135,   136,     5,   138,    42,    42,
     133,    40,    40,     4,    38,     4,    38,    38,   149,   183,
      38,    38,    38,    38,   188,    37,   157,    41,   192,     6,
      41,     6,     4,   197,    10,    11,    12,    13,    14,    15,
      27,    10,    11,    12,    13,    14,    15,    39,    42,    39,
       4,    39,    28,    29,    30,    31,    32,    33,    34,    28,
      29,    30,    31,    32,    33,    34,    42,    37,    39,    27,
      39,    10,    11,    12,    13,    14,    15,    40,    40,    40,
      37,     3,    42,    10,    11,    12,    13,    14,    15,    28,
      29,    30,    31,    32,    33,    34,    39,    43,    38,    41,
      39,    28,    29,    30,    31,    32,    33,    34,    38,    41,
      39,     4,    39,    10,    11,    12,    13,    14,    15,    43,
      41,     4,    40,    10,    11,    12,    13,    14,    15,    21,
      39,    28,    29,    30,    31,    32,    33,    34,    14,    15,
      37,    28,    29,    30,    31,    32,    33,    34,    12,    13,
      14,    15,    28,    29,    30,    31,    32,    33,    34,     4,
       5,    39,     7,     8,    28,    29,    30,    31,    32,    33,
      34,    16,    17,    18,    40,    24,    24,    22,    37,    41,
      37,    26,    45,    41,    83,   166,    -1,   143,    -1,   157
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    45,    46,    47,    48,    38,     4,     0,
       9,    52,    37,    46,     5,    50,    27,    42,    70,    38,
      46,     4,    39,     3,     4,    39,    42,    51,    49,    70,
      27,    70,    53,     5,    40,     3,     4,    30,    31,    35,
      38,    71,    72,    73,    40,     4,     4,     5,     7,     8,
      16,    17,    18,    22,    26,    54,    57,    58,    62,    63,
      65,    38,    73,    73,    73,    71,    10,    11,    12,    13,
      14,    15,    28,    29,    30,    31,    32,    33,    34,    70,
      54,    51,    27,    38,     4,    38,    38,    38,    38,    38,
      38,    71,    41,    54,    54,    54,    54,    37,    66,    71,
      39,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    41,    71,    66,    27,    70,     6,
       6,     4,     5,    59,    71,    71,     4,    37,    54,    39,
      42,    67,    39,    71,    39,    42,    27,     4,    37,    39,
      39,    39,    55,    71,    70,     6,    68,    71,    71,    27,
      60,    71,    40,    40,    40,    54,    67,    42,    69,    71,
      37,    56,    56,    23,    25,    64,    68,    39,    19,    20,
      61,    54,    54,     3,    43,    41,    69,    38,    38,    39,
      41,    41,    43,    56,     4,     4,    40,    21,    56,    54,
      39,    39,    56,    40,    54,    24,    54,    56,    24,    37,
      41,    54,    37,    64,    41,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    47,    47,    47,    47,
      49,    48,    50,    50,    51,    51,    53,    52,    52,    54,
      54,    54,    54,    54,    55,    54,    54,    56,    57,    58,
      59,    59,    60,    61,    61,    62,    62,    63,    64,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     2,     4,     5,     3,
       0,     8,     3,     0,     4,     0,     0,     7,     0,     3,
       2,     2,     2,     2,     0,     5,     0,     0,     8,    12,
       3,     4,     1,     4,     4,     8,    13,     7,     8,     7,
       0,     4,     7,     2,     3,     5,     3,     4,     4,     2,
       0,     3,     0,     1,     1,     3,     0,     5,     3,     4,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     2,     1,
       1,     3,     4
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
#line 98 "trad2.y"
                                                        { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; 
                                                          printf("%s\n", yyval.code) ; }
#line 1398 "trad2.tab.c"
    break;

  case 3: /* declaraciones_funciones: decl_global ';' declaraciones_funciones  */
#line 103 "trad2.y"
                                                                            { sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                                                             yyval.code = gen_code(temp) ; }
#line 1405 "trad2.tab.c"
    break;

  case 4: /* declaraciones_funciones: funcion declaraciones_funciones  */
#line 105 "trad2.y"
                                                                            { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                                                              yyval.code = gen_code(temp) ; }
#line 1412 "trad2.tab.c"
    break;

  case 5: /* declaraciones_funciones: %empty  */
#line 107 "trad2.y"
                                                                            { yyval.code = gen_code("") ; }
#line 1418 "trad2.tab.c"
    break;

  case 6: /* decl_global: INTEGER IDENTIF  */
#line 110 "trad2.y"
                                                        { sprintf(temp, "(setq %s 0)", yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1425 "trad2.tab.c"
    break;

  case 7: /* decl_global: INTEGER IDENTIF '=' NUMBER  */
#line 112 "trad2.y"
                                                        { sprintf(temp, "(setq %s %d)", yyvsp[-2].code, yyvsp[0].value) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1432 "trad2.tab.c"
    break;

  case 8: /* decl_global: INTEGER IDENTIF '=' NUMBER mult_asign  */
#line 114 "trad2.y"
                                                        { sprintf(temp, "(setq %s %d) %s", yyvsp[-3].code, yyvsp[-1].value, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1439 "trad2.tab.c"
    break;

  case 9: /* decl_global: INTEGER IDENTIF mult_asign  */
#line 116 "trad2.y"
                                                        { sprintf(temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1446 "trad2.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 120 "trad2.y"
                                                        { strcpy(nombre_funcion, yyvsp[-3].code) ; 
                                                          limpiar_locales();
                                                          en_funcion = 1;}
#line 1454 "trad2.tab.c"
    break;

  case 11: /* funcion: IDENTIF '(' lista_args ')' $@1 '{' cuerpo '}'  */
#line 125 "trad2.y"
                                                        {en_funcion = 0;
                                                          sprintf(temp, "(defun %s (%s)\n%s)", yyvsp[-7].code, yyvsp[-5].code, yyvsp[-1].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1462 "trad2.tab.c"
    break;

  case 12: /* lista_args: INTEGER IDENTIF r_lista_args  */
#line 130 "trad2.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1469 "trad2.tab.c"
    break;

  case 13: /* lista_args: %empty  */
#line 132 "trad2.y"
                                                        { yyval.code = gen_code("") ; }
#line 1475 "trad2.tab.c"
    break;

  case 14: /* r_lista_args: ',' INTEGER IDENTIF r_lista_args  */
#line 135 "trad2.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1482 "trad2.tab.c"
    break;

  case 15: /* r_lista_args: %empty  */
#line 137 "trad2.y"
                                                        { yyval.code = gen_code("") ; }
#line 1488 "trad2.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 141 "trad2.y"
                                                        { strcpy(nombre_funcion, "main") ;
                                                          limpiar_locales();
                                                          en_funcion = 1; }
#line 1496 "trad2.tab.c"
    break;

  case 17: /* funcion_main: MAIN '(' ')' $@2 '{' cuerpo '}'  */
#line 146 "trad2.y"
                                                        { en_funcion = 0; 
                                                          sprintf(temp, "(defun main ()\n%s)", yyvsp[-1].code) ; 
                                                          yyval.code = gen_code(temp) ; }
#line 1504 "trad2.tab.c"
    break;

  case 18: /* funcion_main: %empty  */
#line 149 "trad2.y"
                                                        { yyval.code = gen_code("") ; }
#line 1510 "trad2.tab.c"
    break;

  case 19: /* cuerpo: sentencia ';' cuerpo  */
#line 152 "trad2.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1517 "trad2.tab.c"
    break;

  case 20: /* cuerpo: bucle_while cuerpo  */
#line 154 "trad2.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1524 "trad2.tab.c"
    break;

  case 21: /* cuerpo: control_if cuerpo  */
#line 156 "trad2.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1531 "trad2.tab.c"
    break;

  case 22: /* cuerpo: bucle_for cuerpo  */
#line 158 "trad2.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1538 "trad2.tab.c"
    break;

  case 23: /* cuerpo: control_switch cuerpo  */
#line 160 "trad2.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1545 "trad2.tab.c"
    break;

  case 24: /* $@3: %empty  */
#line 163 "trad2.y"
                                   { nivel_en_return = nivel_rama ; }
#line 1551 "trad2.tab.c"
    break;

  case 25: /* cuerpo: RETURN expresion ';' $@3 cuerpo  */
#line 164 "trad2.y"
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
#line 1566 "trad2.tab.c"
    break;

  case 26: /* cuerpo: %empty  */
#line 174 "trad2.y"
                                                        { yyval.code = gen_code("") ; }
#line 1572 "trad2.tab.c"
    break;

  case 27: /* abre_rama: %empty  */
#line 176 "trad2.y"
                         {nivel_rama++ ;}
#line 1578 "trad2.tab.c"
    break;

  case 28: /* bucle_while: WHILE '(' expresion ')' '{' abre_rama cuerpo '}'  */
#line 179 "trad2.y"
                                                                         { nivel_rama-- ;
                                                                            sprintf (temp, "(loop while %s do\n%s)", yyvsp[-5].code, yyvsp[-1].code) ;
                                                                            yyval.code = gen_code(temp) ; }
#line 1586 "trad2.tab.c"
    break;

  case 29: /* bucle_for: FOR '(' inicializ ';' expr_cond ';' oper_for ')' '{' abre_rama cuerpo '}'  */
#line 185 "trad2.y"
                                                                             {  nivel_rama--;
                                                                                sprintf(temp, "%s\n(loop while %s do\n%s\n%s)", yyvsp[-9].code, yyvsp[-7].code, yyvsp[-1].code, yyvsp[-5].code) ;
                                                                                yyval.code = gen_code(temp) ; }
#line 1594 "trad2.tab.c"
    break;

  case 30: /* inicializ: IDENTIF '=' expresion  */
#line 189 "trad2.y"
                                                                      { sprintf(temp, "(setf %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                        yyval.code = gen_code(temp) ; }
#line 1601 "trad2.tab.c"
    break;

  case 31: /* inicializ: INTEGER IDENTIF '=' expresion  */
#line 191 "trad2.y"
                                                                      { insertar_local(yyvsp[-2].code) ;
                                                                        sprintf(temp, "(setq %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;  
                                                                        yyval.code = gen_code(temp) ;}
#line 1609 "trad2.tab.c"
    break;

  case 32: /* expr_cond: expresion  */
#line 196 "trad2.y"
                                                                       { yyval.code  = yyvsp[0].code ; }
#line 1615 "trad2.tab.c"
    break;

  case 33: /* oper_for: INC '(' IDENTIF ')'  */
#line 199 "trad2.y"
                                                                       { if (en_funcion && es_local(yyvsp[-1].code)) {
                                                                            sprintf(temp, "(setf %s (+ %s 1))", nombre_local(yyvsp[-1].code), nombre_local(yyvsp[-1].code)) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf %s (+ %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1626 "trad2.tab.c"
    break;

  case 34: /* oper_for: DEC '(' IDENTIF ')'  */
#line 205 "trad2.y"
                                                                       { if (en_funcion && es_local(yyvsp[-1].code)) {
                                                                            sprintf(temp, "(setf %s (- %s 1))", nombre_local(yyvsp[-1].code), nombre_local(yyvsp[-1].code)) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf %s (- %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1637 "trad2.tab.c"
    break;

  case 35: /* control_if: IF '(' expresion ')' '{' abre_rama cuerpo '}'  */
#line 213 "trad2.y"
                                                                        { nivel_rama-- ; 
                                                                         sprintf(temp, "(if %s\n%s)", yyvsp[-5].code, wrap_progn(yyvsp[-1].code)) ;
                                                                         yyval.code = gen_code(temp) ; }
#line 1645 "trad2.tab.c"
    break;

  case 36: /* control_if: IF '(' expresion ')' '{' abre_rama cuerpo '}' ELSE '{' abre_rama cuerpo '}'  */
#line 217 "trad2.y"
                                                                        { nivel_rama -= 2 ; 
                                                                          sprintf(temp, "(if %s\n%s\n%s)", yyvsp[-10].code, wrap_progn(yyvsp[-6].code), wrap_progn(yyvsp[-1].code)) ;
                                                                          yyval.code = gen_code(temp) ; }
#line 1653 "trad2.tab.c"
    break;

  case 37: /* control_switch: SWITCH '(' IDENTIF ')' '{' switch_cases '}'  */
#line 223 "trad2.y"
                                                            { sprintf(temp, "(case %s\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1660 "trad2.tab.c"
    break;

  case 38: /* switch_cases: CASE NUMBER ':' abre_rama cuerpo BREAK ';' switch_cases  */
#line 228 "trad2.y"
                                                            { nivel_rama-- ;
                                                              sprintf(temp, "(%d\n%s)\n%s", yyvsp[-6].value, yyvsp[-3].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1668 "trad2.tab.c"
    break;

  case 39: /* switch_cases: DEFAULT ':' abre_rama cuerpo BREAK ';' switch_cases  */
#line 232 "trad2.y"
                                                            { nivel_rama-- ;
                                                              sprintf(temp, "(otherwise\n%s)\n%s", yyvsp[-3].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1676 "trad2.tab.c"
    break;

  case 40: /* switch_cases: %empty  */
#line 235 "trad2.y"
                                                            { yyval.code = gen_code("") ; }
#line 1682 "trad2.tab.c"
    break;

  case 41: /* sentencia: INTEGER IDENTIF '=' expresion  */
#line 238 "trad2.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-2].code) ;
                                                                            sprintf (temp, "(setq %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                         } else {
                                                                            sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                                         }
                                                                        yyval.code = gen_code (temp) ; }
#line 1694 "trad2.tab.c"
    break;

  case 42: /* sentencia: PRINTF '(' STRING ',' elemento mult_elementos ')'  */
#line 245 "trad2.y"
                                                                       { sprintf (temp, "(princ %s) %s", yyvsp[-2].code, yyvsp[-1].code) ;  
                                                                        yyval.code = gen_code (temp) ; }
#line 1701 "trad2.tab.c"
    break;

  case 43: /* sentencia: INTEGER IDENTIF  */
#line 247 "trad2.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[0].code);
                                                                            sprintf (temp, "(setq %s 0)", nombre_local(yyvsp[0].code)) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1713 "trad2.tab.c"
    break;

  case 44: /* sentencia: INTEGER IDENTIF mult_asign  */
#line 254 "trad2.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-1].code);
                                                                            sprintf (temp, "(setq %s 0) %s", nombre_local(yyvsp[-1].code), yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1725 "trad2.tab.c"
    break;

  case 45: /* sentencia: INTEGER IDENTIF '=' expresion mult_asign  */
#line 261 "trad2.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-3].code);
                                                                            sprintf (temp, "(setq %s %s) %s", nombre_local(yyvsp[-3].code), yyvsp[-1].code, yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s %s) %s", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1737 "trad2.tab.c"
    break;

  case 46: /* sentencia: IDENTIF '=' expresion  */
#line 268 "trad2.y"
                                                                       { if (en_funcion && es_local(yyvsp[-2].code)) {
                                                                            sprintf (temp, "(setf %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1748 "trad2.tab.c"
    break;

  case 47: /* sentencia: PUTS '(' STRING ')'  */
#line 274 "trad2.y"
                                                                       { sprintf(temp, "(print \"%s\")", yyvsp[-1].code) ;
                                                                        yyval.code = gen_code (temp) ; }
#line 1755 "trad2.tab.c"
    break;

  case 48: /* sentencia: IDENTIF '(' lista_params ')'  */
#line 276 "trad2.y"
                                                                       { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                                        yyval.code = gen_code(temp) ; }
#line 1762 "trad2.tab.c"
    break;

  case 49: /* lista_params: expresion r_lista_params  */
#line 280 "trad2.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1769 "trad2.tab.c"
    break;

  case 50: /* lista_params: %empty  */
#line 282 "trad2.y"
                                                        { yyval.code = gen_code("") ; }
#line 1775 "trad2.tab.c"
    break;

  case 51: /* r_lista_params: ',' expresion r_lista_params  */
#line 285 "trad2.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1782 "trad2.tab.c"
    break;

  case 52: /* r_lista_params: %empty  */
#line 287 "trad2.y"
                                                        { yyval.code = gen_code("") ; }
#line 1788 "trad2.tab.c"
    break;

  case 53: /* elemento: expresion  */
#line 290 "trad2.y"
                                                        { yyval.code = yyvsp[0].code ; }
#line 1794 "trad2.tab.c"
    break;

  case 54: /* elemento: STRING  */
#line 291 "trad2.y"
                                                        { sprintf(temp, "\"%s\"", yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1801 "trad2.tab.c"
    break;

  case 55: /* mult_elementos: ',' elemento mult_elementos  */
#line 295 "trad2.y"
                                                        { sprintf(temp, "(princ %s) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1808 "trad2.tab.c"
    break;

  case 56: /* mult_elementos: %empty  */
#line 297 "trad2.y"
                                                        { yyval.code = gen_code("") ; }
#line 1814 "trad2.tab.c"
    break;

  case 57: /* mult_asign: ',' IDENTIF '=' expresion mult_asign  */
#line 300 "trad2.y"
                                                        { sprintf (temp, "(setq %s %s) %s", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1821 "trad2.tab.c"
    break;

  case 58: /* mult_asign: ',' IDENTIF mult_asign  */
#line 302 "trad2.y"
                                                        { sprintf (temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1828 "trad2.tab.c"
    break;

  case 59: /* mult_asign: ',' IDENTIF '=' expresion  */
#line 304 "trad2.y"
                                                        { sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                                          yyval.code = gen_code (temp) ; }
#line 1835 "trad2.tab.c"
    break;

  case 60: /* mult_asign: ',' IDENTIF  */
#line 306 "trad2.y"
                                                        { sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1842 "trad2.tab.c"
    break;

  case 61: /* expresion: termino  */
#line 310 "trad2.y"
                                         { yyval = yyvsp[0] ; }
#line 1848 "trad2.tab.c"
    break;

  case 62: /* expresion: expresion '+' expresion  */
#line 311 "trad2.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1855 "trad2.tab.c"
    break;

  case 63: /* expresion: expresion '-' expresion  */
#line 313 "trad2.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1862 "trad2.tab.c"
    break;

  case 64: /* expresion: expresion '*' expresion  */
#line 315 "trad2.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1869 "trad2.tab.c"
    break;

  case 65: /* expresion: expresion '/' expresion  */
#line 317 "trad2.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1876 "trad2.tab.c"
    break;

  case 66: /* expresion: expresion AND expresion  */
#line 319 "trad2.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1883 "trad2.tab.c"
    break;

  case 67: /* expresion: expresion OR expresion  */
#line 321 "trad2.y"
                                        { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1890 "trad2.tab.c"
    break;

  case 68: /* expresion: expresion NEQ expresion  */
#line 323 "trad2.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1897 "trad2.tab.c"
    break;

  case 69: /* expresion: expresion EQ expresion  */
#line 325 "trad2.y"
                                        { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1904 "trad2.tab.c"
    break;

  case 70: /* expresion: expresion '<' expresion  */
#line 327 "trad2.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1911 "trad2.tab.c"
    break;

  case 71: /* expresion: expresion LTEQ expresion  */
#line 329 "trad2.y"
                                          { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1918 "trad2.tab.c"
    break;

  case 72: /* expresion: expresion '>' expresion  */
#line 331 "trad2.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1925 "trad2.tab.c"
    break;

  case 73: /* expresion: expresion GTEQ expresion  */
#line 333 "trad2.y"
                                          { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1932 "trad2.tab.c"
    break;

  case 74: /* expresion: expresion '%' expresion  */
#line 335 "trad2.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1939 "trad2.tab.c"
    break;

  case 75: /* termino: operando  */
#line 339 "trad2.y"
                                                   { yyval = yyvsp[0] ; }
#line 1945 "trad2.tab.c"
    break;

  case 76: /* termino: '+' operando  */
#line 340 "trad2.y"
                                                   { yyval = yyvsp[0] ; }
#line 1951 "trad2.tab.c"
    break;

  case 77: /* termino: '-' operando  */
#line 341 "trad2.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1958 "trad2.tab.c"
    break;

  case 78: /* termino: '!' operando  */
#line 343 "trad2.y"
                                                   { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ;}
#line 1965 "trad2.tab.c"
    break;

  case 79: /* operando: IDENTIF  */
#line 347 "trad2.y"
                                         { if (en_funcion && es_local(yyvsp[0].code))
                                                sprintf(temp, "%s", nombre_local(yyvsp[0].code)) ;
                                            else
                                                sprintf(temp, "%s", yyvsp[0].code) ;
                                            yyval.code = gen_code(temp) ; }
#line 1975 "trad2.tab.c"
    break;

  case 80: /* operando: NUMBER  */
#line 352 "trad2.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 1982 "trad2.tab.c"
    break;

  case 81: /* operando: '(' expresion ')'  */
#line 354 "trad2.y"
                                         { yyval = yyvsp[-1] ; }
#line 1988 "trad2.tab.c"
    break;

  case 82: /* operando: IDENTIF '(' lista_params ')'  */
#line 356 "trad2.y"
                                          { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ; 
                                            yyval.code = gen_code(temp) ; }
#line 1995 "trad2.tab.c"
    break;


#line 1999 "trad2.tab.c"

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

#line 361 "trad2.y"
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
