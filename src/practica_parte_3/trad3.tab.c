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
#line 3 "trad3.y"
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


#line 128 "trad3.tab.c"

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
  YYSYMBOL_decl_global = 49,               /* decl_global  */
  YYSYMBOL_funcion = 50,                   /* funcion  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_lista_args = 52,                /* lista_args  */
  YYSYMBOL_r_lista_args = 53,              /* r_lista_args  */
  YYSYMBOL_funcion_main = 54,              /* funcion_main  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_cuerpo = 56,                    /* cuerpo  */
  YYSYMBOL_57_3 = 57,                      /* $@3  */
  YYSYMBOL_abre_rama = 58,                 /* abre_rama  */
  YYSYMBOL_bucle_while = 59,               /* bucle_while  */
  YYSYMBOL_bucle_for = 60,                 /* bucle_for  */
  YYSYMBOL_inicializ = 61,                 /* inicializ  */
  YYSYMBOL_expr_cond = 62,                 /* expr_cond  */
  YYSYMBOL_oper_for = 63,                  /* oper_for  */
  YYSYMBOL_control_if = 64,                /* control_if  */
  YYSYMBOL_control_switch = 65,            /* control_switch  */
  YYSYMBOL_switch_cases = 66,              /* switch_cases  */
  YYSYMBOL_sentencia = 67,                 /* sentencia  */
  YYSYMBOL_lista_params = 68,              /* lista_params  */
  YYSYMBOL_r_lista_params = 69,            /* r_lista_params  */
  YYSYMBOL_elemento = 70,                  /* elemento  */
  YYSYMBOL_mult_elementos = 71,            /* mult_elementos  */
  YYSYMBOL_mult_asign = 72,                /* mult_asign  */
  YYSYMBOL_expresion = 73,                 /* expresion  */
  YYSYMBOL_termino = 74,                   /* termino  */
  YYSYMBOL_operando = 75                   /* operando  */
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
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
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
       0,    98,    98,   103,   105,   107,   110,   112,   114,   116,
     118,   123,   122,   133,   135,   138,   140,   144,   143,   152,
     155,   161,   163,   165,   167,   170,   170,   181,   183,   186,
     191,   196,   198,   203,   206,   212,   220,   223,   229,   234,
     238,   242,   245,   252,   258,   265,   272,   279,   285,   287,
     289,   296,   304,   306,   309,   311,   314,   315,   319,   325,
     328,   330,   332,   334,   338,   339,   341,   343,   345,   347,
     349,   351,   353,   355,   357,   359,   361,   363,   367,   368,
     369,   371,   375,   380,   382,   383,   386
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
  "declaraciones_funciones", "decl_global", "funcion", "$@1", "lista_args",
  "r_lista_args", "funcion_main", "$@2", "cuerpo", "$@3", "abre_rama",
  "bucle_while", "bucle_for", "inicializ", "expr_cond", "oper_for",
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

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,   -33,     7,    30,    25,    15,    43,    93,   -22,  -166,
      67,  -166,    43,  -166,   109,    73,   116,   121,   123,  -166,
      90,  -166,   105,  -166,   107,    95,   -19,  -166,   141,  -166,
     110,  -166,  -166,     6,  -166,   111,   150,   104,  -166,   -12,
      -1,    -1,    -1,     6,    71,  -166,  -166,   104,   105,    13,
     152,   118,   120,   131,   138,   139,   140,     6,   119,   104,
     104,   104,   104,   124,     6,     6,  -166,  -166,  -166,   162,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,  -166,   157,  -166,     6,     6,     6,    -6,
     175,   176,    66,     6,     6,   159,   286,  -166,  -166,  -166,
    -166,  -166,   104,   244,   160,   155,  -166,    63,   319,   183,
     183,   106,   106,   106,   106,    84,    84,  -166,  -166,  -166,
    -166,   296,   256,   161,     6,   207,  -166,   177,   192,   193,
     215,   184,   194,   219,   196,  -166,  -166,  -166,  -166,     6,
    -166,   211,  -166,    71,   200,  -166,    14,     6,   213,     6,
     199,   201,   202,   104,   155,     6,  -166,  -166,  -166,   198,
     296,   296,     6,   208,   296,  -166,  -166,   122,  -166,  -166,
     296,    14,   205,   296,    69,   104,   104,   258,   217,   220,
     198,  -166,   224,   225,   238,   237,   239,   236,  -166,  -166,
    -166,   287,   288,   251,  -166,   273,  -166,   104,   261,   262,
    -166,   263,   104,   280,  -166,  -166,   104,  -166,   289,   275,
     278,   104,   285,   122,  -166,   292,   122,  -166,  -166,  -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,    19,     0,     5,    14,     6,     1,
       0,     2,     5,     4,     0,     0,     0,     0,     0,     9,
       0,     3,    16,    11,     7,     0,    63,    17,     0,    13,
       0,     8,    10,     0,    61,     0,     0,    27,    83,    82,
       0,     0,     0,     0,    62,    64,    78,    27,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      27,    27,    27,     0,     0,    53,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,    15,     0,     0,    53,    44,
       0,     0,     0,     0,     0,     0,     0,    12,    21,    23,
      22,    24,    27,     0,     0,    55,    84,    70,    69,    71,
      72,    74,    76,    75,    73,    65,    66,    67,    68,    77,
      18,    47,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    20,    86,    85,     0,
      52,     0,    49,    42,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    27,    55,     0,    46,    50,    57,    59,
      56,    31,     0,     0,    33,    28,    28,    41,    26,    54,
      51,     0,     0,    32,     0,    27,    27,     0,     0,     0,
      59,    43,     0,     0,     0,     0,     0,     0,    28,    38,
      58,     0,     0,     0,    29,    36,    28,    27,     0,     0,
      28,     0,    27,     0,    34,    35,    27,    28,     0,     0,
       0,    27,     0,    41,    30,     0,    41,    40,    37,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,    21,  -166,  -166,  -166,  -166,   290,  -166,  -166,
     -47,  -166,  -165,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -126,  -166,   248,   185,   166,   163,   -20,   -14,  -166,   102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    30,    15,    29,    11,    35,
      58,   153,   175,    59,    60,   131,   163,   184,    61,    62,
     179,    63,   104,   140,   159,   172,    19,   105,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      84,   176,    38,    39,    31,    16,    34,     7,    33,    38,
      39,     8,    98,    99,   100,   101,    17,    38,    39,    44,
     158,   124,    18,   197,    83,    18,    64,    13,    65,    69,
       9,   202,   125,    21,    10,   206,    40,    41,    18,    43,
      86,    42,   211,    96,    40,    41,    43,     1,     2,    42,
     103,    87,    12,    88,    43,   136,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   126,
     129,   130,   121,   122,    71,    72,    73,    74,    75,   132,
     133,    70,    71,    72,    73,    74,    75,   217,   182,   183,
     219,    76,    77,    78,    79,    80,    81,    82,    14,    76,
      77,    78,    79,    80,    81,    82,   168,    20,    49,    50,
     143,    51,    52,    22,    23,    18,    80,    81,    82,    24,
      53,    54,    55,   156,    25,   154,    56,    26,   185,   186,
      57,    27,   160,   161,    32,   164,    78,    79,    80,    81,
      82,   170,    66,    67,    68,   177,    36,   178,   173,    28,
     203,    18,    37,    47,    48,   208,    89,   160,    90,   210,
      91,   102,    97,   134,   215,    70,    71,    72,    73,    74,
      75,    92,    70,    71,    72,    73,    74,    75,    93,    94,
      95,   127,   128,    76,    77,    78,    79,    80,    81,    82,
      76,    77,    78,    79,    80,    81,    82,    74,    75,   139,
     120,   138,   142,   106,    70,    71,    72,    73,    74,    75,
     144,    76,    77,    78,    79,    80,    81,    82,   145,   148,
     147,   149,    76,    77,    78,    79,    80,    81,    82,    70,
      71,    72,    73,    74,    75,   150,   146,   152,   155,   157,
     162,   165,   171,   166,   167,   174,   181,    76,    77,    78,
      79,    80,    81,    82,    70,    71,    72,    73,    74,    75,
     151,   187,   188,   189,   191,   192,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   193,
     194,   196,   195,   137,    76,    77,    78,    79,    80,    81,
      82,   198,   199,   200,   201,   141,    70,    71,    72,    73,
      74,    75,   204,   205,   209,   207,    70,    71,    72,    73,
      74,    75,   213,   212,    76,    77,    78,    79,    80,    81,
      82,   214,   216,   135,    76,    77,    78,    79,    80,    81,
      82,    72,    73,    74,    75,   218,   123,   180,    85,   169,
       0,     0,     0,   190,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      47,   166,     3,     4,    24,    27,    26,    40,    27,     3,
       4,     4,    59,    60,    61,    62,    38,     3,     4,    33,
       6,    27,    44,   188,    44,    44,    38,     6,    40,    43,
       0,   196,    38,    12,     9,   200,    30,    31,    44,    40,
      27,    35,   207,    57,    30,    31,    40,     4,     5,    35,
      64,    38,    37,    40,    40,   102,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    89,
       4,     5,    86,    87,    11,    12,    13,    14,    15,    93,
      94,    10,    11,    12,    13,    14,    15,   213,    19,    20,
     216,    28,    29,    30,    31,    32,    33,    34,     5,    28,
      29,    30,    31,    32,    33,    34,   153,    40,     4,     5,
     124,     7,     8,     4,    41,    44,    32,    33,    34,     3,
      16,    17,    18,   143,     3,   139,    22,     4,   175,   176,
      26,    41,   146,   147,    39,   149,    30,    31,    32,    33,
      34,   155,    40,    41,    42,    23,     5,    25,   162,    44,
     197,    44,    42,    42,     4,   202,     4,   171,    40,   206,
      40,    37,    43,     4,   211,    10,    11,    12,    13,    14,
      15,    40,    10,    11,    12,    13,    14,    15,    40,    40,
      40,     6,     6,    28,    29,    30,    31,    32,    33,    34,
      28,    29,    30,    31,    32,    33,    34,    14,    15,    44,
      43,    41,    41,    41,    10,    11,    12,    13,    14,    15,
       3,    28,    29,    30,    31,    32,    33,    34,    41,     4,
      27,    37,    28,    29,    30,    31,    32,    33,    34,    10,
      11,    12,    13,    14,    15,    41,    44,    41,    27,    39,
      27,    42,    44,    42,    42,    37,    41,    28,    29,    30,
      31,    32,    33,    34,    10,    11,    12,    13,    14,    15,
      41,     3,    45,    43,    40,    40,    10,    11,    12,    13,
      14,    15,    28,    29,    30,    31,    32,    33,    34,    41,
      43,    45,    43,    39,    28,    29,    30,    31,    32,    33,
      34,     4,     4,    42,    21,    39,    10,    11,    12,    13,
      14,    15,    41,    41,    24,    42,    10,    11,    12,    13,
      14,    15,    37,    24,    28,    29,    30,    31,    32,    33,
      34,    43,    37,    37,    28,    29,    30,    31,    32,    33,
      34,    12,    13,    14,    15,    43,    88,   171,    48,   154,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    47,    48,    49,    50,    40,     4,     0,
       9,    54,    37,    48,     5,    52,    27,    38,    44,    72,
      40,    48,     4,    41,     3,     3,     4,    41,    44,    53,
      51,    72,    39,    27,    72,    55,     5,    42,     3,     4,
      30,    31,    35,    40,    73,    74,    75,    42,     4,     4,
       5,     7,     8,    16,    17,    18,    22,    26,    56,    59,
      60,    64,    65,    67,    38,    40,    75,    75,    75,    73,
      10,    11,    12,    13,    14,    15,    28,    29,    30,    31,
      32,    33,    34,    72,    56,    53,    27,    38,    40,     4,
      40,    40,    40,    40,    40,    40,    73,    43,    56,    56,
      56,    56,    37,    73,    68,    73,    41,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      43,    73,    73,    68,    27,    38,    72,     6,     6,     4,
       5,    61,    73,    73,     4,    37,    56,    39,    41,    44,
      69,    39,    41,    73,     3,    41,    44,    27,     4,    37,
      41,    41,    41,    57,    73,    27,    72,    39,     6,    70,
      73,    73,    27,    62,    73,    42,    42,    42,    56,    69,
      73,    44,    71,    73,    37,    58,    58,    23,    25,    66,
      70,    41,    19,    20,    63,    56,    56,     3,    45,    43,
      71,    40,    40,    41,    43,    43,    45,    58,     4,     4,
      42,    21,    58,    56,    41,    41,    58,    42,    56,    24,
      56,    58,    24,    37,    43,    56,    37,    66,    43,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    49,    49,
      49,    51,    50,    52,    52,    53,    53,    55,    54,    54,
      56,    56,    56,    56,    56,    57,    56,    56,    58,    59,
      60,    61,    61,    62,    63,    63,    64,    64,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     2,     4,     5,     3,
       5,     0,     8,     3,     0,     4,     0,     0,     7,     0,
       3,     2,     2,     2,     2,     0,     5,     0,     0,     8,
      12,     3,     4,     1,     4,     4,     8,    13,     7,     8,
       7,     0,     4,     7,     2,     3,     5,     3,     4,     4,
       5,     6,     2,     0,     3,     0,     1,     1,     3,     0,
       5,     3,     4,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     2,     1,     1,     3,     4,     4
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
#line 98 "trad3.y"
                                                        { sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; 
                                                          printf("%s\n", yyval.code) ; }
