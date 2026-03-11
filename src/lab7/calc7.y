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


typedef struct s_attr {
        int valor ;
	int indice ;
        char *cadena ;
} t_attr ;

#define YYSTYPE t_attr



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
                { printf("%s\n", $1.cadena); FF }
            r_expr { ; }
        |   VARIABLE '=' expresion '\n'
                {
                    printf("(setq %c %s)\n", (char)$1.indice, $3.cadena); FF
                }
            r_expr { ; }
        |   '@' expresion '\n'
                {
                    printf("(print %s)\n", $2.cadena); FF
                }
            r_expr { ; }
        ;

r_expr:         /* lambda */                { ; }
            |   axioma                      { ; }
            ;


expresion:      termino
                    { $$.cadena = $1.cadena; }
            |   expresion '+' expresion
                    {
                        sprintf(temp, "(+ %s %s)", $1.cadena, $3.cadena);
                        $$.cadena = genera_cadena(temp);
                    }
            |   expresion '-' expresion
                    {
                        sprintf(temp, "(- %s %s)", $1.cadena, $3.cadena);
                        $$.cadena = genera_cadena(temp);
                    }
            |   expresion '*' expresion
                    {
                        sprintf(temp, "(* %s %s)", $1.cadena, $3.cadena);
                        $$.cadena = genera_cadena(temp);
                    }
            |   expresion '/' expresion
                    {
                        sprintf(temp, "(/ %s %s)", $1.cadena, $3.cadena);
                        $$.cadena = genera_cadena(temp);
                    }
            ;

termino:        operando
                    { $$.cadena = $1.cadena; }
            |   '+' operando %prec SIGNO_UNARIO
                    { $$.cadena = $2.cadena; }
            |   '-' operando %prec SIGNO_UNARIO
                    {
                        sprintf(temp, "(- %s)", $2.cadena);
                        $$.cadena = genera_cadena(temp);
                    }
            ;

operando:       VARIABLE
                    { $$.cadena = char_to_string((char)$1.indice); }
            |   NUMERO
                    { $$.cadena = int_to_string($1.valor); }
            |   '(' expresion ')'
                    { $$.cadena = $2.cadena; }
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
