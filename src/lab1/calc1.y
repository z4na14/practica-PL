%{
/* Seccion 1: Declaraciones de C y bison */
#include <stdio.h>
#define YYSTYPE double
int yylex();
int yyerror(char *s);
%}

/* Seccion 2: Declaraciones de bison */

%%
/* Seccion 3: Sintáctico - Semántico */

lista: axioma | axioma lista;
axioma:
      expresion '\n' { printf("Expresion=%lf\n", $1); }
    | '\n'  { }
    ;

expresion:
    operando                 { $$ = $1; }
    | operando '+' expresion { $$ = $1 + $3; }
    | operando '-' expresion { $$ = $1 - $3; }
    | operando '*' expresion { $$ = $1 * $3; }
    | operando '/' expresion { $$ = $1 / $3; }
    ;

operando: 
    numero { $$ = $1; }
    ;

numero: 
    '0'     { $$ = 0; }
    | '1'   { $$ = 1; }
    | '2'   { $$ = 2; }
    | '3'   { $$ = 3; }
    | '4'   { $$ = 4; }
    | '5'   { $$ = 5; }
    | '6'   { $$ = 6; }
    | '7'   { $$ = 7; }
    | '8'   { $$ = 8; }
    | '9'   { $$ = 9; }
    ;

%%
/* Seccion 4: Código en C */

int yyerror(char *mensaje) {
    fprintf(stderr, "%s\n", mensaje);
    return 0;
}

int yylex() {
    unsigned char c;
    do {
        c = getchar();
    } while (c == ' ');
    return c;
}

int main() {
    yyparse();
    return 0;
}