#line 1413 "trad3.tab.c"
    break;

  case 3: /* declaraciones_funciones: decl_global ';' declaraciones_funciones  */
#line 103 "trad3.y"
                                                                            { sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                                                             yyval.code = gen_code(temp) ; }
#line 1420 "trad3.tab.c"
    break;

  case 4: /* declaraciones_funciones: funcion declaraciones_funciones  */
#line 105 "trad3.y"
                                                                            { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ; 
                                                                              yyval.code = gen_code(temp) ; }
#line 1427 "trad3.tab.c"
    break;

  case 5: /* declaraciones_funciones: %empty  */
#line 107 "trad3.y"
                                                                            { yyval.code = gen_code("") ; }
#line 1433 "trad3.tab.c"
    break;

  case 6: /* decl_global: INTEGER IDENTIF  */
#line 110 "trad3.y"
                                                        { sprintf(temp, "(setq %s 0)", yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1440 "trad3.tab.c"
    break;

  case 7: /* decl_global: INTEGER IDENTIF '=' NUMBER  */
#line 112 "trad3.y"
                                                        { sprintf(temp, "(setq %s %d)", yyvsp[-2].code, yyvsp[0].value) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1447 "trad3.tab.c"
    break;

  case 8: /* decl_global: INTEGER IDENTIF '=' NUMBER mult_asign  */
#line 114 "trad3.y"
                                                        { sprintf(temp, "(setq %s %d) %s", yyvsp[-3].code, yyvsp[-1].value, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1454 "trad3.tab.c"
    break;

  case 9: /* decl_global: INTEGER IDENTIF mult_asign  */
#line 116 "trad3.y"
                                                        { sprintf(temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1461 "trad3.tab.c"
    break;

  case 10: /* decl_global: INTEGER IDENTIF '[' NUMBER ']'  */
#line 118 "trad3.y"
                                                        { sprintf(temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1468 "trad3.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 123 "trad3.y"
                                                        { strcpy(nombre_funcion, yyvsp[-3].code) ; 
                                                          limpiar_locales();
                                                          en_funcion = 1;}
#line 1476 "trad3.tab.c"
    break;

  case 12: /* funcion: IDENTIF '(' lista_args ')' $@1 '{' cuerpo '}'  */
#line 128 "trad3.y"
                                                        {en_funcion = 0;
                                                          sprintf(temp, "(defun %s (%s)\n%s)", yyvsp[-7].code, yyvsp[-5].code, yyvsp[-1].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1484 "trad3.tab.c"
    break;

  case 13: /* lista_args: INTEGER IDENTIF r_lista_args  */
#line 133 "trad3.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1491 "trad3.tab.c"
    break;

  case 14: /* lista_args: %empty  */
#line 135 "trad3.y"
                                                        { yyval.code = gen_code("") ; }
#line 1497 "trad3.tab.c"
    break;

  case 15: /* r_lista_args: ',' INTEGER IDENTIF r_lista_args  */
#line 138 "trad3.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1504 "trad3.tab.c"
    break;

  case 16: /* r_lista_args: %empty  */
#line 140 "trad3.y"
                                                        { yyval.code = gen_code("") ; }
#line 1510 "trad3.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 144 "trad3.y"
                                                        { strcpy(nombre_funcion, "main") ;
                                                          limpiar_locales();
                                                          en_funcion = 1; }
#line 1518 "trad3.tab.c"
    break;

  case 18: /* funcion_main: MAIN '(' ')' $@2 '{' cuerpo '}'  */
#line 149 "trad3.y"
                                                        { en_funcion = 0; 
                                                          sprintf(temp, "(defun main ()\n%s)", yyvsp[-1].code) ; 
                                                          yyval.code = gen_code(temp) ; }
#line 1526 "trad3.tab.c"
    break;

  case 19: /* funcion_main: %empty  */
#line 152 "trad3.y"
                                                        { yyval.code = gen_code("") ; }
#line 1532 "trad3.tab.c"
    break;

  case 20: /* cuerpo: sentencia ';' cuerpo  */
#line 155 "trad3.y"
                                                        { if (strlen(yyvsp[0].code) > 0) {
                                                            sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                                        } else {
                                                            sprintf(temp, "%s", yyvsp[-2].code) ;
                                                        }
                                                          yyval.code = gen_code(temp) ; }
#line 1543 "trad3.tab.c"
    break;

  case 21: /* cuerpo: bucle_while cuerpo  */
#line 161 "trad3.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1550 "trad3.tab.c"
    break;

  case 22: /* cuerpo: control_if cuerpo  */
#line 163 "trad3.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1557 "trad3.tab.c"
    break;

  case 23: /* cuerpo: bucle_for cuerpo  */
#line 165 "trad3.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1564 "trad3.tab.c"
    break;

  case 24: /* cuerpo: control_switch cuerpo  */
#line 167 "trad3.y"
                                                        { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1571 "trad3.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 170 "trad3.y"
                                   { nivel_en_return = nivel_rama ; }
#line 1577 "trad3.tab.c"
    break;

  case 26: /* cuerpo: RETURN expresion ';' $@3 cuerpo  */
#line 171 "trad3.y"
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
#line 1592 "trad3.tab.c"
    break;

  case 27: /* cuerpo: %empty  */
#line 181 "trad3.y"
                                                        { yyval.code = gen_code("") ; }
#line 1598 "trad3.tab.c"
    break;

  case 28: /* abre_rama: %empty  */
#line 183 "trad3.y"
                         {nivel_rama++ ;}
#line 1604 "trad3.tab.c"
    break;

  case 29: /* bucle_while: WHILE '(' expresion ')' '{' abre_rama cuerpo '}'  */
#line 186 "trad3.y"
                                                                         { nivel_rama-- ;
                                                                            sprintf (temp, "(loop while %s do\n%s)", yyvsp[-5].code, yyvsp[-1].code) ;
                                                                            yyval.code = gen_code(temp) ; }
#line 1612 "trad3.tab.c"
    break;

  case 30: /* bucle_for: FOR '(' inicializ ';' expr_cond ';' oper_for ')' '{' abre_rama cuerpo '}'  */
#line 192 "trad3.y"
                                                                             {  nivel_rama--;
                                                                                sprintf(temp, "%s\n(loop while %s do\n%s\n%s)", yyvsp[-9].code, yyvsp[-7].code, yyvsp[-1].code, yyvsp[-5].code) ;
                                                                                yyval.code = gen_code(temp) ; }
#line 1620 "trad3.tab.c"
    break;

  case 31: /* inicializ: IDENTIF '=' expresion  */
#line 196 "trad3.y"
                                                                      { sprintf(temp, "(setf %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                        yyval.code = gen_code(temp) ; }
#line 1627 "trad3.tab.c"
    break;

  case 32: /* inicializ: INTEGER IDENTIF '=' expresion  */
#line 198 "trad3.y"
                                                                      { insertar_local(yyvsp[-2].code) ;
                                                                        sprintf(temp, "(setq %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;  
                                                                        yyval.code = gen_code(temp) ;}
#line 1635 "trad3.tab.c"
    break;

  case 33: /* expr_cond: expresion  */
#line 203 "trad3.y"
                                                                       { yyval.code  = yyvsp[0].code ; }
#line 1641 "trad3.tab.c"
    break;

  case 34: /* oper_for: INC '(' IDENTIF ')'  */
#line 206 "trad3.y"
                                                                       { if (en_funcion && es_local(yyvsp[-1].code)) {
                                                                            sprintf(temp, "(setf %s (+ %s 1))", nombre_local(yyvsp[-1].code), nombre_local(yyvsp[-1].code)) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf %s (+ %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1652 "trad3.tab.c"
    break;

  case 35: /* oper_for: DEC '(' IDENTIF ')'  */
#line 212 "trad3.y"
                                                                       { if (en_funcion && es_local(yyvsp[-1].code)) {
                                                                            sprintf(temp, "(setf %s (- %s 1))", nombre_local(yyvsp[-1].code), nombre_local(yyvsp[-1].code)) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf %s (- %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1663 "trad3.tab.c"
    break;

  case 36: /* control_if: IF '(' expresion ')' '{' abre_rama cuerpo '}'  */
#line 220 "trad3.y"
                                                                        { nivel_rama-- ; 
                                                                         sprintf(temp, "(if %s\n%s)", yyvsp[-5].code, wrap_progn(yyvsp[-1].code)) ;
                                                                         yyval.code = gen_code(temp) ; }
#line 1671 "trad3.tab.c"
    break;

  case 37: /* control_if: IF '(' expresion ')' '{' abre_rama cuerpo '}' ELSE '{' abre_rama cuerpo '}'  */
#line 224 "trad3.y"
                                                                        { nivel_rama -= 2 ; 
                                                                          sprintf(temp, "(if %s\n%s\n%s)", yyvsp[-10].code, wrap_progn(yyvsp[-6].code), wrap_progn(yyvsp[-1].code)) ;
                                                                          yyval.code = gen_code(temp) ; }
#line 1679 "trad3.tab.c"
    break;

  case 38: /* control_switch: SWITCH '(' IDENTIF ')' '{' switch_cases '}'  */
#line 230 "trad3.y"
                                                            { sprintf(temp, "(case %s\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1686 "trad3.tab.c"
    break;

  case 39: /* switch_cases: CASE NUMBER ':' abre_rama cuerpo BREAK ';' switch_cases  */
#line 235 "trad3.y"
                                                            { nivel_rama-- ;
                                                              sprintf(temp, "(%d\n%s)\n%s", yyvsp[-6].value, yyvsp[-3].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1694 "trad3.tab.c"
    break;

  case 40: /* switch_cases: DEFAULT ':' abre_rama cuerpo BREAK ';' switch_cases  */
#line 239 "trad3.y"
                                                            { nivel_rama-- ;
                                                              sprintf(temp, "(otherwise\n%s)\n%s", yyvsp[-3].code, yyvsp[0].code) ;
                                                              yyval.code = gen_code(temp) ; }
#line 1702 "trad3.tab.c"
    break;

  case 41: /* switch_cases: %empty  */
#line 242 "trad3.y"
                                                            { yyval.code = gen_code("") ; }
#line 1708 "trad3.tab.c"
    break;

  case 42: /* sentencia: INTEGER IDENTIF '=' expresion  */
#line 245 "trad3.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-2].code) ;
                                                                            sprintf (temp, "(setq %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                         } else {
                                                                            sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                                         }
                                                                        yyval.code = gen_code (temp) ; }
#line 1720 "trad3.tab.c"
    break;

  case 43: /* sentencia: PRINTF '(' STRING ',' elemento mult_elementos ')'  */
#line 252 "trad3.y"
                                                                       { if (strlen(yyvsp[-1].code) > 0) {
                                                                            sprintf (temp, "(princ %s)\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(princ %s)", yyvsp[-2].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1731 "trad3.tab.c"
    break;

  case 44: /* sentencia: INTEGER IDENTIF  */
#line 258 "trad3.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[0].code);
                                                                            sprintf (temp, "(setq %s 0)", nombre_local(yyvsp[0].code)) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1743 "trad3.tab.c"
    break;

  case 45: /* sentencia: INTEGER IDENTIF mult_asign  */
#line 265 "trad3.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-1].code);
                                                                            sprintf (temp, "(setq %s 0) %s", nombre_local(yyvsp[-1].code), yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1755 "trad3.tab.c"
    break;

  case 46: /* sentencia: INTEGER IDENTIF '=' expresion mult_asign  */
#line 272 "trad3.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-3].code);
                                                                            sprintf (temp, "(setq %s %s) %s", nombre_local(yyvsp[-3].code), yyvsp[-1].code, yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setq %s %s) %s", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code (temp) ; }
#line 1767 "trad3.tab.c"
    break;

  case 47: /* sentencia: IDENTIF '=' expresion  */
#line 279 "trad3.y"
                                                                       { if (en_funcion && es_local(yyvsp[-2].code)) {
                                                                            sprintf (temp, "(setf %s %s)", nombre_local(yyvsp[-2].code), yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf (temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1778 "trad3.tab.c"
    break;

  case 48: /* sentencia: PUTS '(' STRING ')'  */
#line 285 "trad3.y"
                                                                       { sprintf(temp, "(print \"%s\")", yyvsp[-1].code) ;
                                                                        yyval.code = gen_code (temp) ; }
#line 1785 "trad3.tab.c"
    break;

  case 49: /* sentencia: IDENTIF '(' lista_params ')'  */
#line 287 "trad3.y"
                                                                       { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                                                        yyval.code = gen_code(temp) ; }
#line 1792 "trad3.tab.c"
    break;

  case 50: /* sentencia: INTEGER IDENTIF '[' NUMBER ']'  */
#line 289 "trad3.y"
                                                                       { if (en_funcion) {
                                                                            insertar_local(yyvsp[-3].code) ;
                                                                            sprintf(temp, "(setq %s (make-array %d))", nombre_local(yyvsp[-3].code), yyvsp[-1].value) ;
                                                                        } else {
                                                                            sprintf(temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1804 "trad3.tab.c"
    break;

  case 51: /* sentencia: IDENTIF '[' expresion ']' '=' expresion  */
#line 296 "trad3.y"
                                                                       { if (en_funcion && es_local(yyvsp[-5].code)) {
                                                                            sprintf(temp, "(setf (aref %s %s) %s)", nombre_local(yyvsp[-5].code), yyvsp[-3].code, yyvsp[0].code) ;
                                                                        } else {
                                                                            sprintf(temp, "(setf (aref %s %s) %s)", yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code) ;
                                                                        }
                                                                        yyval.code = gen_code(temp) ; }
#line 1815 "trad3.tab.c"
    break;

  case 52: /* lista_params: expresion r_lista_params  */
#line 304 "trad3.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1822 "trad3.tab.c"
    break;

  case 53: /* lista_params: %empty  */
#line 306 "trad3.y"
                                                        { yyval.code = gen_code("") ; }
#line 1828 "trad3.tab.c"
    break;

  case 54: /* r_lista_params: ',' expresion r_lista_params  */
#line 309 "trad3.y"
                                                        { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1835 "trad3.tab.c"
    break;

  case 55: /* r_lista_params: %empty  */
#line 311 "trad3.y"
                                                        { yyval.code = gen_code("") ; }
#line 1841 "trad3.tab.c"
    break;

  case 56: /* elemento: expresion  */
#line 314 "trad3.y"
                                                        { yyval.code = yyvsp[0].code ; }
#line 1847 "trad3.tab.c"
    break;

  case 57: /* elemento: STRING  */
#line 315 "trad3.y"
                                                        { sprintf(temp, "\"%s\"", yyvsp[0].code) ;
                                                          yyval.code = gen_code(temp) ; }
#line 1854 "trad3.tab.c"
    break;

  case 58: /* mult_elementos: ',' elemento mult_elementos  */
#line 319 "trad3.y"
                                                        { if (strlen(yyvsp[0].code) > 0) {
                                                              sprintf(temp, "(princ %s)\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          } else {
                                                              sprintf(temp, "(princ %s)", yyvsp[-1].code) ;
                                                          }
                                                          yyval.code = gen_code(temp) ; }
#line 1865 "trad3.tab.c"
    break;

  case 59: /* mult_elementos: %empty  */
#line 325 "trad3.y"
                                                        { yyval.code = gen_code("") ; }
#line 1871 "trad3.tab.c"
    break;

  case 60: /* mult_asign: ',' IDENTIF '=' expresion mult_asign  */
#line 328 "trad3.y"
                                                        { sprintf (temp, "(setq %s %s) %s", yyvsp[-3].code, yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1878 "trad3.tab.c"
    break;

  case 61: /* mult_asign: ',' IDENTIF mult_asign  */
#line 330 "trad3.y"
                                                        { sprintf (temp, "(setq %s 0) %s", yyvsp[-1].code, yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1885 "trad3.tab.c"
    break;

  case 62: /* mult_asign: ',' IDENTIF '=' expresion  */
#line 332 "trad3.y"
                                                        { sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                                          yyval.code = gen_code (temp) ; }
#line 1892 "trad3.tab.c"
    break;

  case 63: /* mult_asign: ',' IDENTIF  */
#line 334 "trad3.y"
                                                        { sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                                          yyval.code = gen_code (temp) ; }
#line 1899 "trad3.tab.c"
    break;

  case 64: /* expresion: termino  */
#line 338 "trad3.y"
                                         { yyval = yyvsp[0] ; }
#line 1905 "trad3.tab.c"
    break;

  case 65: /* expresion: expresion '+' expresion  */
#line 339 "trad3.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1912 "trad3.tab.c"
    break;

  case 66: /* expresion: expresion '-' expresion  */
#line 341 "trad3.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1919 "trad3.tab.c"
    break;

  case 67: /* expresion: expresion '*' expresion  */
#line 343 "trad3.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1926 "trad3.tab.c"
    break;

  case 68: /* expresion: expresion '/' expresion  */
#line 345 "trad3.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1933 "trad3.tab.c"
    break;

  case 69: /* expresion: expresion AND expresion  */
#line 347 "trad3.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1940 "trad3.tab.c"
    break;

  case 70: /* expresion: expresion OR expresion  */
#line 349 "trad3.y"
                                        { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1947 "trad3.tab.c"
    break;

  case 71: /* expresion: expresion NEQ expresion  */
#line 351 "trad3.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1954 "trad3.tab.c"
    break;

  case 72: /* expresion: expresion EQ expresion  */
#line 353 "trad3.y"
                                        { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1961 "trad3.tab.c"
    break;

  case 73: /* expresion: expresion '<' expresion  */
#line 355 "trad3.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1968 "trad3.tab.c"
    break;

  case 74: /* expresion: expresion LTEQ expresion  */
#line 357 "trad3.y"
                                          { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1975 "trad3.tab.c"
    break;

  case 75: /* expresion: expresion '>' expresion  */
#line 359 "trad3.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1982 "trad3.tab.c"
    break;

  case 76: /* expresion: expresion GTEQ expresion  */
#line 361 "trad3.y"
                                          { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1989 "trad3.tab.c"
    break;

  case 77: /* expresion: expresion '%' expresion  */
#line 363 "trad3.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1996 "trad3.tab.c"
    break;

  case 78: /* termino: operando  */
#line 367 "trad3.y"
                                                   { yyval = yyvsp[0] ; }
#line 2002 "trad3.tab.c"
    break;

  case 79: /* termino: '+' operando  */
#line 368 "trad3.y"
                                                   { yyval = yyvsp[0] ; }
#line 2008 "trad3.tab.c"
    break;

  case 80: /* termino: '-' operando  */
#line 369 "trad3.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 2015 "trad3.tab.c"
    break;

  case 81: /* termino: '!' operando  */
#line 371 "trad3.y"
                                                   { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ;}
#line 2022 "trad3.tab.c"
    break;

  case 82: /* operando: IDENTIF  */
#line 375 "trad3.y"
                                            { if (en_funcion && es_local(yyvsp[0].code))
                                                sprintf(temp, "%s", nombre_local(yyvsp[0].code)) ;
                                              else
                                                sprintf(temp, "%s", yyvsp[0].code) ;
                                            yyval.code = gen_code(temp) ; }
#line 2032 "trad3.tab.c"
    break;

  case 83: /* operando: NUMBER  */
#line 380 "trad3.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 2039 "trad3.tab.c"
    break;

  case 84: /* operando: '(' expresion ')'  */
#line 382 "trad3.y"
                                         { yyval = yyvsp[-1] ; }
#line 2045 "trad3.tab.c"
    break;

  case 85: /* operando: IDENTIF '(' lista_params ')'  */
#line 384 "trad3.y"
                                          { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ; 
                                            yyval.code = gen_code(temp) ; }
#line 2052 "trad3.tab.c"
    break;

  case 86: /* operando: IDENTIF '[' expresion ']'  */
#line 386 "trad3.y"
                                            { if (en_funcion && es_local(yyvsp[-3].code)) {
                                                sprintf(temp, "(aref %s %s)", nombre_local(yyvsp[-3].code), yyvsp[-1].code) ;
                                              } else {
                                                sprintf(temp, "(aref %s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                              }
                                              yyval.code = gen_code(temp) ; }
#line 2063 "trad3.tab.c"
    break;


#line 2067 "trad3.tab.c"

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

#line 395 "trad3.y"
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
