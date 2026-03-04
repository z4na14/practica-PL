// Denis Loren Moldovan       Jorge Adrian Saghin Dudulea   Gr. 121
// 100522240@alumnos.uc3m.es  100522257@alumnos.uc3m.es

%{                    // SECCION 1 - Definiciones
#include <stdio.h>
int yylex();
int yyerror(char *);
%}                      // SECCION 2 - Directivas

%union {                // El tipo de la pila (del AP) tiene caracter dual 
      int valor ;       //  - valor numerico entero 
      int indice ;      //  - indice para identificar una variable 
}  

%token  <valor>  NUMERO    // Todos los token tienen un tipo para la pila
%token  <indice> VARIABLE
%type   <valor>  expresion // Se asocia tambien a los No Terminales un tipo 
%type   <valor>  termino operando

%right  '='             //  es la ultima operacion que se debe realizar
%left   '+' '-'         //  menor orden de precedencia 
%left   '*' '/'         //  orden de precedencia intermedio 
%left   SIGNO_UNARIO    //  mayor orden de precedencia 

%%

                     // SECCION 3: Gramatica - Semantico 
entrada:    /* vacio */
          | entrada linea
          ;

linea:      expresion '\n'              { printf(". \n"); } 
          | VARIABLE '=' expresion '\n' { printf("%c ! \n", $1 + 'A'); }
          | '\n'                        { }
          ;

expresion:  termino                     { /* lambda */ }
          | expresion '+' expresion     { printf("+ "); }
          | expresion '-' expresion     { printf("- "); }
          | expresion '*' expresion     { printf("* "); }
          | expresion '/' expresion     { printf("/ "); }
          ;

termino:    operando                    { }
          | '+' operando %prec SIGNO_UNARIO    { }
          | '-' operando %prec SIGNO_UNARIO    { printf("negate "); }
          ;

operando:   VARIABLE                    { printf("%c @ ", $1 + 'A'); }
          | NUMERO                      { printf("%d ", $1); }
          | '(' expresion ')'           { }
          ;

%%

                     /* SECCION 4  Codigo en C */
int n_linea = 1 ;

int yyerror (char *mensaje) {
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
    return 0;
}

int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c == ' ') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%d", &yylval.valor) ;
         return NUMERO ;
    }

    if (c >= 'a' && c <= 'z') {
         yylval.indice = c - 'a' ;
         return VARIABLE ;
    }

    if (c >= 'A' && c <= 'Z') {
         yylval.indice = c - 'A' ;
         return VARIABLE ;
    }

    if (c == '\n')
         n_linea++ ;
    return c ;
}

int main ()
{
    printf("variable A variable B variable C variable D variable E variable F variable G variable H variable I variable J variable K variable L variable M variable N variable O variable P variable Q variable R variable S variable T variable U variable V variable W variable X variable Y variable Z \n");
    printf(": negate -1 * ; \n"); 

    yyparse () ;
    return 0;
}
