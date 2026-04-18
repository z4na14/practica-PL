#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Practica Final - Tercera Parte",
  title: "Traductor de un subconjunto de Lisp a Forth (back-end)",
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
Esta tercera parte implementa el back-end del traductor: recibe como entrada un subconjunto de Lisp (generado por el front-end de la práctica anterior) y produce código Forth como salida. La traducción es directa (_Direct Translation_): las acciones semánticas de Bison emiten el código Forth en el mismo momento en que se reduce cada regla gramatical.

= Nuevos tokens
Se han añadido los siguientes tokens respecto a la versión inicial: `OR`, `NEQ` (`/=`), `LTEQ` (`<=`), `GTEQ` (`>=`), `MOD` y `NOT`. Los operadores de dos caracteres se detectan mediante el mecanismo de _expandable operators_, que lee un segundo carácter al encontrar uno de los caracteres iniciales.

= Variables: setq y setf
`(setq var expr)` declara una variable global en Forth e inicializa su valor. Hay dos variantes: si el valor inicial es un literal numérico emite `variable <nombre> <valor> <nombre> !`; si es una expresión emite `variable <nombre>`, el código de la expresión, y luego `<nombre> !`. `(setf var expr)` asigna a una variable ya existente, emitiendo solo `<nombre> !` tras la expresión:
```
(setq x 5)        →  variable x 5 x !
(setf x (+ x 1))  →  x @ 1 + x !
```

= Print y princ
- `(print "texto")` emite `.\" texto\" cr` (con salto de línea).
- `(princ expr)` emite `. ` tras evaluar la expresión (sin salto de línea).
- `(princ "texto")` emite `.\" texto\"` (sin salto de línea).

= Defun main y llamada a main
La definición de la función principal se traduce a una palabra Forth. La acción semántica emite `: main ` al reducir la cabecera y ` ; ` al cerrar el cuerpo. La llamada `(main)` emite simplemente `main`:
```
(defun main () <cuerpo>)  →  : main <cuerpo> ;
```

= Bucle: loop while do
El bucle `(loop while <cond> do <cuerpo>)` sigue el patrón `BEGIN ... WHILE ... REPEAT` de Forth. Las tres acciones semánticas emiten `BEGIN` antes de la condición, `WHILE` tras evaluarla y `REPEAT` al cerrar:
```
(loop while (< i 10) do (setf i (+ i 1)))  →  BEGIN i @ 10 < WHILE i @ 1 + i ! REPEAT
```

= Condicional: if
Las acciones emiten `IF`, `ELSE` y `THEN` en los momentos adecuados de la reducción:
```
(if (< x 0) (setf x 0))             →  x @ 0 < IF 0 x ! THEN
(if (< x 0) (setf x 0) (setf x 1)) →  x @ 0 < IF 0 x ! ELSE 1 x ! THEN
```

= Operadores aritméticos y relacionales
Se han añadido las siguientes reglas a la producción `expression`, todas con traducción directa en notación postfija:

#table(
  columns: (auto, auto, auto, auto, auto, auto),
  [Lisp], [Forth], [Lisp], [Forth], [Lisp], [Forth],
  [`(+ a b)`], [`a b +`], [`(and a b)`], [`a b and`], [`(= a b)`], [`a b =`],
  [`(* a b)`], [`a b *`], [`(or a b)`], [`a b or`], [`(/= a b)`], [`a b = 0=`],
  [`(/ a b)`], [`a b /`], [`(not a)`], [`a 0=`], [`(< a b)`], [`a b <`],
  [`(- a b)`], [`a b -`], [`(<= a b)`], [`a b <=`], [`(> a b)`], [`a b >`],
  [`(- a)`], [`a negate`], [`(mod a b)`], [`a b mod`], [`(>= a b)`], [`a b >=`],
)

La desigualdad `/=` se traduce como `= 0=` y `not` como `0=`, ya que Forth no tiene operadores dedicados para estos casos.
