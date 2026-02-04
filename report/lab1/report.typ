#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Práctica 1",
  title: "Calculadora",
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
  team: "125",
  professor: "Maria Paz",
  toc: true,
  logo: "new",
  language: "es"
)

= Questiones

== ¿Por qué aparece este error?

El error aparece porque en nuestra gramática, el axioma sólo acepta una única expresión, por lo que cuando le pasamos más de una, no es capaz de procesar una lista de expresiones.

== Como solucionarlo

Para solucionarlo, lo que hemos hecho ha sido implementar una lista de axiomas, que consiste en una llamada al propio axioma de manera recursiva. De esta manera, bison entiende que recibe una lista infinita de axiomas. Ahora para poder salir de la ejecución sólo es necesario hacer Ctrl+C.

Ejemplo de ejecución:

```bash
󰘧 ./prac
1+2
Expresion=3.000000
3+3
Expresion=6.000000
3+3+3+3
Expresion=12.000000
2+3/4*8
Expresion=2.093750
7*7*7*7*7*7
Expresion=117649.000000
1+3+2-3-4-1+1*3*4*5
Expresion=-54.000000
```
