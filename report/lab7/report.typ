#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Lab 7",
  title: "Infijo a Prefijo",
  group: 81,
  authors: (
    (
      name: "Denis Loren",
      surname: "Moldovan",
      nia: "100522240@alumnos.uc3m.es"
    ),
    (
      name: "Jorge Adrian",
      surname: "Saghin Dudulea",
      nia: "100522257@alumnos.uc3m.es"
    )
  ),
  team: "121",
  professor: "Maria Paz",
  toc: true,
  logo: "new",
  language: "es"
)

#set table(
      stroke: none,
      fill: (x, y) => if calc.even(y) == false { azuluc3m.transparentize(80%) },
      inset: (x: 1.0em, y: 0.5em),
      gutter: 0.2em, row-gutter: 0em, column-gutter: 0em
    )
#show table.cell.where(y: 0) : set text(weight: "bold")


= Introducción
El objetivo de esta práctica es construir un traductor que reciba expresiones aritméticas y asignaciones escritas en notación infija (al estilo del lenguaje C) y las convierta a notación prefija compatible con un intérprete de Common Lisp.

= Cambios en la gramática

== Estructura del axioma

Se añadieron tres alternativas directamente en el axioma para evitar conflictos shift/reduce. Cuando el parser ve una variable seguida de `=` al inicio de una sentencia, con un único token de lookahead puede determinar sin ambigüedad que se trata de una asignación. Si la regla de asignación se hubiera colocado en un no terminal intermedio (por ejemplo, `sentencia`), el parser habría intentado reducir la variable a expresión antes de ver el `=`, produciendo un syntax error.

Las tres alternativas del axioma son:

- Expresión aritmética terminada en salto de línea.
- Asignación: `VARIABLE '=' expresion '\n'`
- Sentencia de impresión: `'@' expresion '\n'`

== Acciones semánticas

Cada producción construye la cadena prefija correspondiente mediante `sprintf` sobre el buffer temporal `temp`, y la almacena con `genera_cadena()` para asignarla a `$$.cadena`. Los nodos hoja (`NUMERO` y `VARIABLE`) usan respectivamente `int_to_string()` y `char_to_string()`.

El tipo `YYSTYPE` se define como la estructura `t_attr` mediante `#define YYSTYPE t_attr`, lo que permite usar `$$.cadena`, `$1.valor` e `$1.indice` como atributos explícitos en todas las producciones, tal y como se pide en el enunciado.

= Descripción de las traducciones

== Expresiones aritméticas

La precedencia y asociatividad ya estaban definidas en la cabecera del fichero mediante `%left` y `%right`, por lo que bison genera el árbol correcto automáticamente. Cada operador binario produce una cadena del tipo `(op izq der)`:

#block(
  fill: luma(240),
  inset: 8pt,
  radius: 4pt,
  ```
  1+2*3   →   (+ 1 (* 2 3))
  (1+2)*3 →   (* (+ 1 2) 3)
  ```
)

== Asignaciones

Una asignación `a = expr` se traduce usando `setq`, que es la forma de asignación en Common Lisp:

#block(
  fill: luma(240),
  inset: 8pt,
  radius: 4pt,
  ```
  a = b*7+c   →   (setq a (+ (* b 7) c))
  ```
)

== Sentencia de impresión (@)

Como el analizador léxico no está adaptado para reconocer palabras reservadas como `printf`, se utiliza el carácter `@` como simplificación. El carácter es devuelto directamente por `yylex()` sin modificaciones y reconocido en el axioma:

#block(
  fill: luma(240),
  inset: 8pt,
  radius: 4pt,
  ```
  @ 5+3   →   (print (+ 5 3))
  ```
)

= Ejemplos de entrada y salida

#table(
  columns: (auto, 1fr),
  text(fill: white, weight: "bold")[Entrada],
  text(fill: white, weight: "bold")[Salida esperada],
  `1+2*3`,           `(+ 1 (* 2 3))`,
  `(1+2)*3`,         `(* (+ 1 2) 3)`,
  `10-4/2`,          `(- 10 (/ 4 2))`,
  `a = b*7+c`,       `(setq a (+ (* b 7) c))`,
  `x = 5+3*2`,       `(setq x (+ 5 (* 3 2)))`,
  `y = (a+b)*c`,     `(setq y (* (+ a b) c))`,
  `a = -5`,          `(setq a (- 5))`,
  `-3+2`,            `(+ (- 3) 2)`,
  `@ 1+2*3`,         `(print (+ 1 (* 2 3)))`,
  `@ x`,             `(print x)`,
)
