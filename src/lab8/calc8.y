// Denis Loren Moldovan       Jorge Adrian Saghin Dudulea   Gr. 121
// 100522240@alumnos.uc3m.es  100522257@alumnos.uc3m.es

%{                      // SECCION 1 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex () ;
extern int yyerror (char*) ;

char temp [2048] ;

#define FF fflush(stdout);

char *mi_malloc (int nbytes)
{
    char *p ;
    static long int nb = 0;
    static int nv = 0 ;
    
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

char *genera_cadena (char *nombre)
{
    char *p ;
    int l ;
    
    l = strlen (nombre)+1 ;
    p = (char *) mi_malloc (l) ;
    strcpy (p, nombre) ;
    
    return p ;
}

char *int_to_string(int n)
{
    sprintf(temp, "%d", n);
    return genera_cadena(temp);
}

char *char_to_string(char c)
{
    sprintf(temp, "%c", c);
    return genera_cadena(temp);
}


typedef struct ASTnode t_node ;

struct ASTnode {
    char   *op ;      
    int     type ;    
    t_node *left ;
    t_node *right ;
} ;

t_node *createASTNode (char *op, int type, t_node *left, t_node *right)
{
    t_node *node ;
    node        = (t_node *) malloc (sizeof (t_node)) ;
    node->op    = strdup (op) ;
    node->type  = type ;
    node->left  = left ;
    node->right = right ;
    return node ;
}

void freeAST (t_node *node)
{
    if (node != NULL) {
        freeAST (node->left) ;
        freeAST (node->right) ;
        free (node->op) ;
        free (node) ;
    }
}

void printAST2Prefix (t_node *node)
{
    if (node == NULL) {
        return ;
    } else if (node->type == 0) {
        printf ("%s ", node->op) ;          
    } else if (node->type == 1) {
        printf ("(%s ", node->op) ;         
        printAST2Prefix (node->left) ;
        printf (") ") ;
    } else {
        printf ("(%s ", node->op) ;         
        printAST2Prefix (node->left) ;
        printAST2Prefix (node->right) ;
        printf (") ") ;
    }
}

#define YYSTYPE t_attr
typedef struct s_attr {
        int     valor ;
        int     indice ;
        char   *cadena ;
        t_node *node ;      
} t_attr ;

%}

/*
%union {                // El tipo de la pila (del AP) tiene caracter dual 
      int valor ;       //  - valor numerico entero 
      int indice ;      //  - indice para identificar una variable
      char *cadena ;
}                       // SECCION 2 
*/


%token  NUMERO
%token  VARIABLE

/*
// No utilicéis el sistema de atributos implicitos que viene a continuacion salvo que tengáis suficiente soltura para depurar los errores que provoca el olvido de dichas declaraciones
// En los examenes se espera siempre el acceso explícito a los atributos.
*/
/*
%token  <valor>  NUMERO    // Todos los token tienen un tipo para la pila
%token  <indice> VARIABLE  // 

%type   <cadena>  axioma expresion termino operando 
*/

%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
%left   SIGNO_UNARIO    //  mayor orden de precedencia 
%%
                        // SECCION 3: Gramatica - Semantico


axioma:     expresion '\n'
                {
                    printAST2Prefix ($1.node) ;
                    printf ("\n") ; FF
                    freeAST ($1.node) ;
                }
            r_expr { ; }

        |   VARIABLE '=' expresion '\n'
                {
                    t_node *var = createASTNode (
                                    char_to_string ((char)$1.indice),
                                    0, NULL, NULL) ;
                    t_node *asign = createASTNode ("setq", 2, var, $3.node) ;
                    printAST2Prefix (asign) ;
                    printf ("\n") ; FF
                    freeAST (asign) ;
                }
            r_expr { ; }

        |   '@' expresion '\n'
                {
                    t_node *p = createASTNode ("print", 1, $2.node, NULL) ;
                    printAST2Prefix (p) ;
                    printf ("\n") ; FF
                    freeAST (p) ;
                }
            r_expr { ; }
        ;

r_expr:                                     { ; }
            |   axioma                      { ; }
            ;


expresion:         termino
                    { $$.node = $1.node ; }

            |   expresion '+' expresion
                    { $$.node = createASTNode ("+", 2, $1.node, $3.node) ; }

            |   expresion '-' expresion
                    { $$.node = createASTNode ("-", 2, $1.node, $3.node) ; }

            |   expresion '*' expresion
                    { $$.node = createASTNode ("*", 2, $1.node, $3.node) ; }

            |   expresion '/' expresion
                    { $$.node = createASTNode ("/", 2, $1.node, $3.node) ; }
            ;

termino:         operando
                    { $$.node = $1.node ; }

            |   '+' operando %prec SIGNO_UNARIO
                    { $$.node = $2.node ; }

            |   '-' operando %prec SIGNO_UNARIO
                    {
                        $$.node = createASTNode ("-", 1, $2.node, NULL) ;
                    }
            ;


operando:       VARIABLE
                    {
                        $$.node = createASTNode (
                                    char_to_string ((char)$1.indice),
                                    0, NULL, NULL) ;
                    }

            |   NUMERO
                    { $$.node = createASTNode (int_to_string ($1.valor), 0, NULL, NULL) ; }

            |   '(' expresion ')'
                    { $$.node = $2.node ; }
            ;

%%

                        /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
}



int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c == ' ' || c == '\r') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
         return NUMERO ;
    }

    if ((c >= 'A' && c <= 'Z') ||
    		 (c >= 'a' && c <= 'z')) {
         yylval.indice = c;
         return VARIABLE ;
    }

    if (c == '\n')
          n_linea++ ;
    return c ;
}


int main ()
{
    yyparse () ;
}
