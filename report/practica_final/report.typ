#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Practica Final - Entrega Final",
  title: "Traductor de un subconjunto de Lisp a Forth",
  group: 81,
  authors: (
    (
      name: "Denis Loren",
      surname: "Moldovan",
      nia: "100522240"
    ),
    (
      name: "Jorge Adrian",
      surname: "Saghin Dudulea",
      nia: "100522257"
    )
  ),
  team: "Equipo 121",
  professor: "MARIA PAZ SESMERO LORENTE",
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

= Implementación del FRONTEND
== Variables globales



== Función main
== Impresión de cadenas
== Impresión de expresiones y cadenas
== Operadores, precedencia y asociatividad
== Estructura de control IF
== Variables locales
== Estructura de control FOR
== Estructura de control Switch/Case
== Funciones
== Implementación de vectores
= Implementación del BACKEND

= Cambios realizados como parte de la entrega final

Al compilar con bison el back.y, hemos obtenido un conflicto shift-reduce en las reglas siguientes:

```sh
  Example: '(' SETQ IDENTIF number • ')'
  Shift derivation
    expression1
    ↳ 7: '(' SETQ IDENTIF number • ')'
  Reduce derivation
    expression1
    ↳ 8: '(' SETQ IDENTIF expression           ')'
                          ↳ 24: operand
                                ↳ 41: number •
```

Para arreglar este conflicto, solo tuvimos que eliminar la regla `'(' SETQ IDENTIF number • ')'` para evitar redundancias.

Otra cosa que hemos cambiado en esta sesión ha sido el volcado de la traducción en el axioma. Lo hemos quitado de las acciones semánticas del no terminal del axioma y hemos incluido los printf en las acciones semánticas de las reglas de `declaraciones_funciones` y de `funcion_main`.


= Pruebas realizadas

Para las pruebas realizadas, hemos usado un set de tests generados por Claude, a partir del código final, tanto del backend como del frontend. Hemos tomado en cuenta que este consistiría basicamente por snippets de código reales de C y Lisp, por lo que, tras revisar la salida y limpiarla, la hemos usado para comprobar el correcto funcionamiento de este.

Para la ejecución de tests, hemos seguido la siguiente dinámica. Para el front-end, hemos usado el siguiente mandato:

\

```bash
$ cat test_complejo.c | ../../trad >test_complejo.out | meld --diff test_complejo.expected test_complejo.out
```

\

Y para el backend, este otro:

\

```bash
$ cat test_complejo.lisp | ../../back >test_complejo.out | meld --diff test_complejo.expected test_complejo.out
```

\

#image("./img/meld.png")

= Declaración de uso de IA

Hemos hecho uso de la inteligencia artificial generativa para la generación de los casos de prueba de las gramáticas ya desarrolladas, para evitar perder el tiempo escribiendo snippets genéricos de código, que puedan llegar a estar mal, y alimentarlos directamente a nuestros programas.

Para esta tarea, hemos usado la versión gratuita de Claude, alimentandolo como contexto nuestra gramática, y revisando completamente la salida completa para evitar errores.