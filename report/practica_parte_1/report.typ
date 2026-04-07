#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Practica Final - Segunda Parte",
  title: "Traductor de un subconjunto de C a un lenguaje de notación prefija (Lisp)",
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


= Avance segunda parte

Durante Semana Santa, se ha desarrollado solamente el primer punto como parte del avance.

== Estructura de control IF

En este punto se pedía implementar la traducción de la estructura if/else, donde las reglas de traducción son:

- `if (<expr>) { <codigo> }`
  - `(if <expr> <codigo>)`
- `if (<expr>) { <codigo1> } else { <codigo2> }`
  - `(if <expr> <codigo1> <codigo2>)`

El uso de `progn` permite agrupar múltiples sentencias en cada rama, tal como exige Lisp. Los bloques `{` y `}` son obligatorios, lo que resuelve el conflicto shift/reduce que menciona el enunciado. La regla `control_if` está integrada dentro de cuerpo, por lo que puede aparecer correctamente dentro del `main`.

== Variables locales

Solamente se han puesto las declaraciones necesarias para llevar a cabo esta parte. El objetivo es, a diferencia de las variables globales, es concatenar el nombre de la función, con un guión bajo, al nombre de la función (en vez de `-` ya que este sería ambiguo), con el objetivo de poder ser llamadas solamente en su respectivo scope.

Para saber si una variable usada dentro de una funcion es local o global, se va a mantener una tabla de variables locales donde se inserten todas las declaradas dentro del cuerpo de la función. Si una variable no aparece en esa tabla, es global y no se concatena.

== Tests

Solamente se ha probado la parte 7 del enunciado, ya que es la única desarrollada para esta entrega opcional.

#table(
  columns: (auto, 1fr, 1fr, 2fr),
  align: (center, left, left, left),
  inset: 6pt,

  table.header(
    [*Nº*], [*Descripción*], [*Entrada C*], [*Salida Lisp esperada*],
  ),

  [1], [IF simple con condición de igualdad], [`if (a == 0) { b = 1; }`], [`(if (= a 0) (progn (setf b 1)))`],
  [2], [IF simple con condición de desigualdad], [`if (a != 0) { b = 1; }`], [`(if (/= a 0) (progn (setf b 1)))`],
  [3], [IF simple con condición menor que], [`if (a < 10) { b = 2; }`], [`(if (< a 10) (progn (setf b 2)))`],
  [4], [IF simple con condición mayor que], [`if (a > 5) { b = 3; }`], [`(if (> a 5) (progn (setf b 3)))`],
  [5], [IF simple con condición menor o igual], [`if (a <= 10) { b = 4; }`], [`(if (<= a 10) (progn (setf b 4)))`],
  [6], [IF simple con condición mayor o igual], [`if (a >= 5) { b = 5; }`], [`(if (>= a 5) (progn (setf b 5)))`],
  [7], [IF con cuerpo de dos sentencias], [`if (a == 1) { b = 2; c = 3; }`], [`(if (= a 1) (progn (setf b 2) (setf c 3)))`],
  [8], [IF-ELSE simple], [`if (a == 0) { b = 1; } else { b = 2; }`], [`(if (= a 0) (progn (setf b 1)) (progn (setf b 2)))`],
  [9], [IF-ELSE con varias sentencias en ambas ramas], [`if (a == 0) { b = 1; c = 2; } else { b = 3; c = 4; }`], [`(if (= a 0) (progn (setf b 1) (setf c 2)) (progn (setf b 3) (setf c 4)))`],
  [10], [IF-ELSE con condición AND], [`if (a == 1 && b == 2) { c = 1; } else { c = 0; }`], [`(if (and (= a 1) (= b 2)) (progn (setf c 1)) (progn (setf c 0)))`],
  [11], [IF-ELSE con condición OR], [`if (a == 0 || b == 0) { c = 1; } else { c = 0; }`], [`(if (or (= a 0) (= b 0)) (progn (setf c 1)) (progn (setf c 0)))`],
  [12], [IF con condición negada], [`if (!a) { b = 1; }`], [`(if (not a) (progn (setf b 1)))`],
  [13], [IF con expresión aritmética en condición], [`if (a + 1 == b) { c = 0; }`], [`(if (= (+ a 1) b) (progn (setf c 0)))`],
  [14], [IF anidado en rama then], [`if (a == 1) { if (b == 2) { c = 3; } }`], [`(if (= a 1) (progn (if (= b 2) (progn (setf c 3)))))`],
  [15], [IF-ELSE anidado en rama then], [`if (a == 1) { if (b == 2) { c = 3; } else { c = 4; } }`], [`(if (= a 1) (progn (if (= b 2) (progn (setf c 3)) (progn (setf c 4)))))`],
  [16], [IF con printf en cuerpo], [`if (a == 1) { printf ("%d", a); }`], [`(if (= a 1) (progn (princ a)))`],
  [17], [IF-ELSE con puts en ambas ramas], [`if (a == 0) { puts ("cero"); } else { puts ("no cero"); }`], [`(if (= a 0) (progn (print "cero")) (progn (print "no cero")))`],
  [18], [IF con condición sobre módulo], [`if (a % 2 == 0) { b = 1; }`], [`(if (= (mod a 2) 0) (progn (setf b 1)))`],
  [19], [IF-ELSE con asignación y printf], [`if (a > 0) { b = a; printf ("%d", b); } else { b = 0; }`], [`(if (> a 0) (progn (setf b a) (princ b)) (progn (setf b 0)))`],
  [20], [IF con condición compuesta AND y OR], [`if (a == 1 && b == 2 || c == 3) { d = 1; }`], [`(if (or (and (= a 1) (= b 2)) (= c 3)) (progn (setf d 1)))`],
)