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

= FOR LOOP


= SWITCH/CASE

El switch statement no tiene ninguna implementación complicada. Al igual que el resto de la gramática, simplemente hemos añadipardo el token para el `SWITCH`, y en cada caso se puede insertar el cuerpo completo, si al final encuentra el break.

Además, estos se pueden encadenar dentro del cuerpo, para añair mas switches en niveles superiores.

= FUNCIONES (FUNCTIONS)


= VECTORES (VECTORS)

Los vectores se pueden declarar y definir globalmente, usarse como operandos, y acceder y modificar dentro del cuerpo de las funciones. 

Al igual que con las variables globales, los vectores también usan los mismo métodos para comprobar que esté dentro del scope de cada función.
