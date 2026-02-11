#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Práctica 2",
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

== ¿A que se deben los resultados de las siguientes expresiones?

```
2*3+1
1+2*3
2+3*1
1*3+2
1-1-1
1-1-1-1
1-1-1-1-1
1-1-1-1-1-1
1-2-3-4-5
```

== ¿Que soluciones se te ocurren al siguente problema?


```
1 2 3 + 2 1 <intro>
Expresion=144.000000
```

== Hay un pequeño fallo tal como está definido expresion. ¿Sabes en qué casos aparece? ¿Y a qué es debido? Prueba diversos tipos de expresiones.



== ¿Por que funciona en el primer caso y no en el segundo?

```
numero: digito { $$ = $1 ; pot = 1 ; }
| digito numero { pot *= 10 ; $$ = $1 * pot + $2 ; }
;
```

```
axioma: expresion '\n' { printf ("Expresion=%lf\n", $1) ; }
| expresion '\n' { printf ("Expresion=%lf\n", $1) ; } axioma
;
```